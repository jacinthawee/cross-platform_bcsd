
int i2d_ASN1_NULL(ASN1_NULL *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)ASN1_NULL_it);
  return iVar1;
}

