
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS7_RECIP_INFO * PKCS7_RECIP_INFO_new(void)

{
  PKCS7_RECIP_INFO *pPVar1;
  
  pPVar1 = (PKCS7_RECIP_INFO *)(*(code *)PTR_ASN1_item_new_006a8654)(PKCS7_RECIP_INFO_it);
  return pPVar1;
}
