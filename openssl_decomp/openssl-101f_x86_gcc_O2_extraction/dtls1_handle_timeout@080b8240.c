
undefined4 dtls1_handle_timeout(SSL *param_1)

{
  __suseconds_t *p_Var1;
  int iVar2;
  undefined4 uVar3;
  BIO *pBVar4;
  uint uVar5;
  long lVar6;
  ushort uVar7;
  dtls1_state_st *pdVar8;
  int in_GS_OFFSET;
  timeval local_28;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (((param_1->d1->next_timeout).tv_usec == 0) && (*(int *)&param_1->d1->timeout_duration == 0))
  goto LAB_080b82cc;
  gettimeofday(&local_28,(__timezone_ptr_t)0x0);
  pdVar8 = param_1->d1;
  iVar2 = (pdVar8->next_timeout).tv_usec;
  if ((iVar2 < local_28.tv_sec) ||
     ((iVar2 == local_28.tv_sec &&
      (*(int *)&pdVar8->timeout_duration == local_28.tv_usec ||
       *(int *)&pdVar8->timeout_duration < local_28.tv_usec)))) {
LAB_080b82f8:
    uVar7 = *(short *)&pdVar8->alert_fragment_len * 2;
    if (0x3c < uVar7) {
      uVar7 = 0x3c;
    }
    *(ushort *)&pdVar8->alert_fragment_len = uVar7;
    if ((iVar2 == 0) && (*(int *)&pdVar8->timeout_duration == 0)) {
      *(undefined2 *)&pdVar8->alert_fragment_len = 1;
    }
    gettimeofday((timeval *)&(pdVar8->next_timeout).tv_usec,(__timezone_ptr_t)0x0);
    pdVar8 = param_1->d1;
    p_Var1 = &(pdVar8->next_timeout).tv_usec;
    *p_Var1 = *p_Var1 + (uint)*(ushort *)&pdVar8->alert_fragment_len;
    pBVar4 = SSL_get_rbio(param_1);
    BIO_ctrl(pBVar4,0x2d,0,&(pdVar8->next_timeout).tv_usec);
    pdVar8 = param_1->d1;
    uVar5 = (pdVar8->next_timeout).tv_sec + 1;
    (pdVar8->next_timeout).tv_sec = uVar5;
    if (2 < uVar5) {
      pBVar4 = SSL_get_wbio(param_1);
      lVar6 = BIO_ctrl(pBVar4,0x2f,0,(void *)0x0);
      *(long *)&pdVar8->w_msg_hdr = lVar6;
      pdVar8 = param_1->d1;
      if (0xc < (uint)(pdVar8->next_timeout).tv_sec) {
        ERR_put_error(0x14,0x13c,0x138,"d1_lib.c",0x1a0);
        uVar3 = 0xffffffff;
        goto LAB_080b82ce;
      }
    }
    uVar5 = (pdVar8->timeout).write_timeouts + 1;
    if (2 < uVar5) {
      uVar5 = 1;
    }
    (pdVar8->timeout).write_timeouts = uVar5;
    if (param_1->tlsext_heartbeat == 0) {
      if (((pdVar8->next_timeout).tv_usec == 0) && (*(int *)&pdVar8->timeout_duration == 0)) {
        *(undefined2 *)&pdVar8->alert_fragment_len = 1;
      }
      gettimeofday((timeval *)&(pdVar8->next_timeout).tv_usec,(__timezone_ptr_t)0x0);
      pdVar8 = param_1->d1;
      p_Var1 = &(pdVar8->next_timeout).tv_usec;
      *p_Var1 = *p_Var1 + (uint)*(ushort *)&pdVar8->alert_fragment_len;
      pBVar4 = SSL_get_rbio(param_1);
      BIO_ctrl(pBVar4,0x2d,0,&(pdVar8->next_timeout).tv_usec);
      uVar3 = dtls1_retransmit_buffered_messages(param_1);
    }
    else {
      param_1->tlsext_heartbeat = 0;
      uVar3 = dtls1_heartbeat(param_1);
    }
  }
  else {
    local_28.tv_sec = (pdVar8->next_timeout).tv_usec - local_28.tv_sec;
    local_28.tv_usec = *(int *)&pdVar8->timeout_duration - local_28.tv_usec;
    if (local_28.tv_usec < 0) {
      local_28.tv_sec = local_28.tv_sec + -1;
      local_28.tv_usec = local_28.tv_usec + 1000000;
    }
    if (local_28.tv_sec == 0) {
      if (local_28.tv_usec < 15000) goto LAB_080b82f8;
    }
    else if ((local_28.tv_sec < 1) && (local_28.tv_usec < 1)) goto LAB_080b82f8;
LAB_080b82cc:
    uVar3 = 0;
  }
LAB_080b82ce:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}

