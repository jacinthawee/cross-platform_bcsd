
undefined4 pkey_gost_mac_copy(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  iVar1 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"gost_pmeth.c",0x1a8);
  if (iVar1 != 0) {
    (*(code *)PTR_memset_006aab00)(iVar1,0,0x28);
    (*(code *)PTR_EVP_PKEY_CTX_set_data_006aa6ec)(param_1,iVar1);
    puVar2 = (undefined4 *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)(param_2);
    puVar3 = (undefined4 *)(*(code *)PTR_EVP_PKEY_CTX_get_data_006aa6dc)(param_1);
    puVar6 = puVar2;
    do {
      puVar7 = puVar3;
      puVar5 = puVar6;
      puVar6 = puVar5 + 4;
      uVar9 = puVar5[1];
      uVar8 = puVar5[2];
      uVar4 = puVar5[3];
      *puVar7 = *puVar5;
      puVar7[1] = uVar9;
      puVar7[2] = uVar8;
      puVar7[3] = uVar4;
      puVar3 = puVar7 + 4;
    } while (puVar6 != puVar2 + 8);
    uVar4 = puVar5[5];
    puVar7[4] = *puVar6;
    puVar7[5] = uVar4;
    return 1;
  }
  return 0;
}

