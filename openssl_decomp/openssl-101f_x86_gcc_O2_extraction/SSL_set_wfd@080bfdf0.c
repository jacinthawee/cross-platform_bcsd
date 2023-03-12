
int SSL_set_wfd(SSL *s,int fd)

{
  BIO *pBVar1;
  int iVar2;
  BIO_METHOD *type;
  BIO *pBVar3;
  BIO *a;
  long lVar4;
  BIO *pBVar5;
  
  if (((s->rbio != (BIO *)0x0) && (iVar2 = BIO_method_type(s->rbio), iVar2 == 0x505)) &&
     (lVar4 = BIO_ctrl(s->rbio,0x69,0,(void *)0x0), lVar4 == fd)) {
    pBVar3 = s->bbio;
    pBVar1 = s->rbio;
    pBVar5 = s->wbio;
    if ((pBVar3 != (BIO *)0x0) && (pBVar3 == pBVar5)) {
      pBVar5 = pBVar5->next_bio;
      s->wbio = pBVar5;
      pBVar3->next_bio = (bio_st *)0x0;
    }
    if ((pBVar5 != (BIO *)0x0) && (pBVar1 != pBVar5)) {
      BIO_free_all(pBVar5);
    }
    s->rbio = pBVar1;
    s->wbio = pBVar1;
    return 1;
  }
  type = BIO_s_socket();
  pBVar3 = BIO_new(type);
  if (pBVar3 != (BIO *)0x0) {
    BIO_int_ctrl(pBVar3,0x68,0,fd);
    pBVar1 = s->bbio;
    pBVar5 = s->rbio;
    a = s->wbio;
    if ((pBVar1 != (BIO *)0x0) && (pBVar1 == a)) {
      a = a->next_bio;
      s->wbio = a;
      pBVar1->next_bio = (bio_st *)0x0;
    }
    if ((pBVar3 != a && a != (BIO *)0x0) && (pBVar5 != a)) {
      BIO_free_all(a);
    }
    s->rbio = pBVar5;
    s->wbio = pBVar3;
    return 1;
  }
  ERR_put_error(0x14,0xc4,7,"ssl_lib.c",0x2b6);
  return 0;
}

