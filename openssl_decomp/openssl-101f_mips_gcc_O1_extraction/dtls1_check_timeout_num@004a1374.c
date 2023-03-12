
undefined4 dtls1_check_timeout_num(SSL *param_1)

{
  uint uVar1;
  BIO *pBVar2;
  undefined4 uVar3;
  dtls1_state_st *pdVar4;
  dtls1_state_st *pdVar5;
  
  pdVar5 = param_1->d1;
  uVar1 = (pdVar5->next_timeout).tv_sec + 1;
  (pdVar5->next_timeout).tv_sec = uVar1;
  if (uVar1 < 3) {
    uVar3 = 0;
  }
  else {
    pBVar2 = SSL_get_wbio(param_1);
    uVar3 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar2,0x2f,0,0);
    pdVar4 = param_1->d1;
    *(undefined4 *)&pdVar5->w_msg_hdr = uVar3;
    uVar3 = 0;
    if (0xc < (uint)(pdVar4->next_timeout).tv_sec) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x13c,0x138,"d1_lib.c",0x1a0);
      uVar3 = 0xffffffff;
    }
  }
  return uVar3;
}

