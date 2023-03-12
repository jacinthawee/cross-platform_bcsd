
bool keyUnwrapCryptoPro(uint param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
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
  uint uStackY_a8;
  undefined *puStackY_a0;
  uint uStackY_9c;
  undefined *puStackY_98;
  uint uStackY_94;
  int iStackY_90;
  int iStackY_58;
  undefined auStack_40 [4];
  undefined auStack_3c [32];
  int *local_1c;
  
  puVar30 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int **)PTR___stack_chk_guard_006a9ae8;
  keyDiversifyCryptoPro();
  puVar23 = auStack_40;
  gost_key(param_1,auStack_3c);
  gost_dec(param_1,param_3 + 8,param_4,4);
  uVar3 = param_4;
  gost_mac_iv(param_1,0x20,param_3,param_4,0x20,puVar23);
  iStackY_58 = 4;
  puVar10 = (uint *)(param_3 + 0x28);
  iVar2 = (*(code *)PTR_memcmp_006a9ad0)(puVar23);
  if (local_1c == *(int **)puVar30) {
    return iVar2 == 0;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStackY_a0 = (undefined *)*local_1c;
  uStackY_9c = local_1c[1];
  puStackY_98 = (undefined *)local_1c[2];
  uStackY_94 = local_1c[3];
  iStackY_90 = local_1c[4];
  uStackY_a8 = 0xca62c1d6;
  puVar1 = puVar10;
  do {
    if (((uint)puVar10 & 3) == 0) {
      uVar15 = *puVar1;
      uVar16 = puVar1[1];
      uVar8 = (uStackY_9c >> 2) + uStackY_9c * 0x40000000;
      uVar21 = puVar1[2];
      uVar20 = puVar1[3];
      uVar19 = puVar1[4];
      uVar18 = puVar1[5];
      uVar17 = puVar1[6];
      uVar28 = puVar1[7];
      uVar27 = puVar1[8];
      uVar6 = ((uint)puStackY_a0 >> 0x1b) + (int)puStackY_a0 * 0x20 + iStackY_90 + 0x5a827999 +
              uVar15 + (((uint)puStackY_98 ^ uStackY_94) & uStackY_9c ^ uStackY_94);
      uVar24 = puVar1[9];
      uVar22 = puVar1[10];
      uVar26 = puVar1[0xb];
      uVar25 = puVar1[0xc];
      uVar9 = ((uint)puStackY_a0 >> 2) + (int)puStackY_a0 * 0x40000000;
      uVar32 = puVar1[0xe];
      uVar3 = puVar1[0xd];
      uVar31 = puVar1[0xf];
      uVar13 = (((uint)puStackY_98 ^ uVar8) & (uint)puStackY_a0 ^ (uint)puStackY_98) +
               uStackY_94 + 0x5a827999 + uVar16 + (uVar6 >> 0x1b) + uVar6 * 0x20;
      uVar12 = (uVar6 >> 2) + uVar6 * 0x40000000;
      puVar30 = puStackY_98 +
                (uVar13 >> 0x1b) + uVar13 * 0x20 +
                ((uVar8 ^ uVar9) & uVar6 ^ uVar8) + uVar21 + 0x5a827999;
      uVar6 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar8 = ((uVar9 ^ uVar12) & uVar13 ^ uVar9) + uVar8 + 0x5a827999 + uVar20 +
              ((uint)puVar30 >> 0x1b) + (int)puVar30 * 0x20;
      uVar4 = ((uint)puVar30 >> 2) + (int)puVar30 * 0x40000000;
      uVar14 = (uVar8 >> 2) + uVar8 * 0x40000000;
      uVar13 = ((uVar12 ^ uVar6) & (uint)puVar30 ^ uVar12) + uVar9 + 0x5a827999 + uVar19 +
               (uVar8 >> 0x1b) + uVar8 * 0x20;
      uVar9 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar12 = ((uVar6 ^ uVar4) & uVar8 ^ uVar6) + uVar18 + 0x5a827999 + uVar12 +
               (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar8 = (uVar12 >> 2) + uVar12 * 0x40000000;
      uVar13 = ((uVar4 ^ uVar14) & uVar13 ^ uVar4) + uVar17 + 0x5a827999 + uVar6 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar6 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar12 = ((uVar14 ^ uVar9) & uVar12 ^ uVar14) + uVar28 + 0x5a827999 + uVar4 +
               (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar4 = (uVar12 >> 2) + uVar12 * 0x40000000;
      uVar13 = ((uVar9 ^ uVar8) & uVar13 ^ uVar9) + uVar27 + 0x5a827999 + uVar14 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar14 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar12 = ((uVar8 ^ uVar6) & uVar12 ^ uVar8) + uVar24 + 0x5a827999 + uVar9 +
               (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar13 = ((uVar6 ^ uVar4) & uVar13 ^ uVar6) + uVar22 + 0x5a827999 + uVar8 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar8 = (uVar12 >> 2) + uVar12 * 0x40000000;
      iVar2 = ((uVar4 ^ uVar14) & uVar12 ^ uVar4) + uVar26 + 0x5a827999 + uVar6;
    }
    else {
      uVar29 = ((uint)puStackY_a0 >> 2) + (int)puStackY_a0 * 0x40000000;
      uVar13 = (uint)puVar1 & 3;
      uVar6 = (uint)(puVar1 + 1) & 3;
      uVar12 = (uint)(puVar1 + 2) & 3;
      uVar8 = (uint)(puVar1 + 3) & 3;
      uVar9 = (int)puVar1 + 3U & 3;
      uVar15 = (*(int *)((int)puVar1 - uVar13) << uVar13 * 8 |
               uVar3 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar9 + 1) * 8 |
               *(uint *)(((int)puVar1 + 3U) - uVar9) >> (3 - uVar9) * 8;
      uVar11 = (uStackY_9c >> 2) + uStackY_9c * 0x40000000;
      uVar3 = (int)puVar1 + 7U & 3;
      uVar16 = (*(int *)((int)(puVar1 + 1) - uVar6) << uVar6 * 8 |
               in_t0 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar3 + 1) * 8 |
               *(uint *)(((int)puVar1 + 7U) - uVar3) >> (3 - uVar3) * 8;
      uVar3 = (int)puVar1 + 0xbU & 3;
      uVar21 = (*(int *)((int)(puVar1 + 2) - uVar12) << uVar12 * 8 |
               in_t5 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar3 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0xbU) - uVar3) >> (3 - uVar3) * 8;
      uVar3 = (uint)(puVar1 + 4) & 3;
      uVar13 = (uint)(puVar1 + 5) & 3;
      uVar4 = (((uint)puStackY_98 ^ uStackY_94) & uStackY_9c ^ uStackY_94) +
              ((uint)puStackY_a0 >> 0x1b) + (int)puStackY_a0 * 0x20 + iStackY_90 + 0x5a827999 +
              uVar15;
      uVar6 = (int)puVar1 + 0xfU & 3;
      uVar20 = (*(int *)((int)(puVar1 + 3) - uVar8) << uVar8 * 8 |
               in_t4 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar6 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0xfU) - uVar6) >> (3 - uVar6) * 8;
      uVar6 = (uint)(puVar1 + 6) & 3;
      uVar12 = (uint)(puVar1 + 7) & 3;
      uVar8 = (int)puVar1 + 0x13U & 3;
      uVar19 = (*(int *)((int)(puVar1 + 4) - uVar3) << uVar3 * 8 |
               in_t3 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar8 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x13U) - uVar8) >> (3 - uVar8) * 8;
      uVar3 = (int)puVar1 + 0x17U & 3;
      uVar18 = (*(int *)((int)(puVar1 + 5) - uVar13) << uVar13 * 8 |
               uStackY_9c & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar3 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x17U) - uVar3) >> (3 - uVar3) * 8;
      uVar3 = (uint)(puVar1 + 8) & 3;
      uVar13 = (uint)(puVar1 + 9) & 3;
      uVar8 = (uint)(puVar1 + 10) & 3;
      uVar7 = (((uint)puStackY_98 ^ uVar11) & (uint)puStackY_a0 ^ (uint)puStackY_98) +
              uStackY_94 + 0x5a827999 + uVar16 + (uVar4 >> 0x1b) + uVar4 * 0x20;
      uVar9 = (uint)(puVar1 + 0xb) & 3;
      uVar14 = (uint)(puVar1 + 0xc) & 3;
      uVar17 = (int)puVar1 + 0x1bU & 3;
      uVar17 = (*(int *)((int)(puVar1 + 6) - uVar6) << uVar6 * 8 |
               uStackY_94 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar17 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x1bU) - uVar17) >> (3 - uVar17) * 8;
      uVar5 = (uVar4 >> 2) + uVar4 * 0x40000000;
      uVar6 = (int)puVar1 + 0x1fU & 3;
      uVar28 = (*(int *)((int)(puVar1 + 7) - uVar12) << uVar12 * 8 |
               param_4 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar6 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x1fU) - uVar6) >> (3 - uVar6) * 8;
      uVar6 = (int)puVar1 + 0x23U & 3;
      uVar27 = (*(int *)((int)(puVar1 + 8) - uVar3) << uVar3 * 8 |
               (uint)puVar30 & 0xffffffffU >> (4 - uVar3) * 8) & -1 << (uVar6 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x23U) - uVar6) >> (3 - uVar6) * 8;
      uVar3 = (uint)(puVar1 + 0xd) & 3;
      uVar6 = (int)puVar1 + 0x27U & 3;
      uVar24 = (*(int *)((int)(puVar1 + 9) - uVar13) << uVar13 * 8 |
               (uint)puVar23 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar6 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x27U) - uVar6) >> (3 - uVar6) * 8;
      uVar13 = (int)puVar1 + 0x2bU & 3;
      uVar22 = (*(int *)((int)(puVar1 + 10) - uVar8) << uVar8 * 8 |
               (uint)puStackY_98 & 0xffffffffU >> (4 - uVar8) * 8) & -1 << (uVar13 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x2bU) - uVar13) >> (3 - uVar13) * 8;
      uVar13 = (int)puVar1 + 0x2fU & 3;
      uVar26 = (*(int *)((int)(puVar1 + 0xb) - uVar9) << uVar9 * 8 |
               param_1 & 0xffffffffU >> (4 - uVar9) * 8) & -1 << (uVar13 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x2fU) - uVar13) >> (3 - uVar13) * 8;
      uVar13 = (uint)(puVar1 + 0xe) & 3;
      uVar6 = (uint)(puVar1 + 0xf) & 3;
      uVar12 = (int)puVar1 + 0x33U & 3;
      uVar25 = (*(int *)((int)(puVar1 + 0xc) - uVar14) << uVar14 * 8 |
               param_3 & 0xffffffffU >> (4 - uVar14) * 8) & -1 << (uVar12 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x33U) - uVar12) >> (3 - uVar12) * 8;
      uVar12 = (int)puVar1 + 0x37U & 3;
      uVar3 = (*(int *)((int)(puVar1 + 0xd) - uVar3) << uVar3 * 8 |
              (uint)(puStackY_98 + uVar21 + 0x5a827999) & 0xffffffffU >> (4 - uVar3) * 8) &
              -1 << (uVar12 + 1) * 8 | *(uint *)(((int)puVar1 + 0x37U) - uVar12) >> (3 - uVar12) * 8
      ;
      puVar30 = puStackY_98 + uVar21 + 0x5a827999 +
                (uVar7 >> 0x1b) + uVar7 * 0x20 + ((uVar11 ^ uVar29) & uVar4 ^ uVar11);
      uVar8 = (uVar7 >> 2) + uVar7 * 0x40000000;
      uVar12 = (int)puVar1 + 0x3bU & 3;
      uVar32 = (*(int *)((int)(puVar1 + 0xe) - uVar13) << uVar13 * 8 |
               (uint)puStackY_a0 & 0xffffffffU >> (4 - uVar13) * 8) & -1 << (uVar12 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x3bU) - uVar12) >> (3 - uVar12) * 8;
      uVar13 = (int)puVar1 + 0x3fU & 3;
      uVar31 = (*(int *)((int)(puVar1 + 0xf) - uVar6) << uVar6 * 8 |
               0xffffffffU >> (4 - uVar6) * 8 & 0x5a827999) & -1 << (uVar13 + 1) * 8 |
               *(uint *)(((int)puVar1 + 0x3fU) - uVar13) >> (3 - uVar13) * 8;
      uVar13 = ((uVar29 ^ uVar5) & uVar7 ^ uVar29) + uVar11 + 0x5a827999 + uVar20 +
               ((uint)puVar30 >> 0x1b) + (int)puVar30 * 0x20;
      uVar4 = ((uint)puVar30 >> 2) + (int)puVar30 * 0x40000000;
      uVar14 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar12 = ((uVar5 ^ uVar8) & (uint)puVar30 ^ uVar5) + uVar29 + 0x5a827999 + uVar19 +
               (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar7 = (uVar12 >> 2) + uVar12 * 0x40000000;
      uVar13 = ((uVar8 ^ uVar4) & uVar13 ^ uVar8) + uVar18 + 0x5a827999 + uVar5 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar6 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar12 = ((uVar4 ^ uVar14) & uVar12 ^ uVar4) + uVar17 + 0x5a827999 + uVar8 +
               (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar9 = (uVar12 >> 2) + uVar12 * 0x40000000;
      uVar13 = ((uVar14 ^ uVar7) & uVar13 ^ uVar14) + uVar28 + 0x5a827999 + uVar4 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar4 = (uVar13 >> 2) + uVar13 * 0x40000000;
      uVar8 = ((uVar7 ^ uVar6) & uVar12 ^ uVar7) + uVar27 + 0x5a827999 + uVar14 +
              (uVar13 >> 0x1b) + uVar13 * 0x20;
      uVar14 = (uVar8 >> 2) + uVar8 * 0x40000000;
      uVar12 = ((uVar6 ^ uVar9) & uVar13 ^ uVar6) + uVar24 + 0x5a827999 + uVar7 +
               (uVar8 >> 0x1b) + uVar8 * 0x20;
      uVar13 = ((uVar9 ^ uVar4) & uVar8 ^ uVar9) + uVar22 + 0x5a827999 + uVar6 +
               (uVar12 >> 0x1b) + uVar12 * 0x20;
      uVar8 = (uVar12 >> 2) + uVar12 * 0x40000000;
      iVar2 = ((uVar4 ^ uVar14) & uVar12 ^ uVar4) + uVar26 + 0x5a827999 + uVar9;
    }
    uVar6 = iVar2 + (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar12 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar9 = (uVar6 >> 2) + uVar6 * 0x40000000;
    uVar13 = ((uVar14 ^ uVar8) & uVar13 ^ uVar14) + uVar25 + 0x5a827999 + uVar4 +
             (uVar6 >> 0x1b) + uVar6 * 0x20;
    uVar6 = ((uVar8 ^ uVar12) & uVar6 ^ uVar8) + uVar3 + 0x5a827999 + uVar14 +
            (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar4 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar14 = ((uVar12 ^ uVar9) & uVar13 ^ uVar12) + uVar32 + 0x5a827999 + uVar8 +
             (uVar6 >> 0x1b) + uVar6 * 0x20;
    uVar13 = ((uVar9 ^ uVar4) & uVar6 ^ uVar9) + uVar31 + 0x5a827999 + uVar12 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar15 = uVar3 ^ uVar15 ^ uVar21 ^ uVar27;
    uVar12 = (uVar6 >> 2) + uVar6 * 0x40000000;
    uVar8 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar16 = uVar32 ^ uVar16 ^ uVar20 ^ uVar24;
    uVar14 = (uVar13 >> 0x1b) + uVar13 * 0x20 + uVar9 + 0x5a827999 + uVar15 +
             ((uVar12 ^ uVar4) & uVar14 ^ uVar4);
    uVar6 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar21 = uVar31 ^ uVar21 ^ uVar19 ^ uVar22;
    uVar9 = ((uVar12 ^ uVar8) & uVar13 ^ uVar12) + uVar4 + 0x5a827999 + uVar16 +
            (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar4 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar20 = uVar15 ^ uVar20 ^ uVar18 ^ uVar26;
    uVar13 = ((uVar8 ^ uVar6) & uVar14 ^ uVar8) + uVar12 + 0x5a827999 + uVar21 +
             (uVar9 >> 0x1b) + uVar9 * 0x20;
    uVar14 = (uVar9 >> 2) + uVar9 * 0x40000000;
    uVar19 = uVar16 ^ uVar19 ^ uVar17 ^ uVar25;
    uVar8 = ((uVar6 ^ uVar4) & uVar9 ^ uVar6) + uVar8 + 0x5a827999 + uVar20 +
            (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar18 = uVar21 ^ uVar18 ^ uVar28 ^ uVar3;
    uVar12 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar6 = (uVar4 ^ uVar14 ^ uVar13) + uVar6 + 0x6ed9eba1 + uVar19 + (uVar8 >> 0x1b) + uVar8 * 0x20
    ;
    uVar17 = uVar20 ^ uVar17 ^ uVar27 ^ uVar32;
    uVar9 = (uVar8 >> 2) + uVar8 * 0x40000000;
    uVar8 = (uVar14 ^ uVar12 ^ uVar8) + uVar18 + 0x6ed9eba1 + uVar4 + (uVar6 >> 0x1b) + uVar6 * 0x20
    ;
    uVar13 = uVar19 ^ uVar28 ^ uVar24 ^ uVar31;
    uVar5 = (uVar6 >> 2) + uVar6 * 0x40000000;
    uVar28 = (uVar12 ^ uVar9 ^ uVar6) + uVar17 + 0x6ed9eba1 + uVar14 +
             (uVar8 >> 0x1b) + uVar8 * 0x20;
    uVar6 = uVar18 ^ uVar27 ^ uVar22 ^ uVar15;
    uVar14 = (uVar8 >> 2) + uVar8 * 0x40000000;
    uVar8 = (uVar9 ^ uVar5 ^ uVar8) + uVar13 + 0x6ed9eba1 + uVar12 +
            (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar24 = uVar17 ^ uVar24 ^ uVar26 ^ uVar16;
    uVar4 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar12 = (uVar5 ^ uVar14 ^ uVar28) + uVar6 + 0x6ed9eba1 + uVar9 + (uVar8 >> 0x1b) + uVar8 * 0x20
    ;
    uVar22 = uVar13 ^ uVar22 ^ uVar25 ^ uVar21;
    uVar28 = (uVar8 >> 2) + uVar8 * 0x40000000;
    uVar5 = (uVar14 ^ uVar4 ^ uVar8) + uVar24 + 0x6ed9eba1 + uVar5 +
            (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar8 = uVar6 ^ uVar26 ^ uVar3 ^ uVar20;
    uVar27 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar14 = (uVar4 ^ uVar28 ^ uVar12) + uVar22 + 0x6ed9eba1 + uVar14 +
             (uVar5 >> 0x1b) + uVar5 * 0x20;
    uVar9 = uVar24 ^ uVar25 ^ uVar32 ^ uVar19;
    uVar7 = (uVar5 >> 2) + uVar5 * 0x40000000;
    uVar12 = (uVar28 ^ uVar27 ^ uVar5) + uVar8 + 0x6ed9eba1 + uVar4 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar3 = uVar22 ^ uVar3 ^ uVar31 ^ uVar18;
    uVar26 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar14 = (uVar27 ^ uVar7 ^ uVar14) + uVar9 + 0x6ed9eba1 + uVar28 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar5 = uVar8 ^ uVar32 ^ uVar15 ^ uVar17;
    uVar25 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar27 = (uVar7 ^ uVar26 ^ uVar12) + uVar3 + 0x6ed9eba1 + uVar27 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar32 = uVar9 ^ uVar31 ^ uVar16 ^ uVar13;
    uVar28 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar12 = (uVar26 ^ uVar25 ^ uVar14) + uVar5 + 0x6ed9eba1 + uVar7 +
             (uVar27 >> 0x1b) + uVar27 * 0x20;
    uVar14 = uVar3 ^ uVar15 ^ uVar21 ^ uVar6;
    uVar4 = (uVar27 >> 2) + uVar27 * 0x40000000;
    uVar26 = (uVar25 ^ uVar28 ^ uVar27) + uVar32 + 0x6ed9eba1 + uVar26 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar15 = uVar5 ^ uVar16 ^ uVar20 ^ uVar24;
    uVar16 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar25 = (uVar28 ^ uVar4 ^ uVar12) + uVar14 + 0x6ed9eba1 + uVar25 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar21 = uVar32 ^ uVar21 ^ uVar19 ^ uVar22;
    uVar27 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar20 = uVar14 ^ uVar20 ^ uVar18 ^ uVar8;
    uVar12 = (uVar4 ^ uVar16 ^ uVar26) + uVar15 + 0x6ed9eba1 + uVar28 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar31 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar19 = uVar15 ^ uVar19 ^ uVar17 ^ uVar9;
    uVar25 = (uVar16 ^ uVar27 ^ uVar25) + uVar21 + 0x6ed9eba1 + uVar4 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar28 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar18 = uVar21 ^ uVar18 ^ uVar13 ^ uVar3;
    uVar12 = (uVar27 ^ uVar31 ^ uVar12) + uVar20 + 0x6ed9eba1 + uVar16 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar26 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar25 = (uVar31 ^ uVar28 ^ uVar25) + uVar19 + 0x6ed9eba1 + uVar27 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar16 = uVar20 ^ uVar17 ^ uVar6 ^ uVar5;
    uVar4 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar13 = uVar19 ^ uVar13 ^ uVar24 ^ uVar32;
    uVar27 = (uVar28 ^ uVar26 ^ uVar12) + uVar18 + 0x6ed9eba1 + uVar31 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar17 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar25 = (uVar26 ^ uVar4 ^ uVar25) + uVar16 + 0x6ed9eba1 + uVar28 +
             (uVar27 >> 0x1b) + uVar27 * 0x20;
    uVar12 = uVar18 ^ uVar6 ^ uVar22 ^ uVar14;
    uVar26 = (uVar4 ^ uVar17 ^ uVar27) + uVar13 + 0x6ed9eba1 + uVar26 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar27 = (uVar27 >> 2) + uVar27 * 0x40000000;
    uVar24 = uVar16 ^ uVar24 ^ uVar8 ^ uVar15;
    uVar31 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar6 = ((uVar25 | uVar27) & uVar17 | uVar25 & uVar27) +
            uVar12 + 0x8f1bbcdc + uVar4 + (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar22 = uVar13 ^ uVar22 ^ uVar9 ^ uVar21;
    uVar17 = ((uVar26 | uVar31) & uVar27 | uVar26 & uVar31) + uVar24 + 0x8f1bbcdc + uVar17 +
             (uVar6 >> 0x1b) + uVar6 * 0x20;
    uVar26 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar8 = uVar12 ^ uVar8 ^ uVar3 ^ uVar20;
    uVar28 = (uVar6 >> 2) + uVar6 * 0x40000000;
    uVar6 = ((uVar6 | uVar26) & uVar31 | uVar6 & uVar26) +
            uVar22 + 0x8f1bbcdc + uVar27 + (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar9 = uVar24 ^ uVar9 ^ uVar5 ^ uVar19;
    uVar25 = ((uVar17 | uVar28) & uVar26 | uVar17 & uVar28) + uVar8 + 0x8f1bbcdc + uVar31 +
             (uVar6 >> 0x1b) + uVar6 * 0x20;
    uVar27 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar3 = uVar22 ^ uVar3 ^ uVar32 ^ uVar18;
    uVar4 = (uVar6 >> 2) + uVar6 * 0x40000000;
    uVar17 = ((uVar6 | uVar27) & uVar28 | uVar6 & uVar27) +
             uVar9 + 0x8f1bbcdc + uVar26 + (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar5 = uVar8 ^ uVar5 ^ uVar14 ^ uVar16;
    uVar6 = ((uVar25 | uVar4) & uVar27 | uVar25 & uVar4) + uVar3 + 0x8f1bbcdc + uVar28 +
            (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar26 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar32 = uVar9 ^ uVar32 ^ uVar15 ^ uVar13;
    uVar28 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar25 = ((uVar17 | uVar26) & uVar4 | uVar17 & uVar26) +
             uVar5 + 0x8f1bbcdc + uVar27 + (uVar6 >> 0x1b) + uVar6 * 0x20;
    uVar14 = uVar3 ^ uVar14 ^ uVar21 ^ uVar12;
    uVar17 = ((uVar6 | uVar28) & uVar26 | uVar6 & uVar28) + uVar32 + 0x8f1bbcdc + uVar4 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar6 = (uVar6 >> 2) + uVar6 * 0x40000000;
    uVar15 = uVar5 ^ uVar15 ^ uVar20 ^ uVar24;
    uVar4 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar27 = ((uVar25 | uVar6) & uVar28 | uVar25 & uVar6) +
             uVar14 + 0x8f1bbcdc + uVar26 + (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar21 = uVar32 ^ uVar21 ^ uVar19 ^ uVar22;
    uVar26 = ((uVar17 | uVar4) & uVar6 | uVar17 & uVar4) + uVar15 + 0x8f1bbcdc + uVar28 +
             (uVar27 >> 0x1b) + uVar27 * 0x20;
    uVar25 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar20 = uVar14 ^ uVar20 ^ uVar18 ^ uVar8;
    uVar31 = (uVar27 >> 2) + uVar27 * 0x40000000;
    uVar6 = ((uVar27 | uVar25) & uVar4 | uVar27 & uVar25) +
            uVar21 + 0x8f1bbcdc + uVar6 + (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar27 = ((uVar26 | uVar31) & uVar25 | uVar26 & uVar31) + uVar20 + 0x8f1bbcdc + uVar4 +
             (uVar6 >> 0x1b) + uVar6 * 0x20;
    uVar19 = uVar15 ^ uVar19 ^ uVar16 ^ uVar9;
    uVar26 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar17 = uVar21 ^ uVar18 ^ uVar13 ^ uVar3;
    uVar28 = (uVar6 >> 2) + uVar6 * 0x40000000;
    uVar18 = ((uVar6 | uVar26) & uVar31 | uVar6 & uVar26) +
             uVar19 + 0x8f1bbcdc + uVar25 + (uVar27 >> 0x1b) + uVar27 * 0x20;
    uVar16 = uVar20 ^ uVar16 ^ uVar12 ^ uVar5;
    uVar4 = ((uVar27 | uVar28) & uVar26 | uVar27 & uVar28) + uVar17 + 0x8f1bbcdc + uVar31 +
            (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar25 = (uVar27 >> 2) + uVar27 * 0x40000000;
    uVar6 = uVar19 ^ uVar13 ^ uVar24 ^ uVar32;
    uVar31 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar13 = ((uVar18 | uVar25) & uVar28 | uVar18 & uVar25) +
             uVar16 + 0x8f1bbcdc + uVar26 + (uVar4 >> 0x1b) + uVar4 * 0x20;
    uVar12 = uVar17 ^ uVar12 ^ uVar22 ^ uVar14;
    uVar18 = ((uVar4 | uVar31) & uVar25 | uVar4 & uVar31) + uVar6 + 0x8f1bbcdc + uVar28 +
             (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar27 = (uVar4 >> 2) + uVar4 * 0x40000000;
    uVar24 = uVar16 ^ uVar24 ^ uVar8 ^ uVar15;
    uVar4 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar13 = ((uVar13 | uVar27) & uVar31 | uVar13 & uVar27) +
             uVar12 + 0x8f1bbcdc + uVar25 + (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar22 = uVar6 ^ uVar22 ^ uVar9 ^ uVar21;
    uVar25 = ((uVar18 | uVar4) & uVar27 | uVar18 & uVar4) + uVar24 + 0x8f1bbcdc + uVar31 +
             (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar26 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar8 = uVar12 ^ uVar8 ^ uVar3 ^ uVar20;
    uVar28 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar18 = ((uVar13 | uVar26) & uVar4 | uVar13 & uVar26) +
             uVar22 + 0x8f1bbcdc + uVar27 + (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar9 = uVar24 ^ uVar9 ^ uVar5 ^ uVar19;
    uVar27 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar4 = ((uVar25 | uVar28) & uVar26 | uVar25 & uVar28) + uVar8 + 0x8f1bbcdc + uVar4 +
            (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar13 = uVar22 ^ uVar3 ^ uVar32 ^ uVar17;
    uVar25 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar5 = uVar8 ^ uVar5 ^ uVar14 ^ uVar16;
    uVar3 = (uVar28 ^ uVar27 ^ uVar18) + uVar9 + 0xca62c1d6 + uVar26 +
            (uVar4 >> 0x1b) + uVar4 * 0x20;
    uVar31 = (uVar4 >> 2) + uVar4 * 0x40000000;
    uVar32 = uVar9 ^ uVar32 ^ uVar15 ^ uVar6;
    uVar28 = (uVar27 ^ uVar25 ^ uVar4) + uVar13 + 0xca62c1d6 + uVar28 +
             (uVar3 >> 0x1b) + uVar3 * 0x20;
    uVar18 = (uVar3 >> 2) + uVar3 * 0x40000000;
    uVar26 = (uVar25 ^ uVar31 ^ uVar3) + uVar5 + 0xca62c1d6 + uVar27 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar3 = uVar13 ^ uVar14 ^ uVar21 ^ uVar12;
    uVar27 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar14 = (uVar31 ^ uVar18 ^ uVar28) + uVar32 + 0xca62c1d6 + uVar25 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    in_t0 = uVar5 ^ uVar15 ^ uVar20 ^ uVar24;
    uVar15 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar26 = (uVar18 ^ uVar27 ^ uVar26) + uVar3 + 0xca62c1d6 + uVar31 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar21 = uVar32 ^ uVar21 ^ uVar19 ^ uVar22;
    uVar25 = (uVar14 >> 2) + uVar14 * 0x40000000;
    in_t4 = uVar3 ^ uVar20 ^ uVar17 ^ uVar8;
    uVar28 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar14 = (uVar27 ^ uVar15 ^ uVar14) + in_t0 + 0xca62c1d6 + uVar18 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar26 = (uVar15 ^ uVar25 ^ uVar26) + uVar21 + 0xca62c1d6 + uVar27 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar18 = in_t0 ^ uVar19 ^ uVar16 ^ uVar9;
    uVar19 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar20 = (uVar25 ^ uVar28 ^ uVar14) + in_t4 + 0xca62c1d6 + uVar15 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar15 = uVar21 ^ uVar17 ^ uVar6 ^ uVar13;
    uVar27 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar17 = (uVar28 ^ uVar19 ^ uVar26) + uVar18 + 0xca62c1d6 + uVar25 +
             (uVar20 >> 0x1b) + uVar20 * 0x20;
    uVar14 = in_t4 ^ uVar16 ^ uVar12 ^ uVar5;
    uVar25 = (uVar20 >> 2) + uVar20 * 0x40000000;
    uVar16 = (uVar19 ^ uVar27 ^ uVar20) + uVar15 + 0xca62c1d6 + uVar28 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar6 = uVar18 ^ uVar6 ^ uVar24 ^ uVar32;
    uVar28 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = (uVar27 ^ uVar25 ^ uVar17) + uVar14 + 0xca62c1d6 + uVar19 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar12 = uVar15 ^ uVar12 ^ uVar22 ^ uVar3;
    uVar26 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar19 = (uVar25 ^ uVar28 ^ uVar16) + uVar6 + 0xca62c1d6 + uVar27 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar16 = uVar14 ^ uVar24 ^ uVar8 ^ in_t0;
    uVar24 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = (uVar28 ^ uVar26 ^ uVar17) + uVar12 + 0xca62c1d6 + uVar25 +
             (uVar19 >> 0x1b) + uVar19 * 0x20;
    in_t5 = uVar6 ^ uVar22 ^ uVar9 ^ uVar21;
    uVar20 = (uVar19 >> 2) + uVar19 * 0x40000000;
    uVar19 = (uVar26 ^ uVar24 ^ uVar19) + uVar16 + 0xca62c1d6 + uVar28 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar12 = uVar12 ^ uVar8 ^ uVar13 ^ in_t4;
    uVar8 = (uVar17 >> 2) + uVar17 * 0x40000000;
    param_1 = uVar12 + 0xca62c1d6;
    uVar17 = (uVar24 ^ uVar20 ^ uVar17) + in_t5 + 0xca62c1d6 + uVar26 +
             (uVar19 >> 0x1b) + uVar19 * 0x20;
    uVar16 = uVar16 ^ uVar9 ^ uVar5 ^ uVar18;
    uVar21 = (uVar19 >> 2) + uVar19 * 0x40000000;
    uVar18 = (uVar20 ^ uVar8 ^ uVar19) + param_1 + uVar24 + (uVar17 >> 0x1b) + uVar17 * 0x20;
    in_t3 = uVar8 ^ uVar21 ^ uVar17;
    uVar17 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar9 = in_t3 + uVar16 + 0xca62c1d6 + uVar20 + (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar19 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar13 = (in_t5 ^ uVar13 ^ uVar32 ^ uVar15) + 0xca62c1d6 + uVar8 + (uVar21 ^ uVar17 ^ uVar18) +
             (uVar9 >> 0x1b) + uVar9 * 0x20;
    param_4 = (uVar9 >> 2) + uVar9 * 0x40000000;
    puVar23 = (undefined *)((uVar16 ^ uVar32 ^ in_t0 ^ uVar6) + 0xca62c1d6);
    uVar6 = (uVar12 ^ uVar5 ^ uVar3 ^ uVar14) + 0xca62c1d6 + uVar21 + (uVar17 ^ uVar19 ^ uVar9) +
            (uVar13 >> 0x1b) + uVar13 * 0x20;
    puVar30 = (undefined *)((uVar13 >> 2) + uVar13 * 0x40000000);
    puStackY_98 = puVar30 + (int)puStackY_98;
    puStackY_a0 = puVar23 + (uVar6 >> 0x1b) + uVar6 * 0x20 + (uVar19 ^ param_4 ^ uVar13) + uVar17 +
                  (int)puStackY_a0;
    uStackY_9c = uVar6 + uStackY_9c;
    uStackY_94 = param_4 + uStackY_94;
    local_1c[1] = uStackY_9c;
    *local_1c = (int)puStackY_a0;
    iStackY_90 = uVar19 + iStackY_90;
    iStackY_58 = iStackY_58 + -1;
    local_1c[4] = iStackY_90;
    local_1c[2] = (int)puStackY_98;
    local_1c[3] = uStackY_94;
    param_3 = uStackY_a8;
    puVar1 = puVar1 + 0x10;
  } while (iStackY_58 != 0);
  return false;
}

