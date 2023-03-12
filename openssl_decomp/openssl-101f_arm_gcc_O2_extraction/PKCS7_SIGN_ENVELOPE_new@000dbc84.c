
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_SIGN_ENVELOPE * PKCS7_SIGN_ENVELOPE_new(void)

{
  PKCS7_SIGN_ENVELOPE *pPVar1;
  
  pPVar1 = (PKCS7_SIGN_ENVELOPE *)ASN1_item_new((ASN1_ITEM *)PTR_PKCS7_SIGN_ENVELOPE_it_000dbc8c);
  return pPVar1;
}

