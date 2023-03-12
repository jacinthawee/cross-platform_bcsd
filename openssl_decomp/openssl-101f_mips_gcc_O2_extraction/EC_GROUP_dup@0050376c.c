
EC_GROUP * EC_GROUP_dup(EC_GROUP *src)

{
  int *dst;
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  
  if (src == (EC_GROUP *)0x0) {
    return (EC_GROUP *)0x0;
  }
  iVar3 = *(int *)src;
  if (iVar3 == 0) {
    uVar2 = 0x6c;
    uVar1 = 0x52;
  }
  else {
    if (*(int *)(iVar3 + 8) != 0) {
      dst = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0xac,"ec_lib.c",0x5b);
      if (dst == (int *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x6c,0x41,"ec_lib.c",0x5e);
        return (EC_GROUP *)0x0;
      }
      *dst = iVar3;
      dst[0x11] = 0;
      dst[1] = 0;
      BN_init((BIGNUM *)(dst + 2));
      BN_init((BIGNUM *)(dst + 7));
      pcVar4 = *(code **)(iVar3 + 8);
      dst[0xc] = 0;
      dst[0xd] = 0;
      dst[0xe] = 4;
      dst[0xf] = 0;
      dst[0x10] = 0;
      iVar3 = (*pcVar4)(dst);
      if (iVar3 != 0) {
        iVar3 = EC_GROUP_copy((EC_GROUP *)dst,src);
        if (iVar3 != 0) {
          return (EC_GROUP *)dst;
        }
        EC_GROUP_free((EC_GROUP *)dst);
        return (EC_GROUP *)0x0;
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(dst);
      return (EC_GROUP *)0x0;
    }
    uVar2 = 0x42;
    uVar1 = 0x57;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0x6c,uVar2,"ec_lib.c",uVar1);
  return (EC_GROUP *)0x0;
}

