
void finish_hash(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  undefined4 *local_90;
  int local_8c;
  undefined4 local_84 [4];
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 local_44 [4];
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int local_24;
  
  local_64 = param_1[4];
  local_90 = (undefined4 *)*param_1;
  local_8c = param_1[1];
  uStack_60 = param_1[5];
  uStack_5c = param_1[6];
  uStack_58 = param_1[7];
  local_54 = param_1[8];
  uStack_50 = param_1[9];
  uStack_4c = param_1[10];
  uStack_48 = param_1[0xb];
  local_24 = __stack_chk_guard;
  local_44[0] = param_1[0xc];
  local_44[1] = param_1[0xd];
  local_44[2] = param_1[0xe];
  local_44[3] = param_1[0xf];
  uStack_2c = param_1[0x12];
  local_34 = param_1[0x10];
  uStack_30 = param_1[0x11];
  uStack_28 = param_1[0x13];
  if (param_1[3] != 0) {
    local_84[0] = 0;
    local_84[1] = 0;
    local_84[2] = 0;
    local_84[3] = 0;
    local_74 = 0;
    local_70 = 0;
    local_6c = 0;
    local_68 = 0;
    __memcpy_chk(local_84,param_1 + 0x14,param_1[3],0x20);
    hash_step(param_1[2],&local_64,local_84);
    iVar2 = 0;
    iVar4 = 0;
    do {
      iVar2 = iVar2 + (uint)*(byte *)((int)local_84 + iVar4) +
                      (uint)*(byte *)((int)local_44 + iVar4);
      *(char *)((int)local_44 + iVar4) = (char)iVar2;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 >> 8;
    } while (iVar4 != 0x20);
    uVar5 = param_1[3];
    bVar7 = CARRY4((uint)local_90,uVar5);
    local_90 = (undefined4 *)((int)local_90 + uVar5);
    local_8c = local_8c + ((int)uVar5 >> 0x1f) + (uint)bVar7;
  }
  local_84[0] = 0;
  uVar5 = (int)local_90 << 3;
  local_84[1] = 0;
  uVar6 = local_8c << 3 | (uint)local_90 >> 0x1d;
  local_84[2] = 0;
  bVar8 = SBORROW4(uVar6,(uint)(uVar5 == 0)) != false;
  bVar7 = (int)(uVar6 - (uVar5 == 0)) < 0;
  local_84[3] = 0;
  local_74 = 0;
  local_70 = 0;
  if (bVar7 == bVar8) {
    local_90 = local_84;
  }
  local_6c = 0;
  local_68 = 0;
  if (bVar7 == bVar8) {
    do {
      uVar1 = (int)uVar6 >> 8;
      uVar3 = uVar5 >> 8 | uVar6 << 0x18;
      *(char *)local_90 = (char)uVar5;
      local_90 = (undefined4 *)((int)local_90 + 1);
      uVar5 = uVar3;
      uVar6 = uVar1;
    } while ((uVar3 | uVar1) != 0);
  }
  hash_step(param_1[2],&local_64,local_84);
  hash_step(param_1[2],&local_64,local_44);
  *param_2 = local_64;
  param_2[1] = uStack_60;
  param_2[2] = uStack_5c;
  param_2[3] = uStack_58;
  bVar7 = local_24 == __stack_chk_guard;
  param_2[4] = local_54;
  param_2[5] = uStack_50;
  param_2[6] = uStack_4c;
  param_2[7] = uStack_48;
  if (bVar7) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(1);
}

