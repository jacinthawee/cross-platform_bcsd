
ASN1_SEQUENCE_ANY * d2i_ASN1_SET_ANY(ASN1_SEQUENCE_ANY **a,uchar **in,long len)

{
  ASN1_SEQUENCE_ANY *pAVar1;
  
  pAVar1 = (ASN1_SEQUENCE_ANY *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_ASN1_SET_ANY_it_000bf82c);
  return pAVar1;
}

