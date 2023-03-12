
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_RESPBYTES * OCSP_RESPBYTES_new(void)

{
  OCSP_RESPBYTES *pOVar1;
  
  pOVar1 = (OCSP_RESPBYTES *)ASN1_item_new((ASN1_ITEM *)PTR_OCSP_RESPBYTES_it_000df19c);
  return pOVar1;
}

