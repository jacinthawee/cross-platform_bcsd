
EC_GROUP * EC_GROUP_new(EC_METHOD *meth)

{
  EC_METHOD **ptr;
  int iVar1;
  int line;
  
  if (meth == (EC_METHOD *)0x0) {
    line = 0x50;
    iVar1 = 0x6c;
  }
  else {
    if (*(int *)(meth + 8) != 0) {
      ptr = (EC_METHOD **)CRYPTO_malloc(0xac,"ec_lib.c",0x58);
      if (ptr == (EC_METHOD **)0x0) {
        ERR_put_error(0x10,0x6c,0x41,"ec_lib.c",0x5a);
        return (EC_GROUP *)0x0;
      }
      *ptr = meth;
      ptr[0x11] = (EC_METHOD *)0x0;
      ptr[1] = (EC_METHOD *)0x0;
      BN_init((BIGNUM *)(ptr + 2));
      BN_init((BIGNUM *)(ptr + 7));
      ptr[0xc] = (EC_METHOD *)0x0;
      ptr[0xd] = (EC_METHOD *)0x0;
      ptr[0xe] = (EC_METHOD *)&DAT_00000004;
      ptr[0xf] = (EC_METHOD *)0x0;
      ptr[0x10] = (EC_METHOD *)0x0;
      iVar1 = (**(code **)(meth + 8))(ptr);
      if (iVar1 != 0) {
        return (EC_GROUP *)ptr;
      }
      CRYPTO_free(ptr);
      return (EC_GROUP *)0x0;
    }
    line = 0x54;
    iVar1 = 0x42;
  }
  ERR_put_error(0x10,0x6c,iVar1,"ec_lib.c",line);
  return (EC_GROUP *)0x0;
}

