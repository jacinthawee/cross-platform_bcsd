
int ECDSA_set_ex_data(EC_KEY *d,int idx,void *arg)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_EC_KEY_get_key_method_data_006aa874)(d,ecdsa_data_dup,ecdsa_data_free);
  if (iVar1 == 0) {
    iVar1 = ECDSA_DATA_new_method_constprop_1();
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_EC_KEY_insert_key_method_data_006aa878)
                      (d,iVar1,ecdsa_data_dup,ecdsa_data_free,ecdsa_data_free);
    if (iVar2 != 0) {
      if (*(int *)(iVar1 + 4) != 0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
      }
      (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0xc,iVar1,iVar1 + 0x10);
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar1,0x18);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
      iVar1 = iVar2;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00600b74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_CRYPTO_set_ex_data_006a9480)(iVar1 + 0x10,idx,arg);
  return iVar1;
}

