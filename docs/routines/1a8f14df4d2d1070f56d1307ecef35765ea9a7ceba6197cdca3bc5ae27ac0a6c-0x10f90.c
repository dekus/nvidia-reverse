
int __fastcall sub_140010F90(void *a1)
{
  DWORD v2;
  char v3;
  _BYTE *v4;
  int v5;
  _BYTE *v6;
  HANDLE StdHandle;
  BOOL v8;
  DWORD i;
  DWORD LastError;
  DWORD v11;
  char v12;
  char v13;
  DWORD v14;
  char v15;
  _BYTE v17[8];
  DWORD NumberOfBytesRead;
  DWORD NumberOfBytesWritten;
  struct _OVERLAPPED Overlapped;
  _BYTE Buffer[4096];

  sub_140010A10("PumpStdinToPipe: started, pipe=%p", a1);
  memset(&Overlapped, 0, 24);
  Overlapped.hEvent = CreateEventW(nullptr, true, false, nullptr);
  if ( Overlapped.hEvent != nullptr )
  {
    v5 = 0;
    v6 = (_BYTE *)sub_140002410(&unk_140029108);
    if ( *v6 != 0 )
    {
      while ( 1 )
      {
        NumberOfBytesRead = 0;
        sub_140010A10("PumpStdinToPipe: calling ReadFile on stdin...");
        StdHandle = GetStdHandle(0xFFFFFFF6);
        v8 = ReadFile(StdHandle, Buffer, 0x1000u, &NumberOfBytesRead, nullptr);
        if ( !v8 || NumberOfBytesRead == 0 )
          break;
        sub_140010A10("PumpStdinToPipe: read %lu bytes from stdin (msg #%d)", NumberOfBytesRead, ++v5);
        for ( i = 0; i < NumberOfBytesRead; i += NumberOfBytesWritten )
        {
          NumberOfBytesWritten = 0;
          ResetEvent(Overlapped.hEvent);
          sub_140010A10("PumpStdinToPipe: WriteFile to pipe, %lu bytes remaining...", NumberOfBytesRead - i);
          if ( !WriteFile(a1, &Buffer[i], NumberOfBytesRead - i, &NumberOfBytesWritten, &Overlapped) )
          {
            LastError = GetLastError();
            if ( LastError != 997 )
            {
              sub_140010A10("PumpStdinToPipe: WriteFile FAILED err=%lu", LastError);
              v17[0] = 0;
              v13 = sub_140002690(v17);
              *(_BYTE *)sub_140003430(&unk_140029108) = v13;
              LODWORD(v4) = CloseHandle(Overlapped.hEvent);
              return (int)v4;
            }
            if ( !GetOverlappedResult(a1, &Overlapped, &NumberOfBytesWritten, true) )
            {
              v11 = GetLastError();
              sub_140010A10("PumpStdinToPipe: GetOverlappedResult FAILED err=%lu", v11);
              v17[0] = 0;
              v12 = sub_140002690(v17);
              *(_BYTE *)sub_140003430(&unk_140029108) = v12;
              LODWORD(v4) = CloseHandle(Overlapped.hEvent);
              return (int)v4;
            }
          }
          sub_140010A10("PumpStdinToPipe: WriteFile wrote %lu bytes", NumberOfBytesWritten);
        }
        if ( *v6 == 0 )
          goto LABEL_16;
      }
      v14 = GetLastError();
      sub_140010A10("PumpStdinToPipe: stdin closed (ok=%d, read=%lu, err=%lu)", v8, NumberOfBytesRead, v14);
    }
LABEL_16:
    sub_140010A10("PumpStdinToPipe: exiting, setting g_running=false");
    CloseHandle(Overlapped.hEvent);
    v17[0] = 0;
    v15 = sub_140002690(v17);
    v4 = (_BYTE *)sub_140003430(&unk_140029108);
    *v4 = v15;
    return (int)v4;
  }
  v2 = GetLastError();
  sub_140010A10("PumpStdinToPipe: CreateEventW failed (err=%lu)", v2);
  v17[0] = 0;
  v3 = sub_140002690(v17);
  v4 = (_BYTE *)sub_140003430(&unk_140029108);
  *v4 = v3;
  return (int)v4;
}
