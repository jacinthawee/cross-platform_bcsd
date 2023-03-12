
uint dtls1_ctrl(SSL *param_1,int param_2,ulong param_3,void *param_4)

{
  uint uVar1;
  int iVar2;
  BIO *bp;
  
  if (param_2 == 0x4b) {
    SSL_clear(param_1);
    SSL_ctrl(param_1,0x20,0x2000,(void *)0x0);
    param_1->d1->mtu = 1;
    uVar1 = SSL_accept(param_1);
    if ((int)uVar1 < 1) {
      return uVar1;
    }
    bp = SSL_get_rbio(param_1);
    BIO_ctrl(bp,0x2e,0,param_4);
    return 1;
  }
  if (param_2 < 0x4c) {
    if (param_2 == 0x49) {
      uVar1 = dtls1_get_timeout(param_1,param_4);
      if (uVar1 != 0) {
        uVar1 = 1;
      }
      return uVar1;
    }
    if (0x49 < param_2) {
      uVar1 = dtls1_handle_timeout();
      return uVar1;
    }
    if (param_2 == 0x11) {
      iVar2 = dtls1_link_min_mtu();
      if ((int)param_3 < iVar2 + -0x30) {
        return 0;
      }
      (param_1->d1->w_msg_hdr).msg_len = param_3;
      return param_3;
    }
  }
  else {
    if (param_2 == 0x78) {
      iVar2 = dtls1_link_min_mtu();
      if ((int)param_3 < iVar2) {
        return 0;
      }
      *(ulong *)&param_1->d1->w_msg_hdr = param_3;
      return 1;
    }
    if (param_2 == 0x79) {
      uVar1 = dtls1_link_min_mtu();
      return uVar1;
    }
    if (param_2 == 0x77) {
      uVar1 = count_leading_zeroes(param_1->version + -0xfeff);
      return uVar1 >> 5;
    }
  }
  uVar1 = ssl3_ctrl(param_1,param_2,param_3,param_4);
  return uVar1;
}

