

__int64 InitializeTelemetry()
{
  unsigned int v0;
  __int64 v1;
  __int64 v2;
  __int64 v3;
  __int64 result;
  _QWORD v5[4];
  __int64 v6;
  _BYTE v7[48];

  v7[32] = 0;
  LOBYTE(v6) = 0;
  try
  {
    __wind
    {
      __wind
      {
        v0 = sub_18010F2E0((__int64)v5, (__int64)v7);
        sub_180112EB0(v5);
        sub_180112EB0(v7);
        result = v0;
      }
      __unwind
      {
        ((void (__fastcall *)(_QWORD *, __int64, __int64, __int64))sub_1801105A0)(v5, v1, v2, v3);
      }
    }
    __unwind
    {
      ((void (__fastcall *)(_BYTE *, __int64, __int64, __int64, _QWORD, _QWORD, _QWORD, _QWORD, __int64))sub_1801105A0)(
        v7,
        v1,
        v2,
        v3,
        v5[0],
        v5[1],
        v5[2],
        v5[3],
        v6);
    }
  }
  catch ( ... )
  {
    sub_180118998();
  }
  return result;
}
