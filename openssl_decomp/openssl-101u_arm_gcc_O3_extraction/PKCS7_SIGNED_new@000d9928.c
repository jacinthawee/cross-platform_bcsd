
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_SIGNED * PKCS7_SIGNED_new(void)

{
  PKCS7_SIGNED *pPVar1;
  
  pPVar1 = (PKCS7_SIGNED *)ASN1_item_new((ASN1_ITEM *)PTR_PKCS7_SIGNED_it_000d9930);
  return pPVar1;
}

