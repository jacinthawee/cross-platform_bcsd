
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS12_SAFEBAG * PKCS12_SAFEBAG_new(void)

{
  PKCS12_SAFEBAG *pPVar1;
  
  pPVar1 = (PKCS12_SAFEBAG *)ASN1_item_new((ASN1_ITEM *)PTR_PKCS12_SAFEBAG_it_000dd3c8);
  return pPVar1;
}

