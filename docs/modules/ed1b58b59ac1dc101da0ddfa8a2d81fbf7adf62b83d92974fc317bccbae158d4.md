# nvrla.exe

`ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4`

## Identity

| Property | Value |
| --- | --- |
| Architecture | AMD64 |
| Source size | 1,388,656 bytes |
| Preferred image base | `0x140000000` |
| Entry RVA | `0xc9110` |
| Imports / exports | 211 / 0 |
| Exception/unwind ranges | 4,295 |
| Executable raw bytes | 1,046,528 |

Physical paths:

- `FrameViewSDK\bin\nvrla.exe`

## Decompilation coverage

**Complete**: 4,052 successful reconstructions, 0 failures, 4,052 attempted entries, 4,052 reported discovered entries.

Counts refer to automated analysis, not manual review or recovered source code. Function boundaries can change during analysis.

## Sections

| Section | RVA | Raw offset | Raw bytes | Virtual bytes | R / W / X | Entropy |
| --- | --- | --- | ---: | ---: | --- | ---: |
| `.text` | `0x1000` | `1024` | 1,046,528 | 1,046,108 | yes / no / yes | 6.4347 |
| `.rdata` | `0x101000` | `1047552` | 256,512 | 256,350 | yes / no / no | 5.4802 |
| `.data` | `0x140000` | `1304064` | 14,336 | 46,092 | yes / yes / no | 4.1775 |
| `.pdata` | `0x14c000` | `1318400` | 51,712 | 51,540 | yes / no / no | 6.0858 |
| `.didat` | `0x159000` | `1370112` | 512 | 472 | yes / yes / no | 3.1453 |
| `_RDATA` | `0x15a000` | `1370624` | 512 | 500 | yes / no / no | 4.1977 |
| `.rsrc` | `0x15b000` | `1371136` | 512 | 480 | yes / no / no | 4.7177 |
| `.reloc` | `0x15c000` | `1371648` | 6,656 | 6,352 | yes / no / no | 5.3592 |

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

- [PE metadata](../../evidence/pe/ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4.json)
- [Function inventory and decompilation results](../../evidence/decompiled/ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4.summary.json)
- [Reconstructed C](../../evidence/decompiled/ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4.pseudocode.c.gz)
- [Reconstructed-function line ranges](../../evidence/decompiled/ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4.spans.jsonl.gz)
- [Initial IDA function listing](../../evidence/decompiled/ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4.ida.asm.gz)
- [Capstone executable-section sweep](../../evidence/disassembly/ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4.asm.gz)
- [Sweep counts and section coverage](../../evidence/disassembly/ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4.summary.json)
- [Call candidates](../../evidence/functions/ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4.calls.jsonl.gz)
- [Recognized API references](../../evidence/api_xrefs/ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4.json)
- [Extracted strings](../../evidence/strings/ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4.jsonl.gz)
- [Selected strings](../../evidence/strings/ed1b58b59ac1dc101da0ddfa8a2d81fbf7adf62b83d92974fc317bccbae158d4.interesting.json)

[Module catalog](../modules.md) · [Research overview](../../README.md)
