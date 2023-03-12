
uint param_cmp_gost01(EVP_PKEY *param_1,EVP_PKEY *param_2)

{
  EC_KEY *pEVar1;
  EC_GROUP *pEVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  pEVar1 = (EC_KEY *)EVP_PKEY_get0(param_1);
  pEVar2 = EC_KEY_get0_group(pEVar1);
  iVar3 = EC_GROUP_get_curve_name(pEVar2);
  pEVar1 = (EC_KEY *)EVP_PKEY_get0(param_2);
  pEVar2 = EC_KEY_get0_group(pEVar1);
  iVar4 = EC_GROUP_get_curve_name(pEVar2);
  uVar5 = count_leading_zeroes(iVar3 - iVar4);
  return uVar5 >> 5;
}

