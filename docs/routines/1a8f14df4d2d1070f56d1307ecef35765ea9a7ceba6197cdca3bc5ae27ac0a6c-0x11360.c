
__int64 sub_140011360()
{
  FILE *v0;
  int v1;
  unsigned int v2;
  FILE *v3;
  int v4;
  void **v5;
  void *v6;
  void *v7;
  _QWORD *v8;
  _QWORD *v9;
  void *v10;
  _BYTE *v11;
  void *v12;
  void *v13;
  HANDLE hThread[2];
  unsigned int ThrdAddr[4];
  HANDLE Handles[2];
  void *Block[2];
  __m128i si128;
  void *v20[2];
  __int64 v21;
  unsigned __int64 v22;
  void *v23[3];
  unsigned __int64 v24;
  _BYTE v25[8];
  void *v26;
  __m128i v27;
  CHAR Buffer[256];

  sub_140010A10("RunBridgeMode: starting");
  v0 = __acrt_iob_func(0);
  v1 = _fileno(v0);
  _setmode(v1, 0x8000);
  v2 = 1;
  v3 = __acrt_iob_func(1u);
  v4 = _fileno(v3);
  _setmode(v4, 0x8000);
  sub_14000F290((__int64)v23);
  __wind
  {
    if ( v23[2] == nullptr )
    {
      sub_140010A10("RunBridgeMode: failed to build pipe name");
LABEL_9:
      sub_14000F940();
      goto LABEL_65;
    }
    v5 = v23;
    if ( v24 > 0xF )
      v5 = (void **)v23[0];
    sub_140010A10("RunBridgeMode: connecting to %s", (const char *)v5);
    v6 = (void *)sub_14000F6E0((__int64)v23);
    if ( v6 == (void *)-1LL )
    {
      if ( (unsigned __int8)sub_1400100F0() == 0 )
      {
        v2 = 0;
        sub_140010A10("RunBridgeMode: MCP server readiness event not signaled — server is disabled or not running");
        goto LABEL_9;
      }
      sub_140010A10("RunBridgeMode: connection failed (server ready event signaled, pipe may be initializing)");
      goto LABEL_65;
    }
    memset(Buffer, 0, sizeof(Buffer));
    GetEnvironmentVariableA("NVAPP_MCP_TOKEN", Buffer, 0x100u);
    *(_OWORD *)v20 = 0;
    v21 = 0;
    v22 = 0;
    sub_140001390();
    __wind
    {
      sub_14000FDC0((__int64)v25);
      __wind
      {
        sub_140010A10("RunBridgeMode: NVAPP_MCP_TOKEN not set, proceeding unauthenticated");
        *(_OWORD *)Block = 0;
        si128 = _mm_load_si128(xmmword_140022190);
        LOBYTE(Block[0]) = 0;
        __wind
        {
          sub_1400119A0(v6);
        }
        __unwind
        {
          sub_140001790(Block);
        }
        if ( si128.m128i_i64[1] > 0xFuLL )
        {
          v7 = Block[0];
          if ( (unsigned __int64)(si128.m128i_i64[1] + 1) >= 0x1000 )
          {
            v7 = *((void **)Block[0] - 1);
            if ( (unsigned __int64)((char *)Block[0] - (char *)v7 - 8) > 0x1F )
              _invalid_parameter_noinfo_noreturn();
          }
          j_j_j_j_free(v7);
        }
        sub_140010A10("RunBridgeMode: connected, starting relay threads");
        v8 = operator new(0x10u);
        if ( v8 != nullptr )
        {
          *v8 = v6;
          v8[1] = sub_140010F90;
        }
        else
        {
          v8 = nullptr;
        }
        Block[0] = v8;
        __eh34_enter_wind_state(2, 4);
        hThread[0] = (HANDLE)_beginthreadex(
                               nullptr,
                               0,
                               (_beginthreadex_proc_type)StartAddress,
                               v8,
                               0,
                               (unsigned int *)&hThread[1]);
        if ( hThread[0] != nullptr )
        {
          if ( __eh34_unwind(4) )
          {
unwind_state_4:
            sub_140001420(Block);
            __eh34_continue_unwinding(4, 2);
          }
          __eh34_exit_wind_state(4, 2);
          __eh34_enter_wind_state(2, 5);
          v9 = operator new(0x10u);
          if ( v9 != nullptr )
          {
            *v9 = v6;
            v9[1] = sub_140010C20;
          }
          else
          {
            v9 = nullptr;
          }
          Block[0] = v9;
          v10 = (void *)_beginthreadex(nullptr, 0, (_beginthreadex_proc_type)StartAddress, v9, 0, &ThrdAddr[2]);
          *(_QWORD *)ThrdAddr = v10;
          if ( v10 != nullptr )
          {
            Handles[0] = hThread[0];
            Handles[1] = v10;
            WaitForMultipleObjects(2u, Handles, false, 0xFFFFFFFF);
            CancelIoEx(v6, nullptr);
            CancelSynchronousIo(hThread[0]);
            __eh34_enter_wind_state(5, 7);
            if ( LODWORD(hThread[1]) != 0 )
            {
              if ( LODWORD(hThread[1]) == Thrd_id() )
                goto LABEL_55;
              *(_OWORD *)Block = *(_OWORD *)hThread;
              if ( Thrd_join((_Thrd_t *)Block, nullptr) != 0 )
                goto LABEL_54;
              *(_OWORD *)hThread = 0;
              if ( ThrdAddr[2] != 0 )
              {
                if ( ThrdAddr[2] != Thrd_id() )
                {
                  *(_OWORD *)Block = *(_OWORD *)ThrdAddr;
                  if ( Thrd_join((_Thrd_t *)Block, nullptr) == 0 )
                  {
                    *(_OWORD *)ThrdAddr = 0;
                    sub_140010A10("RunBridgeMode: both relay threads exited");
                    CloseHandle(v6);
                    sub_140010A10("RunBridgeMode: done");
                    v2 = 0;
                    if ( __eh34_unwind(7) )
                    {
                      sub_140002240((__int64)ThrdAddr);
                      __eh34_continue_unwinding(7, 5);
                    }
                    __eh34_exit_wind_state(7, 5);
                    if ( ThrdAddr[2] != 0 )
                      terminate();
                    if ( LODWORD(hThread[1]) != 0 )
                      terminate();
                    if ( v27.m128i_i64[1] > 0xFuLL )
                    {
                      v11 = v26;
                      if ( (unsigned __int64)(v27.m128i_i64[1] + 1) >= 0x1000 )
                      {
                        v11 = *((_BYTE **)v26 - 1);
                        if ( (unsigned __int64)((_BYTE *)v26 - v11 - 8) > 0x1F )
                          _invalid_parameter_noinfo_noreturn();
                      }
                      j_j_j_j_free(v11);
                    }
                    v27 = _mm_load_si128(xmmword_140022190);
                    LOBYTE(v26) = 0;
                    if ( v22 > 0xF )
                    {
                      v12 = v20[0];
                      if ( v22 + 1 >= 0x1000 )
                      {
                        v12 = *((void **)v20[0] - 1);
                        if ( (unsigned __int64)((char *)v20[0] - (char *)v12 - 8) > 0x1F )
                          _invalid_parameter_noinfo_noreturn();
                      }
                      j_j_j_j_free(v12);
                    }
                    if ( __eh34_unwind(5) )
                      goto unwind_state_5;
                    __eh34_exit_wind_state(5, 2);
                    goto LABEL_65;
                  }
LABEL_54:
                  std::_Throw_Cpp_error(2);
                  __debugbreak();
                }
LABEL_55:
                std::_Throw_Cpp_error(5);
                __debugbreak();
              }
            }
            std::_Throw_Cpp_error(1);
            JUMPOUT(0x14001185ALL);
          }
          __wind
          {
            ThrdAddr[2] = 0;
            std::_Throw_Cpp_error(6);
          }
          __unwind
          {
            sub_140001420(Block);
          }
          if ( __eh34_unwind(5) )
          {
unwind_state_5:
            sub_140002240((__int64)hThread);
            __eh34_continue_unwinding(5, 2);
          }
          __eh34_exit_wind_state(5, 2);
          __eh34_enter_wind_state(2, 4);
        }
        LODWORD(hThread[1]) = 0;
        std::_Throw_Cpp_error(6);
        if ( __eh34_unwind(4) )
          goto unwind_state_4;
        __eh34_exit_wind_state(4, 2);
        __eh34_enter_wind_state(2, 5);
        __eh34_enter_wind_state(5, 7);
        goto LABEL_54;
      }
      __unwind
      {
        sub_1400034E0(v25);
      }
    }
    __unwind
    {
      sub_140001790(v20);
    }
  }
  __unwind
  {
    sub_140001790(v23);
  }
LABEL_65:
  if ( v24 > 0xF )
  {
    v13 = v23[0];
    if ( v24 + 1 >= 0x1000 )
    {
      v13 = *((void **)v23[0] - 1);
      if ( (unsigned __int64)((char *)v23[0] - (char *)v13 - 8) > 0x1F )
        _invalid_parameter_noinfo_noreturn();
    }
    j_j_j_j_free(v13);
  }
  return v2;
}
