
void free_dir(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1[1] != 0) {
    (*(code *)PTR_sk_pop_free_006a7058)(piVar1[1],by_dir_entry_free);
  }
  if (*piVar1 != 0) {
    (*(code *)PTR_BUF_MEM_free_006a7494)();
  }
                    /* WARNING: Could not recover jumptable at 0x00584d78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a6e88)(piVar1);
  return;
}

