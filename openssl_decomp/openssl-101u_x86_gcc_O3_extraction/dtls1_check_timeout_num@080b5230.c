
undefined4 dtls1_check_timeout_num(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  undefined4 uVar2;
  uint uVar3;
  BIO *bp;
  
  uVar3 = (param_1->d1->next_timeout).tv_usec + 1;
  (param_1->d1->next_timeout).tv_usec = uVar3;
  uVar2 = 0;
  if (2 < uVar3) {
    uVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar3 & 0x1000) == 0) {
      bp = SSL_get_wbio(param_1);
      uVar3 = BIO_ctrl(bp,0x2f,0,(void *)0x0);
      pdVar1 = param_1->d1;
      if (uVar3 < (pdVar1->w_msg_hdr).msg_len) {
        (pdVar1->w_msg_hdr).msg_len = uVar3;
      }
      uVar3 = (pdVar1->next_timeout).tv_usec;
    }
    else {
      uVar3 = (param_1->d1->next_timeout).tv_usec;
    }
    uVar2 = 0;
    if (0xc < uVar3) {
      ERR_put_error(0x14,0x13c,0x138,"d1_lib.c",0x1cb);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

