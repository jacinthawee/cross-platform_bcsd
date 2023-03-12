
void gost_mac(int *param_1,uint param_2,int param_3,uint param_4,void *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  size_t __n;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  
  uVar8 = 0;
  local_2c = __TMC_END__;
  local_3c = 0;
  local_38 = 0;
  if (param_4 < 8) {
    uVar6 = 8;
  }
  else {
    uVar10 = 0;
    uVar14 = 0;
    uVar12 = 0;
    uVar15 = 0;
    uVar11 = 0;
    uVar13 = 0;
    uVar2 = 0;
    uVar3 = 0;
    uVar6 = 8;
    uVar9 = uVar8;
    do {
      uVar8 = uVar6;
      iVar5 = param_3 + uVar3;
      uVar6 = uVar8 + 8;
      uVar1 = (uVar15 ^ *(byte *)(iVar5 + 2)) << 0x10 | (uVar11 ^ *(byte *)(iVar5 + 1)) << 8 |
              uVar13 ^ *(byte *)(param_3 + uVar3) | (uVar2 ^ *(byte *)(iVar5 + 3)) << 0x18;
      uVar3 = *param_1 + uVar1;
      uVar3 = param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar4 = ((uVar10 ^ *(byte *)(iVar5 + 6)) << 0x10 | (uVar14 ^ *(byte *)(iVar5 + 5)) << 8 |
               uVar12 ^ *(byte *)(iVar5 + 4) | (uVar9 ^ *(byte *)(iVar5 + 7)) << 0x18) ^
              (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[1] + uVar4;
      uVar3 = param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar1 = uVar1 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[2] + uVar1;
      uVar3 = param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar4 = uVar4 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[3] + uVar4;
      uVar3 = param_1[(uVar3 * 0x10000 >> 0x18) + 0x208] |
              param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108];
      uVar1 = uVar1 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[4] + uVar1;
      uVar3 = param_1[(uVar3 >> 0x18) + 8] | param_1[(uVar3 & 0xff) + 0x308] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar4 = uVar4 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[5] + uVar4;
      uVar3 = param_1[(uVar3 * 0x10000 >> 0x18) + 0x208] |
              param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108];
      uVar1 = uVar1 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[6] + uVar1;
      uVar3 = param_1[(uVar3 >> 0x18) + 8] | param_1[(uVar3 & 0xff) + 0x308] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar4 = uVar4 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[7] + uVar4;
      uVar3 = param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar1 = uVar1 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = *param_1 + uVar1;
      uVar3 = param_1[(uVar3 * 0x100 >> 0x18) + 0x108] |
              param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar4 = uVar4 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[1] + uVar4;
      uVar3 = param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar1 = uVar1 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[2] + uVar1;
      uVar3 = param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar4 = uVar4 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[3] + uVar4;
      uVar3 = param_1[(uVar3 * 0x10000 >> 0x18) + 0x208] |
              param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108];
      uVar1 = uVar1 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[4] + uVar1;
      uVar3 = param_1[(uVar3 >> 0x18) + 8] | param_1[(uVar3 & 0xff) + 0x308] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar4 = uVar4 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[5] + uVar4;
      uVar3 = param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar1 = uVar1 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar3 = param_1[6] + uVar1;
      uVar3 = param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar4 = uVar4 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar14 = (uVar4 << 0x10) >> 0x18;
      uVar3 = param_1[7] + uVar4;
      uVar12 = uVar4 & 0xff;
      uVar10 = (uVar4 << 8) >> 0x18;
      uVar9 = uVar4 >> 0x18;
      uVar3 = param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      uVar1 = uVar1 ^ (uVar3 >> 0x15 | uVar3 << 0xb);
      uVar11 = (uVar1 << 0x10) >> 0x18;
      uVar15 = (uVar1 << 8) >> 0x18;
      uVar13 = uVar1 & 0xff;
      uVar2 = uVar1 >> 0x18;
      uVar3 = uVar8;
    } while (uVar6 <= param_4);
    local_3c = uVar13 | uVar11 << 8 | uVar15 << 0x10 | uVar1 & 0xff000000;
    local_38 = uVar12 | uVar14 << 8 | uVar10 << 0x10 | uVar4 & 0xff000000;
  }
  if (uVar8 < param_4) {
    local_30 = 0;
    local_34 = 0;
    __memcpy_chk(&local_34,param_3 + uVar8,param_4 - uVar8,8);
    mac_block(param_1,&local_3c,&local_34);
    uVar8 = uVar6;
  }
  if (uVar8 == 8) {
    local_30 = 0;
    local_34 = 0;
    mac_block(param_1,&local_3c,&local_34);
  }
  __n = (int)param_2 >> 3;
  param_2 = param_2 & 7;
  bVar7 = (byte)param_2;
  if ((param_2 != 0) && (bVar7 = 0xff, param_2 != 1)) {
    bVar7 = 0;
  }
  if ((int)__n < 1) {
    __n = 0;
  }
  else {
    memcpy(param_5,&local_3c,__n);
  }
  if (param_2 != 0) {
    *(byte *)((int)param_5 + __n) = bVar7 & *(byte *)((int)&local_3c + __n);
  }
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(1);
}

