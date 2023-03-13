
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void CONF_modules_free(void)

{
  int *ptr;
  int iVar1;
  
  while( true ) {
    iVar1 = sk_num(initialized_modules);
    if (iVar1 < 1) break;
    ptr = (int *)sk_pop(initialized_modules);
    iVar1 = *ptr;
    if (*(code **)(iVar1 + 0xc) != (code *)0x0) {
      (**(code **)(iVar1 + 0xc))(ptr);
      iVar1 = *ptr;
    }
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
    CRYPTO_free((void *)ptr[1]);
    CRYPTO_free((void *)ptr[2]);
    CRYPTO_free(ptr);
  }
  sk_free(initialized_modules);
  initialized_modules = (_STACK *)0x0;
  CONF_modules_unload(1);
  return;
}

