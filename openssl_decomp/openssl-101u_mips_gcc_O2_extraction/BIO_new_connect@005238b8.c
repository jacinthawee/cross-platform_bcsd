
BIO * BIO_new_connect(char *host_port)

{
  BIO *bp;
  long lVar1;
  
  bp = BIO_new((BIO_METHOD *)methods_connectp);
  if (bp == (BIO *)0x0) {
    bp = (BIO *)0x0;
  }
  else {
    lVar1 = BIO_ctrl(bp,100,0,host_port);
    if (lVar1 == 0) {
      BIO_free(bp);
      bp = (BIO *)0x0;
    }
  }
  return bp;
}

