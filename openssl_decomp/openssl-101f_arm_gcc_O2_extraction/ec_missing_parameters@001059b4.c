
uint ec_missing_parameters(int param_1)

{
  EC_GROUP *pEVar1;
  uint uVar2;
  
  pEVar1 = EC_KEY_get0_group(*(EC_KEY **)(param_1 + 0x14));
  uVar2 = count_leading_zeroes(pEVar1);
  return uVar2 >> 5;
}

