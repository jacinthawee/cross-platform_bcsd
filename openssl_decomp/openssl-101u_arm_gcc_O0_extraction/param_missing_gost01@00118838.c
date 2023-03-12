
uint param_missing_gost01(EVP_PKEY *param_1)

{
  EC_KEY *key;
  EC_GROUP *pEVar1;
  uint uVar2;
  
  key = (EC_KEY *)EVP_PKEY_get0(param_1);
  if (key != (EC_KEY *)0x0) {
    pEVar1 = EC_KEY_get0_group(key);
    uVar2 = count_leading_zeroes(pEVar1);
    return uVar2 >> 5;
  }
  return 1;
}

