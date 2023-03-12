
void BN_clear_free(BIGNUM *a)

{
  uint uVar1;
  
  if (a == (BIGNUM *)0x0) {
    return;
  }
  if (a->d != (ulong *)0x0) {
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(a->d,a->dmax << 2);
    uVar1 = a->flags;
    if ((uVar1 & 2) != 0) {
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(a,0x14);
      goto joined_r0x004f5b44;
    }
    (*(code *)PTR_CRYPTO_free_006a7f88)(a->d);
  }
  uVar1 = a->flags;
  (*(code *)PTR_OPENSSL_cleanse_006a8174)(a,0x14);
joined_r0x004f5b44:
  if ((uVar1 & 1) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004f5b60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CRYPTO_free_006a7f88)(a);
  return;
}

