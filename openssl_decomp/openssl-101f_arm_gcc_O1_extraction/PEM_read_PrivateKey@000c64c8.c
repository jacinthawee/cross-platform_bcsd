
EVP_PKEY * PEM_read_PrivateKey(FILE *fp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  BIO_METHOD *type;
  BIO *bp;
  BIO *pBVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x7c,7,"pem_pkey.c",0xd8);
  }
  else {
    BIO_ctrl(bp,0x6a,0,fp);
    pBVar1 = (BIO *)PEM_read_bio_PrivateKey(bp,x,cb,u);
    BIO_free(bp);
    bp = pBVar1;
  }
  return (EVP_PKEY *)bp;
}

