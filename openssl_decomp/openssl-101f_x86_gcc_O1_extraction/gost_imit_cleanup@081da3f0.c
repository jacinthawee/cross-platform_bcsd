
undefined4 gost_imit_cleanup(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  *puVar2 = 0;
  puVar2[0x40f] = 0;
  uVar1 = (uint)((int)puVar2 + (0x1040 - (int)(undefined4 *)((uint)(puVar2 + 1) & 0xfffffffc))) >> 2
  ;
  puVar2 = (undefined4 *)((uint)(puVar2 + 1) & 0xfffffffc);
  for (; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return 1;
}

