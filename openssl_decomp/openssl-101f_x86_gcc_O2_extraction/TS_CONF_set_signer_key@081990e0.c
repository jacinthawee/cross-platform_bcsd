
bool TS_CONF_set_signer_key
               (CONF *param_1,char *param_2,char *param_3,void *param_4,undefined4 param_5)

{
  BIO *bp;
  EVP_PKEY *pkey;
  int iVar1;
  bool bVar2;
  
  if (param_3 == (char *)0x0) {
    param_3 = NCONF_get_string(param_1,param_2,"signer_key");
    if (param_3 == (char *)0x0) {
      pkey = (EVP_PKEY *)0x0;
      bVar2 = false;
      __fprintf_chk(stderr,1,"variable lookup failed for %s::%s\n",param_2,"signer_key");
      goto LAB_0819913f;
    }
  }
  bp = BIO_new_file(param_3,"r");
  if (bp != (BIO *)0x0) {
    pkey = PEM_read_bio_PrivateKey(bp,(EVP_PKEY **)0x0,(undefined1 *)0x0,param_4);
    if (pkey != (EVP_PKEY *)0x0) {
      BIO_free(bp);
      iVar1 = TS_RESP_CTX_set_signer_key(param_5,pkey);
      bVar2 = iVar1 != 0;
      goto LAB_0819913f;
    }
  }
  pkey = (EVP_PKEY *)0x0;
  __fprintf_chk(stderr,1,"unable to load private key: %s\n",param_3);
  bVar2 = false;
  BIO_free(bp);
LAB_0819913f:
  EVP_PKEY_free(pkey);
  return bVar2;
}

