
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIST_POINT_NAME * DIST_POINT_NAME_new(void)

{
  DIST_POINT_NAME *pDVar1;
  
  pDVar1 = (DIST_POINT_NAME *)ASN1_item_new((ASN1_ITEM *)PTR_DIST_POINT_NAME_it_000d6560);
  return pDVar1;
}

