
undefined4 pkey_gost_init(EVP_PKEY_CTX *param_1)

{
  EVP_PKEY *pkey;
  int *data;
  void *pvVar1;
  int iVar2;
  EC_KEY *key;
  EC_GROUP *group;
  undefined4 uVar3;
  
  uVar3 = 0;
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  data = (int *)CRYPTO_malloc(0x10,"gost_pmeth.c",0x1a);
  if (data != (int *)0x0) {
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
    uVar3 = 1;
    EVP_PKEY_CTX_set_data(param_1,data);
  }
  return uVar3;
}

