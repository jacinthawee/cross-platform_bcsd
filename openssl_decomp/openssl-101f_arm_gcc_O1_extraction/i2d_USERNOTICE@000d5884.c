
int i2d_USERNOTICE(USERNOTICE *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_USERNOTICE_it_000d588c);
  return iVar1;
}

