
ASN1_STRING * d2i_DISPLAYTEXT(ASN1_STRING **a,uchar **in,long len)

{
  ASN1_STRING *pAVar1;
  
  pAVar1 = (ASN1_STRING *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_DISPLAYTEXT_it_000bd0c0);
  return pAVar1;
}
