
void gost_mac_iv(int *param_1,uint param_2,uint *param_3,int param_4,uint param_5,void *param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  size_t __n;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  
  local_3c = *param_3;
  local_38 = param_3[1];
  local_2c = __TMC_END__;
  if (param_5 < 8) {
    uVar4 = 8;
    uVar2 = 0;
  }
  else {
    uVar9 = local_3c & 0xff;
    uVar7 = local_3c >> 8 & 0xff;
    uVar11 = local_3c >> 0x10 & 0xff;
    uVar8 = local_38 & 0xff;
    uVar10 = local_38 >> 8 & 0xff;
    uVar6 = local_38 >> 0x10 & 0xff;
    uVar1 = 0;
    uVar4 = 8;
    do {
      uVar2 = uVar4;
      iVar3 = param_4 + uVar1;
      uVar4 = uVar2 + 8;
      local_3c = (uVar11 ^ *(byte *)(iVar3 + 2)) << 0x10 | (uVar7 ^ *(byte *)(iVar3 + 1)) << 8 |
                 uVar9 ^ *(byte *)(param_4 + uVar1) |
                 (local_3c >> 0x18 ^ (uint)*(byte *)(iVar3 + 3)) << 0x18;
      uVar1 = *param_1 + local_3c;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_38 = ((uVar6 ^ *(byte *)(iVar3 + 6)) << 0x10 | (uVar10 ^ *(byte *)(iVar3 + 5)) << 8 |
                  uVar8 ^ *(byte *)(iVar3 + 4) |
                 (local_38 >> 0x18 ^ (uint)*(byte *)(iVar3 + 7)) << 0x18) ^
                 (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[1] + local_38;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_3c = local_3c ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[2] + local_3c;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_38 = local_38 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[3] + local_38;
      uVar1 = param_1[(uVar1 * 0x10000 >> 0x18) + 0x208] |
              param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108];
      local_3c = local_3c ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[4] + local_3c;
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_38 = local_38 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[5] + local_38;
      uVar1 = param_1[(uVar1 * 0x10000 >> 0x18) + 0x208] |
              param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108];
      local_3c = local_3c ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[6] + local_3c;
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_38 = local_38 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[7] + local_38;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_3c = local_3c ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = *param_1 + local_3c;
      uVar1 = param_1[(uVar1 * 0x100 >> 0x18) + 0x108] |
              param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_38 = local_38 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[1] + local_38;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_3c = local_3c ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[2] + local_3c;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_38 = local_38 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[3] + local_38;
      uVar1 = param_1[(uVar1 * 0x10000 >> 0x18) + 0x208] |
              param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108];
      local_3c = local_3c ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[4] + local_3c;
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_38 = local_38 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[5] + local_38;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_3c = local_3c ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[6] + local_3c;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_38 = local_38 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar10 = (local_38 << 0x10) >> 0x18;
      uVar1 = param_1[7] + local_38;
      uVar8 = local_38 & 0xff;
      uVar6 = (local_38 << 8) >> 0x18;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      local_3c = local_3c ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar7 = (local_3c << 0x10) >> 0x18;
      uVar11 = (local_3c << 8) >> 0x18;
      uVar9 = local_3c & 0xff;
      uVar1 = uVar2;
    } while (uVar4 <= param_5);
    local_3c = uVar9 | uVar7 << 8 | uVar11 << 0x10 | local_3c & 0xff000000;
    local_38 = uVar8 | uVar10 << 8 | uVar6 << 0x10 | local_38 & 0xff000000;
  }
  if (uVar2 < param_5) {
    local_30 = 0;
    local_34 = 0;
    __memcpy_chk(&local_34,param_4 + uVar2,param_5 - uVar2,8);
    mac_block(param_1,&local_3c,&local_34);
    uVar2 = uVar4;
  }
  if (uVar2 == 8) {
    local_30 = 0;
    local_34 = 0;
    mac_block(param_1,&local_3c,&local_34);
  }
  __n = (int)param_2 >> 3;
  param_2 = param_2 & 7;
  bVar5 = (byte)param_2;
  if ((param_2 != 0) && (bVar5 = 0xff, param_2 != 1)) {
    bVar5 = 0;
  }
  if ((int)__n < 1) {
    __n = 0;
  }
  else {
    memcpy(param_6,&local_3c,__n);
  }
  if (param_2 != 0) {
    *(byte *)((int)param_6 + __n) = bVar5 & *(byte *)((int)&local_3c + __n);
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(1);
}

