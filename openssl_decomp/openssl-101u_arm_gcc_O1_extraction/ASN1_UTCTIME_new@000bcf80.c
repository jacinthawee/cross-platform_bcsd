
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ASN1_UTCTIME * ASN1_UTCTIME_new(void)

{
  ASN1_UTCTIME *pAVar1;
  
  pAVar1 = (ASN1_UTCTIME *)ASN1_item_new((ASN1_ITEM *)PTR_ASN1_UTCTIME_it_000bcf88);
  return pAVar1;
}

