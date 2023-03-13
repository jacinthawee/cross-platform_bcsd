
int EC_KEY_print_fp(FILE *fp,EC_KEY *key,int off)

{
  BIO_METHOD *type;
  BIO *bp;
  EVP_PKEY *pkey;
  int iVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x10,0xb5,0x20,"eck_prn.c",0x5c);
    return 0;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  pkey = EVP_PKEY_new();
  if (pkey != (EVP_PKEY *)0x0) {
    iVar1 = EVP_PKEY_set1_EC_KEY(pkey,key);
    if (iVar1 != 0) {
      iVar1 = EVP_PKEY_print_private(bp,pkey,off,(ASN1_PCTX *)0x0);
      EVP_PKEY_free(pkey);
      goto LAB_0810657c;
    }
  }
  iVar1 = 0;
LAB_0810657c:
  BIO_free(bp);
  return iVar1;
}

