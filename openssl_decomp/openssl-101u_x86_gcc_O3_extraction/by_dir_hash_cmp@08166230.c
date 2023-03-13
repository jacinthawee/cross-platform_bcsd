
int by_dir_hash_cmp(uint **param_1,uint **param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = *param_1;
  uVar2 = **param_2;
  iVar3 = -(uint)(*puVar1 < **param_2);
  if (uVar2 <= *puVar1 && *puVar1 != uVar2) {
    iVar3 = 1;
  }
  return iVar3;
}

