
undefined4 pkey_gost_init(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006a95d4)();
  puVar2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x10,"gost_pmeth.c",0x1a);
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  (*(code *)PTR_memset_006a99f4)(puVar2,0,0x10);
  if ((iVar1 != 0) && (iVar3 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(iVar1), iVar3 != 0)) {
    iVar3 = (*(code *)PTR_EVP_PKEY_base_id_006a6f0c)(iVar1);
    if (iVar3 == 0x32b) {
      uVar4 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(iVar1);
      uVar4 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar4);
      uVar4 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar4);
      *puVar2 = uVar4;
    }
    else {
      if (iVar3 != 0x32c) {
        return 0;
      }
      uVar4 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)(iVar1);
      uVar4 = (*(code *)PTR_gost94_nid_by_params_006a95dc)(uVar4);
      *puVar2 = uVar4;
    }
  }
  (*(code *)PTR_EVP_PKEY_CTX_set_data_006a95e0)(param_1,puVar2);
  return 1;
}

