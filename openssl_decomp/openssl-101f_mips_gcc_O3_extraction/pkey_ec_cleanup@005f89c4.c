
void pkey_ec_cleanup(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x14);
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != 0) {
      (*(code *)PTR_EC_GROUP_free_006a829c)();
    }
                    /* WARNING: Could not recover jumptable at 0x005f8a0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(piVar1);
    return;
  }
  return;
}

