
void __regparm3 gost_cnt_next(int param_1,int *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int in_GS_OFFSET;
  bool bVar3;
  int local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(param_1 + 8) == 0) {
    iVar2 = *(int *)(param_1 + 4);
  }
  else {
    iVar2 = *(int *)(param_1 + 4);
    if (iVar2 == 0x400) {
      cryptopro_key_meshing(param_1 + 0xc,param_2);
      iVar2 = *(int *)(param_1 + 4);
    }
  }
  if (iVar2 == 0) {
    gostcrypt(param_1 + 0xc,param_2,&local_28);
  }
  else {
    local_28 = *param_2;
    local_24 = param_2[1];
  }
  local_28 = local_28 + 0x1010101;
  uVar1 = local_24 + 0x1010105;
  bVar3 = local_24 + 0x1010104 < local_24;
  local_24 = local_24 + 0x1010104;
  if (bVar3) {
    local_24 = uVar1;
  }
  *param_2 = local_28;
  param_2[1] = local_24;
  gostcrypt(param_1 + 0xc,&local_28,param_3);
  *(uint *)(param_1 + 4) = (*(uint *)(param_1 + 4) & 0x3ff) + 8;
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

