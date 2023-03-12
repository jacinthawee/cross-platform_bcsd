
undefined4 pkey_dh_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)CRYPTO_malloc(0x14,"dh_pmeth.c",0x53);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0x400;
    puVar3[1] = 2;
    puVar3[2] = 0;
    *(undefined4 **)(param_1 + 0x14) = puVar3;
    *(undefined4 **)(param_1 + 0x20) = puVar3 + 3;
    *(undefined4 *)(param_1 + 0x24) = 2;
    puVar1 = *(undefined4 **)(param_2 + 0x14);
    *puVar3 = *puVar1;
    uVar2 = puVar1[2];
    puVar3[1] = puVar1[1];
    puVar3[2] = uVar2;
    return 1;
  }
  return 0;
}

