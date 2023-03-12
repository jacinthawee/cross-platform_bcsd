
void free_index(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 4) != 0) {
      (*(code *)PTR_TXT_DB_free_006a7bf4)();
    }
                    /* WARNING: Could not recover jumptable at 0x0045d694. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
    return;
  }
  return;
}

