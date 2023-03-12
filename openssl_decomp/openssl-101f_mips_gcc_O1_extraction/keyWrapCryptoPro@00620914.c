
bool keyWrapCryptoPro(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,uint *param_5)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint extraout_v1;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint in_t0;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint in_t3;
  uint uVar19;
  uint in_t4;
  uint uVar20;
  uint in_t5;
  uint uVar21;
  uint uVar22;
  undefined *puVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  undefined *puVar30;
  uint uVar31;
  uint uVar32;
  uint uStackY_110;
  undefined *puStackY_108;
  uint uStackY_104;
  undefined *puStackY_100;
  uint uStackY_fc;
  int iStackY_f8;
  int iStackY_c0;
  undefined auStack_a8 [4];
  undefined auStack_a4 [32];
  int *piStack_84;
  uint *puStack_80;
  uint uStack_7c;
  undefined4 uStack_78;
  uint uStack_74;
  undefined *puStack_70;
  code *pcStack_6c;
  undefined4 local_58;
  uint *local_54;
  undefined *local_50;
  undefined auStack_44 [32];
  uint local_24;
  
  puVar30 = PTR___stack_chk_guard_006aabf0;
  puStack_70 = auStack_44;
  local_50 = &_gp;
  local_24 = *(uint *)PTR___stack_chk_guard_006aabf0;
  keyDiversifyCryptoPro();
  gost_key(param_1,puStack_70);
  uVar4 = param_3 & 3;
  uVar2 = *(uint *)(param_3 + 4);
  uVar13 = param_3 + 3 & 3;
  *param_5 = (*(int *)(param_3 - uVar4) << uVar4 * 8 | extraout_v1 & 0xffffffffU >> (4 - uVar4) * 8)
             & -1 << (uVar13 + 1) * 8 | *(uint *)((param_3 + 3) - uVar13) >> (3 - uVar13) * 8;
  param_5[1] = uVar2;
  puStack_80 = param_5 + 10;
  gost_enc(param_1,param_4,param_5 + 2,4);
  local_58 = 0x20;
  uVar4 = param_3;
  uVar13 = param_4;
  local_54 = puStack_80;
  gost_mac_iv(param_1,0x20);
  if (local_24 == *(uint *)puVar30) {
    return true;
  }
  pcStack_6c = keyUnwrapCryptoPro;
  uVar2 = local_24;
  (**(code **)(local_50 + -0x5328))();
  puVar30 = PTR___stack_chk_guard_006aabf0;
  piStack_84 = *(int **)PTR___stack_chk_guard_006aabf0;
  uStack_7c = param_3;
  uStack_78 = param_1;
  uStack_74 = param_4;
  keyDiversifyCryptoPro();
  puVar23 = auStack_a8;
  gost_key(uVar2,auStack_a4);
  gost_dec(uVar2,uVar4 + 8,uVar13,4);
  uVar12 = uVar13;
  gost_mac_iv(uVar2,0x20,uVar4,uVar13,0x20,puVar23);
  iStackY_c0 = 4;
  puVar10 = (uint *)(uVar4 + 0x28);
  iVar3 = (*(code *)PTR_memcmp_006aabd8)(puVar23);
  if (piStack_84 == *(int **)puVar30) {
    return iVar3 == 0;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStackY_108 = (undefined *)*piStack_84;
  uStackY_104 = piStack_84[1];
  puStackY_100 = (undefined *)piStack_84[2];
  uStackY_fc = piStack_84[3];
  iStackY_f8 = piStack_84[4];
  uStackY_110 = 0xca62c1d6;
  puVar1 = puVar10;
  do {
    if (((uint)puVar10 & 3) == 0) {
      uVar15 = *puVar1;
      uVar16 = puVar1[1];
      uVar8 = (uStackY_104 >> 2) + uStackY_104 * 0x40000000;
      uVar21 = puVar1[2];
      uVar20 = puVar1[3];
      uVar19 = puVar1[4];
      uVar18 = puVar1[5];
      uVar17 = puVar1[6];
      uVar28 = puVar1[7];
      uVar27 = puVar1[8];
      uVar2 = ((uint)puStackY_108 >> 0x1b) + (int)puStackY_108 * 0x20 + iStackY_f8 + 0x5a827999 +
              uVar15 + (((uint)puStackY_100 ^ uStackY_fc) & uStackY_104 ^ uStackY_fc);
      uVar24 = puVar1[9];
      uVar22 = puVar1[10];
      uVar26 = puVar1[0xb];
      uVar25 = puVar1[0xc];
      uVar9 = ((uint)puStackY_108 >> 2) + (int)puStackY_108 * 0x40000000;
      uVar32 = puVar1[0xe];
      uVar4 = puVar1[0xd];
      uVar5 = puVar1[0xf];
      uVar13 = (((uint)puStackY_100 ^ uVar8) & (uint)puStackY_108 ^ (uint)puStackY_100) +
               uStackY_fc + 0x5a827999 + uVar16 + (uVar2 >> 0x1b) + uVar2 * 0x20;
      uVar12 = (uVar2 >> 2) + uVar2 * 0x40000000;
      puVar30 = puStackY_100 +
                (uVar13 >> 0x1b) + uVar13 * 0x20 +
                ((uVar8 ^ uVar9) & uVar2 ^ uVar8) + uVar21 + 0x5a827999;
      uVar2 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar8 = ((uVar9 ^ uVar12) & uVar13 ^ uVar9) + uVar8 + 0x5a827999 + uVar20 +
              ((uint)puVar30 >> 0x1b) + (int)puVar30 * 0x20;
      uVar31 = ((uint)puVar30 >> 2) + (int)puVar30 * 0x40000000;
      uVar14 = (uVar8 >> 2) + uVar8 * 0x40000000;
      uVar13 = ((uVar12 ^ uVar2) & (uint)puVar30 ^ uVar12) + uVar9 + 0x5a827999 + uVar19 +
               (uVar8 >> 0x1b) + uVar8 * 0x20;
      uVar9 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar12 = ((uVar2 ^ uVar31) & uVar8 ^ uVar2) + uVar18 + 0x5a827999 + uVar12 +
               (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar8 = (uVar12 >> 2) + uVar12 * 0x40000000;
      uVar13 = ((uVar31 ^ uVar14) & uVar13 ^ uVar31) + uVar17 + 0x5a827999 + uVar2 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar2 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar12 = ((uVar14 ^ uVar9) & uVar12 ^ uVar14) + uVar28 + 0x5a827999 + uVar31 +
               (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar31 = (uVar12 >> 2) + uVar12 * 0x40000000;
      uVar13 = ((uVar9 ^ uVar8) & uVar13 ^ uVar9) + uVar27 + 0x5a827999 + uVar14 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar14 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar12 = ((uVar8 ^ uVar2) & uVar12 ^ uVar8) + uVar24 + 0x5a827999 + uVar9 +
               (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar13 = ((uVar2 ^ uVar31) & uVar13 ^ uVar2) + uVar22 + 0x5a827999 + uVar8 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar8 = (uVar12 >> 2) + uVar12 * 0x40000000;
      iVar3 = ((uVar31 ^ uVar14) & uVar12 ^ uVar31) + uVar26 + 0x5a827999 + uVar2;
    }
    else {
      uVar29 = ((uint)puStackY_108 >> 2) + (int)puStackY_108 * 0x40000000;
      uVar8 = (uint)puVar1 & 3;
      uVar9 = (uint)(puVar1 + 1) & 3;
      uVar14 = (uint)(puVar1 + 2) & 3;
      uVar17 = (uint)(puVar1 + 3) & 3;
      uVar15 = (int)puVar1 + 3U & 3;
      uVar15 = (*(int *)((int)puVar1 - uVar8) << uVar8 * 8 | uVar12 & 0xffffffffU >> (4 - uVar8) * 8
               ) & -1 << (uVar15 + 1) * 8 |
               *(uint *)(((int)puVar1 + 3U) - uVar15) >> (3 - uVar15) * 8;
      uVar11 = (uStackY_104 >> 2) + uStackY_104 * 0x40000000;
      uVar12 = (int)puVar1 + 7U & 3;
      uVar16 = (*(int *)((int)(puVar1 + 1) - uVar9) << uVar9 * 8 |
               in_t0 & 0xffffffffU >> (4 - uVar9) * 8) & -1 << (uVar12 + 1) * 8 |
               *(uint *)(((int)puVar1 + 7U) - uVar12) >> (3 - uVar12) * 8;
      uVar12 = (int)puVar1 + 0xbU & 3;
      uVar21 = (*(int *)((int)(puVar1 + 2) - uVar14) << uVar14 * 8 |
               in_t5 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar12 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0xbU) - uVar12) >> (3 - uVar12) * 8;
      uVar12 = (uint)(puVar1 + 4) & 3;
      uVar8 = (uint)(puVar1 + 5) & 3;
      uVar5 = (((uint)puStackY_100 ^ uStackY_fc) & uStackY_104 ^ uStackY_fc) +
              ((uint)puStackY_108 >> 0x1b) + (int)puStackY_108 * 0x20 + iStackY_f8 + 0x5a827999 +
              uVar15;
      uVar9 = (int)puVar1 + 0xfU & 3;
      uVar20 = (*(int *)((int)(puVar1 + 3) - uVar17) << uVar17 * 8 |
               in_t4 & 0xffffffffU >> (4 - uVar17) * 8) & -1 << (uVar9 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0xfU) - uVar9) >> (3 - uVar9) * 8;
      uVar9 = (uint)(puVar1 + 6) & 3;
      uVar14 = (uint)(puVar1 + 7) & 3;
      uVar17 = (int)puVar1 + 0x13U & 3;
      uVar19 = (*(int *)((int)(puVar1 + 4) - uVar12) << uVar12 * 8 |
               in_t3 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar17 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x13U) - uVar17) >> (3 - uVar17) * 8;
      uVar12 = (int)puVar1 + 0x17U & 3;
      uVar18 = (*(int *)((int)(puVar1 + 5) - uVar8) << uVar8 * 8 |
               uStackY_104 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar12 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x17U) - uVar12) >> (3 - uVar12) * 8;
      uVar12 = (uint)(puVar1 + 8) & 3;
      uVar8 = (uint)(puVar1 + 9) & 3;
      uVar22 = (uint)(puVar1 + 10) & 3;
      uVar7 = (((uint)puStackY_100 ^ uVar11) & (uint)puStackY_108 ^ (uint)puStackY_100) +
              uStackY_fc + 0x5a827999 + uVar16 + (uVar5 >> 0x1b) + uVar5 * 0x20;
      uVar25 = (uint)(puVar1 + 0xb) & 3;
      uVar31 = (uint)(puVar1 + 0xc) & 3;
      uVar17 = (int)puVar1 + 0x1bU & 3;
      uVar17 = (*(int *)((int)(puVar1 + 6) - uVar9) << uVar9 * 8 |
               uStackY_fc & 0xffffffffU >> (4 - uVar9) * 8) & -1 << (uVar17 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x1bU) - uVar17) >> (3 - uVar17) * 8;
      uVar6 = (uVar5 >> 2) + uVar5 * 0x40000000;
      uVar9 = (int)puVar1 + 0x1fU & 3;
      uVar28 = (*(int *)((int)(puVar1 + 7) - uVar14) << uVar14 * 8 |
               uVar13 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar9 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x1fU) - uVar9) >> (3 - uVar9) * 8;
      uVar13 = (int)puVar1 + 0x23U & 3;
      uVar27 = (*(int *)((int)(puVar1 + 8) - uVar12) << uVar12 * 8 |
               (uint)puVar30 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar13 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x23U) - uVar13) >> (3 - uVar13) * 8;
      uVar13 = (uint)(puVar1 + 0xd) & 3;
      uVar12 = (int)puVar1 + 0x27U & 3;
      uVar24 = (*(int *)((int)(puVar1 + 9) - uVar8) << uVar8 * 8 |
               (uint)puVar23 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar12 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x27U) - uVar12) >> (3 - uVar12) * 8;
      uVar12 = (int)puVar1 + 0x2bU & 3;
      uVar22 = (*(int *)((int)(puVar1 + 10) - uVar22) << uVar22 * 8 |
               (uint)puStackY_100 & 0xffffffffU >> (4 - uVar22) * 8) & -1 << (uVar12 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x2bU) - uVar12) >> (3 - uVar12) * 8;
      uVar12 = (int)puVar1 + 0x2fU & 3;
      uVar26 = (*(int *)((int)(puVar1 + 0xb) - uVar25) << uVar25 * 8 |
               uVar2 & 0xffffffffU >> (4 - uVar25) * 8) & -1 << (uVar12 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x2fU) - uVar12) >> (3 - uVar12) * 8;
      uVar2 = (uint)(puVar1 + 0xe) & 3;
      uVar12 = (uint)(puVar1 + 0xf) & 3;
      uVar8 = (int)puVar1 + 0x33U & 3;
      uVar25 = (*(int *)((int)(puVar1 + 0xc) - uVar31) << uVar31 * 8 |
               uVar4 & 0xffffffffU >> (4 - uVar31) * 8) & -1 << (uVar8 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x33U) - uVar8) >> (3 - uVar8) * 8;
      uVar4 = (int)puVar1 + 0x37U & 3;
      uVar4 = (*(int *)((int)(puVar1 + 0xd) - uVar13) << uVar13 * 8 |
              (uint)(puStackY_100 + uVar21 + 0x5a827999) & 0xffffffffU >> (4 - uVar13) * 8) &
              -1 << (uVar4 + 1) * 8 | *(uint *)(((int)puVar1 + 0x37U) - uVar4) >> (3 - uVar4) * 8;
      puVar30 = puStackY_100 + uVar21 + 0x5a827999 +
                (uVar7 >> 0x1b) + uVar7 * 0x20 + ((uVar11 ^ uVar29) & uVar5 ^ uVar11);
      uVar8 = (uVar7 >> 2) + uVar7 * 0x40000000;
      uVar13 = (int)puVar1 + 0x3bU & 3;
      uVar32 = (*(int *)((int)(puVar1 + 0xe) - uVar2) << uVar2 * 8 |
               (uint)puStackY_108 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar13 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x3bU) - uVar13) >> (3 - uVar13) * 8;
      uVar13 = (int)puVar1 + 0x3fU & 3;
      uVar5 = (*(int *)((int)(puVar1 + 0xf) - uVar12) << uVar12 * 8 |
              0xffffffffU >> (4 - uVar12) * 8 & 0x5a827999) & -1 << (uVar13 + 1) * 8 |
              *(uint *)(((int)puVar1 + 0x3fU) - uVar13) >> (3 - uVar13) * 8;
      uVar13 = ((uVar29 ^ uVar6) & uVar7 ^ uVar29) + uVar11 + 0x5a827999 + uVar20 +
               ((uint)puVar30 >> 0x1b) + (int)puVar30 * 0x20;
      uVar31 = ((uint)puVar30 >> 2) + (int)puVar30 * 0x40000000;
      uVar14 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar12 = ((uVar6 ^ uVar8) & (uint)puVar30 ^ uVar6) + uVar29 + 0x5a827999 + uVar19 +
               (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar7 = (uVar12 >> 2) + uVar12 * 0x40000000;
      uVar13 = ((uVar8 ^ uVar31) & uVar13 ^ uVar8) + uVar18 + 0x5a827999 + uVar6 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar2 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar12 = ((uVar31 ^ uVar14) & uVar12 ^ uVar31) + uVar17 + 0x5a827999 + uVar8 +
               (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar9 = (uVar12 >> 2) + uVar12 * 0x40000000;
      uVar13 = ((uVar14 ^ uVar7) & uVar13 ^ uVar14) + uVar28 + 0x5a827999 + uVar31 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar31 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar8 = ((uVar7 ^ uVar2) & uVar12 ^ uVar7) + uVar27 + 0x5a827999 + uVar14 +
              (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar14 = (uVar8 >> 2) + uVar8 * 0x40000000;
      uVar12 = ((uVar2 ^ uVar9) & uVar13 ^ uVar2) + uVar24 + 0x5a827999 + uVar7 +
               (uVar8 >> 0x1b) + uVar8 * 0x20;
      uVar13 = ((uVar9 ^ uVar31) & uVar8 ^ uVar9) + uVar22 + 0x5a827999 + uVar2 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar8 = (uVar12 >> 2) + uVar12 * 0x40000000;
      iVar3 = ((uVar31 ^ uVar14) & uVar12 ^ uVar31) + uVar26 + 0x5a827999 + uVar9;
    }
    uVar2 = iVar3 + (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar12 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar9 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar13 = ((uVar14 ^ uVar8) & uVar13 ^ uVar14) + uVar25 + 0x5a827999 + uVar31 +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar2 = ((uVar8 ^ uVar12) & uVar2 ^ uVar8) + uVar4 + 0x5a827999 + uVar14 +
            (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar31 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar14 = ((uVar12 ^ uVar9) & uVar13 ^ uVar12) + uVar32 + 0x5a827999 + uVar8 +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar13 = ((uVar9 ^ uVar31) & uVar2 ^ uVar9) + uVar5 + 0x5a827999 + uVar12 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar15 = uVar4 ^ uVar15 ^ uVar21 ^ uVar27;
    uVar12 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar8 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar16 = uVar32 ^ uVar16 ^ uVar20 ^ uVar24;
    uVar14 = (uVar13 >> 0x1b) + uVar13 * 0x20 + uVar9 + 0x5a827999 + uVar15 +
             ((uVar12 ^ uVar31) & uVar14 ^ uVar31);
    uVar2 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar21 = uVar5 ^ uVar21 ^ uVar19 ^ uVar22;
    uVar9 = ((uVar12 ^ uVar8) & uVar13 ^ uVar12) + uVar31 + 0x5a827999 + uVar16 +
            (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar31 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar20 = uVar15 ^ uVar20 ^ uVar18 ^ uVar26;
    uVar13 = ((uVar8 ^ uVar2) & uVar14 ^ uVar8) + uVar12 + 0x5a827999 + uVar21 +
             (uVar9 >> 0x1b) + uVar9 * 0x20;
    uVar14 = (uVar9 >> 2) + uVar9 * 0x40000000;
    uVar19 = uVar16 ^ uVar19 ^ uVar17 ^ uVar25;
    uVar8 = ((uVar2 ^ uVar31) & uVar9 ^ uVar2) + uVar8 + 0x5a827999 + uVar20 +
            (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar18 = uVar21 ^ uVar18 ^ uVar28 ^ uVar4;
    uVar12 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar2 = (uVar31 ^ uVar14 ^ uVar13) + uVar2 + 0x6ed9eba1 + uVar19 +
            (uVar8 >> 0x1b) + uVar8 * 0x20;
    uVar17 = uVar20 ^ uVar17 ^ uVar27 ^ uVar32;
    uVar9 = (uVar8 >> 2) + uVar8 * 0x40000000;
    uVar8 = (uVar14 ^ uVar12 ^ uVar8) + uVar18 + 0x6ed9eba1 + uVar31 +
            (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar13 = uVar19 ^ uVar28 ^ uVar24 ^ uVar5;
    uVar6 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar28 = (uVar12 ^ uVar9 ^ uVar2) + uVar17 + 0x6ed9eba1 + uVar14 +
             (uVar8 >> 0x1b) + uVar8 * 0x20;
    uVar2 = uVar18 ^ uVar27 ^ uVar22 ^ uVar15;
    uVar14 = (uVar8 >> 2) + uVar8 * 0x40000000;
    uVar12 = (uVar9 ^ uVar6 ^ uVar8) + uVar13 + 0x6ed9eba1 + uVar12 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar24 = uVar17 ^ uVar24 ^ uVar26 ^ uVar16;
    uVar27 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar8 = (uVar6 ^ uVar14 ^ uVar28) + uVar2 + 0x6ed9eba1 + uVar9 +
            (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar22 = uVar13 ^ uVar22 ^ uVar25 ^ uVar21;
    uVar31 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar9 = (uVar14 ^ uVar27 ^ uVar12) + uVar24 + 0x6ed9eba1 + uVar6 +
            (uVar8 >> 0x1b) + uVar8 * 0x20;
    uVar12 = uVar2 ^ uVar26 ^ uVar4 ^ uVar20;
    uVar28 = (uVar8 >> 2) + uVar8 * 0x40000000;
    uVar14 = (uVar27 ^ uVar31 ^ uVar8) + uVar22 + 0x6ed9eba1 + uVar14 +
             (uVar9 >> 0x1b) + uVar9 * 0x20;
    uVar8 = uVar24 ^ uVar25 ^ uVar32 ^ uVar19;
    uVar25 = (uVar9 >> 2) + uVar9 * 0x40000000;
    uVar9 = (uVar31 ^ uVar28 ^ uVar9) + uVar12 + 0x6ed9eba1 + uVar27 +
            (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar4 = uVar22 ^ uVar4 ^ uVar5 ^ uVar18;
    uVar27 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar14 = (uVar28 ^ uVar25 ^ uVar14) + uVar8 + 0x6ed9eba1 + uVar31 +
             (uVar9 >> 0x1b) + uVar9 * 0x20;
    uVar6 = uVar12 ^ uVar32 ^ uVar15 ^ uVar17;
    uVar26 = (uVar9 >> 2) + uVar9 * 0x40000000;
    uVar28 = (uVar25 ^ uVar27 ^ uVar9) + uVar4 + 0x6ed9eba1 + uVar28 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar32 = uVar8 ^ uVar5 ^ uVar16 ^ uVar13;
    uVar31 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar25 = (uVar27 ^ uVar26 ^ uVar14) + uVar6 + 0x6ed9eba1 + uVar25 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar9 = uVar4 ^ uVar15 ^ uVar21 ^ uVar2;
    uVar5 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar27 = (uVar26 ^ uVar31 ^ uVar28) + uVar32 + 0x6ed9eba1 + uVar27 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar14 = uVar6 ^ uVar16 ^ uVar20 ^ uVar24;
    uVar15 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar25 = (uVar31 ^ uVar5 ^ uVar25) + uVar9 + 0x6ed9eba1 + uVar26 +
             (uVar27 >> 0x1b) + uVar27 * 0x20;
    uVar21 = uVar32 ^ uVar21 ^ uVar19 ^ uVar22;
    uVar28 = (uVar27 >> 2) + uVar27 * 0x40000000;
    uVar20 = uVar9 ^ uVar20 ^ uVar18 ^ uVar12;
    uVar16 = (uVar5 ^ uVar15 ^ uVar27) + uVar14 + 0x6ed9eba1 + uVar31 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar31 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar19 = uVar14 ^ uVar19 ^ uVar17 ^ uVar8;
    uVar25 = (uVar15 ^ uVar28 ^ uVar25) + uVar21 + 0x6ed9eba1 + uVar5 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar27 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar18 = uVar21 ^ uVar18 ^ uVar13 ^ uVar4;
    uVar16 = (uVar28 ^ uVar31 ^ uVar16) + uVar20 + 0x6ed9eba1 + uVar15 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar26 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar25 = (uVar31 ^ uVar27 ^ uVar25) + uVar19 + 0x6ed9eba1 + uVar28 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar15 = uVar20 ^ uVar17 ^ uVar2 ^ uVar6;
    uVar5 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar13 = uVar19 ^ uVar13 ^ uVar24 ^ uVar32;
    uVar28 = (uVar27 ^ uVar26 ^ uVar16) + uVar18 + 0x6ed9eba1 + uVar31 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar16 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar17 = (uVar26 ^ uVar5 ^ uVar25) + uVar15 + 0x6ed9eba1 + uVar27 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar2 = uVar18 ^ uVar2 ^ uVar22 ^ uVar9;
    uVar25 = (uVar5 ^ uVar16 ^ uVar28) + uVar13 + 0x6ed9eba1 + uVar26 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar28 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar24 = uVar15 ^ uVar24 ^ uVar12 ^ uVar14;
    uVar31 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = ((uVar17 | uVar28) & uVar16 | uVar17 & uVar28) +
             uVar2 + 0x8f1bbcdc + uVar5 + (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar22 = uVar13 ^ uVar22 ^ uVar8 ^ uVar21;
    uVar26 = ((uVar25 | uVar31) & uVar28 | uVar25 & uVar31) + uVar24 + 0x8f1bbcdc + uVar16 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar27 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar12 = uVar2 ^ uVar12 ^ uVar4 ^ uVar20;
    uVar5 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar16 = ((uVar17 | uVar27) & uVar31 | uVar17 & uVar27) +
             uVar22 + 0x8f1bbcdc + uVar28 + (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar8 = uVar24 ^ uVar8 ^ uVar6 ^ uVar19;
    uVar25 = ((uVar26 | uVar5) & uVar27 | uVar26 & uVar5) + uVar12 + 0x8f1bbcdc + uVar31 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar26 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar4 = uVar22 ^ uVar4 ^ uVar32 ^ uVar18;
    uVar31 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar17 = ((uVar16 | uVar26) & uVar5 | uVar16 & uVar26) +
             uVar8 + 0x8f1bbcdc + uVar27 + (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar6 = uVar12 ^ uVar6 ^ uVar9 ^ uVar15;
    uVar16 = ((uVar25 | uVar31) & uVar26 | uVar25 & uVar31) + uVar4 + 0x8f1bbcdc + uVar5 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar27 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar32 = uVar8 ^ uVar32 ^ uVar14 ^ uVar13;
    uVar28 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar26 = ((uVar17 | uVar27) & uVar31 | uVar17 & uVar27) +
             uVar6 + 0x8f1bbcdc + uVar26 + (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar9 = uVar4 ^ uVar9 ^ uVar21 ^ uVar2;
    uVar25 = ((uVar16 | uVar28) & uVar27 | uVar16 & uVar28) + uVar32 + 0x8f1bbcdc + uVar31 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar17 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar16 = uVar6 ^ uVar14 ^ uVar20 ^ uVar24;
    uVar31 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar14 = ((uVar26 | uVar17) & uVar28 | uVar26 & uVar17) +
             uVar9 + 0x8f1bbcdc + uVar27 + (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar21 = uVar32 ^ uVar21 ^ uVar19 ^ uVar22;
    uVar26 = ((uVar25 | uVar31) & uVar17 | uVar25 & uVar31) + uVar16 + 0x8f1bbcdc + uVar28 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar25 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar20 = uVar9 ^ uVar20 ^ uVar18 ^ uVar12;
    uVar5 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar14 = ((uVar14 | uVar25) & uVar31 | uVar14 & uVar25) +
             uVar21 + 0x8f1bbcdc + uVar17 + (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar27 = ((uVar26 | uVar5) & uVar25 | uVar26 & uVar5) + uVar20 + 0x8f1bbcdc + uVar31 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar19 = uVar16 ^ uVar19 ^ uVar15 ^ uVar8;
    uVar26 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar18 = uVar21 ^ uVar18 ^ uVar13 ^ uVar4;
    uVar28 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar14 = ((uVar14 | uVar26) & uVar5 | uVar14 & uVar26) +
             uVar19 + 0x8f1bbcdc + uVar25 + (uVar27 >> 0x1b) + uVar27 * 0x20;
    uVar17 = uVar20 ^ uVar15 ^ uVar2 ^ uVar6;
    uVar31 = ((uVar27 | uVar28) & uVar26 | uVar27 & uVar28) + uVar18 + 0x8f1bbcdc + uVar5 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar25 = (uVar27 >> 2) + uVar27 * 0x40000000;
    uVar13 = uVar19 ^ uVar13 ^ uVar24 ^ uVar32;
    uVar5 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar15 = ((uVar14 | uVar25) & uVar28 | uVar14 & uVar25) +
             uVar17 + 0x8f1bbcdc + uVar26 + (uVar31 >> 0x1b) + uVar31 * 0x20;
    uVar2 = uVar18 ^ uVar2 ^ uVar22 ^ uVar9;
    uVar14 = ((uVar31 | uVar5) & uVar25 | uVar31 & uVar5) + uVar13 + 0x8f1bbcdc + uVar28 +
             (uVar15 >> 0x1b) + uVar15 * 0x20;
    uVar27 = (uVar31 >> 2) + uVar31 * 0x40000000;
    uVar24 = uVar17 ^ uVar24 ^ uVar12 ^ uVar16;
    uVar31 = (uVar15 >> 2) + uVar15 * 0x40000000;
    uVar15 = ((uVar15 | uVar27) & uVar5 | uVar15 & uVar27) +
             uVar2 + 0x8f1bbcdc + uVar25 + (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar22 = uVar13 ^ uVar22 ^ uVar8 ^ uVar21;
    uVar26 = ((uVar14 | uVar31) & uVar27 | uVar14 & uVar31) + uVar24 + 0x8f1bbcdc + uVar5 +
             (uVar15 >> 0x1b) + uVar15 * 0x20;
    uVar25 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar14 = uVar2 ^ uVar12 ^ uVar4 ^ uVar20;
    uVar28 = (uVar15 >> 2) + uVar15 * 0x40000000;
    uVar12 = ((uVar15 | uVar25) & uVar31 | uVar15 & uVar25) +
             uVar22 + 0x8f1bbcdc + uVar27 + (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar15 = uVar24 ^ uVar8 ^ uVar6 ^ uVar19;
    uVar27 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar26 = ((uVar26 | uVar28) & uVar25 | uVar26 & uVar28) + uVar14 + 0x8f1bbcdc + uVar31 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar4 = uVar22 ^ uVar4 ^ uVar32 ^ uVar18;
    uVar8 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar6 = uVar14 ^ uVar6 ^ uVar9 ^ uVar17;
    uVar12 = (uVar28 ^ uVar27 ^ uVar12) + uVar15 + 0xca62c1d6 + uVar25 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar31 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar5 = uVar15 ^ uVar32 ^ uVar16 ^ uVar13;
    uVar28 = (uVar27 ^ uVar8 ^ uVar26) + uVar4 + 0xca62c1d6 + uVar28 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar25 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar26 = (uVar8 ^ uVar31 ^ uVar12) + uVar6 + 0xca62c1d6 + uVar27 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar12 = uVar4 ^ uVar9 ^ uVar21 ^ uVar2;
    uVar27 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar8 = (uVar31 ^ uVar25 ^ uVar28) + uVar5 + 0xca62c1d6 + uVar8 +
            (uVar26 >> 0x1b) + uVar26 * 0x20;
    in_t0 = uVar6 ^ uVar16 ^ uVar20 ^ uVar24;
    uVar16 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar26 = (uVar25 ^ uVar27 ^ uVar26) + uVar12 + 0xca62c1d6 + uVar31 +
             (uVar8 >> 0x1b) + uVar8 * 0x20;
    uVar21 = uVar5 ^ uVar21 ^ uVar19 ^ uVar22;
    uVar9 = (uVar8 >> 2) + uVar8 * 0x40000000;
    in_t4 = uVar12 ^ uVar20 ^ uVar18 ^ uVar14;
    uVar28 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar8 = (uVar27 ^ uVar16 ^ uVar8) + in_t0 + 0xca62c1d6 + uVar25 +
            (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar25 = (uVar16 ^ uVar9 ^ uVar26) + uVar21 + 0xca62c1d6 + uVar27 +
             (uVar8 >> 0x1b) + uVar8 * 0x20;
    uVar19 = in_t0 ^ uVar19 ^ uVar17 ^ uVar15;
    uVar20 = (uVar8 >> 2) + uVar8 * 0x40000000;
    uVar8 = (uVar9 ^ uVar28 ^ uVar8) + in_t4 + 0xca62c1d6 + uVar16 +
            (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar18 = uVar21 ^ uVar18 ^ uVar13 ^ uVar4;
    uVar26 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar9 = (uVar28 ^ uVar20 ^ uVar25) + uVar19 + 0xca62c1d6 + uVar9 +
            (uVar8 >> 0x1b) + uVar8 * 0x20;
    uVar16 = in_t4 ^ uVar17 ^ uVar2 ^ uVar6;
    uVar25 = (uVar8 >> 2) + uVar8 * 0x40000000;
    uVar17 = (uVar20 ^ uVar26 ^ uVar8) + uVar18 + 0xca62c1d6 + uVar28 +
             (uVar9 >> 0x1b) + uVar9 * 0x20;
    uVar8 = uVar19 ^ uVar13 ^ uVar24 ^ uVar5;
    uVar28 = (uVar9 >> 2) + uVar9 * 0x40000000;
    uVar13 = (uVar26 ^ uVar25 ^ uVar9) + uVar16 + 0xca62c1d6 + uVar20 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar9 = uVar18 ^ uVar2 ^ uVar22 ^ uVar12;
    uVar27 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar2 = (uVar25 ^ uVar28 ^ uVar17) + uVar8 + 0xca62c1d6 + uVar26 +
            (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar17 = uVar16 ^ uVar24 ^ uVar14 ^ in_t0;
    uVar24 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar13 = (uVar28 ^ uVar27 ^ uVar13) + uVar9 + 0xca62c1d6 + uVar25 +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    in_t5 = uVar8 ^ uVar22 ^ uVar15 ^ uVar21;
    uVar20 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar21 = (uVar27 ^ uVar24 ^ uVar2) + uVar17 + 0xca62c1d6 + uVar28 +
             (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar9 = uVar9 ^ uVar14 ^ uVar4 ^ in_t4;
    uVar14 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar2 = uVar9 + 0xca62c1d6;
    uVar13 = (uVar24 ^ uVar20 ^ uVar13) + in_t5 + 0xca62c1d6 + uVar27 +
             (uVar21 >> 0x1b) + uVar21 * 0x20;
    uVar17 = uVar17 ^ uVar15 ^ uVar6 ^ uVar19;
    uVar22 = (uVar21 >> 2) + uVar21 * 0x40000000;
    uVar21 = (uVar20 ^ uVar14 ^ uVar21) + uVar2 + uVar24 + (uVar13 >> 0x1b) + uVar13 * 0x20;
    in_t3 = uVar14 ^ uVar22 ^ uVar13;
    uVar19 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar15 = in_t3 + uVar17 + 0xca62c1d6 + uVar20 + (uVar21 >> 0x1b) + uVar21 * 0x20;
    uVar20 = (uVar21 >> 2) + uVar21 * 0x40000000;
    uVar4 = (in_t5 ^ uVar4 ^ uVar5 ^ uVar18) + 0xca62c1d6 + uVar14 + (uVar22 ^ uVar19 ^ uVar21) +
            (uVar15 >> 0x1b) + uVar15 * 0x20;
    uVar13 = (uVar15 >> 2) + uVar15 * 0x40000000;
    puVar23 = (undefined *)((uVar17 ^ uVar5 ^ in_t0 ^ uVar8) + 0xca62c1d6);
    uVar8 = (uVar9 ^ uVar6 ^ uVar12 ^ uVar16) + 0xca62c1d6 + uVar22 + (uVar19 ^ uVar20 ^ uVar15) +
            (uVar4 >> 0x1b) + uVar4 * 0x20;
    puVar30 = (undefined *)((uVar4 >> 2) + uVar4 * 0x40000000);
    puStackY_100 = puVar30 + (int)puStackY_100;
    puStackY_108 = puVar23 + (uVar8 >> 0x1b) + uVar8 * 0x20 + (uVar20 ^ uVar13 ^ uVar4) + uVar19 +
                   (int)puStackY_108;
    uStackY_104 = uVar8 + uStackY_104;
    uStackY_fc = uVar13 + uStackY_fc;
    piStack_84[1] = uStackY_104;
    *piStack_84 = (int)puStackY_108;
    iStackY_f8 = uVar20 + iStackY_f8;
    iStackY_c0 = iStackY_c0 + -1;
    piStack_84[4] = iStackY_f8;
    piStack_84[2] = (int)puStackY_100;
    piStack_84[3] = uStackY_fc;
    uVar4 = uStackY_110;
    puVar1 = puVar1 + 0x10;
  } while (iStackY_c0 != 0);
  return false;
}

