# NvUI.dll

`b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597`

## Identity

| Property | Value |
| --- | --- |
| Architecture | AMD64 |
| Source size | 9,411,184 bytes |
| Preferred image base | `0x65000000` |
| Entry RVA | `0x24b850` |
| Imports / exports | 479 / 79 |
| Exception/unwind ranges | 10,469 |
| Executable raw bytes | 2,913,280 |

Physical paths:

- `NVIDIA App\NvCpl\NvUI.dll`

## Decompilation coverage

**Complete with errors**: 16,727 successful reconstructions, 13 failures, 16,740 attempted entries, 16,740 reported discovered entries.

Counts refer to automated analysis, not manual review or recovered source code. Function boundaries can change during analysis.

## Sections

| Section | RVA | Raw offset | Raw bytes | Virtual bytes | R / W / X | Entropy |
| --- | --- | --- | ---: | ---: | --- | ---: |
| `.text` | `0x1000` | `1024` | 2,913,280 | 2,913,260 | yes / no / yes | 6.4249 |
| `.rdata` | `0x2c9000` | `2914304` | 906,240 | 906,174 | yes / no / no | 4.732 |
| `.data` | `0x3a7000` | `3820544` | 79,872 | 150,860 | yes / yes / no | 4.6287 |
| `.pdata` | `0x3cc000` | `3900416` | 125,952 | 125,628 | yes / no / no | 6.234 |
| `.didat` | `0x3eb000` | `4026368` | 2,560 | 2,136 | yes / yes / no | 2.8751 |
| `.rsrc` | `0x3ec000` | `4028928` | 5,296,640 | 5,296,602 | yes / no / no | 7.5147 |
| `.reloc` | `0x8fa000` | `9325568` | 75,264 | 75,224 | yes / no / no | 5.4486 |

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

- [PE metadata](../../evidence/pe/b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597.json)
- [Function inventory and decompilation results](../../evidence/decompiled/b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597.summary.json)
- [Reconstructed C](../../evidence/decompiled/b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597.pseudocode.c.gz)
- [Reconstructed-function line ranges](../../evidence/decompiled/b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597.spans.jsonl.gz)
- [Initial IDA function listing](../../evidence/decompiled/b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597.ida.asm.gz)
- [Capstone executable-section sweep](../../evidence/disassembly/b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597.asm.gz)
- [Sweep counts and section coverage](../../evidence/disassembly/b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597.summary.json)
- [Call candidates](../../evidence/functions/b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597.calls.jsonl.gz)
- [Recognized API references](../../evidence/api_xrefs/b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597.json)
- [Extracted strings](../../evidence/strings/b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597.jsonl.gz)
- [Selected strings](../../evidence/strings/b9d8948eedfcc5cbcd123d1b4fcd6f9c63e1cdc17ec4a6cbd3aeca7df098a597.interesting.json)

[Module catalog](../modules.md) · [Research overview](../../README.md)
