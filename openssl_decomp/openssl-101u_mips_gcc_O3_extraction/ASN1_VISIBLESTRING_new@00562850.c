
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_VISIBLESTRING * ASN1_VISIBLESTRING_new(void)

{
  ASN1_VISIBLESTRING *pAVar1;
  
  pAVar1 = (ASN1_VISIBLESTRING *)ASN1_item_new((ASN1_ITEM *)ASN1_VISIBLESTRING_it);
  return pAVar1;
}

