
X509_EXTENSIONS * d2i_X509_EXTENSIONS(X509_EXTENSIONS **a,uchar **in,long len)

{
  X509_EXTENSIONS *pXVar1;
  
  pXVar1 = (X509_EXTENSIONS *)
           ASN1_item_d2i((ASN1_VALUE **)a,in,len,(ASN1_ITEM *)PTR_X509_EXTENSIONS_it_000be2dc);
  return pXVar1;
}

