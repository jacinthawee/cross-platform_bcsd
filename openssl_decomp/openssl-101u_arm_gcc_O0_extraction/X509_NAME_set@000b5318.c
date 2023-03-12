
int X509_NAME_set(X509_NAME **xn,X509_NAME *name)

{
  X509_NAME *pXVar1;
  
  if (name == (X509_NAME *)0x0 || xn == (X509_NAME **)0x0) {
    return 0;
  }
  pXVar1 = *xn;
  if (pXVar1 != name) {
    pXVar1 = (X509_NAME *)ASN1_item_dup((ASN1_ITEM *)PTR_X509_NAME_it_000b5354,name);
    if (pXVar1 == (X509_NAME *)0x0) {
      pXVar1 = *xn;
      if (pXVar1 != (X509_NAME *)0x0) {
        pXVar1 = (X509_NAME *)0x1;
      }
      return (int)pXVar1;
    }
    ASN1_item_free((ASN1_VALUE *)*xn,(ASN1_ITEM *)PTR_X509_NAME_it_000b5354);
    *xn = pXVar1;
  }
  if (pXVar1 != (X509_NAME *)0x0) {
    pXVar1 = (X509_NAME *)0x1;
  }
  return (int)pXVar1;
}

