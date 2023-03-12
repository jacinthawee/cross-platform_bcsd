
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_SERVICELOC * OCSP_SERVICELOC_new(void)

{
  OCSP_SERVICELOC *pOVar1;
  
  pOVar1 = (OCSP_SERVICELOC *)ASN1_item_new((ASN1_ITEM *)PTR_OCSP_SERVICELOC_it_000df34c);
  return pOVar1;
}

