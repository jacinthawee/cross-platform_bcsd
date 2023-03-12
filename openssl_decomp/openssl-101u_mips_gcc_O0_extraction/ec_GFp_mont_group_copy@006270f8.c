
undefined4 ec_GFp_mont_group_copy(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xa0) != 0) {
    (*(code *)PTR_BN_MONT_CTX_free_006a8568)();
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  if (*(int *)(param_1 + 0xa4) != 0) {
    (*(code *)PTR_BN_clear_free_006a7fa8)();
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  iVar1 = ec_GFp_simple_group_copy(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(param_2 + 0xa0) != 0) {
    iVar1 = (*(code *)PTR_BN_MONT_CTX_new_006a8560)();
    *(int *)(param_1 + 0xa0) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = (*(code *)PTR_BN_MONT_CTX_copy_006a98e4)(iVar1,*(undefined4 *)(param_2 + 0xa0));
    if (iVar1 == 0) goto LAB_006271f4;
  }
  if (*(int *)(param_2 + 0xa4) == 0) {
    return 1;
  }
  iVar1 = (*(code *)PTR_BN_dup_006a8218)();
  *(int *)(param_1 + 0xa4) = iVar1;
  if (iVar1 != 0) {
    return 1;
  }
LAB_006271f4:
  if (*(int *)(param_1 + 0xa0) == 0) {
    return 0;
  }
  (*(code *)PTR_BN_MONT_CTX_free_006a8568)();
  *(undefined4 *)(param_1 + 0xa0) = 0;
  return 0;
}

