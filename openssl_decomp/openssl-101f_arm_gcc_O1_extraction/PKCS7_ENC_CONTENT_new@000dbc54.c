
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_ENC_CONTENT * PKCS7_ENC_CONTENT_new(void)

{
  PKCS7_ENC_CONTENT *pPVar1;
  
  pPVar1 = (PKCS7_ENC_CONTENT *)ASN1_item_new((ASN1_ITEM *)PTR_PKCS7_ENC_CONTENT_it_000dbc5c);
  return pPVar1;
}

