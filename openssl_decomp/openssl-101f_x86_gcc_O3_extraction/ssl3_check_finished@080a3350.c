
undefined4 ssl3_check_finished(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_GS_OFFSET;
  int local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(*(int *)(param_1 + 0xc0) + 0xe4) != 0) {
    uVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                      (param_1,0x1130,0x1131,0xffffffff,*(undefined4 *)(param_1 + 0x108),&local_14);
    if (local_14 == 0) goto LAB_080a33c0;
    iVar1 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar1 + 0x354) = 1;
    uVar2 = 2;
    if ((*(uint *)(iVar1 + 0x340) & 0xffffffef) == 4) goto LAB_080a33c0;
  }
  uVar2 = 1;
LAB_080a33c0:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

