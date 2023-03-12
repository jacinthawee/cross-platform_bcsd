
void TS_VERIFY_CTX_init(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  byte bVar3;
  
  bVar3 = 0;
  if (param_1 == (undefined4 *)0x0) {
    OpenSSLDie("ts_verify_ctx.c",0x4c,"ctx != NULL");
  }
  *param_1 = 0;
  param_1[9] = 0;
  puVar2 = (undefined4 *)((uint)(param_1 + 1) & 0xfffffffc);
  for (uVar1 = (uint)((int)param_1 + (0x28 - (int)(undefined4 *)((uint)(param_1 + 1) & 0xfffffffc)))
               >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + (uint)bVar3 * -2 + 1;
  }
  return;
}

