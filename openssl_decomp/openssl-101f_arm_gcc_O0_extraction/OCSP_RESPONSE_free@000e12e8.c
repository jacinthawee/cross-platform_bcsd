
void OCSP_RESPONSE_free(OCSP_RESPONSE *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_OCSP_RESPONSE_it_000e12f0);
  return;
}

