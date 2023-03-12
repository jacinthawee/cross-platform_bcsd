
int i2d_OCSP_RESPONSE(OCSP_RESPONSE *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_OCSP_RESPONSE_it_000df1c0);
  return iVar1;
}

