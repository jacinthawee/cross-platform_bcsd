
undefined4 gost_digest_copy(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  if ((puVar1 != (undefined4 *)0x0) &&
     (puVar4 = *(undefined4 **)(param_2 + 0xc), puVar4 != (undefined4 *)0x0)) {
    *puVar1 = *puVar4;
    iVar2 = (int)puVar1 - (int)(undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
    puVar1[0x423] = puVar4[0x423];
    puVar4 = (undefined4 *)((int)puVar4 - iVar2);
    puVar5 = (undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
    for (uVar3 = iVar2 + 0x1090U >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    puVar1[2] = puVar1 + 0x1c;
  }
  return 1;
}

