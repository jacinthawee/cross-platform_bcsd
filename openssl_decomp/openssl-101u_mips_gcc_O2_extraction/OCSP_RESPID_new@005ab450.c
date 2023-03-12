
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_RESPID * OCSP_RESPID_new(void)

{
  OCSP_RESPID *pOVar1;
  
  pOVar1 = (OCSP_RESPID *)(*(code *)PTR_ASN1_item_new_006a8654)(OCSP_RESPID_it);
  return pOVar1;
}

