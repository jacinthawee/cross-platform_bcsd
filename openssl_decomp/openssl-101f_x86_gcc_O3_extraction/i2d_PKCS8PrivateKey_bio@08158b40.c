
/* WARNING: Removing unreachable block (ram,0x08158958) */
/* WARNING: Removing unreachable block (ram,0x08158980) */

int i2d_PKCS8PrivateKey_bio
              (BIO *bp,EVP_PKEY *x,EVP_CIPHER *enc,char *kstr,int klen,undefined1 *cb,void *u)

{
  PKCS8_PRIV_KEY_INFO *a;
  int iVar1;
  X509_SIG *p8;
  size_t len;
  int in_GS_OFFSET;
  char acStack_420 [1024];
  int iStack_20;
  
  iStack_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = EVP_PKEY2PKCS8(x);
  if (a == (PKCS8_PRIV_KEY_INFO *)0x0) {
    ERR_put_error(9,0x7e,0x73,"pem_pk8.c",0x7a);
    iVar1 = 0;
  }
  else if (enc == (EVP_CIPHER *)0x0) {
    iVar1 = i2d_PKCS8_PRIV_KEY_INFO_bio(bp,a);
    PKCS8_PRIV_KEY_INFO_free(a);
  }
  else {
    if (kstr == (char *)0x0) {
      if (cb == (undefined1 *)0x0) {
        len = PEM_def_callback(acStack_420,0x400,1,u);
      }
      else {
        len = (*(code *)cb)(acStack_420,0x400,1,u);
      }
      if ((int)len < 1) {
        ERR_put_error(9,0x7e,0x6f,"pem_pk8.c",0x82);
        PKCS8_PRIV_KEY_INFO_free(a);
        iVar1 = 0;
        goto LAB_081588cb;
      }
      p8 = PKCS8_encrypt(-1,enc,acStack_420,len,(uchar *)0x0,0,0,a);
      OPENSSL_cleanse(acStack_420,len);
    }
    else {
      p8 = PKCS8_encrypt(-1,enc,kstr,klen,(uchar *)0x0,0,0,a);
    }
    PKCS8_PRIV_KEY_INFO_free(a);
    iVar1 = i2d_PKCS8_bio(bp,p8);
    X509_SIG_free(p8);
  }
LAB_081588cb:
  if (iStack_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

