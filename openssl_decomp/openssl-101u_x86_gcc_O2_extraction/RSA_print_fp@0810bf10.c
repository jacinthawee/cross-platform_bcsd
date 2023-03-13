
int RSA_print_fp(FILE *fp,RSA *r,int offset)

{
  BIO_METHOD *type;
  BIO *bp;
  EVP_PKEY *pkey;
  int iVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(4,0x74,7,"rsa_prn.c",0x48);
    return 0;
  }
  BIO_ctrl(bp,0x6a,0,fp);
  pkey = EVP_PKEY_new();
  if (pkey != (EVP_PKEY *)0x0) {
    iVar1 = EVP_PKEY_set1_RSA(pkey,r);
    if (iVar1 != 0) {
      iVar1 = EVP_PKEY_print_private(bp,pkey,offset,(ASN1_PCTX *)0x0);
      EVP_PKEY_free(pkey);
      goto LAB_0810bf5c;
    }
  }
  iVar1 = 0;
LAB_0810bf5c:
  BIO_free(bp);
  return iVar1;
}

