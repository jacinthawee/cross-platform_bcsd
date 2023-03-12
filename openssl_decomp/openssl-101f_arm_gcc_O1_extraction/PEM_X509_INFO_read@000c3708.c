
stack_st_X509_INFO * PEM_X509_INFO_read(FILE *fp,stack_st_X509_INFO *sk,undefined1 *cb,void *u)

{
  BIO_METHOD *type;
  BIO *bp;
  BIO *pBVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x73,7,"pem_info.c",0x51);
  }
  else {
    BIO_ctrl(bp,0x6a,0,fp);
    pBVar1 = (BIO *)PEM_X509_INFO_read_bio(bp,sk,cb,u);
    BIO_free(bp);
    bp = pBVar1;
  }
  return (stack_st_X509_INFO *)bp;
}

