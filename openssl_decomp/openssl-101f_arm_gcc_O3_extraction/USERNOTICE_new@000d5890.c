
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

USERNOTICE * USERNOTICE_new(void)

{
  USERNOTICE *pUVar1;
  
  pUVar1 = (USERNOTICE *)ASN1_item_new((ASN1_ITEM *)PTR_USERNOTICE_it_000d5898);
  return pUVar1;
}

