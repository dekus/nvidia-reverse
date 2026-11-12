
__int64 __fastcall InitializeTelemetry_2(__int64 a1, __int64 a2)
{
  __int64 v3;
  __int64 v4;
  unsigned int v5;
  __int64 result;
  __int64 v7;
  __int64 v8;
  __int64 v9;
  __int64 v10;
  __int64 v11;
  __int64 v12;
  __int64 v13;
  __int64 v14;
  __int64 v15;
  __int64 v16;
  __int64 v17;
  __int64 v18;
  __int64 v19;
  __int64 v20;
  __int64 v21;
  __int64 v22;
  __int64 v23;
  __int64 v24;
  __int64 v25[4];
  __int64 v26[4];
  _QWORD v27[4];
  char v28;
  _QWORD v29[4];
  char v30;
  _BYTE pExceptionObject[24];
  _BYTE v32[24];
  _BYTE v33[256];
  int v34;

  if ( a1 == 0 )
  {
    sub_1803348E0(v33, 0, 248);
    __eh34_enter_try_state(-1, 0);
    v7 = sub_1801109E0(v33);
    __eh34_enter_wind_state(0, 1);
    v8 = sub_1801167D0(v7, "Invalid argument. ");
    v9 = sub_1801167F0(v8);
    v10 = sub_180116820(v9, sub_18010E9B0);
    v11 = sub_180116850(v10);
    v12 = sub_1801167D0(
            v11,
            "C:\\dvs\\p4\\build\\sw\\gcomp\\rel\\src\\NvTelemetry\\NvTelemetryAPI\\src\\NvTelemetryAPI.cpp");
    v13 = sub_1801167D0(v12, ":");
    v34 = 102;
    v14 = sub_180116880(v13, &v34);
    v15 = sub_1801167D0(v14, "]");
    std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::str(v15, (__int64)v25);
    __eh34_enter_wind_state(1, 2);
    sub_18010DE40((__int64)pExceptionObject, v25);
    throw (std::invalid_argument *)pExceptionObject;
  }
  __eh34_enter_try_state(-1, 0);
  if ( a2 == 0 )
  {
    sub_1803348E0(v33, 0, 248);
    v16 = sub_1801109E0(v33);
    __eh34_enter_wind_state(0, 1);
    v17 = sub_1801167D0(v16, "Invalid argument. ");
    v18 = sub_1801167F0(v17);
    v19 = sub_180116820(v18, sub_18010E9B0);
    v20 = sub_180116850(v19);
    v21 = sub_1801167D0(
            v20,
            "C:\\dvs\\p4\\build\\sw\\gcomp\\rel\\src\\NvTelemetry\\NvTelemetryAPI\\src\\NvTelemetryAPI.cpp");
    v22 = sub_1801167D0(v21, ":");
    v34 = 103;
    v23 = sub_180116880(v22, &v34);
    v24 = sub_1801167D0(v23, "]");
    std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>>::str(v24, (__int64)v25);
    __eh34_enter_wind_state(1, 2);
    sub_18010DE40((__int64)v32, v25);
    throw (std::invalid_argument *)v32;
  }
  v3 = -1;
  v4 = -1;
  do
    ++v4;
  while ( *(_WORD *)(a2 + 2 * v4) != 0 );
  memset(v26, 0, sizeof(v26));
  sub_180116B50(v26, a2);
  qmemcpy(v29, v26, sizeof(v29));
  *(__m128i *)&v26[2] = _mm_load_si128((const __m128i *)&xmmword_180447800);
  LOWORD(v26[0]) = 0;
  v30 = 1;
  do
    ++v3;
  while ( *(_WORD *)(a1 + 2 * v3) != 0 );
  __wind
  {
    __wind
    {
      memset(v25, 0, sizeof(v25));
      sub_180116B50(v25, a1);
      __wind
      {
        __wind
        {
          qmemcpy(v27, v25, sizeof(v27));
          *(__m128i *)&v25[2] = _mm_load_si128((const __m128i *)&xmmword_180447800);
          LOWORD(v25[0]) = 0;
          v28 = 1;
          v5 = sub_18010F2E0((__int64)v27, (__int64)v29);
          sub_180112EB0(v27);
          sub_180112EB0(v29);
          result = v5;
        }
        __unwind
        {
          sub_1801105A0((__int64)v27);
        }
      }
      __unwind
      {
        sub_18010EFA0(v25);
      }
    }
    __unwind
    {
      sub_1801105A0((__int64)v29);
    }
  }
  __unwind
  {
    sub_18010EFA0(v26);
  }
  if ( __eh34_catch(0) )
  {
    if ( __eh34_catch_ellipsis(0) )
      sub_180118998();
  }
  __eh34_exit_try_state(0, -1);
  return result;
}
