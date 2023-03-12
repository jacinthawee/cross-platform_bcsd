
undefined4 store_bignum(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
  iVar2 = iVar1 + 7;
  if (iVar1 + 7 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  if (param_3 < iVar2 >> 3) {
    return 0;
  }
  (*(code *)PTR_memset_006a99f4)(param_2,0,param_3);
  (*(code *)PTR_BN_bn2bin_006a7200)(param_1,param_2 + (param_3 - (iVar2 >> 3)));
  return 1;
}

