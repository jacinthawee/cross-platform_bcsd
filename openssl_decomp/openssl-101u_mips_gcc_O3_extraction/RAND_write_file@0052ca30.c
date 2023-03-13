
int RAND_write_file(char *file)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *siz;
  char *dst;
  undefined auStack_4ac [20];
  uint local_498;
  uchar auStack_41c [1024];
  char *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(char **)PTR___stack_chk_guard_006a9ae8;
  siz = file;
  iVar2 = (*(code *)PTR___xstat_006a9a84)(3,file,auStack_4ac);
  if ((iVar2 == -1) || (iVar2 = 1, (local_498 & 0xb000) != 0x2000)) {
    iVar2 = (*(code *)PTR_open_006a9a3c)(file,0x101,0x180);
    if ((iVar2 == -1) || (iVar3 = (*(code *)PTR_fdopen_006a9b20)(iVar2,&DAT_00632420), iVar3 == 0))
    {
      siz = "wb";
      iVar3 = (*(code *)PTR_fopen_006a9b00)(file);
      iVar2 = 0;
      if (iVar3 == 0) goto LAB_0052cb64;
    }
    (*(code *)PTR_chmod_006a9968)(file,0x180);
    iVar4 = RAND_bytes(auStack_41c,0x400);
    iVar5 = (*(code *)PTR_fwrite_006a9a74)(auStack_41c,1,0x400,iVar3);
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    (*(code *)PTR_fclose_006a9998)(iVar3);
    siz = &DAT_00000400;
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(auStack_41c);
    iVar2 = -1;
    if (0 < iVar4) {
      iVar2 = iVar5;
    }
  }
LAB_0052cb64:
  if (local_1c == *(char **)puVar1) {
    return iVar2;
  }
  dst = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = (*(code *)PTR_OPENSSL_issetugid_006a8914)();
  if ((iVar2 == 0) &&
     (pcVar6 = (char *)(*(code *)PTR_getenv_006a9a60)("RANDFILE"), pcVar6 != (char *)0x0)) {
    if ((*pcVar6 != '\0') &&
       (iVar2 = (*(code *)PTR_strlen_006a9a24)(pcVar6), (char *)(iVar2 + 1) < siz)) {
      pcVar6 = (char *)BUF_strlcpy(dst,pcVar6,(size_t)siz);
      if (siz <= pcVar6) {
        dst = (char *)0x0;
      }
      return (int)dst;
    }
    iVar2 = (*(code *)PTR_OPENSSL_issetugid_006a8914)();
    if (iVar2 == 0) goto LAB_0052cc10;
  }
  else {
    iVar2 = (*(code *)PTR_OPENSSL_issetugid_006a8914)();
    if (iVar2 != 0) goto LAB_0052cc2c;
LAB_0052cc10:
    pcVar6 = (char *)(*(code *)PTR_getenv_006a9a60)(&DAT_00667da8);
    if (pcVar6 == (char *)0x0) goto LAB_0052cc2c;
  }
  if ((*pcVar6 != '\0') &&
     (iVar2 = (*(code *)PTR_strlen_006a9a24)(pcVar6), (char *)(iVar2 + 6) < siz)) {
    BUF_strlcpy(dst,pcVar6,(size_t)siz);
    BUF_strlcat(dst,"/",(size_t)siz);
    BUF_strlcat(dst,".rnd",(size_t)siz);
    return (int)dst;
  }
LAB_0052cc2c:
  *dst = '\0';
  return (int)dst;
}

