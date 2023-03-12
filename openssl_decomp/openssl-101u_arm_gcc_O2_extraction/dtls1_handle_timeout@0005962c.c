
undefined4 dtls1_handle_timeout(SSL *param_1)

{
  BIO *pBVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  uint uVar5;
  dtls1_state_st *pdVar6;
  int iVar7;
  timeval local_20;
  uint uVar4;
  
  if ((*(int *)&param_1->d1->timeout_duration == 0) && (param_1->d1->alert_fragment_len == 0)) {
    return 0;
  }
  gettimeofday(&local_20,(__timezone_ptr_t)0x0);
  pdVar6 = param_1->d1;
  iVar7 = *(int *)&pdVar6->timeout_duration;
  if ((local_20.tv_sec <= iVar7) &&
     ((iVar7 != local_20.tv_sec || (local_20.tv_usec < (int)pdVar6->alert_fragment_len)))) {
    local_20.tv_sec = *(int *)&pdVar6->timeout_duration - local_20.tv_sec;
    local_20.tv_usec = pdVar6->alert_fragment_len - local_20.tv_usec;
    if (local_20.tv_usec < 0) {
      local_20.tv_sec = local_20.tv_sec + -1;
      local_20.tv_usec = local_20.tv_usec + 1000000;
    }
    if (local_20.tv_sec == 0) {
      if (14999 < local_20.tv_usec) {
        return 0;
      }
    }
    else if ((0 < local_20.tv_sec) || (0 < local_20.tv_usec)) {
      return 0;
    }
  }
  uVar4 = (*(ushort *)pdVar6->handshake_fragment & 0x7fff) * 2;
  uVar3 = (undefined2)uVar4;
  if (0x3c < uVar4) {
    uVar3 = 0x3c;
  }
  *(undefined2 *)pdVar6->handshake_fragment = uVar3;
  if ((iVar7 == 0) && (pdVar6->alert_fragment_len == 0)) {
    *(undefined2 *)pdVar6->handshake_fragment = 1;
  }
  gettimeofday((timeval *)&pdVar6->timeout_duration,(__timezone_ptr_t)0x0);
  pdVar6 = param_1->d1;
  *(uint *)&pdVar6->timeout_duration =
       *(int *)&pdVar6->timeout_duration + (uint)*(ushort *)pdVar6->handshake_fragment;
  pBVar1 = SSL_get_rbio(param_1);
  BIO_ctrl(pBVar1,0x2d,0,&param_1->d1->timeout_duration);
  pdVar6 = param_1->d1;
  uVar4 = (pdVar6->next_timeout).tv_usec + 1;
  (pdVar6->next_timeout).tv_usec = uVar4;
  if (2 < uVar4) {
    uVar4 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar4 & 0x1000) == 0) {
      pBVar1 = SSL_get_wbio(param_1);
      uVar4 = BIO_ctrl(pBVar1,0x2f,0,(void *)0x0);
      pdVar6 = param_1->d1;
      uVar5 = (pdVar6->next_timeout).tv_usec;
      if (uVar4 < (pdVar6->w_msg_hdr).msg_len) {
        (pdVar6->w_msg_hdr).msg_len = uVar4;
      }
    }
    else {
      pdVar6 = param_1->d1;
      uVar5 = (pdVar6->next_timeout).tv_usec;
    }
    if (0xc < uVar5) {
      ERR_put_error(0x14,0x13c,0x138,"d1_lib.c",0x1cb);
      return 0xffffffff;
    }
  }
  uVar4 = (pdVar6->timeout).num_alerts + 1;
  if (2 < uVar4) {
    uVar4 = 1;
  }
  (pdVar6->timeout).num_alerts = uVar4;
  if (param_1->tlsext_heartbeat == 0) {
    if ((*(int *)&pdVar6->timeout_duration == 0) && (pdVar6->alert_fragment_len == 0)) {
      *(undefined2 *)pdVar6->handshake_fragment = 1;
    }
    gettimeofday((timeval *)&pdVar6->timeout_duration,(__timezone_ptr_t)0x0);
    pdVar6 = param_1->d1;
    *(uint *)&pdVar6->timeout_duration =
         *(int *)&pdVar6->timeout_duration + (uint)*(ushort *)pdVar6->handshake_fragment;
    pBVar1 = SSL_get_rbio(param_1);
    BIO_ctrl(pBVar1,0x2d,0,&param_1->d1->timeout_duration);
    uVar2 = dtls1_retransmit_buffered_messages(param_1);
    return uVar2;
  }
  param_1->tlsext_heartbeat = 0;
  uVar2 = dtls1_heartbeat(param_1);
  return uVar2;
}

