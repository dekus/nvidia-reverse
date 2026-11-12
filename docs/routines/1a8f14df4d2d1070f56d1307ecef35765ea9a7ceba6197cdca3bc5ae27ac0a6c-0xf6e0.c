
__int64 __fastcall sub_14000F6E0(__int64 a1)
{
  __int64 v2;
  int v3;
  const char *v4;
  const CHAR *v5;
  HANDLE FileA;
  void *v7;
  DWORD LastError;
  DWORD v9;
  const CHAR *v10;
  BOOL v12;
  DWORD CollectDataTimeout;
  DWORD MaxCollectionCount;
  DWORD nTimeOut[16];
  DWORD CurInstances;
  DWORD State;
  DWORD Mode;

  nTimeOut[0] = 100;
  nTimeOut[1] = 200;
  nTimeOut[2] = 400;
  v2 = 0;
  nTimeOut[3] = 800;
  v3 = 1;
  nTimeOut[4] = 1500;
  while ( 1 )
  {
    v4 = (const char *)a1;
    if ( *(_QWORD *)(a1 + 24) > 0xFu )
      v4 = *(const char **)a1;
    sub_140010A10("ConnectWithRetry: attempt %d, pipe=%s", v3, v4);
    v5 = (const CHAR *)a1;
    if ( *(_QWORD *)(a1 + 24) > 0xFu )
      v5 = *(const CHAR **)a1;
    FileA = CreateFileA(v5, 0xC0000000, 0, nullptr, 3u, 0x40000000u, nullptr);
    v7 = FileA;
    if ( FileA != (HANDLE)-1LL )
      break;
    LastError = GetLastError();
    sub_140010A10("ConnectWithRetry: CreateFile failed err=%lu", LastError);
    if ( LastError == 5 )
    {
      sub_14000F940("auth_failed", "Access denied to NvApp MCP server pipe");
      return -1;
    }
    v9 = nTimeOut[v2];
    if ( LastError == 231 )
    {
      v10 = (const CHAR *)a1;
      if ( *(_QWORD *)(a1 + 24) > 0xFu )
        v10 = *(const CHAR **)a1;
      WaitNamedPipeA(v10, v9);
    }
    else
    {
      Sleep(v9);
    }
    ++v3;
    if ( ++v2 >= 5 )
    {
      sub_14000F940(
        "service_unavailable",
        "NvApp MCP server is unavailable. Ensure the user is logged in and NVIDIA App is installed.");
      return -1;
    }
  }
  Mode = 0;
  v12 = SetNamedPipeHandleState(FileA, &Mode, nullptr, nullptr);
  sub_140010A10("ConnectWithRetry: connected! handle=%p (OVERLAPPED), SetPipeHandleState=%d", v7, v12);
  State = 0;
  CurInstances = 0;
  MaxCollectionCount = 0;
  CollectDataTimeout = 0;
  GetNamedPipeHandleStateA(v7, &State, &CurInstances, &MaxCollectionCount, &CollectDataTimeout, nullptr, 0);
  sub_140010A10("ConnectWithRetry: pipeState=0x%lx, instances=%lu", State, CurInstances);
  return (__int64)v7;
}
