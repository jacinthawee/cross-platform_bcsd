
void sha_block_data_order(uint *param_1,byte *param_2,int param_3)

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
  byte *local_94;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_40;
  uint local_3c;
  int local_30;
  
  local_4c = *param_1;
  local_40 = param_1[1];
  local_50 = param_1[2];
  local_48 = param_1[3];
  local_3c = param_1[4];
  local_94 = param_2;
  local_30 = param_3;
  do {
    uVar24 = (uint)local_94[1] << 0x10 | (uint)*local_94 << 0x18 | (uint)local_94[3] |
             (uint)local_94[2] << 8;
    uVar1 = local_40 >> 2 | local_40 << 0x1e;
    uVar4 = ((local_48 ^ local_50) & local_40 ^ local_48) +
            (local_4c >> 0x1b | local_4c << 5) + 0x5a827999 + uVar24 + local_3c;
    uVar22 = (uint)local_94[5] << 0x10 | (uint)local_94[4] << 0x18 | (uint)local_94[7] |
             (uint)local_94[6] << 8;
    uVar9 = (uint)local_94[9] << 0x10 | (uint)local_94[8] << 0x18 | (uint)local_94[0xb] |
            (uint)local_94[10] << 8;
    uVar11 = local_4c >> 2 | local_4c << 0x1e;
    uVar5 = ((local_50 ^ uVar1) & local_4c ^ local_50) + local_48 + 0x5a827999 + uVar22 +
            (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar2 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar17 = (uint)local_94[0xd] << 0x10 | (uint)local_94[0xc] << 0x18 | (uint)local_94[0xf] |
             (uint)local_94[0xe] << 8;
    uVar7 = (uint)local_94[0x11] << 0x10 | (uint)local_94[0x10] << 0x18 | (uint)local_94[0x13] |
            (uint)local_94[0x12] << 8;
    uVar25 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar4 = (uVar4 & (uVar11 ^ uVar1) ^ uVar1) + local_50 + 0x5a827999 + uVar9 +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar18 = (uint)local_94[0x15] << 0x10 | (uint)local_94[0x14] << 0x18 | (uint)local_94[0x17] |
             (uint)local_94[0x16] << 8;
    uVar5 = ((uVar2 ^ uVar11) & uVar5 ^ uVar11) + uVar1 + 0x5a827999 + uVar17 +
            (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar1 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar6 = ((uVar25 ^ uVar2) & uVar4 ^ uVar2) + uVar11 + 0x5a827999 + uVar7 +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar11 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar12 = (uint)local_94[0x19] << 0x10 | (uint)local_94[0x18] << 0x18 | (uint)local_94[0x1b] |
             (uint)local_94[0x1a] << 8;
    uVar4 = uVar2 + uVar18 + 0x5a827999 + ((uVar1 ^ uVar25) & uVar5 ^ uVar25) +
            (uVar6 >> 0x1b | uVar6 * 0x20);
    uVar2 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar5 = (uint)local_94[0x1d] << 0x10 | (uint)local_94[0x1c] << 0x18 | (uint)local_94[0x1f] |
            (uint)local_94[0x1e] << 8;
    uVar8 = (uint)local_94[0x21] << 0x10 | (uint)local_94[0x20] << 0x18 | (uint)local_94[0x23] |
            (uint)local_94[0x22] << 8;
    uVar13 = ((uVar11 ^ uVar1) & uVar6 ^ uVar1) + uVar12 + 0x5a827999 + uVar25 +
             (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar25 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar6 = uVar1 + uVar5 + 0x5a827999 + ((uVar2 ^ uVar11) & uVar4 ^ uVar11) +
            (uVar13 >> 0x1b | uVar13 * 0x20);
    uVar1 = uVar13 >> 2 | uVar13 * 0x40000000;
    uVar23 = (uint)local_94[0x25] << 0x10 | (uint)local_94[0x24] << 0x18 | (uint)local_94[0x27] |
             (uint)local_94[0x26] << 8;
    uVar4 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar13 = uVar11 + uVar8 + 0x5a827999 + ((uVar25 ^ uVar2) & uVar13 ^ uVar2) +
             (uVar6 >> 0x1b | uVar6 * 0x20);
    uVar14 = (uint)local_94[0x29] << 0x10 | (uint)local_94[0x28] << 0x18 | (uint)local_94[0x2b] |
             (uint)local_94[0x2a] << 8;
    uVar6 = uVar2 + uVar23 + 0x5a827999 + ((uVar1 ^ uVar25) & uVar6 ^ uVar25) +
            (uVar13 >> 0x1b | uVar13 * 0x20);
    uVar11 = uVar13 >> 2 | uVar13 * 0x40000000;
    uVar15 = (uint)local_94[0x2f] | (uint)local_94[0x2d] << 0x10 | (uint)local_94[0x2c] << 0x18 |
             (uint)local_94[0x2e] << 8;
    uVar25 = uVar25 + uVar14 + 0x5a827999 + ((uVar4 ^ uVar1) & uVar13 ^ uVar1) +
             (uVar6 >> 0x1b | uVar6 * 0x20);
    uVar2 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar13 = (uint)local_94[0x31] << 0x10 | (uint)local_94[0x30] << 0x18 | (uint)local_94[0x33] |
             (uint)local_94[0x32] << 8;
    uVar19 = (uint)local_94[0x35] << 0x10 | (uint)local_94[0x34] << 0x18 | (uint)local_94[0x37] |
             (uint)local_94[0x36] << 8;
    uVar6 = uVar1 + uVar15 + 0x5a827999 + ((uVar11 ^ uVar4) & uVar6 ^ uVar4) +
            (uVar25 >> 0x1b | uVar25 * 0x20);
    uVar1 = uVar25 >> 2 | uVar25 * 0x40000000;
    uVar3 = (uint)local_94[0x39] << 0x10 | (uint)local_94[0x38] << 0x18 | (uint)local_94[0x3b] |
            (uint)local_94[0x3a] << 8;
    uVar10 = ((uVar2 ^ uVar11) & uVar25 ^ uVar11) + uVar4 + uVar13 + 0x5a827999 +
             (uVar6 >> 0x1b | uVar6 * 0x20);
    uVar25 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar6 = uVar11 + uVar19 + 0x5a827999 + ((uVar1 ^ uVar2) & uVar6 ^ uVar2) +
            (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar11 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar16 = (uint)local_94[0x3d] << 0x10 | (uint)local_94[0x3c] << 0x18 | (uint)local_94[0x3f] |
             (uint)local_94[0x3e] << 8;
    uVar24 = uVar9 ^ uVar24 ^ uVar8 ^ uVar19;
    uVar4 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar2 = uVar2 + uVar3 + 0x5a827999 + ((uVar25 ^ uVar1) & uVar10 ^ uVar1) +
            (uVar6 >> 0x1b | uVar6 * 0x20);
    uVar6 = ((uVar11 ^ uVar25) & uVar6 ^ uVar25) + uVar1 + uVar16 + 0x5a827999 +
            (uVar2 >> 0x1b | uVar2 * 0x20);
    uVar1 = uVar2 >> 2 | uVar2 * 0x40000000;
    uVar20 = uVar17 ^ uVar22 ^ uVar23 ^ uVar3;
    uVar22 = uVar7 ^ uVar9 ^ uVar14 ^ uVar16;
    uVar10 = ((uVar4 ^ uVar11) & uVar2 ^ uVar11) + uVar25 + uVar24 + 0x5a827999 +
             (uVar6 >> 0x1b | uVar6 * 0x20);
    uVar2 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar9 = uVar24 ^ uVar18 ^ uVar17 ^ uVar15;
    uVar17 = uVar12 ^ uVar7 ^ uVar13 ^ uVar20;
    uVar25 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar7 = uVar20 + 0x5a827999 + uVar11 + ((uVar1 ^ uVar4) & uVar6 ^ uVar4) +
            (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar21 = uVar5 ^ uVar18 ^ uVar19 ^ uVar22;
    uVar6 = uVar22 + 0x5a827999 + uVar4 + ((uVar2 ^ uVar1) & uVar10 ^ uVar1) +
            (uVar7 >> 0x1b | uVar7 * 0x20);
    uVar11 = uVar7 >> 2 | uVar7 * 0x40000000;
    uVar12 = uVar9 ^ uVar8 ^ uVar12 ^ uVar3;
    uVar4 = uVar9 + 0x5a827999 + uVar1 + ((uVar25 ^ uVar2) & uVar7 ^ uVar2) +
            (uVar6 >> 0x1b | uVar6 * 0x20);
    uVar18 = uVar17 ^ uVar23 ^ uVar5 ^ uVar16;
    uVar1 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar5 = uVar17 + 0x6ed9eba1 + uVar2 + (uVar11 ^ uVar25 ^ uVar6) + (uVar4 >> 0x1b | uVar4 * 0x20)
    ;
    uVar2 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar6 = uVar14 ^ uVar8 ^ uVar24 ^ uVar21;
    uVar8 = uVar25 + uVar21 + 0x6ed9eba1 + (uVar1 ^ uVar11 ^ uVar4) + (uVar5 >> 0x1b | uVar5 * 0x20)
    ;
    uVar25 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar4 = uVar11 + uVar12 + 0x6ed9eba1 + (uVar2 ^ uVar1 ^ uVar5) + (uVar8 >> 0x1b | uVar8 * 0x20);
    uVar7 = uVar12 ^ uVar15 ^ uVar23 ^ uVar20;
    uVar11 = uVar8 >> 2 | uVar8 * 0x40000000;
    uVar5 = uVar1 + uVar18 + 0x6ed9eba1 + (uVar25 ^ uVar2 ^ uVar8) + (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar14 = uVar18 ^ uVar13 ^ uVar14 ^ uVar22;
    uVar1 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar4 = uVar2 + uVar6 + 0x6ed9eba1 + (uVar11 ^ uVar25 ^ uVar4) + (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar2 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar15 = uVar6 ^ uVar19 ^ uVar15 ^ uVar9;
    uVar5 = uVar25 + uVar7 + 0x6ed9eba1 + (uVar1 ^ uVar11 ^ uVar5) + (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar25 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar8 = uVar7 ^ uVar3 ^ uVar13 ^ uVar17;
    uVar13 = uVar11 + uVar14 + 0x6ed9eba1 + (uVar2 ^ uVar1 ^ uVar4) + (uVar5 >> 0x1b | uVar5 * 0x20)
    ;
    uVar11 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar4 = uVar1 + uVar15 + 0x6ed9eba1 + (uVar25 ^ uVar2 ^ uVar5) +
            (uVar13 >> 0x1b | uVar13 * 0x20);
    uVar19 = uVar16 ^ uVar19 ^ uVar21 ^ uVar14;
    uVar1 = uVar13 >> 2 | uVar13 * 0x40000000;
    uVar10 = uVar24 ^ uVar3 ^ uVar12 ^ uVar15;
    uVar5 = uVar20 ^ uVar16 ^ uVar18 ^ uVar8;
    uVar3 = uVar2 + uVar8 + 0x6ed9eba1 + (uVar11 ^ uVar25 ^ uVar13) + (uVar4 >> 0x1b | uVar4 * 0x20)
    ;
    uVar2 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar4 = uVar25 + uVar19 + 0x6ed9eba1 + (uVar1 ^ uVar11 ^ uVar4) + (uVar3 >> 0x1b | uVar3 * 0x20)
    ;
    uVar25 = uVar3 >> 2 | uVar3 * 0x40000000;
    uVar13 = uVar22 ^ uVar24 ^ uVar6 ^ uVar19;
    uVar24 = (uVar2 ^ uVar1 ^ uVar3) + uVar11 + uVar10 + 0x6ed9eba1 + (uVar4 >> 0x1b | uVar4 * 0x20)
    ;
    uVar11 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar23 = (uVar25 ^ uVar2 ^ uVar4) + uVar5 + 0x6ed9eba1 + uVar1 +
             (uVar24 >> 0x1b | uVar24 * 0x20);
    uVar1 = uVar24 >> 2 | uVar24 * 0x40000000;
    uVar3 = uVar9 ^ uVar20 ^ uVar7 ^ uVar10;
    uVar16 = uVar21 ^ uVar9 ^ uVar15 ^ uVar13;
    uVar4 = uVar23 >> 2 | uVar23 * 0x40000000;
    uVar9 = uVar17 ^ uVar22 ^ uVar14 ^ uVar5;
    uVar22 = uVar12 ^ uVar17 ^ uVar8 ^ uVar3;
    uVar20 = uVar18 ^ uVar21 ^ uVar19 ^ uVar9;
    uVar17 = uVar16 ^ uVar6 ^ uVar12 ^ uVar10;
    uVar12 = uVar22 ^ uVar7 ^ uVar18 ^ uVar5;
    uVar21 = uVar14 ^ uVar6 ^ uVar13 ^ uVar20;
    uVar24 = (uVar11 ^ uVar25 ^ uVar24) + uVar13 + 0x6ed9eba1 + uVar2 +
             (uVar23 >> 0x1b | uVar23 * 0x20);
    uVar6 = (uVar1 ^ uVar11 ^ uVar23) + uVar25 + uVar3 + 0x6ed9eba1 +
            (uVar24 >> 0x1b | uVar24 * 0x20);
    uVar2 = uVar24 >> 2 | uVar24 * 0x40000000;
    uVar25 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar23 = uVar15 ^ uVar7 ^ uVar3 ^ uVar17;
    uVar18 = uVar12 ^ uVar8 ^ uVar14 ^ uVar9;
    uVar26 = uVar19 ^ uVar15 ^ uVar16 ^ uVar21;
    uVar14 = uVar23 ^ uVar8 ^ uVar10 ^ uVar22;
    uVar7 = uVar18 ^ uVar19 ^ uVar5 ^ uVar20;
    uVar15 = uVar14 ^ uVar5 ^ uVar3 ^ uVar12;
    uVar8 = uVar26 ^ uVar10 ^ uVar13 ^ uVar17;
    uVar10 = uVar7 ^ uVar13 ^ uVar9 ^ uVar21;
    uVar19 = uVar8 ^ uVar3 ^ uVar16 ^ uVar23;
    uVar11 = (uVar4 ^ uVar1 ^ uVar24) + uVar9 + 0x6ed9eba1 + uVar11 + (uVar6 >> 0x1b | uVar6 * 0x20)
    ;
    local_94 = local_94 + 0x40;
    uVar5 = (uVar2 ^ uVar4 ^ uVar6) + uVar16 + 0x6ed9eba1 + uVar1 + (uVar11 >> 0x1b | uVar11 * 0x20)
    ;
    uVar9 = uVar15 ^ uVar22 ^ uVar9 ^ uVar18;
    uVar1 = uVar11 >> 2 | uVar11 * 0x40000000;
    uVar6 = uVar22 + 0x6ed9eba1 + uVar4 + (uVar25 ^ uVar2 ^ uVar11) + (uVar5 >> 0x1b | uVar5 * 0x20)
    ;
    uVar11 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar4 = uVar2 + uVar20 + 0x6ed9eba1 + (uVar1 ^ uVar25 ^ uVar5) + (uVar6 >> 0x1b | uVar6 * 0x20);
    uVar2 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar5 = uVar25 + uVar17 + 0x6ed9eba1 + (uVar11 ^ uVar1 ^ uVar6) + (uVar4 >> 0x1b | uVar4 * 0x20)
    ;
    uVar25 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar4 = (uVar2 ^ uVar11 ^ uVar4) + uVar1 + uVar12 + 0x6ed9eba1 + (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar1 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar5 = uVar21 + 0x8f1bbcdc + uVar11 + (uVar4 >> 0x1b | uVar4 * 0x20) +
            (uVar5 & uVar25 | (uVar5 | uVar25) & uVar2);
    uVar11 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar4 = ((uVar4 | uVar1) & uVar25 | uVar4 & uVar1) + uVar23 + 0x8f1bbcdc + uVar2 +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar2 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar5 = uVar25 + uVar18 + 0x8f1bbcdc + (uVar4 >> 0x1b | uVar4 * 0x20) +
            ((uVar5 | uVar11) & uVar1 | uVar5 & uVar11);
    uVar25 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar6 = uVar1 + uVar26 + 0x8f1bbcdc + ((uVar4 | uVar2) & uVar11 | uVar4 & uVar2) +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar1 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar4 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar24 = uVar20 ^ uVar16 ^ uVar26 ^ uVar10;
    uVar16 = uVar19 ^ uVar17 ^ uVar22 ^ uVar14;
    uVar5 = uVar11 + uVar14 + 0x8f1bbcdc + (uVar6 >> 0x1b | uVar6 * 0x20) +
            (uVar5 & uVar25 | (uVar5 | uVar25) & uVar2);
    uVar11 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar6 = ((uVar6 | uVar1) & uVar25 | uVar6 & uVar1) + uVar2 + uVar7 + 0x8f1bbcdc +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar20 = uVar12 ^ uVar20 ^ uVar7 ^ uVar9;
    uVar2 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar27 = uVar23 ^ uVar12 ^ uVar15 ^ uVar16;
    uVar17 = uVar21 ^ uVar17 ^ uVar8 ^ uVar24;
    uVar25 = ((uVar5 | uVar4) & uVar1 | uVar5 & uVar4) +
             uVar25 + uVar8 + 0x8f1bbcdc + (uVar6 >> 0x1b | uVar6 * 0x20);
    uVar5 = ((uVar6 | uVar11) & uVar4 | uVar6 & uVar11) + uVar15 + 0x8f1bbcdc + uVar1 +
            (uVar25 >> 0x1b | uVar25 * 0x20);
    uVar1 = uVar25 >> 2 | uVar25 * 0x40000000;
    uVar21 = uVar18 ^ uVar21 ^ uVar10 ^ uVar20;
    uVar4 = ((uVar25 | uVar2) & uVar11 | uVar25 & uVar2) +
            uVar4 + uVar10 + 0x8f1bbcdc + (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar25 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar5 = uVar19 + 0x8f1bbcdc + uVar11 + ((uVar5 | uVar1) & uVar2 | uVar5 & uVar1) +
            (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar11 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar6 = uVar17 ^ uVar26 ^ uVar23 ^ uVar19;
    uVar13 = uVar27 ^ uVar14 ^ uVar18 ^ uVar9;
    uVar23 = uVar7 ^ uVar26 ^ uVar24 ^ uVar21;
    uVar3 = (uVar4 & uVar25 | (uVar4 | uVar25) & uVar1) +
            uVar2 + uVar9 + 0x8f1bbcdc + (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar2 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar5 = ((uVar5 | uVar11) & uVar25 | uVar5 & uVar11) + uVar1 + uVar24 + 0x8f1bbcdc +
            (uVar3 >> 0x1b | uVar3 * 0x20);
    uVar1 = uVar3 >> 2 | uVar3 * 0x40000000;
    uVar26 = uVar8 ^ uVar14 ^ uVar16 ^ uVar6;
    uVar4 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar22 = uVar13 ^ uVar15 ^ uVar7 ^ uVar20;
    uVar3 = (uVar3 & uVar2 | (uVar3 | uVar2) & uVar11) +
            uVar25 + uVar16 + 0x8f1bbcdc + (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar5 = uVar20 + 0x8f1bbcdc + uVar11 + ((uVar5 | uVar1) & uVar2 | uVar5 & uVar1) +
            (uVar3 >> 0x1b | uVar3 * 0x20);
    uVar11 = uVar3 >> 2 | uVar3 * 0x40000000;
    uVar25 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar8 = uVar23 ^ uVar10 ^ uVar8 ^ uVar17;
    uVar14 = uVar19 ^ uVar15 ^ uVar27 ^ uVar26;
    uVar12 = ((uVar3 | uVar4) & uVar1 | uVar3 & uVar4) +
             uVar2 + uVar17 + 0x8f1bbcdc + (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar7 = uVar27 + 0x8f1bbcdc + uVar1 + ((uVar5 | uVar11) & uVar4 | uVar5 & uVar11) +
            (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar1 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar2 = uVar7 >> 2 | uVar7 * 0x40000000;
    uVar3 = uVar22 ^ uVar9 ^ uVar10 ^ uVar21;
    uVar5 = ((uVar12 | uVar25) & uVar11 | uVar12 & uVar25) +
            uVar4 + uVar21 + 0x8f1bbcdc + (uVar7 >> 0x1b | uVar7 * 0x20);
    uVar15 = uVar24 ^ uVar19 ^ uVar6 ^ uVar8;
    uVar7 = uVar6 + 0x8f1bbcdc + uVar11 + ((uVar7 | uVar1) & uVar25 | uVar7 & uVar1) +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar11 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar19 = uVar16 ^ uVar9 ^ uVar13 ^ uVar14;
    uVar4 = uVar7 >> 2 | uVar7 * 0x40000000;
    uVar10 = uVar20 ^ uVar24 ^ uVar23 ^ uVar3;
    uVar5 = (uVar5 & uVar2 | (uVar5 | uVar2) & uVar1) +
            uVar25 + uVar13 + 0x8f1bbcdc + (uVar7 >> 0x1b | uVar7 * 0x20);
    uVar9 = uVar15 ^ uVar17 ^ uVar16 ^ uVar26;
    uVar12 = uVar23 + 0x8f1bbcdc + uVar1 + ((uVar7 | uVar11) & uVar2 | uVar7 & uVar11) +
             (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar1 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar25 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar18 = uVar2 + uVar26 + 0xca62c1d6 + (uVar4 ^ uVar11 ^ uVar5) +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar7 = uVar27 ^ uVar20 ^ uVar22 ^ uVar19;
    uVar2 = uVar18 >> 2 | uVar18 * 0x40000000;
    uVar5 = uVar22 + 0xca62c1d6 + uVar11 + (uVar1 ^ uVar4 ^ uVar12) +
            (uVar18 >> 0x1b | uVar18 * 0x20);
    uVar17 = uVar21 ^ uVar17 ^ uVar8 ^ uVar10;
    uVar11 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar4 = (uVar25 ^ uVar1 ^ uVar18) + uVar8 + 0xca62c1d6 + uVar4 + (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar16 = uVar6 ^ uVar27 ^ uVar14 ^ uVar9;
    uVar5 = (uVar2 ^ uVar25 ^ uVar5) + uVar1 + uVar14 + 0xca62c1d6 + (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar12 = uVar7 ^ uVar13 ^ uVar21 ^ uVar3;
    uVar1 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar4 = uVar3 + 0xca62c1d6 + uVar25 + (uVar11 ^ uVar2 ^ uVar4) + (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar25 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar6 = uVar17 ^ uVar23 ^ uVar6 ^ uVar15;
    uVar5 = uVar15 + 0xca62c1d6 + uVar2 + (uVar1 ^ uVar11 ^ uVar5) + (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar2 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar18 = uVar19 + 0xca62c1d6 + uVar11 + (uVar25 ^ uVar1 ^ uVar4) +
             (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar11 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar5 = uVar1 + uVar10 + 0xca62c1d6 + (uVar2 ^ uVar25 ^ uVar5) +
            (uVar18 >> 0x1b | uVar18 * 0x20);
    uVar1 = uVar18 >> 2 | uVar18 * 0x40000000;
    uVar4 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar19 = uVar26 ^ uVar13 ^ uVar19 ^ uVar16;
    uVar10 = uVar22 ^ uVar23 ^ uVar10 ^ uVar12;
    uVar25 = uVar9 + 0xca62c1d6 + uVar25 + (uVar11 ^ uVar2 ^ uVar18) +
             (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar5 = (uVar1 ^ uVar11 ^ uVar5) + uVar7 + 0xca62c1d6 + uVar2 + (uVar25 >> 0x1b | uVar25 * 0x20)
    ;
    uVar2 = uVar25 >> 2 | uVar25 * 0x40000000;
    uVar13 = uVar11 + uVar17 + 0xca62c1d6 + (uVar4 ^ uVar1 ^ uVar25) +
             (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar11 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar25 = uVar13 >> 2 | uVar13 * 0x40000000;
    uVar9 = uVar8 ^ uVar26 ^ uVar9 ^ uVar6;
    uVar5 = uVar16 + 0xca62c1d6 + uVar1 + (uVar2 ^ uVar4 ^ uVar5) + (uVar13 >> 0x1b | uVar13 * 0x20)
    ;
    uVar13 = (uVar11 ^ uVar2 ^ uVar13) + uVar12 + 0xca62c1d6 + uVar4 +
             (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar1 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar4 = uVar13 >> 2 | uVar13 * 0x40000000;
    uVar5 = (uVar25 ^ uVar11 ^ uVar5) + uVar2 + uVar6 + 0xca62c1d6 +
            (uVar13 >> 0x1b | uVar13 * 0x20);
    uVar2 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar6 = (uVar1 ^ uVar25 ^ uVar13) + uVar11 + uVar19 + 0xca62c1d6 +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar25 = uVar25 + uVar10 + 0xca62c1d6 + (uVar4 ^ uVar1 ^ uVar5) + (uVar6 >> 0x1b | uVar6 * 0x20)
    ;
    uVar11 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar5 = uVar1 + uVar9 + 0xca62c1d6 + (uVar2 ^ uVar4 ^ uVar6) + (uVar25 >> 0x1b | uVar25 * 0x20);
    uVar1 = uVar25 >> 2 | uVar25 * 0x40000000;
    uVar4 = uVar4 + (uVar14 ^ uVar22 ^ uVar7 ^ uVar19) + 0xca62c1d6 + (uVar11 ^ uVar2 ^ uVar25) +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar25 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar2 = uVar2 + (uVar3 ^ uVar8 ^ uVar17 ^ uVar10) + 0xca62c1d6 + (uVar1 ^ uVar11 ^ uVar5) +
            (uVar4 >> 0x1b | uVar4 * 0x20);
    local_4c = local_4c +
               (uVar25 ^ uVar1 ^ uVar4) + uVar11 + (uVar15 ^ uVar14 ^ uVar16 ^ uVar9) + 0xca62c1d6 +
               (uVar2 >> 0x1b | uVar2 * 0x20);
    local_40 = local_40 + uVar2;
    local_50 = local_50 + (uVar4 >> 2 | uVar4 * 0x40000000);
    local_3c = local_3c + uVar1;
    local_48 = local_48 + uVar25;
    param_1[2] = local_50;
    *param_1 = local_4c;
    param_1[1] = local_40;
    param_1[3] = local_48;
    param_1[4] = local_3c;
    local_30 = local_30 + -1;
  } while (local_30 != 0);
  return;
}

