
ASN1_BIT_STRING * d2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a,uchar **in,long len)

{
  ASN1_BIT_STRING *pAVar1;
  
  pAVar1 = (ASN1_BIT_STRING *)ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)ASN1_BIT_STRING_it)
  ;
  return pAVar1;
}
