
void cleanup1_LHASH_DOALL(int param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar2 + 8) = 0;
  puVar1 = (uint *)(iVar2 + 0x14);
  *puVar1 = *puVar1 | 0xd;
  return;
}

