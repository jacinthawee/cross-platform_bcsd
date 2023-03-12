
int i2d_CRL_DIST_POINTS(CRL_DIST_POINTS *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_CRL_DIST_POINTS_it_000d65a8);
  return iVar1;
}

