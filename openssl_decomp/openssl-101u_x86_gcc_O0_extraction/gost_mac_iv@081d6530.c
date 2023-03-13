
/* WARNING: Could not reconcile some variable overlaps */

undefined4
gost_mac_iv(int *param_1,uint param_2,uint *param_3,byte *param_4,uint param_5,void *param_6)

{
  uint uVar1;
  uint uVar2;
  size_t __n;
  uint uVar3;
  uint uVar4;
  int in_GS_OFFSET;
  byte *local_a4;
  uint local_a0;
  uint local_9c;
  uint local_8c;
  byte local_7c;
  byte local_6c;
  byte local_65;
  uint local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_2c = param_3[1];
  local_30 = *param_3;
  if (param_5 < 8) {
    if (param_5 == 0) goto LAB_081d6b2b;
    local_a0 = 0;
    uVar1 = 8;
LAB_081d6bb8:
    local_28 = 0;
    local_24 = 0;
    __memcpy_chk(&local_28,param_4 + local_a0,param_5 - local_a0,8);
    mac_block(param_1,&local_30,&local_28);
    local_a0 = uVar1;
  }
  else {
    uVar4 = local_30 >> 0x10 & 0xff;
    uVar2 = local_30 & 0xff;
    uVar3 = local_30 >> 8 & 0xff;
    local_a4 = param_4;
    local_a0 = 8;
    local_65 = (byte)local_2c;
    local_9c = local_2c >> 8 & 0xff;
    local_8c = local_2c >> 0x10 & 0xff;
    uVar1 = local_a0;
    do {
      local_a0 = uVar1;
      local_6c = (byte)(local_30 >> 0x18);
      local_7c = (byte)(local_2c >> 0x18);
      uVar2 = (uint)(local_6c ^ local_a4[3]) << 0x18 |
              (uint)(byte)((byte)uVar3 ^ local_a4[1]) << 8 |
              (uint)(byte)((byte)uVar4 ^ local_a4[2]) << 0x10 |
              (uint)(byte)((byte)uVar2 ^ *local_a4);
      uVar1 = uVar2 + *param_1;
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      local_2c = (uVar1 << 0xb | uVar1 >> 0x15) ^
                 ((uint)((byte)local_9c ^ local_a4[5]) << 8 |
                  (uint)((byte)local_8c ^ local_a4[6]) << 0x10 | (uint)(local_65 ^ local_a4[4]) |
                 (uint)(local_7c ^ local_a4[7]) << 0x18);
      uVar1 = local_2c + param_1[1];
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      uVar2 = uVar2 ^ (uVar1 << 0xb | uVar1 >> 0x15);
      uVar1 = param_1[2] + uVar2;
      uVar1 = param_1[(uVar1 >> 0x10 & 0xff) + 0x108] |
              param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 8 & 0xff) + 0x208];
      local_2c = (uVar1 << 0xb | uVar1 >> 0x15) ^ local_2c;
      uVar1 = param_1[3] + local_2c;
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      uVar2 = (uVar1 << 0xb | uVar1 >> 0x15) ^ uVar2;
      uVar1 = uVar2 + param_1[4];
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      local_2c = (uVar1 << 0xb | uVar1 >> 0x15) ^ local_2c;
      uVar1 = local_2c + param_1[5];
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      uVar2 = (uVar1 << 0xb | uVar1 >> 0x15) ^ uVar2;
      uVar1 = uVar2 + param_1[6];
      uVar1 = param_1[(uVar1 >> 8 & 0xff) + 0x208] |
              param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108];
      local_2c = (uVar1 << 0xb | uVar1 >> 0x15) ^ local_2c;
      uVar1 = local_2c + param_1[7];
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      uVar2 = (uVar1 << 0xb | uVar1 >> 0x15) ^ uVar2;
      uVar1 = uVar2 + *param_1;
      uVar1 = param_1[(uVar1 >> 0x10 & 0xff) + 0x108] |
              param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 8 & 0xff) + 0x208];
      local_2c = local_2c ^ (uVar1 << 0xb | uVar1 >> 0x15);
      uVar1 = local_2c + param_1[1];
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      uVar2 = (uVar1 << 0xb | uVar1 >> 0x15) ^ uVar2;
      uVar1 = param_1[2] + uVar2;
      uVar1 = param_1[(uVar1 >> 0x10 & 0xff) + 0x108] |
              param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 8 & 0xff) + 0x208];
      local_2c = (uVar1 << 0xb | uVar1 >> 0x15) ^ local_2c;
      uVar1 = param_1[3] + local_2c;
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      uVar2 = (uVar1 << 0xb | uVar1 >> 0x15) ^ uVar2;
      uVar1 = uVar2 + param_1[4];
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      local_2c = (uVar1 << 0xb | uVar1 >> 0x15) ^ local_2c;
      uVar1 = local_2c + param_1[5];
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      uVar2 = (uVar1 << 0xb | uVar1 >> 0x15) ^ uVar2;
      uVar1 = uVar2 + param_1[6];
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      local_2c = (uVar1 << 0xb | uVar1 >> 0x15) ^ local_2c;
      uVar1 = local_2c + param_1[7];
      local_a4 = local_a4 + 8;
      local_65 = (byte)local_2c;
      uVar1 = param_1[(uVar1 >> 0x18) + 8] | param_1[(uVar1 & 0xff) + 0x308] |
              param_1[(uVar1 >> 0x10 & 0xff) + 0x108] | param_1[(uVar1 >> 8 & 0xff) + 0x208];
      uVar2 = (uVar1 << 0xb | uVar1 >> 0x15) ^ uVar2;
      uVar3 = uVar2 >> 8;
      local_9c = local_2c >> 8;
      uVar4 = uVar2 >> 0x10;
      local_8c = local_2c >> 0x10;
      uVar1 = local_a0 + 8;
      local_30 = uVar2;
    } while (uVar1 <= param_5);
    local_30 = uVar2 & 0xffff | (uVar4 & 0xff) << 0x10 | uVar2 & 0xff000000;
    if (local_a0 < param_5) goto LAB_081d6bb8;
  }
  if (local_a0 == 8) {
    local_28 = 0;
    local_24 = 0;
    mac_block(param_1,&local_30,&local_28);
  }
LAB_081d6b2b:
  __n = (int)param_2 >> 3;
  if ((int)__n < 1) {
    __n = 0;
  }
  else {
    memcpy(param_6,&local_30,__n);
  }
  if ((param_2 & 7) != 0) {
    *(byte *)((int)param_6 + __n) = -((param_2 & 7) == 1) & *(byte *)((int)&local_30 + __n);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

