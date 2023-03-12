
void finish_hash(uint *param_1,uint *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  undefined4 local_8c [4];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  uint uStack_68;
  uint uStack_64;
  uint uStack_60;
  uint local_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint local_4c [4];
  uint local_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  int local_2c;
  
  local_6c = param_1[4];
  uStack_68 = param_1[5];
  uStack_64 = param_1[6];
  uStack_60 = param_1[7];
  uVar6 = *param_1;
  uVar7 = param_1[1];
  local_5c = param_1[8];
  uStack_58 = param_1[9];
  uStack_54 = param_1[10];
  uStack_50 = param_1[0xb];
  local_4c[0] = param_1[0xc];
  local_2c = __TMC_END__;
  local_4c[1] = param_1[0xd];
  local_4c[2] = param_1[0xe];
  local_4c[3] = param_1[0xf];
  uStack_34 = param_1[0x12];
  local_3c = param_1[0x10];
  uStack_38 = param_1[0x11];
  uStack_30 = param_1[0x13];
  if (param_1[3] != 0) {
    local_8c[0] = 0;
    local_8c[1] = 0;
    local_8c[2] = 0;
    local_8c[3] = 0;
    local_7c = 0;
    local_78 = 0;
    local_74 = 0;
    local_70 = 0;
    __memcpy_chk(local_8c,param_1 + 0x14,param_1[3],0x20);
    hash_step(param_1[2],&local_6c,local_8c);
    iVar2 = 0;
    iVar4 = 0;
    do {
      iVar2 = iVar2 + (uint)*(byte *)((int)local_8c + iVar4) +
                      (uint)*(byte *)((int)local_4c + iVar4);
      *(char *)((int)local_4c + iVar4) = (char)iVar2;
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 >> 8;
    } while (iVar4 != 0x20);
    uVar5 = param_1[3];
    bVar8 = CARRY4(uVar6,uVar5);
    uVar6 = uVar6 + uVar5;
    uVar7 = uVar7 + ((int)uVar5 >> 0x1f) + (uint)bVar8;
  }
  uVar5 = uVar6 << 3;
  uVar6 = uVar7 << 3 | uVar6 >> 0x1d;
  local_8c[0] = 0;
  local_8c[1] = 0;
  local_8c[2] = 0;
  local_8c[3] = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  puVar1 = local_8c;
  if ((int)(uVar6 - (uVar5 == 0)) < 0 == (SBORROW4(uVar6,(uint)(uVar5 == 0)) != false)) {
    do {
      uVar7 = (int)uVar6 >> 8;
      uVar3 = uVar5 >> 8 | uVar6 << 0x18;
      *(char *)puVar1 = (char)uVar5;
      puVar1 = (undefined4 *)((int)puVar1 + 1);
      uVar5 = uVar3;
      uVar6 = uVar7;
    } while ((uVar3 | uVar7) != 0);
  }
  hash_step(param_1[2],&local_6c,local_8c);
  hash_step(param_1[2],&local_6c,local_4c);
  *param_2 = local_6c;
  param_2[1] = uStack_68;
  param_2[2] = uStack_64;
  param_2[3] = uStack_60;
  bVar8 = local_2c == __TMC_END__;
  param_2[4] = local_5c;
  param_2[5] = uStack_58;
  param_2[6] = uStack_54;
  param_2[7] = uStack_50;
  if (bVar8) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(1);
}

