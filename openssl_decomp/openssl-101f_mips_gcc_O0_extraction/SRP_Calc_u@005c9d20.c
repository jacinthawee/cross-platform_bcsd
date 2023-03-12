
int SRP_Calc_u(int param_1,char *param_2,int param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined auStack_50 [24];
  undefined auStack_38 [20];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  pcVar7 = param_2;
  if (((param_1 != 0) && (param_2 != (char *)0x0)) && (param_3 != 0)) {
    iVar2 = (*(code *)PTR_BN_num_bits_006a82f4)(param_3);
    iVar8 = iVar2 + 7;
    if (iVar2 + 7 < 0) {
      iVar8 = iVar2 + 0xe;
    }
    param_3 = 0x7e;
    pcVar7 = "srp_lib.c";
    iVar8 = iVar8 >> 3;
    iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar8 << 1);
    if (iVar2 != 0) {
      (*(code *)PTR_memset_006aab00)(iVar2,0,iVar8);
      (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_50);
      uVar3 = (*(code *)PTR_EVP_sha1_006a86c4)();
      (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_50,uVar3,0);
      iVar4 = (*(code *)PTR_BN_bn2bin_006a8300)(param_1,iVar2 + iVar8);
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_50,iVar2 + iVar4,iVar8);
      iVar4 = (*(code *)PTR_BN_bn2bin_006a8300)(param_2,iVar2 + iVar8);
      (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_50,iVar2 + iVar4,iVar8);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
      (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_50,auStack_38,0);
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_50);
      param_3 = 0;
      pcVar7 = (char *)0x14;
      iVar8 = (*(code *)PTR_BN_bin2bn_006a89f0)(auStack_38);
      if (iVar8 != 0) {
        if (*(int *)(iVar8 + 4) == 0) {
          (*(code *)PTR_BN_free_006a811c)(iVar8);
          iVar8 = 0;
        }
        goto LAB_005c9ed0;
      }
    }
  }
  iVar8 = 0;
LAB_005c9ed0:
  if (local_24 == *(int *)puVar1) {
    return iVar8;
  }
  iVar8 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (((param_3 != 0) && (iVar8 != 0)) && ((pcVar7 != (char *)0x0 && (param_4 != 0)))) {
    iVar2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if ((iVar2 == 0) || (iVar4 = (*(code *)PTR_BN_new_006a82b4)(), iVar4 == 0)) {
      iVar5 = 0;
      iVar4 = 0;
    }
    else {
      iVar5 = (*(code *)PTR_BN_new_006a82b4)();
      if (((iVar5 != 0) &&
          (iVar6 = (*(code *)PTR_BN_mod_exp_006a8a48)(iVar4,pcVar7,param_3,&_gp,iVar2), iVar6 != 0))
         && (iVar8 = (*(code *)PTR_BN_mod_mul_006a9698)(iVar4,iVar8,iVar4,&_gp,iVar2), iVar8 != 0))
      {
        (*(code *)PTR_BN_mod_exp_006a8a48)(iVar5,iVar4,param_4,&_gp,iVar2);
      }
    }
    (*(code *)PTR_BN_CTX_free_006a8a40)(iVar2);
    (*(code *)PTR_BN_clear_free_006a9130)(iVar4);
    return iVar5;
  }
  return 0;
}

