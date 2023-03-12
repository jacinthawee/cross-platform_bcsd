
int ASN1_i2d_fp(undefined1 *i2d,FILE *out,void *x)

{
  BIO_METHOD *type;
  BIO *bp;
  int num;
  void *ptr;
  int iVar1;
  int iVar2;
  void *pvVar3;
  int in_GS_OFFSET;
  void *local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ptr = (void *)0x0;
    ERR_put_error(0xd,0x75,7,"a_i2d_fp.c",0x4a);
  }
  else {
    BIO_ctrl(bp,0x6a,0,out);
    num = (*(code *)i2d)(x,0);
    ptr = CRYPTO_malloc(num,"a_i2d_fp.c",0x5b);
    if (ptr == (void *)0x0) {
      ERR_put_error(0xd,0x74,0x41,"a_i2d_fp.c",0x5e);
    }
    else {
      local_24 = ptr;
      (*(code *)i2d)(x,&local_24);
      iVar2 = 0;
      while( true ) {
        iVar1 = BIO_write(bp,(void *)((int)ptr + iVar2),num);
        if (num == iVar1) break;
        if (iVar1 < 1) {
          pvVar3 = (void *)0x0;
          goto LAB_0813bca2;
        }
        iVar2 = iVar2 + iVar1;
        num = num - iVar1;
      }
      pvVar3 = (void *)0x1;
LAB_0813bca2:
      CRYPTO_free(ptr);
      ptr = pvVar3;
    }
    BIO_free(bp);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return (int)ptr;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

