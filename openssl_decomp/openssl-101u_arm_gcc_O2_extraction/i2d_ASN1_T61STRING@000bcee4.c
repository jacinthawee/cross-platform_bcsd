
int i2d_ASN1_T61STRING(ASN1_T61STRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_ASN1_T61STRING_it_000bceec);
  return iVar1;
}

