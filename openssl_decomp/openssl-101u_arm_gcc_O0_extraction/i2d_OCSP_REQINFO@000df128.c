
int i2d_OCSP_REQINFO(OCSP_REQINFO *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_OCSP_REQINFO_it_000df130);
  return iVar1;
}

