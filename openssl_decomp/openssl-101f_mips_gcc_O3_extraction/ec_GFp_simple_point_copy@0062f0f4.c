
undefined4 ec_GFp_simple_point_copy(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_1 + 4,param_2 + 4);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_1 + 0x18,param_2 + 0x18);
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_BN_copy_006a9570)(param_1 + 0x2c,param_2 + 0x2c);
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x40);
        return 1;
      }
    }
  }
  return 0;
}

