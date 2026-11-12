
char __fastcall sub_14000C400(__int64 *a1, __int64 *a2)
{
  bool v2;
  __int64 *v3;
  __int64 v5;
  _QWORD *v6;
  _QWORD *v7;
  bool v8;
  _QWORD *v10;
  _QWORD *v11;
  _QWORD *v12;
  char v13;
  __int64 v14;
  __int64 v15;
  DWORD LastError;
  unsigned int *v17;
  int v18;
  int *v19;
  unsigned int v20;
  bool v21;
  __int64 v22;
  __int64 v23;
  __int64 (*v24)(void);
  __int64 v25;
  __int64 v26;
  __m128i si128;
  const char *v28;
  __int64 v29;
  __int64 v30;
  char v31;
  unsigned int v32;
  int v33[4];
  char v34[8];
  _QWORD v35[16];
  __int16 v36;
  _BYTE v37[510];
  __int16 v38;
  _BYTE v39[510];

  v2 = (unsigned __int64)a2[3] <= 7;
  v3 = a2;
  *(__m128i *)v33 = _mm_load_si128((const __m128i *)&xmmword_14012ED70);
  strcpy(v34, "r.cpp");
  LOBYTE(v5) = (_BYTE)a2;
  if ( !v2 )
    v5 = *a2;
  sub_1400229E0(*a1, (int)v33, 115, 3, (wchar_t *)L"Loading %ls", v5);
  v6 = a1 + 5;
  if ( a1 + 5 != v3 )
  {
    v7 = v3;
    if ( (unsigned __int64)v3[3] > 7 )
      v7 = (_QWORD *)*v3;
    sub_14000EE20(a1 + 5, v7, v3[2]);
  }
  v36 = 0;
  sub_140122090(v37, 0, 510);
  if ( (unsigned __int64)a1[8] > 7 )
    v6 = (_QWORD *)*v6;
  sub_14001E390(v6, &v36, 256);
  v8 = v36 != 95;
  *((_BYTE *)a1 + 72) = v36 != 95;
  if ( !v8 && (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)a1[2] + 8LL))(a1[2]) != 0 )
  {
    v2 = (unsigned __int64)v3[3] <= 7;
    *(__m128i *)v33 = _mm_load_si128((const __m128i *)&xmmword_14012ED70);
    strcpy(v34, "r.cpp");
    if ( !v2 )
      v3 = (__int64 *)*v3;
    sub_1400229E0(*a1, (int)v33, 126, 2, (wchar_t *)L"Safe mode: skip optional plugin %ls", (char)v3);
    return 0;
  }
  v10 = v3;
  if ( (unsigned __int64)v3[3] > 7 )
    v10 = (_QWORD *)*v3;
  sub_140013360(a1 + 42, v10);
  v38 = 0;
  sub_140122090(v39, 0, 510);
  v11 = a1 + 5;
  if ( (unsigned __int64)a1[8] > 7 )
    v11 = (_QWORD *)*v11;
  sub_14001E390(v11, &v38, 256);
  if ( (unsigned __int8)sub_140011950(a1 + 42, &v38, a1[4] + 1008) != 0 )
  {
    v2 = (unsigned __int64)v3[3] <= 7;
    *(__m128i *)v33 = _mm_load_si128((const __m128i *)&xmmword_14012ED70);
    strcpy(v34, "r.cpp");
    if ( !v2 )
      v3 = (__int64 *)*v3;
    sub_1400229E0(*a1, (int)v33, 135, 2, (wchar_t *)L"Disable loading of plugin %ls", (char)v3);
    *((_DWORD *)a1 + 57) = 5;
    sub_14001EB00((char *)a1 + 160, 0x40u);
    return 1;
  }
  if ( a1[32] != 0 )
    *(_QWORD *)(a1[32] + 72) = sub_14001E730();
  v12 = v3;
  if ( (unsigned __int64)v3[3] > 7 )
    v12 = (_QWORD *)*v3;
  v13 = sub_140013E40(a1 + 42, v12, a1 + 10, 0);
  if ( v13 != 0 )
  {
    if ( a1[32] != 0 )
    {
      v17 = (unsigned int *)a1[32];
      v18 = sub_14001E730();
      v19 = (int *)&v32;
      v20 = v18 - v17[18];
      v21 = *v17 < v20;
      v32 = v20;
      if ( !v21 )
        v19 = (int *)v17;
      *v17 = *v19;
    }
    v2 = (unsigned __int64)v3[3] <= 7;
    LOBYTE(v22) = (_BYTE)v3;
    *(__m128i *)v33 = _mm_load_si128((const __m128i *)&xmmword_14012ED70);
    strcpy(v34, "r.cpp");
    if ( !v2 )
      v22 = *v3;
    sub_1400229E0(*a1, (int)v33, 157, 3, (wchar_t *)L"Loaded %ls", v22);
    v23 = a1[10];
    *(_OWORD *)v35 = xmmword_14012E2E8;
    memset(&v35[2], 0, 112);
    v24 = (__int64 (*)(void))sub_1400132A0(a1 + 42, v23, v35);
    strcpy(v34, "r.cpp");
    *(__m128i *)v33 = _mm_load_si128((const __m128i *)&xmmword_14012ED70);
    if ( v24 != nullptr )
    {
      LOBYTE(v25) = (_BYTE)v3;
      if ( (unsigned __int64)v3[3] > 7 )
        v25 = *v3;
      sub_1400229E0(*a1, (int)v33, 170, 4, (wchar_t *)L"Query plugin information for %ls", v25);
      v26 = v24();
      if ( v26 != 0 && *(_DWORD *)v26 != 0 )
      {
        *(_OWORD *)(a1 + 11) = *(_OWORD *)v26;
        *(_OWORD *)(a1 + 13) = *(_OWORD *)(v26 + 16);
        *(_OWORD *)(a1 + 15) = *(_OWORD *)(v26 + 32);
        *(_OWORD *)(a1 + 17) = *(_OWORD *)(v26 + 48);
        a1[19] = *(_QWORD *)(v26 + 64);
        sub_14001EBB0(a1 + 20, 64, a1[12]);
        si128 = _mm_load_si128((const __m128i *)&xmmword_14012ED70);
        v28 = "optional";
        if ( *((_BYTE *)a1 + 72) != 0 )
          v28 = "mandatory";
        strcpy(v34, "r.cpp");
        v31 = (char)v28;
        v29 = *a1;
        *(__m128i *)v33 = si128;
        sub_140022750(v29, (int)v33, 198, 3, "Loaded %s plugin %s, version %u", v31);
        *((_DWORD *)a1 + 58) = 1;
        *((_DWORD *)a1 + 57) = 1;
        return v13;
      }
      v2 = (unsigned __int64)v3[3] <= 7;
      LOBYTE(v30) = (_BYTE)v3;
      *(__m128i *)v33 = _mm_load_si128((const __m128i *)&xmmword_14012ED70);
      strcpy(v34, "r.cpp");
      if ( !v2 )
        v30 = *v3;
      sub_1400229E0(
        *a1,
        (int)v33,
        180,
        1,
        (wchar_t *)L"NvPluginGetInfo for %ls returned invalid plugin descriptor",
        v30);
      if ( (unsigned __int64)v3[3] > 7 )
        v3 = (__int64 *)*v3;
      sub_140007F90(0x24u, L"NvPluginGetInfo for %ls returned invalid plugin descriptor", v3);
    }
    else
    {
      if ( (unsigned __int64)v3[3] > 7 )
        v3 = (__int64 *)*v3;
      sub_1400229E0(*a1, (int)v33, 165, 2, (wchar_t *)L"NvPluginGetInfo is not exported by %ls", (char)v3);
    }
    v13 = 0;
    sub_14000E670(a1);
    return v13;
  }
  v14 = *a1;
  *(__m128i *)v33 = _mm_load_si128((const __m128i *)&xmmword_14012ED70);
  strcpy(v34, "r.cpp");
  GetLastError();
  LOBYTE(v15) = (_BYTE)v3;
  if ( (unsigned __int64)v3[3] > 7 )
    v15 = *v3;
  sub_1400229E0(v14, (int)v33, 152, 1, (wchar_t *)L"Failed to load library %ls. Error %u", v15);
  LastError = GetLastError();
  if ( (unsigned __int64)v3[3] > 7 )
    v3 = (__int64 *)*v3;
  sub_140007F90(0x1Eu, L"Failed to load library %ls. Error %u", v3, LastError);
  return 0;
}
