
int RAND_write_file(char *file)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *siz;
  char *dst;
  undefined auStack_4ac [20];
  uint local_498;
  uchar auStack_41c [1024];
  char *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(char **)PTR___stack_chk_guard_006aabf0;
  siz = file;
  iVar2 = (*(code *)PTR___xstat_006aab8c)(3,file,auStack_4ac);
  if ((iVar2 == -1) || (iVar2 = 1, (local_498 & 0xb000) != 0x2000)) {
    siz = "wb";
    iVar2 = (*(code *)PTR_fopen_006aac08)(file);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      (*(code *)PTR_chmod_006aaa78)(file,0x180);
      iVar3 = RAND_bytes(auStack_41c,0x400);
      iVar4 = (*(code *)PTR_fwrite_006aab7c)(auStack_41c,1,0x400,iVar2);
      if (iVar4 < 0) {
        iVar4 = 0;
      }
      (*(code *)PTR_fclose_006aaaa4)(iVar2);
      siz = &DAT_00000400;
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_41c);
      iVar2 = -1;
      if (0 < iVar3) {
        iVar2 = iVar4;
      }
    }
  }
  if (local_1c == *(char **)puVar1) {
    return iVar2;
  }
  dst = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = (*(code *)PTR_OPENSSL_issetugid_006a9a34)();
  if ((iVar2 == 0) &&
     (pcVar5 = (char *)(*(code *)PTR_getenv_006aab6c)("RANDFILE"), pcVar5 != (char *)0x0)) {
    if ((*pcVar5 != '\0') &&
       (iVar2 = (*(code *)PTR_strlen_006aab30)(pcVar5), (char *)(iVar2 + 1) < siz)) {
      pcVar5 = (char *)BUF_strlcpy(dst,pcVar5,(size_t)siz);
      if (siz <= pcVar5) {
        dst = (char *)0x0;
      }
      return (int)dst;
    }
    iVar2 = (*(code *)PTR_OPENSSL_issetugid_006a9a34)();
    if (iVar2 == 0) goto LAB_0052ff6c;
  }
  else {
    iVar2 = (*(code *)PTR_OPENSSL_issetugid_006a9a34)();
    if (iVar2 != 0) goto LAB_0052ff88;
LAB_0052ff6c:
    pcVar5 = (char *)(*(code *)PTR_getenv_006aab6c)(&DAT_00668868);
    if (pcVar5 == (char *)0x0) goto LAB_0052ff88;
  }
  if ((*pcVar5 != '\0') &&
     (iVar2 = (*(code *)PTR_strlen_006aab30)(pcVar5), (char *)(iVar2 + 6) < siz)) {
    BUF_strlcpy(dst,pcVar5,(size_t)siz);
    BUF_strlcat(dst,"/",(size_t)siz);
    BUF_strlcat(dst,".rnd",(size_t)siz);
    return (int)dst;
  }
LAB_0052ff88:
  *dst = '\0';
  return (int)dst;
}

