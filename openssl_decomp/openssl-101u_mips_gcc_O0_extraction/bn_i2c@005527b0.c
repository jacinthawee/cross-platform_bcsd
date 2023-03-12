
int bn_i2c(int *param_1,undefined *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  if (iVar3 == 0) {
    return -1;
  }
  uVar1 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar3);
  if ((uVar1 & 7) == 0) {
    if (param_2 == (undefined *)0x0) {
      iVar4 = 1;
      goto LAB_00552810;
    }
    *param_2 = 0;
    iVar4 = 1;
    param_2 = param_2 + 1;
  }
  else {
    iVar4 = 0;
    if (param_2 == (undefined *)0x0) goto LAB_00552810;
  }
  (*(code *)PTR_BN_bn2bin_006a7200)(iVar3,param_2);
LAB_00552810:
  iVar2 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar3);
  iVar3 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar3 = iVar2 + 0xe;
  }
  return (iVar3 >> 3) + iVar4;
}

