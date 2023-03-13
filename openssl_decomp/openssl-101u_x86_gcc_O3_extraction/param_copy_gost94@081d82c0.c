
void * param_copy_gost94(EVP_PKEY *param_1,EVP_PKEY *param_2)

{
  BIGNUM **ppBVar1;
  void *pvVar2;
  DSA *key;
  int iVar3;
  int iVar4;
  BIGNUM *pBVar5;
  
  pvVar2 = EVP_PKEY_get0(param_2);
  key = (DSA *)EVP_PKEY_get0(param_1);
  iVar3 = EVP_PKEY_base_id(param_2);
  iVar4 = EVP_PKEY_base_id(param_1);
  if (iVar3 == iVar4) {
    if (pvVar2 == (void *)0x0) {
      ERR_GOST_error(0x75,0x73,"gost_ameth.c",0x20f);
    }
    else {
      if (key == (DSA *)0x0) {
        key = DSA_new();
        iVar3 = EVP_PKEY_base_id(param_2);
        EVP_PKEY_assign(param_1,iVar3,key);
      }
      if (*(BIGNUM **)&key->field_0xc != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)&key->field_0xc);
      }
      pBVar5 = BN_dup(*(BIGNUM **)((int)pvVar2 + 0xc));
      *(BIGNUM **)&key->field_0xc = pBVar5;
      if (*(BIGNUM **)&key->field_0x10 != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)&key->field_0x10);
      }
      pBVar5 = BN_dup(*(BIGNUM **)((int)pvVar2 + 0x10));
      *(BIGNUM **)&key->field_0x10 = pBVar5;
      if (*(BIGNUM **)&key->field_0x14 != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)&key->field_0x14);
      }
      ppBVar1 = (BIGNUM **)((int)pvVar2 + 0x14);
      pvVar2 = (void *)0x1;
      pBVar5 = BN_dup(*ppBVar1);
      *(BIGNUM **)&key->field_0x14 = pBVar5;
      if (*(int *)&key->field_0x1c != 0) {
        gost94_compute_public(key);
      }
    }
    return pvVar2;
  }
  ERR_GOST_error(0x75,0x69,"gost_ameth.c",0x20b);
  return (void *)0x0;
}

