
undefined4 dtls1_check_timeout_num(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  uint uVar2;
  BIO *bp;
  long lVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  pdVar1 = param_1->d1;
  uVar2 = (pdVar1->next_timeout).tv_sec + 1;
  (pdVar1->next_timeout).tv_sec = uVar2;
  if (2 < uVar2) {
    bp = SSL_get_wbio(param_1);
    lVar3 = BIO_ctrl(bp,0x2f,0,(void *)0x0);
    *(long *)&pdVar1->w_msg_hdr = lVar3;
    if (0xc < (uint)(param_1->d1->next_timeout).tv_sec) {
      uVar4 = 0xffffffff;
      ERR_put_error(0x14,0x13c,0x138,"d1_lib.c",0x1a0);
    }
  }
  return uVar4;
}

