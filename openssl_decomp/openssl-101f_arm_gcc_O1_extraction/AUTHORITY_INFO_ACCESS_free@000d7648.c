
void AUTHORITY_INFO_ACCESS_free(AUTHORITY_INFO_ACCESS *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_AUTHORITY_INFO_ACCESS_it_000d7650);
  return;
}
