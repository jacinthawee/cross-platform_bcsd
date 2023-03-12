
DSA * d2i_DSAPrivateKey(DSA **a,uchar **pp,long length)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_item_d2i((ASN1_VALUE **)a,pp,length,
                                (ASN1_ITEM *)PTR_DSAPrivateKey_it_00099874);
  return pDVar1;
}

