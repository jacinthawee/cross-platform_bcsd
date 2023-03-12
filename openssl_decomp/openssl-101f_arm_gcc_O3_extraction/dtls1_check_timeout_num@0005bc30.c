
undefined4 dtls1_check_timeout_num(SSL *param_1)

{
  BIO *bp;
  long lVar1;
  uint uVar2;
  dtls1_state_st *pdVar3;
  
  pdVar3 = param_1->d1;
  uVar2 = (pdVar3->next_timeout).tv_sec + 1;
  (pdVar3->next_timeout).tv_sec = uVar2;
  if (2 < uVar2) {
    bp = SSL_get_wbio(param_1);
    lVar1 = BIO_ctrl(bp,0x2f,0,(void *)0x0);
    uVar2 = (param_1->d1->next_timeout).tv_sec;
    *(long *)&pdVar3->w_msg_hdr = lVar1;
    if (0xc < uVar2) {
      ERR_put_error(0x14,0x13c,0x138,"d1_lib.c",0x1a0);
      return 0xffffffff;
    }
  }
  return 0;
}

