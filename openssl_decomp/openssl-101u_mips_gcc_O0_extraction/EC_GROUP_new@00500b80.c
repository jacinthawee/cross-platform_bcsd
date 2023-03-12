
EC_GROUP * EC_GROUP_new(EC_METHOD *meth)

{
  EC_METHOD **ppEVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  code *pcVar5;
  
  if (meth == (EC_METHOD *)0x0) {
    uVar4 = 0x6c;
    uVar3 = 0x50;
  }
  else {
    if (*(int *)(meth + 8) != 0) {
      ppEVar1 = (EC_METHOD **)(*(code *)PTR_CRYPTO_malloc_006a7008)(0xac,"ec_lib.c",0x58);
      if (ppEVar1 == (EC_METHOD **)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x6c,0x41,"ec_lib.c",0x5a);
        return (EC_GROUP *)0x0;
      }
      *ppEVar1 = meth;
      ppEVar1[0x11] = (EC_METHOD *)0x0;
      ppEVar1[1] = (EC_METHOD *)0x0;
      BN_init((BIGNUM *)(ppEVar1 + 2));
      BN_init((BIGNUM *)(ppEVar1 + 7));
      pcVar5 = *(code **)(meth + 8);
      ppEVar1[0xc] = (EC_METHOD *)0x0;
      ppEVar1[0xd] = (EC_METHOD *)0x0;
      ppEVar1[0xe] = (EC_METHOD *)&SUB_00000004;
      ppEVar1[0xf] = (EC_METHOD *)0x0;
      ppEVar1[0x10] = (EC_METHOD *)0x0;
      iVar2 = (*pcVar5)(ppEVar1);
      if (iVar2 != 0) {
        return (EC_GROUP *)ppEVar1;
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)();
      return (EC_GROUP *)0x0;
    }
    uVar4 = 0x42;
    uVar3 = 0x54;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x6c,uVar4,"ec_lib.c",uVar3);
  return (EC_GROUP *)0x0;
}

