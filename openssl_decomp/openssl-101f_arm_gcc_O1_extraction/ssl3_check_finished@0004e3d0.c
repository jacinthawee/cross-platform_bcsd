
undefined4 ssl3_check_finished(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_14;
  
  if (*(int *)(*(int *)(param_1 + 0xc0) + 0xe4) == 0) {
    return 1;
  }
  uVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                    (param_1,0x1130,0x1131,0xffffffff,*(undefined4 *)(param_1 + 0x108),&local_14);
  if (local_14 != 0) {
    iVar2 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar2 + 0x354) = 1;
    if ((*(uint *)(iVar2 + 0x340) & 0xffffffef) == 4) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
  }
  return uVar1;
}

