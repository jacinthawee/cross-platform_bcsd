
int SSL_SESSION_print_fp(FILE *fp,SSL_SESSION *ses)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp != (BIO *)0x0) {
    BIO_ctrl(bp,0x6a,0,fp);
    iVar1 = SSL_SESSION_print(bp,ses);
    BIO_free(bp);
    return iVar1;
  }
  ERR_put_error(0x14,0xbe,7,"ssl_txt.c",0x61);
  return 0;
}

