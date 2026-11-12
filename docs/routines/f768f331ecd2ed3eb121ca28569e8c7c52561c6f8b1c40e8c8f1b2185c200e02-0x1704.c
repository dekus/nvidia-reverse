
NTSTATUS __fastcall sub_140001704(struct _DRIVER_OBJECT *a1)
{
  NTSTATUS result;
  __int64 v3;
  NTSTATUS v4;
  PVOID StartContext;
  void *ThreadHandle;

  StartContext = nullptr;
  result = IoCreateDevice(a1, 0x20u, nullptr, 0x22u, 0x100u, 0, (PDEVICE_OBJECT *)&StartContext);
  if ( result >= 0 )
  {
    a1->MajorFunction[0] = (PDRIVER_DISPATCH)sub_140001520;
    a1->MajorFunction[2] = (PDRIVER_DISPATCH)sub_140001520;
    a1->DriverUnload = (PDRIVER_UNLOAD)sub_140001690;
    sub_140001934(&unk_140003150, sub_140001830, &unk_140004000, &unk_140004000);
    v3 = *((_QWORD *)StartContext + 8);
    *(_BYTE *)v3 = 0;
    *(_QWORD *)(v3 + 8) = -2000000;
    sub_140001590(v3);
    v4 = PsCreateSystemThread(
           &ThreadHandle,
           0,
           nullptr,
           nullptr,
           nullptr,
           (PKSTART_ROUTINE)HandleInformation,
           StartContext);
    if ( v4 >= 0 )
      ObReferenceObjectByHandle(ThreadHandle, 0x1FFFFFu, nullptr, 0, (PVOID *)(v3 + 16), nullptr);
    else
      IoDeleteDevice((PDEVICE_OBJECT)StartContext);
    ZwClose(ThreadHandle);
    return v4;
  }
  else
  {
    _mm_lfence();
  }
  return result;
}
