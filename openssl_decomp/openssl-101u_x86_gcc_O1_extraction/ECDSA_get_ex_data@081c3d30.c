
void * __regparm1 ECDSA_get_ex_data(EC_KEY *d,int idx)

{
  EC_KEY *key;
  void *pvVar1;
  EC_KEY *pEVar2;
  int in_stack_00000008;
  
  key = (EC_KEY *)EC_KEY_get_key_method_data(d,(dup_func *)idx,ecdsa_data_dup,ecdsa_data_free);
  if (key == (EC_KEY *)0x0) {
    key = (EC_KEY *)ECDSA_DATA_new_method_constprop_1();
    if (key == (EC_KEY *)0x0) {
      return (void *)0x0;
    }
    pEVar2 = (EC_KEY *)
             EC_KEY_insert_key_method_data
                       (key,(void *)idx,(dup_func *)key,ecdsa_data_dup,ecdsa_data_free);
    if (pEVar2 != (EC_KEY *)0x0) {
      if (*(ENGINE **)(key + 4) != (ENGINE *)0x0) {
        ENGINE_finish(*(ENGINE **)(key + 4));
      }
      CRYPTO_free_ex_data(0xc,key,(CRYPTO_EX_DATA *)(key + 0x10));
      OPENSSL_cleanse(key,0x18);
      CRYPTO_free(key);
      key = pEVar2;
    }
  }
  pvVar1 = CRYPTO_get_ex_data((CRYPTO_EX_DATA *)(key + 0x10),in_stack_00000008);
  return pvVar1;
}

