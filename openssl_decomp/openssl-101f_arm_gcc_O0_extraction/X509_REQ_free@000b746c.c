
void X509_REQ_free(X509_REQ *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_X509_REQ_it_000b7474);
  return;
}

