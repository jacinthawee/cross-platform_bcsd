
void * EC_KEY_get_key_method_data
                 (EC_KEY *key,dup_func *dup_func,free_func *free_func,
                 clear_free_func *clear_free_func)

{
  void *pvVar1;
  
  (*(code *)PTR_CRYPTO_lock_006a8144)(5,0x21,"ec_key.c",0x1fd);
  pvVar1 = (void *)EC_EX_DATA_get_data(*(undefined4 *)(key + 0x20),dup_func,free_func,
                                       clear_free_func);
  (*(code *)PTR_CRYPTO_lock_006a8144)(6,0x21,"ec_key.c",0x201);
  return pvVar1;
}

