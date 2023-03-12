
int SSL_set_fd(SSL *s,int fd)

{
  BIO_METHOD *type;
  BIO *bp;
  bio_st *extraout_r1;
  bio_st *pbVar1;
  BIO *pBVar2;
  BIO *pBVar3;
  bool bVar4;
  
  type = BIO_s_socket();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xc0,7,"ssl_lib.c",0x2a1);
    return 0;
  }
  BIO_int_ctrl(bp,0x68,0,fd);
  pBVar3 = s->bbio;
  if (pBVar3 != (BIO *)0x0) {
    pBVar2 = s->wbio;
    bVar4 = pBVar3 == pBVar2;
    pbVar1 = extraout_r1;
    if (bVar4) {
      pBVar2 = pBVar3->next_bio;
      pbVar1 = (bio_st *)0x0;
    }
    if (bVar4) {
      s->wbio = pBVar2;
    }
    if (bVar4) {
      pBVar3->next_bio = pbVar1;
    }
  }
  pBVar3 = s->rbio;
  if ((pBVar3 != (BIO *)0x0) && (bp != pBVar3)) {
    BIO_free_all(pBVar3);
  }
  pBVar3 = s->wbio;
  if (((pBVar3 != (BIO *)0x0) && (bp != pBVar3)) && (pBVar3 != s->rbio)) {
    BIO_free_all(pBVar3);
  }
  s->rbio = bp;
  s->wbio = bp;
  return 1;
}

