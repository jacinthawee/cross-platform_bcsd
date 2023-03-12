
int TS_CONF_set_signer_cert(CONF *param_1,char *param_2,char *param_3,undefined4 param_4)

{
  BIO *bp;
  X509 *a;
  int iVar1;
  
  if ((param_3 == (char *)0x0) &&
     (param_3 = NCONF_get_string(param_1,param_2,"signer_cert"), param_3 == (char *)0x0)) {
    __fprintf_chk(stderr,1,"variable lookup failed for %s::%s\n",param_2,"signer_cert");
    X509_free((X509 *)0x0);
    return 0;
  }
  bp = BIO_new_file(param_3,"r");
  if ((bp == (BIO *)0x0) ||
     (a = PEM_read_bio_X509_AUX(bp,(X509 **)0x0,(undefined1 *)0x0,(void *)0x0), a == (X509 *)0x0)) {
    a = (X509 *)0x0;
    __fprintf_chk(stderr,1,"unable to load certificate: %s\n",param_3);
    BIO_free(bp);
    iVar1 = 0;
  }
  else {
    BIO_free(bp);
    iVar1 = TS_RESP_CTX_set_signer_cert(param_4,a);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  X509_free(a);
  return iVar1;
}

