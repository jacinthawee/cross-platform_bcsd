
void OCSP_REQUEST_free(OCSP_REQUEST *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_OCSP_REQUEST_it_000e1290);
  return;
}

