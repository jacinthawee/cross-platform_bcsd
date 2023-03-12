
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_CRL * X509_CRL_new(void)

{
  X509_CRL *pXVar1;
  
  pXVar1 = (X509_CRL *)ASN1_item_new((ASN1_ITEM *)PTR_X509_CRL_it_000b5c28);
  return pXVar1;
}

