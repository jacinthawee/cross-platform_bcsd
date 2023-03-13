
void free_string(int *param_1)

{
  if ((param_1[7] & 1U) != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_1[1]);
    if (*param_1 == 3) {
      (*(code *)PTR_CRYPTO_free_006a6e88)(param_1[4]);
      (*(code *)PTR_CRYPTO_free_006a6e88)(param_1[5]);
      (*(code *)PTR_CRYPTO_free_006a6e88)(param_1[6]);
                    /* WARNING: Could not recover jumptable at 0x005b08cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x005b0868. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
  return;
}

