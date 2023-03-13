
undefined4 acpt_new(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 0;
  puVar1 = (undefined4 *)CRYPTO_malloc(0x20,"bss_acpt.c",0x92);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    *puVar1 = 0;
    puVar1[7] = 0;
    uVar3 = 0;
    do {
      *(undefined4 *)(((uint)(puVar1 + 1) & 0xfffffffc) + uVar3) = 0;
      uVar3 = uVar3 + 4;
    } while (uVar3 < ((int)puVar1 + (0x20 - ((uint)(puVar1 + 1) & 0xfffffffc)) & 0xfffffffc));
    puVar1[2] = 0xffffffff;
    puVar1[6] = 0;
    *(undefined4 **)(param_1 + 0x20) = puVar1;
    *puVar1 = 1;
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x10) = 1;
  }
  return uVar2;
}

