
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

OCSP_RESPONSE * OCSP_RESPONSE_new(void)

{
  OCSP_RESPONSE *pOVar1;
  
  pOVar1 = (OCSP_RESPONSE *)ASN1_item_new((ASN1_ITEM *)OCSP_RESPONSE_it);
  return pOVar1;
}
