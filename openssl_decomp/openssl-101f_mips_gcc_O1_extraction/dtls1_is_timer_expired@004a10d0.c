
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(SSL **)PTR___stack_chk_guard_006aabf0;
  if ((*(int *)(*(int *)(param_1 + 0x5c) + 0x2c0) == 0) &&
     (uVar2 = 0, *(int *)(*(int *)(param_1 + 0x5c) + 0x2c4) == 0)) goto LAB_004a11ac;
  (*(code *)PTR_gettimeofday_006aabd4)(&local_1c,0);
  iVar3 = *(int *)(param_1 + 0x5c);
  if ((*(int *)(iVar3 + 0x2c0) < local_1c) ||
     ((*(int *)(iVar3 + 0x2c0) == local_1c && (*(int *)(iVar3 + 0x2c4) <= local_18)))) {
LAB_004a1198:
    uVar2 = 1;
    goto LAB_004a11ac;
  }
  local_1c = *(int *)(iVar3 + 0x2c0) - local_1c;
  local_18 = *(int *)(iVar3 + 0x2c4) - local_18;
  if (local_18 < 0) {
    local_1c = local_1c + -1;
    local_18 = local_18 + 1000000;
    if (local_1c == 0) goto LAB_004a1174;
LAB_004a11a4:
    uVar2 = 0;
    if (0 < local_1c) goto LAB_004a11ac;
  }
  else {
    if (local_1c != 0) goto LAB_004a11a4;
LAB_004a1174:
    if (local_18 < 15000) goto LAB_004a1198;
  }
  uVar2 = (uint)(local_18 < 1);
LAB_004a11ac:
  if (local_14 != *(SSL **)puVar1) {
    s = local_14;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    pdVar6 = s->d1;
    uVar2 = (*(ushort *)&pdVar6->alert_fragment_len & 0x7fff) << 1;
    uVar5 = (undefined2)uVar2;
    if (0x3c < uVar2) {
      uVar5 = 0x3c;
    }
    *(undefined2 *)&pdVar6->alert_fragment_len = uVar5;
    if (((pdVar6->next_timeout).tv_usec == 0) && (*(int *)&pdVar6->timeout_duration == 0)) {
      *(undefined2 *)&pdVar6->alert_fragment_len = 1;
    }
    (*(code *)PTR_gettimeofday_006aabd4)(&(pdVar6->next_timeout).tv_usec,0);
    pdVar6 = s->d1;
    (pdVar6->next_timeout).tv_usec =
         (pdVar6->next_timeout).tv_usec + (uint)*(ushort *)&pdVar6->alert_fragment_len;
    pBVar4 = SSL_get_rbio(s);
                    /* WARNING: Could not recover jumptable at 0x004a12a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar4,0x2d,0,&(s->d1->next_timeout).tv_usec);
    return uVar2;
  }
  return uVar2;
}

