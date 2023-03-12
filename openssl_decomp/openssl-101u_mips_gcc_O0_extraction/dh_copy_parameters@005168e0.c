
undefined4 dh_copy_parameters(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_BN_dup_006a8218)(*(undefined4 *)(*(int *)(param_2 + 0x14) + 8));
  if (iVar1 != 0) {
    iVar2 = *(int *)(param_1 + 0x14);
    if (*(int *)(iVar2 + 8) != 0) {
      (*(code *)PTR_BN_free_006a701c)();
      iVar2 = *(int *)(param_1 + 0x14);
    }
    *(int *)(iVar2 + 8) = iVar1;
    iVar1 = (*(code *)PTR_BN_dup_006a8218)(*(undefined4 *)(*(int *)(param_2 + 0x14) + 0xc));
    if (iVar1 != 0) {
      iVar2 = *(int *)(param_1 + 0x14);
      if (*(int *)(iVar2 + 0xc) != 0) {
        (*(code *)PTR_BN_free_006a701c)();
        iVar2 = *(int *)(param_1 + 0x14);
      }
      *(int *)(iVar2 + 0xc) = iVar1;
      return 1;
    }
  }
  return 0;
}

