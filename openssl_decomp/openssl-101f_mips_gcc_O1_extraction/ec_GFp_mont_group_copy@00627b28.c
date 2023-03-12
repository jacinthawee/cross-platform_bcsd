
undefined4 ec_GFp_mont_group_copy(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xa0) != 0) {
    (*(code *)PTR_BN_MONT_CTX_free_006a9690)();
    *(undefined4 *)(param_1 + 0xa0) = 0;
  }
  if (*(int *)(param_1 + 0xa4) != 0) {
    (*(code *)PTR_BN_clear_free_006a9130)();
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  iVar1 = ec_GFp_simple_group_copy(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(param_2 + 0xa0) != 0) {
    iVar1 = (*(code *)PTR_BN_MONT_CTX_new_006a9688)();
    *(int *)(param_1 + 0xa0) = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = (*(code *)PTR_BN_MONT_CTX_copy_006aa9f4)(iVar1,*(undefined4 *)(param_2 + 0xa0));
    if (iVar1 == 0) goto LAB_00627c24;
  }
  if (*(int *)(param_2 + 0xa4) == 0) {
    return 1;
  }
  iVar1 = (*(code *)PTR_BN_dup_006a9100)();
  *(int *)(param_1 + 0xa4) = iVar1;
  if (iVar1 != 0) {
    return 1;
  }
LAB_00627c24:
  if (*(int *)(param_1 + 0xa0) == 0) {
    return 0;
  }
  (*(code *)PTR_BN_MONT_CTX_free_006a9690)();
  *(undefined4 *)(param_1 + 0xa0) = 0;
  return 0;
}

