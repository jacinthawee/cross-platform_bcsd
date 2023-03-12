
undefined4 * TS_VERIFY_CTX_new(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  puVar1 = (undefined4 *)CRYPTO_malloc(0x28,"ts_verify_ctx.c",0x42);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[9] = 0;
    puVar3 = (undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
    for (uVar2 = (uint)((int)puVar1 + (0x28 - (int)(undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc)))
                 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
    return puVar1;
  }
  ERR_put_error(0x2f,0x90,0x41,"ts_verify_ctx.c",0x46);
  return (undefined4 *)0x0;
}

