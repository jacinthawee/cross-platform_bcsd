
void cmac_key_free(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
                    /* WARNING: Could not recover jumptable at 0x005c9f0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CMAC_CTX_free_006a9518)();
    return;
  }
  return;
}
