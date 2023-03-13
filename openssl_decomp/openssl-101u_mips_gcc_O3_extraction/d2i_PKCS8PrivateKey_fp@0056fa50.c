
EVP_PKEY * d2i_PKCS8PrivateKey_fp(FILE *fp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  BIO *bp;
  EVP_PKEY *pEVar1;
  
  bp = (BIO *)(*(code *)PTR_BIO_new_fp_006a7248)(fp,0);
  if (bp == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x79,7,"pem_pk8.c",0xf5);
    pEVar1 = (EVP_PKEY *)0x0;
  }
  else {
    pEVar1 = d2i_PKCS8PrivateKey_bio(bp,x,cb,u);
    (*(code *)PTR_BIO_free_006a6e70)(bp);
  }
  return pEVar1;
}

