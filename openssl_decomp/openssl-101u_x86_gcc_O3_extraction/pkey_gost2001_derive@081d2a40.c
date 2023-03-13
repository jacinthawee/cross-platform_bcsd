
undefined4 pkey_gost2001_derive(EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  EVP_PKEY *pkey;
  EVP_PKEY *pkey_00;
  void *pvVar2;
  EC_KEY *key;
  undefined4 uVar3;
  
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  pkey_00 = EVP_PKEY_CTX_get0_peerkey(param_1);
  pvVar2 = EVP_PKEY_CTX_get_data(param_1);
  iVar1 = *(int *)((int)pvVar2 + 8);
  if (iVar1 == 0) {
    ERR_GOST_error(0x79,0x80,"gost2001_keyx.c",0x55);
    uVar3 = 0;
  }
  else {
    if (param_2 == 0) {
      *param_3 = 0x20;
      return 0x20;
    }
    EVP_PKEY_get0(pkey);
    key = (EC_KEY *)EVP_PKEY_get0(pkey_00);
    EC_KEY_get0_public_key(key);
    uVar3 = VKO_compute_key_isra_0(iVar1);
    *param_3 = uVar3;
    uVar3 = 1;
  }
  return uVar3;
}

