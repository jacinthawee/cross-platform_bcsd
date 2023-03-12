
int i2d_ASN1_NULL(ASN1_NULL *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_ASN1_NULL_it_000bce5c);
  return iVar1;
}

