
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS12_MAC_DATA * PKCS12_MAC_DATA_new(void)

{
  PKCS12_MAC_DATA *pPVar1;
  
  pPVar1 = (PKCS12_MAC_DATA *)ASN1_item_new((ASN1_ITEM *)PTR_PKCS12_MAC_DATA_it_000df414);
  return pPVar1;
}

