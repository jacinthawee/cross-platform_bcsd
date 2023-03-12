
void TS_VERIFY_CTX_free(void *param_1)

{
  if (param_1 != (void *)0x0) {
    X509_STORE_free(*(X509_STORE **)((int)param_1 + 4));
    sk_pop_free(*(_STACK **)((int)param_1 + 8),X509_free + 1);
    ASN1_OBJECT_free(*(ASN1_OBJECT **)((int)param_1 + 0xc));
    X509_ALGOR_free(*(X509_ALGOR **)((int)param_1 + 0x10));
    CRYPTO_free(*(void **)((int)param_1 + 0x14));
    BIO_free_all(*(BIO **)((int)param_1 + 0x1c));
    ASN1_INTEGER_free(*(ASN1_INTEGER **)((int)param_1 + 0x20));
    GENERAL_NAME_free(*(GENERAL_NAME **)((int)param_1 + 0x24));
    memset(param_1,0,0x28);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

