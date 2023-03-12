
int i2d_OCSP_RESPID(OCSP_RESPID *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_OCSP_RESPID_it_000e1308);
  return iVar1;
}

