
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_NULL * ASN1_NULL_new(void)

{
  ASN1_NULL *pAVar1;
  
  pAVar1 = (ASN1_NULL *)ASN1_item_new((ASN1_ITEM *)ASN1_NULL_it);
  return pAVar1;
}
