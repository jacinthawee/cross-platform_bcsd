
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

AUTHORITY_INFO_ACCESS * AUTHORITY_INFO_ACCESS_new(void)

{
  AUTHORITY_INFO_ACCESS *pAVar1;
  
  pAVar1 = (AUTHORITY_INFO_ACCESS *)ASN1_item_new((ASN1_ITEM *)AUTHORITY_INFO_ACCESS_it);
  return pAVar1;
}

