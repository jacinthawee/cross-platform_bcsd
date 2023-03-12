
EVP_PKEY * d2i_PKCS8PrivateKey_bio(BIO *bp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  X509_SIG *a;
  int passlen;
  PKCS8_PRIV_KEY_INFO *p8;
  EVP_PKEY *pEVar1;
  char acStack_424 [1024];
  int local_24;
  
  local_24 = __stack_chk_guard;
  a = d2i_PKCS8_bio(bp,(X509_SIG **)0x0);
  if (a != (X509_SIG *)0x0) {
    if (cb == (undefined1 *)0x0) {
      passlen = PEM_def_callback(acStack_424,0x400,0,u);
    }
    else {
      passlen = (*(code *)cb)(acStack_424,0x400,0,u);
    }
    if (passlen < 1) {
      ERR_put_error(9,0x78,0x68,"pem_pk8.c",0xaf);
      X509_SIG_free(a);
    }
    else {
      p8 = PKCS8_decrypt(a,acStack_424,passlen);
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
          goto LAB_000c384a;
        }
      }
    }
  }
  pEVar1 = (EVP_PKEY *)0x0;
LAB_000c384a:
  if (local_24 == __stack_chk_guard) {
    return pEVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

