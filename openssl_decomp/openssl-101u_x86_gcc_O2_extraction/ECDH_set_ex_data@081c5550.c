
int __regparm1 ECDH_set_ex_data(EC_KEY *d,int idx,void *arg)

{
  EC_KEY *key;
  int iVar1;
  EC_KEY *pEVar2;
  void *in_stack_0000000c;
  
  key = (EC_KEY *)EC_KEY_get_key_method_data(d,(dup_func *)idx,ecdh_data_dup,ecdh_data_free);
  if (key == (EC_KEY *)0x0) {
    key = (EC_KEY *)ECDH_DATA_new_method_constprop_1();
    if (key == (EC_KEY *)0x0) {
      return 0;
    }
    pEVar2 = (EC_KEY *)
             EC_KEY_insert_key_method_data
                       (key,(void *)idx,(dup_func *)key,ecdh_data_dup,ecdh_data_free);
    if (pEVar2 != (EC_KEY *)0x0) {
      if (*(ENGINE **)(key + 4) != (ENGINE *)0x0) {
        ENGINE_finish(*(ENGINE **)(key + 4));
      }
      CRYPTO_free_ex_data(0xd,key,(CRYPTO_EX_DATA *)(key + 0x10));
      OPENSSL_cleanse(key,0x18);
      CRYPTO_free(key);
      key = pEVar2;
    }
  }
  iVar1 = CRYPTO_set_ex_data((CRYPTO_EX_DATA *)(key + 0x10),(int)arg,in_stack_0000000c);
  return iVar1;
}

