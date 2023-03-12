
uint gost_mac(int *param_1,byte **param_2,undefined4 *param_3,byte **param_4,byte *param_5)

{
  undefined *puVar1;
  uint uVar2;
  byte bVar6;
  undefined uVar7;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint extraout_v1;
  uint uVar8;
  int *piVar9;
  uint *puVar10;
  uint *puVar11;
  undefined4 *puVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  undefined *puVar20;
  char *pcVar21;
  char *pcVar22;
  byte **ppbVar23;
  uint *puVar24;
  int unaff_s2;
  byte *pbVar25;
  int unaff_s3;
  int unaff_s4;
  int unaff_s5;
  uint *puVar26;
  int unaff_s6;
  int unaff_s7;
  uint uVar27;
  code *pcVar28;
  undefined *puVar29;
  int iVar30;
  int iVar31;
  undefined *puVar32;
  int unaff_s8;
  undefined4 uVar33;
  undefined auStack_140 [16];
  undefined *puStack_130;
  uint uStack_124;
  uint uStack_120;
  byte bStack_11c;
  byte bStack_11b;
  byte bStack_11a;
  byte bStack_119;
  byte bStack_118;
  byte bStack_117;
  byte bStack_116;
  byte bStack_115;
  byte bStack_114;
  byte bStack_113;
  byte bStack_112;
  byte bStack_111;
  byte bStack_110;
  byte bStack_10f;
  byte bStack_10e;
  byte bStack_10d;
  byte bStack_10c;
  byte bStack_10b;
  byte bStack_10a;
  byte bStack_109;
  byte bStack_108;
  byte bStack_107;
  byte bStack_106;
  byte bStack_105;
  byte bStack_104;
  byte bStack_103;
  byte bStack_102;
  byte bStack_101;
  byte bStack_100;
  byte bStack_ff;
  byte bStack_fe;
  byte bStack_fd;
  uint uStack_fc;
  undefined *puStack_f8;
  uint uStack_f4;
  int iStack_f0;
  int iStack_ec;
  int iStack_e8;
  int iStack_e4;
  int iStack_e0;
  int iStack_dc;
  int iStack_d8;
  code *pcStack_d4;
  undefined *puStack_c0;
  uint uStack_b8;
  int iStack_b4;
  uint **ppuStack_b0;
  byte *pbStack_ac;
  uint uStack_a4;
  uint uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  uint *puStack_94;
  undefined4 *puStack_90;
  uint uStack_8c;
  int iStack_88;
  int iStack_84;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  int iStack_74;
  int iStack_70;
  code *pcStack_6c;
  byte **ppbStack_64;
  uint *local_58;
  int iStack_54;
  uint local_50;
  byte *local_4c;
  int **local_48;
  undefined4 *local_44;
  byte *local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  int *local_2c;
  
  local_48 = (int **)PTR___stack_chk_guard_006aabf0;
  uVar2 = (uint)(param_4 < &DAT_00000008);
  local_58 = (uint *)&_gp;
  local_3c = (byte *)0x0;
  local_38 = 0;
  local_44 = param_3;
  local_4c = param_5;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (uVar2 == 0) {
    unaff_s7 = *param_1;
    unaff_s6 = param_1[1];
    uVar17 = 0;
    unaff_s5 = param_1[2];
    uVar18 = 0;
    unaff_s4 = param_1[3];
    uVar19 = 0;
    unaff_s3 = param_1[4];
    uVar15 = 0;
    unaff_s2 = param_1[5];
    puVar12 = (undefined4 *)0x0;
    uVar27 = 0;
    unaff_s8 = param_1[7];
    uVar8 = 0;
    ppbVar23 = (byte **)&DAT_00000008;
    puVar16 = param_3;
    do {
      ppbStack_64 = ppbVar23;
      ppbVar23 = ppbStack_64 + 2;
      local_50 = (uint)(param_4 < ppbVar23);
      uVar15 = (uVar8 ^ *(byte *)((int)puVar16 + 1)) << 8 |
               ((uint)puVar12 ^ (uint)*(byte *)((int)puVar16 + 2)) << 0x10 |
               uVar27 ^ *(byte *)puVar16 | (uVar15 ^ *(byte *)((int)puVar16 + 3)) << 0x18;
      uVar8 = uVar15 + unaff_s7;
      uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
              param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
      uVar2 = (uVar8 >> 0x15) + uVar8 * 0x800 ^
              ((uVar18 ^ *(byte *)((int)puVar16 + 5)) << 8 |
               (uVar17 ^ *(byte *)((int)puVar16 + 6)) << 0x10 | uVar19 ^ *(byte *)(puVar16 + 1) |
              (uVar2 ^ *(byte *)((int)puVar16 + 7)) << 0x18);
      uVar18 = uVar2 + unaff_s6;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar15 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar15;
      uVar18 = uVar15 + unaff_s5;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar2 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar2;
      uVar18 = uVar2 + unaff_s4;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar15 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar15;
      uVar18 = uVar15 + unaff_s3;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar2 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar2;
      uVar18 = uVar2 + unaff_s2;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar15 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar15;
      uVar18 = uVar15 + param_1[6];
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar2 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar2;
      uVar18 = uVar2 + unaff_s8;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar15 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar15;
      uVar18 = uVar15 + unaff_s7;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar2 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar2;
      uVar18 = uVar2 + unaff_s6;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar15 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar15;
      uVar18 = uVar15 + unaff_s5;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar2 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar2;
      uVar18 = uVar2 + unaff_s4;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar15 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar15;
      uVar18 = uVar15 + unaff_s3;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar2 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar2;
      uVar18 = uVar2 + unaff_s2;
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar15 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar15;
      uVar18 = uVar15 + param_1[6];
      uVar18 = param_1[(uVar18 >> 0x18) + 8] | param_1[(uVar18 & 0xff) + 0x308] |
               param_1[(uVar18 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar18 * 0x10000 >> 0x18) + 0x208];
      uVar2 = (uVar18 >> 0x15) + uVar18 * 0x800 ^ uVar2;
      uVar8 = uVar2 + unaff_s8;
      uVar19 = uVar2 & 0xff;
      uVar18 = (uVar2 << 0x10) >> 0x18;
      uVar17 = (uVar2 << 8) >> 0x18;
      uVar2 = uVar2 >> 0x18;
      uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
              param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
      uVar15 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar15;
      uVar27 = uVar15 & 0xff;
      uVar8 = (uVar15 << 0x10) >> 0x18;
      puVar12 = (undefined4 *)((uVar15 << 8) >> 0x18);
      uVar15 = uVar15 >> 0x18;
      puVar16 = puVar16 + 2;
    } while (param_4 < ppbVar23 == 0);
    param_5 = (byte *)(uVar27 << 0x18 | uVar8 << 0x10 | (int)puVar12 << 8 | uVar15);
    local_38 = uVar19 << 0x18 | uVar18 << 0x10 | uVar17 << 8 | uVar2;
    local_3c = param_5;
    if (ppbStack_64 < param_4) {
LAB_00617f30:
      param_5 = &DAT_00000008;
      local_34 = 0;
      local_30 = 0;
      puVar12 = (undefined4 *)
                (*(code *)PTR___memcpy_chk_006aab54)
                          (&local_34,(byte *)((int)param_3 + (int)ppbStack_64),
                           (int)param_4 - (int)ppbStack_64);
      mac_block(param_1,&local_3c);
      ppbStack_64 = ppbVar23;
    }
    param_3 = puVar12;
    if (ppbStack_64 == (byte **)&DAT_00000008) {
      param_3 = &local_34;
      local_34 = 0;
      ppbStack_64 = &local_3c;
      local_30 = 0;
      mac_block(param_1);
    }
  }
  else {
    ppbStack_64 = param_2;
    if (param_4 != (byte **)0x0) {
      ppbStack_64 = (byte **)0x0;
      ppbVar23 = (byte **)&DAT_00000008;
      goto LAB_00617f30;
    }
  }
  puVar12 = (undefined4 *)((int)param_2 >> 3);
  uStack_8c = (uint)param_2 & 7;
  if ((int)puVar12 < 1) {
    puVar12 = (undefined4 *)0x0;
  }
  else {
    ppbStack_64 = &local_3c;
    param_3 = puVar12;
    (*(code *)local_58[-0x14bb])(local_4c);
  }
  puStack_90 = puVar12;
  if (uStack_8c != 0) {
    uStack_8c = uStack_8c ^ 1;
    puStack_90 = (undefined4 *)(local_4c + (int)puVar12);
    bVar6 = *(byte *)((int)&local_3c + (int)puVar12);
    if (uStack_8c != 0) {
      bVar6 = 0;
    }
    *(byte *)puStack_90 = bVar6;
  }
  if (local_2c == *local_48) {
    return 1;
  }
  pcStack_6c = gost_mac_iv;
  piVar9 = local_2c;
  (*(code *)local_58[-0x14ca])();
  iStack_70 = unaff_s8;
  iStack_74 = unaff_s7;
  iStack_78 = unaff_s6;
  iStack_7c = unaff_s5;
  iStack_80 = unaff_s4;
  iStack_84 = unaff_s3;
  iStack_88 = unaff_s2;
  puStack_c0 = &_gp;
  uVar2 = (uint)param_3 & 3;
  ppuStack_b0 = (uint **)PTR___stack_chk_guard_006aabf0;
  uStack_a0 = param_3[1];
  puVar10 = *(uint **)PTR___stack_chk_guard_006aabf0;
  uVar18 = (uint)(byte *)((int)param_3 + 3) & 3;
  uStack_a4 = (*(int *)((int)param_3 - uVar2) << uVar2 * 8 |
              extraout_v1 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar18 + 1) * 8 |
              *(uint *)((byte *)((int)param_3 + 3) + -uVar18) >> (3 - uVar18) * 8;
  pbStack_ac = param_5;
  puStack_94 = puVar10;
  iStack_b4 = iStack_54;
  if (local_58 < &DAT_00000008) {
    if (local_58 == (uint *)0x0) goto LAB_0061880c;
    puVar10 = (uint *)0x0;
    puVar14 = (uint *)&DAT_00000008;
LAB_006188a0:
    uStack_9c = 0;
    uStack_98 = 0;
    uVar33 = (*(code *)PTR___memcpy_chk_006aab54)
                       (&uStack_9c,param_5 + (int)puVar10,(int)local_58 - (int)puVar10,8);
    mac_block(piVar9,&uStack_a4,uVar33);
    puVar10 = puVar14;
  }
  else {
    unaff_s7 = *piVar9;
    unaff_s6 = piVar9[1];
    unaff_s5 = piVar9[2];
    unaff_s4 = piVar9[3];
    unaff_s3 = piVar9[4];
    unaff_s2 = piVar9[5];
    unaff_s8 = piVar9[7];
    uVar15 = uStack_a4 >> 0x18;
    uVar17 = uStack_a4 >> 0x10 & 0xff;
    uVar8 = uStack_a4 >> 8 & 0xff;
    uStack_a4 = uStack_a4 & 0xff;
    uVar19 = uStack_a0 >> 0x18;
    uVar2 = uStack_a0 >> 0x10 & 0xff;
    uVar18 = uStack_a0 >> 8 & 0xff;
    uStack_a0 = uStack_a0 & 0xff;
    puVar14 = (uint *)&DAT_00000008;
    pbVar25 = param_5;
    do {
      puVar10 = puVar14;
      puVar14 = puVar10 + 2;
      uStack_b8 = (uint)(local_58 < puVar14);
      uStack_a4 = (uVar17 ^ pbVar25[1]) << 8 | (uVar8 ^ pbVar25[2]) << 0x10 | uVar15 ^ *pbVar25 |
                  (uStack_a4 ^ pbVar25[3]) << 0x18;
      uVar17 = uStack_a4 + unaff_s7;
      uVar17 = piVar9[(uVar17 >> 0x18) + 8] | piVar9[(uVar17 & 0xff) + 0x308] |
               piVar9[(uVar17 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar17 * 0x10000 >> 0x18) + 0x208]
      ;
      uStack_a0 = (uVar17 >> 0x15) + uVar17 * 0x800 ^
                  ((uVar2 ^ pbVar25[5]) << 8 | (uVar18 ^ pbVar25[6]) << 0x10 | uVar19 ^ pbVar25[4] |
                  (uStack_a0 ^ pbVar25[7]) << 0x18);
      uVar2 = uStack_a0 + unaff_s6;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a4 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a4;
      uVar2 = uStack_a4 + unaff_s5;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a0 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a0;
      uVar2 = uStack_a0 + unaff_s4;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a4 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a4;
      uVar2 = uStack_a4 + unaff_s3;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a0 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a0;
      uVar2 = uStack_a0 + unaff_s2;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a4 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a4;
      uVar2 = uStack_a4 + piVar9[6];
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a0 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a0;
      uVar2 = uStack_a0 + unaff_s8;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a4 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a4;
      uVar2 = uStack_a4 + unaff_s7;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a0 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a0;
      uVar2 = uStack_a0 + unaff_s6;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a4 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a4;
      uVar2 = uStack_a4 + unaff_s5;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a0 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a0;
      uVar2 = uStack_a0 + unaff_s4;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a4 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a4;
      uVar2 = uStack_a4 + unaff_s3;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a0 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a0;
      uVar2 = uStack_a0 + unaff_s2;
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a4 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a4;
      uVar2 = uStack_a4 + piVar9[6];
      uVar2 = piVar9[(uVar2 >> 0x18) + 8] | piVar9[(uVar2 & 0xff) + 0x308] |
              piVar9[(uVar2 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uStack_a0 = (uVar2 >> 0x15) + uVar2 * 0x800 ^ uStack_a0;
      uVar17 = uStack_a0 + unaff_s8;
      uVar19 = uStack_a0 & 0xff;
      uVar2 = (uStack_a0 << 0x10) >> 0x18;
      uVar18 = (uStack_a0 << 8) >> 0x18;
      uStack_a0 = uStack_a0 >> 0x18;
      uVar17 = piVar9[(uVar17 >> 0x18) + 8] | piVar9[(uVar17 & 0xff) + 0x308] |
               piVar9[(uVar17 * 0x100 >> 0x18) + 0x108] | piVar9[(uVar17 * 0x10000 >> 0x18) + 0x208]
      ;
      uStack_a4 = (uVar17 >> 0x15) + uVar17 * 0x800 ^ uStack_a4;
      uVar15 = uStack_a4 & 0xff;
      uVar17 = (uStack_a4 << 0x10) >> 0x18;
      uVar8 = (uStack_a4 << 8) >> 0x18;
      uStack_a4 = uStack_a4 >> 0x18;
      pbVar25 = pbVar25 + 8;
    } while (local_58 < puVar14 == 0);
    uStack_a0 = uVar19 << 0x18 | uVar2 << 0x10 | uVar18 << 8 | uStack_a0;
    uStack_a4 = uVar15 << 0x18 | uVar17 << 0x10 | uVar8 << 8 | uStack_a4;
    if (puVar10 < local_58) goto LAB_006188a0;
  }
  if (puVar10 == (uint *)&DAT_00000008) {
    uStack_9c = 0;
    puVar10 = &uStack_a4;
    uStack_98 = 0;
    mac_block(piVar9);
  }
LAB_0061880c:
  puVar20 = (undefined *)((int)ppbStack_64 >> 3);
  uStack_f4 = (uint)ppbStack_64 & 7;
  if ((int)puVar20 < 1) {
    puVar20 = (undefined *)0x0;
  }
  else {
    puVar10 = &uStack_a4;
    (**(code **)(puStack_c0 + -0x52ec))(iStack_b4,puVar10,puVar20);
  }
  puStack_f8 = puVar20;
  if (uStack_f4 != 0) {
    uStack_f4 = uStack_f4 ^ 1;
    puStack_f8 = puVar20 + iStack_b4;
    uVar7 = *(undefined *)((int)&uStack_a4 + (int)puVar20);
    if (uStack_f4 != 0) {
      uVar7 = 0;
    }
    *puStack_f8 = uVar7;
  }
  if (puStack_94 == *ppuStack_b0) {
    return 1;
  }
  pcStack_d4 = cryptopro_key_meshing;
  puVar24 = puStack_94;
  (**(code **)(puStack_c0 + -0x5328))();
  puVar14 = (uint *)PTR___stack_chk_guard_006aabf0;
  puVar32 = auStack_140;
  pbVar25 = &bStack_11c;
  puStack_130 = &_gp;
  uStack_fc = *(uint *)PTR___stack_chk_guard_006aabf0;
  pcVar21 = CryptoProKeyMeshingKey;
  iStack_f0 = unaff_s2;
  iStack_ec = unaff_s3;
  iStack_e8 = unaff_s4;
  iStack_e4 = unaff_s5;
  iStack_e0 = unaff_s6;
  iStack_dc = unaff_s7;
  iStack_d8 = unaff_s8;
  do {
    pcVar22 = pcVar21 + 8;
    gostdecrypt(puVar24,pcVar21,pbVar25);
    pbVar25 = pbVar25 + 8;
    pcVar21 = pcVar22;
  } while (pcVar22 != "gost94_keyx.c");
  puVar11 = &uStack_124;
  puVar20 = (undefined *)((uint)bStack_115 << 0x18);
  puVar26 = (uint *)(uint)bStack_108;
  uVar18 = (uint)bStack_119 << 0x18;
  puVar24[4] = (uint)bStack_10b << 8 | (uint)bStack_10a << 0x10 | (uint)bStack_10c |
               (uint)bStack_109 << 0x18;
  puVar24[5] = (uint)bStack_107 << 8 | (uint)bStack_106 << 0x10 | (uint)puVar26 |
               (uint)bStack_105 << 0x18;
  *puVar24 = (uint)bStack_11a << 0x10 | (uint)bStack_11b << 8 | (uint)bStack_11c | uVar18;
  puVar24[1] = (uint)bStack_116 << 0x10 | (uint)bStack_117 << 8 | (uint)bStack_118 | (uint)puVar20;
  puVar24[2] = (uint)bStack_113 << 8 | (uint)bStack_112 << 0x10 | (uint)bStack_114 |
               (uint)bStack_111 << 0x18;
  puVar24[3] = (uint)bStack_10f << 8 | (uint)bStack_10e << 0x10 | (uint)bStack_110 |
               (uint)bStack_10d << 0x18;
  puVar24[7] = (uint)bStack_ff << 8 | (uint)bStack_fe << 0x10 | (uint)bStack_100 |
               (uint)bStack_fd << 0x18;
  puVar24[6] = (uint)bStack_103 << 8 | (uint)bStack_102 << 0x10 | (uint)bStack_104 |
               (uint)bStack_101 << 0x18;
  puVar5 = puVar10;
  gostcrypt(puVar24);
  *puVar10 = uStack_124;
  puVar10[1] = uStack_120;
  uVar2 = *puVar14;
  if (uStack_fc == uVar2) {
    return uVar2;
  }
  uVar33 = 0x618b84;
  uVar2 = uStack_fc;
  (**(code **)(puStack_130 + -0x5328))();
  uVar17 = (uint)bStack_110;
  while( true ) {
    puVar13 = puVar11;
    uVar8 = uVar2;
    puVar1 = PTR___stack_chk_guard_006aabf0;
    *(uint *)(puVar32 + -0x18) = uVar18;
    *(uint *)(puVar32 + -8) = uVar17;
    *(uint **)(puVar32 + -0xc) = puVar26;
    *(uint **)(puVar32 + -0x10) = puVar14;
    *(undefined **)(puVar32 + -0x1a0) = &_gp;
    *(undefined4 *)(puVar32 + -4) = uVar33;
    *(uint **)(puVar32 + -0x14) = puVar10;
    *(uint **)(puVar32 + -0x1c) = puVar24;
    *(undefined **)(puVar32 + -0x20) = puVar20;
    *(undefined4 *)(puVar32 + -0x24) = *(undefined4 *)PTR___stack_chk_guard_006aabf0;
    puVar11 = puVar5;
    puVar14 = puVar13;
    puVar3 = (uint *)(*(code *)PTR_DH_new_006a8618)();
    puVar29 = *(undefined **)(puVar32 + -0x1a0);
    if (puVar3 == (uint *)0x0) {
      uVar2 = 0;
      puVar26 = puVar5;
    }
    else {
      puVar10 = (uint *)(puVar32 + -0x124);
      (**(code **)(puVar29 + -0x53e0))(puVar10,0,0x80);
      puVar20 = puVar32 + -0xa4;
      uVar2 = (**(code **)(*(int *)(puVar32 + -0x1a0) + -0x6de0))(*(undefined4 *)(puVar5[5] + 0x14))
      ;
      iVar30 = *(int *)(puVar32 + -0x1a0);
      puVar3[3] = uVar2;
      uVar2 = (**(code **)(iVar30 + -0x6de0))(*(undefined4 *)(puVar5[5] + 0xc));
      pcVar28 = *(code **)(*(int *)(puVar32 + -0x1a0) + -0x6de0);
      puVar3[2] = uVar2;
      uVar2 = (*pcVar28)(uVar8);
      pcVar28 = *(code **)(*(int *)(puVar32 + -0x1a0) + -0x57fc);
      puVar3[6] = uVar2;
      iVar4 = (*pcVar28)(puVar5);
      puVar11 = *(uint **)(iVar4 + 0x18);
      puVar14 = puVar3;
      puVar26 = (uint *)(**(code **)(*(int *)(puVar32 + -0x1a0) + -0x6db4))(puVar20);
      puVar24 = puVar3;
      if (puVar26 == (uint *)0x0) {
        (**(code **)(*(int *)(puVar32 + -0x1a0) + -0x78dc))(puVar3);
        uVar2 = 0;
        puVar29 = *(undefined **)(puVar32 + -0x1a0);
      }
      else {
        (**(code **)(*(int *)(puVar32 + -0x1a0) + -0x53e0))(puVar10,0,0x80);
        iVar31 = *(int *)(puVar32 + -0x1a0);
        if (0 < (int)puVar26) {
          puVar20 = puVar20 + (int)((int)puVar26 + -1);
          puVar14 = puVar10;
          do {
            uVar7 = *puVar20;
            puVar20 = puVar20 + -1;
            *(undefined *)puVar14 = uVar7;
            puVar14 = (uint *)((int)puVar14 + 1);
          } while (puVar20 != puVar32 + -0xa5);
        }
        puVar20 = puVar32 + -0x198;
        (**(code **)(iVar31 + -0x78dc))(puVar3);
        init_gost_hash_ctx(puVar20,*(undefined4 *)(*(int *)(puVar32 + -0x1a0) + -0x5808));
        start_hash(puVar20);
        puVar14 = (uint *)&DAT_00000080;
        hash_block(puVar20,puVar10);
        puVar11 = puVar13;
        finish_hash(puVar20);
        done_gost_hash_ctx(puVar20);
        uVar2 = 1;
        puVar29 = *(undefined **)(puVar32 + -0x1a0);
      }
    }
    iVar4 = *(int *)(puVar32 + -0x24);
    if (iVar4 == *(int *)puVar1) break;
    pcVar28 = pkey_gost94_derive;
    (**(code **)(puVar29 + -0x5328))();
    *(code **)(puVar32 + -0x1b4) = pcVar28;
    *(undefined **)(puVar32 + -0x1b8) = puVar1;
    *(uint **)(puVar32 + -0x1bc) = puVar24;
    *(undefined **)(puVar32 + -0x1c0) = puVar20;
    *(undefined **)(puVar32 + -0x1c8) = &_gp;
    puVar5 = (uint *)(*(code *)PTR_EVP_PKEY_CTX_get0_peerkey_006aa934)();
    uVar33 = (**(code **)(*(int *)(puVar32 + -0x1c8) + -0x5800))(iVar4);
    *puVar14 = 0x20;
    if (puVar11 == (uint *)0x0) {
      return 1;
    }
    uVar2 = gost_get0_priv_key(uVar33);
    uVar33 = *(undefined4 *)(puVar32 + -0x1b4);
    uVar18 = *(uint *)(puVar32 + -0x1b8);
    puVar24 = *(uint **)(puVar32 + -0x1bc);
    puVar20 = *(undefined **)(puVar32 + -0x1c0);
    puVar32 = puVar32 + -0x1b0;
    puVar14 = puVar13;
    uVar17 = uVar8;
  }
  return uVar2;
}

