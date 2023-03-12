
bool init_gost_hash_ctx(undefined4 *param_1,undefined4 param_2)

{
  void *pvVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  *param_1 = 0;
  param_1[0x1b] = 0;
  puVar3 = (undefined4 *)((uint)(param_1 + 1) & 0xfffffffc);
  for (uVar2 = (uint)((int)param_1 + (0x70 - (int)(undefined4 *)((uint)(param_1 + 1) & 0xfffffffc)))
               >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  pvVar1 = malloc(0x1020);
  param_1[2] = pvVar1;
  if (pvVar1 != (void *)0x0) {
    gost_init(pvVar1,param_2);
  }
  return pvVar1 != (void *)0x0;
}

