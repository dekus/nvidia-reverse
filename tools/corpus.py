import argparse
import gzip
import hashlib
import json
from pathlib import Path
import sys

ROOT = Path(__file__).resolve().parents[1]
EVIDENCE = ROOT / 'evidence'
LFS_HEADER = b'version https://git-lfs.github.com/spec/v1'


def read_json(path):
    return json.loads(path.read_text(encoding='utf-8-sig'))


def modules(query=''):
    query = query.casefold()
    return [row for row in read_json(EVIDENCE / 'pe_index.json')
            if query in row['path'].casefold() or row['sha256'].startswith(query)]


def resolve(query):
    found = modules(query)
    if len(found) != 1:
        raise ValueError(f'Expected one module; matched {len(found)}. Use a full path or a longer SHA-256 prefix.')
    return found[0]


def require_content(path):
    with path.open('rb') as stream:
        if stream.read(len(LFS_HEADER)) == LFS_HEADER:
            raise ValueError(f'LFS content is missing: {path.relative_to(ROOT)}. Run git lfs pull.')


def list_modules(args):
    for row in modules(args.query):
        print(f"{row['sha256']}  {row['path']}")


def show_module(args):
    row = resolve(args.module)
    sha = row['sha256']
    coverage = next(x for x in read_json(EVIDENCE / 'coverage_final.json') if x['sha256'] == sha)
    artifacts = sorted(p.relative_to(ROOT).as_posix() for p in EVIDENCE.rglob(f'{sha}.*') if p.is_file())
    print(json.dumps({'module':row, 'coverage':coverage, 'artifacts':artifacts}, indent=2))


def extract_function(args):
    sha = resolve(args.module)['sha256']
    spans = EVIDENCE / 'decompiled' / f'{sha}.spans.jsonl.gz'
    body = EVIDENCE / 'decompiled' / f'{sha}.pseudocode.c.gz'
    require_content(spans)
    require_content(body)
    rva = int(args.rva, 0)
    with gzip.open(spans, 'rt', encoding='utf-8') as stream:
        found = [row for line in stream if (row := json.loads(line)) and int(row['rva'], 16) == rva]
    if not found:
        raise ValueError('No reconstructed function starts at this RVA. Check the function inventory and coverage.')
    if len(found) > 1:
        raise ValueError('Several blocks start at this RVA; inspect the span index before choosing a reconstruction.')
    span = found[0]
    out = Path(args.output).open('w', encoding='utf-8', newline='\n') if args.output else sys.stdout
    try:
        with gzip.open(body, 'rt', encoding='utf-8') as stream:
            for number, line in enumerate(stream, 1):
                if number > span['end_line']:
                    break
                if number >= span['start_line']:
                    out.write(line)
    finally:
        if args.output:
            out.close()


def search_strings(args):
    sha = resolve(args.module)['sha256']
    path = EVIDENCE / 'strings' / f'{sha}.jsonl.gz'
    require_content(path)
    count = 0
    with gzip.open(path, 'rt', encoding='utf-8') as stream:
        for line in stream:
            row = json.loads(line)
            if args.needle.casefold() in row['text'].casefold():
                print(json.dumps(row, ensure_ascii=False))
                count += 1
                if count >= args.limit:
                    break


def verify(args):
    errors = []
    count = 0
    total = 0
    for entry in (ROOT / 'SHA256SUMS.txt').read_text(encoding='utf-8').splitlines():
        expected, rel = entry.split('  ', 1)
        path = (ROOT / rel).resolve()
        if not path.is_relative_to(ROOT.resolve()):
            errors.append(f'Path outside repository: {rel}')
            continue
        try:
            require_content(path)
            with path.open('rb') as stream:
                actual = hashlib.file_digest(stream, 'sha256').hexdigest()
            if actual != expected:
                errors.append(f'Hash mismatch: {rel}')
                continue
            if args.deep and path.suffix == '.json':
                read_json(path)
            if args.deep and path.suffix == '.gz':
                with gzip.open(path, 'rb') as stream:
                    if path.name.endswith('.jsonl.gz'):
                        for line in stream:
                            json.loads(line)
                    elif path.name.endswith('.json.gz'):
                        json.load(stream)
                    else:
                        while stream.read(1024 * 1024):
                            pass
            count += 1
            total += path.stat().st_size
        except (OSError, ValueError, EOFError) as exc:
            errors.append(f'{rel}: {exc}')
    for error in errors:
        print(error, file=sys.stderr)
    print(json.dumps({'verified_files':count, 'verified_bytes':total, 'errors':len(errors)}, indent=2))
    return 1 if errors else 0


def main():
    parser = argparse.ArgumentParser(description='Browse and verify the NVIDIA reverse-engineering corpus.')
    commands = parser.add_subparsers(dest='command', required=True)
    command = commands.add_parser('list', help='Find modules by path or SHA-256 prefix.')
    command.add_argument('query', nargs='?', default='')
    command.set_defaults(run=list_modules)
    command = commands.add_parser('show', help='Show a module, its coverage and artifact paths.')
    command.add_argument('module')
    command.set_defaults(run=show_module)
    command = commands.add_parser('function', help='Extract reconstructed C for one function RVA.')
    command.add_argument('module')
    command.add_argument('--rva', required=True)
    command.add_argument('--output')
    command.set_defaults(run=extract_function)
    command = commands.add_parser('strings', help='Search extracted strings in one module.')
    command.add_argument('module')
    command.add_argument('needle')
    command.add_argument('--limit', type=int, default=20)
    command.set_defaults(run=search_strings)
    command = commands.add_parser('verify', help='Verify the published SHA-256 manifest.')
    command.add_argument('--deep', action='store_true', help='Also parse JSON/JSONL and read every gzip stream to EOF.')
    command.set_defaults(run=verify)
    args = parser.parse_args()
    if args.command == 'strings' and args.limit < 1:
        parser.error('--limit must be positive')
    try:
        return args.run(args) or 0
    except (OSError, ValueError, EOFError) as exc:
        print(str(exc), file=sys.stderr)
        return 1


if __name__ == '__main__':
    raise SystemExit(main())
