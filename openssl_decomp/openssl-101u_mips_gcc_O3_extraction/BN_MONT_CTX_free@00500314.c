
void BN_MONT_CTX_free(BN_MONT_CTX *mont)

{
  if (mont != (BN_MONT_CTX *)0x0) {
    BN_clear_free(&mont->RR);
    BN_clear_free(&mont->N);
    BN_clear_free(&mont->Ni);
    if ((mont->flags & 1U) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00500398. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CRYPTO_free_006a6e88)(mont);
      return;
    }
  }
  return;
}

