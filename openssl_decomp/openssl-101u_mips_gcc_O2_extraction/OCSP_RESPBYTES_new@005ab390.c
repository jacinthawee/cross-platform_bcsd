
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_RESPBYTES * OCSP_RESPBYTES_new(void)

{
  OCSP_RESPBYTES *pOVar1;
  
  pOVar1 = (OCSP_RESPBYTES *)(*(code *)PTR_ASN1_item_new_006a8654)(OCSP_RESPBYTES_it);
  return pOVar1;
}

