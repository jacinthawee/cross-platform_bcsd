
size_t pkey_ec_derive(int param_1,void *param_2,size_t *param_3)

{
  EC_POINT *pub_key;
  size_t sVar1;
  EC_GROUP *group;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 8) != 0) && (*(int *)(param_1 + 0xc) != 0)) {
    if (param_2 == (void *)0x0) {
      group = EC_KEY_get0_group(*(EC_KEY **)(*(int *)(param_1 + 8) + 0x14));
      iVar2 = EC_GROUP_get_degree(group);
      iVar3 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar3 = iVar2 + 7;
      }
      sVar1 = 1;
      *param_3 = iVar3 >> 3;
    }
    else {
      pub_key = EC_KEY_get0_public_key(*(EC_KEY **)(*(int *)(param_1 + 0xc) + 0x14));
      sVar1 = ECDH_compute_key(param_2,*param_3,pub_key,*(EC_KEY **)(*(int *)(param_1 + 8) + 0x14),
                               (KDF *)0x0);
      if (-1 < (int)sVar1) {
        *param_3 = sVar1;
        sVar1 = 1;
      }
    }
    return sVar1;
  }
  ERR_put_error(0x10,0xd9,0x8c,"ec_pmeth.c",0xb1);
  return 0;
}

