
EC_KEY * EC_KEY_dup(EC_KEY *src)

{
  undefined4 *dst;
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  dst = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x24,"ec_key.c",0x4b);
  if (dst == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xb6,0x41,"ec_key.c",0x4e);
    puVar3 = (undefined4 *)0x0;
  }
  else {
    dst[7] = 0;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    *dst = 1;
    dst[4] = 0;
    dst[5] = 4;
    dst[6] = 1;
    dst[8] = 0;
    puVar1 = (undefined4 *)EC_KEY_copy((EC_KEY *)dst,src);
    puVar3 = dst;
    if ((puVar1 == (undefined4 *)0x0) &&
       (iVar2 = (*(code *)PTR_CRYPTO_add_lock_006a9080)(dst + 6,0xffffffff,0x21,"ec_key.c",0x72),
       puVar3 = puVar1, iVar2 < 1)) {
      if ((EC_GROUP *)dst[1] != (EC_GROUP *)0x0) {
        EC_GROUP_free((EC_GROUP *)dst[1]);
      }
      if ((EC_POINT *)dst[2] != (EC_POINT *)0x0) {
        EC_POINT_free((EC_POINT *)dst[2]);
      }
      if ((BIGNUM *)dst[3] != (BIGNUM *)0x0) {
        BN_clear_free((BIGNUM *)dst[3]);
      }
      EC_EX_DATA_free_all_data(dst + 8);
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(dst,0x24);
      (*(code *)PTR_CRYPTO_free_006a7f88)(dst);
    }
  }
  return (EC_KEY *)puVar3;
}

