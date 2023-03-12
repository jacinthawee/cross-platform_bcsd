
int SSL_set_fd(SSL *s,int fd)

{
  BIO *pBVar1;
  BIO_METHOD *type;
  BIO *bp;
  
  type = BIO_s_socket();
  bp = BIO_new(type);
  if (bp != (BIO *)0x0) {
    BIO_int_ctrl(bp,0x68,0,fd);
    pBVar1 = s->bbio;
    if ((pBVar1 != (BIO *)0x0) && (pBVar1 == s->wbio)) {
      s->wbio = pBVar1->next_bio;
      pBVar1->next_bio = (bio_st *)0x0;
    }
    pBVar1 = s->rbio;
    if ((pBVar1 != (BIO *)0x0) && (bp != pBVar1)) {
      BIO_free_all(pBVar1);
    }
    pBVar1 = s->wbio;
    if (((bp != pBVar1) && (pBVar1 != (BIO *)0x0)) && (pBVar1 != s->rbio)) {
      BIO_free_all(pBVar1);
    }
    s->rbio = bp;
    s->wbio = bp;
    return 1;
  }
  ERR_put_error(0x14,0xc0,7,"ssl_lib.c",0x2a1);
  return 0;
}

