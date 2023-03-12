
undefined4 OPENSSL_gmtime_adj(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  param_2 = param_3 / 0x15180 + param_2;
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
  iVar6 = param_1[4] + -0xd;
  iVar7 = iVar6 >> 0x1f;
  iVar4 = iVar6 / 0xc + iVar7;
  iVar6 = iVar4 - iVar7;
  iVar5 = (param_1[5] + 0x1a2c + iVar6) * 0x5b5;
  iVar6 = ((param_1[5] + 0x1a90 + iVar6) / 100) * 3;
  if (iVar5 < 0) {
    iVar5 = iVar5 + 3;
  }
  if (iVar6 < 0) {
    iVar6 = iVar6 + 3;
  }
  param_2 = (((((iVar7 - iVar4) * 0xc + param_1[4] + -1) * 0x16f) / 0xc + (iVar5 >> 2)) -
            (iVar6 >> 2)) + param_1[3] + -0x7d4b + param_2;
  if (-1 < param_2) {
    param_2 = param_2 + 0x10bd9;
    iVar6 = (param_2 * 4) / 0x23ab1;
    iVar4 = iVar6 * 0x23ab1;
    iVar5 = iVar4 + 3;
    if (iVar5 < 0) {
      iVar5 = iVar4 + 6;
    }
    param_2 = param_2 - (iVar5 >> 2);
    iVar5 = ((param_2 + 1) * 4000) / 0x164b09;
    iVar4 = iVar5 * 0x5b5;
    if (iVar4 < 0) {
      iVar4 = iVar4 + 3;
    }
    iVar2 = (param_2 - (iVar4 >> 2)) + 0x1f;
    iVar4 = iVar2 * 0x50;
    iVar7 = iVar4 / 0x6925;
    uVar1 = ((iVar6 + -0x31) * 100 + iVar5 + iVar7) - 0x76c;
    if (uVar1 < 0x1fa4) {
      param_1[5] = uVar1;
      iVar4 = iVar4 / 0x98f;
      param_1[4] = iVar4 + iVar7 * -0xc + 1;
      param_1[1] = (iVar3 / 0x3c) % 0x3c;
      param_1[3] = iVar2 - (iVar4 * 0x98f) / 0x50;
      param_1[2] = iVar3 / 0xe10;
      *param_1 = iVar3 % 0x3c;
      return 1;
    }
  }
  return 0;
}

