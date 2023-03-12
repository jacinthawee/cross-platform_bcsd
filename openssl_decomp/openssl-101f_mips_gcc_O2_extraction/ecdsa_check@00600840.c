
int ecdsa_check(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (*(code *)PTR_EC_KEY_get_key_method_data_006aa874)(param_1,ecdsa_data_dup,ecdsa_data_free)
  ;
  if (((iVar1 == 0) && (iVar2 = ECDSA_DATA_new_method_constprop_1(), iVar2 != 0)) &&
     (iVar3 = (*(code *)PTR_EC_KEY_insert_key_method_data_006aa878)
                        (param_1,iVar2,ecdsa_data_dup,ecdsa_data_free,ecdsa_data_free),
     iVar1 = iVar2, iVar3 != 0)) {
    if (*(int *)(iVar2 + 4) != 0) {
      (*(code *)PTR_ENGINE_finish_006a80c4)();
    }
    (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0xc,iVar2,iVar2 + 0x10);
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar2,0x18);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
    iVar1 = iVar3;
  }
  return iVar1;
}

