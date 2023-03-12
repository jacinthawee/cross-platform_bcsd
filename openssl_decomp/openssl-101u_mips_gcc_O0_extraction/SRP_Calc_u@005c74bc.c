
int SRP_Calc_u(int param_1,char *param_2,char *param_3,int param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  undefined auStack_50 [24];
  undefined auStack_38 [20];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar8 = param_2;
  pcVar9 = param_3;
  if ((((param_1 != 0) && (param_2 != (char *)0x0)) && (param_3 != (char *)0x0)) &&
     ((pcVar8 = param_3, iVar2 = (*(code *)PTR_BN_ucmp_006a7fb4)(), iVar2 < 0 &&
      (pcVar8 = param_3, iVar2 = (*(code *)PTR_BN_ucmp_006a7fb4)(param_2), iVar2 < 0)))) {
    iVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(param_3);
    iVar2 = iVar3 + 7;
    if (iVar3 + 7 < 0) {
      iVar2 = iVar3 + 0xe;
    }
    pcVar9 = (char *)0x84;
    pcVar8 = "srp_lib.c";
    iVar2 = iVar2 >> 3;
    iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2 << 1);
    if (iVar3 != 0) {
      (*(code *)PTR_memset_006a99f4)(iVar3,0,iVar2);
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_50);
      uVar4 = (*(code *)PTR_EVP_sha1_006a75d0)();
      (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_50,uVar4,0);
      iVar5 = (*(code *)PTR_BN_bn2bin_006a7200)(param_1,iVar3 + iVar2);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_50,iVar3 + iVar5,iVar2);
      iVar5 = (*(code *)PTR_BN_bn2bin_006a7200)(param_2,iVar3 + iVar2);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_50,iVar3 + iVar5,iVar2);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
      (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_50,auStack_38,0);
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_50);
      pcVar9 = (char *)0x0;
      pcVar8 = (char *)0x14;
      iVar2 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_38);
      if (iVar2 != 0) {
        if (*(int *)(iVar2 + 4) == 0) {
          (*(code *)PTR_BN_free_006a701c)(iVar2);
          iVar2 = 0;
        }
        goto LAB_005c76b4;
      }
    }
  }
  iVar2 = 0;
LAB_005c76b4:
  if (local_24 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (((pcVar9 != (char *)0x0) && (iVar2 != 0)) && ((pcVar8 != (char *)0x0 && (param_4 != 0)))) {
    iVar3 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if ((iVar3 == 0) || (iVar5 = (*(code *)PTR_BN_new_006a71b4)(), iVar5 == 0)) {
      iVar2 = 0;
      iVar5 = 0;
    }
    else {
      iVar6 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar5,pcVar8,pcVar9,&_gp,iVar3);
      if ((iVar6 == 0) ||
         (iVar2 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar5,iVar2,iVar5,&_gp,iVar3), iVar2 == 0)) {
        iVar2 = 0;
      }
      else {
        iVar6 = (*(code *)PTR_BN_new_006a71b4)();
        iVar2 = iVar6;
        if ((iVar6 != 0) &&
           (iVar7 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar6,iVar5,param_4,&_gp,iVar3), iVar7 == 0))
        {
          iVar2 = 0;
          (*(code *)PTR_BN_free_006a701c)(iVar6);
        }
      }
    }
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar3);
    (*(code *)PTR_BN_clear_free_006a7fa8)(iVar5);
    return iVar2;
  }
  return 0;
}

