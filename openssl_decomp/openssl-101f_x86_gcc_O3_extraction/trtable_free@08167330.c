
void trtable_free(void *param_1)

{
  if ((param_1 != (void *)0x0) && ((*(uint *)((int)param_1 + 4) & 1) != 0)) {
    if ((*(uint *)((int)param_1 + 4) & 2) == 0) {
      CRYPTO_free(param_1);
      return;
    }
    CRYPTO_free(*(void **)((int)param_1 + 0xc));
    CRYPTO_free(param_1);
    return;
  }
  return;
}

