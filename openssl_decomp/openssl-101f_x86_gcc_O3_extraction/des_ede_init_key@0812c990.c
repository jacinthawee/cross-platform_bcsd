
undefined4 des_ede_init_key(int param_1,const_DES_cblock *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  byte bVar5;
  
  bVar5 = 0;
  DES_set_key_unchecked(param_2,*(DES_key_schedule **)(param_1 + 0x60));
  DES_set_key_unchecked(param_2[1],(DES_key_schedule *)(*(int *)(param_1 + 0x60) + 0x80));
  puVar4 = *(undefined4 **)(param_1 + 0x60);
  puVar4[0x40] = *puVar4;
  iVar1 = (int)puVar4 + (0x100 - (int)(undefined4 *)((uint)(puVar4 + 0x41) & 0xfffffffc));
  puVar4[0x5f] = puVar4[0x1f];
  puVar3 = (undefined4 *)((int)puVar4 - iVar1);
  puVar4 = (undefined4 *)((uint)(puVar4 + 0x41) & 0xfffffffc);
  for (uVar2 = iVar1 + 0x80U >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + (uint)bVar5 * -2 + 1;
    puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
  }
  return 1;
}

