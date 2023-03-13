
void ASN1_STRING_clear_free(size_t *param_1)

{
  if (param_1 == (size_t *)0x0) {
    return;
  }
  if (((void *)param_1[2] != (void *)0x0) && ((*(byte *)(param_1 + 3) & 0x10) == 0)) {
    OPENSSL_cleanse((void *)param_1[2],*param_1);
    if (((void *)param_1[2] != (void *)0x0) && ((*(byte *)(param_1 + 3) & 0x10) == 0)) {
      CRYPTO_free((void *)param_1[2]);
      CRYPTO_free(param_1);
      return;
    }
  }
  CRYPTO_free(param_1);
  return;
}

