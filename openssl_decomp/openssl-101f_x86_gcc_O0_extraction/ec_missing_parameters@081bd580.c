
bool ec_missing_parameters(int param_1)

{
  EC_GROUP *pEVar1;
  
  pEVar1 = EC_KEY_get0_group(*(EC_KEY **)(param_1 + 0x14));
  return pEVar1 == (EC_GROUP *)0x0;
}

