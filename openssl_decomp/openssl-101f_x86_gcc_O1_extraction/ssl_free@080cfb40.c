
undefined4 ssl_free(int param_1)

{
  SSL **ppSVar1;
  SSL *pSVar2;
  
  if (param_1 != 0) {
    ppSVar1 = *(SSL ***)(param_1 + 0x20);
    pSVar2 = *ppSVar1;
    if (pSVar2 != (SSL *)0x0) {
      SSL_shutdown(pSVar2);
    }
    if (*(int *)(param_1 + 0x10) != 0) {
      if ((*(int *)(param_1 + 0xc) != 0) && (pSVar2 = *ppSVar1, pSVar2 != (SSL *)0x0)) {
        SSL_free(pSVar2);
      }
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    if (*(void **)(param_1 + 0x20) != (void *)0x0) {
      CRYPTO_free(*(void **)(param_1 + 0x20));
    }
    return 1;
  }
  return 0;
}

