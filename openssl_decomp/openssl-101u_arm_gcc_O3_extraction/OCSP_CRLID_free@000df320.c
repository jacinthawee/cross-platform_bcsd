
void OCSP_CRLID_free(OCSP_CRLID *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_OCSP_CRLID_it_000df328);
  return;
}

