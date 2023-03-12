
undefined4 dtls1_query_mtu(SSL *param_1)

{
  BIO *pBVar1;
  int iVar2;
  ulong uVar3;
  dtls1_state_st *pdVar4;
  uint uVar5;
  dtls1_state_st *pdVar6;
  int iVar7;
  
  pdVar4 = param_1->d1;
  iVar7 = *(int *)&pdVar4->w_msg_hdr;
  if (iVar7 != 0) {
    pBVar1 = SSL_get_wbio(param_1);
    iVar2 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar1,0x31,0,0);
    (pdVar4->w_msg_hdr).msg_len = iVar7 - iVar2;
    pdVar4 = param_1->d1;
    *(undefined4 *)&pdVar4->w_msg_hdr = 0;
  }
  uVar5 = (pdVar4->w_msg_hdr).msg_len;
  pBVar1 = SSL_get_wbio(param_1);
  iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar1,0x31,0,0);
  if (uVar5 < 0x100U - iVar7) {
    uVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar5 & 0x1000) != 0) {
      return 0;
    }
    pdVar6 = param_1->d1;
    pBVar1 = SSL_get_wbio(param_1);
    uVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar1,0x28,0,0);
    pdVar4 = param_1->d1;
    (pdVar6->w_msg_hdr).msg_len = uVar3;
    uVar5 = (pdVar4->w_msg_hdr).msg_len;
    pBVar1 = SSL_get_wbio(param_1);
    iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar1,0x31,0,0);
    if (uVar5 < 0x100U - iVar7) {
      pdVar4 = param_1->d1;
      pBVar1 = SSL_get_wbio(param_1);
      iVar7 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar1,0x31,0,0);
      (pdVar4->w_msg_hdr).msg_len = 0x100 - iVar7;
      pBVar1 = SSL_get_wbio(param_1);
      (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar1,0x2a,(param_1->d1->w_msg_hdr).msg_len,0);
    }
  }
  return 1;
}

