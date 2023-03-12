
void sha1_block_data_order(uint *param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint in_t4;
  uint in_t5;
  uint uVar13;
  uint in_t6;
  uint uVar14;
  uint in_t7;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint in_t8;
  uint uVar26;
  uint in_t9;
  uint uVar27;
  int local_res8;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  local_40 = *param_1;
  iVar19 = param_2 + 0x40;
  local_3c = param_1[1];
  local_38 = param_1[2];
  local_34 = param_1[3];
  local_30 = param_1[4];
  local_res8 = param_3;
  do {
    uVar5 = iVar19 - 0x40;
    if ((param_2 & 3) == 0) {
      uVar1 = *(uint *)(iVar19 + -0x40);
      uVar8 = *(uint *)(&DAT_ffffffc4 + iVar19);
      uVar24 = (local_3c >> 2) + local_3c * 0x40000000;
      uVar26 = *(uint *)(&DAT_ffffffc8 + iVar19);
      uVar15 = *(uint *)(&DAT_ffffffcc + iVar19);
      uVar13 = *(uint *)(iVar19 + -0x30);
      uVar12 = *(uint *)(iVar19 + -0x2c);
      uVar10 = *(uint *)(iVar19 + -0x28);
      uVar7 = *(uint *)(iVar19 + -0x24);
      uVar14 = *(uint *)(iVar19 + -0x20);
      uVar22 = (local_40 >> 0x1b) + local_40 * 0x20 + local_30 + 0x5a827999 + uVar1 +
               ((local_38 ^ local_34) & local_3c ^ local_34);
      uVar16 = *(uint *)(iVar19 + -0x1c);
      uVar11 = *(uint *)(iVar19 + -0x18);
      uVar6 = *(uint *)(iVar19 + -0x10);
      uVar9 = *(uint *)(iVar19 + -0x14);
      uVar17 = (local_40 >> 2) + local_40 * 0x40000000;
      uVar4 = *(uint *)(iVar19 + -0xc);
      uVar27 = *(uint *)(iVar19 + -8);
      uVar5 = *(uint *)(iVar19 + -4);
      uVar18 = ((local_38 ^ uVar24) & local_40 ^ local_38) + local_34 + 0x5a827999 + uVar8 +
               (uVar22 >> 0x1b) + uVar22 * 0x20;
      uVar3 = (uVar22 >> 2) + uVar22 * 0x40000000;
      uVar22 = ((uVar24 ^ uVar17) & uVar22 ^ uVar24) + local_38 + 0x5a827999 + uVar26 +
               (uVar18 >> 0x1b) + uVar18 * 0x20;
      uVar21 = (uVar18 >> 2) + uVar18 * 0x40000000;
      uVar24 = ((uVar17 ^ uVar3) & uVar18 ^ uVar17) + uVar24 + 0x5a827999 + uVar15 +
               (uVar22 >> 0x1b) + uVar22 * 0x20;
      uVar18 = (uVar22 >> 2) + uVar22 * 0x40000000;
      uVar22 = ((uVar3 ^ uVar21) & uVar22 ^ uVar3) + uVar17 + 0x5a827999 + uVar13 +
               (uVar24 >> 0x1b) + uVar24 * 0x20;
      uVar2 = (uVar24 >> 2) + uVar24 * 0x40000000;
      uVar3 = uVar12 + 0x5a827999 + uVar3;
      uVar17 = (uVar21 ^ uVar18) & uVar24 ^ uVar21;
    }
    else {
      uVar25 = (local_40 >> 2) + local_40 * 0x40000000;
      uVar1 = uVar5 & 3;
      uVar4 = (uint)(&DAT_ffffffc4 + iVar19) & 3;
      uVar6 = (uint)(&DAT_ffffffc8 + iVar19) & 3;
      uVar7 = (uint)(&DAT_ffffffcc + iVar19) & 3;
      uVar23 = (local_3c >> 2) + local_3c * 0x40000000;
      uVar8 = iVar19 - 0x3dU & 3;
      uVar1 = (*(int *)(uVar5 - uVar1) << uVar1 * 8 | param_2 & 3 & 0xffffffffU >> (4 - uVar1) * 8)
              & -1 << (uVar8 + 1) * 8 | *(uint *)((iVar19 - 0x3dU) - uVar8) >> (3 - uVar8) * 8;
      uVar8 = iVar19 - 0x39U & 3;
      uVar8 = (*(int *)(&DAT_ffffffc4 + iVar19 + -uVar4) << uVar4 * 8 |
              param_4 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar8 + 1) * 8 |
              *(uint *)((iVar19 - 0x39U) - uVar8) >> (3 - uVar8) * 8;
      uVar4 = iVar19 - 0x30U & 3;
      uVar9 = iVar19 - 0x2cU & 3;
      uVar10 = iVar19 - 0x35U & 3;
      uVar26 = (*(int *)(&DAT_ffffffc8 + iVar19 + -uVar6) << uVar6 * 8 |
               in_t8 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar10 + 1) * 8 |
               *(uint *)((iVar19 - 0x35U) - uVar10) >> (3 - uVar10) * 8;
      uVar16 = ((local_38 ^ local_34) & local_3c ^ local_34) +
               (local_40 >> 0x1b) + local_40 * 0x20 + local_30 + 0x5a827999 + uVar1;
      uVar6 = iVar19 - 0x31U & 3;
      uVar15 = (*(int *)(&DAT_ffffffcc + iVar19 + -uVar7) << uVar7 * 8 |
               in_t7 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar6 + 1) * 8 |
               *(uint *)((iVar19 - 0x31U) - uVar6) >> (3 - uVar6) * 8;
      uVar6 = iVar19 - 0x28U & 3;
      uVar7 = iVar19 - 0x24U & 3;
      uVar10 = iVar19 - 0x2dU & 3;
      uVar13 = (*(int *)((iVar19 - 0x30U) - uVar4) << uVar4 * 8 |
               in_t5 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar10 + 1) * 8 |
               *(uint *)((iVar19 - 0x2dU) - uVar10) >> (3 - uVar10) * 8;
      uVar4 = iVar19 - 0x29U & 3;
      uVar12 = (*(int *)((iVar19 - 0x2cU) - uVar9) << uVar9 * 8 |
               local_3c & 0xffffffffU >> (4 - uVar9) * 8) & -1 << (uVar4 + 1) * 8 |
               *(uint *)((iVar19 - 0x29U) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = iVar19 - 0x20U & 3;
      uVar9 = iVar19 - 0x1cU & 3;
      uVar20 = ((local_38 ^ uVar23) & local_40 ^ local_38) + local_34 + 0x5a827999 + uVar8 +
               (uVar16 >> 0x1b) + uVar16 * 0x20;
      uVar11 = iVar19 - 0x18U & 3;
      uVar22 = iVar19 - 0x10U & 3;
      uVar3 = (uVar23 ^ uVar25) & uVar16;
      uVar18 = iVar19 - 0x14U & 3;
      uVar17 = (uVar16 >> 2) + uVar16 * 0x40000000;
      uVar24 = iVar19 - 8U & 3;
      uVar21 = iVar19 - 0xcU & 3;
      uVar10 = iVar19 - 0x25U & 3;
      uVar10 = (*(int *)((iVar19 - 0x28U) - uVar6) << uVar6 * 8 |
               local_34 & 0xffffffffU >> (4 - uVar6) * 8) & -1 << (uVar10 + 1) * 8 |
               *(uint *)((iVar19 - 0x25U) - uVar10) >> (3 - uVar10) * 8;
      uVar6 = iVar19 - 0x21U & 3;
      uVar7 = (*(int *)((iVar19 - 0x24U) - uVar7) << uVar7 * 8 |
              local_30 + 0x5a827999 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar6 + 1) * 8 |
              *(uint *)((iVar19 - 0x21U) - uVar6) >> (3 - uVar6) * 8;
      uVar2 = local_38 + 0x5a827999 + uVar26;
      uVar6 = iVar19 - 0x1dU & 3;
      uVar14 = (*(int *)((iVar19 - 0x20U) - uVar4) << uVar4 * 8 |
               in_t6 & 0xffffffffU >> (4 - uVar4) * 8) & -1 << (uVar6 + 1) * 8 |
               *(uint *)((iVar19 - 0x1dU) - uVar6) >> (3 - uVar6) * 8;
      uVar4 = iVar19 - 0x19U & 3;
      uVar16 = (*(int *)((iVar19 - 0x1cU) - uVar9) << uVar9 * 8 |
               in_t4 & 0xffffffffU >> (4 - uVar9) * 8) & -1 << (uVar4 + 1) * 8 |
               *(uint *)((iVar19 - 0x19U) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = iVar19 - 0x15U & 3;
      uVar11 = (*(int *)((iVar19 - 0x18U) - uVar11) << uVar11 * 8 |
               local_40 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar4 + 1) * 8 |
               *(uint *)((iVar19 - 0x15U) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = iVar19 - 0x11U & 3;
      uVar9 = (*(int *)((iVar19 - 0x14U) - uVar18) << uVar18 * 8 |
              local_38 & 0xffffffffU >> (4 - uVar18) * 8) & -1 << (uVar4 + 1) * 8 |
              *(uint *)((iVar19 - 0x11U) - uVar4) >> (3 - uVar4) * 8;
      uVar4 = iVar19 - 0xdU & 3;
      uVar6 = (*(int *)((iVar19 - 0x10U) - uVar22) << uVar22 * 8 |
              uVar5 & 0xffffffffU >> (4 - uVar22) * 8) & -1 << (uVar4 + 1) * 8 |
              *(uint *)((iVar19 - 0xdU) - uVar4) >> (3 - uVar4) * 8;
      uVar5 = iVar19 - 4U & 3;
      uVar4 = iVar19 - 9U & 3;
      uVar4 = (*(int *)((iVar19 - 0xcU) - uVar21) << uVar21 * 8 |
              uVar3 & 0xffffffffU >> (4 - uVar21) * 8) & -1 << (uVar4 + 1) * 8 |
              *(uint *)((iVar19 - 9U) - uVar4) >> (3 - uVar4) * 8;
      uVar3 = (uVar3 ^ uVar23) + uVar2 + (uVar20 >> 0x1b) + uVar20 * 0x20;
      uVar21 = (uVar20 >> 2) + uVar20 * 0x40000000;
      uVar22 = iVar19 - 5U & 3;
      uVar27 = (*(int *)((iVar19 - 8U) - uVar24) << uVar24 * 8 |
               in_t9 & 0xffffffffU >> (4 - uVar24) * 8) & -1 << (uVar22 + 1) * 8 |
               *(uint *)((iVar19 - 5U) - uVar22) >> (3 - uVar22) * 8;
      uVar22 = iVar19 - 1U & 3;
      uVar5 = (*(int *)((iVar19 - 4U) - uVar5) << uVar5 * 8 | uVar2 & 0xffffffffU >> (4 - uVar5) * 8
              ) & -1 << (uVar22 + 1) * 8 | *(uint *)((iVar19 - 1U) - uVar22) >> (3 - uVar22) * 8;
      uVar24 = ((uVar25 ^ uVar17) & uVar20 ^ uVar25) + uVar23 + 0x5a827999 + uVar15 +
               (uVar3 >> 0x1b) + uVar3 * 0x20;
      uVar18 = (uVar3 >> 2) + uVar3 * 0x40000000;
      uVar22 = ((uVar17 ^ uVar21) & uVar3 ^ uVar17) + uVar25 + 0x5a827999 + uVar13 +
               (uVar24 >> 0x1b) + uVar24 * 0x20;
      uVar17 = uVar12 + 0x5a827999 + uVar17;
      uVar2 = (uVar24 >> 2) + uVar24 * 0x40000000;
      uVar3 = (uVar21 ^ uVar18) & uVar24 ^ uVar21;
    }
    uVar17 = uVar3 + uVar17 + (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar3 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar21 = ((uVar18 ^ uVar2) & uVar22 ^ uVar18) + uVar10 + 0x5a827999 + uVar21 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar22 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = ((uVar2 ^ uVar3) & uVar17 ^ uVar2) + uVar7 + 0x5a827999 + uVar18 +
             (uVar21 >> 0x1b) + uVar21 * 0x20;
    uVar24 = (uVar21 >> 2) + uVar21 * 0x40000000;
    uVar21 = ((uVar3 ^ uVar22) & uVar21 ^ uVar3) + uVar14 + 0x5a827999 + uVar2 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar18 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = ((uVar22 ^ uVar24) & uVar17 ^ uVar22) + uVar16 + 0x5a827999 + uVar3 +
             (uVar21 >> 0x1b) + uVar21 * 0x20;
    uVar3 = (uVar21 >> 2) + uVar21 * 0x40000000;
    uVar2 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar22 = ((uVar24 ^ uVar18) & uVar21 ^ uVar24) + uVar11 + 0x5a827999 + uVar22 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar20 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar17 = ((uVar18 ^ uVar3) & uVar17 ^ uVar18) + uVar9 + 0x5a827999 + uVar24 +
             (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar21 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar22 = ((uVar3 ^ uVar2) & uVar22 ^ uVar3) + uVar6 + 0x5a827999 + uVar18 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar17 = ((uVar2 ^ uVar20) & uVar17 ^ uVar2) + uVar4 + 0x5a827999 + uVar3 +
             (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar3 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar18 = ((uVar20 ^ uVar21) & uVar22 ^ uVar20) + uVar27 + 0x5a827999 + uVar2 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar2 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar22 = ((uVar21 ^ uVar3) & uVar17 ^ uVar21) + uVar5 + 0x5a827999 + uVar20 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar24 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar1 = uVar1 ^ uVar26 ^ uVar14 ^ uVar4;
    uVar8 = uVar8 ^ uVar15 ^ uVar16 ^ uVar27;
    uVar1 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar17 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar20 = ((uVar2 ^ uVar3) & uVar18 ^ uVar3) +
             (uVar22 >> 0x1b) + uVar22 * 0x20 + uVar21 + 0x5a827999 + uVar1;
    uVar21 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar8 = uVar26 ^ uVar13 ^ uVar11 ^ uVar5;
    uVar23 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar22 = ((uVar2 ^ uVar24) & uVar22 ^ uVar2) + uVar3 + 0x5a827999 + uVar17 +
             (uVar20 >> 0x1b) + uVar20 * 0x20;
    uVar26 = (uVar20 >> 2) + uVar20 * 0x40000000;
    uVar8 = uVar15 ^ uVar12 ^ uVar9 ^ uVar1;
    uVar18 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar2 = ((uVar24 ^ uVar21) & uVar20 ^ uVar24) + uVar2 + 0x5a827999 + uVar23 +
            (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar8 = uVar13 ^ uVar10 ^ uVar6 ^ uVar17;
    uVar15 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar3 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar8 = uVar12 ^ uVar7 ^ uVar4 ^ uVar23;
    uVar13 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar22 = ((uVar21 ^ uVar26) & uVar22 ^ uVar21) + uVar24 + 0x5a827999 + uVar18 +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar20 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar8 = uVar10 ^ uVar14 ^ uVar27 ^ uVar18;
    uVar12 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar10 = (uVar26 ^ uVar3 ^ uVar2) + uVar21 + 0x6ed9eba1 + uVar15 +
             (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar24 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar7 = uVar7 ^ uVar16 ^ uVar5 ^ uVar15;
    uVar8 = uVar7 * 2 - ((int)uVar7 >> 0x1f);
    uVar26 = (uVar3 ^ uVar20 ^ uVar22) + uVar26 + uVar13 + 0x6ed9eba1 +
             (uVar10 >> 0x1b) + uVar10 * 0x20;
    uVar21 = (uVar10 >> 2) + uVar10 * 0x40000000;
    uVar10 = (uVar20 ^ uVar24 ^ uVar10) + uVar3 + uVar12 + 0x6ed9eba1 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar7 = uVar14 ^ uVar11 ^ uVar1 ^ uVar13;
    uVar22 = uVar7 * 2 - ((int)uVar7 >> 0x1f);
    uVar2 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar3 = (uVar24 ^ uVar21 ^ uVar26) + uVar8 + 0x6ed9eba1 + uVar20 +
            (uVar10 >> 0x1b) + uVar10 * 0x20;
    uVar7 = uVar16 ^ uVar9 ^ uVar17 ^ uVar12;
    uVar14 = uVar7 * 2 - ((int)uVar7 >> 0x1f);
    uVar26 = (uVar10 >> 2) + uVar10 * 0x40000000;
    uVar7 = uVar11 ^ uVar6 ^ uVar23 ^ uVar8;
    uVar16 = uVar7 * 2 - ((int)uVar7 >> 0x1f);
    uVar24 = (uVar21 ^ uVar2 ^ uVar10) + uVar22 + 0x6ed9eba1 + uVar24 +
             (uVar3 >> 0x1b) + uVar3 * 0x20;
    uVar20 = (uVar3 >> 2) + uVar3 * 0x40000000;
    uVar11 = (uVar2 ^ uVar26 ^ uVar3) + uVar14 + 0x6ed9eba1 + uVar21 +
             (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar7 = uVar9 ^ uVar4 ^ uVar18 ^ uVar22;
    uVar10 = uVar7 * 2 - ((int)uVar7 >> 0x1f);
    uVar3 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar6 = uVar6 ^ uVar27 ^ uVar15 ^ uVar14;
    uVar7 = uVar6 * 2 - ((int)uVar6 >> 0x1f);
    uVar21 = (uVar26 ^ uVar20 ^ uVar24) + uVar16 + 0x6ed9eba1 + uVar2 +
             (uVar11 >> 0x1b) + uVar11 * 0x20;
    uVar9 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar11 = (uVar20 ^ uVar3 ^ uVar11) + uVar10 + 0x6ed9eba1 + uVar26 +
             (uVar21 >> 0x1b) + uVar21 * 0x20;
    uVar4 = uVar4 ^ uVar5 ^ uVar13 ^ uVar16;
    uVar6 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar24 = (uVar21 >> 2) + uVar21 * 0x40000000;
    uVar26 = (uVar3 ^ uVar9 ^ uVar21) + uVar7 + 0x6ed9eba1 + uVar20 +
             (uVar11 >> 0x1b) + uVar11 * 0x20;
    uVar4 = uVar27 ^ uVar1 ^ uVar12 ^ uVar10;
    uVar25 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar21 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar5 = uVar5 ^ uVar17 ^ uVar8 ^ uVar7;
    uVar4 = uVar5 * 2 - ((int)uVar5 >> 0x1f);
    uVar2 = (uVar9 ^ uVar24 ^ uVar11) + uVar6 + 0x6ed9eba1 + uVar3 +
            (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar27 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar5 = uVar1 ^ uVar23 ^ uVar22 ^ uVar6;
    uVar5 = uVar5 * 2 - ((int)uVar5 >> 0x1f);
    uVar11 = (uVar24 ^ uVar21 ^ uVar26) + uVar25 + 0x6ed9eba1 + uVar9 +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar3 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar1 = uVar17 ^ uVar18 ^ uVar14 ^ uVar25;
    uVar9 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar1 = (uVar21 ^ uVar27 ^ uVar2) + uVar4 + 0x6ed9eba1 + uVar24 +
            (uVar11 >> 0x1b) + uVar11 * 0x20;
    uVar17 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar21 = (uVar27 ^ uVar3 ^ uVar11) + uVar5 + 0x6ed9eba1 + uVar21 +
             (uVar1 >> 0x1b) + uVar1 * 0x20;
    uVar11 = uVar23 ^ uVar15 ^ uVar16 ^ uVar4;
    uVar20 = uVar11 * 2 - ((int)uVar11 >> 0x1f);
    uVar11 = (uVar1 >> 2) + uVar1 * 0x40000000;
    uVar2 = (uVar3 ^ uVar17 ^ uVar1) + uVar9 + 0x6ed9eba1 + uVar27 +
            (uVar21 >> 0x1b) + uVar21 * 0x20;
    uVar1 = uVar18 ^ uVar13 ^ uVar10 ^ uVar5;
    uVar18 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar26 = (uVar21 >> 2) + uVar21 * 0x40000000;
    uVar1 = uVar15 ^ uVar12 ^ uVar7 ^ uVar9;
    uVar15 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar24 = (uVar17 ^ uVar11 ^ uVar21) + uVar20 + 0x6ed9eba1 + uVar3 +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar3 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar1 = uVar13 ^ uVar8 ^ uVar6 ^ uVar20;
    uVar13 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar21 = (uVar11 ^ uVar26 ^ uVar2) + uVar18 + 0x6ed9eba1 + uVar17 +
             (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar2 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar17 = (uVar26 ^ uVar3 ^ uVar24) + uVar15 + 0x6ed9eba1 + uVar11 +
             (uVar21 >> 0x1b) + uVar21 * 0x20;
    uVar1 = uVar12 ^ uVar22 ^ uVar25 ^ uVar18;
    uVar11 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar12 = (uVar21 >> 2) + uVar21 * 0x40000000;
    uVar1 = uVar8 ^ uVar14 ^ uVar4 ^ uVar15;
    uVar8 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar24 = (uVar3 ^ uVar2 ^ uVar21) + uVar13 + 0x6ed9eba1 + uVar26 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar21 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar26 = (uVar2 ^ uVar12 ^ uVar17) + uVar11 + 0x6ed9eba1 + uVar3 +
             (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar2 = (uVar12 ^ uVar21 ^ uVar24) + uVar8 + 0x6ed9eba1 + uVar2 +
            (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar1 = uVar22 ^ uVar16 ^ uVar5 ^ uVar13;
    uVar17 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar3 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar1 = uVar14 ^ uVar10 ^ uVar9 ^ uVar11;
    uVar14 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar24 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar22 = ((uVar26 | uVar3) & uVar21 | uVar26 & uVar3) +
             uVar17 + 0x8f1bbcdc + uVar12 + (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar1 = uVar16 ^ uVar7 ^ uVar20 ^ uVar8;
    uVar12 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar16 = ((uVar2 | uVar24) & uVar3 | uVar2 & uVar24) + uVar14 + 0x8f1bbcdc + uVar21 +
             (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar2 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar1 = uVar10 ^ uVar6 ^ uVar18 ^ uVar17;
    uVar10 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar26 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar27 = ((uVar22 | uVar2) & uVar24 | uVar22 & uVar2) +
             uVar12 + 0x8f1bbcdc + uVar3 + (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar1 = uVar7 ^ uVar25 ^ uVar15 ^ uVar14;
    uVar7 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar22 = ((uVar16 | uVar26) & uVar2 | uVar16 & uVar26) + uVar10 + 0x8f1bbcdc + uVar24 +
             (uVar27 >> 0x1b) + uVar27 * 0x20;
    uVar21 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar1 = uVar6 ^ uVar4 ^ uVar13 ^ uVar12;
    uVar6 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar3 = (uVar27 >> 2) + uVar27 * 0x40000000;
    uVar16 = ((uVar27 | uVar21) & uVar26 | uVar27 & uVar21) +
             uVar7 + 0x8f1bbcdc + uVar2 + (uVar22 >> 0x1b) + uVar22 * 0x20;
    uVar1 = uVar25 ^ uVar5 ^ uVar11 ^ uVar10;
    uVar23 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar26 = ((uVar22 | uVar3) & uVar21 | uVar22 & uVar3) + uVar6 + 0x8f1bbcdc + uVar26 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar22 = (uVar22 >> 2) + uVar22 * 0x40000000;
    uVar1 = uVar4 ^ uVar9 ^ uVar8 ^ uVar7;
    uVar1 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar24 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar16 = ((uVar16 | uVar22) & uVar3 | uVar16 & uVar22) +
             uVar23 + 0x8f1bbcdc + uVar21 + (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar2 = ((uVar26 | uVar24) & uVar22 | uVar26 & uVar24) + uVar1 + 0x8f1bbcdc + uVar3 +
            (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar5 = uVar5 ^ uVar20 ^ uVar17 ^ uVar6;
    uVar5 = uVar5 * 2 - ((int)uVar5 >> 0x1f);
    uVar3 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar4 = uVar9 ^ uVar18 ^ uVar14 ^ uVar23;
    uVar9 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar21 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar27 = ((uVar16 | uVar3) & uVar24 | uVar16 & uVar3) +
             uVar5 + 0x8f1bbcdc + uVar22 + (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar4 = uVar20 ^ uVar15 ^ uVar12 ^ uVar1;
    uVar20 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar16 = ((uVar2 | uVar21) & uVar3 | uVar2 & uVar21) + uVar9 + 0x8f1bbcdc + uVar24 +
             (uVar27 >> 0x1b) + uVar27 * 0x20;
    uVar2 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar4 = uVar18 ^ uVar13 ^ uVar10 ^ uVar5;
    uVar22 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar26 = (uVar27 >> 2) + uVar27 * 0x40000000;
    uVar18 = ((uVar27 | uVar2) & uVar21 | uVar27 & uVar2) +
             uVar20 + 0x8f1bbcdc + uVar3 + (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar21 = ((uVar16 | uVar26) & uVar2 | uVar16 & uVar26) + uVar22 + 0x8f1bbcdc + uVar21 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar4 = uVar15 ^ uVar11 ^ uVar7 ^ uVar9;
    uVar15 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar24 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar4 = uVar13 ^ uVar8 ^ uVar6 ^ uVar20;
    uVar16 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar3 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar13 = ((uVar18 | uVar24) & uVar26 | uVar18 & uVar24) +
             uVar15 + 0x8f1bbcdc + uVar2 + (uVar21 >> 0x1b) + uVar21 * 0x20;
    uVar18 = ((uVar21 | uVar3) & uVar24 | uVar21 & uVar3) + uVar16 + 0x8f1bbcdc + uVar26 +
             (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar4 = uVar11 ^ uVar17 ^ uVar23 ^ uVar22;
    uVar11 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar21 = (uVar21 >> 2) + uVar21 * 0x40000000;
    uVar4 = uVar8 ^ uVar14 ^ uVar1 ^ uVar15;
    uVar8 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar26 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar24 = ((uVar13 | uVar21) & uVar3 | uVar13 & uVar21) +
             uVar11 + 0x8f1bbcdc + uVar24 + (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar2 = ((uVar18 | uVar26) & uVar21 | uVar18 & uVar26) + uVar8 + 0x8f1bbcdc + uVar3 +
            (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar4 = uVar17 ^ uVar12 ^ uVar5 ^ uVar16;
    uVar17 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar3 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar4 = uVar14 ^ uVar10 ^ uVar9 ^ uVar11;
    uVar13 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar18 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar21 = ((uVar24 | uVar3) & uVar26 | uVar24 & uVar3) +
             uVar17 + 0x8f1bbcdc + uVar21 + (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar26 = ((uVar2 | uVar18) & uVar3 | uVar2 & uVar18) + uVar13 + 0x8f1bbcdc + uVar26 +
             (uVar21 >> 0x1b) + uVar21 * 0x20;
    uVar4 = uVar12 ^ uVar7 ^ uVar20 ^ uVar8;
    uVar12 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar24 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar4 = uVar10 ^ uVar6 ^ uVar22 ^ uVar17;
    uVar10 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar14 = (uVar21 >> 2) + uVar21 * 0x40000000;
    uVar21 = ((uVar21 | uVar24) & uVar18 | uVar21 & uVar24) +
             uVar12 + 0x8f1bbcdc + uVar3 + (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar3 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar4 = uVar7 ^ uVar23 ^ uVar15 ^ uVar13;
    uVar7 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar18 = ((uVar26 | uVar14) & uVar24 | uVar26 & uVar14) + uVar10 + 0x8f1bbcdc + uVar18 +
             (uVar21 >> 0x1b) + uVar21 * 0x20;
    uVar4 = uVar6 ^ uVar1 ^ uVar16 ^ uVar12;
    uVar4 = uVar4 * 2 - ((int)uVar4 >> 0x1f);
    uVar2 = (uVar21 >> 2) + uVar21 * 0x40000000;
    uVar6 = uVar23 ^ uVar5 ^ uVar11 ^ uVar10;
    uVar27 = uVar6 * 2 - ((int)uVar6 >> 0x1f);
    uVar6 = (uVar14 ^ uVar3 ^ uVar21) + uVar7 + 0xca62c1d6 + uVar24 +
            (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar21 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar1 = uVar1 ^ uVar9 ^ uVar8 ^ uVar7;
    uVar1 = uVar1 * 2 - ((int)uVar1 >> 0x1f);
    uVar14 = (uVar3 ^ uVar2 ^ uVar18) + uVar4 + 0xca62c1d6 + uVar14 + (uVar6 >> 0x1b) + uVar6 * 0x20
    ;
    uVar24 = (uVar6 >> 2) + uVar6 * 0x40000000;
    uVar18 = (uVar2 ^ uVar21 ^ uVar6) + uVar27 + 0xca62c1d6 + uVar3 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar5 = uVar5 ^ uVar20 ^ uVar17 ^ uVar4;
    uVar5 = uVar5 * 2 - ((int)uVar5 >> 0x1f);
    uVar2 = (uVar21 ^ uVar24 ^ uVar14) + uVar1 + 0xca62c1d6 + uVar2 +
            (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar6 = uVar9 ^ uVar22 ^ uVar13 ^ uVar27;
    param_4 = uVar6 * 2 - ((int)uVar6 >> 0x1f);
    uVar9 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar6 = uVar20 ^ uVar15 ^ uVar12 ^ uVar1;
    uVar26 = uVar6 * 2 - ((int)uVar6 >> 0x1f);
    uVar20 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar18 = (uVar24 ^ uVar9 ^ uVar18) + uVar5 + 0xca62c1d6 + uVar21 +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    uVar6 = uVar22 ^ uVar16 ^ uVar10 ^ uVar5;
    uVar3 = (uVar2 >> 2) + uVar2 * 0x40000000;
    uVar22 = uVar6 * 2 - ((int)uVar6 >> 0x1f);
    uVar24 = (uVar9 ^ uVar20 ^ uVar2) + param_4 + 0xca62c1d6 + uVar24 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar21 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar6 = uVar15 ^ uVar11 ^ uVar7 ^ param_4;
    uVar14 = uVar6 * 2 - ((int)uVar6 >> 0x1f);
    uVar2 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar15 = (uVar20 ^ uVar3 ^ uVar18) + uVar26 + 0xca62c1d6 + uVar9 +
             (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar6 = uVar16 ^ uVar8 ^ uVar4 ^ uVar26;
    uVar24 = (uVar3 ^ uVar21 ^ uVar24) + uVar22 + 0xca62c1d6 + uVar20 +
             (uVar15 >> 0x1b) + uVar15 * 0x20;
    uVar16 = uVar6 * 2 - ((int)uVar6 >> 0x1f);
    uVar18 = (uVar15 >> 2) + uVar15 * 0x40000000;
    uVar6 = uVar11 ^ uVar17 ^ uVar27 ^ uVar22;
    uVar9 = uVar6 * 2 - ((int)uVar6 >> 0x1f);
    uVar15 = (uVar21 ^ uVar2 ^ uVar15) + uVar14 + 0xca62c1d6 + uVar3 +
             (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar3 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar6 = uVar8 ^ uVar13 ^ uVar1 ^ uVar14;
    uVar11 = (uVar2 ^ uVar18 ^ uVar24) + uVar16 + 0xca62c1d6 + uVar21 +
             (uVar15 >> 0x1b) + uVar15 * 0x20;
    uVar6 = uVar6 * 2 - ((int)uVar6 >> 0x1f);
    uVar24 = (uVar15 >> 2) + uVar15 * 0x40000000;
    uVar21 = (uVar18 ^ uVar3 ^ uVar15) + uVar9 + 0xca62c1d6 + uVar2 +
             (uVar11 >> 0x1b) + uVar11 * 0x20;
    uVar8 = uVar17 ^ uVar12 ^ uVar5 ^ uVar16;
    in_t6 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar15 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar8 = uVar13 ^ uVar10 ^ param_4 ^ uVar9;
    in_t4 = 0xca62c1d6;
    uVar11 = (uVar3 ^ uVar24 ^ uVar11) + uVar6 + 0xca62c1d6 + uVar18 +
             (uVar21 >> 0x1b) + uVar21 * 0x20;
    uVar8 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar13 = (uVar21 >> 2) + uVar21 * 0x40000000;
    uVar12 = uVar12 ^ uVar7 ^ uVar26 ^ uVar6;
    uVar18 = (uVar24 ^ uVar15 ^ uVar21) + in_t6 + 0xca62c1d6 + uVar3 +
             (uVar11 >> 0x1b) + uVar11 * 0x20;
    in_t8 = uVar12 * 2 - ((int)uVar12 >> 0x1f);
    uVar12 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar10 = uVar10 ^ uVar4 ^ uVar22 ^ in_t6;
    uVar17 = (uVar15 ^ uVar13 ^ uVar11) + uVar8 + 0xca62c1d6 + uVar24 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar10 = uVar10 * 2 - ((int)uVar10 >> 0x1f);
    uVar22 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar8 = uVar7 ^ uVar27 ^ uVar14 ^ uVar8;
    uVar11 = (uVar13 ^ uVar12 ^ uVar18) + in_t8 + 0xca62c1d6 + uVar15 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar7 = uVar8 * 2 - ((int)uVar8 >> 0x1f);
    uVar14 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar4 = uVar4 ^ uVar1 ^ uVar16 ^ in_t8;
    uVar16 = (uVar12 ^ uVar22 ^ uVar17) + uVar10 + 0xca62c1d6 + uVar13 +
             (uVar11 >> 0x1b) + uVar11 * 0x20;
    in_t9 = uVar27 ^ uVar5;
    uVar8 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar10 = in_t9 ^ uVar9 ^ uVar10;
    uVar5 = (uVar22 ^ uVar14 ^ uVar11) + uVar7 + 0xca62c1d6 + uVar12 +
            (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar9 = (uVar16 >> 2) + uVar16 * 0x40000000;
    in_t7 = (uVar10 * 2 - ((int)uVar10 >> 0x1f)) + 0xca62c1d6;
    uVar7 = uVar1 ^ param_4 ^ uVar6 ^ uVar7;
    uVar4 = (uVar5 >> 0x1b) + uVar5 * 0x20 +
            (uVar4 * 2 - ((int)uVar4 >> 0x1f)) + -0x359d3e2a + uVar22 + (uVar14 ^ uVar8 ^ uVar16);
    uVar1 = (uVar5 >> 2) + uVar5 * 0x40000000;
    in_t5 = (uVar7 * 2 - ((int)uVar7 >> 0x1f)) + 0xca62c1d6;
    uVar5 = (uVar4 >> 0x1b) + uVar4 * 0x20 + in_t7 + uVar14 + (uVar8 ^ uVar9 ^ uVar5);
    local_38 = (uVar4 >> 2) + uVar4 * 0x40000000 + local_38;
    local_40 = in_t5 + uVar8 + (uVar9 ^ uVar1 ^ uVar4) + (uVar5 >> 0x1b) + uVar5 * 0x20 + local_40;
    local_3c = uVar5 + local_3c;
    local_34 = uVar1 + local_34;
    param_1[1] = local_3c;
    local_30 = uVar9 + local_30;
    *param_1 = local_40;
    param_1[4] = local_30;
    param_1[2] = local_38;
    local_res8 = local_res8 + -1;
    param_1[3] = local_34;
    iVar19 = iVar19 + 0x40;
  } while (local_res8 != 0);
  return;
}

