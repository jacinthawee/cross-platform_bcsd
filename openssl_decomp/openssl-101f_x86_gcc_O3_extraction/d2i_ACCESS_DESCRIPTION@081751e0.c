
ACCESS_DESCRIPTION * d2i_ACCESS_DESCRIPTION(ACCESS_DESCRIPTION **a,uchar **in,long len)

{
  ACCESS_DESCRIPTION *pAVar1;
  
  pAVar1 = (ACCESS_DESCRIPTION *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ACCESS_DESCRIPTION_it);
  return pAVar1;
}
