
void PKCS12_SAFEBAG_free(PKCS12_SAFEBAG *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)PTR_PKCS12_SAFEBAG_it_000dd3d4);
  return;
}

