
void pkey_free_gost01(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0061a490. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_EC_KEY_free_006a82d8)();
    return;
  }
  return;
}

