
BIO * BIO_new_dgram(int fd,int close_flag)

{
  BIO *bp;
  
  bp = BIO_new((BIO_METHOD *)&methods_dgramp);
  if (bp != (BIO *)0x0) {
    BIO_int_ctrl(bp,0x68,close_flag,fd);
  }
  return bp;
}

