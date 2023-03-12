
int dtls1_handle_timeout(SSL *param_1,uint param_2,undefined4 param_3,char *param_4)

{
  ushort uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  BIO *pBVar6;
  dtls1_state_st *pdVar8;
  SSL *pSVar9;
  int *piVar10;
  dtls1_state_st *unaff_s2;
  code *pcVar11;
  int iStack_64;
  int iStack_60;
  SSL *pSStack_5c;
  SSL *pSStack_58;
  undefined *puStack_54;
  dtls1_state_st *pdStack_50;
  code *pcStack_4c;
  undefined4 local_38;
  undefined *local_30;
  uint local_24;
  int local_20;
  __suseconds_t *local_1c;
  int local_18;
  SSL *local_14;
  undefined2 uVar7;
  
  puStack_54 = PTR___stack_chk_guard_006aabf0;
  local_30 = &_gp;
  local_14 = *(SSL **)PTR___stack_chk_guard_006aabf0;
  if (((param_1->d1->next_timeout).tv_usec != 0) ||
     (iVar3 = 0, *(int *)&param_1->d1->timeout_duration != 0)) {
    (*(code *)PTR_gettimeofday_006aabd4)(&local_1c,0);
    pdVar8 = param_1->d1;
    piVar10 = (int *)(pdVar8->next_timeout).tv_usec;
    if (((int)piVar10 < (int)local_1c) ||
       ((piVar10 == local_1c && (*(int *)&pdVar8->timeout_duration <= local_18)))) {
LAB_004a1524:
      uVar1 = *(ushort *)&pdVar8->alert_fragment_len;
LAB_004a1528:
      uVar4 = (uVar1 & 0x7fff) << 1;
      uVar7 = (undefined2)uVar4;
      if (0x3c < uVar4) {
        uVar7 = 0x3c;
      }
      *(undefined2 *)&pdVar8->alert_fragment_len = uVar7;
      if ((piVar10 == (int *)0x0) && (*(int *)&pdVar8->timeout_duration == 0)) {
        *(undefined2 *)&pdVar8->alert_fragment_len = 1;
      }
      (**(code **)(local_30 + -0x530c))(&(pdVar8->next_timeout).tv_usec,0);
      pdVar8 = param_1->d1;
      (pdVar8->next_timeout).tv_usec =
           (pdVar8->next_timeout).tv_usec + (uint)*(ushort *)&pdVar8->alert_fragment_len;
      pBVar6 = SSL_get_rbio(param_1);
      param_2 = 0x2d;
      param_4 = (char *)&(param_1->d1->next_timeout).tv_usec;
      (**(code **)(local_30 + -0x7fc8))(pBVar6,0x2d,0);
      unaff_s2 = param_1->d1;
      uVar4 = (unaff_s2->next_timeout).tv_sec + 1;
      (unaff_s2->next_timeout).tv_sec = uVar4;
      if (2 < uVar4) {
        pBVar6 = SSL_get_wbio(param_1);
        param_4 = (char *)0x0;
        param_2 = 0x2f;
        uVar5 = (**(code **)(local_30 + -0x7fc8))(pBVar6,0x2f,0);
        *(undefined4 *)&unaff_s2->w_msg_hdr = uVar5;
        unaff_s2 = param_1->d1;
        if (0xc < (uint)(unaff_s2->next_timeout).tv_sec) {
          param_4 = "d1_lib.c";
          local_38 = 0x1a0;
          param_2 = 0x13c;
          (**(code **)(local_30 + -0x6eb0))(0x14,0x13c,0x138);
          iVar3 = -1;
          goto LAB_004a14ec;
        }
      }
      uVar4 = (unaff_s2->timeout).write_timeouts + 1;
      if (2 < uVar4) {
        uVar4 = 1;
      }
      (unaff_s2->timeout).write_timeouts = uVar4;
      if (param_1->tlsext_heartbeat == 0) {
        pcVar11 = *(code **)(local_30 + -0x530c);
        if (((unaff_s2->next_timeout).tv_usec == 0) && (*(int *)&unaff_s2->timeout_duration == 0)) {
          *(undefined2 *)&unaff_s2->alert_fragment_len = 1;
        }
        (*pcVar11)(&(unaff_s2->next_timeout).tv_usec,0);
        pdVar8 = param_1->d1;
        (pdVar8->next_timeout).tv_usec =
             (pdVar8->next_timeout).tv_usec + (uint)*(ushort *)&pdVar8->alert_fragment_len;
        pBVar6 = SSL_get_rbio(param_1);
        param_2 = 0x2d;
        param_4 = (char *)&(param_1->d1->next_timeout).tv_usec;
        (**(code **)(local_30 + -0x7fc8))(pBVar6,0x2d,0);
        iVar3 = dtls1_retransmit_buffered_messages(param_1);
      }
      else {
        param_1->tlsext_heartbeat = 0;
        iVar3 = dtls1_heartbeat(param_1);
      }
    }
    else {
      local_24 = (pdVar8->next_timeout).tv_usec - (int)local_1c;
      local_20 = *(int *)&pdVar8->timeout_duration - local_18;
      if (local_20 < 0) {
        local_24 = local_24 - 1;
        local_1c = (__suseconds_t *)0xf4240;
        local_20 = local_20 + 1000000;
        if (local_24 == 0) goto LAB_004a14dc;
LAB_004a1674:
        param_4 = (char *)local_1c;
        if (((int)local_24 < 1) && (local_20 < 1)) {
          uVar1 = *(ushort *)&pdVar8->alert_fragment_len;
          goto LAB_004a1528;
        }
      }
      else {
        if (local_24 != 0) goto LAB_004a1674;
LAB_004a14dc:
        param_4 = (char *)local_1c;
        if (local_20 < 15000) goto LAB_004a1524;
      }
      iVar3 = 0;
      param_2 = local_24;
    }
  }
LAB_004a14ec:
  if (local_14 == *(SSL **)puStack_54) {
    return iVar3;
  }
  pcStack_4c = dtls1_ctrl;
  pSVar9 = local_14;
  (**(code **)(local_30 + -0x5328))();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  pSStack_5c = *(SSL **)PTR___stack_chk_guard_006aabf0;
  pSStack_58 = param_1;
  pdStack_50 = unaff_s2;
  if (param_2 == 0x4a) {
    iVar3 = dtls1_handle_timeout();
  }
  else if (param_2 == 0x4b) {
    param_2 = 0x20;
    SSL_ctrl(pSVar9,0x20,0x2000,(void *)0x0);
    pSVar9->d1->mtu = 1;
    iVar3 = SSL_accept(pSVar9);
    if (0 < iVar3) {
      pBVar6 = SSL_get_rbio(pSVar9);
      param_2 = 0x2e;
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar6,0x2e,0,param_4);
      iVar3 = 1;
    }
  }
  else if (param_2 == 0x49) {
    if (((pSVar9->d1->next_timeout).tv_usec != 0) ||
       (iVar3 = 0, *(int *)&pSVar9->d1->timeout_duration != 0)) {
      (*(code *)PTR_gettimeofday_006aabd4)(&iStack_64,0);
      pdVar8 = pSVar9->d1;
      iVar3 = (pdVar8->next_timeout).tv_usec;
      param_2 = (uint)(iVar3 < iStack_64);
      if ((param_2 == 0) &&
         ((iVar3 != iStack_64 || (iStack_60 < *(int *)&pdVar8->timeout_duration)))) {
        param_2 = (pdVar8->next_timeout).tv_usec;
        iVar3 = *(int *)&pdVar8->timeout_duration;
        *(uint *)param_4 = param_2;
        *(int *)((int)param_4 + 4) = iVar3;
        iStack_64 = *(int *)param_4 - iStack_64;
        iStack_60 = *(int *)((int)param_4 + 4) - iStack_60;
        *(int *)param_4 = iStack_64;
        *(int *)((int)param_4 + 4) = iStack_60;
        if (iStack_60 < 0) {
          iStack_64 = iStack_64 + -1;
          iStack_60 = iStack_60 + 1000000;
          *(int *)param_4 = iStack_64;
          *(int *)((int)param_4 + 4) = iStack_60;
        }
        if ((iStack_64 != 0) || (14999 < iStack_60)) {
          iVar3 = 1;
          goto LAB_004a179c;
        }
      }
      *param_4 = 0;
      iVar3 = 1;
      *(undefined *)((int)param_4 + 1) = 0;
      *(undefined *)((int)param_4 + 2) = 0;
      *(undefined *)((int)param_4 + 3) = 0;
      *(undefined *)((int)param_4 + 4) = 0;
      *(undefined *)((int)param_4 + 5) = 0;
      *(undefined *)((int)param_4 + 6) = 0;
      *(undefined *)((int)param_4 + 7) = 0;
    }
  }
  else {
    iVar3 = ssl3_ctrl();
  }
LAB_004a179c:
  if (pSStack_5c != *(SSL **)puVar2) {
    pSVar9 = pSStack_5c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    SSL_ctrl(pSVar9,0x20,0x2000,(void *)0x0);
    pSVar9->d1->mtu = 1;
    iVar3 = SSL_accept(pSVar9);
    if (0 < iVar3) {
      pBVar6 = SSL_get_rbio(pSVar9);
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar6,0x2e,0,param_2);
      iVar3 = 1;
    }
    return iVar3;
  }
  return iVar3;
}

