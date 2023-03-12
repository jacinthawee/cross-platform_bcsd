
uint keyDiversifyCryptoPro(uint param_1,undefined4 *param_2,byte *param_3,undefined4 *param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint in_v0;
  uint uVar8;
  int iVar9;
  uint in_v1;
  uint extraout_v1;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  uint uVar17;
  undefined4 *puVar18;
  uint uVar19;
  uint uVar20;
  undefined4 *puVar21;
  uint uVar22;
  undefined4 uVar23;
  uint uVar24;
  uint uVar25;
  uint in_t1;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint in_t4;
  uint uVar30;
  uint in_t5;
  uint uVar31;
  uint uVar32;
  undefined *puVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  undefined4 *puVar37;
  uint uVar38;
  uint uVar39;
  undefined *puVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  undefined4 *puStackY_168;
  undefined *puStackY_160;
  uint uStackY_15c;
  undefined *puStackY_158;
  byte *pbStackY_154;
  int iStackY_150;
  int iStackY_118;
  undefined auStack_100 [4];
  undefined auStack_fc [32];
  int *piStack_dc;
  uint *puStack_d8;
  undefined4 *puStack_d4;
  uint uStack_d0;
  undefined4 *puStack_cc;
  undefined *puStack_c8;
  code *pcStack_c4;
  undefined4 uStack_b0;
  uint *puStack_ac;
  undefined *puStack_a8;
  undefined auStack_9c [32];
  uint uStack_7c;
  undefined4 *puStack_74;
  uint uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  byte *pbStack_64;
  undefined *puStack_60;
  code *pcStack_5c;
  uint *local_48;
  undefined *local_40;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  undefined local_30;
  undefined local_2f;
  undefined local_2e;
  undefined local_2d;
  uint local_2c;
  
  puStack_60 = PTR___stack_chk_guard_006aabf0;
  pbStack_64 = param_3 + 8;
  local_40 = &_gp;
  uVar8 = (uint)(param_2 + 1) & 3;
  iVar9 = *(int *)((int)(param_2 + 1) - uVar8);
  uVar19 = (uint)(param_2 + 3) & 3;
  iVar2 = *(int *)((int)(param_2 + 3) - uVar19);
  uVar15 = (uint)(param_2 + 4) & 3;
  iVar3 = *(int *)((int)(param_2 + 4) - uVar15);
  uVar24 = (uint)(param_2 + 5) & 3;
  iVar4 = *(int *)((int)(param_2 + 5) - uVar24);
  uVar13 = (uint)(param_2 + 6) & 3;
  iVar5 = *(int *)((int)(param_2 + 6) - uVar13);
  uVar41 = (uint)(param_2 + 7) & 3;
  iVar6 = *(int *)((int)(param_2 + 7) - uVar41);
  uVar23 = param_2[2];
  uVar14 = (int)param_2 + 7U & 3;
  uVar29 = *(uint *)(((int)param_2 + 7U) - uVar14);
  uVar28 = *(uint *)PTR___stack_chk_guard_006aabf0;
  uVar20 = (int)param_2 + 0x13U & 3;
  uVar30 = *(uint *)(((int)param_2 + 0x13U) - uVar20);
  uVar22 = (int)param_2 + 0x17U & 3;
  uVar31 = *(uint *)(((int)param_2 + 0x17U) - uVar22);
  uVar25 = (int)param_2 + 0x1bU & 3;
  uVar32 = *(uint *)(((int)param_2 + 0x1bU) - uVar25);
  uVar26 = (int)param_2 + 0x1fU & 3;
  uVar34 = *(uint *)(((int)param_2 + 0x1fU) - uVar26);
  uVar27 = (int)param_2 + 0xfU & 3;
  uVar35 = *(uint *)(((int)param_2 + 0xfU) - uVar27);
  *param_4 = *param_2;
  param_4[1] = (iVar9 << uVar8 * 8 | in_t1 & 0xffffffffU >> (4 - uVar8) * 8) &
               -1 << (uVar14 + 1) * 8 | uVar29 >> (3 - uVar14) * 8;
  param_4[2] = uVar23;
  param_4[3] = (iVar2 << uVar19 * 8 | (uint)param_4 & 0xffffffffU >> (4 - uVar19) * 8) &
               -1 << (uVar27 + 1) * 8 | uVar35 >> (3 - uVar27) * 8;
  param_4[4] = (iVar3 << uVar15 * 8 | (uint)param_3 & 0xffffffffU >> (4 - uVar15) * 8) &
               -1 << (uVar20 + 1) * 8 | uVar30 >> (3 - uVar20) * 8;
  param_4[5] = (iVar4 << uVar24 * 8 | param_1 & 0xffffffffU >> (4 - uVar24) * 8) &
               -1 << (uVar22 + 1) * 8 | uVar31 >> (3 - uVar22) * 8;
  param_4[6] = (iVar5 << uVar13 * 8 | in_v1 & 0xffffffffU >> (4 - uVar13) * 8) &
               -1 << (uVar25 + 1) * 8 | uVar32 >> (3 - uVar25) * 8;
  param_4[7] = (iVar6 << uVar41 * 8 | in_v0 & 0xffffffffU >> (4 - uVar41) * 8) &
               -1 << (uVar26 + 1) * 8 | uVar34 >> (3 - uVar26) * 8;
  local_2c = uVar28;
  do {
    bVar1 = *param_3;
    uVar8 = (uint)*(byte *)((int)param_4 + 1) << 8 | (uint)*(byte *)((int)param_4 + 2) << 0x10 |
            (uint)*(byte *)param_4 | (uint)*(byte *)((int)param_4 + 3) << 0x18;
    if ((bVar1 & 1) == 0) {
      uVar15 = (uint)*(byte *)((int)param_4 + 5) << 8 | (uint)*(byte *)((int)param_4 + 6) << 0x10 |
               (uint)*(byte *)(param_4 + 1) | (uint)*(byte *)((int)param_4 + 7) << 0x18;
      uVar19 = uVar8;
      uVar8 = 0;
      if ((bVar1 & 2) != 0) goto LAB_00620790;
LAB_00620578:
      uVar19 = uVar19 + uVar15;
      uVar15 = (uint)*(byte *)((int)param_4 + 9) << 8 | (uint)*(byte *)((int)param_4 + 10) << 0x10 |
               (uint)*(byte *)(param_4 + 2) | (uint)*(byte *)((int)param_4 + 0xb) << 0x18;
      if ((bVar1 & 4) == 0) goto LAB_006205ac;
LAB_006207c4:
      uVar8 = uVar8 + uVar15;
      uVar15 = (uint)*(byte *)((int)param_4 + 0xd) << 8 |
               (uint)*(byte *)((int)param_4 + 0xe) << 0x10 | (uint)*(byte *)(param_4 + 3) |
               (uint)*(byte *)((int)param_4 + 0xf) << 0x18;
      if ((bVar1 & 8) != 0) goto LAB_006207f8;
LAB_006205e0:
      uVar19 = uVar19 + uVar15;
      uVar15 = (uint)*(byte *)((int)param_4 + 0x11) << 8 |
               (uint)*(byte *)((int)param_4 + 0x12) << 0x10 | (uint)*(byte *)(param_4 + 4) |
               (uint)*(byte *)((int)param_4 + 0x13) << 0x18;
      if ((bVar1 & 0x10) == 0) goto LAB_00620614;
LAB_0062082c:
      uVar8 = uVar8 + uVar15;
      uVar15 = (uint)*(byte *)((int)param_4 + 0x15) << 8 |
               (uint)*(byte *)((int)param_4 + 0x16) << 0x10 | (uint)*(byte *)(param_4 + 5) |
               (uint)*(byte *)((int)param_4 + 0x17) << 0x18;
      if ((bVar1 & 0x20) != 0) goto LAB_00620860;
LAB_00620648:
      uVar19 = uVar19 + uVar15;
      uVar15 = (uint)*(byte *)((int)param_4 + 0x19) << 8 |
               (uint)*(byte *)((int)param_4 + 0x1a) << 0x10 | (uint)*(byte *)(param_4 + 6) |
               (uint)*(byte *)((int)param_4 + 0x1b) << 0x18;
      if ((bVar1 & 0x40) == 0) goto LAB_0062067c;
LAB_00620894:
      uVar8 = uVar8 + uVar15;
      uVar24 = (uint)*(byte *)((int)param_4 + 0x1f) << 0x18;
      uVar15 = (uint)*(byte *)((int)param_4 + 0x1d) << 8 |
               (uint)*(byte *)((int)param_4 + 0x1e) << 0x10 | (uint)*(byte *)(param_4 + 7) | uVar24;
      if ((bVar1 & 0x80) != 0) goto LAB_006208c8;
LAB_006206b0:
      uVar19 = uVar19 + uVar15;
    }
    else {
      uVar19 = 0;
      uVar15 = (uint)*(byte *)((int)param_4 + 5) << 8 | (uint)*(byte *)((int)param_4 + 6) << 0x10 |
               (uint)*(byte *)(param_4 + 1) | (uint)*(byte *)((int)param_4 + 7) << 0x18;
      if ((bVar1 & 2) == 0) goto LAB_00620578;
LAB_00620790:
      uVar8 = uVar8 + uVar15;
      uVar15 = (uint)*(byte *)((int)param_4 + 9) << 8 | (uint)*(byte *)((int)param_4 + 10) << 0x10 |
               (uint)*(byte *)(param_4 + 2) | (uint)*(byte *)((int)param_4 + 0xb) << 0x18;
      if ((bVar1 & 4) != 0) goto LAB_006207c4;
LAB_006205ac:
      uVar19 = uVar19 + uVar15;
      uVar15 = (uint)*(byte *)((int)param_4 + 0xd) << 8 |
               (uint)*(byte *)((int)param_4 + 0xe) << 0x10 | (uint)*(byte *)(param_4 + 3) |
               (uint)*(byte *)((int)param_4 + 0xf) << 0x18;
      if ((bVar1 & 8) == 0) goto LAB_006205e0;
LAB_006207f8:
      uVar8 = uVar8 + uVar15;
      uVar15 = (uint)*(byte *)((int)param_4 + 0x11) << 8 |
               (uint)*(byte *)((int)param_4 + 0x12) << 0x10 | (uint)*(byte *)(param_4 + 4) |
               (uint)*(byte *)((int)param_4 + 0x13) << 0x18;
      if ((bVar1 & 0x10) != 0) goto LAB_0062082c;
LAB_00620614:
      uVar19 = uVar19 + uVar15;
      uVar15 = (uint)*(byte *)((int)param_4 + 0x15) << 8 |
               (uint)*(byte *)((int)param_4 + 0x16) << 0x10 | (uint)*(byte *)(param_4 + 5) |
               (uint)*(byte *)((int)param_4 + 0x17) << 0x18;
      if ((bVar1 & 0x20) == 0) goto LAB_00620648;
LAB_00620860:
      uVar8 = uVar8 + uVar15;
      uVar15 = (uint)*(byte *)((int)param_4 + 0x19) << 8 |
               (uint)*(byte *)((int)param_4 + 0x1a) << 0x10 | (uint)*(byte *)(param_4 + 6) |
               (uint)*(byte *)((int)param_4 + 0x1b) << 0x18;
      if ((bVar1 & 0x40) != 0) goto LAB_00620894;
LAB_0062067c:
      uVar19 = uVar19 + uVar15;
      uVar24 = (uint)*(byte *)((int)param_4 + 0x1f) << 0x18;
      uVar15 = (uint)*(byte *)((int)param_4 + 0x1d) << 8 |
               (uint)*(byte *)((int)param_4 + 0x1e) << 0x10 | (uint)*(byte *)(param_4 + 7) | uVar24;
      if ((bVar1 & 0x80) == 0) goto LAB_006206b0;
LAB_006208c8:
      uVar8 = uVar8 + uVar15;
    }
    local_34 = (undefined)uVar8;
    local_30 = (undefined)uVar19;
    local_33 = (undefined)(uVar8 >> 8);
    local_32 = (undefined)(uVar8 >> 0x10);
    local_2f = (undefined)(uVar19 >> 8);
    local_31 = (undefined)(uVar8 >> 0x18);
    local_2e = (undefined)(uVar19 >> 0x10);
    local_2d = (undefined)(uVar19 >> 0x18);
    param_3 = param_3 + 1;
    gost_key(param_1,param_4);
    local_48 = (uint *)&SUB_00000004;
    uStack_d0 = param_1;
    puStack_d4 = param_4;
    puStack_cc = param_4;
    gost_enc_cfb(param_1,&local_34);
    if (pbStack_64 == param_3) {
      uVar8 = *(uint *)puStack_60;
      if (local_2c == uVar8) {
        return uVar8;
      }
      pcStack_5c = keyWrapCryptoPro;
      (**(code **)(local_40 + -0x5328))();
      puVar16 = local_48;
      puVar40 = PTR___stack_chk_guard_006aabf0;
      puStack_c8 = auStack_9c;
      uStack_68 = 0xffffff80;
      uStack_6c = 4;
      puStack_a8 = &_gp;
      uStack_7c = *(uint *)PTR___stack_chk_guard_006aabf0;
      puStack_74 = param_4;
      uStack_70 = param_1;
      keyDiversifyCryptoPro();
      gost_key(uStack_d0,puStack_c8);
      uVar8 = (uint)puStack_d4 & 3;
      uVar15 = puStack_d4[1];
      uVar19 = (uint)(byte *)((int)puStack_d4 + 3U) & 3;
      *puVar16 = (*(int *)((int)puStack_d4 - uVar8) << uVar8 * 8 |
                 extraout_v1 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar19 + 1) * 8 |
                 *(uint *)((byte *)((int)puStack_d4 + 3U) + -uVar19) >> (3 - uVar19) * 8;
      puVar16[1] = uVar15;
      puStack_d8 = puVar16 + 10;
      gost_enc(uStack_d0,puStack_cc,puVar16 + 2,4);
      uStack_b0 = 0x20;
      puVar18 = puStack_d4;
      puVar37 = puStack_cc;
      puStack_ac = puStack_d8;
      gost_mac_iv(uStack_d0,0x20);
      if (uStack_7c == *(uint *)puVar40) {
        return 1;
      }
      pcStack_c4 = keyUnwrapCryptoPro;
      uVar8 = uStack_7c;
      (**(code **)(puStack_a8 + -0x5328))();
      puVar40 = PTR___stack_chk_guard_006aabf0;
      piStack_dc = *(int **)PTR___stack_chk_guard_006aabf0;
      keyDiversifyCryptoPro();
      puVar33 = auStack_100;
      gost_key(uVar8,auStack_fc);
      gost_dec(uVar8,puVar18 + 2,puVar37,4);
      puVar21 = puVar37;
      gost_mac_iv(uVar8,0x20,puVar18,puVar37,0x20,puVar33);
      iStackY_118 = 4;
      puVar16 = puVar18 + 10;
      iVar9 = (*(code *)PTR_memcmp_006aabd8)(puVar33);
      if (piStack_dc == *(int **)puVar40) {
        return (uint)(iVar9 == 0);
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      puStackY_160 = (undefined *)*piStack_dc;
      uStackY_15c = piStack_dc[1];
      puStackY_158 = (undefined *)piStack_dc[2];
      pbStackY_154 = (byte *)piStack_dc[3];
      iStackY_150 = piStack_dc[4];
      puStackY_168 = (undefined4 *)0xca62c1d6;
      puVar7 = puVar16;
      do {
        if (((uint)puVar16 & 3) == 0) {
          uVar22 = *puVar7;
          uVar25 = puVar7[1];
          uVar24 = (uStackY_15c >> 2) + uStackY_15c * 0x40000000;
          uVar31 = puVar7[2];
          uVar30 = puVar7[3];
          uVar29 = puVar7[4];
          uVar27 = puVar7[5];
          uVar26 = puVar7[6];
          uVar38 = puVar7[7];
          uVar36 = puVar7[8];
          uVar19 = ((uint)puStackY_160 >> 0x1b) + (int)puStackY_160 * 0x20 +
                   iStackY_150 + 0x5a827999 + uVar22 +
                   (((uint)puStackY_158 ^ (uint)pbStackY_154) & uStackY_15c ^ (uint)pbStackY_154);
          uVar34 = puVar7[9];
          uVar32 = puVar7[10];
          uVar28 = puVar7[0xb];
          uVar35 = puVar7[0xc];
          uVar13 = ((uint)puStackY_160 >> 2) + (int)puStackY_160 * 0x40000000;
          uVar43 = puVar7[0xe];
          uVar8 = puVar7[0xd];
          uVar42 = puVar7[0xf];
          pbVar12 = pbStackY_154 +
                    (uVar19 >> 0x1b) + uVar19 * 0x20 +
                    (((uint)puStackY_158 ^ uVar24) & (uint)puStackY_160 ^ (uint)puStackY_158) +
                    uVar25 + 0x5a827999;
          uVar15 = (uVar19 >> 2) + uVar19 * 0x40000000;
          puVar40 = puStackY_158 +
                    ((uint)pbVar12 >> 0x1b) + (int)pbVar12 * 0x20 +
                    ((uVar24 ^ uVar13) & uVar19 ^ uVar24) + uVar31 + 0x5a827999;
          uVar19 = ((uint)pbVar12 >> 2) + (int)pbVar12 * 0x40000000;
          uVar24 = ((uVar13 ^ uVar15) & (uint)pbVar12 ^ uVar13) + uVar24 + 0x5a827999 + uVar30 +
                   ((uint)puVar40 >> 0x1b) + (int)puVar40 * 0x20;
          uVar10 = ((uint)puVar40 >> 2) + (int)puVar40 * 0x40000000;
          uVar20 = (uVar24 >> 2) + uVar24 * 0x40000000;
          uVar41 = ((uVar15 ^ uVar19) & (uint)puVar40 ^ uVar15) + uVar13 + 0x5a827999 + uVar29 +
                   (uVar24 >> 0x1b) + uVar24 * 0x20;
          uVar14 = (uVar41 >> 2) + uVar41 * 0x40000000;
          uVar24 = ((uVar19 ^ uVar10) & uVar24 ^ uVar19) + uVar27 + 0x5a827999 + uVar15 +
                   (uVar41 >> 0x1b) + uVar41 * 0x20;
          uVar13 = (uVar24 >> 2) + uVar24 * 0x40000000;
          uVar19 = ((uVar10 ^ uVar20) & uVar41 ^ uVar10) + uVar26 + 0x5a827999 + uVar19 +
                   (uVar24 >> 0x1b) + uVar24 * 0x20;
          uVar15 = (uVar19 >> 2) + uVar19 * 0x40000000;
          uVar24 = ((uVar20 ^ uVar14) & uVar24 ^ uVar20) + uVar38 + 0x5a827999 + uVar10 +
                   (uVar19 >> 0x1b) + uVar19 * 0x20;
          uVar41 = (uVar24 >> 2) + uVar24 * 0x40000000;
          uVar19 = ((uVar14 ^ uVar13) & uVar19 ^ uVar14) + uVar36 + 0x5a827999 + uVar20 +
                   (uVar24 >> 0x1b) + uVar24 * 0x20;
          uVar20 = (uVar19 >> 2) + uVar19 * 0x40000000;
          uVar24 = ((uVar13 ^ uVar15) & uVar24 ^ uVar13) + uVar34 + 0x5a827999 + uVar14 +
                   (uVar19 >> 0x1b) + uVar19 * 0x20;
          uVar19 = ((uVar15 ^ uVar41) & uVar19 ^ uVar15) + uVar32 + 0x5a827999 + uVar13 +
                   (uVar24 >> 0x1b) + uVar24 * 0x20;
          uVar13 = (uVar24 >> 2) + uVar24 * 0x40000000;
          iVar9 = ((uVar41 ^ uVar20) & uVar24 ^ uVar41) + uVar28 + 0x5a827999 + uVar15;
        }
        else {
          uVar39 = ((uint)puStackY_160 >> 2) + (int)puStackY_160 * 0x40000000;
          uVar19 = (uint)puVar7 & 3;
          uVar15 = (uint)(puVar7 + 1) & 3;
          uVar13 = (uint)(puVar7 + 2) & 3;
          uVar41 = (uint)(puVar7 + 3) & 3;
          uVar14 = (uint)(byte *)((int)puVar7 + 3U) & 3;
          uVar22 = (*(int *)((int)puVar7 - uVar19) << uVar19 * 8 |
                   (uint)puVar21 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar14 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 3U) + -uVar14) >> (3 - uVar14) * 8;
          uVar17 = (uStackY_15c >> 2) + uStackY_15c * 0x40000000;
          uVar19 = (uint)(byte *)((int)puVar7 + 7U) & 3;
          uVar25 = (*(int *)((int)(puVar7 + 1) - uVar15) << uVar15 * 8 |
                   uVar24 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar19 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 7U) + -uVar19) >> (3 - uVar19) * 8;
          uVar19 = (uint)(byte *)((int)puVar7 + 0xbU) & 3;
          uVar31 = (*(int *)((int)(puVar7 + 2) - uVar13) << uVar13 * 8 |
                   in_t5 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar19 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0xbU) + -uVar19) >> (3 - uVar19) * 8;
          uVar19 = (uint)(puVar7 + 4) & 3;
          uVar15 = (uint)(puVar7 + 5) & 3;
          uVar10 = (((uint)puStackY_158 ^ (uint)pbStackY_154) & uStackY_15c ^ (uint)pbStackY_154) +
                   ((uint)puStackY_160 >> 0x1b) + (int)puStackY_160 * 0x20 +
                   iStackY_150 + 0x5a827999 + uVar22;
          uVar24 = (uint)(byte *)((int)puVar7 + 0xfU) & 3;
          uVar30 = (*(int *)((int)(puVar7 + 3) - uVar41) << uVar41 * 8 |
                   in_t4 & 0xffffffffU >> (4 - uVar41) * 8) & -1 << (uVar24 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0xfU) + -uVar24) >> (3 - uVar24) * 8;
          uVar24 = (uint)(puVar7 + 6) & 3;
          uVar13 = (uint)(puVar7 + 7) & 3;
          uVar41 = (uint)(byte *)((int)puVar7 + 0x13U) & 3;
          uVar29 = (*(int *)((int)(puVar7 + 4) - uVar19) << uVar19 * 8 |
                   uVar28 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar41 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0x13U) + -uVar41) >> (3 - uVar41) * 8;
          uVar19 = (uint)(byte *)((int)puVar7 + 0x17U) & 3;
          uVar27 = (*(int *)((int)(puVar7 + 5) - uVar15) << uVar15 * 8 |
                   uStackY_15c & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar19 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0x17U) + -uVar19) >> (3 - uVar19) * 8;
          uVar19 = (uint)(puVar7 + 8) & 3;
          uVar15 = (uint)(puVar7 + 9) & 3;
          uVar41 = (uint)(puVar7 + 10) & 3;
          pbVar12 = pbStackY_154 +
                    (uVar10 >> 0x1b) + uVar10 * 0x20 +
                    (((uint)puStackY_158 ^ uVar17) & (uint)puStackY_160 ^ (uint)puStackY_158) +
                    uVar25 + 0x5a827999;
          uVar14 = (uint)(puVar7 + 0xb) & 3;
          uVar20 = (uint)(puVar7 + 0xc) & 3;
          uVar26 = (uint)(byte *)((int)puVar7 + 0x1bU) & 3;
          uVar26 = (*(int *)((int)(puVar7 + 6) - uVar24) << uVar24 * 8 |
                   (uint)pbStackY_154 & 0xffffffffU >> (4 - uVar24) * 8) & -1 << (uVar26 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0x1bU) + -uVar26) >> (3 - uVar26) * 8;
          uVar11 = (uVar10 >> 2) + uVar10 * 0x40000000;
          uVar24 = (uint)(byte *)((int)puVar7 + 0x1fU) & 3;
          uVar38 = (*(int *)((int)(puVar7 + 7) - uVar13) << uVar13 * 8 |
                   (uint)puVar37 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar24 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0x1fU) + -uVar24) >> (3 - uVar24) * 8;
          uVar24 = (uint)(byte *)((int)puVar7 + 0x23U) & 3;
          uVar36 = (*(int *)((int)(puVar7 + 8) - uVar19) << uVar19 * 8 |
                   (uint)puVar40 & 0xffffffffU >> (4 - uVar19) * 8) & -1 << (uVar24 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0x23U) + -uVar24) >> (3 - uVar24) * 8;
          uVar19 = (uint)(puVar7 + 0xd) & 3;
          uVar24 = (uint)(byte *)((int)puVar7 + 0x27U) & 3;
          uVar34 = (*(int *)((int)(puVar7 + 9) - uVar15) << uVar15 * 8 |
                   (uint)puVar33 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar24 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0x27U) + -uVar24) >> (3 - uVar24) * 8;
          uVar15 = (uint)(byte *)((int)puVar7 + 0x2bU) & 3;
          uVar32 = (*(int *)((int)(puVar7 + 10) - uVar41) << uVar41 * 8 |
                   (uint)puStackY_158 & 0xffffffffU >> (4 - uVar41) * 8) & -1 << (uVar15 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0x2bU) + -uVar15) >> (3 - uVar15) * 8;
          uVar15 = (uint)(byte *)((int)puVar7 + 0x2fU) & 3;
          uVar28 = (*(int *)((int)(puVar7 + 0xb) - uVar14) << uVar14 * 8 |
                   uVar8 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar15 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0x2fU) + -uVar15) >> (3 - uVar15) * 8;
          uVar15 = (uint)(puVar7 + 0xe) & 3;
          uVar24 = (uint)(puVar7 + 0xf) & 3;
          uVar8 = (uint)(byte *)((int)puVar7 + 0x33U) & 3;
          uVar35 = (*(int *)((int)(puVar7 + 0xc) - uVar20) << uVar20 * 8 |
                   (uint)puVar18 & 0xffffffffU >> (4 - uVar20) * 8) & -1 << (uVar8 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0x33U) + -uVar8) >> (3 - uVar8) * 8;
          uVar8 = (uint)(byte *)((int)puVar7 + 0x37U) & 3;
          uVar8 = (*(int *)((int)(puVar7 + 0xd) - uVar19) << uVar19 * 8 |
                  (uint)(puStackY_158 + uVar31 + 0x5a827999) & 0xffffffffU >> (4 - uVar19) * 8) &
                  -1 << (uVar8 + 1) * 8 |
                  *(uint *)((byte *)((int)puVar7 + 0x37U) + -uVar8) >> (3 - uVar8) * 8;
          puVar40 = puStackY_158 + uVar31 + 0x5a827999 +
                    ((uint)pbVar12 >> 0x1b) + (int)pbVar12 * 0x20 +
                    ((uVar17 ^ uVar39) & uVar10 ^ uVar17);
          uVar13 = ((uint)pbVar12 >> 2) + (int)pbVar12 * 0x40000000;
          uVar19 = (uint)(byte *)((int)puVar7 + 0x3bU) & 3;
          uVar43 = (*(int *)((int)(puVar7 + 0xe) - uVar15) << uVar15 * 8 |
                   (uint)puStackY_160 & 0xffffffffU >> (4 - uVar15) * 8) & -1 << (uVar19 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0x3bU) + -uVar19) >> (3 - uVar19) * 8;
          uVar19 = (uint)(byte *)((int)puVar7 + 0x3fU) & 3;
          uVar42 = (*(int *)((int)(puVar7 + 0xf) - uVar24) << uVar24 * 8 |
                   0xffffffffU >> (4 - uVar24) * 8 & 0x5a827999) & -1 << (uVar19 + 1) * 8 |
                   *(uint *)((byte *)((int)puVar7 + 0x3fU) + -uVar19) >> (3 - uVar19) * 8;
          uVar19 = ((uVar39 ^ uVar11) & (uint)pbVar12 ^ uVar39) + uVar17 + 0x5a827999 + uVar30 +
                   ((uint)puVar40 >> 0x1b) + (int)puVar40 * 0x20;
          uVar41 = ((uint)puVar40 >> 2) + (int)puVar40 * 0x40000000;
          uVar20 = (uVar19 >> 2) + uVar19 * 0x40000000;
          uVar24 = ((uVar11 ^ uVar13) & (uint)puVar40 ^ uVar11) + uVar39 + 0x5a827999 + uVar29 +
                   (uVar19 >> 0x1b) + uVar19 * 0x20;
          uVar10 = (uVar24 >> 2) + uVar24 * 0x40000000;
          uVar19 = ((uVar13 ^ uVar41) & uVar19 ^ uVar13) + uVar27 + 0x5a827999 + uVar11 +
                   (uVar24 >> 0x1b) + uVar24 * 0x20;
          uVar15 = (uVar19 >> 2) + uVar19 * 0x40000000;
          uVar24 = ((uVar41 ^ uVar20) & uVar24 ^ uVar41) + uVar26 + 0x5a827999 + uVar13 +
                   (uVar19 >> 0x1b) + uVar19 * 0x20;
          uVar14 = (uVar24 >> 2) + uVar24 * 0x40000000;
          uVar19 = ((uVar20 ^ uVar10) & uVar19 ^ uVar20) + uVar38 + 0x5a827999 + uVar41 +
                   (uVar24 >> 0x1b) + uVar24 * 0x20;
          uVar41 = (uVar19 >> 2) + uVar19 * 0x40000000;
          uVar13 = ((uVar10 ^ uVar15) & uVar24 ^ uVar10) + uVar36 + 0x5a827999 + uVar20 +
                   (uVar19 >> 0x1b) + uVar19 * 0x20;
          uVar20 = (uVar13 >> 2) + uVar13 * 0x40000000;
          uVar24 = ((uVar15 ^ uVar14) & uVar19 ^ uVar15) + uVar34 + 0x5a827999 + uVar10 +
                   (uVar13 >> 0x1b) + uVar13 * 0x20;
          uVar19 = ((uVar14 ^ uVar41) & uVar13 ^ uVar14) + uVar32 + 0x5a827999 + uVar15 +
                   (uVar24 >> 0x1b) + uVar24 * 0x20;
          uVar13 = (uVar24 >> 2) + uVar24 * 0x40000000;
          iVar9 = ((uVar41 ^ uVar20) & uVar24 ^ uVar41) + uVar28 + 0x5a827999 + uVar14;
        }
        uVar15 = iVar9 + (uVar19 >> 0x1b) + uVar19 * 0x20;
        uVar24 = (uVar19 >> 2) + uVar19 * 0x40000000;
        uVar14 = (uVar15 >> 2) + uVar15 * 0x40000000;
        uVar19 = ((uVar20 ^ uVar13) & uVar19 ^ uVar20) + uVar35 + 0x5a827999 + uVar41 +
                 (uVar15 >> 0x1b) + uVar15 * 0x20;
        uVar15 = ((uVar13 ^ uVar24) & uVar15 ^ uVar13) + uVar8 + 0x5a827999 + uVar20 +
                 (uVar19 >> 0x1b) + uVar19 * 0x20;
        uVar10 = (uVar19 >> 2) + uVar19 * 0x40000000;
        uVar41 = ((uVar24 ^ uVar14) & uVar19 ^ uVar24) + uVar43 + 0x5a827999 + uVar13 +
                 (uVar15 >> 0x1b) + uVar15 * 0x20;
        uVar19 = ((uVar14 ^ uVar10) & uVar15 ^ uVar14) + uVar42 + 0x5a827999 + uVar24 +
                 (uVar41 >> 0x1b) + uVar41 * 0x20;
        uVar20 = uVar8 ^ uVar22 ^ uVar31 ^ uVar36;
        uVar24 = (uVar15 >> 2) + uVar15 * 0x40000000;
        uVar13 = (uVar41 >> 2) + uVar41 * 0x40000000;
        uVar22 = uVar43 ^ uVar25 ^ uVar30 ^ uVar34;
        uVar14 = (uVar19 >> 0x1b) + uVar19 * 0x20 + uVar14 + 0x5a827999 + uVar20 +
                 ((uVar24 ^ uVar10) & uVar41 ^ uVar10);
        uVar15 = (uVar19 >> 2) + uVar19 * 0x40000000;
        uVar31 = uVar42 ^ uVar31 ^ uVar29 ^ uVar32;
        uVar41 = ((uVar24 ^ uVar13) & uVar19 ^ uVar24) + uVar10 + 0x5a827999 + uVar22 +
                 (uVar14 >> 0x1b) + uVar14 * 0x20;
        uVar10 = (uVar14 >> 2) + uVar14 * 0x40000000;
        uVar30 = uVar20 ^ uVar30 ^ uVar27 ^ uVar28;
        uVar19 = ((uVar13 ^ uVar15) & uVar14 ^ uVar13) + uVar24 + 0x5a827999 + uVar31 +
                 (uVar41 >> 0x1b) + uVar41 * 0x20;
        uVar14 = (uVar41 >> 2) + uVar41 * 0x40000000;
        uVar29 = uVar22 ^ uVar29 ^ uVar26 ^ uVar35;
        uVar13 = ((uVar15 ^ uVar10) & uVar41 ^ uVar15) + uVar13 + 0x5a827999 + uVar30 +
                 (uVar19 >> 0x1b) + uVar19 * 0x20;
        uVar27 = uVar31 ^ uVar27 ^ uVar38 ^ uVar8;
        uVar24 = (uVar19 >> 2) + uVar19 * 0x40000000;
        uVar15 = (uVar10 ^ uVar14 ^ uVar19) + uVar15 + 0x6ed9eba1 + uVar29 +
                 (uVar13 >> 0x1b) + uVar13 * 0x20;
        uVar25 = uVar30 ^ uVar26 ^ uVar36 ^ uVar43;
        uVar41 = (uVar13 >> 2) + uVar13 * 0x40000000;
        uVar13 = (uVar14 ^ uVar24 ^ uVar13) + uVar27 + 0x6ed9eba1 + uVar10 +
                 (uVar15 >> 0x1b) + uVar15 * 0x20;
        uVar19 = uVar29 ^ uVar38 ^ uVar34 ^ uVar42;
        uVar10 = (uVar15 >> 2) + uVar15 * 0x40000000;
        uVar26 = (uVar24 ^ uVar41 ^ uVar15) + uVar25 + 0x6ed9eba1 + uVar14 +
                 (uVar13 >> 0x1b) + uVar13 * 0x20;
        uVar15 = uVar27 ^ uVar36 ^ uVar32 ^ uVar20;
        uVar14 = (uVar13 >> 2) + uVar13 * 0x40000000;
        uVar13 = (uVar41 ^ uVar10 ^ uVar13) + uVar19 + 0x6ed9eba1 + uVar24 +
                 (uVar26 >> 0x1b) + uVar26 * 0x20;
        uVar34 = uVar25 ^ uVar34 ^ uVar28 ^ uVar22;
        uVar36 = (uVar26 >> 2) + uVar26 * 0x40000000;
        uVar24 = (uVar10 ^ uVar14 ^ uVar26) + uVar15 + 0x6ed9eba1 + uVar41 +
                 (uVar13 >> 0x1b) + uVar13 * 0x20;
        uVar41 = uVar19 ^ uVar32 ^ uVar35 ^ uVar31;
        uVar38 = (uVar13 >> 2) + uVar13 * 0x40000000;
        uVar32 = (uVar14 ^ uVar36 ^ uVar13) + uVar34 + 0x6ed9eba1 + uVar10 +
                 (uVar24 >> 0x1b) + uVar24 * 0x20;
        uVar13 = uVar15 ^ uVar28 ^ uVar8 ^ uVar30;
        uVar28 = (uVar24 >> 2) + uVar24 * 0x40000000;
        uVar26 = (uVar36 ^ uVar38 ^ uVar24) + uVar41 + 0x6ed9eba1 + uVar14 +
                 (uVar32 >> 0x1b) + uVar32 * 0x20;
        uVar14 = uVar34 ^ uVar35 ^ uVar43 ^ uVar29;
        uVar10 = (uVar32 >> 2) + uVar32 * 0x40000000;
        uVar24 = (uVar38 ^ uVar28 ^ uVar32) + uVar13 + 0x6ed9eba1 + uVar36 +
                 (uVar26 >> 0x1b) + uVar26 * 0x20;
        uVar8 = uVar41 ^ uVar8 ^ uVar42 ^ uVar27;
        uVar32 = (uVar26 >> 2) + uVar26 * 0x40000000;
        uVar35 = (uVar28 ^ uVar10 ^ uVar26) + uVar14 + 0x6ed9eba1 + uVar38 +
                 (uVar24 >> 0x1b) + uVar24 * 0x20;
        uVar43 = uVar13 ^ uVar43 ^ uVar20 ^ uVar25;
        uVar26 = (uVar24 >> 2) + uVar24 * 0x40000000;
        uVar28 = (uVar10 ^ uVar32 ^ uVar24) + uVar8 + 0x6ed9eba1 + uVar28 +
                 (uVar35 >> 0x1b) + uVar35 * 0x20;
        uVar42 = uVar14 ^ uVar42 ^ uVar22 ^ uVar19;
        uVar36 = (uVar35 >> 2) + uVar35 * 0x40000000;
        uVar24 = (uVar32 ^ uVar26 ^ uVar35) + uVar43 + 0x6ed9eba1 + uVar10 +
                 (uVar28 >> 0x1b) + uVar28 * 0x20;
        uVar20 = uVar8 ^ uVar20 ^ uVar31 ^ uVar15;
        uVar38 = (uVar28 >> 2) + uVar28 * 0x40000000;
        uVar35 = (uVar26 ^ uVar36 ^ uVar28) + uVar42 + 0x6ed9eba1 + uVar32 +
                 (uVar24 >> 0x1b) + uVar24 * 0x20;
        uVar22 = uVar43 ^ uVar22 ^ uVar30 ^ uVar34;
        uVar32 = (uVar24 >> 2) + uVar24 * 0x40000000;
        uVar26 = (uVar36 ^ uVar38 ^ uVar24) + uVar20 + 0x6ed9eba1 + uVar26 +
                 (uVar35 >> 0x1b) + uVar35 * 0x20;
        uVar31 = uVar42 ^ uVar31 ^ uVar29 ^ uVar41;
        uVar28 = (uVar35 >> 2) + uVar35 * 0x40000000;
        uVar30 = uVar20 ^ uVar30 ^ uVar27 ^ uVar13;
        uVar24 = (uVar38 ^ uVar32 ^ uVar35) + uVar22 + 0x6ed9eba1 + uVar36 +
                 (uVar26 >> 0x1b) + uVar26 * 0x20;
        uVar10 = (uVar26 >> 2) + uVar26 * 0x40000000;
        uVar29 = uVar22 ^ uVar29 ^ uVar25 ^ uVar14;
        uVar35 = (uVar32 ^ uVar28 ^ uVar26) + uVar31 + 0x6ed9eba1 + uVar38 +
                 (uVar24 >> 0x1b) + uVar24 * 0x20;
        uVar36 = (uVar24 >> 2) + uVar24 * 0x40000000;
        uVar26 = uVar31 ^ uVar27 ^ uVar19 ^ uVar8;
        uVar24 = (uVar28 ^ uVar10 ^ uVar24) + uVar30 + 0x6ed9eba1 + uVar32 +
                 (uVar35 >> 0x1b) + uVar35 * 0x20;
        uVar27 = (uVar35 >> 2) + uVar35 * 0x40000000;
        uVar32 = (uVar10 ^ uVar36 ^ uVar35) + uVar29 + 0x6ed9eba1 + uVar28 +
                 (uVar24 >> 0x1b) + uVar24 * 0x20;
        uVar25 = uVar30 ^ uVar25 ^ uVar15 ^ uVar43;
        uVar38 = (uVar24 >> 2) + uVar24 * 0x40000000;
        uVar19 = uVar29 ^ uVar19 ^ uVar34 ^ uVar42;
        uVar28 = (uVar36 ^ uVar27 ^ uVar24) + uVar26 + 0x6ed9eba1 + uVar10 +
                 (uVar32 >> 0x1b) + uVar32 * 0x20;
        uVar35 = (uVar32 >> 2) + uVar32 * 0x40000000;
        uVar32 = (uVar27 ^ uVar38 ^ uVar32) + uVar25 + 0x6ed9eba1 + uVar36 +
                 (uVar28 >> 0x1b) + uVar28 * 0x20;
        uVar24 = uVar26 ^ uVar15 ^ uVar41 ^ uVar20;
        uVar27 = (uVar38 ^ uVar35 ^ uVar28) + uVar19 + 0x6ed9eba1 + uVar27 +
                 (uVar32 >> 0x1b) + uVar32 * 0x20;
        uVar28 = (uVar28 >> 2) + uVar28 * 0x40000000;
        uVar34 = uVar25 ^ uVar34 ^ uVar13 ^ uVar22;
        uVar11 = (uVar32 >> 2) + uVar32 * 0x40000000;
        uVar15 = ((uVar32 | uVar28) & uVar35 | uVar32 & uVar28) +
                 uVar24 + 0x8f1bbcdc + uVar38 + (uVar27 >> 0x1b) + uVar27 * 0x20;
        uVar32 = uVar19 ^ uVar41 ^ uVar14 ^ uVar31;
        uVar35 = ((uVar27 | uVar11) & uVar28 | uVar27 & uVar11) + uVar34 + 0x8f1bbcdc + uVar35 +
                 (uVar15 >> 0x1b) + uVar15 * 0x20;
        uVar36 = (uVar27 >> 2) + uVar27 * 0x40000000;
        uVar41 = uVar24 ^ uVar13 ^ uVar8 ^ uVar30;
        uVar10 = (uVar15 >> 2) + uVar15 * 0x40000000;
        uVar15 = ((uVar15 | uVar36) & uVar11 | uVar15 & uVar36) +
                 uVar32 + 0x8f1bbcdc + uVar28 + (uVar35 >> 0x1b) + uVar35 * 0x20;
        uVar14 = uVar34 ^ uVar14 ^ uVar43 ^ uVar29;
        uVar27 = ((uVar35 | uVar10) & uVar36 | uVar35 & uVar10) + uVar41 + 0x8f1bbcdc + uVar11 +
                 (uVar15 >> 0x1b) + uVar15 * 0x20;
        uVar28 = (uVar35 >> 2) + uVar35 * 0x40000000;
        uVar8 = uVar32 ^ uVar8 ^ uVar42 ^ uVar26;
        uVar38 = (uVar15 >> 2) + uVar15 * 0x40000000;
        uVar13 = ((uVar15 | uVar28) & uVar10 | uVar15 & uVar28) +
                 uVar14 + 0x8f1bbcdc + uVar36 + (uVar27 >> 0x1b) + uVar27 * 0x20;
        uVar43 = uVar41 ^ uVar43 ^ uVar20 ^ uVar25;
        uVar15 = ((uVar27 | uVar38) & uVar28 | uVar27 & uVar38) + uVar8 + 0x8f1bbcdc + uVar10 +
                 (uVar13 >> 0x1b) + uVar13 * 0x20;
        uVar35 = (uVar27 >> 2) + uVar27 * 0x40000000;
        uVar42 = uVar14 ^ uVar42 ^ uVar22 ^ uVar19;
        uVar36 = (uVar13 >> 2) + uVar13 * 0x40000000;
        uVar27 = ((uVar13 | uVar35) & uVar38 | uVar13 & uVar35) +
                 uVar43 + 0x8f1bbcdc + uVar28 + (uVar15 >> 0x1b) + uVar15 * 0x20;
        uVar20 = uVar8 ^ uVar20 ^ uVar31 ^ uVar24;
        uVar13 = ((uVar15 | uVar36) & uVar35 | uVar15 & uVar36) + uVar42 + 0x8f1bbcdc + uVar38 +
                 (uVar27 >> 0x1b) + uVar27 * 0x20;
        uVar15 = (uVar15 >> 2) + uVar15 * 0x40000000;
        uVar22 = uVar43 ^ uVar22 ^ uVar30 ^ uVar34;
        uVar28 = (uVar27 >> 2) + uVar27 * 0x40000000;
        uVar27 = ((uVar27 | uVar15) & uVar36 | uVar27 & uVar15) +
                 uVar20 + 0x8f1bbcdc + uVar35 + (uVar13 >> 0x1b) + uVar13 * 0x20;
        uVar31 = uVar42 ^ uVar31 ^ uVar29 ^ uVar32;
        uVar35 = ((uVar13 | uVar28) & uVar15 | uVar13 & uVar28) + uVar22 + 0x8f1bbcdc + uVar36 +
                 (uVar27 >> 0x1b) + uVar27 * 0x20;
        uVar13 = (uVar13 >> 2) + uVar13 * 0x40000000;
        uVar30 = uVar20 ^ uVar30 ^ uVar26 ^ uVar41;
        uVar38 = (uVar27 >> 2) + uVar27 * 0x40000000;
        uVar15 = ((uVar27 | uVar13) & uVar28 | uVar27 & uVar13) +
                 uVar31 + 0x8f1bbcdc + uVar15 + (uVar35 >> 0x1b) + uVar35 * 0x20;
        uVar28 = ((uVar35 | uVar38) & uVar13 | uVar35 & uVar38) + uVar30 + 0x8f1bbcdc + uVar28 +
                 (uVar15 >> 0x1b) + uVar15 * 0x20;
        uVar27 = uVar22 ^ uVar29 ^ uVar25 ^ uVar14;
        uVar29 = (uVar35 >> 2) + uVar35 * 0x40000000;
        uVar26 = uVar31 ^ uVar26 ^ uVar19 ^ uVar8;
        uVar36 = (uVar15 >> 2) + uVar15 * 0x40000000;
        uVar13 = ((uVar15 | uVar29) & uVar38 | uVar15 & uVar29) +
                 uVar27 + 0x8f1bbcdc + uVar13 + (uVar28 >> 0x1b) + uVar28 * 0x20;
        uVar25 = uVar30 ^ uVar25 ^ uVar24 ^ uVar43;
        uVar38 = ((uVar28 | uVar36) & uVar29 | uVar28 & uVar36) + uVar26 + 0x8f1bbcdc + uVar38 +
                 (uVar13 >> 0x1b) + uVar13 * 0x20;
        uVar35 = (uVar28 >> 2) + uVar28 * 0x40000000;
        uVar15 = uVar27 ^ uVar19 ^ uVar34 ^ uVar42;
        uVar10 = (uVar13 >> 2) + uVar13 * 0x40000000;
        uVar19 = ((uVar13 | uVar35) & uVar36 | uVar13 & uVar35) +
                 uVar25 + 0x8f1bbcdc + uVar29 + (uVar38 >> 0x1b) + uVar38 * 0x20;
        uVar13 = uVar26 ^ uVar24 ^ uVar32 ^ uVar20;
        uVar24 = ((uVar38 | uVar10) & uVar35 | uVar38 & uVar10) + uVar15 + 0x8f1bbcdc + uVar36 +
                 (uVar19 >> 0x1b) + uVar19 * 0x20;
        uVar28 = (uVar38 >> 2) + uVar38 * 0x40000000;
        uVar34 = uVar25 ^ uVar34 ^ uVar41 ^ uVar22;
        uVar38 = (uVar19 >> 2) + uVar19 * 0x40000000;
        uVar19 = ((uVar19 | uVar28) & uVar10 | uVar19 & uVar28) +
                 uVar13 + 0x8f1bbcdc + uVar35 + (uVar24 >> 0x1b) + uVar24 * 0x20;
        uVar29 = uVar15 ^ uVar32 ^ uVar14 ^ uVar31;
        uVar35 = ((uVar24 | uVar38) & uVar28 | uVar24 & uVar38) + uVar34 + 0x8f1bbcdc + uVar10 +
                 (uVar19 >> 0x1b) + uVar19 * 0x20;
        uVar32 = (uVar24 >> 2) + uVar24 * 0x40000000;
        uVar41 = uVar13 ^ uVar41 ^ uVar8 ^ uVar30;
        uVar36 = (uVar19 >> 2) + uVar19 * 0x40000000;
        uVar24 = ((uVar19 | uVar32) & uVar38 | uVar19 & uVar32) +
                 uVar29 + 0x8f1bbcdc + uVar28 + (uVar35 >> 0x1b) + uVar35 * 0x20;
        uVar14 = uVar34 ^ uVar14 ^ uVar43 ^ uVar27;
        uVar28 = (uVar35 >> 2) + uVar35 * 0x40000000;
        uVar35 = ((uVar35 | uVar36) & uVar32 | uVar35 & uVar36) + uVar41 + 0x8f1bbcdc + uVar38 +
                 (uVar24 >> 0x1b) + uVar24 * 0x20;
        uVar19 = uVar29 ^ uVar8 ^ uVar42 ^ uVar26;
        uVar8 = (uVar24 >> 2) + uVar24 * 0x40000000;
        uVar43 = uVar41 ^ uVar43 ^ uVar20 ^ uVar25;
        uVar24 = (uVar36 ^ uVar28 ^ uVar24) + uVar14 + 0xca62c1d6 + uVar32 +
                 (uVar35 >> 0x1b) + uVar35 * 0x20;
        uVar38 = (uVar35 >> 2) + uVar35 * 0x40000000;
        uVar10 = uVar14 ^ uVar42 ^ uVar22 ^ uVar15;
        uVar36 = (uVar28 ^ uVar8 ^ uVar35) + uVar19 + 0xca62c1d6 + uVar36 +
                 (uVar24 >> 0x1b) + uVar24 * 0x20;
        uVar32 = (uVar24 >> 2) + uVar24 * 0x40000000;
        uVar35 = (uVar8 ^ uVar38 ^ uVar24) + uVar43 + 0xca62c1d6 + uVar28 +
                 (uVar36 >> 0x1b) + uVar36 * 0x20;
        puVar21 = (undefined4 *)(uVar19 ^ uVar20 ^ uVar31 ^ uVar13);
        uVar28 = (uVar36 >> 2) + uVar36 * 0x40000000;
        uVar20 = (uVar38 ^ uVar32 ^ uVar36) + uVar10 + 0xca62c1d6 + uVar8 +
                 (uVar35 >> 0x1b) + uVar35 * 0x20;
        uVar24 = uVar43 ^ uVar22 ^ uVar30 ^ uVar34;
        uVar22 = (uVar35 >> 2) + uVar35 * 0x40000000;
        pbVar12 = (byte *)((int)puVar21 +
                          (uVar20 >> 0x1b) + uVar20 * 0x20 +
                          (uVar32 ^ uVar28 ^ uVar35) + uVar38 + 0xca62c1d6);
        uVar8 = uVar10 ^ uVar31 ^ uVar27 ^ uVar29;
        uVar31 = (uVar20 >> 2) + uVar20 * 0x40000000;
        in_t4 = (uint)puVar21 ^ uVar30 ^ uVar26 ^ uVar41;
        uVar36 = ((uint)pbVar12 >> 2) + (int)pbVar12 * 0x40000000;
        uVar20 = (uVar28 ^ uVar22 ^ uVar20) + uVar24 + 0xca62c1d6 + uVar32 +
                 ((uint)pbVar12 >> 0x1b) + (int)pbVar12 * 0x20;
        uVar35 = (uVar22 ^ uVar31 ^ (uint)pbVar12) + uVar8 + 0xca62c1d6 + uVar28 +
                 (uVar20 >> 0x1b) + uVar20 * 0x20;
        uVar27 = uVar24 ^ uVar27 ^ uVar25 ^ uVar14;
        uVar30 = (uVar20 >> 2) + uVar20 * 0x40000000;
        uVar32 = (uVar31 ^ uVar36 ^ uVar20) + in_t4 + 0xca62c1d6 + uVar22 +
                 (uVar35 >> 0x1b) + uVar35 * 0x20;
        uVar22 = uVar8 ^ uVar26 ^ uVar15 ^ uVar19;
        uVar28 = (uVar35 >> 2) + uVar35 * 0x40000000;
        uVar26 = (uVar36 ^ uVar30 ^ uVar35) + uVar27 + 0xca62c1d6 + uVar31 +
                 (uVar32 >> 0x1b) + uVar32 * 0x20;
        uVar20 = in_t4 ^ uVar25 ^ uVar13 ^ uVar43;
        uVar31 = (uVar32 >> 2) + uVar32 * 0x40000000;
        uVar25 = (uVar30 ^ uVar28 ^ uVar32) + uVar22 + 0xca62c1d6 + uVar36 +
                 (uVar26 >> 0x1b) + uVar26 * 0x20;
        uVar15 = uVar27 ^ uVar15 ^ uVar34 ^ uVar10;
        uVar35 = (uVar26 >> 2) + uVar26 * 0x40000000;
        uVar26 = (uVar28 ^ uVar31 ^ uVar26) + uVar20 + 0xca62c1d6 + uVar30 +
                 (uVar25 >> 0x1b) + uVar25 * 0x20;
        uVar13 = uVar22 ^ uVar13 ^ uVar29 ^ (uint)puVar21;
        uVar32 = (uVar25 >> 2) + uVar25 * 0x40000000;
        uVar30 = (uVar31 ^ uVar35 ^ uVar25) + uVar15 + 0xca62c1d6 + uVar28 +
                 (uVar26 >> 0x1b) + uVar26 * 0x20;
        uVar25 = uVar20 ^ uVar34 ^ uVar41 ^ uVar24;
        uVar34 = (uVar26 >> 2) + uVar26 * 0x40000000;
        uVar26 = (uVar35 ^ uVar32 ^ uVar26) + uVar13 + 0xca62c1d6 + uVar31 +
                 (uVar30 >> 0x1b) + uVar30 * 0x20;
        in_t5 = uVar15 ^ uVar29 ^ uVar14 ^ uVar8;
        uVar29 = (uVar30 >> 2) + uVar30 * 0x40000000;
        uVar30 = (uVar32 ^ uVar34 ^ uVar30) + uVar25 + 0xca62c1d6 + uVar35 +
                 (uVar26 >> 0x1b) + uVar26 * 0x20;
        uVar13 = uVar13 ^ uVar41 ^ uVar19 ^ in_t4;
        uVar41 = (uVar26 >> 2) + uVar26 * 0x40000000;
        uVar8 = uVar13 + 0xca62c1d6;
        uVar26 = (uVar34 ^ uVar29 ^ uVar26) + in_t5 + 0xca62c1d6 + uVar32 +
                 (uVar30 >> 0x1b) + uVar30 * 0x20;
        uVar25 = uVar25 ^ uVar14 ^ uVar43 ^ uVar27;
        uVar31 = (uVar30 >> 2) + uVar30 * 0x40000000;
        uVar27 = (uVar29 ^ uVar41 ^ uVar30) + uVar8 + uVar34 + (uVar26 >> 0x1b) + uVar26 * 0x20;
        uVar28 = uVar41 ^ uVar31 ^ uVar26;
        uVar26 = (uVar26 >> 2) + uVar26 * 0x40000000;
        uVar14 = uVar28 + uVar25 + 0xca62c1d6 + uVar29 + (uVar27 >> 0x1b) + uVar27 * 0x20;
        uVar29 = (uVar27 >> 2) + uVar27 * 0x40000000;
        uVar19 = (in_t5 ^ uVar19 ^ uVar10 ^ uVar22) + 0xca62c1d6 + uVar41 +
                 (uVar31 ^ uVar26 ^ uVar27) + (uVar14 >> 0x1b) + uVar14 * 0x20;
        puVar37 = (undefined4 *)((uVar14 >> 2) + uVar14 * 0x40000000);
        puVar33 = (undefined *)((uVar25 ^ uVar10 ^ uVar24 ^ uVar15) + 0xca62c1d6);
        uVar15 = (uVar13 ^ uVar43 ^ (uint)puVar21 ^ uVar20) + 0xca62c1d6 + uVar31 +
                 (uVar26 ^ uVar29 ^ uVar14) + (uVar19 >> 0x1b) + uVar19 * 0x20;
        puVar40 = (undefined *)((uVar19 >> 2) + uVar19 * 0x40000000);
        puStackY_158 = puVar40 + (int)puStackY_158;
        puStackY_160 = puVar33 + (uVar15 >> 0x1b) + uVar15 * 0x20 +
                                 (uVar29 ^ (uint)puVar37 ^ uVar19) + uVar26 + (int)puStackY_160;
        uStackY_15c = uVar15 + uStackY_15c;
        pbStackY_154 = (byte *)((int)puVar37 + (int)pbStackY_154);
        piStack_dc[1] = uStackY_15c;
        *piStack_dc = (int)puStackY_160;
        iStackY_150 = uVar29 + iStackY_150;
        iStackY_118 = iStackY_118 + -1;
        piStack_dc[4] = iStackY_150;
        piStack_dc[2] = (int)puStackY_158;
        piStack_dc[3] = (int)pbStackY_154;
        puVar18 = puStackY_168;
        puVar7 = puVar7 + 0x10;
      } while (iStackY_118 != 0);
      return 0;
    }
  } while( true );
}

