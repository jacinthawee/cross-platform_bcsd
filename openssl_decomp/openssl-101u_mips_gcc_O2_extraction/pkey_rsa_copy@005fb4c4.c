
undefined4 pkey_rsa_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x24,"rsa_pmeth.c",99);
  if (puVar1 == (undefined4 *)0x0) {
    return 0;
  }
  puVar1[1] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[4] = 1;
  puVar1[8] = 0;
  *puVar1 = 0x400;
  puVar1[7] = 0xfffffffe;
  *(undefined4 **)(param_1 + 0x14) = puVar1;
  puVar4 = *(undefined4 **)(param_2 + 0x14);
  *(undefined4 **)(param_1 + 0x20) = puVar1 + 2;
  *(undefined4 *)(param_1 + 0x24) = 2;
  iVar3 = puVar4[1];
  *puVar1 = *puVar4;
  if (iVar3 != 0) {
    iVar3 = (*(code *)PTR_BN_dup_006a8218)();
    puVar1[1] = iVar3;
    if (iVar3 == 0) {
      return 0;
    }
  }
  uVar2 = puVar4[5];
  puVar1[4] = puVar4[4];
  puVar1[5] = uVar2;
  return 1;
}

