
CRL_DIST_POINTS * d2i_CRL_DIST_POINTS(CRL_DIST_POINTS **a,uchar **in,long len)

{
  CRL_DIST_POINTS *pCVar1;
  
  pCVar1 = (CRL_DIST_POINTS *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)CRL_DIST_POINTS_it)
  ;
  return pCVar1;
}

