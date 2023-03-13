
int RAND_write_file(char *file)

{
  int iVar1;
  FILE *__s;
  size_t sVar2;
  size_t sVar3;
  int in_GS_OFFSET;
  stat local_478;
  uchar local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = __xstat(3,file,&local_478);
  if ((iVar1 != -1) && (sVar2 = 1, (local_478.st_mode & 0xb000) == 0x2000)) goto LAB_081208ef;
  iVar1 = open(file,0x41,0x180);
  if (iVar1 == -1) {
LAB_08120910:
    __s = fopen(file,"wb");
    if (__s == (FILE *)0x0) {
      sVar2 = 0;
      goto LAB_081208ef;
    }
  }
  else {
    __s = fdopen(iVar1,"wb");
    if (__s == (FILE *)0x0) goto LAB_08120910;
  }
  chmod(file,0x180);
  iVar1 = RAND_bytes(local_420,0x400);
  sVar2 = fwrite(local_420,1,0x400,__s);
  sVar3 = 0;
  if (-1 < (int)sVar2) {
    sVar3 = sVar2;
  }
  fclose(__s);
  OPENSSL_cleanse(local_420,0x400);
  sVar2 = 0xffffffff;
  if (0 < iVar1) {
    sVar2 = sVar3;
  }
LAB_081208ef:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return sVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

