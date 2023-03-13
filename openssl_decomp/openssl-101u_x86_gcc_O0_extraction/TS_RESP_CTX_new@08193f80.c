
undefined4 * TS_RESP_CTX_new(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  byte bVar4;
  
  bVar4 = 0;
  puVar1 = (undefined4 *)CRYPTO_malloc(0x50,"ts_rsp_sign.c",0xac);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x2f,0x7f,0x41,"ts_rsp_sign.c",0xad);
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[0x13] = 0;
    puVar3 = (undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
    for (uVar2 = (uint)((int)puVar1 + (0x50 - (int)(undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc)))
                 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + (uint)bVar4 * -2 + 1;
    }
    puVar1[0xb] = def_serial_cb;
    puVar1[0xd] = def_time_cb;
    puVar1[0xf] = def_extension_cb;
  }
  return puVar1;
}

