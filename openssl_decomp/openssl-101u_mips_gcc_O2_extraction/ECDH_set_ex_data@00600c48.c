
int ECDH_set_ex_data(EC_KEY *d,int idx,void *arg)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_EC_KEY_get_key_method_data_006a976c)(d,ecdh_data_dup,ecdh_data_free);
  if (iVar1 == 0) {
    iVar1 = ECDH_DATA_new_method_constprop_1();
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_EC_KEY_insert_key_method_data_006a9770)
                      (d,iVar1,ecdh_data_dup,ecdh_data_free,ecdh_data_free);
    if (iVar2 != 0) {
      if (*(int *)(iVar1 + 4) != 0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
      }
      (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(0xd,iVar1,iVar1 + 0x10);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar1,0x18);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar1);
      iVar1 = iVar2;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00600cd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_CRYPTO_set_ex_data_006a8360)(iVar1 + 0x10,idx,arg);
  return iVar1;
}

