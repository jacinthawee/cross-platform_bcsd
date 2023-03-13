
uint pkey_rsa_verify(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    int param_5)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar6 = *(int *)(param_1 + 0x14);
  iVar5 = *(int *)(param_1 + 8);
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar7 = *(undefined4 *)(iVar5 + 0x14);
  if (*(int *)(iVar6 + 0x14) == 0) {
    iVar2 = *(int *)(iVar6 + 0x20);
    if (iVar2 == 0) {
      uVar4 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(iVar5);
      iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4,"rsa_pmeth.c",0x8c);
      *(int *)(iVar6 + 0x20) = iVar2;
      if (iVar2 == 0) {
LAB_005fc1b8:
        uVar3 = 0xffffffff;
        goto LAB_005fc0cc;
      }
    }
    local_28 = (*(code *)PTR_RSA_public_decrypt_006a7650)
                         (param_3,param_2,iVar2,uVar7,*(undefined4 *)(iVar6 + 0x10));
    if (local_28 != 0) {
LAB_005fc138:
      if (param_5 == local_28) {
        iVar5 = (*(code *)PTR_memcmp_006a9ad0)(param_4,*(undefined4 *)(iVar6 + 0x20),param_5);
        uVar3 = (uint)(iVar5 == 0);
        goto LAB_005fc0cc;
      }
    }
  }
  else {
    iVar2 = *(int *)(iVar6 + 0x10);
    if (iVar2 == 1) {
      uVar4 = (*(code *)PTR_EVP_MD_type_006a73cc)(*(int *)(iVar6 + 0x14));
      uVar3 = (*(code *)PTR_RSA_verify_006a7a7c)(uVar4,param_4,param_5,param_2,param_3,uVar7);
      goto LAB_005fc0cc;
    }
    if (iVar2 == 5) {
      iVar5 = pkey_rsa_verifyrecover(param_1,0,&local_28,param_2,param_3);
      if (0 < iVar5) goto LAB_005fc138;
    }
    else {
      uVar3 = 0xffffffff;
      if (iVar2 != 6) goto LAB_005fc0cc;
      iVar2 = *(int *)(iVar6 + 0x20);
      if (iVar2 == 0) {
        uVar4 = (*(code *)PTR_EVP_PKEY_size_006a74f8)(iVar5);
        iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4,"rsa_pmeth.c",0x8c);
        *(int *)(iVar6 + 0x20) = iVar2;
        if (iVar2 == 0) goto LAB_005fc1b8;
      }
      iVar5 = (*(code *)PTR_RSA_public_decrypt_006a7650)(param_3,param_2,iVar2,uVar7,3);
      if (0 < iVar5) {
        iVar5 = (*(code *)PTR_RSA_verify_PKCS1_PSS_mgf1_006a9748)
                          (uVar7,param_4,*(undefined4 *)(iVar6 + 0x14),*(undefined4 *)(iVar6 + 0x18)
                           ,*(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar6 + 0x1c));
        uVar3 = (uint)(0 < iVar5);
        goto LAB_005fc0cc;
      }
    }
  }
  uVar3 = 0;
LAB_005fc0cc:
  if (local_24 == *(int *)puVar1) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar3 = (*(code *)PTR_ERR_func_error_string_006a8440)(DSA_str_functs._0_4_);
  if (uVar3 == 0) {
    (*(code *)PTR_ERR_load_strings_006a8444)(0,DSA_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005fc2b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*(code *)PTR_ERR_load_strings_006a8444)(0,DSA_str_reasons);
    return uVar3;
  }
  return uVar3;
}

