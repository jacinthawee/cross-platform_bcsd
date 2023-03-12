
int pkey_gost2001_derive(EVP_PKEY_CTX *param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  EVP_PKEY *pkey;
  EVP_PKEY *pkey_00;
  void *pvVar1;
  EC_KEY *key;
  EC_POINT *pEVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  pkey_00 = EVP_PKEY_CTX_get0_peerkey(param_1);
  pvVar1 = EVP_PKEY_CTX_get_data(param_1);
  iVar5 = *(int *)((int)pvVar1 + 8);
  if (iVar5 == 0) {
    ERR_GOST_error(0x79,0x80,"gost2001_keyx.c",0x56,param_4);
  }
  else {
    if (param_2 == 0) {
      *param_3 = 0x20;
      return 0x20;
    }
    key = (EC_KEY *)EVP_PKEY_get0(pkey_00);
    pEVar2 = EC_KEY_get0_public_key(key);
    pvVar3 = EVP_PKEY_get0(pkey);
    iVar5 = 1;
    uVar4 = VKO_compute_key_isra_0(param_2,pEVar2,pvVar3,*(undefined4 *)((int)pvVar1 + 8));
    *param_3 = uVar4;
  }
  return iVar5;
}

