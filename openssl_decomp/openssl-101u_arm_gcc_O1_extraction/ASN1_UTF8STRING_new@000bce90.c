
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_UTF8STRING * ASN1_UTF8STRING_new(void)

{
  ASN1_UTF8STRING *pAVar1;
  
  pAVar1 = (ASN1_UTF8STRING *)ASN1_item_new((ASN1_ITEM *)PTR_ASN1_UTF8STRING_it_000bce98);
  return pAVar1;
}
