
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int OPENSSL_issetugid(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_getuid_006aabac)();
  iVar2 = (*(code *)PTR_geteuid_006aaba0)();
  if (iVar1 != iVar2) {
    return 1;
  }
  iVar1 = (*(code *)PTR_getgid_006aab08)();
  iVar2 = (*(code *)PTR_getegid_006aab94)();
  return (uint)(iVar1 != iVar2);
}

