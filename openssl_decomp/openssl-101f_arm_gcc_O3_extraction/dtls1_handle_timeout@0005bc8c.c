
undefined4 dtls1_handle_timeout(SSL *param_1)

{
  BIO *pBVar1;
  undefined4 uVar2;
  long lVar3;
  undefined2 uVar4;
  dtls1_state_st *pdVar6;
  int iVar7;
  timeval local_20;
  uint uVar5;
  
  if (((param_1->d1->next_timeout).tv_usec == 0) && (*(int *)&param_1->d1->timeout_duration == 0)) {
    return 0;
  }
  gettimeofday(&local_20,(__timezone_ptr_t)0x0);
  pdVar6 = param_1->d1;
  iVar7 = (pdVar6->next_timeout).tv_usec;
  if ((local_20.tv_sec <= iVar7) &&
     ((iVar7 != local_20.tv_sec || (local_20.tv_usec < *(int *)&pdVar6->timeout_duration)))) {
    local_20.tv_sec = (pdVar6->next_timeout).tv_usec - local_20.tv_sec;
    local_20.tv_usec = *(int *)&pdVar6->timeout_duration - local_20.tv_usec;
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
  uVar5 = (*(ushort *)&pdVar6->alert_fragment_len & 0x7fff) * 2;
  uVar4 = (undefined2)uVar5;
  if (0x3c < uVar5) {
    uVar4 = 0x3c;
  }
  *(undefined2 *)&pdVar6->alert_fragment_len = uVar4;
  if ((iVar7 == 0) && (*(int *)&pdVar6->timeout_duration == 0)) {
    *(undefined2 *)&pdVar6->alert_fragment_len = 1;
  }
  gettimeofday((timeval *)&(pdVar6->next_timeout).tv_usec,(__timezone_ptr_t)0x0);
  pdVar6 = param_1->d1;
  (pdVar6->next_timeout).tv_usec =
       (pdVar6->next_timeout).tv_usec + (uint)*(ushort *)&pdVar6->alert_fragment_len;
  pBVar1 = SSL_get_rbio(param_1);
  BIO_ctrl(pBVar1,0x2d,0,&(param_1->d1->next_timeout).tv_usec);
  pdVar6 = param_1->d1;
  uVar5 = (pdVar6->next_timeout).tv_sec + 1;
  (pdVar6->next_timeout).tv_sec = uVar5;
  if (2 < uVar5) {
    pBVar1 = SSL_get_wbio(param_1);
    lVar3 = BIO_ctrl(pBVar1,0x2f,0,(void *)0x0);
    *(long *)&pdVar6->w_msg_hdr = lVar3;
    pdVar6 = param_1->d1;
    if (0xc < (uint)(pdVar6->next_timeout).tv_sec) {
      ERR_put_error(0x14,0x13c,0x138,"d1_lib.c",0x1a0);
      return 0xffffffff;
    }
  }
  uVar5 = (pdVar6->timeout).write_timeouts + 1;
  if (2 < uVar5) {
    uVar5 = 1;
  }
  (pdVar6->timeout).write_timeouts = uVar5;
  if (param_1->tlsext_heartbeat == 0) {
    if (((pdVar6->next_timeout).tv_usec == 0) && (*(int *)&pdVar6->timeout_duration == 0)) {
      *(undefined2 *)&pdVar6->alert_fragment_len = 1;
    }
    gettimeofday((timeval *)&(pdVar6->next_timeout).tv_usec,(__timezone_ptr_t)0x0);
    pdVar6 = param_1->d1;
    (pdVar6->next_timeout).tv_usec =
         (pdVar6->next_timeout).tv_usec + (uint)*(ushort *)&pdVar6->alert_fragment_len;
    pBVar1 = SSL_get_rbio(param_1);
    BIO_ctrl(pBVar1,0x2d,0,&(param_1->d1->next_timeout).tv_usec);
    uVar2 = dtls1_retransmit_buffered_messages(param_1);
    return uVar2;
  }
  param_1->tlsext_heartbeat = 0;
  uVar2 = dtls1_heartbeat(param_1);
  return uVar2;
}

