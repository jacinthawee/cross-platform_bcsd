
void free_index(void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (*(TXT_DB **)((int)param_1 + 4) != (TXT_DB *)0x0) {
      TXT_DB_free(*(TXT_DB **)((int)param_1 + 4));
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}

