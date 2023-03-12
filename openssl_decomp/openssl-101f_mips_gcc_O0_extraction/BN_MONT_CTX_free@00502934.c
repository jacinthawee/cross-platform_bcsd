
void BN_MONT_CTX_free(BN_MONT_CTX *mont)

{
  if (mont != (BN_MONT_CTX *)0x0) {
    BN_free(&mont->RR);
    BN_free(&mont->N);
    BN_free(&mont->Ni);
    if ((mont->flags & 1U) != 0) {
                    /* WARNING: Could not recover jumptable at 0x005029b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CRYPTO_free_006a7f88)(mont);
      return;
    }
  }
  return;
}

