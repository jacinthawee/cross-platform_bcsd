
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_RESPID * OCSP_RESPID_new(void)

{
  OCSP_RESPID *pOVar1;
  
  pOVar1 = (OCSP_RESPID *)ASN1_item_new((ASN1_ITEM *)PTR_OCSP_RESPID_it_000df1fc);
  return pOVar1;
}

