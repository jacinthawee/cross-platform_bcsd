
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_TYPE * ASN1_TYPE_new(void)

{
  ASN1_TYPE *pAVar1;
  
  pAVar1 = (ASN1_TYPE *)ASN1_item_new((ASN1_ITEM *)PTR_ASN1_ANY_it_000bf76c);
  return pAVar1;
}

