
uint dtls1_shutdown(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x2c);
  if ((uVar3 != 0) || (*(int *)(param_1 + 0x34) == 0x4000)) {
    *(undefined4 *)(param_1 + 0x30) = 3;
    return 1;
  }
  uVar2 = *(uint *)(param_1 + 0x30);
  if ((int)(uVar2 << 0x1f) < 0) {
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x18c) == 0) {
      if (-1 < (int)(uVar2 << 0x1e)) {
        (**(code **)(*(int *)(param_1 + 8) + 0x34))(param_1,0,0,0,0);
        uVar2 = *(uint *)(param_1 + 0x30);
        if (-1 < (int)(uVar2 << 0x1e)) {
          return 0xffffffff;
        }
      }
      goto LAB_0004f54e;
    }
    iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x3c))();
    if (iVar1 == -1) {
      return 0xffffffff;
    }
  }
  else {
    *(uint *)(param_1 + 0x30) = uVar2 | 1;
    ssl3_send_alert(param_1,1,0);
    if (*(int *)(*(int *)(param_1 + 0x58) + 0x18c) != 0) {
      return 0xffffffff;
    }
  }
  uVar2 = *(uint *)(param_1 + 0x30);
LAB_0004f54e:
  if (uVar2 == 3) {
    uVar3 = count_leading_zeroes(*(undefined4 *)(*(int *)(param_1 + 0x58) + 0x18c));
    uVar3 = uVar3 >> 5;
  }
  return uVar3;
}

