
ASN1_NULL * d2i_ASN1_NULL(ASN1_NULL **a,uchar **in,long len)

{
  ASN1_NULL *pAVar1;
  
  pAVar1 = (ASN1_NULL *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_ASN1_NULL_it_000bf544);
  return pAVar1;
}

