
void * ECDH_get_ex_data(EC_KEY *d,int idx)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  iVar1 = (*(code *)PTR_EC_KEY_get_key_method_data_006aa874)(d,ecdh_data_dup,ecdh_data_free);
  if (iVar1 == 0) {
    iVar1 = ECDH_DATA_new_method_constprop_1();
    if (iVar1 == 0) {
      return (void *)0x0;
    }
    iVar3 = (*(code *)PTR_EC_KEY_insert_key_method_data_006aa878)
                      (d,iVar1,ecdh_data_dup,ecdh_data_free,ecdh_data_free);
    if (iVar3 != 0) {
      if (*(int *)(iVar1 + 4) != 0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
      }
      (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0xd,iVar1,iVar1 + 0x10);
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar1,0x18);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
      iVar1 = iVar3;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00602c88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  pvVar2 = (void *)(*(code *)PTR_CRYPTO_get_ex_data_006a9484)(iVar1 + 0x10,idx);
  return pvVar2;
}

