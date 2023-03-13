
void __regparm3 sha_block_data_order(uint *param_1,uint *param_2,int param_3)

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
  uint uVar27;
  uint *local_80;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_34;
  uint local_1c;
  int local_14;
  
  local_78 = *param_1;
  local_34 = param_1[1];
  local_74 = param_1[2];
  local_70 = param_1[3];
  local_1c = param_1[4];
  local_80 = param_2;
  local_14 = param_3;
  do {
    uVar4 = *local_80;
    uVar3 = local_80[1];
    uVar22 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar1 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar4 = local_80[2];
    uVar23 = local_34 << 0x1e | local_34 >> 2;
    uVar15 = ((local_74 ^ local_70) & local_34 ^ local_70) +
             uVar22 + 0x5a827999 + (local_78 << 5 | local_78 >> 0x1b) + local_1c;
    uVar3 = local_80[3];
    uVar2 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar8 = local_70 + 0x5a827999 + uVar1 + (uVar15 * 0x20 | uVar15 >> 0x1b) +
            ((local_74 ^ uVar23) & local_78 ^ local_74);
    uVar6 = local_78 << 0x1e | local_78 >> 2;
    uVar5 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar3 = local_74 + 0x5a827999 + uVar2 + (uVar8 * 0x20 | uVar8 >> 0x1b) +
            ((uVar23 ^ uVar6) & uVar15 ^ uVar23);
    uVar10 = uVar15 * 0x40000000 | uVar15 >> 2;
    uVar4 = local_80[4];
    uVar16 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar15 = (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar23 + 0x5a827999 + uVar5 +
             ((uVar6 ^ uVar10) & uVar8 ^ uVar6);
    uVar23 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar4 = local_80[5];
    uVar17 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar8 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar24 = (uVar15 * 0x20 | uVar15 >> 0x1b) + uVar6 + 0x5a827999 + uVar16 +
             ((uVar10 ^ uVar23) & uVar3 ^ uVar10);
    uVar4 = local_80[6];
    uVar7 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar3 = (uVar24 * 0x20 | uVar24 >> 0x1b) + uVar10 + 0x5a827999 + uVar17 +
            ((uVar23 ^ uVar8) & uVar15 ^ uVar23);
    uVar6 = uVar15 * 0x40000000 | uVar15 >> 2;
    uVar4 = local_80[7];
    uVar15 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar10 = uVar24 * 0x40000000 | uVar24 >> 2;
    uVar23 = (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar23 + 0x5a827999 + uVar7 +
             ((uVar8 ^ uVar6) & uVar24 ^ uVar8);
    uVar4 = local_80[8];
    uVar11 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar24 = (uVar23 * 0x20 | uVar23 >> 0x1b) + uVar8 + 0x5a827999 + uVar15 +
             ((uVar6 ^ uVar10) & uVar3 ^ uVar6);
    uVar4 = local_80[9];
    uVar8 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar12 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar18 = uVar23 * 0x40000000 | uVar23 >> 2;
    uVar3 = (uVar24 * 0x20 | uVar24 >> 0x1b) + uVar6 + 0x5a827999 + uVar11 +
            (uVar23 & (uVar10 ^ uVar8) ^ uVar10);
    uVar4 = local_80[10];
    uVar6 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar23 = (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar10 + 0x5a827999 + uVar12 +
             ((uVar8 ^ uVar18) & uVar24 ^ uVar8);
    uVar4 = local_80[0xb];
    uVar10 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar9 = uVar24 * 0x40000000 | uVar24 >> 2;
    uVar25 = (uVar23 * 0x20 | uVar23 >> 0x1b) + uVar8 + 0x5a827999 + uVar6 +
             ((uVar18 ^ uVar9) & uVar3 ^ uVar18);
    uVar8 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar4 = local_80[0xc];
    uVar24 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar4 = (uVar25 * 0x20 | uVar25 >> 0x1b) + uVar18 + 0x5a827999 + uVar10 +
            ((uVar9 ^ uVar8) & uVar23 ^ uVar9);
    uVar23 = uVar23 * 0x40000000 | uVar23 >> 2;
    uVar3 = local_80[0xd];
    uVar19 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar20 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar9 + 0x5a827999 + uVar24 +
             ((uVar8 ^ uVar23) & uVar25 ^ uVar8);
    uVar25 = uVar25 * 0x40000000 | uVar25 >> 2;
    uVar3 = local_80[0xe];
    uVar18 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
    uVar9 = uVar4 * 0x40000000 | uVar4 >> 2;
    uVar3 = (uVar20 * 0x20 | uVar20 >> 0x1b) + uVar8 + 0x5a827999 + uVar19 +
            (uVar4 & (uVar23 ^ uVar25) ^ uVar23);
    uVar4 = local_80[0xf];
    local_80 = local_80 + 0x10;
    uVar13 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
    uVar21 = uVar20 * 0x40000000 | uVar20 >> 2;
    uVar4 = (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar23 + 0x5a827999 + uVar18 +
            ((uVar25 ^ uVar9) & uVar20 ^ uVar25);
    uVar20 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar8 = ((uVar9 ^ uVar21) & uVar3 ^ uVar9) +
            (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar25 + 0x5a827999 + uVar13;
    uVar25 = uVar11 ^ uVar22 ^ uVar2 ^ uVar19;
    uVar3 = uVar4 * 0x40000000 | uVar4 >> 2;
    uVar4 = uVar9 + 0x5a827999 + (uVar8 * 0x20 | uVar8 >> 0x1b) + uVar25 +
            ((uVar21 ^ uVar20) & uVar4 ^ uVar21);
    uVar22 = uVar1 ^ uVar5 ^ uVar12 ^ uVar18;
    uVar23 = uVar21 + 0x5a827999 + (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar22 +
             ((uVar20 ^ uVar3) & uVar8 ^ uVar20);
    uVar1 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar21 = uVar6 ^ uVar2 ^ uVar16 ^ uVar13;
    uVar2 = uVar20 + 0x5a827999 + (uVar23 * 0x20 | uVar23 >> 0x1b) + uVar21 +
            ((uVar3 ^ uVar1) & uVar4 ^ uVar3);
    uVar9 = uVar4 * 0x40000000 | uVar4 >> 2;
    uVar14 = uVar5 ^ uVar17 ^ uVar10 ^ uVar25;
    uVar4 = uVar16 ^ uVar7 ^ uVar24 ^ uVar22;
    uVar8 = uVar3 + 0x5a827999 + (uVar2 * 0x20 | uVar2 >> 0x1b) + uVar14 +
            ((uVar1 ^ uVar9) & uVar23 ^ uVar1);
    uVar5 = uVar23 * 0x40000000 | uVar23 >> 2;
    uVar3 = (uVar9 ^ uVar5 ^ uVar2) + uVar1 + 0x6ed9eba1 + (uVar8 * 0x20 | uVar8 >> 0x1b) + uVar4;
    uVar1 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar2 = uVar21 ^ uVar19 ^ uVar17 ^ uVar15;
    uVar9 = (uVar1 ^ uVar5 ^ uVar8) + uVar9 + 0x6ed9eba1 + (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar2;
    uVar23 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar8 = uVar14 ^ uVar7 ^ uVar11 ^ uVar18;
    uVar5 = (uVar1 ^ uVar23 ^ uVar3) + uVar5 + 0x6ed9eba1 + (uVar9 * 0x20 | uVar9 >> 0x1b) + uVar8;
    uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar16 = uVar13 ^ uVar15 ^ uVar12 ^ uVar4;
    uVar20 = uVar9 * 0x40000000 | uVar9 >> 2;
    uVar7 = (uVar23 ^ uVar3 ^ uVar9) + uVar16 + uVar1 + 0x6ed9eba1 + (uVar5 * 0x20 | uVar5 >> 0x1b);
    uVar17 = uVar2 ^ uVar25 ^ uVar11 ^ uVar6;
    uVar15 = (uVar20 ^ uVar3 ^ uVar5) +
             uVar23 + 0x6ed9eba1 + (uVar7 * 0x20 | uVar7 >> 0x1b) + uVar17;
    uVar1 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar26 = uVar8 ^ uVar22 ^ uVar12 ^ uVar10;
    uVar3 = (uVar20 ^ uVar1 ^ uVar7) +
            uVar3 + 0x6ed9eba1 + (uVar15 * 0x20 | uVar15 >> 0x1b) + uVar26;
    uVar23 = uVar7 * 0x40000000 | uVar7 >> 2;
    uVar27 = uVar16 ^ uVar21 ^ uVar6 ^ uVar24;
    uVar6 = (uVar1 ^ uVar23 ^ uVar15) +
            uVar27 + uVar20 + 0x6ed9eba1 + (uVar3 * 0x20 | uVar3 >> 0x1b);
    uVar5 = uVar15 * 0x40000000 | uVar15 >> 2;
    uVar9 = uVar17 ^ uVar14 ^ uVar10 ^ uVar19;
    uVar1 = (uVar5 ^ uVar23 ^ uVar3) + uVar1 + 0x6ed9eba1 + (uVar6 * 0x20 | uVar6 >> 0x1b) + uVar9;
    uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar24 = uVar26 ^ uVar24 ^ uVar18 ^ uVar4;
    uVar15 = (uVar5 ^ uVar3 ^ uVar6) + uVar23 + 0x6ed9eba1 + (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar24
    ;
    uVar6 = uVar6 * 0x40000000 | uVar6 >> 2;
    uVar20 = uVar27 ^ uVar19 ^ uVar13 ^ uVar2;
    uVar5 = (uVar3 ^ uVar6 ^ uVar1) + uVar20 + uVar5 + 0x6ed9eba1 + (uVar15 * 0x20 | uVar15 >> 0x1b)
    ;
    uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
    uVar23 = uVar9 ^ uVar18 ^ uVar25 ^ uVar8;
    uVar3 = (uVar1 ^ uVar6 ^ uVar15) + uVar3 + 0x6ed9eba1 + (uVar5 * 0x20 | uVar5 >> 0x1b) + uVar23;
    uVar15 = uVar15 * 0x40000000 | uVar15 >> 2;
    uVar10 = uVar24 ^ uVar13 ^ uVar22 ^ uVar16;
    uVar18 = (uVar1 ^ uVar15 ^ uVar5) + uVar6 + 0x6ed9eba1 + (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar10
    ;
    uVar6 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar7 = uVar20 ^ uVar25 ^ uVar21 ^ uVar17;
    uVar1 = (uVar15 ^ uVar6 ^ uVar3) + uVar7 + uVar1 + 0x6ed9eba1 + (uVar18 * 0x20 | uVar18 >> 0x1b)
    ;
    uVar3 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar5 = uVar23 ^ uVar22 ^ uVar14 ^ uVar26;
    uVar11 = (uVar3 ^ uVar6 ^ uVar18) + uVar15 + 0x6ed9eba1 + (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar5
    ;
    uVar12 = uVar18 * 0x40000000 | uVar18 >> 2;
    uVar15 = uVar10 ^ uVar21 ^ uVar4 ^ uVar27;
    uVar18 = (uVar3 ^ uVar12 ^ uVar1) +
             uVar6 + 0x6ed9eba1 + (uVar11 * 0x20 | uVar11 >> 0x1b) + uVar15;
    uVar1 = uVar1 * 0x40000000 | uVar1 >> 2;
    uVar6 = uVar7 ^ uVar14 ^ uVar2 ^ uVar9;
    uVar3 = (uVar12 ^ uVar1 ^ uVar11) +
            uVar6 + uVar3 + 0x6ed9eba1 + (uVar18 * 0x20 | uVar18 >> 0x1b);
    uVar13 = uVar11 * 0x40000000 | uVar11 >> 2;
    uVar11 = uVar5 ^ uVar4 ^ uVar8 ^ uVar24;
    uVar22 = (uVar1 ^ uVar13 ^ uVar18) +
             uVar11 + uVar12 + 0x6ed9eba1 + (uVar3 * 0x20 | uVar3 >> 0x1b);
    uVar18 = uVar18 * 0x40000000 | uVar18 >> 2;
    uVar12 = uVar15 ^ uVar20 ^ uVar2 ^ uVar16;
    uVar1 = (uVar13 ^ uVar18 ^ uVar3) +
            uVar12 + uVar1 + 0x6ed9eba1 + (uVar22 * 0x20 | uVar22 >> 0x1b);
    uVar4 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar25 = uVar8 ^ uVar17 ^ uVar23 ^ uVar6;
    uVar3 = (uVar4 ^ uVar18 ^ uVar22) +
            uVar25 + uVar13 + 0x6ed9eba1 + (uVar1 * 0x20 | uVar1 >> 0x1b);
    uVar8 = uVar22 * 0x40000000 | uVar22 >> 2;
    uVar13 = uVar16 ^ uVar26 ^ uVar10 ^ uVar11;
    uVar22 = uVar27 ^ uVar17 ^ uVar7 ^ uVar12;
    uVar21 = (uVar4 ^ uVar8 ^ uVar1) + uVar13 + uVar18 + 0x6ed9eba1 + (uVar3 * 0x20 | uVar3 >> 0x1b)
    ;
    uVar2 = uVar1 * 0x40000000 | uVar1 >> 2;
    uVar1 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar18 = uVar9 ^ uVar26 ^ uVar5 ^ uVar25;
    uVar4 = ((uVar3 | uVar2) & uVar8 | uVar3 & uVar2) +
            uVar4 + 0x8f1bbcdc + (uVar21 * 0x20 | uVar21 >> 0x1b) + uVar22;
    uVar3 = ((uVar21 | uVar1) & uVar2 | uVar21 & uVar1) +
            uVar8 + 0x8f1bbcdc + (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar18;
    uVar14 = uVar21 * 0x40000000 | uVar21 >> 2;
    uVar21 = uVar13 ^ uVar27 ^ uVar24 ^ uVar15;
    uVar26 = uVar22 ^ uVar9 ^ uVar20 ^ uVar6;
    uVar8 = (uVar14 & uVar4 | (uVar14 | uVar4) & uVar1) +
            uVar2 + 0x8f1bbcdc + (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar21;
    uVar2 = uVar4 * 0x40000000 | uVar4 >> 2;
    uVar4 = uVar11 ^ uVar24 ^ uVar23 ^ uVar18;
    uVar1 = (uVar3 & uVar2 | uVar14 & (uVar3 | uVar2)) +
            uVar1 + 0x8f1bbcdc + (uVar8 * 0x20 | uVar8 >> 0x1b) + uVar26;
    uVar9 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar3 = (uVar8 & uVar9 | (uVar8 | uVar9) & uVar2) +
            uVar14 + 0x8f1bbcdc + (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar4;
    uVar24 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar14 = uVar21 ^ uVar20 ^ uVar10 ^ uVar12;
    uVar20 = uVar1 * 0x40000000 | uVar1 >> 2;
    uVar1 = (uVar24 & uVar1 | (uVar24 | uVar1) & uVar9) +
            uVar2 + 0x8f1bbcdc + (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar14;
    uVar16 = uVar23 ^ uVar7 ^ uVar25 ^ uVar26;
    uVar23 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar8 = (uVar3 & uVar20 | (uVar3 | uVar20) & uVar24) +
            uVar9 + 0x8f1bbcdc + (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar16;
    uVar9 = uVar4 ^ uVar13 ^ uVar10 ^ uVar5;
    uVar2 = uVar1 * 0x40000000 | uVar1 >> 2;
    uVar3 = (uVar1 & uVar23 | (uVar1 | uVar23) & uVar20) +
            uVar24 + 0x8f1bbcdc + (uVar8 * 0x20 | uVar8 >> 0x1b) + uVar9;
    uVar17 = uVar7 ^ uVar15 ^ uVar22 ^ uVar14;
    uVar10 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar1 = (uVar2 & uVar8 | (uVar2 | uVar8) & uVar23) +
            uVar20 + 0x8f1bbcdc + (uVar3 * 0x20 | uVar3 >> 0x1b) + uVar17;
    uVar7 = uVar16 ^ uVar5 ^ uVar6 ^ uVar18;
    uVar20 = uVar3 * 0x40000000 | uVar3 >> 2;
    uVar23 = (uVar3 & uVar10 | uVar2 & (uVar3 | uVar10)) +
             uVar23 + 0x8f1bbcdc + (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar7;
    uVar3 = uVar21 ^ uVar15 ^ uVar11 ^ uVar9;
    uVar8 = uVar1 * 0x40000000 | uVar1 >> 2;
    uVar1 = (uVar1 & uVar20 | (uVar1 | uVar20) & uVar10) +
            uVar2 + 0x8f1bbcdc + (uVar23 * 0x20 | uVar23 >> 0x1b) + uVar3;
    uVar5 = uVar17 ^ uVar6 ^ uVar12 ^ uVar26;
    uVar24 = uVar23 * 0x40000000 | uVar23 >> 2;
    uVar2 = (uVar8 & uVar23 | (uVar8 | uVar23) & uVar20) +
            uVar10 + 0x8f1bbcdc + (uVar1 * 0x20 | uVar1 >> 0x1b) + uVar5;
    uVar19 = uVar7 ^ uVar11 ^ uVar25 ^ uVar4;
    uVar23 = uVar1 * 0x40000000 | uVar1 >> 2;
    uVar6 = (uVar1 & uVar24 | uVar8 & (uVar1 | uVar24)) +
            uVar20 + 0x8f1bbcdc + (uVar2 * 0x20 | uVar2 >> 0x1b) + uVar19;
    uVar1 = uVar14 ^ uVar12 ^ uVar13 ^ uVar3;
    uVar15 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar2 = (uVar2 & uVar23 | (uVar2 | uVar23) & uVar24) +
            uVar8 + 0x8f1bbcdc + (uVar6 * 0x20 | uVar6 >> 0x1b) + uVar1;
    uVar25 = uVar25 ^ uVar22 ^ uVar16 ^ uVar5;
    uVar20 = uVar6 * 0x40000000 | uVar6 >> 2;
    uVar8 = (uVar15 & uVar6 | (uVar15 | uVar6) & uVar23) +
            uVar24 + 0x8f1bbcdc + (uVar2 * 0x20 | uVar2 >> 0x1b) + uVar25;
    uVar13 = uVar19 ^ uVar13 ^ uVar18 ^ uVar9;
    uVar23 = (uVar2 & uVar20 | uVar15 & (uVar2 | uVar20)) +
             uVar23 + 0x8f1bbcdc + (uVar8 * 0x20 | uVar8 >> 0x1b) + uVar13;
    uVar11 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar24 = uVar1 ^ uVar17 ^ uVar22 ^ uVar21;
    uVar6 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar2 = (uVar8 & uVar11 | (uVar8 | uVar11) & uVar20) +
            uVar15 + 0x8f1bbcdc + (uVar23 * 0x20 | uVar23 >> 0x1b) + uVar24;
    uVar22 = uVar25 ^ uVar18 ^ uVar26 ^ uVar7;
    uVar10 = uVar23 * 0x40000000 | uVar23 >> 2;
    uVar18 = uVar3 ^ uVar21 ^ uVar4 ^ uVar13;
    uVar8 = ((uVar6 | uVar23) & uVar11 | uVar6 & uVar23) +
            uVar20 + 0x8f1bbcdc + (uVar2 * 0x20 | uVar2 >> 0x1b) + uVar22;
    uVar23 = (uVar6 & (uVar2 | uVar10) | uVar2 & uVar10) +
             uVar11 + 0x8f1bbcdc + (uVar8 * 0x20 | uVar8 >> 0x1b) + uVar18;
    uVar21 = uVar26 ^ uVar14 ^ uVar5 ^ uVar24;
    uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar15 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar6 = (uVar8 & uVar2 | (uVar8 | uVar2) & uVar10) +
            uVar6 + 0x8f1bbcdc + (uVar23 * 0x20 | uVar23 >> 0x1b) + uVar21;
    uVar20 = uVar22 ^ uVar4 ^ uVar16 ^ uVar19;
    uVar11 = uVar14 ^ uVar9 ^ uVar1 ^ uVar18;
    uVar10 = (uVar2 ^ uVar15 ^ uVar23) +
             uVar20 + uVar10 + 0xca62c1d6 + (uVar6 * 0x20 | uVar6 >> 0x1b);
    uVar8 = uVar23 * 0x40000000 | uVar23 >> 2;
    uVar2 = (uVar15 ^ uVar8 ^ uVar6) +
            uVar11 + uVar2 + 0xca62c1d6 + (uVar10 * 0x20 | uVar10 >> 0x1b);
    uVar12 = uVar6 * 0x40000000 | uVar6 >> 2;
    uVar23 = uVar16 ^ uVar17 ^ uVar25 ^ uVar21;
    uVar4 = (uVar8 ^ uVar12 ^ uVar10) +
            uVar23 + uVar15 + 0xca62c1d6 + (uVar2 * 0x20 | uVar2 >> 0x1b);
    uVar16 = uVar10 * 0x40000000 | uVar10 >> 2;
    uVar10 = uVar13 ^ uVar9 ^ uVar7 ^ uVar20;
    uVar9 = uVar17 ^ uVar3 ^ uVar24 ^ uVar11;
    uVar8 = (uVar12 ^ uVar16 ^ uVar2) + uVar10 + uVar8 + 0xca62c1d6 + (uVar4 * 0x20 | uVar4 >> 0x1b)
    ;
    uVar6 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar15 = (uVar16 ^ uVar6 ^ uVar4) + uVar9 + uVar12 + 0xca62c1d6 + (uVar8 * 0x20 | uVar8 >> 0x1b)
    ;
    uVar14 = uVar4 * 0x40000000 | uVar4 >> 2;
    uVar4 = uVar23 ^ uVar7 ^ uVar5 ^ uVar22;
    uVar2 = (uVar6 ^ uVar14 ^ uVar8) +
            uVar4 + uVar16 + 0xca62c1d6 + (uVar15 * 0x20 | uVar15 >> 0x1b);
    uVar16 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar7 = uVar10 ^ uVar3 ^ uVar19 ^ uVar18;
    uVar12 = uVar5 ^ uVar1 ^ uVar21 ^ uVar9;
    uVar8 = (uVar14 ^ uVar16 ^ uVar15) + uVar7 + uVar6 + 0xca62c1d6 + (uVar2 * 0x20 | uVar2 >> 0x1b)
    ;
    uVar15 = uVar15 * 0x40000000 | uVar15 >> 2;
    uVar5 = (uVar16 ^ uVar15 ^ uVar2) +
            uVar12 + uVar14 + 0xca62c1d6 + (uVar8 * 0x20 | uVar8 >> 0x1b);
    uVar6 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar3 = uVar20 ^ uVar19 ^ uVar25 ^ uVar4;
    uVar2 = (uVar6 ^ uVar15 ^ uVar8) + uVar3 + uVar16 + 0xca62c1d6 + (uVar5 * 0x20 | uVar5 >> 0x1b);
    uVar17 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar14 = uVar7 ^ uVar1 ^ uVar13 ^ uVar11;
    uVar8 = (uVar17 ^ uVar6 ^ uVar5) + uVar15 + 0xca62c1d6 + (uVar2 * 0x20 | uVar2 >> 0x1b) + uVar14
    ;
    uVar15 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar16 = uVar12 ^ uVar25 ^ uVar24 ^ uVar23;
    uVar5 = (uVar17 ^ uVar15 ^ uVar2) + uVar16 + uVar6 + 0xca62c1d6 + (uVar8 * 0x20 | uVar8 >> 0x1b)
    ;
    uVar2 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar25 = uVar3 ^ uVar10 ^ uVar13 ^ uVar22;
    uVar1 = (uVar15 ^ uVar2 ^ uVar8) + uVar25 + uVar17 + 0xca62c1d6 + (uVar5 * 0x20 | uVar5 >> 0x1b)
    ;
    uVar17 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar24 = uVar14 ^ uVar24 ^ uVar18 ^ uVar9;
    uVar8 = (uVar2 ^ uVar17 ^ uVar5) + uVar24 + uVar15 + 0xca62c1d6 + (uVar1 * 0x20 | uVar1 >> 0x1b)
    ;
    uVar15 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar6 = uVar16 ^ uVar22 ^ uVar21 ^ uVar4;
    uVar5 = (uVar17 ^ uVar15 ^ uVar1) + uVar6 + uVar2 + 0xca62c1d6 + (uVar8 * 0x20 | uVar8 >> 0x1b);
    uVar13 = uVar1 * 0x40000000 | uVar1 >> 2;
    uVar1 = uVar7 ^ uVar18 ^ uVar20 ^ uVar25;
    uVar2 = (uVar15 ^ uVar13 ^ uVar8) + uVar1 + uVar17 + 0xca62c1d6 + (uVar5 * 0x20 | uVar5 >> 0x1b)
    ;
    uVar8 = uVar8 * 0x40000000 | uVar8 >> 2;
    uVar24 = uVar24 ^ uVar21 ^ uVar11 ^ uVar12;
    uVar7 = (uVar13 ^ uVar8 ^ uVar5) + uVar24 + uVar15 + 0xca62c1d6 + (uVar2 * 0x20 | uVar2 >> 0x1b)
    ;
    uVar5 = uVar5 * 0x40000000 | uVar5 >> 2;
    uVar6 = uVar6 ^ uVar20 ^ uVar23 ^ uVar3;
    uVar15 = (uVar8 ^ uVar5 ^ uVar2) + uVar13 + 0xca62c1d6 + (uVar7 * 0x20 | uVar7 >> 0x1b) + uVar6;
    uVar3 = uVar2 * 0x40000000 | uVar2 >> 2;
    uVar1 = (uVar5 ^ uVar3 ^ uVar7) +
            uVar8 + 0xca62c1d6 + (uVar15 * 0x20 | uVar15 >> 0x1b) +
            (uVar11 ^ uVar10 ^ uVar14 ^ uVar1);
    uVar8 = uVar7 * 0x40000000 | uVar7 >> 2;
    uVar5 = (uVar3 ^ uVar8 ^ uVar15) +
            uVar5 + 0xca62c1d6 + (uVar1 * 0x20 | uVar1 >> 0x1b) + (uVar23 ^ uVar9 ^ uVar16 ^ uVar24)
    ;
    uVar2 = uVar15 * 0x40000000 | uVar15 >> 2;
    local_78 = local_78 +
               (uVar6 ^ uVar10 ^ uVar4 ^ uVar25) +
               uVar3 + 0xca62c1d6 + (uVar5 * 0x20 | uVar5 >> 0x1b) + (uVar8 ^ uVar2 ^ uVar1);
    local_34 = local_34 + uVar5;
    local_74 = local_74 + (uVar1 * 0x40000000 | uVar1 >> 2);
    *param_1 = local_78;
    param_1[1] = local_34;
    param_1[2] = local_74;
    local_70 = local_70 + uVar2;
    local_1c = local_1c + uVar8;
    local_14 = local_14 + -1;
    param_1[3] = local_70;
    param_1[4] = local_1c;
  } while (local_14 != 0);
  return;
}

