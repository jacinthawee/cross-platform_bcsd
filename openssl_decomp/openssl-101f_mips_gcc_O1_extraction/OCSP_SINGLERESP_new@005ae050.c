
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_SINGLERESP * OCSP_SINGLERESP_new(void)

{
  OCSP_SINGLERESP *pOVar1;
  
  pOVar1 = (OCSP_SINGLERESP *)(*(code *)PTR_ASN1_item_new_006a9778)(OCSP_SINGLERESP_it);
  return pOVar1;
}

