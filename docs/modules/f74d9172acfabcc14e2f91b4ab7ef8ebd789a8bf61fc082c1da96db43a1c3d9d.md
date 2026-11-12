# FrameViewKMDServiceContainerPlugin_x64.dll

`f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d`

## Identity

| Property | Value |
| --- | --- |
| Architecture | AMD64 |
| Source size | 151,152 bytes |
| Preferred image base | `0x180000000` |
| Entry RVA | `0xd540` |
| Imports / exports | 215 / 1 |
| Exception/unwind ranges | 299 |
| Executable raw bytes | 58,880 |

Physical paths:

- `FrameViewSDK\FvContainer\plugins.system\FrameViewKMDServiceContainerPlugin_x64.dll`

## Decompilation coverage

**Complete**: 395 successful reconstructions, 0 failures, 395 attempted entries, 395 reported discovered entries.

Counts refer to automated analysis, not manual review or recovered source code. Function boundaries can change during analysis.

## Sections

| Section | RVA | Raw offset | Raw bytes | Virtual bytes | R / W / X | Entropy |
| --- | --- | --- | ---: | ---: | --- | ---: |
| `.text` | `0x1000` | `1024` | 58,880 | 58,571 | yes / no / yes | 6.1367 |
| `.rdata` | `0x10000` | `59904` | 42,496 | 42,382 | yes / no / no | 4.5378 |
| `.data` | `0x1b000` | `102400` | 3,072 | 5,784 | yes / yes / no | 3.8114 |
| `.pdata` | `0x1d000` | `105472` | 4,096 | 3,588 | yes / no / no | 4.4679 |
| `.rsrc` | `0x1e000` | `109568` | 30,720 | 30,520 | yes / no / no | 6.5712 |
| `.reloc` | `0x26000` | `140288` | 512 | 344 | yes / no / no | 4.1787 |

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

- [PE metadata](../../evidence/pe/f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d.json)
- [Function inventory and decompilation results](../../evidence/decompiled/f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d.summary.json)
- [Reconstructed C](../../evidence/decompiled/f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d.pseudocode.c.gz)
- [Reconstructed-function line ranges](../../evidence/decompiled/f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d.spans.jsonl.gz)
- [Initial IDA function listing](../../evidence/decompiled/f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d.ida.asm.gz)
- [Capstone executable-section sweep](../../evidence/disassembly/f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d.asm.gz)
- [Sweep counts and section coverage](../../evidence/disassembly/f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d.summary.json)
- [Call candidates](../../evidence/functions/f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d.calls.jsonl.gz)
- [Recognized API references](../../evidence/api_xrefs/f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d.json)
- [Extracted strings](../../evidence/strings/f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d.jsonl.gz)
- [Selected strings](../../evidence/strings/f74d9172acfabcc14e2f91b4ab7ef8ebd789a8bf61fc082c1da96db43a1c3d9d.interesting.json)

[Module catalog](../modules.md) · [Research overview](../../README.md)
