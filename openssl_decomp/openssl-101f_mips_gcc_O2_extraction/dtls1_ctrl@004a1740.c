
int dtls1_ctrl(SSL *param_1,uint param_2,undefined4 param_3,uint *param_4)

{
  undefined *puVar1;
  int iVar2;
  dtls1_state_st *pdVar3;
  BIO *pBVar4;
  uint uVar5;
  uint uVar6;
  SSL *ssl;
  int local_1c;
  int local_18;
  SSL *local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(SSL **)PTR___stack_chk_guard_006aabf0;
  if (param_2 == 0x4a) {
    iVar2 = dtls1_handle_timeout();
  }
  else if (param_2 == 0x4b) {
    param_2 = 0x20;
    SSL_ctrl(param_1,0x20,0x2000,(void *)0x0);
    param_1->d1->mtu = 1;
    iVar2 = SSL_accept(param_1);
    if (0 < iVar2) {
      pBVar4 = SSL_get_rbio(param_1);
      param_2 = 0x2e;
      (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar4,0x2e,0,param_4);
      iVar2 = 1;
    }
  }
  else if (param_2 == 0x49) {
    if (((param_1->d1->next_timeout).tv_usec != 0) ||
       (iVar2 = 0, *(int *)&param_1->d1->timeout_duration != 0)) {
      (*(code *)PTR_gettimeofday_006aabd4)(&local_1c,0);
      pdVar3 = param_1->d1;
      iVar2 = (pdVar3->next_timeout).tv_usec;
      param_2 = (uint)(iVar2 < local_1c);
      if ((param_2 == 0) && ((iVar2 != local_1c || (local_18 < *(int *)&pdVar3->timeout_duration))))
      {
        param_2 = (pdVar3->next_timeout).tv_usec;
        uVar5 = *(uint *)&pdVar3->timeout_duration;
        *param_4 = param_2;
        param_4[1] = uVar5;
        uVar6 = *param_4 - local_1c;
        uVar5 = param_4[1] - local_18;
        *param_4 = uVar6;
        param_4[1] = uVar5;
        if ((int)uVar5 < 0) {
          uVar6 = uVar6 - 1;
          uVar5 = uVar5 + 1000000;
          *param_4 = uVar6;
          param_4[1] = uVar5;
        }
        if ((uVar6 != 0) || (14999 < (int)uVar5)) {
          iVar2 = 1;
          goto LAB_004a179c;
        }
      }
      *(undefined *)param_4 = 0;
      iVar2 = 1;
      *(undefined *)((int)param_4 + 1) = 0;
      *(undefined *)((int)param_4 + 2) = 0;
      *(undefined *)((int)param_4 + 3) = 0;
      *(undefined *)(param_4 + 1) = 0;
      *(undefined *)((int)param_4 + 5) = 0;
      *(undefined *)((int)param_4 + 6) = 0;
      *(undefined *)((int)param_4 + 7) = 0;
    }
  }
  else {
    iVar2 = ssl3_ctrl();
  }
LAB_004a179c:
  if (local_14 == *(SSL **)puVar1) {
    return iVar2;
  }
  ssl = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  SSL_ctrl(ssl,0x20,0x2000,(void *)0x0);
  ssl->d1->mtu = 1;
  iVar2 = SSL_accept(ssl);
  if (0 < iVar2) {
    pBVar4 = SSL_get_rbio(ssl);
    (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar4,0x2e,0,param_2);
    iVar2 = 1;
  }
  return iVar2;
}

