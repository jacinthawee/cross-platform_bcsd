
int DSA_print(BIO *bp,DSA *x,int off)

{
  EVP_PKEY *pkey;
  int iVar1;
  
  pkey = EVP_PKEY_new();
  if ((pkey != (EVP_PKEY *)0x0) && (iVar1 = EVP_PKEY_set1_DSA(pkey,x), iVar1 != 0)) {
    iVar1 = EVP_PKEY_print_private(bp,pkey,off,(ASN1_PCTX *)0x0);
    EVP_PKEY_free(pkey);
    return iVar1;
  }
  return 0;
}

