
void cleanup(EVP_PKEY_CTX *ctx)

{
  if (*(int *)ctx == 1) {
    X509_free(*(X509 **)(ctx + 4));
  }
  else if (*(int *)ctx == 2) {
    X509_CRL_free(*(X509_CRL **)(ctx + 4));
    CRYPTO_free(ctx);
    return;
  }
  CRYPTO_free(ctx);
  return;
}

