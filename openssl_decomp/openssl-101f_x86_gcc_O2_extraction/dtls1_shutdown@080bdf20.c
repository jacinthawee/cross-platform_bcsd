
undefined4 dtls1_shutdown(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x2c) != 0) || (*(int *)(param_1 + 0x34) == 0x4000)) {
    *(undefined4 *)(param_1 + 0x30) = 3;
    return 1;
  }
  uVar1 = *(uint *)(param_1 + 0x30);
  if ((uVar1 & 1) == 0) {
    *(uint *)(param_1 + 0x30) = uVar1 | 1;
    ssl3_send_alert(param_1,1,0);
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x18c) != 0) {
      return 0xffffffff;
    }
    uVar1 = *(uint *)(param_1 + 0x30);
joined_r0x080a4db9:
    if (uVar1 != 3) {
      return 0;
    }
  }
  else {
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x18c) == 0) {
      if ((uVar1 & 2) != 0) goto joined_r0x080a4db9;
      (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0,0,0,0);
      uVar1 = *(uint *)(param_1 + 0x30);
      if ((uVar1 & 2) == 0) {
        return 0xffffffff;
      }
    }
    else {
      iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x3c))(param_1);
      if (iVar2 == -1) {
        return 0xffffffff;
      }
      uVar1 = *(uint *)(param_1 + 0x30);
    }
    if (uVar1 != 3) {
      return 0;
    }
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x18c) != 0) {
      return 0;
    }
  }
  return 1;
}

