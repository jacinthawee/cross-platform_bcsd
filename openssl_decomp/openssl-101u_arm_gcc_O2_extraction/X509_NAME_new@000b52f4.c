
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_NAME * X509_NAME_new(void)

{
  X509_NAME *pXVar1;
  
  pXVar1 = (X509_NAME *)ASN1_item_new((ASN1_ITEM *)PTR_X509_NAME_it_000b52fc);
  return pXVar1;
}

