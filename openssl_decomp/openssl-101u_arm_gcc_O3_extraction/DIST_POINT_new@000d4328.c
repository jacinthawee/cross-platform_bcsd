
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DIST_POINT * DIST_POINT_new(void)

{
  DIST_POINT *pDVar1;
  
  pDVar1 = (DIST_POINT *)ASN1_item_new((ASN1_ITEM *)PTR_DIST_POINT_it_000d4330);
  return pDVar1;
}

