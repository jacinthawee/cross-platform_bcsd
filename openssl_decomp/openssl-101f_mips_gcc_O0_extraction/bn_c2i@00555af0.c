
undefined4
bn_c2i(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
      int param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_BN_new_006a82b4)(param_2,param_3);
    *param_1 = iVar1;
  }
  iVar1 = (*(code *)PTR_BN_bin2bn_006a89f0)(param_2,param_3,iVar1);
  uVar2 = 1;
  if (iVar1 == 0) {
    if (*param_1 == 0) {
      uVar2 = 0;
    }
    else if ((*(uint *)(param_6 + 0x14) & 1) == 0) {
      (*(code *)PTR_BN_free_006a811c)();
      uVar2 = 0;
      *param_1 = 0;
    }
    else {
      (*(code *)PTR_BN_clear_free_006a9130)();
      uVar2 = 0;
      *param_1 = 0;
    }
  }
  return uVar2;
}

