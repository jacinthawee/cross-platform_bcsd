
ASN1_UNIVERSALSTRING * d2i_ASN1_UNIVERSALSTRING(ASN1_UNIVERSALSTRING **a,uchar **in,long len)

{
  ASN1_UNIVERSALSTRING *pAVar1;
  
  pAVar1 = (ASN1_UNIVERSALSTRING *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASN1_UNIVERSALSTRING_it);
  return pAVar1;
}
