
int i2d_OCSP_CERTID(OCSP_CERTID *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_OCSP_CERTID_it_000e11e8);
  return iVar1;
}

