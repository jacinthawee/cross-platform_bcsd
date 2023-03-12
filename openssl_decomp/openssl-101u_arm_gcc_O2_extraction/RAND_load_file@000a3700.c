
int RAND_load_file(char *file,long max_bytes)

{
  int iVar1;
  FILE *__stream;
  int iVar2;
  int num;
  undefined4 in_stack_fffffb80;
  FILE *pFVar3;
  undefined4 in_stack_fffffb84;
  stat sStack_478;
  undefined auStack_41c [1024];
  int local_1c;
  
  local_1c = __stack_chk_guard;
  if ((((file == (char *)0x0) || (iVar1 = __xstat(3,file,&sStack_478), iVar1 < 0)) ||
      (RAND_add(&sStack_478,0x58,(double)CONCAT44(in_stack_fffffb84,in_stack_fffffb80)),
      max_bytes == 0)) || (__stream = fopen(file,"rb"), __stream == (FILE *)0x0)) {
    iVar1 = 0;
  }
  else {
    if ((sStack_478.st_mode & 0x6000) != 0) {
      if (max_bytes == -1) {
        max_bytes = 0x800;
      }
      setvbuf(__stream,(char *)0x0,2,0);
    }
    iVar1 = 0;
    do {
      if (max_bytes < 1) {
        num = 0x400;
      }
      else {
        num = 0x400;
        if (max_bytes < 0x401) {
          num = max_bytes;
        }
      }
      pFVar3 = __stream;
      iVar2 = __fread_chk(auStack_41c,0x400,1,num);
      if (iVar2 < 1) break;
      iVar1 = iVar1 + iVar2;
      RAND_add(auStack_41c,num,(double)CONCAT44(in_stack_fffffb84,pFVar3));
    } while ((max_bytes < 1) || (max_bytes = max_bytes - num, 0 < max_bytes));
    fclose(__stream);
    OPENSSL_cleanse(auStack_41c,0x400);
  }
  if (local_1c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}

