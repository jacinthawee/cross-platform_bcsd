
void NETSCAPE_X509_free(NETSCAPE_X509 *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)NETSCAPE_X509_it);
  return;
}

