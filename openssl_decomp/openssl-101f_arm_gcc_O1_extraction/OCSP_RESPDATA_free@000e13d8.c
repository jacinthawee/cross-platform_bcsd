
void OCSP_RESPDATA_free(OCSP_RESPDATA *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_OCSP_RESPDATA_it_000e13e0);
  return;
}

