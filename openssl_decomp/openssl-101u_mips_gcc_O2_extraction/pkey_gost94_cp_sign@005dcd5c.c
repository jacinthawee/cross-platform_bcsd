
undefined4
pkey_gost94_cp_sign(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 param_4,
                   undefined4 param_5)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006a95d4)();
  if (param_3 != (undefined4 *)0x0) {
    if (param_2 == 0) {
      *param_3 = 0x40;
      return 1;
    }
    uVar2 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(uVar2);
    puVar3 = (undefined4 *)gost_do_sign(param_4,param_5,uVar2);
    puVar1 = PTR_memset_006a99f4;
    if (puVar3 != (undefined4 *)0x0) {
      *param_3 = 0x40;
      (*(code *)puVar1)(param_2,0,0x40);
      uVar2 = puVar3[1];
      iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar2);
      iVar5 = iVar4 + 7;
      if (iVar4 + 7 < 0) {
        iVar5 = iVar4 + 0xe;
      }
      if (iVar5 >> 3 < 0x21) {
        (*(code *)PTR_memset_006a99f4)(param_2,0,0x20);
        (*(code *)PTR_BN_bn2bin_006a7200)(uVar2,param_2 + (0x20 - (iVar5 >> 3)));
      }
      uVar2 = *puVar3;
      iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(uVar2);
      iVar5 = iVar4 + 7;
      if (iVar4 + 7 < 0) {
        iVar5 = iVar4 + 0xe;
      }
      if (iVar5 >> 3 < 0x21) {
        (*(code *)PTR_memset_006a99f4)(param_2 + 0x20,0,0x20);
        (*(code *)PTR_BN_bn2bin_006a7200)(uVar2,param_2 + 0x20 + (0x20 - (iVar5 >> 3)));
      }
      (*(code *)PTR_DSA_SIG_free_006a8758)(puVar3);
      return 1;
    }
  }
  return 0;
}
