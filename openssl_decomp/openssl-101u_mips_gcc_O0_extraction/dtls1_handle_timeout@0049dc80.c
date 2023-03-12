
undefined * dtls1_handle_timeout(SSL *param_1,int param_2,undefined *param_3,char *param_4)

{
  ushort uVar1;
  undefined *puVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  BIO *pBVar6;
  dtls1_state_st *pdVar8;
  uint uVar9;
  SSL *s;
  ushort *local_1c;
  int local_18;
  SSL *local_14;
  undefined2 uVar7;
  
  puVar4 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  if ((*(int *)&param_1->d1->timeout_duration != 0) ||
     (puVar2 = (undefined *)0x0, param_1->d1->alert_fragment_len != 0)) {
    (*(code *)PTR_gettimeofday_006a9acc)(&local_1c,0);
    pdVar8 = param_1->d1;
    param_3 = *(undefined **)&pdVar8->timeout_duration;
    if (((int)param_3 < (int)local_1c) ||
       (((ushort *)param_3 == local_1c && ((int)pdVar8->alert_fragment_len <= local_18)))) {
LAB_0049dd68:
      uVar1 = *(ushort *)pdVar8->handshake_fragment;
    }
    else {
      param_2 = *(int *)&pdVar8->timeout_duration - (int)local_1c;
      local_18 = pdVar8->alert_fragment_len - local_18;
      if (local_18 < 0) {
        param_2 = param_2 + -1;
        local_1c = (ushort *)0xf4240;
        local_18 = local_18 + 1000000;
        if (param_2 != 0) goto LAB_0049deb8;
LAB_0049dd24:
        param_4 = (char *)local_1c;
        if (14999 < local_18) {
LAB_0049dd30:
          puVar2 = (undefined *)0x0;
          goto LAB_0049dd34;
        }
        goto LAB_0049dd68;
      }
      if (param_2 == 0) goto LAB_0049dd24;
LAB_0049deb8:
      param_4 = (char *)local_1c;
      if ((0 < param_2) || (0 < local_18)) goto LAB_0049dd30;
      uVar1 = *(ushort *)pdVar8->handshake_fragment;
    }
    uVar3 = (uVar1 & 0x7fff) << 1;
    uVar7 = (undefined2)uVar3;
    if (0x3c < uVar3) {
      uVar7 = 0x3c;
    }
    *(undefined2 *)pdVar8->handshake_fragment = uVar7;
    if ((param_3 == (undefined *)0x0) && (pdVar8->alert_fragment_len == 0)) {
      *(undefined2 *)pdVar8->handshake_fragment = 1;
    }
    (*(code *)PTR_gettimeofday_006a9acc)(&pdVar8->timeout_duration,0);
    pdVar8 = param_1->d1;
    *(uint *)&pdVar8->timeout_duration =
         *(int *)&pdVar8->timeout_duration + (uint)*(ushort *)pdVar8->handshake_fragment;
    pBVar6 = SSL_get_rbio(param_1);
    param_3 = (undefined *)0x0;
    param_2 = 0x2d;
    param_4 = (char *)&param_1->d1->timeout_duration;
    (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar6,0x2d,0,param_4);
    pdVar8 = param_1->d1;
    uVar3 = (pdVar8->next_timeout).tv_usec + 1;
    (pdVar8->next_timeout).tv_usec = uVar3;
    if (2 < uVar3) {
      param_4 = (char *)0x0;
      param_3 = (undefined *)0x0;
      param_2 = 0x20;
      uVar3 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
      if ((uVar3 & 0x1000) == 0) {
        pBVar6 = SSL_get_wbio(param_1);
        param_4 = (char *)0x0;
        param_3 = (undefined *)0x0;
        param_2 = 0x2f;
        uVar3 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar6,0x2f,0,0);
        pdVar8 = param_1->d1;
        if (uVar3 < (pdVar8->w_msg_hdr).msg_len) {
          uVar9 = (pdVar8->next_timeout).tv_usec;
          (pdVar8->w_msg_hdr).msg_len = uVar3;
        }
        else {
          uVar9 = (pdVar8->next_timeout).tv_usec;
        }
      }
      else {
        pdVar8 = param_1->d1;
        uVar9 = (pdVar8->next_timeout).tv_usec;
      }
      if (0xc < uVar9) {
        param_3 = (undefined *)0x138;
        param_4 = "d1_lib.c";
        param_2 = 0x13c;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x13c,0x138,"d1_lib.c",0x1cb);
        puVar2 = (undefined *)0xffffffff;
        goto LAB_0049dd34;
      }
    }
    uVar3 = (pdVar8->timeout).num_alerts + 1;
    if (2 < uVar3) {
      uVar3 = 1;
    }
    (pdVar8->timeout).num_alerts = uVar3;
    puVar2 = PTR_gettimeofday_006a9acc;
    if (param_1->tlsext_heartbeat == 0) {
      if ((*(int *)&pdVar8->timeout_duration == 0) && (pdVar8->alert_fragment_len == 0)) {
        *(undefined2 *)pdVar8->handshake_fragment = 1;
      }
      (*(code *)puVar2)(&pdVar8->timeout_duration,0);
      pdVar8 = param_1->d1;
      *(uint *)&pdVar8->timeout_duration =
           *(int *)&pdVar8->timeout_duration + (uint)*(ushort *)pdVar8->handshake_fragment;
      pBVar6 = SSL_get_rbio(param_1);
      param_3 = (undefined *)0x0;
      param_2 = 0x2d;
      param_4 = (char *)&param_1->d1->timeout_duration;
      (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar6,0x2d,0,param_4);
      puVar2 = (undefined *)dtls1_retransmit_buffered_messages(param_1);
    }
    else {
      param_1->tlsext_heartbeat = 0;
      puVar2 = (undefined *)dtls1_heartbeat(param_1);
    }
  }
LAB_0049dd34:
  if (local_14 == *(SSL **)puVar4) {
    return puVar2;
  }
  s = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (param_2 == 0x4b) {
    SSL_clear(s);
    SSL_ctrl(s,0x20,0x2000,(void *)0x0);
    s->d1->mtu = 1;
    param_3 = (undefined *)SSL_accept(s);
    if (0 < (int)param_3) {
      pBVar6 = SSL_get_rbio(s);
      (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar6,0x2e,0,param_4);
      param_3 = (undefined *)0x1;
    }
  }
  else if (param_2 < 0x4c) {
    if (param_2 == 0x49) {
      iVar5 = dtls1_get_timeout();
      return (undefined *)(uint)(iVar5 != 0);
    }
    if (0x49 < param_2) {
      puVar4 = (undefined *)dtls1_handle_timeout();
      return puVar4;
    }
    if (param_2 != 0x11) goto LAB_0049e01c;
    iVar5 = dtls1_link_min_mtu();
    if ((int)param_3 < iVar5 + -0x30) {
      return (undefined *)0x0;
    }
    (s->d1->w_msg_hdr).msg_len = (ulong)param_3;
  }
  else {
    if (param_2 != 0x78) {
      if (param_2 == 0x79) {
        puVar4 = (undefined *)dtls1_link_min_mtu();
        return puVar4;
      }
      if (param_2 == 0x77) {
        return (undefined *)(uint)(s->version == 0xfeff);
      }
LAB_0049e01c:
      puVar4 = (undefined *)ssl3_ctrl(s);
      return puVar4;
    }
    iVar5 = dtls1_link_min_mtu();
    if ((int)param_3 < iVar5) {
      return (undefined *)0x0;
    }
    *(undefined **)&s->d1->w_msg_hdr = param_3;
    param_3 = (undefined *)0x1;
  }
  return param_3;
}

