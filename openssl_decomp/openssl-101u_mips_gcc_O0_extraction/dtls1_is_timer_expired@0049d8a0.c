
uint dtls1_is_timer_expired(int param_1)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar5;
  BIO *pBVar4;
  SSL *s;
  dtls1_state_st *pdVar6;
  int local_1c;
  int local_18;
  SSL *local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  if ((*(int *)(*(int *)(param_1 + 0x5c) + 0x2c4) == 0) &&
     (uVar2 = 0, *(int *)(*(int *)(param_1 + 0x5c) + 0x2c8) == 0)) goto LAB_0049d97c;
  (*(code *)PTR_gettimeofday_006a9acc)(&local_1c,0);
  iVar3 = *(int *)(param_1 + 0x5c);
  if ((*(int *)(iVar3 + 0x2c4) < local_1c) ||
     ((*(int *)(iVar3 + 0x2c4) == local_1c && (*(int *)(iVar3 + 0x2c8) <= local_18)))) {
LAB_0049d968:
    uVar2 = 1;
    goto LAB_0049d97c;
  }
  local_1c = *(int *)(iVar3 + 0x2c4) - local_1c;
  local_18 = *(int *)(iVar3 + 0x2c8) - local_18;
  if (local_18 < 0) {
    local_1c = local_1c + -1;
    local_18 = local_18 + 1000000;
    if (local_1c == 0) goto LAB_0049d944;
LAB_0049d974:
    uVar2 = 0;
    if (0 < local_1c) goto LAB_0049d97c;
  }
  else {
    if (local_1c != 0) goto LAB_0049d974;
LAB_0049d944:
    if (local_18 < 15000) goto LAB_0049d968;
  }
  uVar2 = (uint)(local_18 < 1);
LAB_0049d97c:
  if (local_14 != *(SSL **)puVar1) {
    s = local_14;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    pdVar6 = s->d1;
    uVar2 = (*(ushort *)pdVar6->handshake_fragment & 0x7fff) << 1;
    uVar5 = (undefined2)uVar2;
    if (0x3c < uVar2) {
      uVar5 = 0x3c;
    }
    *(undefined2 *)pdVar6->handshake_fragment = uVar5;
    if ((*(int *)&pdVar6->timeout_duration == 0) && (pdVar6->alert_fragment_len == 0)) {
      *(undefined2 *)pdVar6->handshake_fragment = 1;
    }
    (*(code *)PTR_gettimeofday_006a9acc)(&pdVar6->timeout_duration,0);
    pdVar6 = s->d1;
    *(uint *)&pdVar6->timeout_duration =
         *(int *)&pdVar6->timeout_duration + (uint)*(ushort *)pdVar6->handshake_fragment;
    pBVar4 = SSL_get_rbio(s);
                    /* WARNING: Could not recover jumptable at 0x0049da78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar4,0x2d,0,&s->d1->timeout_duration);
    return uVar2;
  }
  return uVar2;
}

