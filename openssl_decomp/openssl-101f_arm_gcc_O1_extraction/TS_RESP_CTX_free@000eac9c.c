
void TS_RESP_CTX_free(X509 **param_1)

{
  if (param_1 != (X509 **)0x0) {
    X509_free(*param_1);
    EVP_PKEY_free((EVP_PKEY *)param_1[1]);
    sk_pop_free((_STACK *)param_1[2],X509_free);
    sk_pop_free((_STACK *)param_1[3],ASN1_OBJECT_free);
    ASN1_OBJECT_free((ASN1_OBJECT *)param_1[4]);
    sk_free((_STACK *)param_1[5]);
    ASN1_INTEGER_free((ASN1_INTEGER *)param_1[6]);
    ASN1_INTEGER_free((ASN1_INTEGER *)param_1[7]);
    ASN1_INTEGER_free((ASN1_INTEGER *)param_1[8]);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

