
int i2d_NETSCAPE_SPKI(NETSCAPE_SPKI *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_NETSCAPE_SPKI_it_000b5e20);
  return iVar1;
}

