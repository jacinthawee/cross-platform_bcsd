
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_ISSUER_AND_SERIAL * PKCS7_ISSUER_AND_SERIAL_new(void)

{
  PKCS7_ISSUER_AND_SERIAL *pPVar1;
  
  pPVar1 = (PKCS7_ISSUER_AND_SERIAL *)
           ASN1_item_new((ASN1_ITEM *)PTR_PKCS7_ISSUER_AND_SERIAL_it_000d9990);
  return pPVar1;
}

