
DSA * DSAparams_dup(DSA *x)

{
  DSA *pDVar1;
  
  pDVar1 = (DSA *)ASN1_item_dup((ASN1_ITEM *)PTR_DSAparams_it_00098028,x);
  return pDVar1;
}

