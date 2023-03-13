
void * def_create(int param_1)

{
  void *ptr;
  int iVar1;
  void *pvVar2;
  
  ptr = CRYPTO_malloc(0x10,"conf_def.c",0x85);
  pvVar2 = ptr;
  if (ptr != (void *)0x0) {
    iVar1 = (**(code **)(param_1 + 8))(ptr);
    if (iVar1 == 0) {
      pvVar2 = (void *)0x0;
      CRYPTO_free(ptr);
    }
  }
  return pvVar2;
}

