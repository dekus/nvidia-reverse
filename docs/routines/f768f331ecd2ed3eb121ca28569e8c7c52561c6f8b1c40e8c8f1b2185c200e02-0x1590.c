
int __fastcall sub_140001590(__int64 a1)
{
  char v17;
  int v18;
  __int64 v19;
  char Str1[4];
  int v22;
  int v23;
  __int128 v24;
  int v25;

  _RAX = 0;
  __asm { cpuid }
  if ( (int)_RAX >= 1 )
  {
    v25 = 0;
    *(_QWORD *)(a1 + 24) = 0;
    _RAX = 0;
    __asm { cpuid }
    v23 = _RCX;
    _RAX = 1;
    *(_DWORD *)Str1 = _RBX;
    v22 = _RDX;
    __asm { cpuid }
    v17 = (_RDX & 0x20) != 0;
    v18 = _RAX;
    v24 = 0;
    if ( strncmp(Str1, "GenuineIntel", 0x20u) == 0 )
    {
      LOBYTE(v19) = v17;
      _RAX = sub_140001A98(v19);
LABEL_7:
      *(_QWORD *)(a1 + 24) = _RAX;
      return _RAX;
    }
    LODWORD(_RAX) = strncmp(Str1, "AuthenticAMD", 0x20u);
    if ( (_DWORD)_RAX == 0 )
    {
      *(_QWORD *)(a1 + 24) = sub_140001194(v17);
      LODWORD(_RAX) = v18 >> 20;
      if ( ((v18 >> 8) & 0xF) + (unsigned __int8)(v18 >> 20) == 23 )
      {
        _RAX = sub_140001194(v17);
        goto LABEL_7;
      }
    }
  }
  return _RAX;
}
