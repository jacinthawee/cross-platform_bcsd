
EC_KEY * EC_KEY_new_by_curve_name(int nid)

{
  undefined4 *puVar1;
  EC_GROUP *pEVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x24,"ec_key.c",0x4b);
  if (puVar1 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xb6,0x41,"ec_key.c",0x4d);
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[7] = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 1;
    puVar1[5] = 4;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[6] = 1;
    puVar1[8] = 0;
    pEVar2 = EC_GROUP_new_by_curve_name(nid);
    puVar1[1] = pEVar2;
    if (pEVar2 == (EC_GROUP *)0x0) {
      iVar3 = (*(code *)PTR_CRYPTO_add_lock_006a805c)(puVar1 + 6,0xffffffff,0x21,"ec_key.c",0x71);
      if (iVar3 < 1) {
        if ((EC_GROUP *)puVar1[1] != (EC_GROUP *)0x0) {
          EC_GROUP_free((EC_GROUP *)puVar1[1]);
        }
        if ((EC_POINT *)puVar1[2] != (EC_POINT *)0x0) {
          EC_POINT_free((EC_POINT *)puVar1[2]);
        }
        if ((BIGNUM *)puVar1[3] != (BIGNUM *)0x0) {
          BN_clear_free((BIGNUM *)puVar1[3]);
        }
        EC_EX_DATA_free_all_data(puVar1 + 8);
        (*(code *)PTR_OPENSSL_cleanse_006a7074)(puVar1,0x24);
        (*(code *)PTR_CRYPTO_free_006a6e88)(puVar1);
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)0x0;
      }
    }
  }
  return (EC_KEY *)puVar1;
}

