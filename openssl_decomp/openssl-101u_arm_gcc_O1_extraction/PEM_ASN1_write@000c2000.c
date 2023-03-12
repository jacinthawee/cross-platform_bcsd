
int PEM_ASN1_write(undefined1 *i2d,char *name,FILE *fp,void *x,EVP_CIPHER *enc,uchar *kstr,int klen,
                  undefined1 *callback,void *u)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp != (BIO *)0x0) {
    BIO_ctrl(bp,0x6a,0,fp);
    iVar1 = PEM_ASN1_write_bio(i2d,name,bp,x,enc,kstr,klen,callback,u);
    BIO_free(bp);
    return iVar1;
  }
  ERR_put_error(9,0x68,7,"pem_lib.c",0x143);
  return 0;
}

