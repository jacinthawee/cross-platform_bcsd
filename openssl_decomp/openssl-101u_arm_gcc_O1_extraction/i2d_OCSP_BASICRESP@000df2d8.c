
int i2d_OCSP_BASICRESP(OCSP_BASICRESP *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_OCSP_BASICRESP_it_000df2e0);
  return iVar1;
}

