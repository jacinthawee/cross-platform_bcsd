
void * __regparm1
EC_KEY_get_key_method_data
          (EC_KEY *key,dup_func *dup_func,free_func *free_func,clear_free_func *clear_free_func)

{
  void *mode;
  undefined4 in_stack_00000010;
  
  CRYPTO_lock((int)key,5,(char *)0x21,(int)"ec_key.c");
  mode = (void *)EC_EX_DATA_get_data(*(undefined4 *)(dup_func + 0x20),free_func,clear_free_func,
                                     in_stack_00000010);
  CRYPTO_lock((int)mode,6,(char *)0x21,(int)"ec_key.c");
  return mode;
}

