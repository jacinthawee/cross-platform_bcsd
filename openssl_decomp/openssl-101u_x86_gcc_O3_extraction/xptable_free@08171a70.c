
void xptable_free(void *param_1)

{
  if ((param_1 != (void *)0x0) && ((*(uint *)((int)param_1 + 8) & 1) != 0)) {
    if ((*(uint *)((int)param_1 + 8) & 2) == 0) {
      CRYPTO_free(param_1);
      return;
    }
    CRYPTO_free(*(void **)((int)param_1 + 0x10));
    CRYPTO_free(*(void **)((int)param_1 + 0x14));
    CRYPTO_free(param_1);
    return;
  }
  return;
}

