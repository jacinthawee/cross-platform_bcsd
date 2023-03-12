
EC_GROUP * EC_GROUP_dup(EC_GROUP *src)

{
  int *dst;
  code *pcVar1;
  int iVar2;
  
  if (src != (EC_GROUP *)0x0) {
    iVar2 = *(int *)src;
    if (iVar2 == 0) {
      ERR_put_error(0x10,0x6c,0x6c,"ec_lib.c",0x50);
    }
    else if (*(int *)(iVar2 + 8) == 0) {
      ERR_put_error(0x10,0x6c,0x42,"ec_lib.c",0x54);
    }
    else {
      dst = (int *)CRYPTO_malloc(0xac,"ec_lib.c",0x58);
      if (dst == (int *)0x0) {
        ERR_put_error(0x10,0x6c,0x41,"ec_lib.c",0x5a);
      }
      else {
        *dst = iVar2;
        dst[0x11] = 0;
        dst[1] = 0;
        BN_init((BIGNUM *)(dst + 2));
        BN_init((BIGNUM *)(dst + 7));
        pcVar1 = *(code **)(iVar2 + 8);
        dst[0xc] = 0;
        dst[0xd] = 0;
        dst[0xf] = 0;
        dst[0x10] = 0;
        dst[0xe] = 4;
        iVar2 = (*pcVar1)(dst);
        if (iVar2 != 0) {
          iVar2 = EC_GROUP_copy((EC_GROUP *)dst,src);
          if (iVar2 != 0) {
            return (EC_GROUP *)dst;
          }
          EC_GROUP_free((EC_GROUP *)dst);
          return (EC_GROUP *)0x0;
        }
        CRYPTO_free(dst);
      }
    }
    src = (EC_GROUP *)0x0;
  }
  return src;
}

