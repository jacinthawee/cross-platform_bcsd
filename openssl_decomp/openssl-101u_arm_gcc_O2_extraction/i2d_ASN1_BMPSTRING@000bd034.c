
int i2d_ASN1_BMPSTRING(ASN1_BMPSTRING *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_ASN1_BMPSTRING_it_000bd03c);
  return iVar1;
}

