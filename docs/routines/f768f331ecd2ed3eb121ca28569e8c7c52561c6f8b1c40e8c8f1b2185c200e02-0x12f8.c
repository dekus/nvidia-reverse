
char __fastcall sub_1400012F8(__int64 a1, unsigned __int8 a2, unsigned int a3, __int64 a4, __int64 a5)
{
  __int64 v5;
  ULONG v6;

  v5 = 0;
  v6 = (32 * (a2 & 7)) | (a2 >> 3);
  if ( a3 == 0 )
    return 1;
  while ( HalSetBusDataByOffset(PCIConfiguration, 0, v6, (PVOID)(a4 + 4 * v5), 0x60u, 4u) == 4
       && HalGetBusDataByOffset(PCIConfiguration, 0, v6, (PVOID)(a5 + 4 * v5), 0x64u, 4u) == 4 )
  {
    v5 = (unsigned int)(v5 + 1);
    if ( (unsigned int)v5 >= a3 )
      return 1;
  }
  return 0;
}
