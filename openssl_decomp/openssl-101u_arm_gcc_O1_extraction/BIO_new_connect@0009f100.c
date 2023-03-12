
BIO * BIO_new_connect(char *host_port)

{
  BIO *bp;
  long lVar1;
  
  bp = BIO_new((BIO_METHOD *)&methods_connectp);
  if (bp == (BIO *)0x0) {
    return (BIO *)0x0;
  }
  lVar1 = BIO_ctrl(bp,100,0,host_port);
  if (lVar1 != 0) {
    return bp;
  }
  BIO_free(bp);
  return (BIO *)0x0;
}

