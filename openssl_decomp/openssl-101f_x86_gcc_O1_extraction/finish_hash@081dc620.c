
undefined4 finish_hash(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int in_GS_OFFSET;
  bool bVar6;
  uint *puVar7;
  uint local_94;
  uint local_90;
  undefined4 local_80 [8];
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  
  puVar3 = local_80;
  local_90 = param_1[1];
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_94 = *param_1;
  local_60 = param_1[4];
  local_5c = param_1[5];
  local_58 = param_1[6];
  local_54 = param_1[7];
  local_50 = param_1[8];
  local_4c = param_1[9];
  local_48 = param_1[10];
  local_44 = param_1[0xb];
  local_40 = param_1[0xc];
  local_3c = param_1[0xd];
  local_38 = param_1[0xe];
  local_34 = param_1[0xf];
  local_30 = param_1[0x10];
  local_2c = param_1[0x11];
  local_28 = param_1[0x12];
  local_24 = param_1[0x13];
  uVar1 = param_1[3];
  if (uVar1 == 0) {
    puVar7 = &local_60;
  }
  else {
    uVar4 = 0;
    do {
      *(undefined4 *)((int)puVar3 + uVar4) = 0;
      uVar4 = uVar4 + 4;
    } while (uVar4 < 0x20);
    iVar5 = 0;
    __memcpy_chk(puVar3,param_1 + 0x14,uVar1,0x20);
    puVar7 = &local_60;
    hash_step();
    iVar2 = 0;
    do {
      iVar2 = iVar2 + (uint)*(byte *)((int)puVar3 + iVar5) + (uint)*(byte *)((int)&local_40 + iVar5)
      ;
      *(char *)((int)&local_40 + iVar5) = (char)iVar2;
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 >> 8;
    } while (iVar5 != 0x20);
    uVar1 = param_1[3];
    bVar6 = CARRY4(local_94,uVar1);
    local_94 = local_94 + uVar1;
    local_90 = local_90 + ((int)uVar1 >> 0x1f) + (uint)bVar6;
  }
  uVar1 = 0;
  do {
    *(undefined4 *)((int)puVar3 + uVar1) = 0;
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x20);
  uVar1 = local_90 << 3 | local_94 >> 0x1d;
  local_94 = local_94 << 3;
  if (0 < (int)uVar1) goto LAB_081dc710;
  uVar4 = local_94;
  if (-1 < (int)uVar1) {
    while (uVar4 != 0) {
LAB_081dc710:
      *(char *)puVar3 = (char)local_94;
      local_94 = local_94 >> 8 | uVar1 << 0x18;
      uVar1 = (int)uVar1 >> 8;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      uVar4 = uVar1 | local_94;
    }
  }
  hash_step(param_2,puVar7);
  hash_step();
  iVar2 = *(int *)(in_GS_OFFSET + 0x14);
  *param_2 = local_60;
  param_2[1] = local_5c;
  param_2[2] = local_58;
  param_2[3] = local_54;
  param_2[4] = local_50;
  param_2[5] = local_4c;
  param_2[6] = local_48;
  param_2[7] = local_44;
  if (local_20 != iVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}

