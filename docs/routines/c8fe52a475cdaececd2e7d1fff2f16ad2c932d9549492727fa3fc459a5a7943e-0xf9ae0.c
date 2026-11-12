
char __fastcall sub_1800F9AE0(__int64 a1, _QWORD *a2)
{
  __int64 v4;
  __int64 v5;
  _QWORD *v6;
  _QWORD *v7;
  _QWORD *v8;
  _QWORD *v9;
  __int64 v10;
  unsigned __int8 v11;
  int v12;
  unsigned __int64 *v13;
  unsigned __int64 v14;
  const void *v15;
  unsigned __int64 v16;
  _BYTE *v17;
  _BYTE *i;
  _BYTE *v19;
  _BYTE *v20;
  _BYTE *j;
  _BYTE *v22;
  _BYTE *v23;
  _BYTE *k;
  _BYTE *v25;
  _BYTE *v26;
  _BYTE *m;
  _BYTE *v28;
  char result;
  const char *v30;
  const char *v31;
  int v32;
  __int64 v33;
  void (__fastcall *v34)(__int64, _QWORD, __int64, void **, __int64, char *);
  __int64 v35;
  __int64 v36;
  void *v37;
  void *v38;
  _BYTE *v39;
  char v40[8];
  void *v41;
  __int128 v42;
  _QWORD v43[2];
  __int64 v44;
  __int64 v45;
  void *Block[2];
  __m128i si128;
  void *v48[2];
  __m128i v49;

  *(_OWORD *)v43 = 0;
  v44 = 6;
  v45 = 15;
  strcpy((char *)v43, "origin");
  v4 = sub_18000AF10();
  v5 = a2[11];
  v6 = *(_QWORD **)(v5 + 16 * (v4 & a2[14]) + 8);
  v7 = (_QWORD *)a2[9];
  if ( v6 == v7 )
  {
LABEL_14:
    v6 = nullptr;
  }
  else
  {
    v8 = *(_QWORD **)(v5 + 16 * (v4 & a2[14]));
    while ( 1 )
    {
      v9 = v6 + 2;
      if ( v6[5] > 0xFu )
        v9 = (_QWORD *)*v9;
      if ( v6[4] == 6 )
      {
        v10 = 0;
        while ( 1 )
        {
          v11 = *((_BYTE *)v43 + v10++);
          if ( v11 != *((_BYTE *)v9 + v10 - 1) )
            break;
          if ( v10 == 6 )
          {
            v12 = 0;
            goto LABEL_11;
          }
        }
        v12 = v11 < *((_BYTE *)v9 + v10 - 1) ? -1 : 1;
LABEL_11:
        if ( v12 == 0 )
          break;
      }
      if ( v6 == v8 )
        goto LABEL_14;
      v6 = (_QWORD *)v6[1];
    }
  }
  if ( v6 == nullptr )
    return 1;
  v44 = 0;
  v45 = 15;
  LOBYTE(v43[0]) = 0;
  if ( v6 == v7 )
    return 1;
  v13 = v6 + 6;
  v14 = v13[2];
  v15 = v13;
  v16 = v13[3];
  if ( v16 > 0xF )
    v15 = (const void *)*v13;
  if ( v14 == 4 && memcmp(v15, "null", 4u) == 0 )
    return 1;
  v17 = v13;
  if ( v16 > 0xF )
    v17 = (_BYTE *)*v13;
  if ( v14 >= 0x10 )
  {
    for ( i = v17; *i != 104 || memcmp(i, "http://localhost", 0x10u) != 0; --i )
    {
      if ( i == v17 )
        goto LABEL_34;
    }
    if ( i == v17 )
    {
      if ( v13[2] == 16 )
        return 1;
      v19 = v13;
      if ( v16 > 0xF )
        v19 = (_BYTE *)*v13;
      if ( v19[16] == 58 )
        return 1;
    }
  }
LABEL_34:
  v20 = v13;
  if ( v16 > 0xF )
    v20 = (_BYTE *)*v13;
  if ( v13[2] >= 0x10 )
  {
    for ( j = v20; *j != 104 || memcmp(j, "http://127.0.0.1", 0x10u) != 0; --j )
    {
      if ( j == v20 )
        goto LABEL_47;
    }
    if ( j == v20 )
    {
      if ( v13[2] == 16 )
        return 1;
      v22 = v13;
      if ( v16 > 0xF )
        v22 = (_BYTE *)*v13;
      if ( v22[16] == 58 )
        return 1;
    }
  }
LABEL_47:
  v23 = v13;
  if ( v16 > 0xF )
    v23 = (_BYTE *)*v13;
  if ( v13[2] >= 0x11 )
  {
    for ( k = v23; *k != 104 || memcmp(k, "https://localhost", 0x11u) != 0; --k )
    {
      if ( k == v23 )
        goto LABEL_60;
    }
    if ( k == v23 )
    {
      if ( v13[2] == 17 )
        return 1;
      v25 = v13;
      if ( v16 > 0xF )
        v25 = (_BYTE *)*v13;
      if ( v25[17] == 58 )
        return 1;
    }
  }
LABEL_60:
  v26 = v13;
  if ( v16 > 0xF )
    v26 = (_BYTE *)*v13;
  if ( v13[2] >= 0x11 )
  {
    for ( m = v26; *m != 104 || memcmp(m, "https://127.0.0.1", 0x11u) != 0; --m )
    {
      if ( m == v26 )
        goto LABEL_74;
    }
    if ( m == v26 )
    {
      if ( v13[2] == 17 )
        return 1;
      v28 = v13;
      if ( v16 > 0xF )
        v28 = (_BYTE *)*v13;
      if ( v28[17] == 58 )
        return 1;
    }
  }
LABEL_74:
  if ( v13[3] > 0xF )
    v13 = (unsigned __int64 *)*v13;
  v30 = "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\transport\\H"
        "ttpTransport.cpp";
  if ( strrchr(
         "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\transport\\"
         "HttpTransport.cpp",
         92) != nullptr )
    v31 = strrchr(
            "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\transpor"
            "t\\HttpTransport.cpp",
            92)
        + 1;
  else
    v31 = "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\transport\\"
          "HttpTransport.cpp";
  if ( strrchr(v31, 47) != nullptr )
  {
    if ( strrchr(
           "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\transport"
           "\\HttpTransport.cpp",
           92) != nullptr )
      v30 = strrchr(
              "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\transp"
              "ort\\HttpTransport.cpp",
              92)
          + 1;
    v32 = 47;
  }
  else
  {
    if ( strrchr(
           "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\transport"
           "\\HttpTransport.cpp",
           92) == nullptr )
      goto LABEL_86;
    v32 = 92;
  }
  v30 = strrchr(v30, v32) + 1;
LABEL_86:
  GXP::LogMessage(1, v30, 522, "HttpTransport: rejected request with invalid Origin: %s", (const char *)v13);
  v33 = *(_QWORD *)(a1 + 136);
  v34 = *(void (__fastcall **)(__int64, _QWORD, __int64, void **, __int64, char *))(*(_QWORD *)v33 + 40LL);
  sub_180010CE0();
  __wind
  {
    v35 = sub_1800EBD00((__int64)v48, -32600, "Forbidden: invalid origin", 0);
    v36 = v35;
    __wind
    {
      *(_OWORD *)Block = 0;
      si128 = 0;
      _mm_lfence();
      Block[0] = operator new(0x20u);
      si128 = _mm_load_si128((const __m128i *)&xmmword_18021CE60);
      strcpy((char *)Block[0], "application/json");
      __wind
      {
        v34(v33, a2[20], 403, Block, v36, v40);
      }
      __unwind
      {
        sub_1800084D0(Block);
      }
      if ( si128.m128i_i64[1] > 0xFuLL )
      {
        v37 = Block[0];
        if ( (unsigned __int64)(si128.m128i_i64[1] + 1) >= 0x1000 )
        {
          v37 = *((void **)Block[0] - 1);
          if ( (unsigned __int64)((char *)Block[0] - (char *)v37 - 8) > 0x1F )
            _invalid_parameter_noinfo_noreturn();
        }
        j_j_j_j_free(v37);
      }
      si128 = _mm_load_si128((const __m128i *)&xmmword_180217880);
      LOBYTE(Block[0]) = 0;
      if ( v49.m128i_i64[1] > 0xFuLL )
      {
        v38 = v48[0];
        if ( (unsigned __int64)(v49.m128i_i64[1] + 1) >= 0x1000 )
        {
          v38 = *((void **)v48[0] - 1);
          if ( (unsigned __int64)((char *)v48[0] - (char *)v38 - 8) > 0x1F )
            _invalid_parameter_noinfo_noreturn();
        }
        j_j_j_j_free(v38);
      }
      v49 = _mm_load_si128((const __m128i *)&xmmword_180217880);
      LOBYTE(v48[0]) = 0;
      v39 = v41;
      if ( v41 != nullptr )
      {
        if ( ((*((_QWORD *)&v42 + 1) - (_QWORD)v41) & 0xFFFFFFFFFFFFFFF8uLL) >= 0x1000 )
        {
          v39 = *((_BYTE **)v41 - 1);
          if ( (unsigned __int64)((_BYTE *)v41 - v39 - 8) > 0x1F )
            _invalid_parameter_noinfo_noreturn();
        }
        j_j_j_j_free(v39);
        v41 = nullptr;
        v42 = 0;
      }
      sub_1800229A0();
      result = 0;
    }
    __unwind
    {
      sub_1800084D0(v48);
    }
  }
  __unwind
  {
    sub_180029E20();
  }
  return result;
}
