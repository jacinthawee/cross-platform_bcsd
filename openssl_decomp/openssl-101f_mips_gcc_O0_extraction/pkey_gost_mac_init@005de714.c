
undefined4 pkey_gost_mac_init(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x28,"gost_pmeth.c",0x1a8);
  if (iVar1 != 0) {
    (*(code *)PTR_memset_006aab00)(iVar1,0,0x28);
    (*(code *)PTR_EVP_PKEY_CTX_set_data_006aa6ec)(param_1,iVar1);
    return 1;
  }
  return 0;
}

