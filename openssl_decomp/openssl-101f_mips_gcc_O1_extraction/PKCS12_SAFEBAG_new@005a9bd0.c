
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PKCS12_SAFEBAG * PKCS12_SAFEBAG_new(void)

{
  PKCS12_SAFEBAG *pPVar1;
  
  pPVar1 = (PKCS12_SAFEBAG *)(*(code *)PTR_ASN1_item_new_006a9778)(PKCS12_SAFEBAG_it);
  return pPVar1;
}

