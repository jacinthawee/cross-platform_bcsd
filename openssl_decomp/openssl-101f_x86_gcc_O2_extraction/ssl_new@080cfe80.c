
undefined4 ssl_new(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0x18,"bio_ssl.c",0x6c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[5] = 0;
    uVar2 = 0;
    do {
      *(undefined4 *)(((uint)(puVar1 + 1) & 0xfffffffc) + uVar2) = 0;
      uVar2 = uVar2 + 4;
    } while (uVar2 < ((int)puVar1 + (0x18 - ((uint)(puVar1 + 1) & 0xfffffffc)) & 0xfffffffc));
    *(undefined4 **)(param_1 + 0x20) = puVar1;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  ERR_put_error(0x20,0x76,0x41,"bio_ssl.c",0x6f);
  return 0;
}

