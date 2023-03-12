
int __regparm1 ECDSA_set_method(EC_KEY *eckey,ECDSA_METHOD *meth)

{
  EC_KEY *key;
  EC_KEY *pEVar1;
  undefined4 in_stack_00000008;
  
  key = (EC_KEY *)EC_KEY_get_key_method_data(eckey,(dup_func *)meth,ecdsa_data_dup,ecdsa_data_free);
  if (key == (EC_KEY *)0x0) {
    key = (EC_KEY *)ECDSA_DATA_new_method_constprop_1();
    if (key == (EC_KEY *)0x0) {
      return 0;
    }
    pEVar1 = (EC_KEY *)
             EC_KEY_insert_key_method_data(key,meth,(dup_func *)key,ecdsa_data_dup,ecdsa_data_free);
    if (pEVar1 != (EC_KEY *)0x0) {
      if (*(ENGINE **)(key + 4) != (ENGINE *)0x0) {
        ENGINE_finish(*(ENGINE **)(key + 4));
      }
      CRYPTO_free_ex_data(0xc,key,(CRYPTO_EX_DATA *)(key + 0x10));
      OPENSSL_cleanse(key,0x18);
      CRYPTO_free(key);
      key = pEVar1;
    }
  }
  if (*(ENGINE **)(key + 4) != (ENGINE *)0x0) {
    ENGINE_finish(*(ENGINE **)(key + 4));
    *(undefined4 *)(key + 4) = 0;
  }
  *(undefined4 *)(key + 0xc) = in_stack_00000008;
  return 1;
}

