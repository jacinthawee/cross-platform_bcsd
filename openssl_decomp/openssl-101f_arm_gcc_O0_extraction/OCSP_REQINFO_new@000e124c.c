
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_REQINFO * OCSP_REQINFO_new(void)

{
  OCSP_REQINFO *pOVar1;
  
  pOVar1 = (OCSP_REQINFO *)ASN1_item_new((ASN1_ITEM *)PTR_OCSP_REQINFO_it_000e1254);
  return pOVar1;
}

