
undefined4 ssl_check_clienthello_tlsext_early(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  int in_GS_OFFSET;
  undefined4 local_14;
  int local_10;
  
  local_14 = 0x70;
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar1 = *(int *)(param_1 + 0xe4);
  if (((iVar1 != 0) && (pcVar3 = *(code **)(iVar1 + 0x100), pcVar3 != (code *)0x0)) ||
     ((iVar1 = *(int *)(param_1 + 0x170), iVar1 != 0 &&
      (pcVar3 = *(code **)(iVar1 + 0x100), pcVar3 != (code *)0x0)))) {
    iVar1 = (*pcVar3)(param_1,&local_14,*(undefined4 *)(iVar1 + 0x104));
    if (iVar1 == 2) {
      ssl3_send_alert(param_1,2,local_14);
      uVar2 = 0xffffffff;
      goto LAB_080ac4c8;
    }
    if (iVar1 != 3) {
      if (iVar1 == 1) {
        ssl3_send_alert(param_1,1,local_14);
        uVar2 = 1;
      }
      else {
        uVar2 = 1;
      }
      goto LAB_080ac4c8;
    }
  }
  *(undefined4 *)(param_1 + 0x124) = 0;
  uVar2 = 1;
LAB_080ac4c8:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

