
EVP_PKEY * d2i_PKCS8PrivateKey_bio(BIO *bp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  X509_SIG *a;
  int passlen;
  PKCS8_PRIV_KEY_INFO *p8;
  EVP_PKEY *pEVar1;
  int in_GS_OFFSET;
  char local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  a = d2i_PKCS8_bio(bp,(X509_SIG **)0x0);
  if (a != (X509_SIG *)0x0) {
    if (cb == (undefined1 *)0x0) {
      passlen = PEM_def_callback(local_420,0x400,0,u);
    }
    else {
      passlen = (*(code *)cb)(local_420,0x400,0,u);
    }
    if (passlen < 1) {
      ERR_put_error(9,0x78,0x68,"pem_pk8.c",0xaf);
      X509_SIG_free(a);
    }
    else {
      p8 = PKCS8_decrypt(a,local_420,passlen);
      X509_SIG_free(a);
      if (p8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
        pEVar1 = EVP_PKCS82PKEY(p8);
        PKCS8_PRIV_KEY_INFO_free(p8);
        if (pEVar1 != (EVP_PKEY *)0x0) {
          if (x != (EVP_PKEY **)0x0) {
            if (*x != (EVP_PKEY *)0x0) {
              EVP_PKEY_free(*x);
            }
            *x = pEVar1;
          }
          goto LAB_08156773;
        }
      }
    }
  }
  pEVar1 = (EVP_PKEY *)0x0;
LAB_08156773:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pEVar1;
}

