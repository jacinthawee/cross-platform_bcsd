
undefined4 pkey_rsa_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  BIGNUM *pBVar3;
  
  puVar2 = (undefined4 *)CRYPTO_malloc(0x24,"rsa_pmeth.c",99);
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  *puVar2 = 0x400;
  puVar2[1] = 0;
  puVar2[5] = 0;
  puVar2[4] = 1;
  puVar2[6] = 0;
  puVar2[8] = 0;
  puVar2[7] = 0xfffffffe;
  *(undefined4 **)(param_1 + 0x14) = puVar2;
  *(undefined4 *)(param_1 + 0x24) = 2;
  *(undefined4 **)(param_1 + 0x20) = puVar2 + 2;
  puVar1 = *(undefined4 **)(param_2 + 0x14);
  *puVar2 = *puVar1;
  if ((BIGNUM *)puVar1[1] != (BIGNUM *)0x0) {
    pBVar3 = BN_dup((BIGNUM *)puVar1[1]);
    puVar2[1] = pBVar3;
    if (pBVar3 == (BIGNUM *)0x0) {
      return 0;
    }
  }
  puVar2[4] = puVar1[4];
  puVar2[5] = puVar1[5];
  return 1;
}

