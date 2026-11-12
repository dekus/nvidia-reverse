
_BOOL8 __fastcall sub_140013EC0(__int64 *a1, WCHAR *a2, __int64 *a3)
{
  __int64 *v3;
  WCHAR *v4;
  char v6;
  DWORD LastError;
  DWORD CurrentDirectoryW;
  int v10;
  HINSTANCE Library;
  int StringW;
  __int64 v13;
  __int64 v14;
  wchar_t *v15;
  unsigned __int64 v16;
  char *v17;
  char *v18;
  __int64 v19;
  wchar_t *v20;
  __int64 v21;
  wchar_t *v22;
  char *v23;
  __int64 v24;
  __int64 v25;
  wchar_t *v26;
  char *v27;
  HMODULE *i;
  bool v29;
  char *v30;
  _BOOL8 result;
  __int64 v32;
  char v33;
  __int64 v34;
  char v35;
  DWORD dwErrCode;
  __int16 v37[2];
  UINT uMode;
  void *Block[2];
  char *v40;
  __int128 v41;
  wchar_t *v42;
  WCHAR v43[4];
  wchar_t *Context;
  WCHAR *v45;
  __int64 v46;
  __int64 *v47;
  __int64 *v48;
  HMODULE hLibModule;
  __int64 *v50;
  const std::exception *v51;
  int v52[4];
  char v53[16];
  wchar_t Delimiter[4];
  WCHAR Buffer[264];

  v3 = a3;
  v47 = a3;
  v4 = a2;
  v45 = a2;
  v48 = a1;
  v50 = a3;
  uMode = GetErrorMode();
  SetErrorMode(uMode | 1);
  v6 = 1;
  v35 = 1;
  *(_OWORD *)Block = 0;
  v40 = nullptr;
  LastError = 0;
  dwErrCode = 0;
  if ( PathIsRelativeW(v4) )
  {
    CurrentDirectoryW = GetCurrentDirectoryW(0x104u, Buffer);
    if ( CurrentDirectoryW != 0 )
    {
      wcscat_s(Buffer, 0x104u, ::Delimiter);
      wcscat_s(Buffer, 0x104u, v4);
      v4 = Buffer;
      v45 = Buffer;
    }
  }
  __wind
  {
    __wind
    {
      v10 = sub_14001E730();
      Library = LoadLibraryExW(v4, nullptr, 2u);
      hLibModule = Library;
      if ( Library != nullptr )
      {
        if ( a1[6] != 0 )
          *(_DWORD *)(a1[6] + 60) = sub_14001E730() - v10;
        *(_QWORD *)v43 = 0;
        StringW = LoadStringW(Library, 0x29BBu, v43, 0);
        if ( StringW != 0 )
        {
          try
          {
            v13 = *(_QWORD *)v43;
            v14 = *(_QWORD *)v43 + 2LL * StringW;
            v41 = 0;
            v15 = nullptr;
            v42 = nullptr;
            v16 = (2LL * StringW) >> 1;
            v17 = nullptr;
            v18 = nullptr;
            if ( v16 != 0 )
            {
              if ( v16 > 0x7FFFFFFFFFFFFFFFLL )
                unknown_libname_55(0x7FFFFFFFFFFFFFFFLL, 0);
              _mm_lfence();
              v19 = v16;
              v20 = (wchar_t *)sub_1400035E0(2 * v16);
              *(_QWORD *)&v41 = v20;
              v15 = &v20[v19];
              v42 = &v20[v19];
              v21 = v14 - v13;
              sub_140122450(v20, v13, v21);
              v21 >>= 1;
              v17 = (char *)&v20[v21];
              *((_QWORD *)&v41 + 1) = v17;
              v18 = (char *)&v20[v19];
              LastError = dwErrCode;
            }
            else
            {
              v20 = (wchar_t *)v41;
            }
            __wind
            {
              v37[0] = 0;
              if ( v17 == v18 )
              {
                sub_140012410((char **)&v41, v17, v37);
                v15 = v42;
                v20 = (wchar_t *)v41;
              }
              else
              {
                *(_WORD *)v17 = 0;
                *((_QWORD *)&v41 + 1) = v17 + 2;
              }
              wcscpy(Delimiter, L",; ");
              Context = nullptr;
              v22 = wcstok_s(v20, Delimiter, &Context);
              v23 = (char *)Block[1];
              while ( 1 )
              {
                v24 = (__int64)v22;
                if ( v22 == nullptr )
                  break;
                if ( GetModuleHandleW(v22) != nullptr )
                {
                  *(__m128i *)v52 = _mm_load_si128((const __m128i *)&xmmword_14012FE50);
                  strcpy(v53, "lperWin32.cpp");
                  sub_1400229E0(*a1, (int)v52, 216, 3, (wchar_t *)L"Dependency module %ls has been loaded already", v24);
                  v22 = wcstok_s(nullptr, Delimiter, &Context);
                }
                else
                {
                  v25 = sub_140013970(a1, v24);
                  v46 = v25;
                  if ( v25 == 0 )
                  {
                    v35 = 0;
                    LastError = GetLastError();
                    dwErrCode = LastError;
                    *(__m128i *)v52 = _mm_load_si128((const __m128i *)&xmmword_14012FE50);
                    strcpy(v53, "lperWin32.cpp");
                    sub_140022750(*a1, (int)v52, 226, 1, "Dependency module load failed", LastError);
                    goto LABEL_53;
                  }
                  if ( v23 == v40 )
                  {
                    sub_1400122B0((char **)Block, v23, &v46);
                    v23 = (char *)Block[1];
                  }
                  else
                  {
                    *(_QWORD *)v23 = v25;
                    v23 += 8;
                    Block[1] = v23;
                  }
                  v22 = wcstok_s(nullptr, Delimiter, &Context);
                }
              }
            }
            __unwind
            {
              sub_140012F40((__int64)&v41);
            }
LABEL_53:
            if ( v20 != nullptr )
            {
              v26 = v20;
              if ( (unsigned __int64)(2 * (v15 - v20)) >= 0x1000 )
              {
                v20 = *((wchar_t **)v20 - 1);
                if ( (unsigned __int64)((char *)v26 - (char *)v20 - 8) > 0x1F )
                  invalid_parameter_noinfo_noreturn();
              }
              j_j_free_0(v20);
            }
            v4 = v45;
            v6 = v35;
            v3 = v47;
          }
          catch ( const std::exception *v51 )
          {
            dwErrCode = GetLastError();
            *(__m128i *)v52 = _mm_load_si128((const __m128i *)&xmmword_14012FE50);
            strcpy(v53, "lperWin32.cpp");
            v32 = *v48;
            v33 = (*(__int64 (__fastcall **)(const std::exception *))(*(_QWORD *)v51 + 8LL))(v51);
            sub_140022750(v32, (unsigned int)&v34 + 184, 240, 1, "Dependency module load exception", v33);
            FreeLibrary(hLibModule);
            v23 = (char *)Block[1];
            LastError = dwErrCode;
            v3 = v50;
            goto LABEL_37;
          }
        }
        else
        {
          v23 = (char *)Block[1];
        }
        FreeLibrary(Library);
        if ( v6 == 0 )
          goto LABEL_37;
      }
      else
      {
        v23 = (char *)Block[1];
      }
      *v3 = sub_140013C10(a1, v4, 1);
LABEL_37:
      SetErrorMode(uMode);
      v27 = (char *)Block[0];
      for ( i = (HMODULE *)Block[0]; i != (HMODULE *)v23; ++i )
        FreeLibrary(*i);
      v29 = *v3 != 0;
      if ( LastError != 0 )
        SetLastError(LastError);
      if ( v27 != nullptr )
      {
        v30 = v27;
        if ( ((v40 - v27) & 0xFFFFFFFFFFFFFFF8uLL) >= 0x1000 )
        {
          v27 = *((char **)v27 - 1);
          if ( (unsigned __int64)(v30 - v27 - 8) > 0x1F )
            invalid_parameter_noinfo_noreturn();
        }
        j_j_free_0(v27);
      }
      result = v29;
    }
    __unwind
    {
      sub_140012FC0(&dwErrCode);
    }
  }
  __unwind
  {
    sub_140012EE0((__int64)Block);
  }
  return result;
}
