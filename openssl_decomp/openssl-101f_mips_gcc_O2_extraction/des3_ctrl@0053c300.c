
undefined4 des3_ctrl(int param_1,int param_2,undefined4 param_3,uchar *param_4)

{
  int iVar1;
  
  if (param_2 != 6) {
    return 0xffffffff;
  }
  iVar1 = RAND_bytes(param_4,*(int *)(param_1 + 0x58));
  if (0 < iVar1) {
    (*(code *)PTR_DES_set_odd_parity_006a9ad8)(param_4);
    if (0xf < *(int *)(param_1 + 0x58)) {
      (*(code *)PTR_DES_set_odd_parity_006a9ad8)(param_4 + 8);
      if (0x17 < *(int *)(param_1 + 0x58)) {
        (*(code *)PTR_DES_set_odd_parity_006a9ad8)(param_4 + 0x10);
        return 1;
      }
    }
    return 1;
  }
  return 0;
}

