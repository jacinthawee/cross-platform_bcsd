
EC_KEY * __regparm1 ecdh_check(EC_KEY *param_1_00,dup_func *param_1)

{
  EC_KEY *pEVar1;
  EC_KEY *key;
  EC_KEY *pEVar2;
  
  pEVar1 = (EC_KEY *)EC_KEY_get_key_method_data(param_1_00,param_1,ecdh_data_dup,ecdh_data_free);
  if (pEVar1 == (EC_KEY *)0x0) {
    key = (EC_KEY *)ECDH_DATA_new_method_constprop_1();
    if (key != (EC_KEY *)0x0) {
      pEVar2 = (EC_KEY *)
               EC_KEY_insert_key_method_data
                         (key,param_1,(dup_func *)key,ecdh_data_dup,ecdh_data_free);
      pEVar1 = key;
      if (pEVar2 != (EC_KEY *)0x0) {
        if (*(ENGINE **)(key + 4) != (ENGINE *)0x0) {
          ENGINE_finish(*(ENGINE **)(key + 4));
        }
        CRYPTO_free_ex_data(0xd,key,(CRYPTO_EX_DATA *)(key + 0x10));
        OPENSSL_cleanse(key,0x18);
        CRYPTO_free(key);
        pEVar1 = pEVar2;
      }
    }
  }
  return pEVar1;
}

