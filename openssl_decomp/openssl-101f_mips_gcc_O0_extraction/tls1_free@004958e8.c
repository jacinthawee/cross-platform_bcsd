
void tls1_free(int param_1)

{
  if (*(int *)(param_1 + 0x15c) != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  ssl3_free(param_1);
  return;
}

