
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

POLICYQUALINFO * POLICYQUALINFO_new(void)

{
  POLICYQUALINFO *pPVar1;
  
  pPVar1 = (POLICYQUALINFO *)ASN1_item_new((ASN1_ITEM *)PTR_POLICYQUALINFO_it_000d3608);
  return pPVar1;
}

