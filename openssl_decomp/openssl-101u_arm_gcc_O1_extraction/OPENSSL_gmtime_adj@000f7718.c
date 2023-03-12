
undefined4 OPENSSL_gmtime_adj(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  param_2 = param_2 + param_3 / 0x15180;
  iVar3 = param_1[2] * 0xe10 + param_1[1] * 0x3c + *param_1 + param_3 % 0x15180;
  if (iVar3 < 0x15180) {
    if (iVar3 < 0) {
      param_2 = param_2 + -1;
      iVar3 = iVar3 + 0x15180;
    }
  }
  else {
    param_2 = param_2 + 1;
    iVar3 = iVar3 + -0x15180;
  }
  iVar7 = param_1[4] + -0xd;
  iVar1 = iVar7 >> 0x1f;
  iVar7 = iVar7 / 0xc + iVar1;
  iVar5 = iVar7 - iVar1;
  uVar6 = (iVar5 + param_1[5] + 0x1a2c) * 0x5b5;
  uVar4 = uVar6 & ~((int)uVar6 >> 0x20);
  if ((int)uVar6 < 0) {
    uVar4 = uVar6 + 3;
  }
  uVar6 = ((param_1[5] + 0x1a90 + iVar5) / 100) * 3;
  uVar2 = uVar6 & ~((int)uVar6 >> 0x20);
  if ((int)uVar6 < 0) {
    uVar2 = uVar6 + 3;
  }
  param_2 = param_2 + param_1[3] +
                      ((((param_1[4] + -1 + (iVar1 - iVar7) * 0xc) * 0x16f) / 0xc +
                       ((int)uVar4 >> 2)) - ((int)uVar2 >> 2)) + -0x7d4b;
  if (-1 < param_2) {
    param_2 = param_2 + 0x10bd9;
    iVar1 = (param_2 * 4) / 0x23ab1;
    iVar5 = iVar1 * 0x23ab1;
    iVar7 = iVar5 + 3;
    if (iVar7 < 0) {
      iVar7 = iVar5 + 6;
    }
    param_2 = param_2 - (iVar7 >> 2);
    iVar7 = (param_2 * 4000 + 4000) / 0x164b09;
    uVar6 = iVar7 * 0x5b5;
    uVar4 = uVar6 & ~((int)uVar6 >> 0x20);
    if ((int)uVar6 < 0) {
      uVar4 = uVar6 + 3;
    }
    iVar8 = (param_2 - ((int)uVar4 >> 2)) + 0x1f;
    iVar5 = (iVar8 * 0x50) / 0x98f;
    uVar4 = ((iVar1 + -0x31) * 100 + iVar7 + iVar5 / 0xb) - 0x76c;
    if (uVar4 < 0x1fa4) {
      *param_1 = iVar3 % 0x3c;
      param_1[5] = uVar4;
      param_1[4] = iVar5 + (iVar5 / 0xb) * -0xc + 1;
      param_1[1] = (iVar3 / 0x3c) % 0x3c;
      param_1[2] = iVar3 / 0xe10;
      param_1[3] = iVar8 - (iVar5 * 0x98f) / 0x50;
      return 1;
    }
  }
  return 0;
}

