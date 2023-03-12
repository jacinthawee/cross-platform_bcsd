
int i2d_OTHERNAME(OTHERNAME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_OTHERNAME_it_000d09f8);
  return iVar1;
}

