
void BIO_CONNECT_free(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 4) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    if (*(int *)(param_1 + 8) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
                    /* WARNING: Could not recover jumptable at 0x0052389c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
    return;
  }
  return;
}

