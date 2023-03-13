
void free_string(int *param_1)

{
  if ((*(byte *)(param_1 + 7) & 1) != 0) {
    CRYPTO_free((void *)param_1[1]);
    if (*param_1 == 3) {
      CRYPTO_free((void *)param_1[4]);
      CRYPTO_free((void *)param_1[5]);
      CRYPTO_free((void *)param_1[6]);
      CRYPTO_free(param_1);
      return;
    }
  }
  CRYPTO_free(param_1);
  return;
}

