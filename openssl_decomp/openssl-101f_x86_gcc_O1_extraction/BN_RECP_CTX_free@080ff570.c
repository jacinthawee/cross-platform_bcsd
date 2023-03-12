
void BN_RECP_CTX_free(BN_RECP_CTX *recp)

{
  if (recp != (BN_RECP_CTX *)0x0) {
    BN_free(&recp->N);
    BN_free(&recp->Nr);
    if ((*(byte *)&recp->flags & 1) != 0) {
      CRYPTO_free(recp);
      return;
    }
  }
  return;
}

