
__int64 sub_18007C320()
{
  LSTATUS ValueW;
  const char *v1;
  const char *v2;
  int v3;
  unsigned int v5;
  int v6;
  const char *v7;
  const char *v8;
  const char *v9;
  int v10;
  int pvData;
  DWORD pcbData;

  pcbData = 4;
  pvData = 0;
  ValueW = RegGetValueW(
             HKEY_LOCAL_MACHINE,
             L"SOFTWARE\\NVIDIA Corporation\\Global\\NvApp",
             L"McpAccessLevel",
             0x10010u,
             nullptr,
             &pvData,
             &pcbData);
  if ( ValueW != 0 )
  {
    v1 = "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp";
    if ( strrchr(
           "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
           92) != nullptr )
      v2 = strrchr(
             "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
             92)
         + 1;
    else
      v2 = "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp";
    if ( strrchr(v2, 47) != nullptr )
    {
      if ( strrchr(
             "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
             92) != nullptr )
        v1 = strrchr(
               "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
               92)
           + 1;
      v3 = 47;
    }
    else
    {
      if ( strrchr(
             "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
             92) == nullptr )
      {
LABEL_12:
        GXP::LogMessage(2, v1, 114, "McpServerPlugin: McpAccessLevel not set (rc=%ld), defaulting to standard", ValueW);
        return 1;
      }
      v3 = 92;
    }
    v1 = strrchr(v1, v3) + 1;
    goto LABEL_12;
  }
  v5 = 1;
  v6 = pvData;
  v7 = "standard";
  if ( pvData == 1 )
  {
    v7 = "readonly";
    v5 = 0;
  }
  else if ( pvData == 3 )
  {
    v7 = "full_access";
    v5 = 2;
  }
  v8 = "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp";
  if ( strrchr(
         "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
         92) != nullptr )
    v9 = strrchr(
           "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
           92)
       + 1;
  else
    v9 = "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp";
  if ( strrchr(v9, 47) != nullptr )
  {
    if ( strrchr(
           "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
           92) != nullptr )
      v8 = strrchr(
             "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
             92)
         + 1;
    v10 = 47;
    goto LABEL_26;
  }
  if ( strrchr(
         "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
         92) != nullptr )
  {
    v10 = 92;
LABEL_26:
    v8 = strrchr(v8, v10) + 1;
  }
  GXP::LogMessage(2, v8, 134, "McpServerPlugin: McpAccessLevel registry value=%lu, resolved to '%s'", v6, v7);
  return v5;
}
