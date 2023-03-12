
undefined4 ssl_free(int param_1)

{
  SSL *pSVar1;
  SSL **ppSVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  ppSVar2 = *(SSL ***)(param_1 + 0x20);
  pSVar1 = *ppSVar2;
  if (pSVar1 != (SSL *)0x0) {
    SSL_shutdown(pSVar1);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    if ((*(int *)(param_1 + 0xc) != 0) && (pSVar1 = *ppSVar2, pSVar1 != (SSL *)0x0)) {
      SSL_free(pSVar1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  if (*(void **)(param_1 + 0x20) != (void *)0x0) {
    CRYPTO_free(*(void **)(param_1 + 0x20));
    return 1;
  }
  return 1;
}

