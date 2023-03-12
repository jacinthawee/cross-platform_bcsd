
DH * DHparams_dup(DH *param_1)

{
  DH *pDVar1;
  
  pDVar1 = (DH *)ASN1_item_dup((ASN1_ITEM *)DHparams_it,param_1);
  return pDVar1;
}

