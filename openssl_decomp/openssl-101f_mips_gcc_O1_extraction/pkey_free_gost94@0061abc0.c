
void pkey_free_gost94(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
                    /* WARNING: Could not recover jumptable at 0x0061abd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_DSA_free_006a862c)();
    return;
  }
  return;
}

