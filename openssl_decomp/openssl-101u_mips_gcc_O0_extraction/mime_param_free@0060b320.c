
void mime_param_free(int *param_1)

{
  if (*param_1 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  if (param_1[1] != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
                    /* WARNING: Could not recover jumptable at 0x0060b37c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
  return;
}

