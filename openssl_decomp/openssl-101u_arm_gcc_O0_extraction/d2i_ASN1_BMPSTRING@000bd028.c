
ASN1_BMPSTRING * d2i_ASN1_BMPSTRING(ASN1_BMPSTRING **a,uchar **in,long len)

{
  ASN1_BMPSTRING *pAVar1;
  
  pAVar1 = (ASN1_BMPSTRING *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_ASN1_BMPSTRING_it_000bd030);
  return pAVar1;
}

