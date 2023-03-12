
void __regparm3 sha1_block_data_order(uint *param_1,uint *param_2,int param_3)

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
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint *local_84;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_3c;
  uint local_1c;
  int local_14;
  
  local_78 = *param_1;
  local_3c = param_1[1];
  local_74 = param_1[2];
  local_70 = param_1[3];
  local_1c = param_1[4];
  local_84 = param_2;
  local_14 = param_3;
  do {
    uVar3 = *local_84;
    uVar21 = local_84[1];
    uVar19 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar1 = uVar21 >> 0x18 | (uVar21 & 0xff0000) >> 8 | (uVar21 & 0xff00) << 8 | uVar21 << 0x18;
    uVar3 = local_84[2];
    uVar20 = local_3c << 0x1e | local_3c >> 2;
    uVar5 = ((local_74 ^ local_70) & local_3c ^ local_70) +
            uVar19 + 0x5a827999 + (local_78 << 5 | local_78 >> 0x1b) + local_1c;
    uVar21 = local_84[3];
    uVar2 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar4 = local_70 + 0x5a827999 + uVar1 + (uVar5 * 0x20 | uVar5 >> 0x1b) +
            ((local_74 ^ uVar20) & local_78 ^ local_74);
    uVar8 = uVar21 >> 0x18 | (uVar21 & 0xff0000) >> 8 | (uVar21 & 0xff00) << 8 | uVar21 << 0x18;
    uVar16 = local_78 << 0x1e | local_78 >> 2;
    uVar6 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar3 = local_74 + 0x5a827999 + uVar2 + (uVar4 * 0x20 | uVar4 >> 0x1b) +
            ((uVar20 ^ uVar16) & uVar5 ^ uVar20);
    uVar21 = local_84[4];
    uVar9 = uVar21 >> 0x18 | (uVar21 & 0xff0000) >> 8 | (uVar21 & 0xff00) << 8 | uVar21 << 0x18;
    uVar10 = ((uVar16 ^ uVar6) & uVar4 ^ uVar16) +
             (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar20 + 0x5a827999 + uVar8;
    uVar5 = uVar4 * 0x40000000 | uVar4 >> 2;
    uVar21 = local_84[5];
    uVar11 = uVar21 >> 0x18 | (uVar21 & 0xff0000) >> 8 | (uVar21 & 0xff00) << 8 | uVar21 << 0x18;
    uVar20 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar21 = (uVar10 * 0x20 | uVar10 >> 0x1b) + uVar16 + 0x5a827999 + uVar9 +
             ((uVar6 ^ uVar5) & uVar3 ^ uVar6);
    uVar4 = uVar10 * 0x40000000 | uVar10 >> 2;
    uVar3 = local_84[6];
    uVar12 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar6 = (uVar21 * 0x20 | uVar21 >> 0x1b) + uVar6 + 0x5a827999 + uVar11 +
            ((uVar5 ^ uVar20) & uVar10 ^ uVar5);
    uVar3 = local_84[7];
    uVar7 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar10 = uVar21 * 0x40000000 | uVar21 >> 2;
    uVar3 = (uVar6 * 0x20 | uVar6 >> 0x1b) + uVar5 + 0x5a827999 + uVar12 +
            ((uVar20 ^ uVar4) & uVar21 ^ uVar20);
    uVar21 = local_84[8];
    uVar13 = uVar21 >> 0x18 | (uVar21 & 0xff0000) >> 8 | (uVar21 & 0xff00) << 8 | uVar21 << 0x18;
    uVar5 = (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar20 + 0x5a827999 + uVar7 +
            ((uVar4 ^ uVar10) & uVar6 ^ uVar4);
    uVar21 = local_84[9];
    uVar17 = uVar6 * 0x40000000 | uVar6 >> 2;
    uVar14 = uVar21 >> 0x18 | (uVar21 & 0xff0000) >> 8 | (uVar21 & 0xff00) << 8 | uVar21 << 0x18;
    uVar16 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar20 = (uVar5 * 0x20 | uVar5 >> 0x1b) + uVar4 + 0x5a827999 + uVar13 +
             (uVar3 & (uVar10 ^ uVar17) ^ uVar10);
    uVar3 = local_84[10];
    uVar21 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar4 = (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar10 + 0x5a827999 + uVar14 +
            ((uVar17 ^ uVar16) & uVar5 ^ uVar17);
    uVar6 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar3 = local_84[0xb];
    uVar5 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar10 = uVar20 * 0x40000000 | uVar20 >> 2;
    uVar22 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar17 + 0x5a827999 + uVar21 +
             ((uVar16 ^ uVar6) & uVar20 ^ uVar16);
    uVar20 = uVar4 * 0x40000000 | uVar4 >> 2;
    uVar3 = local_84[0xc];
    uVar18 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar3 = local_84[0xd];
    uVar17 = (uVar22 * 0x20 | uVar22 >> 0x1b) + uVar16 + 0x5a827999 + uVar5 +
             ((uVar6 ^ uVar10) & uVar4 ^ uVar6);
    uVar15 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar23 = uVar22 * 0x40000000 | uVar22 >> 2;
    uVar4 = uVar17 * 0x40000000 | uVar17 >> 2;
    uVar16 = (uVar17 * 0x20 | uVar17 >> 0x1b) + uVar6 + 0x5a827999 + uVar18 +
             ((uVar20 ^ uVar10) & uVar22 ^ uVar10);
    uVar3 = local_84[0xe];
    uVar22 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar6 = (uVar16 * 0x20 | uVar16 >> 0x1b) + uVar10 + 0x5a827999 + uVar15 +
            ((uVar20 ^ uVar23) & uVar17 ^ uVar20);
    uVar3 = local_84[0xf];
    uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar17 = uVar16 * 0x40000000 | uVar16 >> 2;
    uVar16 = (uVar6 * 0x20 | uVar6 >> 0x1b) + uVar20 + 0x5a827999 + uVar22 +
             ((uVar4 ^ uVar23) & uVar16 ^ uVar23);
    uVar10 = uVar6 * 0x40000000 | uVar6 >> 2;
    uVar20 = (uVar16 * 0x20 | uVar16 >> 0x1b) + uVar23 + 0x5a827999 + uVar3 +
             ((uVar4 ^ uVar17) & uVar6 ^ uVar4);
    uVar6 = uVar19 ^ uVar2 ^ uVar13 ^ uVar15;
    uVar24 = uVar6 << 1 | (uint)((int)uVar6 < 0);
    uVar6 = ((uVar17 ^ uVar10) & uVar16 ^ uVar17) +
            (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar4 + 0x5a827999 + uVar24;
    uVar4 = uVar16 * 0x40000000 | uVar16 >> 2;
    uVar1 = uVar14 ^ uVar1 ^ uVar8 ^ uVar22;
    uVar19 = uVar1 << 1 | (uint)((int)uVar1 < 0);
    uVar1 = uVar20 * 0x40000000 | uVar20 >> 2;
    uVar16 = (uVar6 * 0x20 | uVar6 >> 0x1b) + uVar17 + 0x5a827999 + uVar19 +
             ((uVar10 ^ uVar4) & uVar20 ^ uVar10);
    uVar2 = uVar21 ^ uVar2 ^ uVar9 ^ uVar3;
    uVar17 = uVar2 << 1 | (uint)((int)uVar2 < 0);
    uVar10 = (uVar16 * 0x20 | uVar16 >> 0x1b) + uVar10 + 0x5a827999 + uVar17 +
             ((uVar4 ^ uVar1) & uVar6 ^ uVar4);
    uVar6 = uVar6 * 0x40000000 | uVar6 >> 2;
    uVar2 = uVar8 ^ uVar11 ^ uVar5 ^ uVar24;
    uVar20 = uVar2 << 1 | (uint)((int)uVar2 < 0);
    uVar25 = ((uVar1 ^ uVar6) & uVar16 ^ uVar1) +
             (uVar10 * 0x20 | uVar10 >> 0x1b) + uVar4 + 0x5a827999 + uVar20;
    uVar4 = uVar16 * 0x40000000 | uVar16 >> 2;
    uVar2 = uVar18 ^ uVar9 ^ uVar12 ^ uVar19;
    uVar8 = uVar2 << 1 | (uint)((int)uVar2 < 0);
    uVar23 = (uVar6 ^ uVar4 ^ uVar10) +
             uVar1 + 0x6ed9eba1 + uVar8 + (uVar25 * 0x20 | uVar25 >> 0x1b);
    uVar1 = uVar11 ^ uVar7 ^ uVar15 ^ uVar17;
    uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);
    uVar10 = uVar10 * 0x40000000 | uVar10 >> 2;
    uVar9 = (uVar4 ^ uVar10 ^ uVar25) +
            (uVar23 * 0x20 | uVar23 >> 0x1b) + uVar6 + 0x6ed9eba1 + uVar1;
    uVar2 = uVar25 * 0x40000000 | uVar25 >> 2;
    uVar6 = uVar22 ^ uVar12 ^ uVar13 ^ uVar20;
    uVar12 = uVar6 << 1 | (uint)((int)uVar6 < 0);
    uVar16 = (uVar10 ^ uVar2 ^ uVar23) +
             uVar4 + 0x6ed9eba1 + uVar12 + (uVar9 * 0x20 | uVar9 >> 0x1b);
    uVar23 = uVar23 * 0x40000000 | uVar23 >> 2;
    uVar4 = uVar3 ^ uVar7 ^ uVar14 ^ uVar8;
    uVar6 = uVar4 << 1 | (uint)((int)uVar4 < 0);
    uVar25 = (uVar2 ^ uVar23 ^ uVar9) +
             uVar10 + 0x6ed9eba1 + uVar6 + (uVar16 * 0x20 | uVar16 >> 0x1b);
    uVar4 = uVar13 ^ uVar21 ^ uVar24 ^ uVar1;
    uVar7 = uVar4 << 1 | (uint)((int)uVar4 < 0);
    uVar4 = uVar9 * 0x40000000 | uVar9 >> 2;
    uVar2 = (uVar23 ^ uVar4 ^ uVar16) +
            (uVar25 * 0x20 | uVar25 >> 0x1b) + uVar2 + 0x6ed9eba1 + uVar7;
    uVar10 = uVar14 ^ uVar5 ^ uVar19 ^ uVar12;
    uVar9 = uVar10 << 1 | (uint)((int)uVar10 < 0);
    uVar11 = uVar16 * 0x40000000 | uVar16 >> 2;
    uVar16 = (uVar4 ^ uVar11 ^ uVar25) +
             uVar23 + 0x6ed9eba1 + uVar9 + (uVar2 * 0x20 | uVar2 >> 0x1b);
    uVar21 = uVar21 ^ uVar18 ^ uVar17 ^ uVar6;
    uVar23 = uVar21 << 1 | (uint)((int)uVar21 < 0);
    uVar25 = uVar25 * 0x40000000 | uVar25 >> 2;
    uVar14 = (uVar11 ^ uVar25 ^ uVar2) +
             uVar4 + 0x6ed9eba1 + uVar23 + (uVar16 * 0x20 | uVar16 >> 0x1b);
    uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar21 = uVar20 ^ uVar5 ^ uVar15 ^ uVar7;
    uVar10 = uVar21 << 1 | (uint)((int)uVar21 < 0);
    uVar4 = (uVar2 ^ uVar25 ^ uVar16) +
            uVar11 + 0x6ed9eba1 + uVar10 + (uVar14 * 0x20 | uVar14 >> 0x1b);
    uVar16 = uVar16 * 0x40000000 | uVar16 >> 2;
    uVar21 = uVar8 ^ uVar18 ^ uVar22 ^ uVar9;
    uVar13 = uVar21 << 1 | (uint)((int)uVar21 < 0);
    uVar11 = (uVar2 ^ uVar16 ^ uVar14) +
             uVar25 + 0x6ed9eba1 + uVar13 + (uVar4 * 0x20 | uVar4 >> 0x1b);
    uVar18 = uVar14 * 0x40000000 | uVar14 >> 2;
    uVar21 = uVar3 ^ uVar15 ^ uVar1 ^ uVar23;
    uVar21 = uVar21 << 1 | (uint)((int)uVar21 < 0);
    uVar15 = (uVar16 ^ uVar18 ^ uVar4) +
             uVar2 + 0x6ed9eba1 + uVar21 + (uVar11 * 0x20 | uVar11 >> 0x1b);
    uVar2 = uVar22 ^ uVar24 ^ uVar12 ^ uVar10;
    uVar2 = uVar2 << 1 | (uint)((int)uVar2 < 0);
    uVar5 = uVar4 * 0x40000000 | uVar4 >> 2;
    uVar4 = (uVar18 ^ uVar5 ^ uVar11) +
            uVar16 + 0x6ed9eba1 + uVar2 + (uVar15 * 0x20 | uVar15 >> 0x1b);
    uVar14 = uVar11 * 0x40000000 | uVar11 >> 2;
    uVar3 = uVar6 ^ uVar3 ^ uVar19 ^ uVar13;
    uVar11 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar16 = (uVar5 ^ uVar14 ^ uVar15) +
             uVar18 + 0x6ed9eba1 + uVar11 + (uVar4 * 0x20 | uVar4 >> 0x1b);
    uVar15 = uVar15 * 0x40000000 | uVar15 >> 2;
    uVar3 = uVar7 ^ uVar24 ^ uVar17 ^ uVar21;
    uVar18 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar3 = uVar19 ^ uVar20 ^ uVar9 ^ uVar2;
    uVar5 = (uVar14 ^ uVar15 ^ uVar4) +
            uVar5 + 0x6ed9eba1 + uVar18 + (uVar16 * 0x20 | uVar16 >> 0x1b);
    uVar19 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar3 = uVar4 * 0x40000000 | uVar4 >> 2;
    uVar22 = (uVar15 ^ uVar3 ^ uVar16) +
             (uVar5 * 0x20 | uVar5 >> 0x1b) + uVar14 + 0x6ed9eba1 + uVar19;
    uVar4 = uVar17 ^ uVar8 ^ uVar23 ^ uVar11;
    uVar14 = uVar4 << 1 | (uint)((int)uVar4 < 0);
    uVar17 = uVar16 * 0x40000000 | uVar16 >> 2;
    uVar15 = (uVar3 ^ uVar17 ^ uVar5) +
             (uVar22 * 0x20 | uVar22 >> 0x1b) + uVar15 + 0x6ed9eba1 + uVar14;
    uVar25 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar4 = uVar20 ^ uVar1 ^ uVar10 ^ uVar18;
    uVar16 = uVar4 << 1 | (uint)((int)uVar4 < 0);
    uVar5 = (uVar17 ^ uVar25 ^ uVar22) +
            uVar3 + 0x6ed9eba1 + uVar16 + (uVar15 * 0x20 | uVar15 >> 0x1b);
    uVar3 = uVar8 ^ uVar12 ^ uVar13 ^ uVar19;
    uVar3 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar24 = uVar22 * 0x40000000 | uVar22 >> 2;
    uVar22 = (uVar25 ^ uVar24 ^ uVar15) +
             (uVar5 * 0x20 | uVar5 >> 0x1b) + uVar17 + 0x6ed9eba1 + uVar3;
    uVar1 = uVar1 ^ uVar6 ^ uVar21 ^ uVar14;
    uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);
    uVar17 = uVar15 * 0x40000000 | uVar15 >> 2;
    uVar8 = (uVar24 ^ uVar17 ^ uVar5) +
            (uVar22 * 0x20 | uVar22 >> 0x1b) + uVar25 + 0x6ed9eba1 + uVar1;
    uVar4 = uVar12 ^ uVar7 ^ uVar2 ^ uVar16;
    uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
    uVar20 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar5 = (uVar17 ^ uVar20 ^ uVar22) +
            uVar24 + 0x6ed9eba1 + uVar4 + (uVar8 * 0x20 | uVar8 >> 0x1b);
    uVar12 = uVar22 * 0x40000000 | uVar22 >> 2;
    uVar6 = uVar11 ^ uVar6 ^ uVar9 ^ uVar3;
    uVar15 = uVar6 << 1 | (uint)((int)uVar6 < 0);
    uVar6 = uVar7 ^ uVar23 ^ uVar18 ^ uVar1;
    uVar22 = uVar6 << 1 | (uint)((int)uVar6 < 0);
    uVar7 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar8 = (uVar12 ^ uVar20 ^ uVar8) +
            uVar17 + 0x6ed9eba1 + uVar15 + (uVar5 * 0x20 | uVar5 >> 0x1b);
    uVar17 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar24 = ((uVar5 | uVar7) & uVar12 | uVar5 & uVar7) +
             (uVar8 * 0x20 | uVar8 >> 0x1b) + uVar20 + 0x8f1bbcdc + uVar22;
    uVar5 = uVar9 ^ uVar10 ^ uVar19 ^ uVar4;
    uVar6 = uVar5 << 1 | (uint)((int)uVar5 < 0);
    uVar9 = ((uVar8 | uVar17) & uVar7 | uVar8 & uVar17) +
            (uVar24 * 0x20 | uVar24 >> 0x1b) + uVar12 + 0x8f1bbcdc + uVar6;
    uVar20 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar5 = uVar23 ^ uVar13 ^ uVar14 ^ uVar15;
    uVar8 = uVar5 << 1 | (uint)((int)uVar5 < 0);
    uVar25 = (uVar20 & uVar24 | uVar17 & (uVar20 | uVar24)) +
             (uVar9 * 0x20 | uVar9 >> 0x1b) + uVar7 + 0x8f1bbcdc + uVar8;
    uVar12 = uVar24 * 0x40000000 | uVar24 >> 2;
    uVar5 = uVar16 ^ uVar10 ^ uVar21 ^ uVar22;
    uVar23 = uVar5 << 1 | (uint)((int)uVar5 < 0);
    uVar10 = (uVar9 & uVar12 | uVar20 & (uVar9 | uVar12)) +
             (uVar25 * 0x20 | uVar25 >> 0x1b) + uVar17 + 0x8f1bbcdc + uVar23;
    uVar9 = uVar9 * 0x40000000 | uVar9 >> 2;
    uVar5 = uVar13 ^ uVar2 ^ uVar3 ^ uVar6;
    uVar5 = uVar5 << 1 | (uint)((int)uVar5 < 0);
    uVar7 = (uVar25 & uVar9 | (uVar25 | uVar9) & uVar12) +
            (uVar10 * 0x20 | uVar10 >> 0x1b) + uVar20 + 0x8f1bbcdc + uVar5;
    uVar20 = uVar25 * 0x40000000 | uVar25 >> 2;
    uVar21 = uVar21 ^ uVar11 ^ uVar1 ^ uVar8;
    uVar24 = uVar21 << 1 | (uint)((int)uVar21 < 0);
    uVar17 = uVar10 * 0x40000000 | uVar10 >> 2;
    uVar21 = (uVar20 & uVar10 | (uVar20 | uVar10) & uVar9) +
             (uVar7 * 0x20 | uVar7 >> 0x1b) + uVar12 + 0x8f1bbcdc + uVar24;
    uVar2 = uVar2 ^ uVar18 ^ uVar4 ^ uVar23;
    uVar10 = uVar2 << 1 | (uint)((int)uVar2 < 0);
    uVar9 = (uVar7 & uVar17 | uVar20 & (uVar7 | uVar17)) +
            (uVar21 * 0x20 | uVar21 >> 0x1b) + uVar9 + 0x8f1bbcdc + uVar10;
    uVar12 = uVar7 * 0x40000000 | uVar7 >> 2;
    uVar2 = uVar15 ^ uVar11 ^ uVar19 ^ uVar5;
    uVar11 = uVar2 << 1 | (uint)((int)uVar2 < 0);
    uVar2 = uVar21 * 0x40000000 | uVar21 >> 2;
    uVar21 = (uVar21 & uVar12 | (uVar21 | uVar12) & uVar17) +
             (uVar9 * 0x20 | uVar9 >> 0x1b) + uVar20 + 0x8f1bbcdc + uVar11;
    uVar20 = uVar18 ^ uVar14 ^ uVar22 ^ uVar24;
    uVar18 = uVar20 << 1 | (uint)((int)uVar20 < 0);
    uVar13 = uVar9 * 0x40000000 | uVar9 >> 2;
    uVar20 = (uVar2 & uVar9 | (uVar2 | uVar9) & uVar12) +
             (uVar21 * 0x20 | uVar21 >> 0x1b) + uVar17 + 0x8f1bbcdc + uVar18;
    uVar7 = uVar19 ^ uVar16 ^ uVar6 ^ uVar10;
    uVar19 = uVar7 << 1 | (uint)((int)uVar7 < 0);
    uVar17 = uVar21 * 0x40000000 | uVar21 >> 2;
    uVar21 = (uVar21 & uVar13 | uVar2 & (uVar21 | uVar13)) +
             (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar12 + 0x8f1bbcdc + uVar19;
    uVar7 = uVar14 ^ uVar3 ^ uVar8 ^ uVar11;
    uVar12 = uVar7 << 1 | (uint)((int)uVar7 < 0);
    uVar7 = uVar20 * 0x40000000 | uVar20 >> 2;
    uVar20 = (uVar20 & uVar17 | uVar13 & (uVar20 | uVar17)) +
             (uVar21 * 0x20 | uVar21 >> 0x1b) + uVar2 + 0x8f1bbcdc + uVar12;
    uVar2 = uVar16 ^ uVar1 ^ uVar23 ^ uVar18;
    uVar16 = uVar2 << 1 | (uint)((int)uVar2 < 0);
    uVar9 = uVar21 * 0x40000000 | uVar21 >> 2;
    uVar2 = (uVar7 & uVar21 | (uVar7 | uVar21) & uVar17) +
            (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar13 + 0x8f1bbcdc + uVar16;
    uVar3 = uVar3 ^ uVar4 ^ uVar5 ^ uVar19;
    uVar21 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar25 = uVar20 * 0x40000000 | uVar20 >> 2;
    uVar17 = (uVar20 & uVar9 | (uVar20 | uVar9) & uVar7) +
             (uVar2 * 0x20 | uVar2 >> 0x1b) + uVar17 + 0x8f1bbcdc + uVar21;
    uVar3 = uVar1 ^ uVar15 ^ uVar24 ^ uVar12;
    uVar1 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar20 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar3 = (uVar2 & uVar25 | (uVar2 | uVar25) & uVar9) +
            (uVar17 * 0x20 | uVar17 >> 0x1b) + uVar7 + 0x8f1bbcdc + uVar1;
    uVar2 = uVar4 ^ uVar22 ^ uVar10 ^ uVar16;
    uVar7 = uVar2 << 1 | (uint)((int)uVar2 < 0);
    uVar13 = (uVar20 & uVar17 | (uVar20 | uVar17) & uVar25) +
             (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar9 + 0x8f1bbcdc + uVar7;
    uVar2 = uVar15 ^ uVar6 ^ uVar11 ^ uVar21;
    uVar9 = uVar2 << 1 | (uint)((int)uVar2 < 0);
    uVar14 = uVar17 * 0x40000000 | uVar17 >> 2;
    uVar26 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar4 = (uVar3 & uVar14 | uVar20 & (uVar3 | uVar14)) +
            (uVar13 * 0x20 | uVar13 >> 0x1b) + uVar25 + 0x8f1bbcdc + uVar9;
    uVar3 = uVar22 ^ uVar8 ^ uVar18 ^ uVar1;
    uVar2 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar17 = uVar13 * 0x40000000 | uVar13 >> 2;
    uVar3 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar20 + 0x8f1bbcdc + uVar2 +
            (uVar13 & uVar26 | (uVar13 | uVar26) & uVar14);
    uVar20 = uVar19 ^ uVar6 ^ uVar23 ^ uVar7;
    uVar13 = uVar20 << 1 | (uint)((int)uVar20 < 0);
    uVar20 = uVar4 * 0x40000000 | uVar4 >> 2;
    uVar6 = ((uVar17 | uVar4) & uVar26 | uVar17 & uVar4) +
            (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar14 + 0x8f1bbcdc + uVar13;
    uVar4 = uVar12 ^ uVar8 ^ uVar5 ^ uVar9;
    uVar15 = uVar4 << 1 | (uint)((int)uVar4 < 0);
    uVar4 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar22 = ((uVar3 | uVar20) & uVar17 | uVar3 & uVar20) +
             (uVar6 * 0x20 | uVar6 >> 0x1b) + uVar26 + 0x8f1bbcdc + uVar15;
    uVar3 = uVar16 ^ uVar23 ^ uVar24 ^ uVar2;
    uVar25 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar14 = uVar6 * 0x40000000 | uVar6 >> 2;
    uVar8 = (uVar6 & uVar4 | (uVar6 | uVar4) & uVar20) +
            (uVar22 * 0x20 | uVar22 >> 0x1b) + uVar17 + 0x8f1bbcdc + uVar25;
    uVar3 = uVar5 ^ uVar10 ^ uVar21 ^ uVar13;
    uVar23 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar26 = (uVar4 ^ uVar14 ^ uVar22) +
             uVar20 + 0xca62c1d6 + uVar23 + (uVar8 * 0x20 | uVar8 >> 0x1b);
    uVar3 = uVar24 ^ uVar11 ^ uVar1 ^ uVar15;
    uVar6 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar17 = uVar22 * 0x40000000 | uVar22 >> 2;
    uVar22 = (uVar14 ^ uVar17 ^ uVar8) +
             uVar4 + 0xca62c1d6 + uVar6 + (uVar26 * 0x20 | uVar26 >> 0x1b);
    uVar3 = uVar10 ^ uVar18 ^ uVar7 ^ uVar25;
    uVar4 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar10 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar20 = (uVar17 ^ uVar10 ^ uVar26) +
             (uVar22 * 0x20 | uVar22 >> 0x1b) + uVar14 + 0xca62c1d6 + uVar4;
    uVar3 = uVar11 ^ uVar19 ^ uVar9 ^ uVar23;
    uVar5 = uVar3 << 1 | (uint)((int)uVar3 < 0);
    uVar24 = uVar26 * 0x40000000 | uVar26 >> 2;
    uVar3 = (uVar10 ^ uVar24 ^ uVar22) +
            uVar17 + 0xca62c1d6 + uVar5 + (uVar20 * 0x20 | uVar20 >> 0x1b);
    uVar22 = uVar22 * 0x40000000 | uVar22 >> 2;
    uVar8 = uVar18 ^ uVar12 ^ uVar2 ^ uVar6;
    uVar14 = uVar8 << 1 | (uint)((int)uVar8 < 0);
    uVar11 = (uVar24 ^ uVar22 ^ uVar20) +
             (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar10 + 0xca62c1d6 + uVar14;
    uVar17 = uVar20 * 0x40000000 | uVar20 >> 2;
    uVar20 = uVar19 ^ uVar16 ^ uVar13 ^ uVar4;
    uVar10 = uVar20 << 1 | (uint)((int)uVar20 < 0);
    uVar8 = (uVar22 ^ uVar17 ^ uVar3) +
            uVar24 + 0xca62c1d6 + uVar10 + (uVar11 * 0x20 | uVar11 >> 0x1b);
    uVar20 = uVar12 ^ uVar21 ^ uVar15 ^ uVar5;
    uVar20 = uVar20 << 1 | (uint)((int)uVar20 < 0);
    uVar18 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar3 = (uVar17 ^ uVar18 ^ uVar11) +
            uVar22 + 0xca62c1d6 + uVar20 + (uVar8 * 0x20 | uVar8 >> 0x1b);
    uVar11 = uVar11 * 0x40000000 | uVar11 >> 2;
    uVar16 = uVar16 ^ uVar1 ^ uVar25 ^ uVar14;
    uVar22 = uVar16 << 1 | (uint)((int)uVar16 < 0);
    uVar17 = (uVar11 ^ uVar18 ^ uVar8) +
             uVar17 + 0xca62c1d6 + uVar22 + (uVar3 * 0x20 | uVar3 >> 0x1b);
    uVar12 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar21 = uVar21 ^ uVar7 ^ uVar23 ^ uVar10;
    uVar16 = uVar21 << 1 | (uint)((int)uVar21 < 0);
    uVar8 = (uVar11 ^ uVar12 ^ uVar3) +
            uVar18 + 0xca62c1d6 + uVar16 + (uVar17 * 0x20 | uVar17 >> 0x1b);
    uVar21 = uVar1 ^ uVar9 ^ uVar6 ^ uVar20;
    uVar21 = uVar21 << 1 | (uint)((int)uVar21 < 0);
    uVar19 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar3 = (uVar12 ^ uVar19 ^ uVar17) +
            uVar11 + 0xca62c1d6 + uVar21 + (uVar8 * 0x20 | uVar8 >> 0x1b);
    uVar18 = uVar17 * 0x40000000 | uVar17 >> 2;
    uVar1 = uVar7 ^ uVar2 ^ uVar4 ^ uVar22;
    uVar17 = uVar1 << 1 | (uint)((int)uVar1 < 0);
    uVar7 = (uVar19 ^ uVar18 ^ uVar8) +
            uVar12 + 0xca62c1d6 + uVar17 + (uVar3 * 0x20 | uVar3 >> 0x1b);
    uVar11 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar1 = uVar9 ^ uVar13 ^ uVar5 ^ uVar16;
    uVar1 = uVar1 << 1 | (uint)((int)uVar1 < 0);
    uVar2 = uVar2 ^ uVar15 ^ uVar14 ^ uVar21;
    uVar12 = uVar2 << 1 | (uint)((int)uVar2 < 0);
    uVar2 = (uVar18 ^ uVar11 ^ uVar3) + uVar19 + 0xca62c1d6 + uVar1 + (uVar7 * 0x20 | uVar7 >> 0x1b)
    ;
    uVar9 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar3 = (uVar11 ^ uVar9 ^ uVar7) + uVar18 + 0xca62c1d6 + uVar12 + (uVar2 * 0x20 | uVar2 >> 0x1b)
    ;
    uVar18 = uVar7 * 0x40000000 | uVar7 >> 2;
    uVar8 = uVar13 ^ uVar25 ^ uVar10 ^ uVar17;
    uVar8 = uVar8 << 1 | (uint)((int)uVar8 < 0);
    uVar7 = (uVar9 ^ uVar18 ^ uVar2) + uVar11 + 0xca62c1d6 + uVar8 + (uVar3 * 0x20 | uVar3 >> 0x1b);
    uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar20 = uVar15 ^ uVar23 ^ uVar20 ^ uVar1;
    uVar11 = uVar20 << 1 | (uint)((int)uVar20 < 0);
    uVar9 = (uVar2 ^ uVar18 ^ uVar3) + uVar9 + 0xca62c1d6 + uVar11 + (uVar7 * 0x20 | uVar7 >> 0x1b);
    uVar13 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar12 = uVar12 ^ uVar25 ^ uVar6 ^ uVar22;
    uVar12 = uVar12 << 1 | (uint)((int)uVar12 < 0);
    uVar3 = (uVar2 ^ uVar13 ^ uVar7) + uVar18 + 0xca62c1d6 + uVar12 + (uVar9 * 0x20 | uVar9 >> 0x1b)
    ;
    uVar8 = uVar23 ^ uVar4 ^ uVar16 ^ uVar8;
    uVar16 = uVar8 << 1 | (uint)((int)uVar8 < 0);
    uVar20 = uVar7 * 0x40000000 | uVar7 >> 2;
    uVar8 = uVar9 * 0x40000000 | uVar9 >> 2;
    uVar2 = (uVar13 ^ uVar20 ^ uVar9) + (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar2 + 0xca62c1d6 + uVar16
    ;
    uVar11 = uVar6 ^ uVar5 ^ uVar21 ^ uVar11;
    uVar6 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar3 = (uVar2 * 0x20 | uVar2 >> 0x1b) +
            uVar13 + 0xca62c1d6 + (uVar11 << 1 | (uint)((int)uVar11 < 0)) + (uVar8 ^ uVar20 ^ uVar3)
    ;
    uVar12 = uVar12 ^ uVar17 ^ uVar4 ^ uVar14;
    uVar21 = uVar20 + 0xca62c1d6 + (uVar12 << 1 | (uint)((int)uVar12 < 0)) +
             (uVar3 * 0x20 | uVar3 >> 0x1b) + (uVar6 ^ uVar8 ^ uVar2);
    uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar16 = uVar1 ^ uVar5 ^ uVar10 ^ uVar16;
    local_3c = local_3c + uVar21;
    local_78 = local_78 +
               (uVar21 * 0x20 | uVar21 >> 0x1b) +
               uVar8 + 0xca62c1d6 + (uVar16 << 1 | (uint)((int)uVar16 < 0)) +
               (uVar6 ^ uVar2 ^ uVar3);
    local_74 = local_74 + (uVar3 * 0x40000000 | uVar3 >> 2);
    *param_1 = local_78;
    param_1[1] = local_3c;
    param_1[2] = local_74;
    local_70 = local_70 + uVar2;
    local_1c = local_1c + uVar6;
    local_14 = local_14 + -1;
    param_1[3] = local_70;
    param_1[4] = local_1c;
    local_84 = local_84 + 0x10;
  } while (local_14 != 0);
  return;
}

