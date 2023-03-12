
int i2d_DISPLAYTEXT(ASN1_STRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_DISPLAYTEXT_it_000bf7c0);
  return iVar1;
}

