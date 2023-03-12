
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_CERTSTATUS * OCSP_CERTSTATUS_new(void)

{
  OCSP_CERTSTATUS *pOVar1;
  
  pOVar1 = (OCSP_CERTSTATUS *)ASN1_item_new((ASN1_ITEM *)PTR_OCSP_CERTSTATUS_it_000e1374);
  return pOVar1;
}

