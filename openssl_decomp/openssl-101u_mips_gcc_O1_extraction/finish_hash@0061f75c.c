
uint finish_hash(int *param_1,byte **param_2,uint param_3,uint param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint in_v1;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint extraout_v1;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  undefined4 *puVar20;
  uint uVar21;
  uint in_t0;
  undefined4 uVar22;
  uint uVar23;
  uint uVar24;
  uint in_t1;
  uint uVar25;
  uint uVar26;
  uint in_t2;
  uint uVar27;
  uint in_t3;
  uint uVar28;
  uint uVar29;
  uint in_t4;
  byte *pbVar30;
  uint uVar31;
  uint in_t5;
  byte *pbVar32;
  uint uVar33;
  uint in_t6;
  uint uVar34;
  undefined *puVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  undefined4 *puVar39;
  uint uVar40;
  uint uVar41;
  byte *pbVar42;
  undefined *puVar43;
  uint uVar44;
  uint uVar45;
  undefined8 uVar46;
  undefined4 *puStackY_210;
  undefined *puStackY_208;
  uint uStackY_204;
  undefined *puStackY_200;
  byte *pbStackY_1fc;
  int iStackY_1f8;
  int iStackY_1c0;
  undefined auStack_1a8 [4];
  undefined auStack_1a4 [32];
  int *piStack_184;
  uint *puStack_180;
  undefined4 *puStack_17c;
  uint uStack_178;
  undefined4 *puStack_174;
  undefined *puStack_170;
  code *pcStack_16c;
  undefined4 uStack_158;
  uint *puStack_154;
  undefined *puStack_150;
  undefined auStack_144 [32];
  uint uStack_124;
  undefined4 *puStack_11c;
  uint uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  byte *pbStack_10c;
  undefined *puStack_108;
  code *pcStack_104;
  uint *puStack_f0;
  undefined *puStack_e8;
  undefined uStack_dc;
  undefined uStack_db;
  undefined uStack_da;
  undefined uStack_d9;
  undefined uStack_d8;
  undefined uStack_d7;
  undefined uStack_d6;
  undefined uStack_d5;
  uint uStack_d4;
  int *piStack_cc;
  uint uStack_c8;
  undefined4 **ppuStack_c4;
  uint *puStack_c0;
  int iStack_bc;
  byte **ppbStack_b8;
  undefined4 *puStack_b4;
  undefined *puStack_b0;
  undefined4 uStack_ac;
  undefined *local_98;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 *local_6c;
  byte *local_68;
  byte *local_64;
  byte *local_60;
  byte *local_5c;
  undefined4 *local_58;
  byte *local_54;
  byte *local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c [2];
  
  puStack_b0 = PTR___stack_chk_guard_006a9ae8;
  puStack_b4 = &local_8c;
  local_98 = &_gp;
  uVar6 = (uint)(param_1 + 4) & 3;
  uVar8 = (uint)(param_1 + 5) & 3;
  uVar17 = (uint)(param_1 + 6) & 3;
  local_2c[0] = *(uint *)PTR___stack_chk_guard_006a9ae8;
  uVar23 = (uint)(param_1 + 7) & 3;
  uVar15 = (uint)(param_1 + 8) & 3;
  uVar25 = (uint)(param_1 + 10) & 3;
  uVar16 = (uint)(param_1 + 9) & 3;
  uVar19 = (int)param_1 + 0x13U & 3;
  local_6c = (undefined4 *)
             ((*(int *)((int)(param_1 + 4) - uVar6) << uVar6 * 8 |
              in_t6 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar19 + 1) * 8 |
             *(uint *)(((int)param_1 + 0x13U) - uVar19) >> (3 - uVar19) * 8);
  uVar6 = (int)param_1 + 0x17U & 3;
  pbVar32 = (byte *)((*(int *)((int)(param_1 + 5) - uVar8) << uVar8 * 8 |
                     in_t5 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar6 + 1) * 8 |
                    *(uint *)(((int)param_1 + 0x17U) - uVar6) >> (3 - uVar6) * 8);
  uVar6 = (int)param_1 + 0x1bU & 3;
  pbVar30 = (byte *)((*(int *)((int)(param_1 + 6) - uVar17) << uVar17 * 8 |
                     in_t4 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar6 + 1) * 8 |
                    *(uint *)(((int)param_1 + 0x1bU) - uVar6) >> (3 - uVar6) * 8);
  uVar6 = (int)param_1 + 0x1fU & 3;
  local_60 = (byte *)((*(int *)((int)(param_1 + 7) - uVar23) << uVar23 * 8 |
                      in_t3 & 0xffffffffU >> (4 - uVar23) * 8) & -1 << (uVar6 + 1) * 8 |
                     *(uint *)(((int)param_1 + 0x1fU) - uVar6) >> (3 - uVar6) * 8);
  uVar6 = (int)param_1 + 0x27U & 3;
  local_58 = (undefined4 *)
             ((*(int *)((int)(param_1 + 9) - uVar16) << uVar16 * 8 |
              (uint)param_1 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar6 + 1) * 8 |
             *(uint *)(((int)param_1 + 0x27U) - uVar6) >> (3 - uVar6) * 8);
  uVar6 = (int)param_1 + 0x2bU & 3;
  local_54 = (byte *)((*(int *)((int)(param_1 + 10) - uVar25) << uVar25 * 8 |
                      in_v1 & 0xffffffffU >> (4 - uVar25) * 8) & -1 << (uVar6 + 1) * 8 |
                     *(uint *)(((int)param_1 + 0x2bU) - uVar6) >> (3 - uVar6) * 8);
  uVar6 = (uint)(param_1 + 0xc) & 3;
  uVar8 = (uint)(param_1 + 0xd) & 3;
  uVar17 = (uint)(param_1 + 0xe) & 3;
  uVar23 = (uint)(param_1 + 0xf) & 3;
  local_50 = (byte *)param_1[0xb];
  uVar25 = (int)param_1 + 0x23U & 3;
  local_5c = (byte *)((*(int *)((int)(param_1 + 8) - uVar15) << uVar15 * 8 |
                      param_3 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar25 + 1) * 8 |
                     *(uint *)(((int)param_1 + 0x23U) - uVar25) >> (3 - uVar25) * 8);
  uVar15 = (uint)(param_1 + 0x10) & 3;
  uVar25 = (int)param_1 + 0x33U & 3;
  local_4c = (*(int *)((int)(param_1 + 0xc) - uVar6) << uVar6 * 8 |
             in_t2 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar25 + 1) * 8 |
             *(uint *)(((int)param_1 + 0x33U) - uVar25) >> (3 - uVar25) * 8;
  uVar6 = (int)param_1 + 0x37U & 3;
  uVar25 = (*(int *)((int)(param_1 + 0xd) - uVar8) << uVar8 * 8 |
           in_t1 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar6 + 1) * 8 |
           *(uint *)(((int)param_1 + 0x37U) - uVar6) >> (3 - uVar6) * 8;
  uVar6 = (int)param_1 + 0x3bU & 3;
  local_44 = (*(int *)((int)(param_1 + 0xe) - uVar17) << uVar17 * 8 |
             in_t0 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar6 + 1) * 8 |
             *(uint *)(((int)param_1 + 0x3bU) - uVar6) >> (3 - uVar6) * 8;
  iStack_bc = *param_1;
  uStack_c8 = param_1[1];
  uVar6 = (int)param_1 + 0x3fU & 3;
  local_40 = (*(int *)((int)(param_1 + 0xf) - uVar23) << uVar23 * 8 |
             param_4 & 0xffffffffU >> (4 - uVar23) * 8) & -1 << (uVar6 + 1) * 8 |
             *(uint *)(((int)param_1 + 0x3fU) - uVar6) >> (3 - uVar6) * 8;
  uVar6 = (int)param_1 + 0x43U & 3;
  local_3c = (*(int *)((int)(param_1 + 0x10) - uVar15) << uVar15 * 8 |
             (uint)param_2 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar6 + 1) * 8 |
             *(uint *)(((int)param_1 + 0x43U) - uVar6) >> (3 - uVar6) * 8;
  uVar6 = (uint)(param_1 + 0x11) & 3;
  uVar8 = (uint)(param_1 + 0x12) & 3;
  uVar17 = (uint)(param_1 + 0x13) & 3;
  uVar23 = (int)param_1 + 0x47U & 3;
  local_38 = (*(int *)((int)(param_1 + 0x11) - uVar6) << uVar6 * 8 |
             (uint)local_58 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar23 + 1) * 8 |
             *(uint *)(((int)param_1 + 0x47U) - uVar23) >> (3 - uVar23) * 8;
  uVar6 = (int)param_1 + 0x4bU & 3;
  local_34 = (*(int *)((int)(param_1 + 0x12) - uVar8) << uVar8 * 8 |
             (uint)local_54 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar6 + 1) * 8 |
             *(uint *)(((int)param_1 + 0x4bU) - uVar6) >> (3 - uVar6) * 8;
  uVar6 = (int)param_1 + 0x4fU & 3;
  local_30 = (*(int *)((int)(param_1 + 0x13) - uVar17) << uVar17 * 8 |
             (uint)local_50 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar6 + 1) * 8 |
             *(uint *)(((int)param_1 + 0x4fU) - uVar6) >> (3 - uVar6) * 8;
  local_68 = pbVar32;
  local_64 = pbVar30;
  local_48 = uVar25;
  if (param_1[3] != 0) {
    local_8c = 0;
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    local_78 = 0;
    local_74 = 0;
    local_70 = 0;
    (*(code *)PTR___memcpy_chk_006a9a48)(puStack_b4,param_1 + 0x14,param_1[3],0x20);
    hash_step(param_1[2],&local_6c,puStack_b4);
    iVar13 = 0;
    puVar9 = &local_4c;
    puVar14 = puStack_b4;
    do {
      puVar10 = (uint *)((int)puVar9 + 1);
      bVar1 = *(byte *)puVar14;
      puVar14 = (undefined4 *)((int)puVar14 + 1);
      iVar7 = (uint)*(byte *)puVar9 + (uint)bVar1 + iVar13;
      iVar13 = iVar7 >> 8;
      *(byte *)puVar9 = (byte)iVar7;
      puVar9 = puVar10;
    } while (local_2c != puVar10);
    uVar6 = uStack_c8 + param_1[3];
    iStack_bc = (uint)(uVar6 < uStack_c8) + iStack_bc + (param_1[3] >> 0x1f);
    uStack_c8 = uVar6;
  }
  puStack_c0 = &local_4c;
  ppuStack_c4 = &local_6c;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  uVar6 = uStack_c8 << 3;
  uVar8 = uStack_c8 >> 0x1d | iStack_bc << 3;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  puVar14 = puStack_b4;
  if ((int)uVar8 < 1) {
    if (uVar8 == 0) {
      if (uVar6 == 0) {
        iVar13 = param_1[2];
        goto LAB_0061f8dc;
      }
      goto LAB_0061f8b8;
    }
  }
  else {
LAB_0061f8b8:
    do {
      uVar17 = uVar8 << 0x18;
      *(byte *)puVar14 = (byte)uVar6;
      uVar8 = (int)uVar8 >> 8;
      uVar6 = uVar17 | uVar6 >> 8;
      puVar14 = (undefined4 *)((int)puVar14 + 1);
    } while ((uVar8 | uVar6) != 0);
  }
  iVar13 = param_1[2];
LAB_0061f8dc:
  hash_step(iVar13,ppuStack_c4,puStack_b4);
  hash_step(param_1[2],ppuStack_c4,puStack_c0);
  *param_2 = (byte *)local_6c;
  param_2[1] = local_68;
  param_2[2] = local_64;
  param_2[3] = local_60;
  param_2[4] = local_5c;
  param_2[5] = (byte *)local_58;
  param_2[6] = local_54;
  param_2[7] = local_50;
  if (local_2c[0] == *(uint *)puStack_b0) {
    return 1;
  }
  uStack_ac = 0x61fa5c;
  uStack_118 = local_2c[0];
  puVar14 = local_58;
  pbVar42 = local_5c;
  puStack_11c = local_6c;
  uVar46 = (**(code **)(local_98 + -0x5330))();
  puStack_108 = PTR___stack_chk_guard_006a9ae8;
  pbStack_10c = pbVar42 + 8;
  puStack_e8 = &_gp;
  uVar6 = (uint)(puVar14 + 1) & 3;
  iVar13 = *(int *)((int)(puVar14 + 1) - uVar6);
  uVar8 = (uint)(puVar14 + 3) & 3;
  iVar7 = *(int *)((int)(puVar14 + 3) - uVar8);
  uVar17 = (uint)(puVar14 + 4) & 3;
  iVar2 = *(int *)((int)(puVar14 + 4) - uVar17);
  uVar23 = (uint)(puVar14 + 5) & 3;
  iVar3 = *(int *)((int)(puVar14 + 5) - uVar23);
  uVar15 = (uint)(puVar14 + 6) & 3;
  iVar4 = *(int *)((int)(puVar14 + 6) - uVar15);
  uVar16 = (uint)(puVar14 + 7) & 3;
  iVar5 = *(int *)((int)(puVar14 + 7) - uVar16);
  uVar22 = puVar14[2];
  uVar19 = (uint)(byte *)((int)puVar14 + 7U) & 3;
  uVar31 = *(uint *)((byte *)((int)puVar14 + 7U) + -uVar19);
  uVar28 = *(uint *)PTR___stack_chk_guard_006a9ae8;
  uVar21 = (uint)(byte *)((int)puVar14 + 0x13U) & 3;
  uVar33 = *(uint *)((byte *)((int)puVar14 + 0x13U) + -uVar21);
  uVar24 = (uint)(byte *)((int)puVar14 + 0x17U) & 3;
  uVar34 = *(uint *)((byte *)((int)puVar14 + 0x17U) + -uVar24);
  uVar26 = (uint)(byte *)((int)puVar14 + 0x1bU) & 3;
  uVar36 = *(uint *)((byte *)((int)puVar14 + 0x1bU) + -uVar26);
  uVar27 = (uint)(byte *)((int)puVar14 + 0x1fU) & 3;
  uVar37 = *(uint *)((byte *)((int)puVar14 + 0x1fU) + -uVar27);
  uVar29 = (uint)(byte *)((int)puVar14 + 0xfU) & 3;
  uVar38 = *(uint *)((byte *)((int)puVar14 + 0xfU) + -uVar29);
  *puStack_11c = *puVar14;
  puStack_11c[1] =
       (iVar13 << uVar6 * 8 | uVar25 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar19 + 1) * 8 |
       uVar31 >> (3 - uVar19) * 8;
  puStack_11c[2] = uVar22;
  puStack_11c[3] =
       (iVar7 << uVar8 * 8 | (uint)puStack_11c & 0xffffffffU >> (4 - uVar8) * 8) &
       -1 << (uVar29 + 1) * 8 | uVar38 >> (3 - uVar29) * 8;
  puStack_11c[4] =
       (iVar2 << uVar17 * 8 | (uint)pbVar42 & 0xffffffffU >> (4 - uVar17) * 8) &
       -1 << (uVar21 + 1) * 8 | uVar33 >> (3 - uVar21) * 8;
  puStack_11c[5] =
       (iVar3 << uVar23 * 8 | uStack_118 & 0xffffffffU >> (4 - uVar23) * 8) & -1 << (uVar24 + 1) * 8
       | uVar34 >> (3 - uVar24) * 8;
  puStack_11c[6] =
       (iVar4 << uVar15 * 8 | (uint)uVar46 & 0xffffffffU >> (4 - uVar15) * 8) &
       -1 << (uVar26 + 1) * 8 | uVar36 >> (3 - uVar26) * 8;
  puStack_11c[7] =
       (iVar5 << uVar16 * 8 | (uint)((ulonglong)uVar46 >> 0x20) & 0xffffffffU >> (4 - uVar16) * 8) &
       -1 << (uVar27 + 1) * 8 | uVar37 >> (3 - uVar27) * 8;
  uStack_d4 = uVar28;
  piStack_cc = param_1;
  ppbStack_b8 = param_2;
  do {
    bVar1 = *pbVar42;
    uVar6 = (uint)*(byte *)((int)puStack_11c + 1) << 8 |
            (uint)*(byte *)((int)puStack_11c + 2) << 0x10 | (uint)*(byte *)puStack_11c |
            (uint)*(byte *)((int)puStack_11c + 3) << 0x18;
    if ((bVar1 & 1) == 0) {
      uVar17 = (uint)*(byte *)((int)puStack_11c + 5) << 8 |
               (uint)*(byte *)((int)puStack_11c + 6) << 0x10 | (uint)*(byte *)(puStack_11c + 1) |
               (uint)*(byte *)((int)puStack_11c + 7) << 0x18;
      uVar8 = uVar6;
      uVar6 = 0;
      if ((bVar1 & 2) == 0) goto LAB_0061fb78;
LAB_0061fd90:
      uVar6 = uVar6 + uVar17;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 9) << 8 |
               (uint)*(byte *)((int)puStack_11c + 10) << 0x10 | (uint)*(byte *)(puStack_11c + 2) |
               (uint)*(byte *)((int)puStack_11c + 0xb) << 0x18;
      if ((bVar1 & 4) == 0) goto LAB_0061fbac;
LAB_0061fdc4:
      uVar6 = uVar6 + uVar17;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 0xd) << 8 |
               (uint)*(byte *)((int)puStack_11c + 0xe) << 0x10 | (uint)*(byte *)(puStack_11c + 3) |
               (uint)*(byte *)((int)puStack_11c + 0xf) << 0x18;
      if ((bVar1 & 8) == 0) goto LAB_0061fbe0;
LAB_0061fdf8:
      uVar6 = uVar6 + uVar17;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 0x11) << 8 |
               (uint)*(byte *)((int)puStack_11c + 0x12) << 0x10 | (uint)*(byte *)(puStack_11c + 4) |
               (uint)*(byte *)((int)puStack_11c + 0x13) << 0x18;
      if ((bVar1 & 0x10) == 0) goto LAB_0061fc14;
LAB_0061fe2c:
      uVar6 = uVar6 + uVar17;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 0x15) << 8 |
               (uint)*(byte *)((int)puStack_11c + 0x16) << 0x10 | (uint)*(byte *)(puStack_11c + 5) |
               (uint)*(byte *)((int)puStack_11c + 0x17) << 0x18;
      if ((bVar1 & 0x20) == 0) goto LAB_0061fc48;
LAB_0061fe60:
      uVar6 = uVar6 + uVar17;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 0x19) << 8 |
               (uint)*(byte *)((int)puStack_11c + 0x1a) << 0x10 | (uint)*(byte *)(puStack_11c + 6) |
               (uint)*(byte *)((int)puStack_11c + 0x1b) << 0x18;
      if ((bVar1 & 0x40) == 0) goto LAB_0061fc7c;
LAB_0061fe94:
      uVar6 = uVar6 + uVar17;
      uVar23 = (uint)*(byte *)((int)puStack_11c + 0x1f) << 0x18;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 0x1d) << 8 |
               (uint)*(byte *)((int)puStack_11c + 0x1e) << 0x10 | (uint)*(byte *)(puStack_11c + 7) |
               uVar23;
      if ((bVar1 & 0x80) == 0) goto LAB_0061fcb0;
LAB_0061fec8:
      uVar6 = uVar6 + uVar17;
    }
    else {
      uVar8 = 0;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 5) << 8 |
               (uint)*(byte *)((int)puStack_11c + 6) << 0x10 | (uint)*(byte *)(puStack_11c + 1) |
               (uint)*(byte *)((int)puStack_11c + 7) << 0x18;
      if ((bVar1 & 2) != 0) goto LAB_0061fd90;
LAB_0061fb78:
      uVar8 = uVar8 + uVar17;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 9) << 8 |
               (uint)*(byte *)((int)puStack_11c + 10) << 0x10 | (uint)*(byte *)(puStack_11c + 2) |
               (uint)*(byte *)((int)puStack_11c + 0xb) << 0x18;
      if ((bVar1 & 4) != 0) goto LAB_0061fdc4;
LAB_0061fbac:
      uVar8 = uVar8 + uVar17;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 0xd) << 8 |
               (uint)*(byte *)((int)puStack_11c + 0xe) << 0x10 | (uint)*(byte *)(puStack_11c + 3) |
               (uint)*(byte *)((int)puStack_11c + 0xf) << 0x18;
      if ((bVar1 & 8) != 0) goto LAB_0061fdf8;
LAB_0061fbe0:
      uVar8 = uVar8 + uVar17;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 0x11) << 8 |
               (uint)*(byte *)((int)puStack_11c + 0x12) << 0x10 | (uint)*(byte *)(puStack_11c + 4) |
               (uint)*(byte *)((int)puStack_11c + 0x13) << 0x18;
      if ((bVar1 & 0x10) != 0) goto LAB_0061fe2c;
LAB_0061fc14:
      uVar8 = uVar8 + uVar17;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 0x15) << 8 |
               (uint)*(byte *)((int)puStack_11c + 0x16) << 0x10 | (uint)*(byte *)(puStack_11c + 5) |
               (uint)*(byte *)((int)puStack_11c + 0x17) << 0x18;
      if ((bVar1 & 0x20) != 0) goto LAB_0061fe60;
LAB_0061fc48:
      uVar8 = uVar8 + uVar17;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 0x19) << 8 |
               (uint)*(byte *)((int)puStack_11c + 0x1a) << 0x10 | (uint)*(byte *)(puStack_11c + 6) |
               (uint)*(byte *)((int)puStack_11c + 0x1b) << 0x18;
      if ((bVar1 & 0x40) != 0) goto LAB_0061fe94;
LAB_0061fc7c:
      uVar8 = uVar8 + uVar17;
      uVar23 = (uint)*(byte *)((int)puStack_11c + 0x1f) << 0x18;
      uVar17 = (uint)*(byte *)((int)puStack_11c + 0x1d) << 8 |
               (uint)*(byte *)((int)puStack_11c + 0x1e) << 0x10 | (uint)*(byte *)(puStack_11c + 7) |
               uVar23;
      if ((bVar1 & 0x80) != 0) goto LAB_0061fec8;
LAB_0061fcb0:
      uVar8 = uVar8 + uVar17;
    }
    uStack_dc = (undefined)uVar6;
    uStack_d8 = (undefined)uVar8;
    uStack_db = (undefined)(uVar6 >> 8);
    uStack_da = (undefined)(uVar6 >> 0x10);
    uStack_d7 = (undefined)(uVar8 >> 8);
    uStack_d9 = (undefined)(uVar6 >> 0x18);
    uStack_d6 = (undefined)(uVar8 >> 0x10);
    uStack_d5 = (undefined)(uVar8 >> 0x18);
    pbVar42 = pbVar42 + 1;
    gost_key(uStack_118,puStack_11c);
    puStack_f0 = (uint *)&SUB_00000004;
    uStack_178 = uStack_118;
    puStack_17c = puStack_11c;
    puStack_174 = puStack_11c;
    gost_enc_cfb(uStack_118,&uStack_dc);
    if (pbStack_10c == pbVar42) {
      uVar6 = *(uint *)puStack_108;
      if (uStack_d4 == uVar6) {
        return uVar6;
      }
      pcStack_104 = keyWrapCryptoPro;
      (**(code **)(puStack_e8 + -0x5330))();
      puVar9 = puStack_f0;
      puVar43 = PTR___stack_chk_guard_006a9ae8;
      puStack_170 = auStack_144;
      uStack_110 = 0xffffff80;
      uStack_114 = 4;
      puStack_150 = &_gp;
      uStack_124 = *(uint *)PTR___stack_chk_guard_006a9ae8;
      keyDiversifyCryptoPro();
      gost_key(uStack_178,puStack_170);
      uVar6 = (uint)puStack_17c & 3;
      uVar17 = puStack_17c[1];
      uVar8 = (uint)(byte *)((int)puStack_17c + 3U) & 3;
      *puVar9 = (*(int *)((int)puStack_17c - uVar6) << uVar6 * 8 |
                extraout_v1 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar8 + 1) * 8 |
                *(uint *)((byte *)((int)puStack_17c + 3U) + -uVar8) >> (3 - uVar8) * 8;
      puVar9[1] = uVar17;
      puStack_180 = puVar9 + 10;
      gost_enc(uStack_178,puStack_174,puVar9 + 2,4);
      uStack_158 = 0x20;
      puVar14 = puStack_17c;
      puVar39 = puStack_174;
      puStack_154 = puStack_180;
      gost_mac_iv(uStack_178,0x20);
      if (uStack_124 != *(uint *)puVar43) {
        pcStack_16c = keyUnwrapCryptoPro;
        uVar6 = uStack_124;
        (**(code **)(puStack_150 + -0x5330))();
        puVar43 = PTR___stack_chk_guard_006a9ae8;
        piStack_184 = *(int **)PTR___stack_chk_guard_006a9ae8;
        keyDiversifyCryptoPro();
        puVar35 = auStack_1a8;
        gost_key(uVar6,auStack_1a4);
        gost_dec(uVar6,puVar14 + 2,puVar39,4);
        puVar20 = puVar39;
        gost_mac_iv(uVar6,0x20,puVar14,puVar39,0x20,puVar35);
        iStackY_1c0 = 4;
        puVar9 = puVar14 + 10;
        iVar13 = (*(code *)PTR_memcmp_006a9ad0)(puVar35);
        if (piStack_184 != *(int **)puVar43) {
          (*(code *)PTR___stack_chk_fail_006a9ab0)();
          puStackY_208 = (undefined *)*piStack_184;
          uStackY_204 = piStack_184[1];
          puStackY_200 = (undefined *)piStack_184[2];
          pbStackY_1fc = (byte *)piStack_184[3];
          iStackY_1f8 = piStack_184[4];
          puStackY_210 = (undefined4 *)0xca62c1d6;
          puVar10 = puVar9;
          do {
            if (((uint)puVar9 & 3) == 0) {
              uVar21 = *puVar10;
              uVar24 = puVar10[1];
              uVar23 = (uStackY_204 >> 2) + uStackY_204 * 0x40000000;
              uVar33 = puVar10[2];
              uVar31 = puVar10[3];
              uVar29 = puVar10[4];
              uVar27 = puVar10[5];
              uVar26 = puVar10[6];
              uVar40 = puVar10[7];
              uVar28 = puVar10[8];
              uVar8 = ((uint)puStackY_208 >> 0x1b) + (int)puStackY_208 * 0x20 +
                      iStackY_1f8 + 0x5a827999 + uVar21 +
                      (((uint)puStackY_200 ^ (uint)pbStackY_1fc) & uStackY_204 ^ (uint)pbStackY_1fc)
              ;
              uVar36 = puVar10[9];
              uVar34 = puVar10[10];
              uVar38 = puVar10[0xb];
              uVar37 = puVar10[0xc];
              uVar15 = ((uint)puStackY_208 >> 2) + (int)puStackY_208 * 0x40000000;
              uVar45 = puVar10[0xe];
              uVar6 = puVar10[0xd];
              uVar44 = puVar10[0xf];
              pbVar30 = pbStackY_1fc +
                        (uVar8 >> 0x1b) + uVar8 * 0x20 +
                        (((uint)puStackY_200 ^ uVar23) & (uint)puStackY_208 ^ (uint)puStackY_200) +
                        uVar24 + 0x5a827999;
              uVar17 = (uVar8 >> 2) + uVar8 * 0x40000000;
              puVar43 = puStackY_200 +
                        ((uint)pbVar30 >> 0x1b) + (int)pbVar30 * 0x20 +
                        ((uVar23 ^ uVar15) & uVar8 ^ uVar23) + uVar33 + 0x5a827999;
              uVar8 = ((uint)pbVar30 >> 2) + (int)pbVar30 * 0x40000000;
              uVar23 = ((uVar15 ^ uVar17) & (uint)pbVar30 ^ uVar15) + uVar23 + 0x5a827999 + uVar31 +
                       ((uint)puVar43 >> 0x1b) + (int)puVar43 * 0x20;
              uVar11 = ((uint)puVar43 >> 2) + (int)puVar43 * 0x40000000;
              uVar19 = (uVar23 >> 2) + uVar23 * 0x40000000;
              uVar25 = ((uVar17 ^ uVar8) & (uint)puVar43 ^ uVar17) + uVar15 + 0x5a827999 + uVar29 +
                       (uVar23 >> 0x1b) + uVar23 * 0x20;
              uVar16 = (uVar25 >> 2) + uVar25 * 0x40000000;
              uVar23 = ((uVar8 ^ uVar11) & uVar23 ^ uVar8) + uVar27 + 0x5a827999 + uVar17 +
                       (uVar25 >> 0x1b) + uVar25 * 0x20;
              uVar15 = (uVar23 >> 2) + uVar23 * 0x40000000;
              uVar8 = ((uVar11 ^ uVar19) & uVar25 ^ uVar11) + uVar26 + 0x5a827999 + uVar8 +
                      (uVar23 >> 0x1b) + uVar23 * 0x20;
              uVar17 = (uVar8 >> 2) + uVar8 * 0x40000000;
              uVar23 = ((uVar19 ^ uVar16) & uVar23 ^ uVar19) + uVar40 + 0x5a827999 + uVar11 +
                       (uVar8 >> 0x1b) + uVar8 * 0x20;
              uVar25 = (uVar23 >> 2) + uVar23 * 0x40000000;
              uVar8 = ((uVar16 ^ uVar15) & uVar8 ^ uVar16) + uVar28 + 0x5a827999 + uVar19 +
                      (uVar23 >> 0x1b) + uVar23 * 0x20;
              uVar19 = (uVar8 >> 2) + uVar8 * 0x40000000;
              uVar23 = ((uVar15 ^ uVar17) & uVar23 ^ uVar15) + uVar36 + 0x5a827999 + uVar16 +
                       (uVar8 >> 0x1b) + uVar8 * 0x20;
              uVar8 = ((uVar17 ^ uVar25) & uVar8 ^ uVar17) + uVar34 + 0x5a827999 + uVar15 +
                      (uVar23 >> 0x1b) + uVar23 * 0x20;
              uVar15 = (uVar23 >> 2) + uVar23 * 0x40000000;
              iVar13 = ((uVar25 ^ uVar19) & uVar23 ^ uVar25) + uVar38 + 0x5a827999 + uVar17;
            }
            else {
              uVar41 = ((uint)puStackY_208 >> 2) + (int)puStackY_208 * 0x40000000;
              uVar8 = (uint)puVar10 & 3;
              uVar17 = (uint)(puVar10 + 1) & 3;
              uVar15 = (uint)(puVar10 + 2) & 3;
              uVar25 = (uint)(puVar10 + 3) & 3;
              uVar16 = (uint)(byte *)((int)puVar10 + 3U) & 3;
              uVar21 = (*(int *)((int)puVar10 - uVar8) << uVar8 * 8 |
                       (uint)puVar20 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar16 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 3U) + -uVar16) >> (3 - uVar16) * 8;
              uVar18 = (uStackY_204 >> 2) + uStackY_204 * 0x40000000;
              uVar8 = (uint)(byte *)((int)puVar10 + 7U) & 3;
              uVar24 = (*(int *)((int)(puVar10 + 1) - uVar17) << uVar17 * 8 |
                       uVar23 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar8 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 7U) + -uVar8) >> (3 - uVar8) * 8;
              uVar8 = (uint)(byte *)((int)puVar10 + 0xbU) & 3;
              uVar33 = (*(int *)((int)(puVar10 + 2) - uVar15) << uVar15 * 8 |
                       (uint)pbVar32 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar8 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0xbU) + -uVar8) >> (3 - uVar8) * 8;
              uVar8 = (uint)(puVar10 + 4) & 3;
              uVar17 = (uint)(puVar10 + 5) & 3;
              uVar11 = (((uint)puStackY_200 ^ (uint)pbStackY_1fc) & uStackY_204 ^ (uint)pbStackY_1fc
                       ) + ((uint)puStackY_208 >> 0x1b) + (int)puStackY_208 * 0x20 +
                           iStackY_1f8 + 0x5a827999 + uVar21;
              uVar23 = (uint)(byte *)((int)puVar10 + 0xfU) & 3;
              uVar31 = (*(int *)((int)(puVar10 + 3) - uVar25) << uVar25 * 8 |
                       (uint)pbVar30 & 0xffffffffU >> (4 - uVar25) * 8) & -1 << (uVar23 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0xfU) + -uVar23) >> (3 - uVar23) * 8;
              uVar23 = (uint)(puVar10 + 6) & 3;
              uVar15 = (uint)(puVar10 + 7) & 3;
              uVar25 = (uint)(byte *)((int)puVar10 + 0x13U) & 3;
              uVar29 = (*(int *)((int)(puVar10 + 4) - uVar8) << uVar8 * 8 |
                       uVar28 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar25 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0x13U) + -uVar25) >> (3 - uVar25) * 8;
              uVar8 = (uint)(byte *)((int)puVar10 + 0x17U) & 3;
              uVar27 = (*(int *)((int)(puVar10 + 5) - uVar17) << uVar17 * 8 |
                       uStackY_204 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar8 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0x17U) + -uVar8) >> (3 - uVar8) * 8;
              uVar8 = (uint)(puVar10 + 8) & 3;
              uVar17 = (uint)(puVar10 + 9) & 3;
              uVar25 = (uint)(puVar10 + 10) & 3;
              pbVar30 = pbStackY_1fc +
                        (uVar11 >> 0x1b) + uVar11 * 0x20 +
                        (((uint)puStackY_200 ^ uVar18) & (uint)puStackY_208 ^ (uint)puStackY_200) +
                        uVar24 + 0x5a827999;
              uVar16 = (uint)(puVar10 + 0xb) & 3;
              uVar19 = (uint)(puVar10 + 0xc) & 3;
              uVar26 = (uint)(byte *)((int)puVar10 + 0x1bU) & 3;
              uVar26 = (*(int *)((int)(puVar10 + 6) - uVar23) << uVar23 * 8 |
                       (uint)pbStackY_1fc & 0xffffffffU >> (4 - uVar23) * 8) &
                       -1 << (uVar26 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0x1bU) + -uVar26) >> (3 - uVar26) * 8;
              uVar12 = (uVar11 >> 2) + uVar11 * 0x40000000;
              uVar23 = (uint)(byte *)((int)puVar10 + 0x1fU) & 3;
              uVar40 = (*(int *)((int)(puVar10 + 7) - uVar15) << uVar15 * 8 |
                       (uint)puVar39 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar23 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0x1fU) + -uVar23) >> (3 - uVar23) * 8;
              uVar23 = (uint)(byte *)((int)puVar10 + 0x23U) & 3;
              uVar28 = (*(int *)((int)(puVar10 + 8) - uVar8) << uVar8 * 8 |
                       (uint)puVar43 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar23 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0x23U) + -uVar23) >> (3 - uVar23) * 8;
              uVar8 = (uint)(puVar10 + 0xd) & 3;
              uVar23 = (uint)(byte *)((int)puVar10 + 0x27U) & 3;
              uVar36 = (*(int *)((int)(puVar10 + 9) - uVar17) << uVar17 * 8 |
                       (uint)puVar35 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar23 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0x27U) + -uVar23) >> (3 - uVar23) * 8;
              uVar17 = (uint)(byte *)((int)puVar10 + 0x2bU) & 3;
              uVar34 = (*(int *)((int)(puVar10 + 10) - uVar25) << uVar25 * 8 |
                       (uint)puStackY_200 & 0xffffffffU >> (4 - uVar25) * 8) &
                       -1 << (uVar17 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0x2bU) + -uVar17) >> (3 - uVar17) * 8;
              uVar17 = (uint)(byte *)((int)puVar10 + 0x2fU) & 3;
              uVar38 = (*(int *)((int)(puVar10 + 0xb) - uVar16) << uVar16 * 8 |
                       uVar6 & 0xffffffffU >> (4 - uVar16) * 8) & -1 << (uVar17 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0x2fU) + -uVar17) >> (3 - uVar17) * 8;
              uVar17 = (uint)(puVar10 + 0xe) & 3;
              uVar23 = (uint)(puVar10 + 0xf) & 3;
              uVar6 = (uint)(byte *)((int)puVar10 + 0x33U) & 3;
              uVar37 = (*(int *)((int)(puVar10 + 0xc) - uVar19) << uVar19 * 8 |
                       (uint)puVar14 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar6 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0x33U) + -uVar6) >> (3 - uVar6) * 8;
              uVar6 = (uint)(byte *)((int)puVar10 + 0x37U) & 3;
              uVar6 = (*(int *)((int)(puVar10 + 0xd) - uVar8) << uVar8 * 8 |
                      (uint)(puStackY_200 + uVar33 + 0x5a827999) & 0xffffffffU >> (4 - uVar8) * 8) &
                      -1 << (uVar6 + 1) * 8 |
                      *(uint *)((byte *)((int)puVar10 + 0x37U) + -uVar6) >> (3 - uVar6) * 8;
              puVar43 = puStackY_200 + uVar33 + 0x5a827999 +
                        ((uint)pbVar30 >> 0x1b) + (int)pbVar30 * 0x20 +
                        ((uVar18 ^ uVar41) & uVar11 ^ uVar18);
              uVar15 = ((uint)pbVar30 >> 2) + (int)pbVar30 * 0x40000000;
              uVar8 = (uint)(byte *)((int)puVar10 + 0x3bU) & 3;
              uVar45 = (*(int *)((int)(puVar10 + 0xe) - uVar17) << uVar17 * 8 |
                       (uint)puStackY_208 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar8 + 1) * 8
                       | *(uint *)((byte *)((int)puVar10 + 0x3bU) + -uVar8) >> (3 - uVar8) * 8;
              uVar8 = (uint)(byte *)((int)puVar10 + 0x3fU) & 3;
              uVar44 = (*(int *)((int)(puVar10 + 0xf) - uVar23) << uVar23 * 8 |
                       0xffffffffU >> (4 - uVar23) * 8 & 0x5a827999) & -1 << (uVar8 + 1) * 8 |
                       *(uint *)((byte *)((int)puVar10 + 0x3fU) + -uVar8) >> (3 - uVar8) * 8;
              uVar8 = ((uVar41 ^ uVar12) & (uint)pbVar30 ^ uVar41) + uVar18 + 0x5a827999 + uVar31 +
                      ((uint)puVar43 >> 0x1b) + (int)puVar43 * 0x20;
              uVar25 = ((uint)puVar43 >> 2) + (int)puVar43 * 0x40000000;
              uVar19 = (uVar8 >> 2) + uVar8 * 0x40000000;
              uVar23 = ((uVar12 ^ uVar15) & (uint)puVar43 ^ uVar12) + uVar41 + 0x5a827999 + uVar29 +
                       (uVar8 >> 0x1b) + uVar8 * 0x20;
              uVar11 = (uVar23 >> 2) + uVar23 * 0x40000000;
              uVar8 = ((uVar15 ^ uVar25) & uVar8 ^ uVar15) + uVar27 + 0x5a827999 + uVar12 +
                      (uVar23 >> 0x1b) + uVar23 * 0x20;
              uVar17 = (uVar8 >> 2) + uVar8 * 0x40000000;
              uVar23 = ((uVar25 ^ uVar19) & uVar23 ^ uVar25) + uVar26 + 0x5a827999 + uVar15 +
                       (uVar8 >> 0x1b) + uVar8 * 0x20;
              uVar16 = (uVar23 >> 2) + uVar23 * 0x40000000;
              uVar8 = ((uVar19 ^ uVar11) & uVar8 ^ uVar19) + uVar40 + 0x5a827999 + uVar25 +
                      (uVar23 >> 0x1b) + uVar23 * 0x20;
              uVar25 = (uVar8 >> 2) + uVar8 * 0x40000000;
              uVar15 = ((uVar11 ^ uVar17) & uVar23 ^ uVar11) + uVar28 + 0x5a827999 + uVar19 +
                       (uVar8 >> 0x1b) + uVar8 * 0x20;
              uVar19 = (uVar15 >> 2) + uVar15 * 0x40000000;
              uVar23 = ((uVar17 ^ uVar16) & uVar8 ^ uVar17) + uVar36 + 0x5a827999 + uVar11 +
                       (uVar15 >> 0x1b) + uVar15 * 0x20;
              uVar8 = ((uVar16 ^ uVar25) & uVar15 ^ uVar16) + uVar34 + 0x5a827999 + uVar17 +
                      (uVar23 >> 0x1b) + uVar23 * 0x20;
              uVar15 = (uVar23 >> 2) + uVar23 * 0x40000000;
              iVar13 = ((uVar25 ^ uVar19) & uVar23 ^ uVar25) + uVar38 + 0x5a827999 + uVar16;
            }
            uVar17 = iVar13 + (uVar8 >> 0x1b) + uVar8 * 0x20;
            uVar23 = (uVar8 >> 2) + uVar8 * 0x40000000;
            uVar16 = (uVar17 >> 2) + uVar17 * 0x40000000;
            uVar8 = ((uVar19 ^ uVar15) & uVar8 ^ uVar19) + uVar37 + 0x5a827999 + uVar25 +
                    (uVar17 >> 0x1b) + uVar17 * 0x20;
            uVar17 = ((uVar15 ^ uVar23) & uVar17 ^ uVar15) + uVar6 + 0x5a827999 + uVar19 +
                     (uVar8 >> 0x1b) + uVar8 * 0x20;
            uVar11 = (uVar8 >> 2) + uVar8 * 0x40000000;
            uVar25 = ((uVar23 ^ uVar16) & uVar8 ^ uVar23) + uVar45 + 0x5a827999 + uVar15 +
                     (uVar17 >> 0x1b) + uVar17 * 0x20;
            uVar8 = ((uVar16 ^ uVar11) & uVar17 ^ uVar16) + uVar44 + 0x5a827999 + uVar23 +
                    (uVar25 >> 0x1b) + uVar25 * 0x20;
            uVar19 = uVar6 ^ uVar21 ^ uVar33 ^ uVar28;
            uVar23 = (uVar17 >> 2) + uVar17 * 0x40000000;
            uVar15 = (uVar25 >> 2) + uVar25 * 0x40000000;
            uVar21 = uVar45 ^ uVar24 ^ uVar31 ^ uVar36;
            uVar16 = (uVar8 >> 0x1b) + uVar8 * 0x20 + uVar16 + 0x5a827999 + uVar19 +
                     ((uVar23 ^ uVar11) & uVar25 ^ uVar11);
            uVar17 = (uVar8 >> 2) + uVar8 * 0x40000000;
            uVar33 = uVar44 ^ uVar33 ^ uVar29 ^ uVar34;
            uVar25 = ((uVar23 ^ uVar15) & uVar8 ^ uVar23) + uVar11 + 0x5a827999 + uVar21 +
                     (uVar16 >> 0x1b) + uVar16 * 0x20;
            uVar11 = (uVar16 >> 2) + uVar16 * 0x40000000;
            uVar31 = uVar19 ^ uVar31 ^ uVar27 ^ uVar38;
            uVar8 = ((uVar15 ^ uVar17) & uVar16 ^ uVar15) + uVar23 + 0x5a827999 + uVar33 +
                    (uVar25 >> 0x1b) + uVar25 * 0x20;
            uVar16 = (uVar25 >> 2) + uVar25 * 0x40000000;
            uVar29 = uVar21 ^ uVar29 ^ uVar26 ^ uVar37;
            uVar15 = ((uVar17 ^ uVar11) & uVar25 ^ uVar17) + uVar15 + 0x5a827999 + uVar31 +
                     (uVar8 >> 0x1b) + uVar8 * 0x20;
            uVar27 = uVar33 ^ uVar27 ^ uVar40 ^ uVar6;
            uVar23 = (uVar8 >> 2) + uVar8 * 0x40000000;
            uVar17 = (uVar11 ^ uVar16 ^ uVar8) + uVar17 + 0x6ed9eba1 + uVar29 +
                     (uVar15 >> 0x1b) + uVar15 * 0x20;
            uVar24 = uVar31 ^ uVar26 ^ uVar28 ^ uVar45;
            uVar25 = (uVar15 >> 2) + uVar15 * 0x40000000;
            uVar15 = (uVar16 ^ uVar23 ^ uVar15) + uVar27 + 0x6ed9eba1 + uVar11 +
                     (uVar17 >> 0x1b) + uVar17 * 0x20;
            uVar8 = uVar29 ^ uVar40 ^ uVar36 ^ uVar44;
            uVar11 = (uVar17 >> 2) + uVar17 * 0x40000000;
            uVar26 = (uVar23 ^ uVar25 ^ uVar17) + uVar24 + 0x6ed9eba1 + uVar16 +
                     (uVar15 >> 0x1b) + uVar15 * 0x20;
            uVar17 = uVar27 ^ uVar28 ^ uVar34 ^ uVar19;
            uVar16 = (uVar15 >> 2) + uVar15 * 0x40000000;
            uVar15 = (uVar25 ^ uVar11 ^ uVar15) + uVar8 + 0x6ed9eba1 + uVar23 +
                     (uVar26 >> 0x1b) + uVar26 * 0x20;
            uVar36 = uVar24 ^ uVar36 ^ uVar38 ^ uVar21;
            uVar28 = (uVar26 >> 2) + uVar26 * 0x40000000;
            uVar23 = (uVar11 ^ uVar16 ^ uVar26) + uVar17 + 0x6ed9eba1 + uVar25 +
                     (uVar15 >> 0x1b) + uVar15 * 0x20;
            uVar25 = uVar8 ^ uVar34 ^ uVar37 ^ uVar33;
            uVar40 = (uVar15 >> 2) + uVar15 * 0x40000000;
            uVar34 = (uVar16 ^ uVar28 ^ uVar15) + uVar36 + 0x6ed9eba1 + uVar11 +
                     (uVar23 >> 0x1b) + uVar23 * 0x20;
            uVar15 = uVar17 ^ uVar38 ^ uVar6 ^ uVar31;
            uVar38 = (uVar23 >> 2) + uVar23 * 0x40000000;
            uVar26 = (uVar28 ^ uVar40 ^ uVar23) + uVar25 + 0x6ed9eba1 + uVar16 +
                     (uVar34 >> 0x1b) + uVar34 * 0x20;
            uVar16 = uVar36 ^ uVar37 ^ uVar45 ^ uVar29;
            uVar11 = (uVar34 >> 2) + uVar34 * 0x40000000;
            uVar23 = (uVar40 ^ uVar38 ^ uVar34) + uVar15 + 0x6ed9eba1 + uVar28 +
                     (uVar26 >> 0x1b) + uVar26 * 0x20;
            uVar6 = uVar25 ^ uVar6 ^ uVar44 ^ uVar27;
            uVar34 = (uVar26 >> 2) + uVar26 * 0x40000000;
            uVar37 = (uVar38 ^ uVar11 ^ uVar26) + uVar16 + 0x6ed9eba1 + uVar40 +
                     (uVar23 >> 0x1b) + uVar23 * 0x20;
            uVar45 = uVar15 ^ uVar45 ^ uVar19 ^ uVar24;
            uVar26 = (uVar23 >> 2) + uVar23 * 0x40000000;
            uVar38 = (uVar11 ^ uVar34 ^ uVar23) + uVar6 + 0x6ed9eba1 + uVar38 +
                     (uVar37 >> 0x1b) + uVar37 * 0x20;
            uVar44 = uVar16 ^ uVar44 ^ uVar21 ^ uVar8;
            uVar28 = (uVar37 >> 2) + uVar37 * 0x40000000;
            uVar23 = (uVar34 ^ uVar26 ^ uVar37) + uVar45 + 0x6ed9eba1 + uVar11 +
                     (uVar38 >> 0x1b) + uVar38 * 0x20;
            uVar19 = uVar6 ^ uVar19 ^ uVar33 ^ uVar17;
            uVar40 = (uVar38 >> 2) + uVar38 * 0x40000000;
            uVar37 = (uVar26 ^ uVar28 ^ uVar38) + uVar44 + 0x6ed9eba1 + uVar34 +
                     (uVar23 >> 0x1b) + uVar23 * 0x20;
            uVar21 = uVar45 ^ uVar21 ^ uVar31 ^ uVar36;
            uVar34 = (uVar23 >> 2) + uVar23 * 0x40000000;
            uVar26 = (uVar28 ^ uVar40 ^ uVar23) + uVar19 + 0x6ed9eba1 + uVar26 +
                     (uVar37 >> 0x1b) + uVar37 * 0x20;
            uVar33 = uVar44 ^ uVar33 ^ uVar29 ^ uVar25;
            uVar38 = (uVar37 >> 2) + uVar37 * 0x40000000;
            uVar31 = uVar19 ^ uVar31 ^ uVar27 ^ uVar15;
            uVar23 = (uVar40 ^ uVar34 ^ uVar37) + uVar21 + 0x6ed9eba1 + uVar28 +
                     (uVar26 >> 0x1b) + uVar26 * 0x20;
            uVar11 = (uVar26 >> 2) + uVar26 * 0x40000000;
            uVar29 = uVar21 ^ uVar29 ^ uVar24 ^ uVar16;
            uVar37 = (uVar34 ^ uVar38 ^ uVar26) + uVar33 + 0x6ed9eba1 + uVar40 +
                     (uVar23 >> 0x1b) + uVar23 * 0x20;
            uVar28 = (uVar23 >> 2) + uVar23 * 0x40000000;
            uVar26 = uVar33 ^ uVar27 ^ uVar8 ^ uVar6;
            uVar23 = (uVar38 ^ uVar11 ^ uVar23) + uVar31 + 0x6ed9eba1 + uVar34 +
                     (uVar37 >> 0x1b) + uVar37 * 0x20;
            uVar27 = (uVar37 >> 2) + uVar37 * 0x40000000;
            uVar34 = (uVar11 ^ uVar28 ^ uVar37) + uVar29 + 0x6ed9eba1 + uVar38 +
                     (uVar23 >> 0x1b) + uVar23 * 0x20;
            uVar24 = uVar31 ^ uVar24 ^ uVar17 ^ uVar45;
            uVar40 = (uVar23 >> 2) + uVar23 * 0x40000000;
            uVar8 = uVar29 ^ uVar8 ^ uVar36 ^ uVar44;
            uVar38 = (uVar28 ^ uVar27 ^ uVar23) + uVar26 + 0x6ed9eba1 + uVar11 +
                     (uVar34 >> 0x1b) + uVar34 * 0x20;
            uVar37 = (uVar34 >> 2) + uVar34 * 0x40000000;
            uVar34 = (uVar27 ^ uVar40 ^ uVar34) + uVar24 + 0x6ed9eba1 + uVar28 +
                     (uVar38 >> 0x1b) + uVar38 * 0x20;
            uVar23 = uVar26 ^ uVar17 ^ uVar25 ^ uVar19;
            uVar27 = (uVar40 ^ uVar37 ^ uVar38) + uVar8 + 0x6ed9eba1 + uVar27 +
                     (uVar34 >> 0x1b) + uVar34 * 0x20;
            uVar38 = (uVar38 >> 2) + uVar38 * 0x40000000;
            uVar36 = uVar24 ^ uVar36 ^ uVar15 ^ uVar21;
            uVar12 = (uVar34 >> 2) + uVar34 * 0x40000000;
            uVar17 = ((uVar34 | uVar38) & uVar37 | uVar34 & uVar38) +
                     uVar23 + 0x8f1bbcdc + uVar40 + (uVar27 >> 0x1b) + uVar27 * 0x20;
            uVar34 = uVar8 ^ uVar25 ^ uVar16 ^ uVar33;
            uVar37 = ((uVar27 | uVar12) & uVar38 | uVar27 & uVar12) + uVar36 + 0x8f1bbcdc + uVar37 +
                     (uVar17 >> 0x1b) + uVar17 * 0x20;
            uVar28 = (uVar27 >> 2) + uVar27 * 0x40000000;
            uVar25 = uVar23 ^ uVar15 ^ uVar6 ^ uVar31;
            uVar11 = (uVar17 >> 2) + uVar17 * 0x40000000;
            uVar17 = ((uVar17 | uVar28) & uVar12 | uVar17 & uVar28) +
                     uVar34 + 0x8f1bbcdc + uVar38 + (uVar37 >> 0x1b) + uVar37 * 0x20;
            uVar16 = uVar36 ^ uVar16 ^ uVar45 ^ uVar29;
            uVar27 = ((uVar37 | uVar11) & uVar28 | uVar37 & uVar11) + uVar25 + 0x8f1bbcdc + uVar12 +
                     (uVar17 >> 0x1b) + uVar17 * 0x20;
            uVar38 = (uVar37 >> 2) + uVar37 * 0x40000000;
            uVar6 = uVar34 ^ uVar6 ^ uVar44 ^ uVar26;
            uVar40 = (uVar17 >> 2) + uVar17 * 0x40000000;
            uVar15 = ((uVar17 | uVar38) & uVar11 | uVar17 & uVar38) +
                     uVar16 + 0x8f1bbcdc + uVar28 + (uVar27 >> 0x1b) + uVar27 * 0x20;
            uVar45 = uVar25 ^ uVar45 ^ uVar19 ^ uVar24;
            uVar17 = ((uVar27 | uVar40) & uVar38 | uVar27 & uVar40) + uVar6 + 0x8f1bbcdc + uVar11 +
                     (uVar15 >> 0x1b) + uVar15 * 0x20;
            uVar37 = (uVar27 >> 2) + uVar27 * 0x40000000;
            uVar44 = uVar16 ^ uVar44 ^ uVar21 ^ uVar8;
            uVar28 = (uVar15 >> 2) + uVar15 * 0x40000000;
            uVar27 = ((uVar15 | uVar37) & uVar40 | uVar15 & uVar37) +
                     uVar45 + 0x8f1bbcdc + uVar38 + (uVar17 >> 0x1b) + uVar17 * 0x20;
            uVar19 = uVar6 ^ uVar19 ^ uVar33 ^ uVar23;
            uVar15 = ((uVar17 | uVar28) & uVar37 | uVar17 & uVar28) + uVar44 + 0x8f1bbcdc + uVar40 +
                     (uVar27 >> 0x1b) + uVar27 * 0x20;
            uVar17 = (uVar17 >> 2) + uVar17 * 0x40000000;
            uVar21 = uVar45 ^ uVar21 ^ uVar31 ^ uVar36;
            uVar38 = (uVar27 >> 2) + uVar27 * 0x40000000;
            uVar27 = ((uVar27 | uVar17) & uVar28 | uVar27 & uVar17) +
                     uVar19 + 0x8f1bbcdc + uVar37 + (uVar15 >> 0x1b) + uVar15 * 0x20;
            uVar33 = uVar44 ^ uVar33 ^ uVar29 ^ uVar34;
            uVar37 = ((uVar15 | uVar38) & uVar17 | uVar15 & uVar38) + uVar21 + 0x8f1bbcdc + uVar28 +
                     (uVar27 >> 0x1b) + uVar27 * 0x20;
            uVar15 = (uVar15 >> 2) + uVar15 * 0x40000000;
            uVar31 = uVar19 ^ uVar31 ^ uVar26 ^ uVar25;
            uVar40 = (uVar27 >> 2) + uVar27 * 0x40000000;
            uVar17 = ((uVar27 | uVar15) & uVar38 | uVar27 & uVar15) +
                     uVar33 + 0x8f1bbcdc + uVar17 + (uVar37 >> 0x1b) + uVar37 * 0x20;
            uVar38 = ((uVar37 | uVar40) & uVar15 | uVar37 & uVar40) + uVar31 + 0x8f1bbcdc + uVar38 +
                     (uVar17 >> 0x1b) + uVar17 * 0x20;
            uVar27 = uVar21 ^ uVar29 ^ uVar24 ^ uVar16;
            uVar29 = (uVar37 >> 2) + uVar37 * 0x40000000;
            uVar26 = uVar33 ^ uVar26 ^ uVar8 ^ uVar6;
            uVar28 = (uVar17 >> 2) + uVar17 * 0x40000000;
            uVar15 = ((uVar17 | uVar29) & uVar40 | uVar17 & uVar29) +
                     uVar27 + 0x8f1bbcdc + uVar15 + (uVar38 >> 0x1b) + uVar38 * 0x20;
            uVar24 = uVar31 ^ uVar24 ^ uVar23 ^ uVar45;
            uVar40 = ((uVar38 | uVar28) & uVar29 | uVar38 & uVar28) + uVar26 + 0x8f1bbcdc + uVar40 +
                     (uVar15 >> 0x1b) + uVar15 * 0x20;
            uVar37 = (uVar38 >> 2) + uVar38 * 0x40000000;
            uVar17 = uVar27 ^ uVar8 ^ uVar36 ^ uVar44;
            uVar11 = (uVar15 >> 2) + uVar15 * 0x40000000;
            uVar8 = ((uVar15 | uVar37) & uVar28 | uVar15 & uVar37) +
                    uVar24 + 0x8f1bbcdc + uVar29 + (uVar40 >> 0x1b) + uVar40 * 0x20;
            uVar15 = uVar26 ^ uVar23 ^ uVar34 ^ uVar19;
            uVar23 = ((uVar40 | uVar11) & uVar37 | uVar40 & uVar11) + uVar17 + 0x8f1bbcdc + uVar28 +
                     (uVar8 >> 0x1b) + uVar8 * 0x20;
            uVar38 = (uVar40 >> 2) + uVar40 * 0x40000000;
            uVar36 = uVar24 ^ uVar36 ^ uVar25 ^ uVar21;
            uVar40 = (uVar8 >> 2) + uVar8 * 0x40000000;
            uVar8 = ((uVar8 | uVar38) & uVar11 | uVar8 & uVar38) +
                    uVar15 + 0x8f1bbcdc + uVar37 + (uVar23 >> 0x1b) + uVar23 * 0x20;
            uVar29 = uVar17 ^ uVar34 ^ uVar16 ^ uVar33;
            uVar37 = ((uVar23 | uVar40) & uVar38 | uVar23 & uVar40) + uVar36 + 0x8f1bbcdc + uVar11 +
                     (uVar8 >> 0x1b) + uVar8 * 0x20;
            uVar34 = (uVar23 >> 2) + uVar23 * 0x40000000;
            uVar25 = uVar15 ^ uVar25 ^ uVar6 ^ uVar31;
            uVar28 = (uVar8 >> 2) + uVar8 * 0x40000000;
            uVar23 = ((uVar8 | uVar34) & uVar40 | uVar8 & uVar34) +
                     uVar29 + 0x8f1bbcdc + uVar38 + (uVar37 >> 0x1b) + uVar37 * 0x20;
            uVar16 = uVar36 ^ uVar16 ^ uVar45 ^ uVar27;
            uVar38 = (uVar37 >> 2) + uVar37 * 0x40000000;
            uVar37 = ((uVar37 | uVar28) & uVar34 | uVar37 & uVar28) + uVar25 + 0x8f1bbcdc + uVar40 +
                     (uVar23 >> 0x1b) + uVar23 * 0x20;
            uVar8 = uVar29 ^ uVar6 ^ uVar44 ^ uVar26;
            uVar6 = (uVar23 >> 2) + uVar23 * 0x40000000;
            uVar45 = uVar25 ^ uVar45 ^ uVar19 ^ uVar24;
            uVar23 = (uVar28 ^ uVar38 ^ uVar23) + uVar16 + 0xca62c1d6 + uVar34 +
                     (uVar37 >> 0x1b) + uVar37 * 0x20;
            uVar40 = (uVar37 >> 2) + uVar37 * 0x40000000;
            uVar11 = uVar16 ^ uVar44 ^ uVar21 ^ uVar17;
            uVar28 = (uVar38 ^ uVar6 ^ uVar37) + uVar8 + 0xca62c1d6 + uVar28 +
                     (uVar23 >> 0x1b) + uVar23 * 0x20;
            uVar34 = (uVar23 >> 2) + uVar23 * 0x40000000;
            uVar37 = (uVar6 ^ uVar40 ^ uVar23) + uVar45 + 0xca62c1d6 + uVar38 +
                     (uVar28 >> 0x1b) + uVar28 * 0x20;
            puVar20 = (undefined4 *)(uVar8 ^ uVar19 ^ uVar33 ^ uVar15);
            uVar38 = (uVar28 >> 2) + uVar28 * 0x40000000;
            uVar19 = (uVar40 ^ uVar34 ^ uVar28) + uVar11 + 0xca62c1d6 + uVar6 +
                     (uVar37 >> 0x1b) + uVar37 * 0x20;
            uVar23 = uVar45 ^ uVar21 ^ uVar31 ^ uVar36;
            uVar21 = (uVar37 >> 2) + uVar37 * 0x40000000;
            pbVar32 = (byte *)((int)puVar20 +
                              (uVar19 >> 0x1b) + uVar19 * 0x20 +
                              (uVar34 ^ uVar38 ^ uVar37) + uVar40 + 0xca62c1d6);
            uVar6 = uVar11 ^ uVar33 ^ uVar27 ^ uVar29;
            uVar33 = (uVar19 >> 2) + uVar19 * 0x40000000;
            pbVar30 = (byte *)((uint)puVar20 ^ uVar31 ^ uVar26 ^ uVar25);
            uVar28 = ((uint)pbVar32 >> 2) + (int)pbVar32 * 0x40000000;
            uVar19 = (uVar38 ^ uVar21 ^ uVar19) + uVar23 + 0xca62c1d6 + uVar34 +
                     ((uint)pbVar32 >> 0x1b) + (int)pbVar32 * 0x20;
            uVar34 = (uVar21 ^ uVar33 ^ (uint)pbVar32) + uVar6 + 0xca62c1d6 + uVar38 +
                     (uVar19 >> 0x1b) + uVar19 * 0x20;
            uVar27 = uVar23 ^ uVar27 ^ uVar24 ^ uVar16;
            uVar31 = (uVar19 >> 2) + uVar19 * 0x40000000;
            pbVar32 = pbVar30 + (uVar34 >> 0x1b) + uVar34 * 0x20 +
                                (uVar33 ^ uVar28 ^ uVar19) + uVar21 + 0xca62c1d6;
            uVar21 = uVar6 ^ uVar26 ^ uVar17 ^ uVar8;
            uVar37 = (uVar34 >> 2) + uVar34 * 0x40000000;
            uVar26 = (uVar28 ^ uVar31 ^ uVar34) + uVar27 + 0xca62c1d6 + uVar33 +
                     ((uint)pbVar32 >> 0x1b) + (int)pbVar32 * 0x20;
            uVar19 = (uint)pbVar30 ^ uVar24 ^ uVar15 ^ uVar45;
            uVar33 = ((uint)pbVar32 >> 2) + (int)pbVar32 * 0x40000000;
            uVar24 = (uVar31 ^ uVar37 ^ (uint)pbVar32) + uVar21 + 0xca62c1d6 + uVar28 +
                     (uVar26 >> 0x1b) + uVar26 * 0x20;
            uVar17 = uVar27 ^ uVar17 ^ uVar36 ^ uVar11;
            uVar38 = (uVar26 >> 2) + uVar26 * 0x40000000;
            uVar26 = (uVar37 ^ uVar33 ^ uVar26) + uVar19 + 0xca62c1d6 + uVar31 +
                     (uVar24 >> 0x1b) + uVar24 * 0x20;
            uVar15 = uVar21 ^ uVar15 ^ uVar29 ^ (uint)puVar20;
            uVar34 = (uVar24 >> 2) + uVar24 * 0x40000000;
            uVar31 = (uVar33 ^ uVar38 ^ uVar24) + uVar17 + 0xca62c1d6 + uVar37 +
                     (uVar26 >> 0x1b) + uVar26 * 0x20;
            uVar24 = uVar19 ^ uVar36 ^ uVar25 ^ uVar23;
            uVar36 = (uVar26 >> 2) + uVar26 * 0x40000000;
            uVar26 = (uVar38 ^ uVar34 ^ uVar26) + uVar15 + 0xca62c1d6 + uVar33 +
                     (uVar31 >> 0x1b) + uVar31 * 0x20;
            pbVar32 = (byte *)(uVar17 ^ uVar29 ^ uVar16 ^ uVar6);
            uVar29 = (uVar31 >> 2) + uVar31 * 0x40000000;
            uVar31 = (uVar34 ^ uVar36 ^ uVar31) + uVar24 + 0xca62c1d6 + uVar38 +
                     (uVar26 >> 0x1b) + uVar26 * 0x20;
            uVar15 = uVar15 ^ uVar25 ^ uVar8 ^ (uint)pbVar30;
            uVar25 = (uVar26 >> 2) + uVar26 * 0x40000000;
            uVar6 = uVar15 + 0xca62c1d6;
            pbVar42 = pbVar32 + (uVar31 >> 0x1b) + uVar31 * 0x20 +
                                (uVar36 ^ uVar29 ^ uVar26) + uVar34 + 0xca62c1d6;
            uVar24 = uVar24 ^ uVar16 ^ uVar45 ^ uVar27;
            uVar33 = (uVar31 >> 2) + uVar31 * 0x40000000;
            uVar27 = (uVar29 ^ uVar25 ^ uVar31) + uVar6 + uVar36 +
                     ((uint)pbVar42 >> 0x1b) + (int)pbVar42 * 0x20;
            uVar28 = uVar25 ^ uVar33 ^ (uint)pbVar42;
            uVar26 = ((uint)pbVar42 >> 2) + (int)pbVar42 * 0x40000000;
            uVar16 = uVar28 + uVar24 + 0xca62c1d6 + uVar29 + (uVar27 >> 0x1b) + uVar27 * 0x20;
            uVar29 = (uVar27 >> 2) + uVar27 * 0x40000000;
            uVar8 = ((uint)pbVar32 ^ uVar8 ^ uVar11 ^ uVar21) + 0xca62c1d6 + uVar25 +
                    (uVar33 ^ uVar26 ^ uVar27) + (uVar16 >> 0x1b) + uVar16 * 0x20;
            puVar39 = (undefined4 *)((uVar16 >> 2) + uVar16 * 0x40000000);
            puVar35 = (undefined *)((uVar24 ^ uVar11 ^ uVar23 ^ uVar17) + 0xca62c1d6);
            uVar17 = (uVar15 ^ uVar45 ^ (uint)puVar20 ^ uVar19) + 0xca62c1d6 + uVar33 +
                     (uVar26 ^ uVar29 ^ uVar16) + (uVar8 >> 0x1b) + uVar8 * 0x20;
            puVar43 = (undefined *)((uVar8 >> 2) + uVar8 * 0x40000000);
            puStackY_200 = puVar43 + (int)puStackY_200;
            puStackY_208 = puVar35 + (uVar17 >> 0x1b) + uVar17 * 0x20 +
                                     (uVar29 ^ (uint)puVar39 ^ uVar8) + uVar26 + (int)puStackY_208;
            uStackY_204 = uVar17 + uStackY_204;
            pbStackY_1fc = (byte *)((int)puVar39 + (int)pbStackY_1fc);
            piStack_184[1] = uStackY_204;
            *piStack_184 = (int)puStackY_208;
            iStackY_1f8 = uVar29 + iStackY_1f8;
            iStackY_1c0 = iStackY_1c0 + -1;
            piStack_184[4] = iStackY_1f8;
            piStack_184[2] = (int)puStackY_200;
            piStack_184[3] = (int)pbStackY_1fc;
            puVar14 = puStackY_210;
            puVar10 = puVar10 + 0x10;
          } while (iStackY_1c0 != 0);
          return 0;
        }
        return (uint)(iVar13 == 0);
      }
      return 1;
    }
  } while( true );
}

