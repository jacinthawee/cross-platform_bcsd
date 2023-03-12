
void X509_free(X509 *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_X509_it_000b544c);
  return;
}

