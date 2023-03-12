
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS12_BAGS * PKCS12_BAGS_new(void)

{
  PKCS12_BAGS *pPVar1;
  
  pPVar1 = (PKCS12_BAGS *)ASN1_item_new((ASN1_ITEM *)PTR_PKCS12_BAGS_it_000df444);
  return pPVar1;
}

