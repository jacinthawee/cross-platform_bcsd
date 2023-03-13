
undefined4 gost_imit_copy(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(param_1 + 0xc);
  puVar3 = *(undefined4 **)(param_2 + 0xc);
  *puVar4 = *puVar3;
  puVar4[0x40f] = puVar3[0x40f];
  iVar1 = (int)puVar4 - (int)(undefined4 *)((uint)(puVar4 + 1) & 0xfffffffc);
  puVar3 = (undefined4 *)((int)puVar3 - iVar1);
  puVar4 = (undefined4 *)((uint)(puVar4 + 1) & 0xfffffffc);
  for (uVar2 = iVar1 + 0x1040U >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return 1;
}

