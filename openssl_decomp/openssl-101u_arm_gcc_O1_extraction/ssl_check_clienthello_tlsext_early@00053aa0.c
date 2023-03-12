
undefined4 ssl_check_clienthello_tlsext_early(int param_1)

{
  int iVar1;
  undefined4 local_14 [2];
  
  iVar1 = *(int *)(param_1 + 0xe4);
  local_14[0] = 0x70;
  if ((iVar1 == 0) || (*(code **)(iVar1 + 0x100) == (code *)0x0)) {
    iVar1 = *(int *)(param_1 + 0x170);
    if ((iVar1 == 0) || (*(code **)(iVar1 + 0x100) == (code *)0x0)) goto LAB_00053b12;
    iVar1 = (**(code **)(iVar1 + 0x100))(param_1,local_14,*(undefined4 *)(iVar1 + 0x104));
  }
  else {
    iVar1 = (**(code **)(iVar1 + 0x100))(param_1,local_14,*(undefined4 *)(iVar1 + 0x104));
  }
  if (iVar1 == 2) {
    ssl3_send_alert(param_1,2,local_14[0]);
    return 0xffffffff;
  }
  if (iVar1 != 3) {
    if (iVar1 != 1) {
      return 1;
    }
    ssl3_send_alert(param_1,1,local_14[0]);
    return 1;
  }
LAB_00053b12:
  *(undefined4 *)(param_1 + 0x124) = 0;
  return 1;
}

