
DSA * d2i_DSAparams(DSA **a,uchar **pp,long length)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_item_d2i((ASN1_VALUE **)a,pp,length,(ASN1_ITEM *)PTR_DSAparams_it_0009988c);
  return pDVar1;
}

