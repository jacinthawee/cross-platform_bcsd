
void CONF_modules_unload(int all)

{
  int *ptr;
  int iVar1;
  DSO **ppDVar2;
  
  while (iVar1 = sk_num(initialized_modules), 0 < iVar1) {
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
  iVar1 = sk_num(supported_modules);
  iVar1 = iVar1 + -1;
  if (-1 < iVar1) {
    if (all == 0) {
      do {
        ppDVar2 = (DSO **)sk_value(supported_modules,iVar1);
        if (((int)ppDVar2[4] < 1) && (*ppDVar2 != (DSO *)0x0)) {
          sk_delete(supported_modules,iVar1);
          if (*ppDVar2 != (DSO *)0x0) {
            DSO_free(*ppDVar2);
          }
          CRYPTO_free(ppDVar2[1]);
          CRYPTO_free(ppDVar2);
        }
        iVar1 = iVar1 + -1;
      } while (iVar1 != -1);
    }
    else {
      do {
        ppDVar2 = (DSO **)sk_value(supported_modules,iVar1);
        sk_delete(supported_modules,iVar1);
        if (*ppDVar2 != (DSO *)0x0) {
          DSO_free(*ppDVar2);
        }
        iVar1 = iVar1 + -1;
        CRYPTO_free(ppDVar2[1]);
        CRYPTO_free(ppDVar2);
      } while (iVar1 != -1);
    }
  }
  iVar1 = sk_num(supported_modules);
  if (iVar1 == 0) {
    sk_free(supported_modules);
    supported_modules = (_STACK *)0x0;
  }
  return;
}

