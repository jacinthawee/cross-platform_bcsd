
undefined4 pkey_dh_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x14,"dh_pmeth.c",0x53);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = 2;
    *puVar1 = 0x400;
    puVar1[2] = 0;
    *(undefined4 **)(param_1 + 0x14) = puVar1;
    puVar2 = *(undefined4 **)(param_2 + 0x14);
    *(undefined4 **)(param_1 + 0x20) = puVar1 + 3;
    *(undefined4 *)(param_1 + 0x24) = 2;
    uVar4 = *puVar2;
    uVar3 = puVar2[2];
    puVar1[1] = puVar2[1];
    *puVar1 = uVar4;
    puVar1[2] = uVar3;
    return 1;
  }
  return 0;
}

