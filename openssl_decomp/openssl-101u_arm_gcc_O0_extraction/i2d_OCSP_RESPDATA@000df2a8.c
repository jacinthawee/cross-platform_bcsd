
int i2d_OCSP_RESPDATA(OCSP_RESPDATA *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_OCSP_RESPDATA_it_000df2b0);
  return iVar1;
}

