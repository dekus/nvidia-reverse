
void __fastcall sub_140001690(__int64 a1)
{
  struct _DEVICE_OBJECT *v1;
  PVOID DeviceExtension;
  __int64 v3;
  void *v4;

  v1 = *(struct _DEVICE_OBJECT **)(a1 + 8);
  DeviceExtension = v1->DeviceExtension;
  v3 = *((_QWORD *)DeviceExtension + 3);
  if ( v3 != 0 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v3 + 8LL))(v3, 1);
  v4 = *((void **)DeviceExtension + 2);
  *(_BYTE *)DeviceExtension = 1;
  KeWaitForSingleObject(v4, Executive, 0, 0, nullptr);
  ObfDereferenceObject(*((PVOID *)DeviceExtension + 2));
  sub_14000194C(&unk_140004000);
  IoDeleteDevice(v1);
}
