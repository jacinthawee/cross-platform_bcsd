
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
  if ((iVar1 == -1) || (sVar3 = 1, (local_478.st_mode & 0xb000) != 0x2000)) {
    sVar3 = 0;
    __s = fopen(file,"wb");
    if (__s != (FILE *)0x0) {
      chmod(file,0x180);
      iVar1 = RAND_bytes(local_420,0x400);
      sVar2 = fwrite(local_420,1,0x400,__s);
      if (-1 < (int)sVar2) {
        sVar3 = sVar2;
      }
      fclose(__s);
      OPENSSL_cleanse(local_420,0x400);
      if (iVar1 < 1) {
        sVar3 = 0xffffffff;
      }
    }
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return sVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

