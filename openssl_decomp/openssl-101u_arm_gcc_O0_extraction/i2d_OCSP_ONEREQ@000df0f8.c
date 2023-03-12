
int i2d_OCSP_ONEREQ(OCSP_ONEREQ *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_OCSP_ONEREQ_it_000df100);
  return iVar1;
}

