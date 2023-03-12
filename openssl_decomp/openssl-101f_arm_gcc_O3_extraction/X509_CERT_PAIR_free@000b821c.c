
void X509_CERT_PAIR_free(X509_CERT_PAIR *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_X509_CERT_PAIR_it_000b8224);
  return;
}

