
void __fastcall sub_140013360(__int64 a1, __int64 a2)
{
  __int64 v4;
  volatile signed __int32 *v5;
  _DWORD *v6;
  unsigned __int64 v7;
  __int64 v8;
  int v9;
  bool v10;
  void *v11;
  unsigned __int64 v12;
  __int64 *v13;
  __int64 v14;
  __int64 v15;
  _DWORD *v16;
  volatile signed __int32 *v17;
  void *v18;
  _QWORD *v19;
  _QWORD *v20;
  _QWORD *v21;
  __int64 v22;
  volatile signed __int32 *v23;
  volatile signed __int32 *v24;
  int v25;
  __int64 *v26;
  __int64 v27;
  __int64 v28;
  _DWORD *v29;
  volatile signed __int32 *v30;
  void *v31;
  volatile signed __int32 *v32;
  volatile signed __int32 *v33;
  void *v34;
  __int64 v36;
  char v37;
  __int64 v38;
  __int128 v39;
  __int64 *v40;
  void *Block;
  char v42;
  void *v43;
  __int64 (__fastcall ***v44)(_QWORD, __int64);
  _QWORD *v45;
  volatile signed __int32 **v46;
  __int64 (__fastcall ***v47)(_QWORD, __int64);
  __int128 v48;
  const std::exception *v49;
  __int128 v50;
  __m128i v51[2];
  char v52[16];
  __int128 v53;
  __int64 v54;
  unsigned __int64 v55;
  __int128 v56;
  __int64 v57;
  unsigned __int64 v58;
  _QWORD v59[3];
  unsigned __int64 v60;

  v40 = (__int64 *)a1;
  v4 = 0;
  v45 = (_QWORD *)(a1 + 32);
  *(_QWORD *)(a1 + 32) = 0;
  v46 = (volatile signed __int32 **)(a1 + 40);
  v5 = *(volatile signed __int32 **)(a1 + 40);
  *(_QWORD *)(a1 + 40) = 0;
  if ( v5 != nullptr && _InterlockedExchangeAdd(v5 + 2, 0xFFFFFFFF) == 1 )
  {
    (**(void (__fastcall ***)(volatile signed __int32 *))v5)(v5);
    if ( _InterlockedExchangeAdd(v5 + 3, 0xFFFFFFFF) == 1 )
      (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v5 + 8LL))(v5);
  }
  Block = (void *)sub_1400118D0(a2);
  v42 = 1;
  v43 = nullptr;
  if ( Block != nullptr )
  {
    v6 = operator new(4u, (const struct std::nothrow_t *)&unk_140137144);
    if ( v6 != nullptr )
    {
      *v6 = 0;
      v43 = v6;
      ++*v6;
    }
    else
    {
      v43 = nullptr;
      j_j_free_0_1(Block);
      Block = nullptr;
    }
  }
  v39 = 0;
  v7 = -1;
  do
    ++v7;
  while ( *((_WORD *)Block + v7) != 0 );
  __wind
  {
    __wind
    {
      v53 = 0;
      v54 = 0;
      v55 = 0;
      sub_1400037F0(&v53, (__int64)Block, v7);
      v8 = sub_140014830(v51, &v53, 3);
      v38 = *(_QWORD *)v8;
      LODWORD(v48) = *(_DWORD *)(v8 + 8);
      *((_QWORD *)&v48 + 1) = &off_140167060;
      v50 = v48;
      if ( (_DWORD)v38 != 0 )
      {
        v9 = 0;
        v10 = (_DWORD)v38 != 1;
      }
      else
      {
        v10 = false;
        v9 = v50;
      }
      if ( v55 > 7 )
      {
        v11 = (void *)v53;
        if ( 2 * v55 + 2 >= 0x1000 )
        {
          v11 = *(void **)(v53 - 8);
          if ( (unsigned __int64)(v53 - (_QWORD)v11 - 8) > 0x1F )
            invalid_parameter_noinfo_noreturn();
        }
        j_j_free_0(v11);
      }
      if ( Block != nullptr && (v10 || v9 != 0) )
      {
        v12 = -1;
        do
          ++v12;
        while ( *((_WORD *)Block + v12) != 0 );
        try
        {
          v56 = 0;
          v57 = 0;
          v58 = 0;
          sub_1400037F0(&v56, (__int64)Block, v12);
          __wind
          {
            v13 = (__int64 *)sub_140033F90(&v44, a1, 1, &v56);
            v14 = *v13;
            v15 = 0;
            v16 = nullptr;
            if ( *v13 != 0 )
            {
              __wind
              {
                v16 = operator new(0x18u);
                if ( v16 != nullptr )
                {
                  v16[2] = 1;
                  v16[3] = 1;
                  *(_QWORD *)v16 = &std::_Ref_count_resource<nvc::ISettingsStorage *,std::default_delete<nvc::ISettingsStorage>>::`vftable';
                  *((_QWORD *)v16 + 2) = v14;
                }
                else
                {
                  v16 = nullptr;
                }
                *v13 = 0;
                v15 = v14;
              }
              __unwind
              {
                sub_140012EC0(&v44);
              }
            }
          }
          __unwind
          {
            sub_140013010((__int64)&v56);
          }
        }
        catch ( const std::exception *v49 )
        {
          v51[1] = _mm_load_si128((const __m128i *)&xmmword_14012FE50);
          strcpy(v52, "lperWin32.cpp");
          v36 = *v40;
          v37 = (*(__int64 (__fastcall **)(const std::exception *))(*(_QWORD *)v49 + 8LL))(v49);
          sub_140022750(v36, (int)v51[1].m128i_i32, 52, 1, "Unable to load plugin config file, error: %s", v37);
          v4 = 0;
          goto LABEL_41;
        }
        *(_QWORD *)&v39 = v15;
        v17 = *((volatile signed __int32 **)&v39 + 1);
        *((_QWORD *)&v39 + 1) = v16;
        if ( v17 != nullptr && _InterlockedExchangeAdd(v17 + 2, 0xFFFFFFFF) == 1 )
        {
          (**(void (__fastcall ***)(volatile signed __int32 *))v17)(v17);
          if ( _InterlockedExchangeAdd(v17 + 3, 0xFFFFFFFF) == 1 )
            (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v17 + 8LL))(v17);
        }
        if ( v44 != nullptr )
          (**v44)(v44, 1);
        if ( v58 > 7 )
        {
          v18 = (void *)v56;
          if ( 2 * v58 + 2 >= 0x1000 )
          {
            v18 = *(void **)(v56 - 8);
            if ( (unsigned __int64)(v56 - (_QWORD)v18 - 8) > 0x1F )
              invalid_parameter_noinfo_noreturn();
          }
          j_j_free_0(v18);
        }
      }
      else
      {
        try
        {
          v25 = (*(__int64 (__fastcall **)(_QWORD, _QWORD *))(**(_QWORD **)(a1 + 16) + 160LL))(
                  *(_QWORD *)(a1 + 16),
                  v59);
          __wind
          {
            v26 = (__int64 *)sub_1400368E0((unsigned int)&v40, a1, v25, 1, 0);
            v27 = *v26;
            v28 = 0;
            v29 = nullptr;
            if ( *v26 != 0 )
            {
              __wind
              {
                v29 = operator new(0x18u);
                if ( v29 != nullptr )
                {
                  v29[2] = 1;
                  v29[3] = 1;
                  *(_QWORD *)v29 = &std::_Ref_count_resource<nvc::ISettingsStorage *,std::default_delete<nvc::ISettingsStorage>>::`vftable';
                  *((_QWORD *)v29 + 2) = v27;
                }
                else
                {
                  v29 = nullptr;
                }
                *v26 = 0;
                v28 = v27;
              }
              __unwind
              {
                sub_140012EC0((__int64 (__fastcall ****)(_QWORD, __int64))&v40);
              }
            }
          }
          __unwind
          {
            sub_140002470(v59);
          }
        }
        catch ( std::exception )
        {
          v4 = 0;
          goto LABEL_41;
        }
        *(_QWORD *)&v39 = v28;
        v30 = *((volatile signed __int32 **)&v39 + 1);
        *((_QWORD *)&v39 + 1) = v29;
        if ( v30 != nullptr && _InterlockedExchangeAdd(v30 + 2, 0xFFFFFFFF) == 1 )
        {
          (**(void (__fastcall ***)(volatile signed __int32 *))v30)(v30);
          if ( _InterlockedExchangeAdd(v30 + 3, 0xFFFFFFFF) == 1 )
            (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v30 + 8LL))(v30);
        }
        if ( v40 != nullptr )
          (*(void (__fastcall **)(__int64 *, __int64))*v40)(v40, 1);
        if ( v60 > 7 )
        {
          v31 = (void *)v59[0];
          if ( 2 * v60 + 2 >= 0x1000 )
          {
            v31 = *(void **)(v59[0] - 8LL);
            if ( (unsigned __int64)(v59[0] - (_QWORD)v31 - 8LL) > 0x1F )
              invalid_parameter_noinfo_noreturn();
          }
          j_j_free_0(v31);
        }
      }
LABEL_41:
      v19 = (_QWORD *)sub_140029830(&v47, &v39);
      v20 = v19;
      v21 = v45;
      v22 = *v19;
      v23 = nullptr;
      if ( *v19 != 0 )
      {
        __wind
        {
          v24 = (volatile signed __int32 *)operator new(0x18u);
        }
        __unwind
        {
          sub_140012EA0(&v47);
        }
        v23 = v24;
        if ( v24 != nullptr )
        {
          *(_OWORD *)v24 = 0;
          *((_DWORD *)v24 + 2) = 1;
          *((_DWORD *)v24 + 3) = 1;
          *(_QWORD *)v24 = &std::_Ref_count_resource<nvc::IPluginConfig *,std::default_delete<nvc::IPluginConfig>>::`vftable';
          *((_QWORD *)v24 + 2) = v22;
        }
        else
        {
          v23 = nullptr;
        }
        *v20 = 0;
        v4 = v22;
      }
      *v21 = v4;
      v32 = *v46;
      *v46 = v23;
      if ( v32 != nullptr && _InterlockedExchangeAdd(v32 + 2, 0xFFFFFFFF) == 1 )
      {
        (**(void (__fastcall ***)(volatile signed __int32 *))v32)(v32);
        if ( _InterlockedExchangeAdd(v32 + 3, 0xFFFFFFFF) == 1 )
          (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v32 + 8LL))(v32);
      }
      if ( v47 != nullptr )
        (**v47)(v47, 1);
      v33 = *((volatile signed __int32 **)&v39 + 1);
      if ( *((_QWORD *)&v39 + 1) != 0
        && _InterlockedExchangeAdd((volatile signed __int32 *)(*((_QWORD *)&v39 + 1) + 8LL), 0xFFFFFFFF) == 1 )
      {
        (**(void (__fastcall ***)(volatile signed __int32 *))v33)(v33);
        if ( _InterlockedExchangeAdd(v33 + 3, 0xFFFFFFFF) == 1 )
          (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v33 + 8LL))(v33);
      }
      v34 = v43;
      if ( v43 != nullptr && (*(_DWORD *)v43)-- == 1 )
      {
        j_j_free_0_1(Block);
        j_j_free_0(v34);
      }
    }
    __unwind
    {
      sub_140012E40((__int64)&v39);
    }
  }
  __unwind
  {
    sub_140012D80((__int64)&Block);
  }
}
