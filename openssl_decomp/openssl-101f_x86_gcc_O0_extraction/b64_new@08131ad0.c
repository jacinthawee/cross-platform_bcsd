
undefined4 b64_new(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0xa5c,"bio_b64.c",0x74);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[1] = 0;
    puVar1[6] = 1;
    puVar1[5] = 1;
    puVar1[4] = 0;
    *(undefined4 **)(param_1 + 0x20) = puVar1;
    *(undefined4 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    return 1;
  }
  return 0;
}

