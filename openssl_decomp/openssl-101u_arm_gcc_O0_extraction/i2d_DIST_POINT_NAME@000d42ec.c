
int i2d_DIST_POINT_NAME(DIST_POINT_NAME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_DIST_POINT_NAME_it_000d42f4);
  return iVar1;
}

