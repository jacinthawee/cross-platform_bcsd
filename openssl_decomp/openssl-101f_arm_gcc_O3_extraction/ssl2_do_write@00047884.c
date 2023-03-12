
undefined4 ssl2_do_write(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  
  iVar1 = ssl2_write(param_1,*(int *)(param_1[0xf] + 4) + param_1[0x12]);
  iVar3 = param_1[0x11];
  if (iVar3 == iVar1) {
    uVar2 = 1;
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])
                (1,*param_1,0,*(undefined4 *)(param_1[0xf] + 4),iVar3 + param_1[0x12],param_1,
                 param_1[0x1a]);
      return 1;
    }
  }
  else {
    bVar4 = -1 < iVar1;
    if (bVar4) {
      iVar3 = iVar3 - iVar1;
    }
    if (bVar4) {
      param_1[0x11] = iVar3;
      uVar2 = 0;
      iVar1 = iVar1 + param_1[0x12];
    }
    else {
      uVar2 = 0xffffffff;
    }
    if (bVar4) {
      param_1[0x12] = iVar1;
    }
  }
  return uVar2;
}

