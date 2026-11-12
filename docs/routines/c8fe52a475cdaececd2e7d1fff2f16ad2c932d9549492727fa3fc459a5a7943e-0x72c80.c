
char __fastcall sub_180072C80(__int64 a1)
{
  _BYTE *v2;
  bool v3;
  const char *v4;
  const char *v5;
  int v6;
  const char *v8;
  int v9;
  _BYTE *Block;
  unsigned __int64 v11;

  sub_18002AE70();
  sub_18000BD20();
  if ( v11 > 0xF )
  {
    v2 = Block;
    if ( v11 + 1 >= 0x1000 )
    {
      v2 = *((_BYTE **)Block - 1);
      if ( (unsigned __int64)(Block - v2 - 8) > 0x1F )
        _invalid_parameter_noinfo_noreturn();
    }
    j_j_j_j_free(v2);
  }
  v3 = *(_QWORD *)(a1 + 1008) == 0;
  v4 = "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp";
  if ( v3 )
  {
    if ( strrchr(
           "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
           92) != nullptr )
      v5 = strrchr(
             "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
             92)
         + 1;
    else
      v5 = "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp";
    if ( strrchr(v5, 47) != nullptr )
    {
      if ( strrchr(
             "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
             92) != nullptr )
        v4 = strrchr(
               "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
               92)
           + 1;
      v6 = 47;
    }
    else
    {
      if ( strrchr(
             "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
             92) == nullptr )
      {
LABEL_17:
        GXP::LogMessage(1, v4, 181, "GenerateSessionToken: CSPRNG failed");
        return 0;
      }
      v6 = 92;
    }
    v4 = strrchr(v4, v6) + 1;
    goto LABEL_17;
  }
  if ( strrchr(
         "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
         92) != nullptr )
    v8 = strrchr(
           "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
           92)
       + 1;
  else
    v8 = "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp";
  if ( strrchr(v8, 47) != nullptr )
  {
    if ( strrchr(
           "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
           92) != nullptr )
      v4 = strrchr(
             "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
             92)
         + 1;
    v9 = 47;
    goto LABEL_27;
  }
  if ( strrchr(
         "C:\\tmp\\workspace\\NvAppP1\\qemu_NvAppWinNightly\\plugins\\src\\plugin-modules\\McpServer\\plugin\\McpServerPlugin.cpp",
         92) != nullptr )
  {
    v9 = 92;
LABEL_27:
    v4 = strrchr(v4, v9) + 1;
  }
  GXP::LogMessage(2, v4, 184, "GenerateSessionToken: 256-bit session token generated");
  return 1;
}
