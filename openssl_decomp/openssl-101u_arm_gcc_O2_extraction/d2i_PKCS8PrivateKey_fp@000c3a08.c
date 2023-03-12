
EVP_PKEY * d2i_PKCS8PrivateKey_fp(FILE *fp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  BIO *bp;
  BIO *pBVar1;
  
  bp = BIO_new_fp(fp,0);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x79,7,"pem_pk8.c",0xf5);
  }
  else {
    pBVar1 = (BIO *)d2i_PKCS8PrivateKey_bio(bp,x,cb,u);
    BIO_free(bp);
    bp = pBVar1;
  }
  return (EVP_PKEY *)bp;
}

