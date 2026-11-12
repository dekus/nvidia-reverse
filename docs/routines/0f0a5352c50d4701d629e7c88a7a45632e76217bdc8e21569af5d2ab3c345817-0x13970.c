
__int64 __fastcall sub_140013970(__int64 *a1, __int64 a2)
{
  char v2;
  __int64 v4;
  void (__fastcall *v5)(__int64, char *, __int128 *);
  unsigned __int64 v6;
  void *v7;
  char *v8;
  __int64 v9;
  __int64 v10;
  DWORD LastError;
  char *v12;
  DWORD v13;
  char *v14;
  char *v15;
  const nvc::ConfigErrorException *v17;
  _QWORD *v18;
  const char *v19;
  __int64 v20;
  __int64 v21;
  DWORD v22;
  __int64 v23;
  __int64 *v24;
  __int64 v25;
  const nvc::ConfigErrorException *v26;
  const std::exception *v27;
  int v28[4];
  char v29[16];
  char v30[24];
  unsigned __int64 v31;
  __int128 v32;
  __m128i si128;

  v2 = a2;
  v24 = a1;
  v25 = a2;
  v23 = 0;
  v4 = a1[4];
  v5 = *(void (__fastcall **)(__int64, char *, __int128 *))(*(_QWORD *)v4 + 16LL);
  v32 = 0;
  si128 = 0;
  v6 = -1;
  do
    ++v6;
  while ( *(_WORD *)(a2 + 2 * v6) != 0 );
  try
  {
    sub_1400037F0(&v32, a2, v6);
    __wind
    {
      v5(v4, v30, &v32);
      if ( si128.m128i_i64[1] > 7uLL )
      {
        v7 = (void *)v32;
        if ( (unsigned __int64)(2 * si128.m128i_i64[1] + 2) >= 0x1000 )
        {
          v7 = *(void **)(v32 - 8);
          if ( (unsigned __int64)(v32 - (_QWORD)v7 - 8) > 0x1F )
            invalid_parameter_noinfo_noreturn();
        }
        j_j_free_0(v7);
      }
      si128 = _mm_load_si128((const __m128i *)&xmmword_14012C600);
      LOWORD(v32) = 0;
      v8 = v30;
      if ( v31 > 7 )
        v8 = *(char **)v30;
    }
    __unwind
    {
      sub_140002470(&v32);
    }
    __wind
    {
      v9 = sub_140013C10(a1, v8, 0);
      v23 = v9;
      strcpy(v29, "lperWin32.cpp");
      *(__m128i *)v28 = _mm_load_si128((const __m128i *)&xmmword_14012FE50);
      if ( v9 != 0 )
      {
        sub_1400229E0(*a1, (int)v28, 140, 3, (wchar_t *)L"Loaded dependency module %ls", v2);
      }
      else
      {
        v10 = *a1;
        LastError = GetLastError();
        v12 = v30;
        if ( v31 > 7 )
          LOBYTE(v12) = v30[0];
        v22 = LastError;
        sub_1400229E0(v10, (int)v28, 144, 1, (wchar_t *)L"Failed to load dependency %ls. Error %u", (char)v12);
        v13 = GetLastError();
        v14 = v30;
        if ( v31 > 7 )
          v14 = *(char **)v30;
        sub_140007F90(0x1Du, L"Failed to load dependency %ls. Error %u", v14, v13);
      }
    }
    __unwind
    {
      sub_140002470(v30);
    }
    if ( v31 > 7 )
    {
      v15 = *(char **)v30;
      if ( 2 * v31 + 2 >= 0x1000 )
      {
        v15 = *(char **)(*(_QWORD *)v30 - 8LL);
        if ( (unsigned __int64)(*(_QWORD *)v30 - (_QWORD)v15 - 8LL) > 0x1F )
          invalid_parameter_noinfo_noreturn();
      }
      j_j_free_0(v15);
    }
  }
  catch ( const nvc::ConfigErrorException *v26 )
  {
    *(__m128i *)v28 = _mm_load_si128((const __m128i *)&xmmword_14012FE50);
    strcpy(v29, "lperWin32.cpp");
    v17 = v26;
    v18 = (_QWORD *)((char *)v26 + 24);
    if ( *((_QWORD *)v26 + 6) > 0xFu )
      v18 = (_QWORD *)*v18;
    sub_140022750(*v24, (int)v28, 149, 1, "%s", (char)v18);
    v19 = (char *)v17 + 24;
    if ( *((_QWORD *)v17 + 6) > 0xFu )
      v19 = *(const char **)v19;
    sub_140007ED0(0x1Fu, "%s", v19);
    return v23;
  }
  catch ( const std::exception *v27 )
  {
    *(__m128i *)v28 = _mm_load_si128((const __m128i *)&xmmword_14012FE50);
    strcpy(v29, "lperWin32.cpp");
    v20 = *v24;
    (*(void (__fastcall **)(const std::exception *))(*(_QWORD *)v27 + 8LL))(v27);
    sub_140005CE0((__int64)&v32);
    __wind
    {
      sub_1400229E0(
        v20,
        (unsigned int)&v21 + 104,
        153,
        2,
        (wchar_t *)L"Skipping loading dependency module %ls, reason: %ls",
        v25);
    }
    __unwind
    {
      sub_140002470(&v32);
    }
    if ( si128.m128i_i64[1] > 7uLL )
      std::wstring::_Deallocate_for_capacity((__int64)&v32, (void *)v32, si128.m128i_i64[1]);
    return v23;
  }
  return v9;
}
