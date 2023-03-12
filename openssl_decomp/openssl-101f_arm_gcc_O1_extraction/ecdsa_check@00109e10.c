
void * ecdsa_check(EC_KEY *param_1)

{
  void *data;
  void *pvVar1;
  
  data = EC_KEY_get_key_method_data
                   (param_1,ecdsa_data_dup + 1,ecdsa_data_free + 1,ecdsa_data_free + 1);
  if (((data == (void *)0x0) &&
      (data = (void *)ECDSA_DATA_new_method_constprop_0(), data != (void *)0x0)) &&
     (pvVar1 = EC_KEY_insert_key_method_data
                         (param_1,data,ecdsa_data_dup + 1,ecdsa_data_free + 1,ecdsa_data_free + 1),
     pvVar1 != (void *)0x0)) {
    if (*(ENGINE **)((int)data + 4) != (ENGINE *)0x0) {
      ENGINE_finish(*(ENGINE **)((int)data + 4));
    }
    CRYPTO_free_ex_data(0xc,data,(CRYPTO_EX_DATA *)((int)data + 0x10));
    OPENSSL_cleanse(data,0x18);
    CRYPTO_free(data);
    data = pvVar1;
  }
  return data;
}

