
void OCSP_BASICRESP_free(OCSP_BASICRESP *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)OCSP_BASICRESP_it);
  return;
}

