
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_REVOKEDINFO * OCSP_REVOKEDINFO_new(void)

{
  OCSP_REVOKEDINFO *pOVar1;
  
  pOVar1 = (OCSP_REVOKEDINFO *)(*(code *)PTR_ASN1_item_new_006a9778)(OCSP_REVOKEDINFO_it);
  return pOVar1;
}

