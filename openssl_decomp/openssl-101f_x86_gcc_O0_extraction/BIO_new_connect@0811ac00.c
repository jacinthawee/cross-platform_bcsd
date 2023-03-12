
BIO * BIO_new_connect(char *host_port)

{
  BIO *bp;
  long lVar1;
  BIO *pBVar2;
  
  bp = BIO_new((BIO_METHOD *)methods_connectp);
  if (bp == (BIO *)0x0) {
    pBVar2 = (BIO *)0x0;
  }
  else {
    lVar1 = BIO_ctrl(bp,100,0,host_port);
    pBVar2 = bp;
    if (lVar1 == 0) {
      pBVar2 = (BIO *)0x0;
      BIO_free(bp);
    }
  }
  return pBVar2;
}

