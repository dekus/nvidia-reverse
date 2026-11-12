
__int64 __fastcall GetUserTelemetryConsent(__int64 a1, __int64 a2)
{
  int v4;
  char v5;
  int v7;
  char v8;

  if ( (unsigned int)sub_1801455D4(&unk_180478B50) != 0 )
    std::_Throw_Cpp_error(5);
  if ( dword_180478B9C == 0x7FFFFFFF )
  {
    dword_180478B9C = 2147483646;
    std::_Throw_Cpp_error(6);
  }
  while ( byte_180478C34 != 0 || dword_180478C30 == -1 )
    sub_180144B2C(&unk_180478BE8, &unk_180478B50);
  ++dword_180478C30;
  Mtx_unlock((_Mtx_t)&unk_180478B50);
  if ( qword_180478D80 != 0 )
  {
    (*(void (__fastcall **)(_QWORD, __int64, __int64))(**(_QWORD **)(qword_180478D80 + 424) + 64LL))(
      *(_QWORD *)(qword_180478D80 + 424),
      a1,
      a2);
    if ( (unsigned int)sub_1801455D4(&unk_180478B50) != 0 )
      std::_Throw_Cpp_error(5);
    if ( dword_180478B9C == 0x7FFFFFFF )
    {
      dword_180478B9C = 2147483646;
      std::_Throw_Cpp_error(6);
    }
    v7 = --dword_180478C30;
    v8 = byte_180478C34;
    Mtx_unlock((_Mtx_t)&unk_180478B50);
    if ( v8 != 0 )
    {
      if ( v7 == 0 )
        sub_180144A44(&unk_180478BA0);
    }
    else if ( v7 == -2 )
    {
      sub_180144A20(&unk_180478BE8);
    }
    return 0;
  }
  else
  {
    if ( (unsigned int)sub_1801455D4(&unk_180478B50) != 0 )
      std::_Throw_Cpp_error(5);
    if ( dword_180478B9C == 0x7FFFFFFF )
    {
      dword_180478B9C = 2147483646;
      std::_Throw_Cpp_error(6);
    }
    v4 = --dword_180478C30;
    v5 = byte_180478C34;
    Mtx_unlock((_Mtx_t)&unk_180478B50);
    if ( v5 != 0 )
    {
      if ( v4 == 0 )
        sub_180144A44(&unk_180478BA0);
    }
    else if ( v4 == -2 )
    {
      sub_180144A20(&unk_180478BE8);
    }
    return 2147947423LL;
  }
}
