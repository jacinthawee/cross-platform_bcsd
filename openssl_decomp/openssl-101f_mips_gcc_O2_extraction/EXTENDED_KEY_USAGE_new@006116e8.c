
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

EXTENDED_KEY_USAGE * EXTENDED_KEY_USAGE_new(void)

{
  EXTENDED_KEY_USAGE *pEVar1;
  
  pEVar1 = (EXTENDED_KEY_USAGE *)(*(code *)PTR_ASN1_item_new_006a9778)(EXTENDED_KEY_USAGE_it);
  return pEVar1;
}

