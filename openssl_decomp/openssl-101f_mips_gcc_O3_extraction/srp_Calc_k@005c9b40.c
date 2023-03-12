
int srp_Calc_k(undefined *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  undefined *unaff_s0;
  int iVar9;
  undefined auStack_b0 [24];
  undefined auStack_98 [20];
  int iStack_84;
  undefined *puStack_80;
  int iStack_7c;
  undefined *puStack_78;
  int iStack_74;
  undefined *puStack_70;
  undefined auStack_48 [24];
  undefined auStack_30 [20];
  int local_1c;
  
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)();
  iStack_7c = iVar2 + 7;
  if (iVar2 + 7 < 0) {
    iStack_7c = iVar2 + 0xe;
  }
  iVar8 = 0x5c;
  pcVar6 = "srp_lib.c";
  iStack_7c = iStack_7c >> 3;
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iStack_7c);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    (*(code *)PTR_BN_bn2bin_006a8300)(param_1,iVar2);
    param_1 = auStack_48;
    (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(param_1);
    uVar3 = (*(code *)PTR_EVP_sha1_006a86c4)();
    (*(code *)PTR_EVP_DigestInit_ex_006a8670)(param_1,uVar3,0);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(param_1,iVar2,iStack_7c);
    (*(code *)PTR_memset_006aab00)(iVar2,0,iStack_7c);
    param_2 = (*(code *)PTR_BN_bn2bin_006a8300)(param_2,iVar2);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(param_1,iVar2 + param_2,iStack_7c - param_2);
    (*(code *)PTR_EVP_DigestUpdate_006a8674)(param_1,iVar2,param_2);
    unaff_s0 = auStack_30;
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
    (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(param_1,unaff_s0,0);
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(param_1);
    iVar8 = 0;
    pcVar6 = (char *)0x14;
    iVar2 = (*(code *)PTR_BN_bin2bn_006a89f0)(unaff_s0);
  }
  if (local_1c == *(int *)puStack_70) {
    return iVar2;
  }
  iVar2 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_84 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar7 = pcVar6;
  puStack_80 = unaff_s0;
  puStack_78 = param_1;
  iStack_74 = param_2;
  if (((iVar2 != 0) && (pcVar6 != (char *)0x0)) && (iVar8 != 0)) {
    iVar8 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar8);
    iVar9 = iVar8 + 7;
    if (iVar8 + 7 < 0) {
      iVar9 = iVar8 + 0xe;
    }
    iVar8 = 0x7e;
    pcVar7 = "srp_lib.c";
    iVar9 = iVar9 >> 3;
    iVar4 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar9 << 1);
    if (iVar4 != 0) {
      (*(code *)PTR_memset_006aab00)(iVar4,0,iVar9);
      (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_b0);
      uVar3 = (*(code *)PTR_EVP_sha1_006a86c4)();
      (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_b0,uVar3,0);
      iVar2 = (*(code *)PTR_BN_bn2bin_006a8300)(iVar2,iVar4 + iVar9);
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_b0,iVar4 + iVar2,iVar9);
      iVar2 = (*(code *)PTR_BN_bn2bin_006a8300)(pcVar6,iVar4 + iVar9);
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_b0,iVar4 + iVar2,iVar9);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar4);
      (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_b0,auStack_98,0);
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_b0);
      iVar8 = 0;
      pcVar7 = (char *)0x14;
      iVar2 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_98);
      if (iVar2 != 0) {
        if (*(int *)(iVar2 + 4) == 0) {
          (*(code *)PTR_BN_free_006a811c)(iVar2);
          iVar2 = 0;
        }
        goto LAB_005c9ed0;
      }
    }
  }
  iVar2 = 0;
LAB_005c9ed0:
  if (iStack_84 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = iStack_84;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (((iVar8 != 0) && (iVar2 != 0)) && ((pcVar7 != (char *)0x0 && (param_4 != 0)))) {
    iVar9 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if ((iVar9 == 0) || (iVar4 = (*(code *)PTR_BN_new_006a82b4)(), iVar4 == 0)) {
      iVar5 = 0;
      iVar4 = 0;
    }
    else {
      iVar5 = (*(code *)PTR_BN_new_006a82b4)();
      if (((iVar5 != 0) &&
          (iVar8 = (*(code *)PTR_BN_mod_exp_006a8a48)(iVar4,pcVar7,iVar8,&_gp,iVar9), iVar8 != 0))
         && (iVar2 = (*(code *)PTR_BN_mod_mul_006a9698)(iVar4,iVar2,iVar4,&_gp,iVar9), iVar2 != 0))
      {
        (*(code *)PTR_BN_mod_exp_006a8a48)(iVar5,iVar4,param_4,&_gp,iVar9);
      }
    }
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar9);
    (*(code *)PTR_BN_clear_free_006a9130)(iVar4);
    return iVar5;
  }
  return 0;
}

