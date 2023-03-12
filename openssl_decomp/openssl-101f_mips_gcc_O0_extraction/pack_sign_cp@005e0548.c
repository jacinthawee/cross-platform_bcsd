
undefined4 pack_sign_cp(undefined4 *param_1,int param_2,int param_3,int *param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  puVar1 = PTR_memset_006aab00;
  *param_4 = param_2 << 1;
  (*(code *)puVar1)(param_3,0,param_2 << 1);
  uVar4 = param_1[1];
  iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar4);
  iVar3 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar3 = iVar2 + 0xe;
  }
  if (iVar3 >> 3 <= param_2) {
    (*(code *)PTR_memset_006aab00)(param_3,0,param_2);
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar4,param_3 + (param_2 - (iVar3 >> 3)));
  }
  uVar4 = *param_1;
  iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(uVar4);
  iVar3 = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iVar3 = iVar2 + 0xe;
  }
  if (iVar3 >> 3 <= param_2) {
    (*(code *)PTR_memset_006aab00)(param_3 + param_2,0,param_2);
    (*(code *)PTR_BN_bn2bin_006a8300)(uVar4,param_3 + param_2 + (param_2 - (iVar3 >> 3)));
  }
  (*(code *)PTR_DSA_SIG_free_006a987c)(param_1);
  return 1;
}

