
undefined4 dtls1_check_timeout_num(SSL *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  BIO *pBVar3;
  uint uVar4;
  dtls1_state_st *pdVar5;
  
  uVar1 = (param_1->d1->next_timeout).tv_usec + 1;
  (param_1->d1->next_timeout).tv_usec = uVar1;
  if (uVar1 < 3) {
    return 0;
  }
  uVar1 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
  if ((uVar1 & 0x1000) == 0) {
    pBVar3 = SSL_get_wbio(param_1);
    uVar1 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar3,0x2f,0,0);
    pdVar5 = param_1->d1;
    if (uVar1 < (pdVar5->w_msg_hdr).msg_len) {
      uVar4 = (pdVar5->next_timeout).tv_usec;
      (pdVar5->w_msg_hdr).msg_len = uVar1;
    }
    else {
      uVar4 = (pdVar5->next_timeout).tv_usec;
    }
  }
  else {
    uVar4 = (param_1->d1->next_timeout).tv_usec;
  }
  uVar2 = 0;
  if (0xc < uVar4) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13c,0x138,"d1_lib.c",0x1cb);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

