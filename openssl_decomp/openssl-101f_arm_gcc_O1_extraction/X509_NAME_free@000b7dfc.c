
void X509_NAME_free(X509_NAME *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_X509_NAME_it_000b7e04);
  return;
}

