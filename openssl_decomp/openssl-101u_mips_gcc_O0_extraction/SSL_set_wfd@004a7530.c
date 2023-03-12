
int SSL_set_wfd(SSL *s,int fd)

{
  int iVar1;
  undefined4 uVar2;
  BIO *pBVar3;
  BIO *pBVar4;
  BIO *pBVar5;
  BIO *pBVar6;
  
  if (((s->rbio == (BIO *)0x0) ||
      (iVar1 = (*(code *)PTR_BIO_method_type_006a8328)(), iVar1 != 0x505)) ||
     (iVar1 = (*(code *)PTR_BIO_ctrl_006a6e18)(s->rbio,0x69,0,0), iVar1 != fd)) {
    uVar2 = (*(code *)PTR_BIO_s_socket_006a8324)();
    pBVar3 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar2);
    if (pBVar3 == (BIO *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xc4,7,"ssl_lib.c",0x2c0);
      return 0;
    }
    (*(code *)PTR_BIO_int_ctrl_006a785c)(pBVar3,0x68,0,fd);
    pBVar4 = s->bbio;
    pBVar6 = s->rbio;
    pBVar5 = s->wbio;
    if ((pBVar4 != (BIO *)0x0) && (pBVar4 == pBVar5)) {
      pBVar5 = pBVar5->next_bio;
      s->wbio = pBVar5;
      pBVar4->next_bio = (bio_st *)0x0;
    }
    if (((pBVar5 != (BIO *)0x0) && (pBVar3 != pBVar5)) && (pBVar6 != pBVar5)) {
      (*(code *)PTR_BIO_free_all_006a6e74)();
    }
    s->rbio = pBVar6;
    s->wbio = pBVar3;
  }
  else {
    pBVar3 = s->bbio;
    pBVar5 = s->rbio;
    pBVar4 = s->wbio;
    if ((pBVar3 != (BIO *)0x0) && (pBVar3 == pBVar4)) {
      pBVar4 = pBVar4->next_bio;
      s->wbio = pBVar4;
      pBVar3->next_bio = (bio_st *)0x0;
    }
    if ((pBVar4 != (BIO *)0x0) && (pBVar5 != pBVar4)) {
      (*(code *)PTR_BIO_free_all_006a6e74)();
    }
    s->rbio = pBVar5;
    s->wbio = pBVar5;
  }
  return 1;
}

