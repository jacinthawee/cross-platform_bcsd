
int i2b_PVK_bio(BIO *out,EVP_PKEY *pk,int enclevel,undefined1 *cb,void *u)

{
  int iVar1;
  int len;
  int iVar2;
  int in_GS_OFFSET;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  len = i2b_PVK_constprop_4(cb,u);
  if (-1 < len) {
    iVar2 = BIO_write(out,(void *)0x0,len);
    CRYPTO_free((void *)0x0);
    if (len == iVar2) {
      ERR_put_error(9,0x8a,0x76,"pvkfmt.c",0x377);
      goto LAB_0815add0;
    }
  }
  len = -1;
LAB_0815add0:
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return len;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

