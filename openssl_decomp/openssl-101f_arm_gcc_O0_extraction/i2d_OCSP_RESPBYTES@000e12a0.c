
int i2d_OCSP_RESPBYTES(OCSP_RESPBYTES *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_OCSP_RESPBYTES_it_000e12a8);
  return iVar1;
}

