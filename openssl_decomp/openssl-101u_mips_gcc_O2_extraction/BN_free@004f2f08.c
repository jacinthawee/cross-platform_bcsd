
void BN_free(BIGNUM *a)

{
  uint uVar1;
  
  if (a != (BIGNUM *)0x0) {
    uVar1 = a->flags;
    if ((a->d != (ulong *)0x0) && ((uVar1 & 2) == 0)) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
      uVar1 = a->flags;
    }
    if ((uVar1 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x004f2f98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CRYPTO_free_006a6e88)(a);
      return;
    }
    a->d = (ulong *)0x0;
    a->flags = uVar1 | 0x8000;
  }
  return;
}

