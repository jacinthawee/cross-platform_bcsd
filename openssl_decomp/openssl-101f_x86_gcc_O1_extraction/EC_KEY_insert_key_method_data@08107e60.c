
void * __regparm1
EC_KEY_insert_key_method_data
          (EC_KEY *key,void *data,dup_func *dup_func,free_func *free_func,
          clear_free_func *clear_free_func)

{
  void *pvVar1;
  void *mode;
  
  CRYPTO_lock((int)key,9,(char *)0x21,(int)"ec_key.c");
  pvVar1 = (void *)EC_EX_DATA_get_data(*(undefined4 *)((int)data + 0x20),free_func,clear_free_func);
  mode = pvVar1;
  if (pvVar1 == (void *)0x0) {
    mode = (void *)EC_EX_DATA_set_data((int)data + 0x20,dup_func,free_func,clear_free_func);
  }
  CRYPTO_lock((int)mode,10,(char *)0x21,(int)"ec_key.c");
  return pvVar1;
}

