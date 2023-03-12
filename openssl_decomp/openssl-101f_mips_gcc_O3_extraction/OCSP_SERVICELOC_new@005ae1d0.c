
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_SERVICELOC * OCSP_SERVICELOC_new(void)

{
  OCSP_SERVICELOC *pOVar1;
  
  pOVar1 = (OCSP_SERVICELOC *)(*(code *)PTR_ASN1_item_new_006a9778)(OCSP_SERVICELOC_it);
  return pOVar1;
}

