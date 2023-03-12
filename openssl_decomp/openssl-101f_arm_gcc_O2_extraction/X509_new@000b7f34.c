
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509 * X509_new(void)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)ASN1_item_new((ASN1_ITEM *)PTR_X509_it_000b7f3c);
  return pXVar1;
}

