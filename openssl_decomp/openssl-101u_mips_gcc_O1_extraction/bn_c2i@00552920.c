
undefined4
bn_c2i(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
      int param_6)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_BN_new_006a71b4)(param_2,param_3);
    *param_1 = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = (*(code *)PTR_BN_bin2bn_006a7904)(param_2,param_3,iVar1);
  if (iVar1 != 0) {
    return 1;
  }
  if (*param_1 == 0) {
    return 0;
  }
  if ((*(uint *)(param_6 + 0x14) & 1) == 0) {
    (*(code *)PTR_BN_free_006a701c)();
    *param_1 = 0;
    return 0;
  }
  (*(code *)PTR_BN_clear_free_006a7fa8)();
  *param_1 = 0;
  return 0;
}

