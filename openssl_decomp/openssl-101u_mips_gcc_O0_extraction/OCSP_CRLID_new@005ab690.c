
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_CRLID * OCSP_CRLID_new(void)

{
  OCSP_CRLID *pOVar1;
  
  pOVar1 = (OCSP_CRLID *)(*(code *)PTR_ASN1_item_new_006a8654)(OCSP_CRLID_it);
  return pOVar1;
}

