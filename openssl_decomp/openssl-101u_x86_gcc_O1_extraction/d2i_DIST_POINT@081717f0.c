
DIST_POINT * d2i_DIST_POINT(DIST_POINT **a,uchar **in,long len)

{
  DIST_POINT *pDVar1;
  
  pDVar1 = (DIST_POINT *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)DIST_POINT_it);
  return pDVar1;
}

