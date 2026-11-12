
void __fastcall HandleInformation(_QWORD *StartContext)
{
  __int64 v1;
  void (__fastcall ***v2)(_QWORD);

  v1 = StartContext[8];
  v2 = *(void (__fastcall ****)(_QWORD))(v1 + 24);
  if ( v2 != nullptr )
  {
    while ( *(_BYTE *)v1 == 0 )
    {
      (**v2)(v2);
      KeDelayExecutionThread(0, 0, (PLARGE_INTEGER)(v1 + 8));
    }
  }
}
