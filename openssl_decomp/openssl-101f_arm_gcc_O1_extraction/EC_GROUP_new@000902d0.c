
EC_GROUP * EC_GROUP_new(EC_METHOD *meth)

{
  EC_METHOD **ppEVar1;
  code *pcVar2;
  EC_METHOD **ppEVar3;
  
  if (meth == (EC_METHOD *)0x0) {
    ERR_put_error(0x10,0x6c,0x6c,"ec_lib.c",0x52);
  }
  else {
    ppEVar3 = *(EC_METHOD ***)(meth + 8);
    if (ppEVar3 == (EC_METHOD **)0x0) {
      ERR_put_error(0x10,0x6c,0x42,"ec_lib.c",0x57);
      meth = (EC_METHOD *)ppEVar3;
    }
    else {
      ppEVar3 = (EC_METHOD **)CRYPTO_malloc(0xac,"ec_lib.c",0x5b);
      if (ppEVar3 == (EC_METHOD **)0x0) {
        ERR_put_error(0x10,0x6c,0x41,"ec_lib.c",0x5e);
        meth = (EC_METHOD *)ppEVar3;
      }
      else {
        *ppEVar3 = meth;
        ppEVar3[0x11] = (EC_METHOD *)0x0;
        ppEVar3[1] = (EC_METHOD *)0x0;
        BN_init((BIGNUM *)(ppEVar3 + 2));
        BN_init((BIGNUM *)(ppEVar3 + 7));
        pcVar2 = *(code **)(meth + 8);
        ppEVar3[0xc] = (EC_METHOD *)0x0;
        ppEVar3[0xd] = (EC_METHOD *)0x0;
        ppEVar3[0xf] = (EC_METHOD *)0x0;
        ppEVar3[0x10] = (EC_METHOD *)0x0;
        ppEVar3[0xe] = (EC_METHOD *)&DAT_00000004;
        ppEVar1 = (EC_METHOD **)(*pcVar2)(ppEVar3);
        meth = (EC_METHOD *)ppEVar3;
        if (ppEVar1 == (EC_METHOD **)0x0) {
          CRYPTO_free(ppEVar3);
          meth = (EC_METHOD *)ppEVar1;
        }
      }
    }
  }
  return (EC_GROUP *)meth;
}

