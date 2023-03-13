
undefined4 __regparm3 dtls1_query_mtu(SSL *param_1)

{
  int iVar1;
  dtls1_state_st *pdVar2;
  BIO *pBVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  dtls1_state_st *pdVar7;
  
  pdVar7 = param_1->d1;
  iVar1 = *(int *)&pdVar7->w_msg_hdr;
  if (iVar1 != 0) {
    pBVar3 = SSL_get_wbio(param_1);
    lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
    (pdVar7->w_msg_hdr).msg_len = iVar1 - lVar4;
    pdVar7 = param_1->d1;
    *(undefined4 *)&pdVar7->w_msg_hdr = 0;
  }
  uVar5 = (pdVar7->w_msg_hdr).msg_len;
  pBVar3 = SSL_get_wbio(param_1);
  lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
  if (uVar5 < 0x100U - lVar4) {
    uVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar5 & 0x1000) != 0) {
      return 0;
    }
    pdVar7 = param_1->d1;
    pBVar3 = SSL_get_wbio(param_1);
    uVar6 = BIO_ctrl(pBVar3,0x28,0,(void *)0x0);
    (pdVar7->w_msg_hdr).msg_len = uVar6;
    uVar5 = (param_1->d1->w_msg_hdr).msg_len;
    pBVar3 = SSL_get_wbio(param_1);
    lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
    if (uVar5 < 0x100U - lVar4) {
      pdVar7 = param_1->d1;
      pBVar3 = SSL_get_wbio(param_1);
      lVar4 = BIO_ctrl(pBVar3,0x31,0,(void *)0x0);
      pdVar2 = param_1->d1;
      (pdVar7->w_msg_hdr).msg_len = 0x100 - lVar4;
      uVar6 = (pdVar2->w_msg_hdr).msg_len;
      pBVar3 = SSL_get_wbio(param_1);
      BIO_ctrl(pBVar3,0x2a,uVar6,(void *)0x0);
    }
  }
  return 1;
}

