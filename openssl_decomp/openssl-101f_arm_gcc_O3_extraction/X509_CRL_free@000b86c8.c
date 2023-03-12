
void X509_CRL_free(X509_CRL *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_X509_CRL_it_000b86d0);
  return;
}

