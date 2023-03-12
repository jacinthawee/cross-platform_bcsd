
void * PEM_ASN1_read(undefined1 *d2i,char *name,FILE *fp,void **x,undefined1 *cb,void *u)

{
  BIO_METHOD *type;
  BIO *bp;
  BIO *pBVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x66,7,"pem_lib.c",0xac);
  }
  else {
    BIO_ctrl(bp,0x6a,0,fp);
    pBVar1 = (BIO *)PEM_ASN1_read_bio(d2i,name,bp,x,cb,u);
    BIO_free(bp);
    bp = pBVar1;
  }
  return bp;
}

