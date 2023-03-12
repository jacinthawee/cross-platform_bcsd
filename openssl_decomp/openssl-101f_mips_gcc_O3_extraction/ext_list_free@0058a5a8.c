
void ext_list_free(int param_1)

{
  if ((*(uint *)(param_1 + 4) & 1) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0058a5c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)();
  return;
}

