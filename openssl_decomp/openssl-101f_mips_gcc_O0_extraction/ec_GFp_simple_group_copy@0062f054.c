
undefined4 ec_GFp_simple_group_copy(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_1 + 0x48,param_2 + 0x48);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_1 + 0x74,param_2 + 0x74);
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_1 + 0x88,param_2 + 0x88);
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_2 + 0x9c);
        return 1;
      }
    }
  }
  return 0;
}

