
void DSA_SIG_free(DSA_SIG *a)

{
  if (a != (DSA_SIG *)0x0) {
    if (a->r != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
    if (a->s != (BIGNUM *)0x0) {
      (*(code *)PTR_BN_free_006a811c)();
    }
                    /* WARNING: Could not recover jumptable at 0x00515bdc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a7f88)(a);
    return;
  }
  return;
}

