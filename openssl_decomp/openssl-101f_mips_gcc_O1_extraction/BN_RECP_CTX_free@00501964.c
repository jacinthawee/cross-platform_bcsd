
void BN_RECP_CTX_free(BN_RECP_CTX *recp)

{
  if (recp != (BN_RECP_CTX *)0x0) {
    BN_free(&recp->N);
    BN_free(&recp->Nr);
    if ((recp->flags & 1U) != 0) {
                    /* WARNING: Could not recover jumptable at 0x005019d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CRYPTO_free_006a7f88)(recp);
      return;
    }
  }
  return;
}

