
void ssl2_clear(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)param_1[0x15];
  *puVar1 = 0;
  puVar1[0x47] = 0;
  uVar2 = puVar1[0xc];
  uVar3 = puVar1[0xd];
  puVar5 = (undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
  for (uVar4 = (uint)((int)puVar1 + (0x120 - (int)(undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc)))
               >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar1[0xc] = uVar2;
  puVar1[0xd] = uVar3;
  puVar1[1] = 1;
  param_1[0x13] = uVar2;
  *param_1 = 2;
  param_1[0x14] = 0;
  return;
}

