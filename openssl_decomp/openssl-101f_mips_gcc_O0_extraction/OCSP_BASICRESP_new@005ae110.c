
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_BASICRESP * OCSP_BASICRESP_new(void)

{
  OCSP_BASICRESP *pOVar1;
  
  pOVar1 = (OCSP_BASICRESP *)(*(code *)PTR_ASN1_item_new_006a9778)(OCSP_BASICRESP_it);
  return pOVar1;
}

