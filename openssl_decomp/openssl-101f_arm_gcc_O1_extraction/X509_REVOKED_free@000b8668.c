
void X509_REVOKED_free(X509_REVOKED *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_X509_REVOKED_it_000b8670);
  return;
}
