
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_RESPONSE * OCSP_RESPONSE_new(void)

{
  OCSP_RESPONSE *pOVar1;
  
  pOVar1 = (OCSP_RESPONSE *)(*(code *)PTR_ASN1_item_new_006a9778)(OCSP_RESPONSE_it);
  return pOVar1;
}

