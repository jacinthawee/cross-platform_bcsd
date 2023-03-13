
int DSA_print_fp(FILE *bp,DSA *x,int off)

{
  BIO_METHOD *type;
  BIO *bp_00;
  EVP_PKEY *pkey;
  int iVar1;
  
  type = BIO_s_file();
  bp_00 = BIO_new(type);
  if (bp_00 == (BIO *)0x0) {
    ERR_put_error(10,0x69,7,"dsa_prn.c",0x48);
    return 0;
  }
  BIO_ctrl(bp_00,0x6a,0,bp);
  pkey = EVP_PKEY_new();
  if (pkey != (EVP_PKEY *)0x0) {
    iVar1 = EVP_PKEY_set1_DSA(pkey,x);
    if (iVar1 != 0) {
      iVar1 = EVP_PKEY_print_private(bp_00,pkey,off,(ASN1_PCTX *)0x0);
      EVP_PKEY_free(pkey);
      goto LAB_0810e8bc;
    }
  }
  iVar1 = 0;
LAB_0810e8bc:
  BIO_free(bp_00);
  return iVar1;
}

