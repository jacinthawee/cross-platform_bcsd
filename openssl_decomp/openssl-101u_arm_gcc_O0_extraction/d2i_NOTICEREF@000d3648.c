
NOTICEREF * d2i_NOTICEREF(NOTICEREF **a,uchar **in,long len)

{
  NOTICEREF *pNVar1;
  
  pNVar1 = (NOTICEREF *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_NOTICEREF_it_000d3650);
  return pNVar1;
}

