
void BIO_CONNECT_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (*(void **)((int)param_1 + 4) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)param_1 + 4));
    }
    if (*(void **)((int)param_1 + 8) != (void *)0x0) {
      CRYPTO_free(*(void **)((int)param_1 + 8));
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}

