
undefined4 buffer_free(int param_1)

{
  int iVar1;
  void *pvVar2;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x20);
    pvVar2 = *(void **)(iVar1 + 8);
    if (pvVar2 != (void *)0x0) {
      CRYPTO_free(pvVar2);
    }
    pvVar2 = *(void **)(iVar1 + 0x14);
    if (pvVar2 != (void *)0x0) {
      CRYPTO_free(pvVar2);
    }
    CRYPTO_free(*(void **)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  return 0;
}

