
X509 * TS_CONF_load_cert(char *param_1)

{
  BIO *bp;
  X509 *pXVar1;
  
  bp = BIO_new_file(param_1,"r");
  if ((bp != (BIO *)0x0) &&
     (pXVar1 = PEM_read_bio_X509_AUX(bp,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0),
     pXVar1 != (X509 *)0x0)) {
    BIO_free(bp);
    return pXVar1;
  }
  __fprintf_chk(stderr,1,"unable to load certificate: %s\n",param_1);
  BIO_free(bp);
  return (X509 *)0x0;
}

