
int SRP_Calc_x(int param_1,char *param_2,int param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined auStack_50 [24];
  undefined auStack_38 [20];
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar7 = param_2;
  iVar2 = param_3;
  if (((param_1 != 0) && (param_2 != (char *)0x0)) && (param_3 != 0)) {
    iVar2 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar3 = iVar2 + 7;
    if (iVar2 + 7 < 0) {
      iVar3 = iVar2 + 0xe;
    }
    iVar2 = 0xdf;
    pcVar7 = "srp_lib.c";
    iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3 >> 3);
    if (iVar3 != 0) {
      (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_50);
      uVar4 = (*(code *)PTR_EVP_sha1_006a75d0)();
      (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_50,uVar4,0);
      uVar4 = (*(code *)PTR_strlen_006a9a24)(param_2);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_50,param_2,uVar4);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_50,":",1);
      uVar4 = (*(code *)PTR_strlen_006a9a24)(param_3);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_50,param_3,uVar4);
      (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_50,auStack_38,0);
      uVar4 = (*(code *)PTR_EVP_sha1_006a75d0)();
      (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_50,uVar4,0);
      (*(code *)PTR_BN_bn2bin_006a7200)(param_1,iVar3);
      iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(param_1);
      iVar2 = iVar5 + 7;
      if (iVar5 + 7 < 0) {
        iVar2 = iVar5 + 0xe;
      }
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_50,iVar3,iVar2 >> 3);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
      (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_50,auStack_38,0x14);
      (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_50,auStack_38,0);
      (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_50);
      iVar2 = 0;
      pcVar7 = (char *)0x14;
      iVar3 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_38);
      goto LAB_005c7cd0;
    }
  }
  iVar3 = 0;
LAB_005c7cd0:
  if (local_24 == *(int *)puVar1) {
    return iVar3;
  }
  iVar3 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (((iVar3 != 0) && (pcVar7 != (char *)0x0)) && (iVar2 != 0)) {
    iVar5 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (iVar5 == 0) {
      iVar8 = 0;
    }
    else {
      iVar6 = (*(code *)PTR_BN_new_006a71b4)();
      iVar8 = iVar6;
      if (iVar6 != 0) {
        iVar2 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar6,iVar2,iVar3,pcVar7,iVar5);
        if (iVar2 == 0) {
          iVar8 = 0;
          (*(code *)PTR_BN_free_006a701c)(iVar6);
        }
      }
      (*(code *)PTR_BN_CTX_free_006a7954)(iVar5);
    }
    return iVar8;
  }
  return 0;
}

