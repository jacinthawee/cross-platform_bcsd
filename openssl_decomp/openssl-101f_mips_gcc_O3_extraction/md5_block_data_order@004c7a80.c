
void md5_block_data_order(int *param_1,byte *param_2,int param_3)

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
  int local_104;
  int local_100;
  
  local_104 = *param_1;
  uVar1 = param_1[3];
  local_100 = param_3 + -1;
  uVar3 = param_1[1];
  uVar4 = param_1[2];
  if (param_3 != 0) {
    do {
      uVar6 = (uint)param_2[1] << 8 | (uint)param_2[2] << 0x10 | (uint)*param_2 |
              (uint)param_2[3] << 0x18;
      uVar2 = ((uVar4 ^ uVar1) & uVar3 ^ uVar1) + 0xd76aa478 + uVar6 + local_104;
      uVar13 = (uint)param_2[5] << 8 | (uint)param_2[6] << 0x10 | (uint)param_2[4] |
               (uint)param_2[7] << 0x18;
      uVar2 = (uVar2 >> 0x19) + uVar2 * 0x80 + uVar3;
      uVar5 = ((uVar3 ^ uVar4) & uVar2 ^ uVar4) + uVar1 + 0xe8c7b756 + uVar13;
      uVar19 = (uint)param_2[9] << 8 | (uint)param_2[10] << 0x10 | (uint)param_2[8] |
               (uint)param_2[0xb] << 0x18;
      uVar5 = uVar2 + (uVar5 >> 0x14) + uVar5 * 0x1000;
      uVar23 = (uint)param_2[0xd] << 8 | (uint)param_2[0xe] << 0x10 | (uint)param_2[0xc] |
               (uint)param_2[0xf] << 0x18;
      uVar16 = ((uVar2 ^ uVar3) & uVar5 ^ uVar3) + uVar4 + 0x242070db + uVar19;
      uVar17 = uVar5 + (uVar16 >> 0xf) + uVar16 * 0x20000;
      uVar7 = (uint)param_2[0x11] << 8 | (uint)param_2[0x12] << 0x10 | (uint)param_2[0x10] |
              (uint)param_2[0x13] << 0x18;
      uVar16 = ((uVar2 ^ uVar5) & uVar17 ^ uVar2) + uVar3 + 0xc1bdceee + uVar23;
      uVar9 = uVar17 + (uVar16 >> 10) + uVar16 * 0x400000;
      uVar2 = ((uVar5 ^ uVar17) & uVar9 ^ uVar5) + uVar7 + 0xf57c0faf + uVar2;
      uVar14 = (uint)param_2[0x15] << 8 | (uint)param_2[0x16] << 0x10 | (uint)param_2[0x14] |
               (uint)param_2[0x17] << 0x18;
      uVar8 = uVar9 + (uVar2 >> 0x19) + uVar2 * 0x80;
      uVar5 = ((uVar17 ^ uVar9) & uVar8 ^ uVar17) + uVar14 + 0x4787c62a + uVar5;
      uVar2 = (uint)param_2[0x19] << 8 | (uint)param_2[0x1a] << 0x10 | (uint)param_2[0x18] |
              (uint)param_2[0x1b] << 0x18;
      uVar16 = uVar8 + (uVar5 >> 0x14) + uVar5 * 0x1000;
      uVar5 = ((uVar9 ^ uVar8) & uVar16 ^ uVar9) + uVar2 + 0xa8304613 + uVar17;
      uVar11 = (uint)param_2[0x1d] << 8 | (uint)param_2[0x1e] << 0x10 | (uint)param_2[0x1c] |
               (uint)param_2[0x1f] << 0x18;
      uVar17 = uVar16 + (uVar5 >> 0xf) + uVar5 * 0x20000;
      uVar5 = ((uVar8 ^ uVar16) & uVar17 ^ uVar8) + uVar11 + 0xfd469501 + uVar9;
      uVar25 = (uint)param_2[0x21] << 8 | (uint)param_2[0x22] << 0x10 | (uint)param_2[0x20] |
               (uint)param_2[0x23] << 0x18;
      uVar9 = uVar17 + (uVar5 >> 10) + uVar5 * 0x400000;
      uVar5 = ((uVar16 ^ uVar17) & uVar9 ^ uVar16) + uVar25 + 0x698098d8 + uVar8;
      uVar20 = (uint)param_2[0x25] << 8 | (uint)param_2[0x26] << 0x10 | (uint)param_2[0x24] |
               (uint)param_2[0x27] << 0x18;
      uVar8 = uVar9 + (uVar5 >> 0x19) + uVar5 * 0x80;
      uVar5 = ((uVar17 ^ uVar9) & uVar8 ^ uVar17) + uVar20 + 0x8b44f7af + uVar16;
      uVar12 = (uint)param_2[0x29] << 8 | (uint)param_2[0x2a] << 0x10 | (uint)param_2[0x28] |
               (uint)param_2[0x2b] << 0x18;
      uVar16 = uVar8 + (uVar5 >> 0x14) + uVar5 * 0x1000;
      uVar22 = (uint)param_2[0x2d] << 8 | (uint)param_2[0x2e] << 0x10 | (uint)param_2[0x2c] |
               (uint)param_2[0x2f] << 0x18;
      uVar5 = ((uVar9 ^ uVar8) & uVar16 ^ uVar9) + (uVar12 - 0xa44f) + uVar17;
      uVar17 = uVar16 + (uVar5 >> 0xf) + uVar5 * 0x20000;
      uVar24 = (uint)param_2[0x31] << 8 | (uint)param_2[0x32] << 0x10 | (uint)param_2[0x30] |
               (uint)param_2[0x33] << 0x18;
      uVar5 = ((uVar8 ^ uVar16) & uVar17 ^ uVar8) + uVar22 + 0x895cd7be + uVar9;
      uVar9 = uVar17 + (uVar5 >> 10) + uVar5 * 0x400000;
      uVar5 = ((uVar16 ^ uVar17) & uVar9 ^ uVar16) + uVar24 + 0x6b901122 + uVar8;
      uVar18 = (uint)param_2[0x35] << 8 | (uint)param_2[0x36] << 0x10 | (uint)param_2[0x34] |
               (uint)param_2[0x37] << 0x18;
      uVar8 = uVar9 + (uVar5 >> 0x19) + uVar5 * 0x80;
      uVar5 = ((uVar17 ^ uVar9) & uVar8 ^ uVar17) + uVar18 + 0xfd987193 + uVar16;
      uVar21 = (uint)param_2[0x39] << 8 | (uint)param_2[0x3a] << 0x10 | (uint)param_2[0x38] |
               (uint)param_2[0x3b] << 0x18;
      uVar10 = uVar8 + (uVar5 >> 0x14) + uVar5 * 0x1000;
      uVar5 = ((uVar9 ^ uVar8) & uVar10 ^ uVar9) + uVar21 + 0xa679438e + uVar17;
      uVar15 = (uint)param_2[0x3f] << 0x18 |
               (uint)param_2[0x3d] << 8 | (uint)param_2[0x3e] << 0x10 | (uint)param_2[0x3c];
      uVar5 = uVar10 + (uVar5 >> 0xf) + uVar5 * 0x20000;
      uVar16 = ((uVar8 ^ uVar10) & uVar5 ^ uVar8) + uVar15 + 0x49b40821 + uVar9;
      uVar16 = uVar5 + (uVar16 >> 10) + uVar16 * 0x400000;
      uVar8 = ((uVar5 ^ uVar16) & uVar10 ^ uVar5) + uVar13 + 0xf61e2562 + uVar8;
      uVar17 = uVar16 + (uVar8 >> 0x1b) + uVar8 * 0x20;
      uVar8 = ((uVar16 ^ uVar17) & uVar5 ^ uVar16) + uVar2 + 0xc040b340 + uVar10;
      uVar10 = uVar17 + (uVar8 >> 0x17) + uVar8 * 0x200;
      uVar5 = ((uVar17 ^ uVar10) & uVar16 ^ uVar17) + uVar22 + 0x265e5a51 + uVar5;
      uVar8 = uVar10 + (uVar5 >> 0x12) + uVar5 * 0x4000;
      uVar5 = ((uVar10 ^ uVar8) & uVar17 ^ uVar10) + uVar6 + 0xe9b6c7aa + uVar16;
      uVar9 = uVar8 + (uVar5 >> 0xc) + uVar5 * 0x100000;
      uVar5 = ((uVar8 ^ uVar9) & uVar10 ^ uVar8) + uVar14 + 0xd62f105d + uVar17;
      uVar5 = uVar9 + (uVar5 >> 0x1b) + uVar5 * 0x20;
      uVar16 = ((uVar9 ^ uVar5) & uVar8 ^ uVar9) + uVar12 + 0x2441453 + uVar10;
      uVar17 = uVar5 + (uVar16 >> 0x17) + uVar16 * 0x200;
      uVar16 = ((uVar5 ^ uVar17) & uVar9 ^ uVar5) + uVar15 + 0xd8a1e681 + uVar8;
      uVar8 = uVar17 + (uVar16 >> 0x12) + uVar16 * 0x4000;
      uVar16 = ((uVar17 ^ uVar8) & uVar5 ^ uVar17) + uVar7 + 0xe7d3fbc8 + uVar9;
      uVar16 = uVar8 + (uVar16 >> 0xc) + uVar16 * 0x100000;
      uVar5 = ((uVar8 ^ uVar16) & uVar17 ^ uVar8) + uVar20 + 0x21e1cde6 + uVar5;
      uVar5 = uVar16 + (uVar5 >> 0x1b) + uVar5 * 0x20;
      uVar17 = ((uVar16 ^ uVar5) & uVar8 ^ uVar16) + uVar21 + 0xc33707d6 + uVar17;
      uVar17 = uVar5 + (uVar17 >> 0x17) + uVar17 * 0x200;
      uVar8 = ((uVar5 ^ uVar17) & uVar16 ^ uVar5) + uVar23 + 0xf4d50d87 + uVar8;
      uVar8 = uVar17 + (uVar8 >> 0x12) + uVar8 * 0x4000;
      uVar16 = ((uVar17 ^ uVar8) & uVar5 ^ uVar17) + uVar25 + 0x455a14ed + uVar16;
      uVar16 = uVar8 + (uVar16 >> 0xc) + uVar16 * 0x100000;
      uVar5 = ((uVar8 ^ uVar16) & uVar17 ^ uVar8) + uVar18 + 0xa9e3e905 + uVar5;
      uVar5 = uVar16 + (uVar5 >> 0x1b) + uVar5 * 0x20;
      uVar17 = ((uVar16 ^ uVar5) & uVar8 ^ uVar16) + uVar19 + 0xfcefa3f8 + uVar17;
      uVar17 = uVar5 + (uVar17 >> 0x17) + uVar17 * 0x200;
      uVar8 = ((uVar5 ^ uVar17) & uVar16 ^ uVar5) + uVar11 + 0x676f02d9 + uVar8;
      uVar8 = uVar17 + (uVar8 >> 0x12) + uVar8 * 0x4000;
      uVar16 = (uVar5 & (uVar17 ^ uVar8) ^ uVar17) + uVar24 + 0x8d2a4c8a + uVar16;
      uVar16 = uVar8 + (uVar16 >> 0xc) + uVar16 * 0x100000;
      uVar5 = (uVar17 ^ uVar8 ^ uVar16) + (uVar14 - 0x5c6be) + uVar5;
      uVar5 = uVar16 + (uVar5 >> 0x1c) + uVar5 * 0x10;
      uVar17 = (uVar8 ^ uVar16 ^ uVar5) + uVar25 + 0x8771f681 + uVar17;
      uVar17 = uVar5 + (uVar17 >> 0x15) + uVar17 * 0x800;
      uVar8 = (uVar16 ^ uVar5 ^ uVar17) + uVar22 + 0x6d9d6122 + uVar8;
      uVar8 = uVar17 + (uVar8 >> 0x10) + uVar8 * 0x10000;
      uVar16 = (uVar5 ^ uVar17 ^ uVar8) + uVar21 + 0xfde5380c + uVar16;
      uVar16 = uVar8 + (uVar16 >> 9) + uVar16 * 0x800000;
      uVar5 = (uVar17 ^ uVar8 ^ uVar16) + uVar13 + 0xa4beea44 + uVar5;
      uVar5 = uVar16 + (uVar5 >> 0x1c) + uVar5 * 0x10;
      uVar17 = (uVar8 ^ uVar16 ^ uVar5) + uVar7 + 0x4bdecfa9 + uVar17;
      uVar9 = uVar5 + (uVar17 >> 0x15) + uVar17 * 0x800;
      uVar8 = (uVar16 ^ uVar5 ^ uVar9) + uVar11 + 0xf6bb4b60 + uVar8;
      uVar17 = uVar9 + (uVar8 >> 0x10) + uVar8 * 0x10000;
      uVar16 = (uVar5 ^ uVar9 ^ uVar17) + uVar12 + 0xbebfbc70 + uVar16;
      uVar16 = uVar17 + (uVar16 >> 9) + uVar16 * 0x800000;
      uVar5 = (uVar9 ^ uVar17 ^ uVar16) + uVar18 + 0x289b7ec6 + uVar5;
      uVar8 = uVar16 + (uVar5 >> 0x1c) + uVar5 * 0x10;
      uVar5 = (uVar17 ^ uVar16 ^ uVar8) + uVar6 + 0xeaa127fa + uVar9;
      uVar5 = uVar8 + (uVar5 >> 0x15) + uVar5 * 0x800;
      uVar17 = (uVar16 ^ uVar8 ^ uVar5) + uVar23 + 0xd4ef3085 + uVar17;
      uVar17 = uVar5 + (uVar17 >> 0x10) + uVar17 * 0x10000;
      uVar16 = (uVar8 ^ uVar5 ^ uVar17) + uVar2 + 0x4881d05 + uVar16;
      uVar16 = uVar17 + (uVar16 >> 9) + uVar16 * 0x800000;
      uVar8 = (uVar5 ^ uVar17 ^ uVar16) + uVar20 + 0xd9d4d039 + uVar8;
      uVar8 = uVar16 + (uVar8 >> 0x1c) + uVar8 * 0x10;
      uVar5 = (uVar17 ^ uVar16 ^ uVar8) + uVar24 + 0xe6db99e5 + uVar5;
      uVar9 = uVar8 + (uVar5 >> 0x15) + uVar5 * 0x800;
      uVar5 = (uVar16 ^ uVar8 ^ uVar9) + uVar15 + 0x1fa27cf8 + uVar17;
      uVar17 = uVar9 + (uVar5 >> 0x10) + uVar5 * 0x10000;
      uVar5 = (uVar8 ^ uVar9 ^ uVar17) + uVar19 + 0xc4ac5665 + uVar16;
      uVar10 = uVar17 + (uVar5 >> 9) + uVar5 * 0x800000;
      uVar5 = ((~uVar9 | uVar10) ^ uVar17) + uVar6 + 0xf4292244 + uVar8;
      uVar6 = uVar10 + (uVar5 >> 0x1a) + uVar5 * 0x40;
      uVar5 = ((~uVar17 | uVar6) ^ uVar10) + uVar11 + 0x432aff97 + uVar9;
      uVar8 = uVar6 + (uVar5 >> 0x16) + uVar5 * 0x400;
      uVar5 = ((~uVar10 | uVar8) ^ uVar6) + uVar21 + 0xab9423a7 + uVar17;
      uVar16 = uVar8 + (uVar5 >> 0x11) + uVar5 * 0x8000;
      uVar5 = ((~uVar6 | uVar16) ^ uVar8) + uVar14 + 0xfc93a039 + uVar10;
      uVar5 = uVar16 + (uVar5 >> 0xb) + uVar5 * 0x200000;
      uVar6 = ((~uVar8 | uVar5) ^ uVar16) + uVar24 + 0x655b59c3 + uVar6;
      uVar17 = uVar5 + (uVar6 >> 0x1a) + uVar6 * 0x40;
      uVar6 = ((~uVar16 | uVar17) ^ uVar5) + uVar23 + 0x8f0ccc92 + uVar8;
      uVar6 = uVar17 + (uVar6 >> 0x16) + uVar6 * 0x400;
      uVar16 = ((~uVar5 | uVar6) ^ uVar17) + (uVar12 - 0x100b83) + uVar16;
      uVar8 = uVar6 + (uVar16 >> 0x11) + uVar16 * 0x8000;
      uVar5 = ((~uVar17 | uVar8) ^ uVar6) + uVar13 + 0x85845dd1 + uVar5;
      uVar16 = uVar8 + (uVar5 >> 0xb) + uVar5 * 0x200000;
      uVar5 = ((~uVar6 | uVar16) ^ uVar8) + uVar25 + 0x6fa87e4f + uVar17;
      uVar5 = uVar16 + (uVar5 >> 0x1a) + uVar5 * 0x40;
      uVar6 = ((~uVar8 | uVar5) ^ uVar16) + uVar15 + 0xfe2ce6e0 + uVar6;
      uVar17 = uVar5 + (uVar6 >> 0x16) + uVar6 * 0x400;
      uVar2 = ((~uVar16 | uVar17) ^ uVar5) + uVar2 + 0xa3014314 + uVar8;
      uVar6 = uVar17 + (uVar2 >> 0x11) + uVar2 * 0x8000;
      uVar2 = ((~uVar5 | uVar6) ^ uVar17) + uVar18 + 0x4e0811a1 + uVar16;
      uVar16 = uVar6 + (uVar2 >> 0xb) + uVar2 * 0x200000;
      uVar2 = ((~uVar17 | uVar16) ^ uVar6) + uVar7 + 0xf7537e82 + uVar5;
      uVar2 = uVar16 + (uVar2 >> 0x1a) + uVar2 * 0x40;
      uVar5 = ((~uVar6 | uVar2) ^ uVar16) + uVar22 + 0xbd3af235 + uVar17;
      uVar5 = uVar2 + (uVar5 >> 0x16) + uVar5 * 0x400;
      uVar6 = ((~uVar16 | uVar5) ^ uVar2) + uVar19 + 0x2ad7d2bb + uVar6;
      uVar6 = uVar5 + (uVar6 >> 0x11) + uVar6 * 0x8000;
      local_104 = uVar2 + local_104;
      uVar2 = ((~uVar2 | uVar6) ^ uVar5) + uVar20 + 0xeb86d391 + uVar16;
      uVar4 = uVar6 + uVar4;
      uVar3 = (uVar2 >> 0xb) + uVar2 * 0x200000 + uVar6 + uVar3;
      *param_1 = local_104;
      param_1[2] = uVar4;
      param_1[1] = uVar3;
      uVar1 = uVar5 + uVar1;
      local_100 = local_100 + -1;
      param_1[3] = uVar1;
      param_2 = param_2 + 0x40;
    } while (local_100 != -1);
  }
  return;
}

