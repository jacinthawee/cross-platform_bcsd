
int ASN1_i2d_bio(undefined1 *i2d,BIO *out,uchar *x)

{
  int iVar1;
  void *ptr;
  int iVar2;
  int iVar3;
  int in_GS_OFFSET;
  void *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = (*(code *)i2d)(x,0);
  ptr = CRYPTO_malloc(iVar1,"a_i2d_fp.c",0x5a);
  if (ptr == (void *)0x0) {
    ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5c);
    iVar1 = 0;
  }
  else {
    local_24 = ptr;
    (*(code *)i2d)(x,&local_24);
    iVar3 = 0;
    while( true ) {
      iVar2 = BIO_write(out,(void *)((int)ptr + iVar3),iVar1);
      if (iVar1 == iVar2) break;
      if (iVar2 < 1) {
        iVar1 = 0;
        goto LAB_081395f2;
      }
      iVar3 = iVar3 + iVar2;
      iVar1 = iVar1 - iVar2;
    }
    iVar1 = 1;
LAB_081395f2:
    CRYPTO_free(ptr);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

