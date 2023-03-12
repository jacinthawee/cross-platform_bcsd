
int TS_CONF_set_signer_key
              (CONF *param_1,char *param_2,char *param_3,void *param_4,undefined4 param_5)

{
  BIO *bp;
  EVP_PKEY *pkey;
  int iVar1;
  
  if ((param_3 == (char *)0x0) &&
     (param_3 = NCONF_get_string(param_1,param_2,"signer_key"), param_3 == (char *)0x0)) {
    __fprintf_chk(stderr,1,"variable lookup failed for %s::%s\n",param_2,"signer_key");
    EVP_PKEY_free((EVP_PKEY *)0x0);
    return 0;
  }
  bp = BIO_new_file(param_3,"r");
  if ((bp == (BIO *)0x0) ||
     (pkey = PEM_read_bio_PrivateKey(bp,(EVP_PKEY **)0x0,(undefined1 *)0x0,param_4),
     pkey == (EVP_PKEY *)0x0)) {
    pkey = (EVP_PKEY *)0x0;
    __fprintf_chk(stderr,1,"unable to load private key: %s\n",param_3);
    BIO_free(bp);
    iVar1 = 0;
  }
  else {
    BIO_free(bp);
    iVar1 = TS_RESP_CTX_set_signer_key(param_5,pkey);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  EVP_PKEY_free(pkey);
  return iVar1;
}

