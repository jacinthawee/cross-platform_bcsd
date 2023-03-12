
void CONF_modules_unload(int all)

{
  int *ptr;
  void *ptr_00;
  int iVar1;
  DSO **ppDVar2;
  _STACK *p_Var3;
  bool bVar4;
  
  while (iVar1 = sk_num(initialized_modules), 0 < iVar1) {
    ptr = (int *)sk_pop(initialized_modules);
    iVar1 = *ptr;
    if (*(code **)(iVar1 + 0xc) != (code *)0x0) {
      (**(code **)(iVar1 + 0xc))();
      iVar1 = *ptr;
    }
    ptr_00 = (void *)ptr[1];
    *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
    CRYPTO_free(ptr_00);
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
        bVar4 = iVar1 != 0;
        iVar1 = iVar1 + -1;
      } while (bVar4);
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
  p_Var3 = (_STACK *)sk_num(supported_modules);
  if (p_Var3 == (_STACK *)0x0) {
    sk_free(supported_modules);
    supported_modules = p_Var3;
  }
  return;
}

