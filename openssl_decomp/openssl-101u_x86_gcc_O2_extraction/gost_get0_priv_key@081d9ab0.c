
BIGNUM * gost_get0_priv_key(EVP_PKEY *param_1)

{
  int iVar1;
  void *pvVar2;
  EC_KEY *key;
  BIGNUM *pBVar3;
  
  iVar1 = EVP_PKEY_base_id(param_1);
  if (iVar1 == 0x32b) {
    key = (EC_KEY *)EVP_PKEY_get0(param_1);
    if (key != (EC_KEY *)0x0) {
      pBVar3 = EC_KEY_get0_private_key(key);
      return pBVar3;
    }
  }
  else if (iVar1 == 0x32c) {
    pvVar2 = EVP_PKEY_get0(param_1);
    if (pvVar2 != (void *)0x0) {
      return *(BIGNUM **)((int)pvVar2 + 0x1c);
    }
  }
  return (BIGNUM *)0x0;
}

