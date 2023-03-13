
int ECDSA_set_method(EC_KEY *eckey,ECDSA_METHOD *meth)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_EC_KEY_get_key_method_data_006a976c)(eckey,ecdsa_data_dup,ecdsa_data_free);
  if (iVar1 == 0) {
    iVar1 = ECDSA_DATA_new_method_constprop_1();
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_EC_KEY_insert_key_method_data_006a9770)
                      (eckey,iVar1,ecdsa_data_dup,ecdsa_data_free,ecdsa_data_free);
    if (iVar2 != 0) {
      if (*(int *)(iVar1 + 4) != 0) {
        (*(code *)PTR_ENGINE_finish_006a6fc4)();
      }
      (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(0xc,iVar1,iVar1 + 0x10);
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar1,0x18);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar1);
      iVar1 = iVar2;
    }
  }
  if (*(int *)(iVar1 + 4) != 0) {
    (*(code *)PTR_ENGINE_finish_006a6fc4)();
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  *(ECDSA_METHOD **)(iVar1 + 0xc) = meth;
  return 1;
}

