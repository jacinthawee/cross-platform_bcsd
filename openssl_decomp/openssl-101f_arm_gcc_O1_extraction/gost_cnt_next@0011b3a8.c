
/* WARNING: Could not reconcile some variable overlaps */

void gost_cnt_next(int param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  uint local_30;
  uint local_2c;
  int local_24;
  
  local_24 = __TMC_END__;
  if (*(int *)(param_1 + 8) == 0) {
    iVar2 = *(int *)(param_1 + 4);
  }
  else {
    iVar2 = *(int *)(param_1 + 4);
    if (iVar2 == 0x400) {
      cryptopro_key_meshing(param_1 + 0xc);
      iVar2 = *(int *)(param_1 + 4);
    }
  }
  if (iVar2 == 0) {
    gostcrypt(param_1 + 0xc,param_2,&local_30);
  }
  else {
    local_30 = *param_2;
    local_2c = param_2[1];
  }
  uVar1 = (local_2c >> 0x10 & 0xff) << 0x10 | (local_2c >> 8 & 0xff) << 8 | local_2c & 0xff |
          local_2c & 0xff000000;
  uVar3 = uVar1 + 0x1010104;
  uVar4 = ((local_30 >> 0x10 & 0xff) << 0x10 | (local_30 >> 8 & 0xff) << 8 | local_30 & 0xff |
          local_30 & 0xff000000) + 0x1010101;
  if (uVar3 < uVar1) {
    uVar3 = uVar1 + 0x1010105;
  }
  local_30 = uVar4 & 0xff000000 | (uVar4 >> 0x10 & 0xff) << 0x10 | uVar4 & 0xffff;
  local_2c._0_3_ = (uint3)uVar3 & 0xff00ff;
  local_2c._0_2_ = CONCAT11((char)(uVar3 >> 8),(undefined)local_2c);
  local_2c = uVar3 & 0xff000000 | (uint3)local_2c & 0xffff0000 | (uint)(ushort)local_2c;
  *param_2 = local_30;
  param_2[1] = local_2c;
  gostcrypt(param_1 + 0xc,&local_30,param_3);
  bVar5 = local_24 != __TMC_END__;
  *(uint *)(param_1 + 4) = (*(uint *)(param_1 + 4) & 0x3ff) + 8;
  if (bVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

