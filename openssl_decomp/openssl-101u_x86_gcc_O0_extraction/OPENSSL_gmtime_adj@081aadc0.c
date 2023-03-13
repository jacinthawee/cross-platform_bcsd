
undefined4 OPENSSL_gmtime_adj(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int local_20;
  
  param_2 = param_3 / 0x15180 + param_2;
  local_20 = param_1[1] * 0x3c + param_1[2] * 0xe10 + *param_1 + param_3 % 0x15180;
  if (local_20 < 0x15180) {
    if (local_20 < 0) {
      param_2 = param_2 + -1;
      local_20 = local_20 + 0x15180;
    }
  }
  else {
    local_20 = local_20 + -0x15180;
    param_2 = param_2 + 1;
  }
  iVar6 = param_1[4] + -0xd >> 0x1f;
  iVar2 = (param_1[4] + -0xd) / 0xc + iVar6;
  iVar4 = iVar2 - iVar6;
  iVar6 = (param_1[4] + -1 + (iVar6 - iVar2) * 0xc) * 0x16f;
  iVar7 = iVar6 >> 0x1f;
  iVar2 = (param_1[5] + 0x1a2c + iVar4) * 0x5b5;
  if (iVar2 < 0) {
    iVar2 = iVar2 + 3;
  }
  iVar4 = ((param_1[5] + 0x1a90 + iVar4) / 100) * 3;
  iVar3 = iVar4 + 3;
  if (-1 < iVar4) {
    iVar3 = iVar4;
  }
  iVar2 = param_2 + -0x7d4b +
          (((iVar2 >> 2) + ((iVar6 / 6 + iVar7 >> 1) - iVar7)) - (iVar3 >> 2)) + param_1[3];
  uVar5 = 0;
  if (-1 < iVar2) {
    iVar2 = iVar2 + 0x10bd9;
    iVar4 = (iVar2 * 4) / 0x23ab1;
    iVar7 = iVar4 * 0x23ab1;
    iVar6 = iVar7 + 3;
    if (iVar6 < 0) {
      iVar6 = iVar7 + 6;
    }
    iVar2 = iVar2 - (iVar6 >> 2);
    iVar6 = ((iVar2 + 1) * 4000) / 0x164b09;
    iVar3 = iVar6 * 0x5b5;
    iVar7 = iVar3 + 3;
    if (-1 < iVar3) {
      iVar7 = iVar3;
    }
    iVar2 = (iVar2 - (iVar7 >> 2)) + 0x1f;
    iVar7 = iVar2 * 0x50;
    iVar3 = iVar7 / 0x6925;
    uVar1 = iVar3 + -0x76c + iVar6 + (iVar4 + -0x31) * 100;
    if (uVar1 < 0x1fa4) {
      param_1[5] = uVar1;
      iVar7 = iVar7 / 0x98f;
      param_1[4] = iVar7 + 1 + iVar3 * -0xc;
      param_1[3] = iVar2 - (iVar7 * 0x98f) / 0x50;
      param_1[2] = local_20 / 0xe10;
      uVar5 = 1;
      param_1[1] = (local_20 / 0x3c) % 0x3c;
      *param_1 = local_20 % 0x3c;
    }
  }
  return uVar5;
}

