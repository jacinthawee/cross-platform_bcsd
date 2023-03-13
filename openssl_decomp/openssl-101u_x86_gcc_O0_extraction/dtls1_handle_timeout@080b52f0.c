
undefined4 dtls1_handle_timeout(SSL *param_1)

{
  int iVar1;
  undefined4 uVar2;
  BIO *pBVar3;
  uint uVar4;
  ushort uVar5;
  dtls1_state_st *pdVar6;
  int iVar7;
  int in_GS_OFFSET;
  timeval local_28;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(int *)&param_1->d1->timeout_duration == 0) && (param_1->d1->alert_fragment_len == 0))
  goto LAB_080b537c;
  gettimeofday(&local_28,(__timezone_ptr_t)0x0);
  pdVar6 = param_1->d1;
  iVar1 = *(int *)&pdVar6->timeout_duration;
  if ((iVar1 < local_28.tv_sec) ||
     ((iVar1 == local_28.tv_sec &&
      (pdVar6->alert_fragment_len == local_28.tv_usec ||
       (int)pdVar6->alert_fragment_len < local_28.tv_usec)))) {
LAB_080b53a8:
    uVar5 = *(short *)pdVar6->handshake_fragment * 2;
    if (0x3c < uVar5) {
      uVar5 = 0x3c;
    }
    *(ushort *)pdVar6->handshake_fragment = uVar5;
    if ((iVar1 == 0) && (pdVar6->alert_fragment_len == 0)) {
      *(undefined2 *)pdVar6->handshake_fragment = 1;
    }
    gettimeofday((timeval *)&pdVar6->timeout_duration,(__timezone_ptr_t)0x0);
    pdVar6 = param_1->d1;
    *(uint *)&pdVar6->timeout_duration =
         *(int *)&pdVar6->timeout_duration + (uint)*(ushort *)pdVar6->handshake_fragment;
    pBVar3 = SSL_get_rbio(param_1);
    BIO_ctrl(pBVar3,0x2d,0,&pdVar6->timeout_duration);
    pdVar6 = param_1->d1;
    uVar4 = (pdVar6->next_timeout).tv_usec + 1;
    (pdVar6->next_timeout).tv_usec = uVar4;
    if (2 < uVar4) {
      uVar4 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
      if ((uVar4 & 0x1000) == 0) {
        pBVar3 = SSL_get_wbio(param_1);
        uVar4 = BIO_ctrl(pBVar3,0x2f,0,(void *)0x0);
        pdVar6 = param_1->d1;
        if (uVar4 < (pdVar6->w_msg_hdr).msg_len) {
          (pdVar6->w_msg_hdr).msg_len = uVar4;
        }
        uVar4 = (pdVar6->next_timeout).tv_usec;
      }
      else {
        pdVar6 = param_1->d1;
        uVar4 = (pdVar6->next_timeout).tv_usec;
      }
      if (0xc < uVar4) {
        ERR_put_error(0x14,0x13c,0x138,"d1_lib.c",0x1cb);
        uVar2 = 0xffffffff;
        goto LAB_080b537e;
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
      pBVar3 = SSL_get_rbio(param_1);
      BIO_ctrl(pBVar3,0x2d,0,&pdVar6->timeout_duration);
      uVar2 = dtls1_retransmit_buffered_messages(param_1);
    }
    else {
      param_1->tlsext_heartbeat = 0;
      uVar2 = dtls1_heartbeat(param_1);
    }
  }
  else {
    local_28.tv_sec = *(int *)&pdVar6->timeout_duration - local_28.tv_sec;
    iVar7 = pdVar6->alert_fragment_len - local_28.tv_usec;
    if (iVar7 < 0) {
      local_28.tv_sec = local_28.tv_sec + -1;
      iVar7 = iVar7 + 1000000;
    }
    if (local_28.tv_sec == 0) {
      if (iVar7 < 15000) goto LAB_080b53a8;
    }
    else if ((local_28.tv_sec < 1) && (iVar7 < 1)) goto LAB_080b53a8;
LAB_080b537c:
    uVar2 = 0;
  }
LAB_080b537e:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

