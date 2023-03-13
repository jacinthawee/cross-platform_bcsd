
uint pkey_cmac_ctrl(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x14);
  if (param_2 == 6) {
    if ((param_4 != 0) && (-1 < param_3)) {
      iVar1 = (*(code *)PTR_CMAC_Init_006a9520)(uVar2,param_4,param_3,0,0);
      return (uint)(iVar1 != 0);
    }
    return 0;
  }
  if (param_2 == 0xc) {
    iVar1 = (*(code *)PTR_CMAC_Init_006a9520)(uVar2,0,0,param_4,*(undefined4 *)(param_1 + 4));
    return (uint)(iVar1 != 0);
  }
  if (param_2 == 1) {
    if ((*(int *)(param_1 + 8) != 0) &&
       (iVar1 = (*(code *)PTR_CMAC_CTX_copy_006a951c)
                          (uVar2,*(undefined4 *)(*(int *)(param_1 + 8) + 0x14)), iVar1 == 0)) {
      return 0;
    }
    iVar1 = (*(code *)PTR_CMAC_Init_006a9520)(uVar2,0,0,0,0);
    return (uint)(iVar1 != 0);
  }
  return 0xfffffffe;
}

