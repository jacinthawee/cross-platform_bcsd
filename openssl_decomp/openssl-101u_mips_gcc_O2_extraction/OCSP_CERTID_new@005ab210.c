
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_CERTID * OCSP_CERTID_new(void)

{
  OCSP_CERTID *pOVar1;
  
  pOVar1 = (OCSP_CERTID *)(*(code *)PTR_ASN1_item_new_006a8654)(OCSP_CERTID_it);
  return pOVar1;
}

