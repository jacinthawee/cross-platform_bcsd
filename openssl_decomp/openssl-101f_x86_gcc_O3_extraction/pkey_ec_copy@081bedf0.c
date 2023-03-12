
undefined4 pkey_ec_copy(int param_1,int param_2)

{
  EC_GROUP **ppEVar1;
  EC_GROUP **ppEVar2;
  EC_GROUP *pEVar3;
  
  ppEVar2 = (EC_GROUP **)CRYPTO_malloc(8,"ec_pmeth.c",0x50);
  if (ppEVar2 == (EC_GROUP **)0x0) {
    return 0;
  }
  *ppEVar2 = (EC_GROUP *)0x0;
  ppEVar2[1] = (EC_GROUP *)0x0;
  *(EC_GROUP ***)(param_1 + 0x14) = ppEVar2;
  ppEVar1 = *(EC_GROUP ***)(param_2 + 0x14);
  pEVar3 = *ppEVar1;
  if (pEVar3 != (EC_GROUP *)0x0) {
    pEVar3 = EC_GROUP_dup(pEVar3);
    *ppEVar2 = pEVar3;
    if (pEVar3 == (EC_GROUP *)0x0) {
      return 0;
    }
  }
  ppEVar2[1] = ppEVar1[1];
  return 1;
}

