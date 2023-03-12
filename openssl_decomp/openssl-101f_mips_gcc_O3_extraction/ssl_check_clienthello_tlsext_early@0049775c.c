
undefined4
ssl_check_clienthello_tlsext_early
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  undefined *puVar6;
  undefined4 local_18;
  int local_14;
  
  puVar6 = PTR___stack_chk_guard_006aabf0;
  iVar1 = *(int *)(param_1 + 0xe4);
  local_18 = 0x70;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((iVar1 == 0) || (*(code **)(iVar1 + 0x100) == (code *)0x0)) {
    iVar1 = *(int *)(param_1 + 0x170);
    if ((iVar1 != 0) && (*(code **)(iVar1 + 0x100) != (code *)0x0)) {
      iVar1 = (**(code **)(iVar1 + 0x100))(param_1,&local_18,*(undefined4 *)(iVar1 + 0x104));
      goto joined_r0x00497840;
    }
  }
  else {
    iVar1 = (**(code **)(iVar1 + 0x100))(param_1,&local_18,*(undefined4 *)(iVar1 + 0x104));
joined_r0x00497840:
    if (iVar1 == 2) {
      ssl3_send_alert(param_1,2,local_18);
      uVar2 = 0xffffffff;
      goto LAB_004977d8;
    }
    if (iVar1 != 3) {
      if (iVar1 == 1) {
        ssl3_send_alert(param_1,1,local_18);
        uVar2 = 1;
      }
      else {
        uVar2 = 1;
      }
      goto LAB_004977d8;
    }
  }
  *(undefined4 *)(param_1 + 0x124) = 0;
  uVar2 = 1;
LAB_004977d8:
  if (local_14 == *(int *)puVar6) {
    return uVar2;
  }
  iVar1 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar6 = &_gp;
  if (((*(int *)(iVar1 + 0x128) != -1) && (*(int *)(iVar1 + 0xe4) != 0)) &&
     (*(int *)(*(int *)(iVar1 + 0xe4) + 0x13c) != 0)) {
    iVar3 = ssl_get_server_send_pkey();
    if (iVar3 == 0) {
      *(undefined4 *)(iVar1 + 300) = 0;
      return 1;
    }
    piVar4 = *(int **)(iVar1 + 0x98);
    pcVar5 = *(code **)(*(int *)(iVar1 + 0xe4) + 0x13c);
    uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0xe4) + 0x140);
    *piVar4 = iVar3;
    iVar3 = (*pcVar5)(iVar1,uVar2,piVar4,param_4,puVar6);
    if (iVar3 == 2) {
      ssl3_send_alert(iVar1,2,0x50);
      return 0xffffffff;
    }
    if (iVar3 != 3) {
      if (iVar3 != 0) {
        return 1;
      }
      if (*(int *)(iVar1 + 0x138) != 0) {
        *(undefined4 *)(iVar1 + 300) = 1;
        return 1;
      }
    }
  }
  *(undefined4 *)(iVar1 + 300) = 0;
  return 1;
}

