
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int OPENSSL_issetugid(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_getuid_006a9aa4)();
  iVar2 = (*(code *)PTR_geteuid_006a9a98)();
  if (iVar1 != iVar2) {
    return 1;
  }
  iVar1 = (*(code *)PTR_getgid_006a99fc)();
  iVar2 = (*(code *)PTR_getegid_006a9a8c)();
  return (uint)(iVar1 != iVar2);
}

