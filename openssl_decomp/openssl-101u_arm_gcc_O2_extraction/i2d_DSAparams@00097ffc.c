
int i2d_DSAparams(DSA *a,uchar **pp)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,pp,(ASN1_ITEM *)PTR_DSAparams_it_00098004);
  return iVar1;
}

