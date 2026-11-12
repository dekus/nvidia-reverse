# nvaudcap64v.dll

`cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc`

## Identity

| Property | Value |
| --- | --- |
| Architecture | AMD64 |
| Source size | 192,232 bytes |
| Preferred image base | `0x180000000` |
| Entry RVA | `0x18d80` |
| Imports / exports | 131 / 1 |
| Exception/unwind ranges | 461 |
| Executable raw bytes | 145,920 |

Physical paths:

- `Installer2\VirtualAudio.Driver.{7C43349F-A7F0-4D47-8E5D-C03E063D8955}\nvaudcap64v.dll`

## Decompilation coverage

**Complete**: 306 successful reconstructions, 0 failures, 306 attempted entries, 306 reported discovered entries.

Counts refer to automated analysis, not manual review or recovered source code. Function boundaries can change during analysis.

## Sections

| Section | RVA | Raw offset | Raw bytes | Virtual bytes | R / W / X | Entropy |
| --- | --- | --- | ---: | ---: | --- | ---: |
| `.text` | `0x1000` | `1024` | 145,920 | 145,487 | yes / no / yes | 6.4683 |
| `.rdata` | `0x25000` | `146944` | 17,408 | 17,028 | yes / no / no | 5.0593 |
| `.data` | `0x2a000` | `164352` | 512 | 2,240 | yes / yes / no | 2.1199 |
| `.pdata` | `0x2b000` | `164864` | 5,632 | 5,532 | yes / no / no | 5.2809 |
| `.rsrc` | `0x2d000` | `170496` | 1,024 | 936 | yes / no / no | 3.0546 |
| `.reloc` | `0x2e000` | `171520` | 512 | 144 | yes / no / no | 2.0213 |

## PE mitigation flags

| Flag | Present |
| --- | --- |
| dynamic_base | true |
| high_entropy_va | true |
| nx_compat | true |
| guard_cf_flag | true |
| no_seh | false |
| appcontainer | false |
| force_integrity | false |

## Evidence

Large artifacts require Git LFS. A filename hash identifies the original PE; the content of a generated artifact has a different digest.

- [PE metadata](../../evidence/pe/cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc.json)
- [Function inventory and decompilation results](../../evidence/decompiled/cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc.summary.json)
- [Reconstructed C](../../evidence/decompiled/cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc.pseudocode.c.gz)
- [Reconstructed-function line ranges](../../evidence/decompiled/cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc.spans.jsonl.gz)
- [Initial IDA function listing](../../evidence/decompiled/cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc.ida.asm.gz)
- [Capstone executable-section sweep](../../evidence/disassembly/cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc.asm.gz)
- [Sweep counts and section coverage](../../evidence/disassembly/cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc.summary.json)
- [Call candidates](../../evidence/functions/cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc.calls.jsonl.gz)
- [Recognized API references](../../evidence/api_xrefs/cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc.json)
- [Extracted strings](../../evidence/strings/cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc.jsonl.gz)
- [Selected strings](../../evidence/strings/cfaffaea819a28bc1c837a8da021afe8da3cc22b787a2ecca8ec90e04109ebcc.interesting.json)

[Module catalog](../modules.md) · [Research overview](../../README.md)
