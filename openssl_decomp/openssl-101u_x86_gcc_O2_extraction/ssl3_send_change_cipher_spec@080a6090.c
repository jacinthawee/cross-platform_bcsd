
undefined4 ssl3_send_change_cipher_spec(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0xd] == param_2) {
    uVar2 = 1;
    **(undefined **)(param_1[0xf] + 4) = 1;
    param_1[0x11] = 1;
    param_1[0x12] = 0;
    param_1[0xd] = param_3;
    iVar1 = 0;
  }
  else {
    uVar2 = param_1[0x11];
    iVar1 = param_1[0x12];
  }
  iVar1 = ssl3_write_bytes(param_1,0x14,iVar1 + *(int *)(param_1[0xf] + 4),uVar2);
  if (iVar1 < 0) {
    uVar2 = 0xffffffff;
  }
  else if (iVar1 == param_1[0x11]) {
    uVar2 = 1;
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])
                (1,*param_1,0x14,*(undefined4 *)(param_1[0xf] + 4),iVar1 + param_1[0x12],param_1,
                 param_1[0x1a]);
      return 1;
    }
  }
  else {
    param_1[0x12] = param_1[0x12] + iVar1;
    param_1[0x11] = param_1[0x11] - iVar1;
    uVar2 = 0;
  }
  return uVar2;
}

