
undefined4 pkey_rsa_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x24,"rsa_pmeth.c",99);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  puVar1[1] = 0;
  *puVar1 = 0x400;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[8] = 0;
  puVar1[7] = 0xfffffffe;
  puVar1[4] = 1;
  *(undefined4 **)(param_1 + 0x14) = puVar1;
  puVar4 = *(undefined4 **)(param_2 + 0x14);
  *(undefined4 **)(param_1 + 0x20) = puVar1 + 2;
  *(undefined4 *)(param_1 + 0x24) = 2;
  pBVar2 = (BIGNUM *)puVar4[1];
  *puVar1 = *puVar4;
  if (pBVar2 != (BIGNUM *)0x0) {
    pBVar2 = BN_dup(pBVar2);
    puVar1[1] = pBVar2;
    if (pBVar2 == (BIGNUM *)0x0) {
      return 0;
    }
  }
  uVar3 = puVar4[5];
  puVar1[4] = puVar4[4];
  puVar1[5] = uVar3;
  return 1;
}

