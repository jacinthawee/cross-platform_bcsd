
undefined4 pkey_gost_copy(EVP_PKEY_CTX *param_1,EVP_PKEY_CTX *param_2)

{
  EVP_PKEY *pkey;
  int *data;
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  EC_KEY *key;
  EC_GROUP *group;
  
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  data = (int *)CRYPTO_malloc(0x10,"gost_pmeth.c",0x1a);
  if (data == (int *)0x0) {
    return 0;
  }
  *data = 0;
  data[1] = 0;
  data[2] = 0;
  data[3] = 0;
  if ((pkey != (EVP_PKEY *)0x0) && (pvVar1 = EVP_PKEY_get0(pkey), pvVar1 != (void *)0x0)) {
    iVar2 = EVP_PKEY_base_id(pkey);
    if (iVar2 == 0x32b) {
      key = (EC_KEY *)EVP_PKEY_get0(pkey);
      group = EC_KEY_get0_group(key);
      iVar2 = EC_GROUP_get_curve_name(group);
      *data = iVar2;
    }
    else {
      if (iVar2 != 0x32c) {
        return 0;
      }
      pvVar1 = EVP_PKEY_get0(pkey);
      iVar2 = gost94_nid_by_params(pvVar1);
      *data = iVar2;
    }
  }
  EVP_PKEY_CTX_set_data(param_1,data);
  puVar3 = (undefined4 *)EVP_PKEY_CTX_get_data(param_2);
  puVar4 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
  *puVar4 = *puVar3;
  puVar4[1] = puVar3[1];
  puVar4[2] = puVar3[2];
  puVar4[3] = puVar3[3];
  if (puVar3[2] != 0) {
    puVar4[2] = 0;
  }
  return 1;
}

