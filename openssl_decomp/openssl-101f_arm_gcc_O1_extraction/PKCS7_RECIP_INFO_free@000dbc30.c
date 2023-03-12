
void PKCS7_RECIP_INFO_free(PKCS7_RECIP_INFO *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_PKCS7_RECIP_INFO_it_000dbc38);
  return;
}

