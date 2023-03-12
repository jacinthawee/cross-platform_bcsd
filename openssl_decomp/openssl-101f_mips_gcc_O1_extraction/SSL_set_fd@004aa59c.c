
int SSL_set_fd(SSL *s,int fd)

{
  undefined4 uVar1;
  BIO *pBVar2;
  BIO *pBVar3;
  
  uVar1 = (*(code *)PTR_BIO_s_socket_006a9440)();
  pBVar2 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar1);
  if (pBVar2 != (BIO *)0x0) {
    (*(code *)PTR_BIO_int_ctrl_006a8948)(pBVar2,0x68,0,fd);
    pBVar3 = s->bbio;
    if ((pBVar3 != (BIO *)0x0) && (pBVar3 == s->wbio)) {
      s->wbio = pBVar3->next_bio;
      pBVar3->next_bio = (bio_st *)0x0;
    }
    if ((s->rbio != (BIO *)0x0) && (pBVar2 != s->rbio)) {
      (*(code *)PTR_BIO_free_all_006a7f74)();
    }
    pBVar3 = s->wbio;
    if (((pBVar3 != (BIO *)0x0) && (pBVar2 != pBVar3)) && (pBVar3 != s->rbio)) {
      (*(code *)PTR_BIO_free_all_006a7f74)();
    }
    s->rbio = pBVar2;
    s->wbio = pBVar2;
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xc0,7,"ssl_lib.c",0x2a1);
  return 0;
}

