
void by_dir_entry_free(int *param_1)

{
  if (*param_1 != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  if (param_1[2] != 0) {
    (*(code *)PTR_sk_pop_free_006a8158)(param_1[2],by_dir_hash_free);
  }
                    /* WARNING: Could not recover jumptable at 0x00587aa0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(param_1);
  return;
}

