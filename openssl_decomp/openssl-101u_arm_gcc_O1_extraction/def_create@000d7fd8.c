
void * def_create(int param_1)

{
  void *ptr;
  void *pvVar1;
  
  ptr = CRYPTO_malloc(0x10,"conf_def.c",0x85);
  if ((ptr != (void *)0x0) && (pvVar1 = (void *)(**(code **)(param_1 + 8))(), pvVar1 == (void *)0x0)
     ) {
    CRYPTO_free(ptr);
    ptr = pvVar1;
  }
  return ptr;
}

