
void TS_VERIFY_CTX_cleanup(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  X509_STORE_free(*(X509_STORE **)(param_1 + 4));
  sk_pop_free(*(_STACK **)(param_1 + 8),X509_free + 1);
  ASN1_OBJECT_free(*(ASN1_OBJECT **)(param_1 + 0xc));
  X509_ALGOR_free(*(X509_ALGOR **)(param_1 + 0x10));
  CRYPTO_free(*(void **)(param_1 + 0x14));
  BIO_free_all(*(BIO **)(param_1 + 0x1c));
  ASN1_INTEGER_free(*(ASN1_INTEGER **)(param_1 + 0x20));
  GENERAL_NAME_free(*(GENERAL_NAME **)(param_1 + 0x24));
  (*(code *)PTR_memset_0018a15c)(param_1,0,0x28);
  return;
}

