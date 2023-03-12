
int i2b_PVK_bio(BIO *out,EVP_PKEY *pk,int enclevel,undefined1 *cb,void *u)

{
  int len;
  int iVar1;
  void *local_1c [2];
  
  local_1c[0] = (void *)0x0;
  len = i2b_PVK_constprop_5(local_1c);
  if (-1 < len) {
    iVar1 = BIO_write(out,local_1c[0],len);
    CRYPTO_free(local_1c[0]);
    if (iVar1 == len) {
      ERR_put_error(9,0x8a,0x76,"pvkfmt.c",0x377);
      return iVar1;
    }
  }
  return -1;
}

