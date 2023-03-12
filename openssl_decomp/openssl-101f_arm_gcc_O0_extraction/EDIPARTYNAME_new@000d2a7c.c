
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EDIPARTYNAME * EDIPARTYNAME_new(void)

{
  EDIPARTYNAME *pEVar1;
  
  pEVar1 = (EDIPARTYNAME *)ASN1_item_new((ASN1_ITEM *)PTR_EDIPARTYNAME_it_000d2a84);
  return pEVar1;
}

