
EVP_PKEY * TS_CONF_load_key(char *param_1,void *param_2)

{
  BIO *bp;
  EVP_PKEY *pEVar1;
  
  bp = BIO_new_file(param_1,"r");
  if (bp != (BIO *)0x0) {
    pEVar1 = PEM_read_bio_PrivateKey(bp,(EVP_PKEY **)0x0,(undefined1 *)0x0,param_2);
    if (pEVar1 != (EVP_PKEY *)0x0) goto LAB_08198bd5;
  }
  pEVar1 = (EVP_PKEY *)0x0;
  __fprintf_chk(stderr,1,"unable to load private key: %s\n",param_1);
LAB_08198bd5:
  BIO_free(bp);
  return pEVar1;
}

