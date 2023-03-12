
void PKCS12_MAC_DATA_free(PKCS12_MAC_DATA *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_PKCS12_MAC_DATA_it_000df420);
  return;
}

