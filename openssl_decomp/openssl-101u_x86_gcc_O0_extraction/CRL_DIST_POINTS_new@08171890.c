
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CRL_DIST_POINTS * CRL_DIST_POINTS_new(void)

{
  CRL_DIST_POINTS *pCVar1;
  
  pCVar1 = (CRL_DIST_POINTS *)ASN1_item_new((ASN1_ITEM *)CRL_DIST_POINTS_it);
  return pCVar1;
}

