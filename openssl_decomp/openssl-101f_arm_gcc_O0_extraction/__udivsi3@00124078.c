
uint __udivsi3(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 - 1 == 0) {
    return param_1;
  }
  if (param_2 == 0) {
    if (param_1 != 0) {
      param_1 = 0xffffffff;
    }
    uVar1 = __aeabi_idiv0(param_1);
    return uVar1;
  }
  if (param_1 <= param_2) {
    return (uint)(param_1 == param_2);
  }
  if ((param_2 & param_2 - 1) == 0) {
    iVar2 = count_leading_zeroes(param_2);
    return param_1 >> (0x1fU - iVar2 & 0xff);
  }
  iVar3 = count_leading_zeroes(param_1);
  iVar2 = count_leading_zeroes(param_2);
                    /* WARNING: Could not recover jumptable at 0x001240a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(&UNK_001240b0 + (0x1f - (iVar2 - iVar3)) * 0x10))(param_1,param_2,0);
  return uVar1;
}

