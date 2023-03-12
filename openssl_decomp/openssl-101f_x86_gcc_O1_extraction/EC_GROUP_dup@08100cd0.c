
EC_GROUP * EC_GROUP_dup(EC_GROUP *src)

{
  int *dst;
  int iVar1;
  
  if (src != (EC_GROUP *)0x0) {
    iVar1 = *(int *)src;
    if (iVar1 == 0) {
      ERR_put_error(0x10,0x6c,0x6c,"ec_lib.c",0x52);
      return (EC_GROUP *)0x0;
    }
    if (*(int *)(iVar1 + 8) == 0) {
      ERR_put_error(0x10,0x6c,0x42,"ec_lib.c",0x57);
      return (EC_GROUP *)0x0;
    }
    dst = (int *)CRYPTO_malloc(0xac,"ec_lib.c",0x5b);
    if (dst == (int *)0x0) {
      ERR_put_error(0x10,0x6c,0x41,"ec_lib.c",0x5e);
      return (EC_GROUP *)0x0;
    }
    *dst = iVar1;
    dst[0x11] = 0;
    dst[1] = 0;
    BN_init((BIGNUM *)(dst + 2));
    BN_init((BIGNUM *)(dst + 7));
    dst[0xc] = 0;
    dst[0xd] = 0;
    dst[0xe] = 4;
    dst[0xf] = 0;
    dst[0x10] = 0;
    iVar1 = (**(code **)(iVar1 + 8))(dst);
    if (iVar1 == 0) {
      CRYPTO_free(dst);
      return (EC_GROUP *)0x0;
    }
    iVar1 = EC_GROUP_copy((EC_GROUP *)dst,src);
    if (iVar1 != 0) {
      return (EC_GROUP *)dst;
    }
    EC_GROUP_free((EC_GROUP *)dst);
  }
  return (EC_GROUP *)0x0;
}

