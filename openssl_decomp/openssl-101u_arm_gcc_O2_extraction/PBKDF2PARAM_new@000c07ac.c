
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PBKDF2PARAM * PBKDF2PARAM_new(void)

{
  PBKDF2PARAM *pPVar1;
  
  pPVar1 = (PBKDF2PARAM *)ASN1_item_new((ASN1_ITEM *)PTR_PBKDF2PARAM_it_000c07b4);
  return pPVar1;
}

