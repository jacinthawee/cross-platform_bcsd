
BIO * BIO_new_accept(char *host_port)

{
  BIO *bp;
  long lVar1;
  
  bp = BIO_new((BIO_METHOD *)methods_acceptp);
  if (bp == (BIO *)0x0) {
    bp = (BIO *)0x0;
  }
  else {
    lVar1 = BIO_ctrl(bp,0x76,0,host_port);
    if (lVar1 == 0) {
      BIO_free(bp);
      bp = (BIO *)0x0;
    }
  }
  return bp;
}

