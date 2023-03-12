
BIO * BIO_new_accept(char *host_port)

{
  BIO *bp;
  long lVar1;
  BIO *pBVar2;
  
  bp = BIO_new((BIO_METHOD *)methods_acceptp);
  if (bp == (BIO *)0x0) {
    pBVar2 = (BIO *)0x0;
  }
  else {
    lVar1 = BIO_ctrl(bp,0x76,0,host_port);
    pBVar2 = bp;
    if (lVar1 == 0) {
      pBVar2 = (BIO *)0x0;
      BIO_free(bp);
    }
  }
  return pBVar2;
}

