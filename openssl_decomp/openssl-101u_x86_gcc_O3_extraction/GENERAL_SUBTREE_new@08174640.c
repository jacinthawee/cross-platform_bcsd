
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

GENERAL_SUBTREE * GENERAL_SUBTREE_new(void)

{
  GENERAL_SUBTREE *pGVar1;
  
  pGVar1 = (GENERAL_SUBTREE *)ASN1_item_new((ASN1_ITEM *)GENERAL_SUBTREE_it);
  return pGVar1;
}

