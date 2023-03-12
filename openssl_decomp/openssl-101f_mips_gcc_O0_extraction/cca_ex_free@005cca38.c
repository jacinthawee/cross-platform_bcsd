
void cca_ex_free(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x005cca48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(param_2);
    return;
  }
  return;
}

