
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_REQINFO * OCSP_REQINFO_new(void)

{
  OCSP_REQINFO *pOVar1;
  
  pOVar1 = (OCSP_REQINFO *)(*(code *)PTR_ASN1_item_new_006a8654)(OCSP_REQINFO_it);
  return pOVar1;
}

