
void xptable_free(int param_1)

{
  if ((param_1 != 0) && ((*(uint *)(param_1 + 8) & 1) != 0)) {
    if ((*(uint *)(param_1 + 8) & 2) == 0) {
                    /* WARNING: Could not recover jumptable at 0x00593cb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
      return;
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(param_1 + 0x10));
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(param_1 + 0x14));
                    /* WARNING: Could not recover jumptable at 0x00593cf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_1);
    return;
  }
  return;
}

