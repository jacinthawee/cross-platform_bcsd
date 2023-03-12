
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

GENERAL_NAMES * GENERAL_NAMES_new(void)

{
  GENERAL_NAMES *pGVar1;
  
  pGVar1 = (GENERAL_NAMES *)ASN1_item_new((ASN1_ITEM *)PTR_GENERAL_NAMES_it_000d0a7c);
  return pGVar1;
}

