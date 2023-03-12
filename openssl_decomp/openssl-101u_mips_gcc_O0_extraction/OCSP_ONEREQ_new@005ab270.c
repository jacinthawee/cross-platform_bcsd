
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_ONEREQ * OCSP_ONEREQ_new(void)

{
  OCSP_ONEREQ *pOVar1;
  
  pOVar1 = (OCSP_ONEREQ *)(*(code *)PTR_ASN1_item_new_006a8654)(OCSP_ONEREQ_it);
  return pOVar1;
}

