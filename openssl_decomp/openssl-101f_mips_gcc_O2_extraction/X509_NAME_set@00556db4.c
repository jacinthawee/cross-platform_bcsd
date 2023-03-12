
int X509_NAME_set(X509_NAME **xn,X509_NAME *name)

{
  X509_NAME *pXVar1;
  
  if ((xn != (X509_NAME **)0x0) && (name != (X509_NAME *)0x0)) {
    pXVar1 = *xn;
    if (name != pXVar1) {
      pXVar1 = (X509_NAME *)ASN1_item_dup((ASN1_ITEM *)X509_NAME_it,name);
      if (pXVar1 == (X509_NAME *)0x0) {
        return (uint)(*xn != (X509_NAME *)0x0);
      }
      ASN1_item_free((ASN1_VALUE *)*xn,(ASN1_ITEM *)X509_NAME_it);
      *xn = pXVar1;
    }
    return (uint)(pXVar1 != (X509_NAME *)0x0);
  }
  return 0;
}

