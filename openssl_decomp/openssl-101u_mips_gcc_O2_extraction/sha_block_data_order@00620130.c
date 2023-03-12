
void sha_block_data_order(uint *param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint in_t0;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint in_t3;
  uint uVar17;
  uint in_t4;
  uint uVar18;
  uint in_t5;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint unaff_s0;
  uint uVar22;
  uint unaff_s1;
  uint uVar23;
  uint unaff_s2;
  uint uVar24;
  uint unaff_s3;
  uint uVar25;
  uint unaff_s4;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  int local_res8;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  local_40 = *param_1;
  iVar21 = param_2 + 0x40;
  local_3c = param_1[1];
  local_38 = param_1[2];
  local_34 = param_1[3];
  local_30 = param_1[4];
  local_res8 = param_3;
  do {
    if ((param_2 & 3) == 0) {
      uVar13 = *(uint *)(iVar21 + -0x40);
      uVar14 = *(uint *)(&DAT_ffffffc4 + iVar21);
      uVar7 = (local_3c >> 2) + local_3c * 0x40000000;
      uVar19 = *(uint *)(&DAT_ffffffc8 + iVar21);
      uVar18 = *(uint *)(&DAT_ffffffcc + iVar21);
      uVar17 = *(uint *)(iVar21 + -0x30);
      uVar16 = *(uint *)(iVar21 + -0x2c);
      uVar15 = *(uint *)(iVar21 + -0x28);
      uVar26 = *(uint *)(iVar21 + -0x24);
      uVar25 = *(uint *)(iVar21 + -0x20);
      uVar5 = (local_40 >> 0x1b) + local_40 * 0x20 + local_30 + 0x5a827999 + uVar13 +
              ((local_38 ^ local_34) & local_3c ^ local_34);
      uVar22 = *(uint *)(iVar21 + -0x1c);
      uVar20 = *(uint *)(iVar21 + -0x18);
      uVar24 = *(uint *)(iVar21 + -0x14);
      uVar23 = *(uint *)(iVar21 + -0x10);
      uVar28 = (local_40 >> 2) + local_40 * 0x40000000;
      uVar30 = *(uint *)(iVar21 + -8);
      uVar2 = *(uint *)(iVar21 + -0xc);
      uVar29 = *(uint *)(iVar21 + -4);
      uVar11 = ((local_38 ^ uVar7) & local_40 ^ local_38) + local_34 + 0x5a827999 + uVar14 +
               (uVar5 >> 0x1b) + uVar5 * 0x20;
      uVar10 = (uVar5 >> 2) + uVar5 * 0x40000000;
      uVar1 = ((uVar7 ^ uVar28) & uVar5 ^ uVar7) + local_38 + 0x5a827999 + uVar19 +
              (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar5 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar7 = ((uVar28 ^ uVar10) & uVar11 ^ uVar28) + uVar7 + 0x5a827999 + uVar18 +
              (uVar1 >> 0x1b) + uVar1 * 0x20;
      uVar3 = (uVar1 >> 2) + uVar1 * 0x40000000;
      uVar12 = (uVar7 >> 2) + uVar7 * 0x40000000;
      uVar11 = ((uVar10 ^ uVar5) & uVar1 ^ uVar10) + uVar28 + 0x5a827999 + uVar17 +
               (uVar7 >> 0x1b) + uVar7 * 0x20;
      uVar28 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar10 = ((uVar5 ^ uVar3) & uVar7 ^ uVar5) + uVar16 + 0x5a827999 + uVar10 +
               (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar7 = (uVar10 >> 2) + uVar10 * 0x40000000;
      uVar11 = ((uVar3 ^ uVar12) & uVar11 ^ uVar3) + uVar15 + 0x5a827999 + uVar5 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar5 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar10 = ((uVar12 ^ uVar28) & uVar10 ^ uVar12) + uVar26 + 0x5a827999 + uVar3 +
               (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar1 = (uVar10 >> 2) + uVar10 * 0x40000000;
      uVar11 = ((uVar28 ^ uVar7) & uVar11 ^ uVar28) + uVar25 + 0x5a827999 + uVar12 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar12 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar10 = ((uVar7 ^ uVar5) & uVar10 ^ uVar7) + uVar22 + 0x5a827999 + uVar28 +
               (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar11 = ((uVar5 ^ uVar1) & uVar11 ^ uVar5) + uVar20 + 0x5a827999 + uVar7 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar7 = (uVar10 >> 2) + uVar10 * 0x40000000;
      iVar8 = ((uVar1 ^ uVar12) & uVar10 ^ uVar1) + uVar24 + 0x5a827999 + uVar5;
    }
    else {
      uVar27 = (local_40 >> 2) + local_40 * 0x40000000;
      uVar2 = iVar21 - 0x40U & 3;
      uVar11 = (uint)(&DAT_ffffffc4 + iVar21) & 3;
      uVar5 = (uint)(&DAT_ffffffc8 + iVar21) & 3;
      uVar10 = (uint)(&DAT_ffffffcc + iVar21) & 3;
      uVar7 = iVar21 - 0x3dU & 3;
      uVar13 = (*(int *)((iVar21 - 0x40U) - uVar2) << uVar2 * 8 |
               param_4 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar7 + 1) * 8 |
               *(uint *)((iVar21 - 0x3dU) - uVar7) >> (3 - uVar7) * 8;
      uVar9 = (local_3c >> 2) + local_3c * 0x40000000;
      uVar2 = iVar21 - 0x39U & 3;
      uVar14 = (*(int *)(&DAT_ffffffc4 + iVar21 + -uVar11) << uVar11 * 8 |
               in_t0 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar2 + 1) * 8 |
               *(uint *)((iVar21 - 0x39U) - uVar2) >> (3 - uVar2) * 8;
      uVar2 = iVar21 - 0x35U & 3;
      uVar19 = (*(int *)(&DAT_ffffffc8 + iVar21 + -uVar5) << uVar5 * 8 |
               in_t5 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar2 + 1) * 8 |
               *(uint *)((iVar21 - 0x35U) - uVar2) >> (3 - uVar2) * 8;
      uVar2 = iVar21 - 0x30U & 3;
      uVar11 = iVar21 - 0x2cU & 3;
      uVar3 = ((local_38 ^ local_34) & local_3c ^ local_34) +
              (local_40 >> 0x1b) + local_40 * 0x20 + local_30 + 0x5a827999 + uVar13;
      uVar5 = iVar21 - 0x31U & 3;
      uVar18 = (*(int *)(&DAT_ffffffcc + iVar21 + -uVar10) << uVar10 * 8 |
               in_t4 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar5 + 1) * 8 |
               *(uint *)((iVar21 - 0x31U) - uVar5) >> (3 - uVar5) * 8;
      uVar5 = iVar21 - 0x28U & 3;
      uVar10 = iVar21 - 0x24U & 3;
      uVar7 = iVar21 - 0x2dU & 3;
      uVar17 = (*(int *)((iVar21 - 0x30U) - uVar2) << uVar2 * 8 |
               in_t3 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar7 + 1) * 8 |
               *(uint *)((iVar21 - 0x2dU) - uVar7) >> (3 - uVar7) * 8;
      uVar2 = iVar21 - 0x29U & 3;
      uVar16 = (*(int *)((iVar21 - 0x2cU) - uVar11) << uVar11 * 8 |
               local_3c & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar2 + 1) * 8 |
               *(uint *)((iVar21 - 0x29U) - uVar2) >> (3 - uVar2) * 8;
      uVar2 = iVar21 - 0x20U & 3;
      uVar11 = iVar21 - 0x1cU & 3;
      uVar7 = iVar21 - 0x18U & 3;
      uVar6 = ((local_38 ^ uVar9) & local_40 ^ local_38) + local_34 + 0x5a827999 + uVar14 +
              (uVar3 >> 0x1b) + uVar3 * 0x20;
      uVar28 = iVar21 - 0x14U & 3;
      uVar12 = iVar21 - 0x10U & 3;
      uVar1 = local_38 + 0x5a827999 + uVar19;
      uVar15 = iVar21 - 0x25U & 3;
      uVar15 = (*(int *)((iVar21 - 0x28U) - uVar5) << uVar5 * 8 |
               local_34 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar15 + 1) * 8 |
               *(uint *)((iVar21 - 0x25U) - uVar15) >> (3 - uVar15) * 8;
      uVar4 = (uVar3 >> 2) + uVar3 * 0x40000000;
      uVar5 = iVar21 - 0x21U & 3;
      uVar26 = (*(int *)((iVar21 - 0x24U) - uVar10) << uVar10 * 8 |
               unaff_s4 & 0xffffffffU >> (4 - uVar10) * 8) & -1 << (uVar5 + 1) * 8 |
               *(uint *)((iVar21 - 0x21U) - uVar5) >> (3 - uVar5) * 8;
      uVar5 = iVar21 - 0x1dU & 3;
      uVar25 = (*(int *)((iVar21 - 0x20U) - uVar2) << uVar2 * 8 |
               unaff_s3 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar5 + 1) * 8 |
               *(uint *)((iVar21 - 0x1dU) - uVar5) >> (3 - uVar5) * 8;
      uVar2 = iVar21 - 0xcU & 3;
      uVar5 = iVar21 - 0x19U & 3;
      uVar22 = (*(int *)((iVar21 - 0x1cU) - uVar11) << uVar11 * 8 |
               unaff_s0 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar5 + 1) * 8 |
               *(uint *)((iVar21 - 0x19U) - uVar5) >> (3 - uVar5) * 8;
      uVar11 = iVar21 - 0x15U & 3;
      uVar20 = (*(int *)((iVar21 - 0x18U) - uVar7) << uVar7 * 8 |
               local_38 & 0xffffffffU >> (4 - uVar7) * 8) & -1 << (uVar11 + 1) * 8 |
               *(uint *)((iVar21 - 0x15U) - uVar11) >> (3 - uVar11) * 8;
      uVar11 = iVar21 - 0x11U & 3;
      uVar24 = (*(int *)((iVar21 - 0x14U) - uVar28) << uVar28 * 8 |
               unaff_s2 & 0xffffffffU >> (4 - uVar28) * 8) & -1 << (uVar11 + 1) * 8 |
               *(uint *)((iVar21 - 0x11U) - uVar11) >> (3 - uVar11) * 8;
      uVar11 = iVar21 - 8U & 3;
      uVar5 = iVar21 - 4U & 3;
      uVar10 = iVar21 - 0xdU & 3;
      uVar23 = (*(int *)((iVar21 - 0x10U) - uVar12) << uVar12 * 8 |
               unaff_s1 & 0xffffffffU >> (4 - uVar12) * 8) & -1 << (uVar10 + 1) * 8 |
               *(uint *)((iVar21 - 0xdU) - uVar10) >> (3 - uVar10) * 8;
      uVar10 = iVar21 - 9U & 3;
      uVar2 = (*(int *)((iVar21 - 0xcU) - uVar2) << uVar2 * 8 |
              uVar1 & 0xffffffffU >> (4 - uVar2) * 8) & -1 << (uVar10 + 1) * 8 |
              *(uint *)((iVar21 - 9U) - uVar10) >> (3 - uVar10) * 8;
      uVar28 = ((uVar9 ^ uVar27) & uVar3 ^ uVar9) + uVar1 + (uVar6 >> 0x1b) + uVar6 * 0x20;
      uVar7 = (uVar6 >> 2) + uVar6 * 0x40000000;
      uVar10 = iVar21 - 5U & 3;
      uVar30 = (*(int *)((iVar21 - 8U) - uVar11) << uVar11 * 8 |
               local_40 & 0xffffffffU >> (4 - uVar11) * 8) & -1 << (uVar10 + 1) * 8 |
               *(uint *)((iVar21 - 5U) - uVar10) >> (3 - uVar10) * 8;
      uVar11 = iVar21 - 1U & 3;
      uVar29 = (*(int *)((iVar21 - 4U) - uVar5) << uVar5 * 8 |
               0xffffffffU >> (4 - uVar5) * 8 & 0x5a827999) & -1 << (uVar11 + 1) * 8 |
               *(uint *)((iVar21 - 1U) - uVar11) >> (3 - uVar11) * 8;
      uVar11 = ((uVar27 ^ uVar4) & uVar6 ^ uVar27) + uVar9 + 0x5a827999 + uVar18 +
               (uVar28 >> 0x1b) + uVar28 * 0x20;
      uVar1 = (uVar28 >> 2) + uVar28 * 0x40000000;
      uVar12 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar10 = ((uVar4 ^ uVar7) & uVar28 ^ uVar4) + uVar27 + 0x5a827999 + uVar17 +
               (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar3 = (uVar10 >> 2) + uVar10 * 0x40000000;
      uVar11 = ((uVar7 ^ uVar1) & uVar11 ^ uVar7) + uVar16 + 0x5a827999 + uVar4 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar5 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar10 = ((uVar1 ^ uVar12) & uVar10 ^ uVar1) + uVar15 + 0x5a827999 + uVar7 +
               (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar28 = (uVar10 >> 2) + uVar10 * 0x40000000;
      uVar11 = ((uVar12 ^ uVar3) & uVar11 ^ uVar12) + uVar26 + 0x5a827999 + uVar1 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar1 = (uVar11 >> 2) + uVar11 * 0x40000000;
      uVar7 = ((uVar3 ^ uVar5) & uVar10 ^ uVar3) + uVar25 + 0x5a827999 + uVar12 +
              (uVar11 >> 0x1b) + uVar11 * 0x20;
      uVar12 = (uVar7 >> 2) + uVar7 * 0x40000000;
      uVar10 = ((uVar5 ^ uVar28) & uVar11 ^ uVar5) + uVar22 + 0x5a827999 + uVar3 +
               (uVar7 >> 0x1b) + uVar7 * 0x20;
      uVar11 = ((uVar28 ^ uVar1) & uVar7 ^ uVar28) + uVar20 + 0x5a827999 + uVar5 +
               (uVar10 >> 0x1b) + uVar10 * 0x20;
      uVar7 = (uVar10 >> 2) + uVar10 * 0x40000000;
      iVar8 = ((uVar1 ^ uVar12) & uVar10 ^ uVar1) + uVar24 + 0x5a827999 + uVar28;
    }
    uVar5 = iVar8 + (uVar11 >> 0x1b) + uVar11 * 0x20;
    uVar10 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar28 = (uVar5 >> 2) + uVar5 * 0x40000000;
    uVar11 = ((uVar12 ^ uVar7) & uVar11 ^ uVar12) + uVar23 + 0x5a827999 + uVar1 +
             (uVar5 >> 0x1b) + uVar5 * 0x20;
    uVar5 = ((uVar7 ^ uVar10) & uVar5 ^ uVar7) + uVar2 + 0x5a827999 + uVar12 +
            (uVar11 >> 0x1b) + uVar11 * 0x20;
    uVar1 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar12 = ((uVar10 ^ uVar28) & uVar11 ^ uVar10) + uVar30 + 0x5a827999 + uVar7 +
             (uVar5 >> 0x1b) + uVar5 * 0x20;
    uVar11 = ((uVar28 ^ uVar1) & uVar5 ^ uVar28) + uVar29 + 0x5a827999 + uVar10 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar13 = uVar2 ^ uVar13 ^ uVar19 ^ uVar25;
    uVar10 = (uVar5 >> 2) + uVar5 * 0x40000000;
    uVar7 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar14 = uVar30 ^ uVar14 ^ uVar18 ^ uVar22;
    uVar12 = (uVar11 >> 0x1b) + uVar11 * 0x20 + uVar28 + 0x5a827999 + uVar13 +
             ((uVar10 ^ uVar1) & uVar12 ^ uVar1);
    uVar5 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar19 = uVar29 ^ uVar19 ^ uVar17 ^ uVar20;
    uVar28 = ((uVar10 ^ uVar7) & uVar11 ^ uVar10) + uVar1 + 0x5a827999 + uVar14 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar1 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar18 = uVar13 ^ uVar18 ^ uVar16 ^ uVar24;
    uVar11 = ((uVar7 ^ uVar5) & uVar12 ^ uVar7) + uVar10 + 0x5a827999 + uVar19 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar12 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar17 = uVar14 ^ uVar17 ^ uVar15 ^ uVar23;
    uVar7 = ((uVar5 ^ uVar1) & uVar28 ^ uVar5) + uVar7 + 0x5a827999 + uVar18 +
            (uVar11 >> 0x1b) + uVar11 * 0x20;
    uVar16 = uVar19 ^ uVar16 ^ uVar26 ^ uVar2;
    uVar10 = (uVar11 >> 2) + uVar11 * 0x40000000;
    uVar5 = (uVar1 ^ uVar12 ^ uVar11) + uVar5 + 0x6ed9eba1 + uVar17 + (uVar7 >> 0x1b) + uVar7 * 0x20
    ;
    uVar15 = uVar18 ^ uVar15 ^ uVar25 ^ uVar30;
    uVar28 = (uVar7 >> 2) + uVar7 * 0x40000000;
    uVar7 = (uVar12 ^ uVar10 ^ uVar7) + uVar16 + 0x6ed9eba1 + uVar1 + (uVar5 >> 0x1b) + uVar5 * 0x20
    ;
    uVar11 = uVar17 ^ uVar26 ^ uVar22 ^ uVar29;
    uVar3 = (uVar5 >> 2) + uVar5 * 0x40000000;
    uVar26 = (uVar10 ^ uVar28 ^ uVar5) + uVar15 + 0x6ed9eba1 + uVar12 +
             (uVar7 >> 0x1b) + uVar7 * 0x20;
    uVar5 = uVar16 ^ uVar25 ^ uVar20 ^ uVar13;
    uVar12 = (uVar7 >> 2) + uVar7 * 0x40000000;
    uVar10 = (uVar28 ^ uVar3 ^ uVar7) + uVar11 + 0x6ed9eba1 + uVar10 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar22 = uVar15 ^ uVar22 ^ uVar24 ^ uVar14;
    uVar25 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar7 = (uVar3 ^ uVar12 ^ uVar26) + uVar5 + 0x6ed9eba1 + uVar28 +
            (uVar10 >> 0x1b) + uVar10 * 0x20;
    uVar20 = uVar11 ^ uVar20 ^ uVar23 ^ uVar19;
    uVar1 = (uVar10 >> 2) + uVar10 * 0x40000000;
    uVar28 = (uVar12 ^ uVar25 ^ uVar10) + uVar22 + 0x6ed9eba1 + uVar3 +
             (uVar7 >> 0x1b) + uVar7 * 0x20;
    uVar10 = uVar5 ^ uVar24 ^ uVar2 ^ uVar18;
    uVar26 = (uVar7 >> 2) + uVar7 * 0x40000000;
    uVar12 = (uVar25 ^ uVar1 ^ uVar7) + uVar20 + 0x6ed9eba1 + uVar12 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar7 = uVar22 ^ uVar23 ^ uVar30 ^ uVar17;
    uVar23 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar28 = (uVar1 ^ uVar26 ^ uVar28) + uVar10 + 0x6ed9eba1 + uVar25 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar2 = uVar20 ^ uVar2 ^ uVar29 ^ uVar16;
    uVar25 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar12 = (uVar26 ^ uVar23 ^ uVar12) + uVar7 + 0x6ed9eba1 + uVar1 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar30 = uVar10 ^ uVar30 ^ uVar13 ^ uVar15;
    uVar24 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar26 = (uVar23 ^ uVar25 ^ uVar28) + uVar2 + 0x6ed9eba1 + uVar26 +
             (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar29 = uVar7 ^ uVar29 ^ uVar14 ^ uVar11;
    uVar1 = (uVar12 >> 2) + uVar12 * 0x40000000;
    uVar23 = (uVar25 ^ uVar24 ^ uVar12) + uVar30 + 0x6ed9eba1 + uVar23 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar28 = uVar2 ^ uVar13 ^ uVar19 ^ uVar5;
    uVar3 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar25 = (uVar24 ^ uVar1 ^ uVar26) + uVar29 + 0x6ed9eba1 + uVar25 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar12 = uVar30 ^ uVar14 ^ uVar18 ^ uVar22;
    uVar13 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar14 = (uVar1 ^ uVar3 ^ uVar23) + uVar28 + 0x6ed9eba1 + uVar24 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar19 = uVar29 ^ uVar19 ^ uVar17 ^ uVar20;
    uVar26 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar18 = uVar28 ^ uVar18 ^ uVar16 ^ uVar10;
    uVar24 = (uVar3 ^ uVar13 ^ uVar25) + uVar12 + 0x6ed9eba1 + uVar1 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar1 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar17 = uVar12 ^ uVar17 ^ uVar15 ^ uVar7;
    uVar23 = (uVar13 ^ uVar26 ^ uVar14) + uVar19 + 0x6ed9eba1 + uVar3 +
             (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar25 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar14 = uVar19 ^ uVar16 ^ uVar11 ^ uVar2;
    uVar16 = (uVar26 ^ uVar1 ^ uVar24) + uVar18 + 0x6ed9eba1 + uVar13 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar24 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar23 = (uVar1 ^ uVar25 ^ uVar23) + uVar17 + 0x6ed9eba1 + uVar26 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar13 = uVar18 ^ uVar15 ^ uVar5 ^ uVar30;
    uVar3 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar11 = uVar17 ^ uVar11 ^ uVar22 ^ uVar29;
    uVar26 = (uVar25 ^ uVar24 ^ uVar16) + uVar14 + 0x6ed9eba1 + uVar1 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar15 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar16 = (uVar24 ^ uVar3 ^ uVar23) + uVar13 + 0x6ed9eba1 + uVar25 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar5 = uVar14 ^ uVar5 ^ uVar20 ^ uVar28;
    uVar23 = (uVar3 ^ uVar15 ^ uVar26) + uVar11 + 0x6ed9eba1 + uVar24 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar25 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar22 = uVar13 ^ uVar22 ^ uVar10 ^ uVar12;
    uVar1 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar16 = ((uVar16 | uVar25) & uVar15 | uVar16 & uVar25) +
             uVar5 + 0x8f1bbcdc + uVar3 + (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar20 = uVar11 ^ uVar20 ^ uVar7 ^ uVar19;
    uVar24 = ((uVar23 | uVar1) & uVar25 | uVar23 & uVar1) + uVar22 + 0x8f1bbcdc + uVar15 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar26 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar10 = uVar5 ^ uVar10 ^ uVar2 ^ uVar18;
    uVar3 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar15 = ((uVar16 | uVar26) & uVar1 | uVar16 & uVar26) +
             uVar20 + 0x8f1bbcdc + uVar25 + (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar7 = uVar22 ^ uVar7 ^ uVar30 ^ uVar17;
    uVar23 = ((uVar24 | uVar3) & uVar26 | uVar24 & uVar3) + uVar10 + 0x8f1bbcdc + uVar1 +
             (uVar15 >> 0x1b) + uVar15 * 0x20;
    uVar25 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar2 = uVar20 ^ uVar2 ^ uVar29 ^ uVar14;
    uVar1 = (uVar15 >> 2) + uVar15 * 0x40000000;
    uVar16 = ((uVar15 | uVar25) & uVar3 | uVar15 & uVar25) +
             uVar7 + 0x8f1bbcdc + uVar26 + (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar30 = uVar10 ^ uVar30 ^ uVar28 ^ uVar13;
    uVar15 = ((uVar23 | uVar1) & uVar25 | uVar23 & uVar1) + uVar2 + 0x8f1bbcdc + uVar3 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar24 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar29 = uVar7 ^ uVar29 ^ uVar12 ^ uVar11;
    uVar26 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar23 = ((uVar16 | uVar24) & uVar1 | uVar16 & uVar24) +
             uVar30 + 0x8f1bbcdc + uVar25 + (uVar15 >> 0x1b) + uVar15 * 0x20;
    uVar28 = uVar2 ^ uVar28 ^ uVar19 ^ uVar5;
    uVar16 = ((uVar15 | uVar26) & uVar24 | uVar15 & uVar26) + uVar29 + 0x8f1bbcdc + uVar1 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar15 = (uVar15 >> 2) + uVar15 * 0x40000000;
    uVar12 = uVar30 ^ uVar12 ^ uVar18 ^ uVar22;
    uVar1 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar25 = ((uVar23 | uVar15) & uVar26 | uVar23 & uVar15) +
             uVar28 + 0x8f1bbcdc + uVar24 + (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar19 = uVar29 ^ uVar19 ^ uVar17 ^ uVar20;
    uVar24 = ((uVar16 | uVar1) & uVar15 | uVar16 & uVar1) + uVar12 + 0x8f1bbcdc + uVar26 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar23 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar16 = uVar28 ^ uVar18 ^ uVar14 ^ uVar10;
    uVar3 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar18 = ((uVar25 | uVar23) & uVar1 | uVar25 & uVar23) +
             uVar19 + 0x8f1bbcdc + uVar15 + (uVar24 >> 0x1b) + uVar24 * 0x20;
    uVar25 = ((uVar24 | uVar3) & uVar23 | uVar24 & uVar3) + uVar16 + 0x8f1bbcdc + uVar1 +
             (uVar18 >> 0x1b) + uVar18 * 0x20;
    uVar15 = uVar12 ^ uVar17 ^ uVar13 ^ uVar7;
    uVar24 = (uVar24 >> 2) + uVar24 * 0x40000000;
    uVar14 = uVar19 ^ uVar14 ^ uVar11 ^ uVar2;
    uVar26 = (uVar18 >> 2) + uVar18 * 0x40000000;
    uVar17 = ((uVar18 | uVar24) & uVar3 | uVar18 & uVar24) +
             uVar15 + 0x8f1bbcdc + uVar23 + (uVar25 >> 0x1b) + uVar25 * 0x20;
    uVar13 = uVar16 ^ uVar13 ^ uVar5 ^ uVar30;
    uVar1 = ((uVar25 | uVar26) & uVar24 | uVar25 & uVar26) + uVar14 + 0x8f1bbcdc + uVar3 +
            (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar18 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar11 = uVar15 ^ uVar11 ^ uVar22 ^ uVar29;
    uVar25 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = ((uVar17 | uVar18) & uVar26 | uVar17 & uVar18) +
             uVar13 + 0x8f1bbcdc + uVar24 + (uVar1 >> 0x1b) + uVar1 * 0x20;
    uVar5 = uVar14 ^ uVar5 ^ uVar20 ^ uVar28;
    uVar23 = ((uVar1 | uVar25) & uVar18 | uVar1 & uVar25) + uVar11 + 0x8f1bbcdc + uVar26 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar24 = (uVar1 >> 2) + uVar1 * 0x40000000;
    uVar22 = uVar13 ^ uVar22 ^ uVar10 ^ uVar12;
    uVar26 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = ((uVar17 | uVar24) & uVar25 | uVar17 & uVar24) +
             uVar5 + 0x8f1bbcdc + uVar18 + (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar18 = uVar11 ^ uVar20 ^ uVar7 ^ uVar19;
    uVar20 = ((uVar23 | uVar26) & uVar24 | uVar23 & uVar26) + uVar22 + 0x8f1bbcdc + uVar25 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar23 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar10 = uVar5 ^ uVar10 ^ uVar2 ^ uVar16;
    uVar25 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = ((uVar17 | uVar23) & uVar26 | uVar17 & uVar23) +
             uVar18 + 0x8f1bbcdc + uVar24 + (uVar20 >> 0x1b) + uVar20 * 0x20;
    uVar7 = uVar22 ^ uVar7 ^ uVar30 ^ uVar15;
    uVar24 = (uVar20 >> 2) + uVar20 * 0x40000000;
    uVar26 = ((uVar20 | uVar25) & uVar23 | uVar20 & uVar25) + uVar10 + 0x8f1bbcdc + uVar26 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar2 = uVar18 ^ uVar2 ^ uVar29 ^ uVar14;
    uVar20 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar30 = uVar10 ^ uVar30 ^ uVar28 ^ uVar13;
    uVar17 = (uVar25 ^ uVar24 ^ uVar17) + uVar7 + 0xca62c1d6 + uVar23 +
             (uVar26 >> 0x1b) + uVar26 * 0x20;
    uVar1 = (uVar26 >> 2) + uVar26 * 0x40000000;
    uVar3 = uVar7 ^ uVar29 ^ uVar12 ^ uVar11;
    uVar25 = (uVar24 ^ uVar20 ^ uVar26) + uVar2 + 0xca62c1d6 + uVar25 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar23 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar17 = (uVar20 ^ uVar1 ^ uVar17) + uVar30 + 0xca62c1d6 + uVar24 +
             (uVar25 >> 0x1b) + uVar25 * 0x20;
    param_4 = uVar2 ^ uVar28 ^ uVar19 ^ uVar5;
    uVar24 = (uVar25 >> 2) + uVar25 * 0x40000000;
    uVar28 = (uVar1 ^ uVar23 ^ uVar25) + uVar3 + 0xca62c1d6 + uVar20 +
             (uVar17 >> 0x1b) + uVar17 * 0x20;
    in_t0 = uVar30 ^ uVar12 ^ uVar16 ^ uVar22;
    uVar12 = (uVar17 >> 2) + uVar17 * 0x40000000;
    uVar20 = (uVar23 ^ uVar24 ^ uVar17) + param_4 + 0xca62c1d6 + uVar1 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar17 = uVar3 ^ uVar19 ^ uVar15 ^ uVar18;
    uVar19 = (uVar28 >> 2) + uVar28 * 0x40000000;
    in_t4 = param_4 ^ uVar16 ^ uVar14 ^ uVar10;
    uVar25 = (uVar20 >> 2) + uVar20 * 0x40000000;
    uVar28 = (uVar24 ^ uVar12 ^ uVar28) + in_t0 + 0xca62c1d6 + uVar23 +
             (uVar20 >> 0x1b) + uVar20 * 0x20;
    uVar23 = (uVar12 ^ uVar19 ^ uVar20) + uVar17 + 0xca62c1d6 + uVar24 +
             (uVar28 >> 0x1b) + uVar28 * 0x20;
    uVar15 = in_t0 ^ uVar15 ^ uVar13 ^ uVar7;
    uVar16 = (uVar28 >> 2) + uVar28 * 0x40000000;
    uVar20 = (uVar19 ^ uVar25 ^ uVar28) + in_t4 + 0xca62c1d6 + uVar12 +
             (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar12 = uVar17 ^ uVar14 ^ uVar11 ^ uVar2;
    uVar24 = (uVar23 >> 2) + uVar23 * 0x40000000;
    uVar14 = (uVar25 ^ uVar16 ^ uVar23) + uVar15 + 0xca62c1d6 + uVar19 +
             (uVar20 >> 0x1b) + uVar20 * 0x20;
    uVar28 = in_t4 ^ uVar13 ^ uVar5 ^ uVar30;
    uVar19 = (uVar20 >> 2) + uVar20 * 0x40000000;
    uVar13 = (uVar16 ^ uVar24 ^ uVar20) + uVar12 + 0xca62c1d6 + uVar25 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar11 = uVar15 ^ uVar11 ^ uVar22 ^ uVar3;
    uVar23 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar14 = (uVar24 ^ uVar19 ^ uVar14) + uVar28 + 0xca62c1d6 + uVar16 +
             (uVar13 >> 0x1b) + uVar13 * 0x20;
    uVar5 = uVar12 ^ uVar5 ^ uVar18 ^ param_4;
    uVar20 = (uVar13 >> 2) + uVar13 * 0x40000000;
    uVar16 = (uVar19 ^ uVar23 ^ uVar13) + uVar11 + 0xca62c1d6 + uVar24 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar13 = uVar28 ^ uVar22 ^ uVar10 ^ in_t0;
    uVar22 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar14 = (uVar23 ^ uVar20 ^ uVar14) + uVar5 + 0xca62c1d6 + uVar19 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    unaff_s1 = 0xca62c1d6;
    in_t5 = uVar11 ^ uVar18 ^ uVar7 ^ uVar17;
    uVar17 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar16 = (uVar20 ^ uVar22 ^ uVar16) + uVar13 + 0xca62c1d6 + uVar23 +
             (uVar14 >> 0x1b) + uVar14 * 0x20;
    uVar5 = uVar5 ^ uVar10 ^ uVar2 ^ in_t4;
    uVar10 = (uVar14 >> 2) + uVar14 * 0x40000000;
    unaff_s2 = uVar5 + 0xca62c1d6;
    uVar14 = (uVar22 ^ uVar17 ^ uVar14) + in_t5 + 0xca62c1d6 + uVar20 +
             (uVar16 >> 0x1b) + uVar16 * 0x20;
    uVar13 = uVar13 ^ uVar7 ^ uVar30 ^ uVar15;
    uVar18 = (uVar16 >> 2) + uVar16 * 0x40000000;
    uVar15 = (uVar17 ^ uVar10 ^ uVar16) + unaff_s2 + uVar22 + (uVar14 >> 0x1b) + uVar14 * 0x20;
    in_t3 = uVar10 ^ uVar18 ^ uVar14;
    uVar14 = (uVar14 >> 2) + uVar14 * 0x40000000;
    uVar7 = in_t3 + uVar13 + 0xca62c1d6 + uVar17 + (uVar15 >> 0x1b) + uVar15 * 0x20;
    uVar16 = (uVar15 >> 2) + uVar15 * 0x40000000;
    uVar2 = (in_t5 ^ uVar2 ^ uVar3 ^ uVar12) + 0xca62c1d6 + uVar10 + (uVar18 ^ uVar14 ^ uVar15) +
            (uVar7 >> 0x1b) + uVar7 * 0x20;
    unaff_s4 = (uVar7 >> 2) + uVar7 * 0x40000000;
    unaff_s0 = (uVar13 ^ uVar3 ^ in_t0 ^ uVar11) + 0xca62c1d6;
    uVar11 = (uVar5 ^ uVar30 ^ param_4 ^ uVar28) + 0xca62c1d6 + uVar18 + (uVar14 ^ uVar16 ^ uVar7) +
             (uVar2 >> 0x1b) + uVar2 * 0x20;
    unaff_s3 = (uVar2 >> 2) + uVar2 * 0x40000000;
    local_38 = unaff_s3 + local_38;
    local_40 = unaff_s0 + uVar14 + (uVar16 ^ unaff_s4 ^ uVar2) + (uVar11 >> 0x1b) + uVar11 * 0x20 +
               local_40;
    local_3c = uVar11 + local_3c;
    local_34 = unaff_s4 + local_34;
    param_1[1] = local_3c;
    *param_1 = local_40;
    local_30 = uVar16 + local_30;
    local_res8 = local_res8 + -1;
    param_1[4] = local_30;
    param_1[2] = local_38;
    param_1[3] = local_34;
    iVar21 = iVar21 + 0x40;
  } while (local_res8 != 0);
  return;
}

