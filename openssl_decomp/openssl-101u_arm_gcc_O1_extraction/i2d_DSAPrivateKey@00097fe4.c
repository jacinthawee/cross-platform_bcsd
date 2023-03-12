
int i2d_DSAPrivateKey(DSA *a,uchar **pp)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,pp,(ASN1_ITEM *)PTR_DSAPrivateKey_it_00097fec);
  return iVar1;
}

