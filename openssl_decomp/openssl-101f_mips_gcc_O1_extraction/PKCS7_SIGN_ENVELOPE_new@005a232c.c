
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_SIGN_ENVELOPE * PKCS7_SIGN_ENVELOPE_new(void)

{
  PKCS7_SIGN_ENVELOPE *pPVar1;
  
  pPVar1 = (PKCS7_SIGN_ENVELOPE *)(*(code *)PTR_ASN1_item_new_006a9778)(PKCS7_SIGN_ENVELOPE_it);
  return pPVar1;
}

