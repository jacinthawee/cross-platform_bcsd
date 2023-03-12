
void * EC_KEY_insert_key_method_data
                 (EC_KEY *key,void *data,dup_func *dup_func,free_func *free_func,
                 clear_free_func *clear_free_func)

{
  void *pvVar1;
  
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0x21,"ec_key.c",0x219);
  pvVar1 = (void *)EC_EX_DATA_get_data(*(undefined4 *)(key + 0x20),dup_func,free_func,
                                       clear_free_func);
  if (pvVar1 == (void *)0x0) {
    EC_EX_DATA_set_data(key + 0x20,data,dup_func,free_func,clear_free_func);
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(10,0x21,"ec_key.c",0x21d);
  return pvVar1;
}

