
uint __aeabi_idiv(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  if (param_2 == 0) {
    bVar6 = (int)param_1 < 0;
    if (0 < (int)param_1) {
      param_1 = 0x7fffffff;
    }
    if (bVar6) {
      param_1 = 0x80000000;
    }
    uVar2 = __aeabi_idiv0(param_1);
    return uVar2;
  }
  uVar5 = param_1 ^ param_2;
  uVar2 = param_2;
  if ((int)param_2 < 0) {
    uVar2 = -param_2;
  }
  if (uVar2 - 1 == 0) {
    if ((int)param_2 < 0) {
      param_1 = -param_1;
    }
    return param_1;
  }
  uVar3 = param_1;
  if ((int)param_1 < 0) {
    uVar3 = -param_1;
  }
  if (uVar3 <= uVar2) {
    if (uVar3 < uVar2) {
      param_1 = 0;
    }
    if (uVar3 == uVar2) {
      param_1 = (int)uVar5 >> 0x1f | 1;
    }
    return param_1;
  }
  if ((uVar2 & uVar2 - 1) == 0) {
    iVar1 = count_leading_zeroes(uVar2);
    uVar3 = uVar3 >> (0x1fU - iVar1 & 0xff);
    if ((int)uVar5 < 0) {
      uVar3 = -uVar3;
    }
    return uVar3;
  }
  iVar4 = count_leading_zeroes(uVar3);
  iVar1 = count_leading_zeroes(uVar2);
                    /* WARNING: Could not recover jumptable at 0x00122ff0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)(&UNK_00122ff8 + (0x1f - (iVar1 - iVar4)) * 0x10))(0);
  return uVar2;
}

