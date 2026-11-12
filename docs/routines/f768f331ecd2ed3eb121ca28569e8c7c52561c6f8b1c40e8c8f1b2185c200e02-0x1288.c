
char __fastcall sub_140001288(__int64 a1, unsigned int a2, unsigned int *a3, __int64 a4)
{
  __int64 v8;

  if ( *(_BYTE *)(a1 + 8) == 0 )
    return 1;
  v8 = 0;
  if ( a2 == 0 )
    return 1;
  while ( (unsigned int)sub_140001270(a1, *a3, (_QWORD *)(a4 + 8 * v8)) == 0 )
  {
    v8 = (unsigned int)(v8 + 1);
    ++a3;
    if ( (unsigned int)v8 >= a2 )
      return 1;
  }
  return 0;
}
