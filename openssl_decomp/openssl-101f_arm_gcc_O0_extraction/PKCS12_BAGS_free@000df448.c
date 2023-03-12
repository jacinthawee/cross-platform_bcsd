
void PKCS12_BAGS_free(PKCS12_BAGS *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_PKCS12_BAGS_it_000df450);
  return;
}

