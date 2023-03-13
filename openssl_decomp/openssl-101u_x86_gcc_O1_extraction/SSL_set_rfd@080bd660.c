
int SSL_set_rfd(SSL *s,int fd)

{
  BIO *pBVar1;
  int iVar2;
  BIO_METHOD *type;
  BIO *pBVar3;
  BIO *pBVar4;
  long lVar5;
  
  if (((s->wbio != (BIO *)0x0) && (iVar2 = BIO_method_type(s->wbio), iVar2 == 0x505)) &&
     (lVar5 = BIO_ctrl(s->wbio,0x69,0,(void *)0x0), lVar5 == fd)) {
    pBVar3 = s->bbio;
    pBVar4 = s->wbio;
    if ((pBVar3 == (BIO *)0x0) || (pBVar4 != pBVar3)) {
      pBVar3 = s->rbio;
      if ((pBVar3 == (BIO *)0x0) || (pBVar4 == pBVar3)) goto LAB_080bd7ac;
LAB_080bd784:
      BIO_free_all(pBVar3);
    }
    else {
      s->wbio = pBVar4->next_bio;
      pBVar3->next_bio = (bio_st *)0x0;
      pBVar3 = s->rbio;
      if ((pBVar3 != (BIO *)0x0) && (pBVar4 != pBVar3)) goto LAB_080bd784;
    }
    pBVar3 = s->wbio;
    if (((pBVar4 != pBVar3) && (pBVar3 != (BIO *)0x0)) && (pBVar3 != s->rbio)) {
      BIO_free_all(pBVar3);
    }
LAB_080bd7ac:
    s->rbio = pBVar4;
    s->wbio = pBVar4;
    return 1;
  }
  type = BIO_s_socket();
  pBVar3 = BIO_new(type);
  if (pBVar3 == (BIO *)0x0) {
    ERR_put_error(0x14,0xc2,7,"ssl_lib.c",0x2d6);
    return 0;
  }
  BIO_int_ctrl(pBVar3,0x68,0,fd);
  pBVar4 = s->bbio;
  pBVar1 = s->wbio;
  if ((pBVar4 == (BIO *)0x0) || (pBVar1 != pBVar4)) {
    pBVar4 = s->rbio;
    if ((pBVar4 == (BIO *)0x0) || (pBVar3 == pBVar4)) goto LAB_080bd6f2;
LAB_080bd6ca:
    BIO_free_all(pBVar4);
  }
  else {
    s->wbio = pBVar1->next_bio;
    pBVar4->next_bio = (bio_st *)0x0;
    pBVar4 = s->rbio;
    if ((pBVar3 != pBVar4) && (pBVar4 != (BIO *)0x0)) goto LAB_080bd6ca;
  }
  pBVar4 = s->wbio;
  if (((pBVar4 != (BIO *)0x0) && (pBVar1 != pBVar4)) && (pBVar4 != s->rbio)) {
    BIO_free_all(pBVar4);
  }
LAB_080bd6f2:
  s->rbio = pBVar3;
  s->wbio = pBVar1;
  return 1;
}

