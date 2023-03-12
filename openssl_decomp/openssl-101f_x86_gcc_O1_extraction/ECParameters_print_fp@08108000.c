
int ECParameters_print_fp(FILE *fp,EC_KEY *key)

{
  BIO_METHOD *type;
  BIO *bp;
  EVP_PKEY *pkey;
  int iVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x10,0x94,0x20,"eck_prn.c",0x6e);
    return 0;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  pkey = EVP_PKEY_new();
  if (pkey != (EVP_PKEY *)0x0) {
    iVar1 = EVP_PKEY_set1_EC_KEY(pkey,key);
    if (iVar1 != 0) {
      iVar1 = EVP_PKEY_print_params(bp,pkey,4,(ASN1_PCTX *)0x0);
      EVP_PKEY_free(pkey);
      goto LAB_0810804c;
    }
  }
  iVar1 = 0;
LAB_0810804c:
  BIO_free(bp);
  return iVar1;
}

