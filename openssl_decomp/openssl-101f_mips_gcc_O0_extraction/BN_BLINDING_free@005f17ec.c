
void BN_BLINDING_free(BN_BLINDING *b)

{
  if (b != (BN_BLINDING *)0x0) {
    if (*(int *)b != 0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    if (*(int *)(b + 4) != 0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    if (*(int *)(b + 8) != 0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    if (*(int *)(b + 0xc) != 0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
                    /* WARNING: Could not recover jumptable at 0x005f1880. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(b);
    return;
  }
  return;
}

