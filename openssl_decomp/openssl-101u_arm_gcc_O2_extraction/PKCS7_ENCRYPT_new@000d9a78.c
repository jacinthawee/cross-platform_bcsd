
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_ENCRYPT * PKCS7_ENCRYPT_new(void)

{
  PKCS7_ENCRYPT *pPVar1;
  
  pPVar1 = (PKCS7_ENCRYPT *)ASN1_item_new((ASN1_ITEM *)PTR_PKCS7_ENCRYPT_it_000d9a80);
  return pPVar1;
}

