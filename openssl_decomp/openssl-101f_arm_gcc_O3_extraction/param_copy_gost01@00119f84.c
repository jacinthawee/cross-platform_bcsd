
undefined4 param_copy_gost01(EVP_PKEY *param_1,EVP_PKEY *param_2)

{
  EC_KEY *key;
  EC_KEY *key_00;
  int iVar1;
  int iVar2;
  EC_GROUP *group;
  BIGNUM *pBVar3;
  
  key = (EC_KEY *)EVP_PKEY_get0(param_1);
  key_00 = (EC_KEY *)EVP_PKEY_get0(param_2);
  iVar1 = EVP_PKEY_base_id(param_2);
  iVar2 = EVP_PKEY_base_id(param_1);
  if (iVar1 != iVar2) {
    ERR_GOST_error(0x74,0x69,"gost_ameth.c",0x234);
    return 0;
  }
  if (key_00 != (EC_KEY *)0x0) {
    if (key == (EC_KEY *)0x0) {
      key = EC_KEY_new();
      iVar1 = EVP_PKEY_base_id(param_2);
      EVP_PKEY_assign(param_1,iVar1,key);
    }
    group = EC_KEY_get0_group(key_00);
    EC_KEY_set_group(key,group);
    pBVar3 = EC_KEY_get0_private_key(key);
    if (pBVar3 != (BIGNUM *)0x0) {
      gost2001_compute_public(key);
      return 1;
    }
    return 1;
  }
  ERR_GOST_error(0x74,0x73,"gost_ameth.c",0x23a);
  return 0;
}

