
void policy_cache_free(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      policy_data_free();
    }
    if (param_1[1] != 0) {
      (*(code *)PTR_sk_pop_free_006a7058)(param_1[1],PTR_policy_data_free_006a9098);
    }
                    /* WARNING: Could not recover jumptable at 0x005988e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
    return;
  }
  return;
}

