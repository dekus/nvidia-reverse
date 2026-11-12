
char __fastcall sub_1400019D0(__int64 a1)
{
  char result;
  unsigned int v3[12];
  __int64 v4;
  _BYTE v5[72];

  v4 = -1;
  v3[0] = 412;
  v3[1] = 418;
  v3[2] = 408;
  v3[3] = 206;
  v3[4] = 433;
  v3[5] = 1542;
  v3[6] = 1556;
  v3[7] = 1553;
  v3[8] = 1561;
  v3[9] = 1593;
  sub_140001F80(v5, 0, 72);
  result = sub_140001288(a1, 0xAu, v3, (__int64)&v4);
  if ( result == 1 )
    return sub_1400011F0(a1, 10, (__int64)v3, (__int64)&v4);
  return result;
}
