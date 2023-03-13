
void st_free(void *param_1)

{
  if ((*(byte *)((int)param_1 + 0x10) & 1) == 0) {
    return;
  }
  CRYPTO_free(param_1);
  return;
}

