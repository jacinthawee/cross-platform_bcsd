
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_DIGEST * PKCS7_DIGEST_new(void)

{
  PKCS7_DIGEST *pPVar1;
  
  pPVar1 = (PKCS7_DIGEST *)(*(code *)PTR_ASN1_item_new_006a9778)(PKCS7_DIGEST_it);
  return pPVar1;
}
