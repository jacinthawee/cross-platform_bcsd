
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
  
  puStack_40 = PTR___stack_chk_guard_006aabf0;
  local_28 = &_gp;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((*(int *)(*(int *)(param_1 + 0x5c) + 0x2c0) != 0) ||
     (piVar3 = (int *)0x0, *(int *)(*(int *)(param_1 + 0x5c) + 0x2c4) != 0)) {
    (*(code *)PTR_gettimeofday_006aabd4)(&local_1c,0);
    iVar2 = *(int *)(param_1 + 0x5c);
    piVar3 = param_2;
    if ((local_1c <= *(int *)(iVar2 + 0x2c0)) &&
       ((*(int *)(iVar2 + 0x2c0) != local_1c || (local_18 < *(int *)(iVar2 + 0x2c4))))) {
      iVar7 = *(int *)(iVar2 + 0x2c4);
      *param_2 = *(int *)(iVar2 + 0x2c0);
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
      if ((local_1c != 0) || (14999 < local_18)) goto LAB_004a1044;
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
LAB_004a1044:
  if (local_14 == *(int *)puStack_40) {
    return piVar3;
  }
  pcStack_3c = dtls1_is_timer_expired;
  iVar2 = local_14;
  (**(code **)(local_28 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pSStack_4c = *(SSL **)PTR___stack_chk_guard_006aabf0;
  piStack_44 = param_2;
  if ((*(int *)(*(int *)(iVar2 + 0x5c) + 0x2c0) == 0) &&
     (piVar3 = (int *)0x0, *(int *)(*(int *)(iVar2 + 0x5c) + 0x2c4) == 0)) goto LAB_004a11ac;
  (*(code *)PTR_gettimeofday_006aabd4)(&iStack_54,0);
  iVar2 = *(int *)(iVar2 + 0x5c);
  if ((*(int *)(iVar2 + 0x2c0) < iStack_54) ||
     ((*(int *)(iVar2 + 0x2c0) == iStack_54 && (*(int *)(iVar2 + 0x2c4) <= iStack_50)))) {
LAB_004a1198:
    piVar3 = (int *)0x1;
    goto LAB_004a11ac;
  }
  iStack_54 = *(int *)(iVar2 + 0x2c0) - iStack_54;
  iStack_50 = *(int *)(iVar2 + 0x2c4) - iStack_50;
  if (iStack_50 < 0) {
    iStack_54 = iStack_54 + -1;
    iStack_50 = iStack_50 + 1000000;
    if (iStack_54 == 0) goto LAB_004a1174;
LAB_004a11a4:
    piVar3 = (int *)0x0;
    if (0 < iStack_54) goto LAB_004a11ac;
  }
  else {
    if (iStack_54 != 0) goto LAB_004a11a4;
LAB_004a1174:
    if (iStack_50 < 15000) goto LAB_004a1198;
  }
  piVar3 = (int *)(uint)(iStack_50 < 1);
LAB_004a11ac:
  if (pSStack_4c != *(SSL **)puVar1) {
    s = pSStack_4c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    pdVar8 = s->d1;
    uVar4 = (*(ushort *)&pdVar8->alert_fragment_len & 0x7fff) << 1;
    uVar6 = (undefined2)uVar4;
    if (0x3c < uVar4) {
      uVar6 = 0x3c;
    }
    *(undefined2 *)&pdVar8->alert_fragment_len = uVar6;
    if (((pdVar8->next_timeout).tv_usec == 0) && (*(int *)&pdVar8->timeout_duration == 0)) {
      *(undefined2 *)&pdVar8->alert_fragment_len = 1;
    }
    (*(code *)PTR_gettimeofday_006aabd4)(&(pdVar8->next_timeout).tv_usec,0);
    pdVar8 = s->d1;
    (pdVar8->next_timeout).tv_usec =
         (pdVar8->next_timeout).tv_usec + (uint)*(ushort *)&pdVar8->alert_fragment_len;
    pBVar5 = SSL_get_rbio(s);
                    /* WARNING: Could not recover jumptable at 0x004a12a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    piVar3 = (int *)(*(code *)PTR_BIO_ctrl_006a7f18)(pBVar5,0x2d,0,&(s->d1->next_timeout).tv_usec);
    return piVar3;
  }
  return piVar3;
}

