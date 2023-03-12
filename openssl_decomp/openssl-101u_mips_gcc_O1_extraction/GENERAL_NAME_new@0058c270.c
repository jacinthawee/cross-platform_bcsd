
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

GENERAL_NAME * GENERAL_NAME_new(void)

{
  GENERAL_NAME *pGVar1;
  
  pGVar1 = (GENERAL_NAME *)(*(code *)PTR_ASN1_item_new_006a8654)(GENERAL_NAME_it);
  return pGVar1;
}

