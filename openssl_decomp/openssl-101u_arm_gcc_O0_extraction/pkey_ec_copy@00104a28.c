
undefined4 pkey_ec_copy(int param_1,int param_2)

{
  EC_GROUP **ppEVar1;
  EC_GROUP *pEVar2;
  EC_GROUP **ppEVar3;
  
  ppEVar1 = (EC_GROUP **)CRYPTO_malloc(8,"ec_pmeth.c",0x50);
  if (ppEVar1 == (EC_GROUP **)0x0) {
    return 0;
  }
  *ppEVar1 = (EC_GROUP *)0x0;
  ppEVar1[1] = (EC_GROUP *)0x0;
  *(EC_GROUP ***)(param_1 + 0x14) = ppEVar1;
  ppEVar3 = *(EC_GROUP ***)(param_2 + 0x14);
  pEVar2 = *ppEVar3;
  if (pEVar2 != (EC_GROUP *)0x0) {
    pEVar2 = EC_GROUP_dup(pEVar2);
    *ppEVar1 = pEVar2;
    if (pEVar2 == (EC_GROUP *)0x0) {
      return 0;
    }
  }
  ppEVar1[1] = ppEVar3[1];
  return 1;
}

