
int * dtls1_get_timeout(int param_1,int *param_2)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  BIO *pBVar5;
  int iVar7;
  SSL *s;
  dtls1_state_st *pdVar8;
  int iStack_54;
  int iStack_50;
  SSL *pSStack_4c;
  int *piStack_44;
  undefined *puStack_40;
  code *pcStack_3c;
  undefined *local_28;
  int local_1c;
  int local_18;
  int local_14;
  undefined2 uVar6;
  
  puStack_40 = PTR___stack_chk_guard_006a9ae8;
  local_28 = &_gp;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((*(int *)(*(int *)(param_1 + 0x5c) + 0x2c4) != 0) ||
     (piVar3 = (int *)0x0, *(int *)(*(int *)(param_1 + 0x5c) + 0x2c8) != 0)) {
    (*(code *)PTR_gettimeofday_006a9acc)(&local_1c,0);
    iVar2 = *(int *)(param_1 + 0x5c);
    piVar3 = param_2;
    if ((local_1c <= *(int *)(iVar2 + 0x2c4)) &&
       ((*(int *)(iVar2 + 0x2c4) != local_1c || (local_18 < *(int *)(iVar2 + 0x2c8))))) {
      iVar7 = *(int *)(iVar2 + 0x2c8);
      *param_2 = *(int *)(iVar2 + 0x2c4);
      param_2[1] = iVar7;
      local_1c = *param_2 - local_1c;
      local_18 = param_2[1] - local_18;
      *param_2 = local_1c;
      param_2[1] = local_18;
      if (local_18 < 0) {
        local_1c = local_1c + -1;
        local_18 = local_18 + 1000000;
        *param_2 = local_1c;
        param_2[1] = local_18;
      }
      if ((local_1c != 0) || (14999 < local_18)) goto LAB_0049d814;
    }
    *(undefined *)param_2 = 0;
    *(undefined *)((int)param_2 + 1) = 0;
    *(undefined *)((int)param_2 + 2) = 0;
    *(undefined *)((int)param_2 + 3) = 0;
    *(undefined *)(param_2 + 1) = 0;
    *(undefined *)((int)param_2 + 5) = 0;
    *(undefined *)((int)param_2 + 6) = 0;
    *(undefined *)((int)param_2 + 7) = 0;
  }
LAB_0049d814:
  if (local_14 == *(int *)puStack_40) {
    return piVar3;
  }
  pcStack_3c = dtls1_is_timer_expired;
  iVar2 = local_14;
  (**(code **)(local_28 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pSStack_4c = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  piStack_44 = param_2;
  if ((*(int *)(*(int *)(iVar2 + 0x5c) + 0x2c4) == 0) &&
     (piVar3 = (int *)0x0, *(int *)(*(int *)(iVar2 + 0x5c) + 0x2c8) == 0)) goto LAB_0049d97c;
  (*(code *)PTR_gettimeofday_006a9acc)(&iStack_54,0);
  iVar2 = *(int *)(iVar2 + 0x5c);
  if ((*(int *)(iVar2 + 0x2c4) < iStack_54) ||
     ((*(int *)(iVar2 + 0x2c4) == iStack_54 && (*(int *)(iVar2 + 0x2c8) <= iStack_50)))) {
LAB_0049d968:
    piVar3 = (int *)0x1;
    goto LAB_0049d97c;
  }
  iStack_54 = *(int *)(iVar2 + 0x2c4) - iStack_54;
  iStack_50 = *(int *)(iVar2 + 0x2c8) - iStack_50;
  if (iStack_50 < 0) {
    iStack_54 = iStack_54 + -1;
    iStack_50 = iStack_50 + 1000000;
    if (iStack_54 == 0) goto LAB_0049d944;
LAB_0049d974:
    piVar3 = (int *)0x0;
    if (0 < iStack_54) goto LAB_0049d97c;
  }
  else {
    if (iStack_54 != 0) goto LAB_0049d974;
LAB_0049d944:
    if (iStack_50 < 15000) goto LAB_0049d968;
  }
  piVar3 = (int *)(uint)(iStack_50 < 1);
LAB_0049d97c:
  if (pSStack_4c != *(SSL **)puVar1) {
    s = pSStack_4c;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    pdVar8 = s->d1;
    uVar4 = (*(ushort *)pdVar8->handshake_fragment & 0x7fff) << 1;
    uVar6 = (undefined2)uVar4;
    if (0x3c < uVar4) {
      uVar6 = 0x3c;
    }
    *(undefined2 *)pdVar8->handshake_fragment = uVar6;
    if ((*(int *)&pdVar8->timeout_duration == 0) && (pdVar8->alert_fragment_len == 0)) {
      *(undefined2 *)pdVar8->handshake_fragment = 1;
    }
    (*(code *)PTR_gettimeofday_006a9acc)(&pdVar8->timeout_duration,0);
    pdVar8 = s->d1;
    *(uint *)&pdVar8->timeout_duration =
         *(int *)&pdVar8->timeout_duration + (uint)*(ushort *)pdVar8->handshake_fragment;
    pBVar5 = SSL_get_rbio(s);
                    /* WARNING: Could not recover jumptable at 0x0049da78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    piVar3 = (int *)(*(code *)PTR_BIO_ctrl_006a6e18)(pBVar5,0x2d,0,&s->d1->timeout_duration);
    return piVar3;
  }
  return piVar3;
}

