
void BN_MONT_CTX_free(BN_MONT_CTX *mont)

{
  if (mont != (BN_MONT_CTX *)0x0) {
    BN_clear_free(&mont->RR);
    BN_clear_free(&mont->N);
    BN_clear_free(&mont->Ni);
    if ((*(byte *)&mont->flags & 1) != 0) {
      CRYPTO_free(mont);
      return;
    }
  }
  return;
}
