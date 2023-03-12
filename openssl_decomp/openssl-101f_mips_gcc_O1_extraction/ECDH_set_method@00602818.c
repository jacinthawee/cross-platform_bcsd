
int ECDH_set_method(EC_KEY *param_1,ECDH_METHOD *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_EC_KEY_get_key_method_data_006aa874)(param_1,ecdh_data_dup,ecdh_data_free);
  if (iVar1 == 0) {
    iVar1 = ECDH_DATA_new_method_constprop_1();
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_EC_KEY_insert_key_method_data_006aa878)
                      (param_1,iVar1,ecdh_data_dup,ecdh_data_free,ecdh_data_free);
    if (iVar2 != 0) {
      if (*(int *)(iVar1 + 4) != 0) {
        (*(code *)PTR_ENGINE_finish_006a80c4)();
      }
      (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0xd,iVar1,iVar1 + 0x10);
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar1,0x18);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
      iVar1 = iVar2;
    }
  }
  if (*(int *)(iVar1 + 4) != 0) {
    (*(code *)PTR_ENGINE_finish_006a80c4)();
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  *(ECDH_METHOD **)(iVar1 + 0xc) = param_2;
  return 1;
}

