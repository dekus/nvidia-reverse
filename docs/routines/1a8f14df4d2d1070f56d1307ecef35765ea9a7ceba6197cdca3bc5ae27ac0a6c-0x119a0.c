
__int64 __fastcall sub_1400119A0(HANDLE hFile, __int64 *a2, __int64 *a3)
{
  size_t v6;
  __m128i *v7;
  __m128i *v8;
  __int64 v9;
  unsigned __int64 v10;
  unsigned __int64 v11;
  __int64 v12;
  __m128i v13;
  void **v14;
  _BYTE *v15;
  __int64 v16;
  __m128i v17;
  void **v18;
  _BYTE *v19;
  __int64 v20;
  __m128i v21;
  void **v22;
  _BYTE *v23;
  __int64 v24;
  void *v25;
  void *v26;
  void *v27;
  void *v28;
  void *v29;
  void *v30;
  void *v31;
  void *v32;
  DWORD v33;
  LPCVOID *v34;
  BOOL OverlappedResult;
  unsigned __int8 v36;
  DWORD LastError;
  void *v38;
  DWORD NumberOfBytesWritten;
  struct _OVERLAPPED Overlapped;
  void *Src[2];
  __m128i v43;
  LPCVOID lpBuffer[2];
  DWORD nNumberOfBytesToWrite[4];
  void *Block[2];
  __m128i si128;
  void *v48[2];
  __m128i v49;
  void *v50[2];
  __int128 v51;
  void *v52[2];
  __int128 v53;
  void *v54[2];
  __m128i v55;
  void *v56[2];
  __m128i v57;
  void *v58[3];
  unsigned __int64 v59;

  v6 = 0;
  sub_140001BA0(v58, *(unsigned int *)a3);
  __wind
  {
    sub_140010160(v56, a3 + 1);
    __wind
    {
      v7 = (__m128i *)sub_140010160(v54, a2);
      __wind
      {
        v8 = v7;
        v9 = v7[1].m128i_i64[0];
        v10 = v7[1].m128i_u64[1];
        if ( v10 - v9 < 0x1F )
        {
          v12 = sub_140001D10(v7, 31, 0, 0, "{\"_bridge_handshake\":{\"token\":\"", 0x1Fu);
          v8 = (__m128i *)v12;
        }
        else
        {
          v7[1].m128i_i64[0] = v9 + 31;
          v11 = (unsigned __int64)v7;
          if ( v10 > 0xF )
            v11 = v7->m128i_i64[0];
          if ( (unsigned __int64)"" <= v11 || (unsigned __int64)"{\"_bridge_handshake\":{\"token\":\"" > v11 + v9 )
          {
            v6 = 31;
          }
          else if ( v11 > (unsigned __int64)"{\"_bridge_handshake\":{\"token\":\"" )
          {
            v6 = v11 - (_QWORD)"{\"_bridge_handshake\":{\"token\":\"";
          }
          memmove((void *)(v11 + 31), (const void *)v11, v9 + 1);
          memcpy((void *)v11, "{\"_bridge_handshake\":{\"token\":\"", v6);
          memcpy((void *)(v11 + v6), &aBridgeHandshak[v6 + 31], 31 - v6);
        }
        __wind
        {
          *(_OWORD *)Src = 0;
          v43 = 0;
          *(__m128i *)Src = *v8;
          v43 = v8[1];
          v8[1].m128i_i64[0] = 0;
          v8[1].m128i_i64[1] = 15;
          v8->m128i_i8[0] = 0;
          v13 = v43;
          if ( v43.m128i_i64[1] - v43.m128i_i64[0] < 0xFuLL )
          {
            _mm_lfence();
            v16 = sub_140001EE0(Src, 15, 0, (__int64)"\",\"parentExe\":\"", 0xFu);
          }
          else
          {
            v43.m128i_i64[0] += 15;
            v14 = Src;
            if ( v13.m128i_i64[1] > 0xFuLL )
              v14 = (void **)Src[0];
            v15 = (char *)v14 + v13.m128i_i64[0];
            memmove(v15, "\",\"parentExe\":\"", 0xFu);
            v15[15] = 0;
            v16 = (__int64)Src;
          }
          __wind
          {
            *(_OWORD *)v52 = *(_OWORD *)v16;
            v53 = *(_OWORD *)(v16 + 16);
            *(_QWORD *)(v16 + 16) = 0;
            *(_QWORD *)(v16 + 24) = 15;
            *(_BYTE *)v16 = 0;
            sub_140001150();
            __wind
            {
              v17 = v49;
              if ( v49.m128i_i64[1] - v49.m128i_i64[0] < 0xEuLL )
              {
                _mm_lfence();
                v20 = sub_140001EE0(v48, 14, 0, (__int64)"\",\"parentPid\":", 0xEu);
              }
              else
              {
                v49.m128i_i64[0] += 14;
                v18 = v48;
                if ( v17.m128i_i64[1] > 0xFuLL )
                  v18 = (void **)v48[0];
                v19 = (char *)v18 + v17.m128i_i64[0];
                memmove(v19, "\",\"parentPid\":", 0xEu);
                v19[14] = 0;
                v20 = (__int64)v48;
              }
              __wind
              {
                *(_OWORD *)v50 = *(_OWORD *)v20;
                v51 = *(_OWORD *)(v20 + 16);
                *(_QWORD *)(v20 + 16) = 0;
                *(_QWORD *)(v20 + 24) = 15;
                *(_BYTE *)v20 = 0;
                sub_140001150();
                v21 = si128;
                if ( si128.m128i_i64[1] - si128.m128i_i64[0] < 3uLL )
                {
                  __wind
                  {
                    _mm_lfence();
                    v24 = sub_140001EE0(Block, 3, 0, (__int64)"}}\n", 3u);
                  }
                  __unwind
                  {
                    sub_140001790(Block);
                  }
                }
                else
                {
                  si128.m128i_i64[0] += 3;
                  v22 = Block;
                  if ( v21.m128i_i64[1] > 0xFuLL )
                    v22 = (void **)Block[0];
                  v23 = (char *)v22 + v21.m128i_i64[0];
                  memmove(v23, "}}\n", 3u);
                  v23[3] = 0;
                  v24 = (__int64)Block;
                }
              }
              __unwind
              {
                sub_140001790(v50);
              }
            }
            __unwind
            {
              sub_140001790(v48);
            }
          }
          __unwind
          {
            sub_140001790(v52);
          }
        }
        __unwind
        {
          sub_140001790(Src);
        }
      }
      __unwind
      {
        sub_140001790(v54);
      }
    }
    __unwind
    {
      sub_140001790(v56);
    }
  }
  __unwind
  {
    sub_140001790(v58);
  }
  __wind
  {
    *(_OWORD *)lpBuffer = 0;
    memset(nNumberOfBytesToWrite, 0, sizeof(nNumberOfBytesToWrite));
    *(_OWORD *)lpBuffer = *(_OWORD *)v24;
    *(_OWORD *)nNumberOfBytesToWrite = *(_OWORD *)(v24 + 16);
    *(_QWORD *)(v24 + 16) = 0;
    *(_QWORD *)(v24 + 24) = 15;
    *(_BYTE *)v24 = 0;
    if ( si128.m128i_i64[1] > 0xFuLL )
    {
      v25 = Block[0];
      if ( (unsigned __int64)(si128.m128i_i64[1] + 1) >= 0x1000 )
      {
        v25 = *((void **)Block[0] - 1);
        if ( (unsigned __int64)((char *)Block[0] - (char *)v25 - 8) > 0x1F )
          _invalid_parameter_noinfo_noreturn();
      }
      j_j_j_j_free(v25);
    }
    si128 = _mm_load_si128(xmmword_140022190);
    LOBYTE(Block[0]) = 0;
    if ( *((_QWORD *)&v51 + 1) > 0xFu )
    {
      v26 = v50[0];
      if ( (unsigned __int64)(*((_QWORD *)&v51 + 1) + 1LL) >= 0x1000 )
      {
        v26 = *((void **)v50[0] - 1);
        if ( (unsigned __int64)((char *)v50[0] - (char *)v26 - 8) > 0x1F )
          _invalid_parameter_noinfo_noreturn();
      }
      j_j_j_j_free(v26);
    }
    if ( v49.m128i_i64[1] > 0xFuLL )
    {
      v27 = v48[0];
      if ( (unsigned __int64)(v49.m128i_i64[1] + 1) >= 0x1000 )
      {
        v27 = *((void **)v48[0] - 1);
        if ( (unsigned __int64)((char *)v48[0] - (char *)v27 - 8) > 0x1F )
          _invalid_parameter_noinfo_noreturn();
      }
      j_j_j_j_free(v27);
    }
    v49 = _mm_load_si128(xmmword_140022190);
    LOBYTE(v48[0]) = 0;
    if ( *((_QWORD *)&v53 + 1) > 0xFu )
    {
      v28 = v52[0];
      if ( (unsigned __int64)(*((_QWORD *)&v53 + 1) + 1LL) >= 0x1000 )
      {
        v28 = *((void **)v52[0] - 1);
        if ( (unsigned __int64)((char *)v52[0] - (char *)v28 - 8) > 0x1F )
          _invalid_parameter_noinfo_noreturn();
      }
      j_j_j_j_free(v28);
    }
    if ( v43.m128i_i64[1] > 0xFuLL )
    {
      v29 = Src[0];
      if ( (unsigned __int64)(v43.m128i_i64[1] + 1) >= 0x1000 )
      {
        v29 = *((void **)Src[0] - 1);
        if ( (unsigned __int64)((char *)Src[0] - (char *)v29 - 8) > 0x1F )
          _invalid_parameter_noinfo_noreturn();
      }
      j_j_j_j_free(v29);
    }
    v43 = _mm_load_si128(xmmword_140022190);
    LOBYTE(Src[0]) = 0;
    if ( v55.m128i_i64[1] > 0xFuLL )
    {
      v30 = v54[0];
      if ( (unsigned __int64)(v55.m128i_i64[1] + 1) >= 0x1000 )
      {
        v30 = *((void **)v54[0] - 1);
        if ( (unsigned __int64)((char *)v54[0] - (char *)v30 - 8) > 0x1F )
          _invalid_parameter_noinfo_noreturn();
      }
      j_j_j_j_free(v30);
    }
    v55 = _mm_load_si128(xmmword_140022190);
    LOBYTE(v54[0]) = 0;
    if ( v57.m128i_i64[1] > 0xFuLL )
    {
      v31 = v56[0];
      if ( (unsigned __int64)(v57.m128i_i64[1] + 1) >= 0x1000 )
      {
        v31 = *((void **)v56[0] - 1);
        if ( (unsigned __int64)((char *)v56[0] - (char *)v31 - 8) > 0x1F )
          _invalid_parameter_noinfo_noreturn();
      }
      j_j_j_j_free(v31);
    }
    v57 = _mm_load_si128(xmmword_140022190);
    LOBYTE(v56[0]) = 0;
    if ( v59 > 0xF )
    {
      v32 = v58[0];
      if ( v59 + 1 >= 0x1000 )
      {
        v32 = *((void **)v58[0] - 1);
        if ( (unsigned __int64)((char *)v58[0] - (char *)v32 - 8) > 0x1F )
          _invalid_parameter_noinfo_noreturn();
      }
      j_j_j_j_free(v32);
    }
    sub_140010A10("SendBridgeHandshake: sending %zu bytes", *(size_t *)nNumberOfBytesToWrite);
    memset(&Overlapped, 0, 24);
    Overlapped.hEvent = CreateEventW(nullptr, true, false, nullptr);
    if ( Overlapped.hEvent != nullptr )
    {
      NumberOfBytesWritten = 0;
      v34 = lpBuffer;
      if ( *(_QWORD *)&nNumberOfBytesToWrite[2] > 0xFu )
        v34 = (LPCVOID *)lpBuffer[0];
      OverlappedResult = WriteFile(hFile, v34, nNumberOfBytesToWrite[0], &NumberOfBytesWritten, &Overlapped);
      if ( !OverlappedResult && GetLastError() == 997 )
        OverlappedResult = GetOverlappedResult(hFile, &Overlapped, &NumberOfBytesWritten, OverlappedResult + 1);
      CloseHandle(Overlapped.hEvent);
      if ( OverlappedResult && NumberOfBytesWritten == nNumberOfBytesToWrite[0] )
      {
        sub_140010A10("SendBridgeHandshake: sent successfully");
        v36 = 1;
        goto LABEL_84;
      }
      LastError = GetLastError();
      sub_140010A10(
        "SendBridgeHandshake: WriteFile FAILED (ok=%d, written=%lu, err=%lu)",
        OverlappedResult,
        NumberOfBytesWritten,
        LastError);
    }
    else
    {
      v33 = GetLastError();
      sub_140010A10("SendBridgeHandshake: CreateEventW failed (err=%lu)", v33);
    }
    v36 = 0;
  }
  __unwind
  {
    sub_140001790(lpBuffer);
  }
LABEL_84:
  if ( *(_QWORD *)&nNumberOfBytesToWrite[2] > 0xFu )
  {
    v38 = (void *)lpBuffer[0];
    if ( (unsigned __int64)(*(_QWORD *)&nNumberOfBytesToWrite[2] + 1LL) >= 0x1000 )
    {
      v38 = *((void **)lpBuffer[0] - 1);
      if ( (unsigned __int64)((char *)lpBuffer[0] - (char *)v38 - 8) > 0x1F )
        _invalid_parameter_noinfo_noreturn();
    }
    j_j_j_j_free(v38);
  }
  return v36;
}
