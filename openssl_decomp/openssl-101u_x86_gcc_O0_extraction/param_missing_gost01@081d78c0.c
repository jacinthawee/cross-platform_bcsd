
bool param_missing_gost01(EVP_PKEY *param_1)

{
  EC_KEY *key;
  EC_GROUP *pEVar1;
  bool bVar2;
  
  key = (EC_KEY *)EVP_PKEY_get0(param_1);
  bVar2 = true;
  if (key != (EC_KEY *)0x0) {
    pEVar1 = EC_KEY_get0_group(key);
    bVar2 = pEVar1 == (EC_GROUP *)0x0;
  }
  return bVar2;
}

