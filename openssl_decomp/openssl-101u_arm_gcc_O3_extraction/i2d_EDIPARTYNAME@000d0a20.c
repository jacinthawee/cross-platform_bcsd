
int i2d_EDIPARTYNAME(EDIPARTYNAME *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_EDIPARTYNAME_it_000d0a28);
  return iVar1;
}

