
undefined4 pkey_gost_copy(EVP_PKEY_CTX *param_1,EVP_PKEY_CTX *param_2)

{
  EVP_PKEY *pkey;
  int *__s;
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  EC_KEY *key;
  EC_GROUP *group;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  __s = (int *)CRYPTO_malloc(0x10,"gost_pmeth.c",0x1a);
  if (__s == (int *)0x0) {
    return 0;
  }
  memset(__s,0,0x10);
  if ((pkey != (EVP_PKEY *)0x0) && (pvVar1 = EVP_PKEY_get0(pkey), pvVar1 != (void *)0x0)) {
    iVar2 = EVP_PKEY_base_id(pkey);
    if (iVar2 == 0x32b) {
      key = (EC_KEY *)EVP_PKEY_get0(pkey);
      group = EC_KEY_get0_group(key);
      iVar2 = EC_GROUP_get_curve_name(group);
      *__s = iVar2;
    }
    else {
      if (iVar2 != 0x32c) {
        return 0;
      }
      EVP_PKEY_get0(pkey);
      iVar2 = gost94_nid_by_params();
      *__s = iVar2;
    }
  }
  EVP_PKEY_CTX_set_data(param_1,__s);
  puVar3 = (undefined4 *)EVP_PKEY_CTX_get_data(param_2);
  puVar4 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
  uVar5 = puVar3[1];
  uVar6 = puVar3[2];
  uVar7 = puVar3[3];
  *puVar4 = *puVar3;
  puVar4[1] = uVar5;
  puVar4[2] = uVar6;
  puVar4[3] = uVar7;
  if (puVar3[2] == 0) {
    return 1;
  }
  puVar4[2] = 0;
  return 1;
}

