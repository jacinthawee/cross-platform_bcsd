
undefined4 pkey_gost_mac_init(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x28,"gost_pmeth.c",0x196);
  if (iVar1 != 0) {
    (*(code *)PTR_memset_006a99f4)(iVar1,0,0x28);
    (*(code *)PTR_EVP_PKEY_CTX_set_data_006a95e0)(param_1,iVar1);
    return 1;
  }
  return 0;
}

