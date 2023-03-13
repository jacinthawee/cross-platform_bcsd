
void X509_CRL_METHOD_free(byte *param_1)

{
  if ((*param_1 & 1) == 0) {
    return;
  }
  CRYPTO_free(param_1);
  return;
}

