
int i2d_OCSP_CRLID(OCSP_CRLID *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_OCSP_CRLID_it_000df310);
  return iVar1;
}

