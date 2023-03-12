
void RIPEMD160_Transform(RIPEMD160_CTX *c,uchar *b)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
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
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  int iVar40;
  uint uStack_9c;
  uint uStack_98;
  int iStack_90;
  
  iStack_90 = 0;
  uVar1 = c->A;
  uVar2 = c->B;
  uStack_9c = c->C;
  uVar3 = c->D;
  uStack_98 = c->E;
  do {
    uVar15 = (uint)b[1] << 8 | (uint)b[2] << 0x10 | (uint)*b | (uint)b[3] << 0x18;
    uVar11 = (uint)b[0x15] << 8 | (uint)b[0x16] << 0x10 | (uint)b[0x14] | (uint)b[0x17] << 0x18;
    uVar5 = ((~uVar3 | uStack_9c) ^ uVar2) + uVar1 + 0x50a28be6 + uVar11;
    uVar4 = (uVar2 ^ uStack_9c ^ uVar3) + uVar1 + uVar15;
    uVar12 = (uStack_9c >> 0x16) + uStack_9c * 0x400;
    uVar36 = (uint)b[9] << 8 | (uint)b[10] << 0x10 | (uint)b[8] | (uint)b[0xb] << 0x18;
    uVar4 = (uVar4 >> 0x15) + uVar4 * 0x800 + uStack_98;
    uVar6 = (uVar5 >> 0x18) + uVar5 * 0x100 + uStack_98;
    uVar7 = (uint)b[5] << 8 | (uint)b[6] << 0x10 | (uint)b[4] | (uint)b[7] << 0x18;
    uVar13 = (uint)b[0x39] << 8 | (uint)b[0x3a] << 0x10 | (uint)b[0x38] | (uint)b[0x3b] << 0x18;
    uVar8 = (uVar12 ^ uVar2 ^ uVar4) + uVar7 + uStack_98;
    uVar10 = ((~uVar12 | uVar2) ^ uVar6) + uStack_98 + 0x50a28be6 + uVar13;
    uVar27 = (uVar2 >> 0x16) + uVar2 * 0x400;
    uVar21 = (uint)b[0x1d] << 8 | (uint)b[0x1e] << 0x10 | (uint)b[0x1c] | (uint)b[0x1f] << 0x18;
    uVar5 = (uVar4 >> 0x16) + uVar4 * 0x400;
    uVar10 = (uVar10 >> 0x17) + uVar10 * 0x200 + uVar3;
    uVar8 = (uVar8 >> 0x12) + uVar8 * 0x4000 + uVar3;
    uVar23 = ((~uVar27 | uVar6) ^ uVar10) + uVar3 + 0x50a28be6 + uVar21;
    uVar4 = (uVar4 ^ uVar27 ^ uVar8) + uVar36 + uVar3;
    uVar18 = (uint)b[0xd] << 8 | (uint)b[0xe] << 0x10 | (uint)b[0xc] | (uint)b[0xf] << 0x18;
    uVar14 = uVar12 + (uVar4 >> 0x11) + uVar4 * 0x8000;
    uVar24 = uVar12 + (uVar23 >> 0x17) + uVar23 * 0x200;
    uVar4 = (uVar8 ^ uVar5 ^ uVar14) + uVar12 + uVar18;
    uVar6 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar23 = ((~uVar6 | uVar10) ^ uVar24) + uVar12 + 0x50a28be6 + uVar15;
    uVar8 = (uVar8 >> 0x16) + uVar8 * 0x400;
    uVar12 = uVar27 + (uVar4 >> 0x14) + uVar4 * 0x1000;
    uVar34 = (uint)b[0x11] << 8 | (uint)b[0x12] << 0x10 | (uint)b[0x10] | (uint)b[0x13] << 0x18;
    uVar16 = (uint)b[0x25] << 8 | (uint)b[0x26] << 0x10 | (uint)b[0x24] | (uint)b[0x27] << 0x18;
    uVar19 = uVar27 + (uVar23 >> 0x15) + uVar23 * 0x800;
    uVar10 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar23 = (uVar14 ^ uVar8 ^ uVar12) + uVar27 + uVar34;
    uVar4 = ((~uVar10 | uVar24) ^ uVar19) + uVar27 + 0x50a28be6 + uVar16;
    uVar14 = (uVar14 >> 0x16) + uVar14 * 0x400;
    uVar27 = uVar5 + (uVar23 >> 0x1b) + uVar23 * 0x20;
    uVar25 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar24 = uVar6 + (uVar4 >> 0x13) + uVar4 * 0x2000;
    uVar4 = (uVar12 ^ uVar14 ^ uVar27) + uVar5 + uVar11;
    uVar5 = ((~uVar25 | uVar19) ^ uVar24) + uVar36 + 0x50a28be6 + uVar6;
    uVar28 = (uint)b[0x2d] << 8 | (uint)b[0x2e] << 0x10 | (uint)b[0x2c] | (uint)b[0x2f] << 0x18;
    uVar20 = (uVar19 >> 0x16) + uVar19 * 0x400;
    uVar5 = uVar10 + (uVar5 >> 0x11) + uVar5 * 0x8000;
    uVar23 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar4 = uVar8 + (uVar4 >> 0x18) + uVar4 * 0x100;
    uVar35 = (uint)b[0x19] << 8 | (uint)b[0x1a] << 0x10 | (uint)b[0x18] | (uint)b[0x1b] << 0x18;
    uVar6 = (uVar27 ^ uVar23 ^ uVar4) + uVar8 + uVar35;
    uVar8 = ((~uVar20 | uVar24) ^ uVar5) + uVar28 + 0x50a28be6 + uVar10;
    uVar19 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar17 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar12 = uVar25 + (uVar8 >> 0x11) + uVar8 * 0x8000;
    uVar24 = uVar14 + (uVar6 >> 0x19) + uVar6 * 0x80;
    uVar6 = (uVar4 ^ uVar17 ^ uVar24) + uVar14 + uVar21;
    uVar38 = (uint)b[0x35] << 8 | (uint)b[0x36] << 0x10 | (uint)b[0x34] | (uint)b[0x37] << 0x18;
    uVar39 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar27 = (uVar4 >> 0x16) + uVar4 * 0x400;
    uVar4 = (uint)b[0x21] << 8 | (uint)b[0x22] << 0x10 | (uint)b[0x20] | (uint)b[0x23] << 0x18;
    uVar5 = ((~uVar19 | uVar5) ^ uVar12) + uVar34 + 0x50a28be6 + uVar25;
    uVar8 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar5 = uVar20 + (uVar5 >> 0x1b) + uVar5 * 0x20;
    uVar10 = uVar23 + (uVar6 >> 0x17) + uVar6 * 0x200;
    uVar14 = (uint)b[0x3f] << 0x18 | (uint)b[0x3d] << 8 | (uint)b[0x3e] << 0x10 | (uint)b[0x3c];
    uVar25 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar31 = (uint)b[0x29] << 8 | (uint)b[0x2a] << 0x10 | (uint)b[0x28] | (uint)b[0x2b] << 0x18;
    uVar6 = (uVar24 ^ uVar27 ^ uVar10) + uVar23 + uVar4;
    uVar23 = ((~uVar39 | uVar12) ^ uVar5) + uVar38 + 0x50a28be6 + uVar20;
    uVar24 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar12 = uVar17 + (uVar6 >> 0x15) + uVar6 * 0x800;
    uVar6 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar29 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar26 = (uint)b[0x31] << 8 | (uint)b[0x32] << 0x10 | (uint)b[0x30] | (uint)b[0x33] << 0x18;
    uVar23 = uVar19 + (uVar23 >> 0x19) + uVar23 * 0x80;
    uVar10 = (uVar10 ^ uVar25 ^ uVar12) + uVar17 + uVar16;
    uVar10 = uVar27 + (uVar10 >> 0x13) + uVar10 * 0x2000;
    uVar33 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar12 = (uVar12 ^ uVar24 ^ uVar10) + uVar27 + uVar31;
    uVar27 = uVar25 + (uVar12 >> 0x12) + uVar12 * 0x4000;
    uVar30 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar10 = (uVar10 ^ uVar29 ^ uVar27) + uVar25 + uVar28;
    uVar12 = uVar24 + (uVar10 >> 0x11) + uVar10 * 0x8000;
    uVar20 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar32 = (uVar23 >> 0x16) + uVar23 * 0x400;
    uVar10 = (uVar27 ^ uVar33 ^ uVar12) + uVar24 + uVar26;
    uVar27 = uVar29 + (uVar10 >> 0x1a) + uVar10 * 0x40;
    uVar5 = ((~uVar8 | uVar5) ^ uVar23) + uVar35 + 0x50a28be6 + uVar19;
    uVar37 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar24 = uVar39 + (uVar5 >> 0x19) + uVar5 * 0x80;
    uVar25 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar5 = ((~uVar6 | uVar23) ^ uVar24) + uVar14 + 0x50a28be6 + uVar39;
    uVar10 = uVar8 + (uVar5 >> 0x18) + uVar5 * 0x100;
    uVar23 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar5 = (uVar12 ^ uVar30 ^ uVar27) + uVar29 + uVar38;
    uVar12 = uVar33 + (uVar5 >> 0x19) + uVar5 * 0x80;
    uVar19 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar5 = ((~uVar32 | uVar24) ^ uVar10) + uVar4 + 0x50a28be6 + uVar8;
    uVar5 = uVar6 + (uVar5 >> 0x15) + uVar5 * 0x800;
    uVar17 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar8 = (uVar27 ^ uVar20 ^ uVar12) + uVar33 + uVar13;
    uVar6 = ((~uVar25 | uVar10) ^ uVar5) + uVar7 + 0x50a28be6 + uVar6;
    uVar8 = uVar30 + (uVar8 >> 0x17) + uVar8 * 0x200;
    uVar29 = uVar32 + (uVar6 >> 0x12) + uVar6 * 0x4000;
    uVar6 = (uVar8 >> 0x16) + uVar8 * 0x400;
    uVar10 = ((~uVar23 | uVar5) ^ uVar29) + uVar31 + 0x50a28be6 + uVar32;
    uVar5 = (uVar12 ^ uVar37 ^ uVar8) + uVar30 + uVar14;
    uVar12 = (uVar29 >> 0x16) + uVar29 * 0x400;
    uVar24 = uVar25 + (uVar10 >> 0x12) + uVar10 * 0x4000;
    uVar10 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar27 = uVar20 + (uVar5 >> 0x18) + uVar5 * 0x100;
    uVar5 = ((~uVar17 | uVar29) ^ uVar24) + uVar18 + 0x50a28be6 + uVar25;
    uVar25 = uVar23 + (uVar5 >> 0x14) + uVar5 * 0x1000;
    uVar8 = ((uVar8 ^ uVar19) & uVar27 ^ uVar19) + uVar21 + 0x5a827999 + uVar20;
    uVar5 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar30 = uVar37 + (uVar8 >> 0x19) + uVar8 * 0x80;
    uVar8 = ((uVar27 ^ uVar6) & uVar30 ^ uVar6) + uVar34 + 0x5a827999 + uVar37;
    uVar20 = (uVar30 >> 0x16) + uVar30 * 0x400;
    uVar29 = uVar19 + (uVar8 >> 0x1a) + uVar8 * 0x40;
    uVar8 = ((~uVar12 | uVar24) ^ uVar25) + uVar26 + 0x50a28be6 + uVar23;
    uVar27 = uVar17 + (uVar8 >> 0x1a) + uVar8 * 0x40;
    uVar8 = ((uVar30 ^ uVar5) & uVar29 ^ uVar5) + uVar38 + 0x5a827999 + uVar19;
    uVar19 = (uVar29 >> 0x16) + uVar29 * 0x400;
    uVar8 = uVar6 + (uVar8 >> 0x18) + uVar8 * 0x100;
    uVar6 = ((uVar29 ^ uVar20) & uVar8 ^ uVar20) + uVar7 + 0x5a827999 + uVar6;
    uVar30 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar23 = (uVar8 >> 0x16) + uVar8 * 0x400;
    uVar24 = uVar5 + (uVar6 >> 0x13) + uVar6 * 0x2000;
    uVar6 = (uVar25 >> 0x16) + uVar25 * 0x400;
    uVar17 = ((uVar25 ^ uVar27) & uVar10 ^ uVar25) + uVar35 + 0x5c4dd124 + uVar17;
    uVar5 = ((uVar8 ^ uVar19) & uVar24 ^ uVar19) + uVar31 + 0x5a827999 + uVar5;
    uVar29 = uVar12 + (uVar17 >> 0x17) + uVar17 * 0x200;
    uVar25 = uVar20 + (uVar5 >> 0x15) + uVar5 * 0x800;
    uVar8 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar24 = ((uVar24 ^ uVar23) & uVar25 ^ uVar23) + uVar35 + 0x5a827999 + uVar20;
    uVar5 = ((uVar27 ^ uVar29) & uVar6 ^ uVar27) + uVar28 + 0x5c4dd124 + uVar12;
    uVar17 = uVar19 + (uVar24 >> 0x17) + uVar24 * 0x200;
    uVar27 = (uVar25 >> 0x16) + uVar25 * 0x400;
    uVar24 = uVar10 + (uVar5 >> 0x13) + uVar5 * 0x2000;
    uVar20 = ((uVar25 ^ uVar8) & uVar17 ^ uVar8) + uVar14 + 0x5a827999 + uVar19;
    uVar19 = (uVar29 >> 0x16) + uVar29 * 0x400;
    uVar5 = ((uVar29 ^ uVar24) & uVar30 ^ uVar29) + uVar18 + 0x5c4dd124 + uVar10;
    uVar12 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar25 = uVar23 + (uVar20 >> 0x19) + uVar20 * 0x80;
    uVar5 = uVar6 + (uVar5 >> 0x11) + uVar5 * 0x8000;
    uVar10 = ((uVar17 ^ uVar27) & uVar25 ^ uVar27) + uVar18 + 0x5a827999 + uVar23;
    uVar6 = ((uVar24 ^ uVar5) & uVar19 ^ uVar24) + uVar21 + 0x5c4dd124 + uVar6;
    uVar23 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar6 = uVar30 + (uVar6 >> 0x19) + uVar6 * 0x80;
    uVar24 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar17 = (uVar17 >> 0x16) + uVar17 * 0x400;
    uVar5 = ((uVar5 ^ uVar6) & uVar12 ^ uVar5) + uVar15 + 0x5c4dd124 + uVar30;
    uVar10 = uVar8 + (uVar10 >> 0x11) + uVar10 * 0x8000;
    uVar5 = uVar19 + (uVar5 >> 0x14) + uVar5 * 0x1000;
    uVar6 = ((uVar6 ^ uVar5) & uVar23 ^ uVar6) + uVar38 + 0x5c4dd124 + uVar19;
    uVar20 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar19 = uVar12 + (uVar6 >> 0x18) + uVar6 * 0x100;
    uVar5 = ((uVar5 ^ uVar19) & uVar24 ^ uVar5) + uVar11 + 0x5c4dd124 + uVar12;
    uVar12 = uVar23 + (uVar5 >> 0x17) + uVar5 * 0x200;
    uVar5 = ((uVar25 ^ uVar17) & uVar10 ^ uVar17) + uVar26 + 0x5a827999 + uVar8;
    uVar30 = (uVar25 >> 0x16) + uVar25 * 0x400;
    uVar8 = ((uVar19 ^ uVar12) & uVar20 ^ uVar19) + uVar31 + 0x5c4dd124 + uVar23;
    uVar6 = uVar27 + (uVar5 >> 0x19) + uVar5 * 0x80;
    uVar5 = uVar24 + (uVar8 >> 0x15) + uVar8 * 0x800;
    uVar32 = (uVar19 >> 0x16) + uVar19 * 0x400;
    uVar8 = ((uVar10 ^ uVar30) & uVar6 ^ uVar30) + uVar15 + 0x5a827999 + uVar27;
    uVar10 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar19 = uVar17 + (uVar8 >> 0x14) + uVar8 * 0x1000;
    uVar8 = ((uVar12 ^ uVar5) & uVar32 ^ uVar12) + uVar13 + 0x5c4dd124 + uVar24;
    uVar27 = uVar20 + (uVar8 >> 0x19) + uVar8 * 0x80;
    uVar23 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar12 = ((uVar6 ^ uVar10) & uVar19 ^ uVar10) + uVar16 + 0x5a827999 + uVar17;
    uVar8 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar25 = uVar30 + (uVar12 >> 0x11) + uVar12 * 0x8000;
    uVar6 = ((uVar5 ^ uVar27) & uVar23 ^ uVar5) + uVar14 + 0x5c4dd124 + uVar20;
    uVar29 = uVar32 + (uVar6 >> 0x19) + uVar6 * 0x80;
    uVar12 = ((uVar19 ^ uVar8) & uVar25 ^ uVar8) + uVar11 + 0x5a827999 + uVar30;
    uVar6 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar24 = uVar10 + (uVar12 >> 0x17) + uVar12 * 0x200;
    uVar5 = ((uVar27 ^ uVar29) & uVar6 ^ uVar27) + uVar4 + 0x5c4dd124 + uVar32;
    uVar20 = (uVar19 >> 0x16) + uVar19 * 0x400;
    uVar12 = uVar23 + (uVar5 >> 0x14) + uVar5 * 0x1000;
    uVar17 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar10 = ((uVar25 ^ uVar20) & uVar24 ^ uVar20) + uVar36 + 0x5a827999 + uVar10;
    uVar25 = (uVar25 >> 0x16) + uVar25 * 0x400;
    uVar5 = ((uVar29 ^ uVar12) & uVar17 ^ uVar29) + uVar26 + 0x5c4dd124 + uVar23;
    uVar23 = uVar8 + (uVar10 >> 0x15) + uVar10 * 0x800;
    uVar10 = uVar6 + (uVar5 >> 0x19) + uVar5 * 0x80;
    uVar5 = ((uVar24 ^ uVar25) & uVar23 ^ uVar25) + uVar13 + 0x5a827999 + uVar8;
    uVar29 = (uVar29 >> 0x16) + uVar29 * 0x400;
    uVar24 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar19 = uVar20 + (uVar5 >> 0x19) + uVar5 * 0x80;
    uVar5 = ((uVar12 ^ uVar10) & uVar29 ^ uVar12) + uVar34 + 0x5c4dd124 + uVar6;
    uVar8 = ((uVar23 ^ uVar24) & uVar19 ^ uVar24) + uVar28 + 0x5a827999 + uVar20;
    uVar6 = uVar17 + (uVar5 >> 0x1a) + uVar5 * 0x40;
    uVar23 = (uVar23 >> 0x16) + uVar23 * 0x400;
    uVar12 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar27 = uVar25 + (uVar8 >> 0x13) + uVar8 * 0x2000;
    uVar5 = ((uVar10 ^ uVar6) & uVar12 ^ uVar10) + uVar16 + 0x5c4dd124 + uVar17;
    uVar8 = ((uVar19 ^ uVar23) & uVar27 ^ uVar23) + uVar4 + 0x5a827999 + uVar25;
    uVar5 = uVar29 + (uVar5 >> 0x11) + uVar5 * 0x8000;
    uVar17 = uVar24 + (uVar8 >> 0x14) + uVar8 * 0x1000;
    uVar8 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar19 = (uVar19 >> 0x16) + uVar19 * 0x400;
    uVar10 = ((~uVar27 | uVar17) ^ uVar19) + uVar18 + 0x6ed9eba1 + uVar24;
    uVar24 = ((uVar6 ^ uVar5) & uVar8 ^ uVar6) + uVar7 + 0x5c4dd124 + uVar29;
    uVar25 = uVar23 + (uVar10 >> 0x15) + uVar10 * 0x800;
    uVar20 = uVar12 + (uVar24 >> 0x13) + uVar24 * 0x2000;
    uVar6 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar24 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar10 = ((~uVar17 | uVar25) ^ uVar24) + uVar31 + 0x6ed9eba1 + uVar23;
    uVar12 = ((uVar5 ^ uVar20) & uVar6 ^ uVar5) + uVar36 + 0x5c4dd124 + uVar12;
    uVar27 = uVar19 + (uVar10 >> 0x13) + uVar10 * 0x2000;
    uVar23 = uVar8 + (uVar12 >> 0x15) + uVar12 * 0x800;
    uVar32 = (uVar17 >> 0x16) + uVar17 * 0x400;
    uVar5 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar10 = ((~uVar25 | uVar27) ^ uVar32) + uVar13 + 0x6ed9eba1 + uVar19;
    uVar8 = ((~uVar20 | uVar23) ^ uVar5) + uVar14 + 0x6d703ef3 + uVar8;
    uVar10 = uVar24 + (uVar10 >> 0x1a) + uVar10 * 0x40;
    uVar17 = uVar6 + (uVar8 >> 0x17) + uVar8 * 0x200;
    uVar30 = (uVar25 >> 0x16) + uVar25 * 0x400;
    uVar29 = (uVar20 >> 0x16) + uVar20 * 0x400;
    uVar8 = ((~uVar27 | uVar10) ^ uVar30) + uVar34 + 0x6ed9eba1 + uVar24;
    uVar12 = ((~uVar23 | uVar17) ^ uVar29) + uVar11 + 0x6d703ef3 + uVar6;
    uVar6 = uVar32 + (uVar8 >> 0x19) + uVar8 * 0x80;
    uVar19 = uVar5 + (uVar12 >> 0x19) + uVar12 * 0x80;
    uVar25 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar20 = (uVar23 >> 0x16) + uVar23 * 0x400;
    uVar8 = ((~uVar10 | uVar6) ^ uVar25) + uVar16 + 0x6ed9eba1 + uVar32;
    uVar5 = ((~uVar17 | uVar19) ^ uVar20) + uVar7 + 0x6d703ef3 + uVar5;
    uVar12 = uVar30 + (uVar8 >> 0x12) + uVar8 * 0x4000;
    uVar23 = uVar29 + (uVar5 >> 0x11) + uVar5 * 0x8000;
    uVar27 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar17 = (uVar17 >> 0x16) + uVar17 * 0x400;
    uVar8 = ((~uVar6 | uVar12) ^ uVar27) + uVar14 + 0x6ed9eba1 + uVar30;
    uVar5 = ((~uVar19 | uVar23) ^ uVar17) + uVar18 + 0x6d703ef3 + uVar29;
    uVar8 = uVar25 + (uVar8 >> 0x17) + uVar8 * 0x200;
    uVar24 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar10 = uVar20 + (uVar5 >> 0x15) + uVar5 * 0x800;
    uVar19 = (uVar19 >> 0x16) + uVar19 * 0x400;
    uVar5 = ((~uVar12 | uVar8) ^ uVar24) + uVar4 + 0x6ed9eba1 + uVar25;
    uVar6 = ((~uVar23 | uVar10) ^ uVar19) + uVar21 + 0x6d703ef3 + uVar20;
    uVar5 = uVar27 + (uVar5 >> 0x13) + uVar5 * 0x2000;
    uVar12 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar6 = uVar17 + (uVar6 >> 0x18) + uVar6 * 0x100;
    uVar23 = (uVar23 >> 0x16) + uVar23 * 0x400;
    uVar27 = ((~uVar8 | uVar5) ^ uVar12) + uVar7 + 0x6ed9eba1 + uVar27;
    uVar17 = ((~uVar10 | uVar6) ^ uVar23) + uVar13 + 0x6d703ef3 + uVar17;
    uVar27 = uVar24 + (uVar27 >> 0x11) + uVar27 * 0x8000;
    uVar8 = (uVar8 >> 0x16) + uVar8 * 0x400;
    uVar17 = uVar19 + (uVar17 >> 0x1a) + uVar17 * 0x40;
    uVar10 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar24 = ((~uVar5 | uVar27) ^ uVar8) + uVar36 + 0x6ed9eba1 + uVar24;
    uVar19 = ((~uVar6 | uVar17) ^ uVar10) + uVar35 + 0x6d703ef3 + uVar19;
    uVar24 = uVar12 + (uVar24 >> 0x12) + uVar24 * 0x4000;
    uVar5 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar19 = uVar23 + (uVar19 >> 0x1a) + uVar19 * 0x40;
    uVar6 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar12 = ((~uVar27 | uVar24) ^ uVar5) + uVar21 + 0x6ed9eba1 + uVar12;
    uVar23 = ((~uVar17 | uVar19) ^ uVar6) + uVar16 + 0x6d703ef3 + uVar23;
    uVar12 = uVar8 + (uVar12 >> 0x18) + uVar12 * 0x100;
    uVar27 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar23 = uVar10 + (uVar23 >> 0x12) + uVar23 * 0x4000;
    uVar17 = (uVar17 >> 0x16) + uVar17 * 0x400;
    uVar8 = ((~uVar24 | uVar12) ^ uVar27) + uVar15 + 0x6ed9eba1 + uVar8;
    uVar10 = ((~uVar19 | uVar23) ^ uVar17) + uVar28 + 0x6d703ef3 + uVar10;
    uVar8 = uVar5 + (uVar8 >> 0x13) + uVar8 * 0x2000;
    uVar24 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar10 = uVar6 + (uVar10 >> 0x14) + uVar10 * 0x1000;
    uVar19 = (uVar19 >> 0x16) + uVar19 * 0x400;
    uVar5 = ((~uVar12 | uVar8) ^ uVar24) + uVar35 + 0x6ed9eba1 + uVar5;
    uVar6 = ((~uVar23 | uVar10) ^ uVar19) + uVar4 + 0x6d703ef3 + uVar6;
    uVar5 = uVar27 + (uVar5 >> 0x1a) + uVar5 * 0x40;
    uVar12 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar6 = uVar17 + (uVar6 >> 0x13) + uVar6 * 0x2000;
    uVar23 = (uVar23 >> 0x16) + uVar23 * 0x400;
    uVar27 = ((~uVar8 | uVar5) ^ uVar12) + uVar38 + 0x6ed9eba1 + uVar27;
    uVar17 = ((~uVar10 | uVar6) ^ uVar23) + uVar26 + 0x6d703ef3 + uVar17;
    uVar27 = uVar24 + (uVar27 >> 0x1b) + uVar27 * 0x20;
    uVar8 = (uVar8 >> 0x16) + uVar8 * 0x400;
    uVar17 = uVar19 + (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar10 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar24 = ((~uVar5 | uVar27) ^ uVar8) + uVar28 + 0x6ed9eba1 + uVar24;
    uVar19 = ((~uVar6 | uVar17) ^ uVar10) + uVar36 + 0x6d703ef3 + uVar19;
    uVar24 = uVar12 + (uVar24 >> 0x14) + uVar24 * 0x1000;
    uVar5 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar19 = uVar23 + (uVar19 >> 0x12) + uVar19 * 0x4000;
    uVar6 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar12 = ((~uVar27 | uVar24) ^ uVar5) + uVar11 + 0x6ed9eba1 + uVar12;
    uVar23 = ((~uVar17 | uVar19) ^ uVar6) + uVar31 + 0x6d703ef3 + uVar23;
    uVar12 = uVar8 + (uVar12 >> 0x19) + uVar12 * 0x80;
    uVar27 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar23 = uVar10 + (uVar23 >> 0x13) + uVar23 * 0x2000;
    uVar17 = (uVar17 >> 0x16) + uVar17 * 0x400;
    uVar8 = ((~uVar24 | uVar12) ^ uVar27) + uVar26 + 0x6ed9eba1 + uVar8;
    uVar10 = ((~uVar19 | uVar23) ^ uVar17) + uVar15 + 0x6d703ef3 + uVar10;
    uVar8 = uVar5 + (uVar8 >> 0x1b) + uVar8 * 0x20;
    uVar24 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar10 = uVar6 + (uVar10 >> 0x13) + uVar10 * 0x2000;
    uVar19 = (uVar19 >> 0x16) + uVar19 * 0x400;
    uVar5 = ((uVar12 ^ uVar8) & uVar24 ^ uVar12) + uVar7 + 0x8f1bbcdc + uVar5;
    uVar6 = ((~uVar23 | uVar10) ^ uVar19) + uVar34 + 0x6d703ef3 + uVar6;
    uVar5 = uVar27 + (uVar5 >> 0x15) + uVar5 * 0x800;
    uVar12 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar6 = uVar17 + (uVar6 >> 0x19) + uVar6 * 0x80;
    uVar25 = (uVar23 >> 0x16) + uVar23 * 0x400;
    uVar23 = ((uVar8 ^ uVar5) & uVar12 ^ uVar8) + uVar16 + 0x8f1bbcdc + uVar27;
    uVar17 = ((~uVar10 | uVar6) ^ uVar25) + uVar38 + 0x6d703ef3 + uVar17;
    uVar29 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar27 = uVar24 + (uVar23 >> 0x14) + uVar23 * 0x1000;
    uVar20 = uVar19 + (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar8 = (uVar8 >> 0x16) + uVar8 * 0x400;
    uVar23 = ((uVar6 ^ uVar29) & uVar20 ^ uVar29) + uVar4 + 0x7a6d76e9 + uVar19;
    uVar10 = ((uVar5 ^ uVar27) & uVar8 ^ uVar5) + uVar28 + 0x8f1bbcdc + uVar24;
    uVar6 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar24 = uVar25 + (uVar23 >> 0x11) + uVar23 * 0x8000;
    uVar23 = uVar12 + (uVar10 >> 0x12) + uVar10 * 0x4000;
    uVar17 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar10 = ((uVar20 ^ uVar6) & uVar24 ^ uVar6) + uVar35 + 0x7a6d76e9 + uVar25;
    uVar5 = ((uVar27 ^ uVar23) & uVar17 ^ uVar27) + uVar31 + 0x8f1bbcdc + uVar12;
    uVar20 = (uVar20 >> 0x16) + uVar20 * 0x400;
    uVar12 = uVar29 + (uVar10 >> 0x1b) + uVar10 * 0x20;
    uVar10 = uVar8 + (uVar5 >> 0x11) + uVar5 * 0x8000;
    uVar19 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar5 = ((uVar24 ^ uVar20) & uVar12 ^ uVar20) + uVar34 + 0x7a6d76e9 + uVar29;
    uVar8 = ((uVar23 ^ uVar10) & uVar19 ^ uVar23) + uVar15 + 0x8f1bbcdc + uVar8;
    uVar24 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar25 = uVar6 + (uVar5 >> 0x18) + uVar5 * 0x100;
    uVar8 = uVar17 + (uVar8 >> 0x12) + uVar8 * 0x4000;
    uVar27 = (uVar23 >> 0x16) + uVar23 * 0x400;
    uVar5 = ((uVar12 ^ uVar24) & uVar25 ^ uVar24) + uVar7 + 0x7a6d76e9 + uVar6;
    uVar12 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar6 = uVar20 + (uVar5 >> 0x15) + uVar5 * 0x800;
    uVar5 = ((uVar10 ^ uVar8) & uVar27 ^ uVar10) + uVar4 + 0x8f1bbcdc + uVar17;
    uVar20 = ((uVar25 ^ uVar12) & uVar6 ^ uVar12) + uVar18 + 0x7a6d76e9 + uVar20;
    uVar17 = uVar19 + (uVar5 >> 0x11) + uVar5 * 0x8000;
    uVar23 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar5 = (uVar25 >> 0x16) + uVar25 * 0x400;
    uVar20 = uVar24 + (uVar20 >> 0x12) + uVar20 * 0x4000;
    uVar10 = ((uVar8 ^ uVar17) & uVar23 ^ uVar8) + uVar26 + 0x8f1bbcdc + uVar19;
    uVar24 = ((uVar6 ^ uVar5) & uVar20 ^ uVar5) + uVar28 + 0x7a6d76e9 + uVar24;
    uVar19 = uVar27 + (uVar10 >> 0x17) + uVar10 * 0x200;
    uVar10 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar6 = (uVar8 >> 0x16) + uVar8 * 0x400;
    uVar24 = uVar12 + (uVar24 >> 0x12) + uVar24 * 0x4000;
    uVar27 = ((uVar17 ^ uVar19) & uVar6 ^ uVar17) + uVar34 + 0x8f1bbcdc + uVar27;
    uVar8 = ((uVar20 ^ uVar10) & uVar24 ^ uVar10) + uVar14 + 0x7a6d76e9 + uVar12;
    uVar27 = uVar23 + (uVar27 >> 0x18) + uVar27 * 0x100;
    uVar20 = (uVar20 >> 0x16) + uVar20 * 0x400;
    uVar12 = uVar5 + (uVar8 >> 0x1a) + uVar8 * 0x40;
    uVar17 = (uVar17 >> 0x16) + uVar17 * 0x400;
    uVar5 = ((uVar24 ^ uVar20) & uVar12 ^ uVar20) + uVar15 + 0x7a6d76e9 + uVar5;
    uVar8 = ((uVar19 ^ uVar27) & uVar17 ^ uVar19) + uVar38 + 0x8f1bbcdc + uVar23;
    uVar23 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar25 = uVar6 + (uVar8 >> 0x17) + uVar8 * 0x200;
    uVar5 = uVar10 + (uVar5 >> 0x12) + uVar5 * 0x4000;
    uVar24 = (uVar19 >> 0x16) + uVar19 * 0x400;
    uVar8 = ((uVar12 ^ uVar23) & uVar5 ^ uVar23) + uVar11 + 0x7a6d76e9 + uVar10;
    uVar6 = ((uVar27 ^ uVar25) & uVar24 ^ uVar27) + uVar18 + 0x8f1bbcdc + uVar6;
    uVar10 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar8 = uVar20 + (uVar8 >> 0x1a) + uVar8 * 0x40;
    uVar19 = uVar17 + (uVar6 >> 0x12) + uVar6 * 0x4000;
    uVar29 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar6 = ((uVar5 ^ uVar10) & uVar8 ^ uVar10) + uVar26 + 0x7a6d76e9 + uVar20;
    uVar12 = ((uVar25 ^ uVar19) & uVar29 ^ uVar25) + uVar21 + 0x8f1bbcdc + uVar17;
    uVar5 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar6 = uVar23 + (uVar6 >> 0x17) + uVar6 * 0x200;
    uVar27 = uVar24 + (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar20 = (uVar25 >> 0x16) + uVar25 * 0x400;
    uVar23 = ((uVar8 ^ uVar5) & uVar6 ^ uVar5) + uVar36 + 0x7a6d76e9 + uVar23;
    uVar24 = ((uVar19 ^ uVar27) & uVar20 ^ uVar19) + uVar14 + 0x8f1bbcdc + uVar24;
    uVar12 = (uVar8 >> 0x16) + uVar8 * 0x400;
    uVar23 = uVar10 + (uVar23 >> 0x14) + uVar23 * 0x1000;
    uVar24 = uVar29 + (uVar24 >> 0x1a) + uVar24 * 0x40;
    uVar17 = (uVar19 >> 0x16) + uVar19 * 0x400;
    uVar10 = ((uVar6 ^ uVar12) & uVar23 ^ uVar12) + uVar38 + 0x7a6d76e9 + uVar10;
    uVar8 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar6 = ((uVar27 ^ uVar24) & uVar17 ^ uVar27) + uVar13 + 0x8f1bbcdc + uVar29;
    uVar10 = uVar5 + (uVar10 >> 0x17) + uVar10 * 0x200;
    uVar6 = uVar20 + (uVar6 >> 0x18) + uVar6 * 0x100;
    uVar19 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar5 = ((uVar23 ^ uVar8) & uVar10 ^ uVar8) + uVar16 + 0x7a6d76e9 + uVar5;
    uVar27 = (uVar23 >> 0x16) + uVar23 * 0x400;
    uVar5 = uVar12 + (uVar5 >> 0x14) + uVar5 * 0x1000;
    uVar23 = ((uVar24 ^ uVar6) & uVar19 ^ uVar24) + uVar11 + 0x8f1bbcdc + uVar20;
    uVar23 = uVar17 + (uVar23 >> 0x1a) + uVar23 * 0x40;
    uVar12 = ((uVar10 ^ uVar27) & uVar5 ^ uVar27) + uVar21 + 0x7a6d76e9 + uVar12;
    uVar24 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar10 = (uVar10 >> 0x16) + uVar10 * 0x400;
    uVar12 = uVar8 + (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar17 = ((uVar6 ^ uVar23) & uVar24 ^ uVar6) + uVar35 + 0x8f1bbcdc + uVar17;
    uVar8 = ((uVar5 ^ uVar10) & uVar12 ^ uVar10) + uVar31 + 0x7a6d76e9 + uVar8;
    uVar17 = uVar19 + (uVar17 >> 0x1b) + uVar17 * 0x20;
    uVar20 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar5 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar25 = uVar27 + (uVar8 >> 0x11) + uVar8 * 0x8000;
    uVar8 = ((uVar23 ^ uVar17) & uVar20 ^ uVar23) + uVar36 + 0x8f1bbcdc + uVar19;
    uVar23 = (uVar23 >> 0x16) + uVar23 * 0x400;
    uVar6 = ((uVar12 ^ uVar5) & uVar25 ^ uVar5) + uVar13 + 0x7a6d76e9 + uVar27;
    uVar19 = uVar24 + (uVar8 >> 0x14) + uVar8 * 0x1000;
    uVar12 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar27 = uVar10 + (uVar6 >> 0x18) + uVar6 * 0x100;
    uVar8 = ((~uVar23 | uVar17) ^ uVar19) + uVar34 + 0xa953fd4e + uVar24;
    uVar17 = (uVar17 >> 0x16) + uVar17 * 0x400;
    uVar6 = (uVar25 ^ uVar12 ^ uVar27) + uVar26 + uVar10;
    uVar24 = uVar20 + (uVar8 >> 0x17) + uVar8 * 0x200;
    uVar25 = (uVar25 >> 0x16) + uVar25 * 0x400;
    uVar8 = uVar5 + (uVar6 >> 0x18) + uVar6 * 0x100;
    uVar6 = ((~uVar17 | uVar19) ^ uVar24) + uVar15 + 0xa953fd4e + uVar20;
    uVar5 = (uVar27 ^ uVar25 ^ uVar8) + uVar14 + uVar5;
    uVar6 = uVar23 + (uVar6 >> 0x11) + uVar6 * 0x8000;
    uVar19 = (uVar19 >> 0x16) + uVar19 * 0x400;
    uVar27 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar5 = uVar12 + (uVar5 >> 0x1b) + uVar5 * 0x20;
    uVar10 = (uVar8 ^ uVar27 ^ uVar5) + uVar31 + uVar12;
    uVar12 = ((~uVar19 | uVar24) ^ uVar6) + uVar11 + 0xa953fd4e + uVar23;
    uVar23 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar8 = (uVar8 >> 0x16) + uVar8 * 0x400;
    uVar12 = uVar17 + (uVar12 >> 0x1b) + uVar12 * 0x20;
    uVar20 = uVar25 + (uVar10 >> 0x14) + uVar10 * 0x1000;
    uVar10 = ((~uVar23 | uVar6) ^ uVar12) + uVar16 + 0xa953fd4e + uVar17;
    uVar24 = (uVar5 ^ uVar8 ^ uVar20) + uVar34 + uVar25;
    uVar6 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar5 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar17 = uVar19 + (uVar10 >> 0x15) + uVar10 * 0x800;
    uVar25 = uVar27 + (uVar24 >> 0x17) + uVar24 * 0x200;
    uVar19 = ((~uVar6 | uVar12) ^ uVar17) + uVar21 + 0xa953fd4e + uVar19;
    uVar24 = (uVar20 ^ uVar5 ^ uVar25) + uVar7 + uVar27;
    uVar10 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar20 = (uVar20 >> 0x16) + uVar20 * 0x400;
    uVar27 = uVar23 + (uVar19 >> 0x1a) + uVar19 * 0x40;
    uVar24 = uVar8 + (uVar24 >> 0x14) + uVar24 * 0x1000;
    uVar8 = (uVar25 ^ uVar20 ^ uVar24) + uVar11 + uVar8;
    uVar12 = ((~uVar10 | uVar17) ^ uVar27) + uVar26 + 0xa953fd4e + uVar23;
    uVar19 = (uVar17 >> 0x16) + uVar17 * 0x400;
    uVar25 = (uVar25 >> 0x16) + uVar25 * 0x400;
    uVar12 = uVar6 + (uVar12 >> 0x18) + uVar12 * 0x100;
    uVar17 = uVar5 + (uVar8 >> 0x1b) + uVar8 * 0x20;
    uVar6 = ((~uVar19 | uVar27) ^ uVar12) + uVar36 + 0xa953fd4e + uVar6;
    uVar5 = (uVar24 ^ uVar25 ^ uVar17) + uVar4 + uVar5;
    uVar23 = (uVar27 >> 0x16) + uVar27 * 0x400;
    uVar11 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar6 = uVar10 + (uVar6 >> 0x13) + uVar6 * 0x2000;
    uVar5 = uVar20 + (uVar5 >> 0x12) + uVar5 * 0x4000;
    uVar8 = ((~uVar23 | uVar12) ^ uVar6) + uVar31 + 0xa953fd4e + uVar10;
    uVar24 = (uVar17 ^ uVar11 ^ uVar5) + uVar21 + uVar20;
    uVar10 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar27 = (uVar17 >> 0x16) + uVar17 * 0x400;
    uVar17 = uVar19 + (uVar8 >> 0x14) + uVar8 * 0x1000;
    uVar12 = uVar25 + (uVar24 >> 0x1a) + uVar24 * 0x40;
    uVar8 = ((~uVar10 | uVar6) ^ uVar17) + uVar13 + 0xa953fd4e + uVar19;
    uVar19 = (uVar5 ^ uVar27 ^ uVar12) + uVar35 + uVar25;
    uVar6 = (uVar6 >> 0x16) + uVar6 * 0x400;
    uVar5 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar24 = uVar23 + (uVar8 >> 0x1b) + uVar8 * 0x20;
    uVar20 = uVar11 + (uVar19 >> 0x18) + uVar19 * 0x100;
    uVar7 = ((~uVar6 | uVar17) ^ uVar24) + uVar7 + 0xa953fd4e + uVar23;
    uVar8 = (uVar12 ^ uVar5 ^ uVar20) + uVar36 + uVar11;
    uVar17 = (uVar17 >> 0x16) + uVar17 * 0x400;
    uVar19 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar12 = uVar10 + (uVar7 >> 0x14) + uVar7 * 0x1000;
    uVar7 = uVar27 + (uVar8 >> 0x13) + uVar8 * 0x2000;
    uVar8 = ((~uVar17 | uVar24) ^ uVar12) + uVar18 + 0xa953fd4e + uVar10;
    uVar10 = (uVar20 ^ uVar19 ^ uVar7) + uVar38 + uVar27;
    uVar11 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar27 = (uVar20 >> 0x16) + uVar20 * 0x400;
    uVar8 = uVar6 + (uVar8 >> 0x13) + uVar8 * 0x2000;
    uVar23 = uVar5 + (uVar10 >> 0x1a) + uVar10 * 0x40;
    uVar6 = ((~uVar11 | uVar12) ^ uVar8) + uVar4 + 0xa953fd4e + uVar6;
    uVar4 = (uVar7 ^ uVar27 ^ uVar23) + uVar13 + uVar5;
    uVar12 = (uVar12 >> 0x16) + uVar12 * 0x400;
    uVar10 = (uVar7 >> 0x16) + uVar7 * 0x400;
    uVar5 = uVar17 + (uVar6 >> 0x12) + uVar6 * 0x4000;
    uVar4 = uVar19 + (uVar4 >> 0x1b) + uVar4 * 0x20;
    uVar13 = ((~uVar12 | uVar8) ^ uVar5) + uVar28 + 0xa953fd4e + uVar17;
    uVar7 = (uVar23 ^ uVar10 ^ uVar4) + uVar15 + uVar19;
    uVar6 = (uVar8 >> 0x16) + uVar8 * 0x400;
    uVar23 = (uVar23 >> 0x16) + uVar23 * 0x400;
    uVar24 = uVar11 + (uVar13 >> 0x15) + uVar13 * 0x800;
    uVar13 = uVar27 + (uVar7 >> 0x11) + uVar7 * 0x8000;
    uVar8 = ((~uVar6 | uVar5) ^ uVar24) + uVar35 + 0xa953fd4e + uVar11;
    uVar7 = (uVar4 ^ uVar23 ^ uVar13) + uVar18 + uVar27;
    uVar5 = (uVar5 >> 0x16) + uVar5 * 0x400;
    uVar4 = (uVar4 >> 0x16) + uVar4 * 0x400;
    uVar11 = uVar12 + (uVar8 >> 0x18) + uVar8 * 0x100;
    uVar27 = uVar10 + (uVar7 >> 0x13) + uVar7 * 0x2000;
    uVar7 = ((~uVar5 | uVar24) ^ uVar11) + uVar14 + 0xa953fd4e + uVar12;
    uVar8 = (uVar13 ^ uVar4 ^ uVar27) + uVar16 + uVar10;
    uVar14 = (uVar24 >> 0x16) + uVar24 * 0x400;
    uVar12 = (uVar13 >> 0x16) + uVar13 * 0x400;
    uVar10 = (uVar7 >> 0x1b) + uVar7 * 0x20 + uVar6;
    uVar8 = uVar23 + (uVar8 >> 0x15) + uVar8 * 0x800;
    uVar7 = (uVar27 ^ uVar12 ^ uVar8) + uVar28 + uVar23;
    uVar6 = ((~uVar14 | uVar11) ^ uVar10) + uVar38 + 0xa953fd4e + uVar6;
    iVar9 = uVar5 + uVar1;
    iVar22 = uVar12 + uStack_9c;
    iVar40 = (uVar27 >> 0x16) + uVar27 * 0x400 + uVar2;
    uStack_9c = uVar4 + uVar3 + uVar14;
    uVar2 = (uVar11 >> 0x16) + uVar11 * 0x400 + iVar22;
    c->B = uVar2;
    uVar1 = uVar10 + iVar40;
    uVar3 = (uVar7 >> 0x15) + uVar7 * 0x800 + uVar5 + uVar4 + uStack_98;
    uStack_98 = (uVar6 >> 0x1a) + uVar6 * 0x40 + iVar9 + uVar8;
    iStack_90 = iStack_90 + -1;
    c->C = uStack_9c;
    c->D = uVar3;
    c->E = uStack_98;
    c->A = uVar1;
    b = b + 0x40;
  } while (iStack_90 != -1);
  return;
}
