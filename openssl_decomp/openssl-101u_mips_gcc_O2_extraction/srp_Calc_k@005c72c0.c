
int srp_Calc_k(char *param_1,int param_2,char *param_3,int param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  int unaff_s1;
  undefined auStack_b0 [24];
  undefined auStack_98 [20];
  int iStack_84;
  undefined *puStack_80;
  int iStack_7c;
  char *pcStack_78;
  undefined *puStack_74;
  int iStack_70;
  char acStack_48 [24];
  undefined auStack_30 [20];
  int local_1c;
  
  puStack_74 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_80 = (undefined *)(*(code *)PTR_BN_num_bits_006a71f4)();
  pcVar8 = param_1;
  iVar1 = (*(code *)PTR_BN_ucmp_006a7fb4)(param_2);
  if (iVar1 < 0) {
    puVar2 = puStack_80 + 7;
    if ((int)(puStack_80 + 7) < 0) {
      puVar2 = puStack_80 + 0xe;
    }
    param_3 = (char *)0x5f;
    pcVar8 = "srp_lib.c";
    unaff_s1 = (int)puVar2 >> 3;
    puVar2 = (undefined *)(*(code *)PTR_CRYPTO_malloc_006a7008)(unaff_s1);
    puStack_80 = puVar2;
    if (puVar2 == (undefined *)0x0) goto LAB_005c74a8;
    (*(code *)PTR_BN_bn2bin_006a7200)(param_1,puVar2);
    (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(acStack_48);
    uVar3 = (*(code *)PTR_EVP_sha1_006a75d0)();
    (*(code *)PTR_EVP_DigestInit_ex_006a757c)(acStack_48,uVar3,0);
    (*(code *)PTR_EVP_DigestUpdate_006a7580)(acStack_48,puVar2,unaff_s1);
    (*(code *)PTR_memset_006a99f4)(puVar2,0,unaff_s1);
    param_2 = (*(code *)PTR_BN_bn2bin_006a7200)(param_2,puVar2);
    (*(code *)PTR_EVP_DigestUpdate_006a7580)(acStack_48,puVar2 + param_2,unaff_s1 - param_2);
    (*(code *)PTR_EVP_DigestUpdate_006a7580)(acStack_48,puVar2,param_2);
    puStack_80 = auStack_30;
    (*(code *)PTR_CRYPTO_free_006a6e88)(puVar2);
    (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(acStack_48,puStack_80,0);
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(acStack_48);
    param_3 = (char *)0x0;
    pcVar8 = &DAT_00000014;
    iVar1 = (*(code *)PTR_BN_bin2bn_006a7904)(puStack_80);
    param_1 = acStack_48;
  }
  else {
LAB_005c74a8:
    iVar1 = 0;
  }
  if (local_1c == *(int *)puStack_74) {
    return iVar1;
  }
  iVar1 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_84 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar9 = pcVar8;
  pcVar10 = param_3;
  iStack_7c = unaff_s1;
  pcStack_78 = param_1;
  iStack_70 = param_2;
  if ((((iVar1 != 0) && (pcVar8 != (char *)0x0)) && (param_3 != (char *)0x0)) &&
     ((pcVar9 = param_3, iVar4 = (*(code *)PTR_BN_ucmp_006a7fb4)(), iVar4 < 0 &&
      (pcVar9 = param_3, iVar4 = (*(code *)PTR_BN_ucmp_006a7fb4)(pcVar8), iVar4 < 0)))) {
    iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(param_3);
    iVar4 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar4 = iVar5 + 0xe;
    }
    pcVar10 = &DAT_00000084;
    pcVar9 = "srp_lib.c";
    iVar4 = iVar4 >> 3;
    iVar5 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4 << 1);
    if (iVar5 != 0) {
      (*(code *)PTR_memset_006a99f4)(iVar5,0,iVar4);
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_b0);
      uVar3 = (*(code *)PTR_EVP_sha1_006a75d0)();
      (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_b0,uVar3,0);
      iVar1 = (*(code *)PTR_BN_bn2bin_006a7200)(iVar1,iVar5 + iVar4);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_b0,iVar5 + iVar1,iVar4);
      iVar1 = (*(code *)PTR_BN_bn2bin_006a7200)(pcVar8,iVar5 + iVar4);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_b0,iVar5 + iVar1,iVar4);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar5);
      (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_b0,auStack_98,0);
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_b0);
      pcVar10 = (char *)0x0;
      pcVar9 = &DAT_00000014;
      iVar1 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_98);
      if (iVar1 != 0) {
        if (*(int *)(iVar1 + 4) == 0) {
          (*(code *)PTR_BN_free_006a701c)(iVar1);
          iVar1 = 0;
        }
        goto LAB_005c76b4;
      }
    }
  }
  iVar1 = 0;
LAB_005c76b4:
  if (iStack_84 == *(int *)puVar2) {
    return iVar1;
  }
  iVar1 = iStack_84;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (((pcVar10 != (char *)0x0) && (iVar1 != 0)) && ((pcVar9 != (char *)0x0 && (param_4 != 0)))) {
    iVar4 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if ((iVar4 == 0) || (iVar5 = (*(code *)PTR_BN_new_006a71b4)(), iVar5 == 0)) {
      iVar1 = 0;
      iVar5 = 0;
    }
    else {
      iVar6 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar5,pcVar9,pcVar10,&_gp,iVar4);
      if ((iVar6 == 0) ||
         (iVar1 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar5,iVar1,iVar5,&_gp,iVar4), iVar1 == 0)) {
        iVar1 = 0;
      }
      else {
        iVar6 = (*(code *)PTR_BN_new_006a71b4)();
        iVar1 = iVar6;
        if ((iVar6 != 0) &&
           (iVar7 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar6,iVar5,param_4,&_gp,iVar4), iVar7 == 0))
        {
          iVar1 = 0;
          (*(code *)PTR_BN_free_006a701c)(iVar6);
        }
      }
    }
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar4);
    (*(code *)PTR_BN_clear_free_006a7fa8)(iVar5);
    return iVar1;
  }
  return 0;
}

