
int i2d_NOTICEREF(NOTICEREF *a,uchar **out)

{
  int iVar1;
  
  iVar1 = ASN1_item_i2d((ASN1_VALUE *)a,out,(ASN1_ITEM *)PTR_NOTICEREF_it_000d365c);
  return iVar1;
}

