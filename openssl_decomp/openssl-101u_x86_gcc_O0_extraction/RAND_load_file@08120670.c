
int RAND_load_file(char *file,long max_bytes)

{
  int iVar1;
  FILE *__stream;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  stat local_478;
  undefined local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (file != (char *)0x0) {
    iVar1 = __xstat(3,file,&local_478);
    if (-1 < iVar1) {
      RAND_add(&local_478,0x58,0.0);
      if (max_bytes != 0) {
        __stream = fopen(file,"rb");
        if (__stream != (FILE *)0x0) {
          if ((local_478.st_mode & 0x6000) != 0) {
            if (max_bytes == -1) {
              max_bytes = 0x800;
            }
            setvbuf(__stream,(char *)0x0,2,0);
          }
          iVar1 = 0;
          do {
            while (max_bytes < 1) {
              iVar3 = __fread_chk(local_420,0x400,1,0x400,__stream);
              if (iVar3 < 1) goto LAB_0812078e;
              iVar1 = iVar1 + iVar3;
              RAND_add(local_420,0x400,(double)iVar3);
            }
            iVar3 = 0x400;
            if (max_bytes < 0x401) {
              iVar3 = max_bytes;
            }
            iVar2 = __fread_chk(local_420,0x400,1,iVar3,__stream);
            if (iVar2 < 1) break;
            max_bytes = max_bytes - iVar3;
            RAND_add(local_420,iVar3,(double)iVar2);
            iVar1 = iVar1 + iVar2;
          } while (0 < max_bytes);
LAB_0812078e:
          fclose(__stream);
          OPENSSL_cleanse(local_420,0x400);
          goto LAB_081206c7;
        }
      }
    }
  }
  iVar1 = 0;
LAB_081206c7:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

