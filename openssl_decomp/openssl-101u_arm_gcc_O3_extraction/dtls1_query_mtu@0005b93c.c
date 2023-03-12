
undefined4 dtls1_query_mtu(SSL *param_1)

{
  BIO *pBVar1;
  long lVar2;
  ulong uVar3;
  dtls1_state_st *pdVar4;
  uint uVar5;
  int iVar6;
  dtls1_state_st *pdVar7;
  
  pdVar4 = param_1->d1;
  iVar6 = *(int *)&pdVar4->w_msg_hdr;
  if (iVar6 != 0) {
    pBVar1 = SSL_get_wbio(param_1);
    lVar2 = BIO_ctrl(pBVar1,0x31,0,(void *)0x0);
    (pdVar4->w_msg_hdr).msg_len = iVar6 - lVar2;
    pdVar4 = param_1->d1;
    *(undefined4 *)&pdVar4->w_msg_hdr = 0;
  }
  uVar5 = (pdVar4->w_msg_hdr).msg_len;
  pBVar1 = SSL_get_wbio(param_1);
  lVar2 = BIO_ctrl(pBVar1,0x31,0,(void *)0x0);
  if (uVar5 < 0x100U - lVar2) {
    uVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar5 & 0x1000) != 0) {
      return 0;
    }
    pdVar7 = param_1->d1;
    pBVar1 = SSL_get_wbio(param_1);
    uVar3 = BIO_ctrl(pBVar1,0x28,0,(void *)0x0);
    pdVar4 = param_1->d1;
    (pdVar7->w_msg_hdr).msg_len = uVar3;
    uVar5 = (pdVar4->w_msg_hdr).msg_len;
    pBVar1 = SSL_get_wbio(param_1);
    lVar2 = BIO_ctrl(pBVar1,0x31,0,(void *)0x0);
    if (uVar5 < 0x100U - lVar2) {
      pdVar4 = param_1->d1;
      pBVar1 = SSL_get_wbio(param_1);
      lVar2 = BIO_ctrl(pBVar1,0x31,0,(void *)0x0);
      (pdVar4->w_msg_hdr).msg_len = 0x100 - lVar2;
      pBVar1 = SSL_get_wbio(param_1);
      BIO_ctrl(pBVar1,0x2a,(param_1->d1->w_msg_hdr).msg_len,(void *)0x0);
    }
  }
  return 1;
}

