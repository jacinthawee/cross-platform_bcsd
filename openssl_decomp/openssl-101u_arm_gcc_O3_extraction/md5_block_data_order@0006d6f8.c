
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
  uint local_68;
  uint local_64;
  int local_30;
  int local_2c;
  
  local_2c = param_3 + -1;
  local_30 = *param_1;
  local_68 = param_1[2];
  local_64 = param_1[3];
  uVar4 = param_1[1];
  if (param_3 != 0) {
    do {
      uVar5 = (uint)param_2[2] << 0x10 | (uint)param_2[1] << 8 | (uint)*param_2 |
              (uint)param_2[3] << 0x18;
      uVar12 = ((local_64 ^ local_68) & uVar4 ^ local_64) + 0xd76aa478 + uVar5 + local_30;
      uVar6 = (uint)param_2[6] << 0x10 | (uint)param_2[5] << 8 | (uint)param_2[4] |
              (uint)param_2[7] << 0x18;
      uVar13 = uVar4 + (uVar12 >> 0x19 | uVar12 * 0x80);
      uVar12 = (uVar13 & (local_68 ^ uVar4) ^ local_68) + local_64 + 0xe8c7b756 + uVar6;
      uVar17 = uVar13 + (uVar12 >> 0x14 | uVar12 * 0x1000);
      uVar9 = (uint)param_2[10] << 0x10 | (uint)param_2[9] << 8 | (uint)param_2[8] |
              (uint)param_2[0xb] << 0x18;
      uVar12 = local_68 + 0x242070db + uVar9 + (uVar17 & (uVar13 ^ uVar4) ^ uVar4);
      uVar7 = uVar17 + (uVar12 >> 0xf | uVar12 * 0x20000);
      uVar8 = (uint)param_2[0xe] << 0x10 | (uint)param_2[0xd] << 8 | (uint)param_2[0xc] |
              (uint)param_2[0xf] << 0x18;
      uVar12 = uVar4 + 0xc1bdceee + uVar8 + (uVar7 & (uVar17 ^ uVar13) ^ uVar13);
      uVar1 = (uint)param_2[0x10] | (uint)param_2[0x12] << 0x10 | (uint)param_2[0x11] << 8 |
              (uint)param_2[0x13] << 0x18;
      uVar12 = uVar7 + (uVar12 >> 10 | uVar12 * 0x400000);
      uVar13 = uVar1 + 0xf57c0faf + uVar13 + ((uVar7 ^ uVar17) & uVar12 ^ uVar17);
      uVar10 = uVar12 + (uVar13 >> 0x19 | uVar13 * 0x80);
      uVar2 = (uint)param_2[0x16] << 0x10 | (uint)param_2[0x15] << 8 | (uint)param_2[0x14] |
              (uint)param_2[0x17] << 0x18;
      uVar13 = uVar2 + 0x4787c62a + uVar17 + (uVar10 & (uVar12 ^ uVar7) ^ uVar7);
      uVar17 = uVar10 + (uVar13 >> 0x14 | uVar13 * 0x1000);
      uVar3 = (uint)param_2[0x1a] << 0x10 | (uint)param_2[0x19] << 8 | (uint)param_2[0x18] |
              (uint)param_2[0x1b] << 0x18;
      uVar7 = uVar3 + 0xa8304613 + uVar7 + (uVar17 & (uVar10 ^ uVar12) ^ uVar12);
      uVar7 = uVar17 + (uVar7 >> 0xf | uVar7 * 0x20000);
      uVar21 = (uint)param_2[0x1e] << 0x10 | (uint)param_2[0x1d] << 8 | (uint)param_2[0x1c] |
               (uint)param_2[0x1f] << 0x18;
      uVar12 = uVar21 + 0xfd469501 + uVar12 + (uVar7 & (uVar17 ^ uVar10) ^ uVar10);
      uVar13 = uVar7 + (uVar12 >> 10 | uVar12 * 0x400000);
      uVar12 = (uint)param_2[0x22] << 0x10 | (uint)param_2[0x21] << 8 | (uint)param_2[0x20] |
               (uint)param_2[0x23] << 0x18;
      uVar10 = uVar12 + 0x698098d8 + uVar10 + (uVar13 & (uVar7 ^ uVar17) ^ uVar17);
      uVar10 = uVar13 + (uVar10 >> 0x19 | uVar10 * 0x80);
      uVar22 = (uint)param_2[0x26] << 0x10 | (uint)param_2[0x25] << 8 | (uint)param_2[0x24] |
               (uint)param_2[0x27] << 0x18;
      uVar17 = (uVar10 & (uVar13 ^ uVar7) ^ uVar7) + uVar17 + uVar22 + 0x8b44f7af;
      uVar18 = (uint)param_2[0x2a] << 0x10 | (uint)param_2[0x29] << 8 | (uint)param_2[0x28] |
               (uint)param_2[0x2b] << 0x18;
      uVar23 = uVar10 + (uVar17 >> 0x14 | uVar17 * 0x1000);
      uVar7 = uVar7 + (uVar18 - 0xa44f) + (uVar23 & (uVar10 ^ uVar13) ^ uVar13);
      uVar17 = uVar23 + (uVar7 >> 0xf | uVar7 * 0x20000);
      uVar7 = (uint)param_2[0x2c] | (uint)param_2[0x2e] << 0x10 | (uint)param_2[0x2d] << 8 |
              (uint)param_2[0x2f] << 0x18;
      uVar13 = uVar7 + 0x895cd7be + uVar13 + ((uVar23 ^ uVar10) & uVar17 ^ uVar10);
      uVar19 = uVar17 + (uVar13 >> 10 | uVar13 * 0x400000);
      uVar15 = (uint)param_2[0x32] << 0x10 | (uint)param_2[0x31] << 8 | (uint)param_2[0x30] |
               (uint)param_2[0x33] << 0x18;
      uVar13 = uVar15 + 0x6b901122 + uVar10 + (uVar19 & (uVar17 ^ uVar23) ^ uVar23);
      uVar13 = uVar19 + (uVar13 >> 0x19 | uVar13 * 0x80);
      uVar14 = (uint)param_2[0x36] << 0x10 | (uint)param_2[0x35] << 8 | (uint)param_2[0x34] |
               (uint)param_2[0x37] << 0x18;
      uVar10 = uVar14 + 0xfd987193 + uVar23 + ((uVar19 ^ uVar17) & uVar13 ^ uVar17);
      uVar23 = uVar13 + (uVar10 >> 0x14 | uVar10 * 0x1000);
      uVar16 = (uint)param_2[0x3a] << 0x10 | (uint)param_2[0x39] << 8 | (uint)param_2[0x38] |
               (uint)param_2[0x3b] << 0x18;
      uVar17 = ((uVar13 ^ uVar19) & uVar23 ^ uVar19) + uVar17 + uVar16 + 0xa679438e;
      uVar17 = uVar23 + (uVar17 >> 0xf | uVar17 * 0x20000);
      uVar24 = (uint)param_2[0x3e] << 0x10 | (uint)param_2[0x3d] << 8 | (uint)param_2[0x3c] |
               (uint)param_2[0x3f] << 0x18;
      local_2c = local_2c + -1;
      uVar10 = ((uVar23 ^ uVar13) & uVar17 ^ uVar13) + uVar19 + uVar24 + 0x49b40821;
      uVar10 = uVar17 + (uVar10 >> 10 | uVar10 * 0x400000);
      uVar13 = uVar13 + uVar6 + 0xf61e2562 + ((uVar10 ^ uVar17) & uVar23 ^ uVar17);
      uVar11 = uVar10 + (uVar13 >> 0x1b | uVar13 * 0x20);
      uVar13 = uVar23 + uVar3 + 0xc040b340 + ((uVar11 ^ uVar10) & uVar17 ^ uVar10);
      uVar19 = uVar11 + (uVar13 >> 0x17 | uVar13 * 0x200);
      uVar13 = uVar17 + uVar7 + 0x265e5a51 + (uVar10 & (uVar19 ^ uVar11) ^ uVar11);
      uVar23 = uVar19 + (uVar13 >> 0x12 | uVar13 * 0x4000);
      uVar13 = uVar5 + 0xe9b6c7aa + uVar10 + (uVar11 & (uVar23 ^ uVar19) ^ uVar19);
      uVar20 = uVar23 + (uVar13 >> 0xc | uVar13 * 0x100000);
      uVar13 = uVar2 + 0xd62f105d + uVar11 + (uVar19 & (uVar20 ^ uVar23) ^ uVar23);
      uVar13 = uVar20 + (uVar13 >> 0x1b | uVar13 * 0x20);
      uVar17 = ((uVar13 ^ uVar20) & uVar23 ^ uVar20) + uVar18 + 0x2441453 + uVar19;
      uVar17 = uVar13 + (uVar17 >> 0x17 | uVar17 * 0x200);
      uVar10 = ((uVar17 ^ uVar13) & uVar20 ^ uVar13) + uVar24 + 0xd8a1e681 + uVar23;
      uVar10 = uVar17 + (uVar10 >> 0x12 | uVar10 * 0x4000);
      uVar23 = ((uVar10 ^ uVar17) & uVar13 ^ uVar17) + uVar1 + 0xe7d3fbc8 + uVar20;
      uVar11 = uVar10 + (uVar23 >> 0xc | uVar23 * 0x100000);
      uVar13 = ((uVar11 ^ uVar10) & uVar17 ^ uVar10) + uVar22 + 0x21e1cde6 + uVar13;
      uVar19 = uVar11 + (uVar13 >> 0x1b | uVar13 * 0x20);
      uVar13 = ((uVar19 ^ uVar11) & uVar10 ^ uVar11) + uVar16 + 0xc33707d6 + uVar17;
      uVar23 = uVar19 + (uVar13 >> 0x17 | uVar13 * 0x200);
      uVar13 = uVar8 + 0xf4d50d87 + uVar10 + ((uVar23 ^ uVar19) & uVar11 ^ uVar19);
      uVar13 = uVar23 + (uVar13 >> 0x12 | uVar13 * 0x4000);
      uVar17 = uVar12 + 0x455a14ed + uVar11 + (uVar19 & (uVar13 ^ uVar23) ^ uVar23);
      uVar17 = uVar13 + (uVar17 >> 0xc | uVar17 * 0x100000);
      uVar10 = uVar14 + 0xa9e3e905 + uVar19 + (uVar23 & (uVar17 ^ uVar13) ^ uVar13);
      uVar10 = uVar17 + (uVar10 >> 0x1b | uVar10 * 0x20);
      uVar23 = uVar9 + 0xfcefa3f8 + uVar23 + (uVar13 & (uVar10 ^ uVar17) ^ uVar17);
      uVar19 = uVar10 + (uVar23 >> 0x17 | uVar23 * 0x200);
      uVar13 = uVar21 + 0x676f02d9 + uVar13 + (uVar17 & (uVar19 ^ uVar10) ^ uVar10);
      uVar23 = uVar19 + (uVar13 >> 0x12 | uVar13 * 0x4000);
      uVar13 = uVar15 + 0x8d2a4c8a + uVar17 + (uVar10 & (uVar23 ^ uVar19) ^ uVar19);
      uVar17 = uVar23 + (uVar13 >> 0xc | uVar13 * 0x100000);
      uVar13 = (uVar23 ^ uVar19 ^ uVar17) + (uVar2 - 0x5c6be) + uVar10;
      uVar13 = uVar17 + (uVar13 >> 0x1c | uVar13 * 0x10);
      uVar10 = (uVar23 ^ uVar17 ^ uVar13) + uVar12 + 0x8771f681 + uVar19;
      uVar19 = uVar13 + (uVar10 >> 0x15 | uVar10 * 0x800);
      uVar10 = (uVar17 ^ uVar13 ^ uVar19) + uVar7 + 0x6d9d6122 + uVar23;
      uVar23 = uVar19 + (uVar10 >> 0x10 | uVar10 * 0x10000);
      uVar17 = (uVar13 ^ uVar19 ^ uVar23) + uVar16 + 0xfde5380c + uVar17;
      uVar17 = uVar23 + (uVar17 >> 9 | uVar17 * 0x800000);
      uVar13 = uVar6 + 0xa4beea44 + uVar13 + (uVar19 ^ uVar23 ^ uVar17);
      uVar10 = uVar17 + (uVar13 >> 0x1c | uVar13 * 0x10);
      uVar13 = (uVar23 ^ uVar17 ^ uVar10) + uVar1 + 0x4bdecfa9 + uVar19;
      uVar19 = uVar10 + (uVar13 >> 0x15 | uVar13 * 0x800);
      uVar13 = (uVar17 ^ uVar10 ^ uVar19) + uVar21 + 0xf6bb4b60 + uVar23;
      uVar13 = uVar19 + (uVar13 >> 0x10 | uVar13 * 0x10000);
      uVar17 = (uVar10 ^ uVar19 ^ uVar13) + uVar18 + 0xbebfbc70 + uVar17;
      uVar23 = uVar13 + (uVar17 >> 9 | uVar17 * 0x800000);
      uVar17 = (uVar19 ^ uVar13 ^ uVar23) + uVar14 + 0x289b7ec6 + uVar10;
      uVar11 = uVar23 + (uVar17 >> 0x1c | uVar17 * 0x10);
      uVar17 = (uVar13 ^ uVar23 ^ uVar11) + uVar5 + 0xeaa127fa + uVar19;
      uVar17 = uVar11 + (uVar17 >> 0x15 | uVar17 * 0x800);
      uVar13 = (uVar23 ^ uVar11 ^ uVar17) + uVar8 + 0xd4ef3085 + uVar13;
      uVar10 = uVar17 + (uVar13 >> 0x10 | uVar13 * 0x10000);
      uVar13 = (uVar11 ^ uVar17 ^ uVar10) + uVar3 + 0x4881d05 + uVar23;
      uVar23 = uVar10 + (uVar13 >> 9 | uVar13 * 0x800000);
      uVar13 = (uVar17 ^ uVar10 ^ uVar23) + uVar22 + 0xd9d4d039 + uVar11;
      uVar13 = uVar23 + (uVar13 >> 0x1c | uVar13 * 0x10);
      uVar17 = uVar15 + 0xe6db99e5 + uVar17 + (uVar10 ^ uVar23 ^ uVar13);
      uVar17 = uVar13 + (uVar17 >> 0x15 | uVar17 * 0x800);
      uVar10 = (uVar23 ^ uVar13 ^ uVar17) + uVar24 + 0x1fa27cf8 + uVar10;
      uVar19 = uVar17 + (uVar10 >> 0x10 | uVar10 * 0x10000);
      uVar10 = uVar9 + 0xc4ac5665 + uVar23 + (uVar13 ^ uVar17 ^ uVar19);
      uVar23 = uVar19 + (uVar10 >> 9 | uVar10 * 0x800000);
      uVar13 = uVar5 + 0xf4292244 + uVar13 + ((uVar23 | ~uVar17) ^ uVar19);
      uVar10 = uVar23 + (uVar13 >> 0x1a | uVar13 * 0x40);
      uVar13 = uVar21 + 0x432aff97 + uVar17 + ((uVar10 | ~uVar19) ^ uVar23);
      uVar13 = uVar10 + (uVar13 >> 0x16 | uVar13 * 0x400);
      uVar17 = uVar16 + 0xab9423a7 + uVar19 + ((uVar13 | ~uVar23) ^ uVar10);
      uVar17 = uVar13 + (uVar17 >> 0x11 | uVar17 * 0x8000);
      uVar2 = uVar2 + 0xfc93a039 + uVar23 + ((uVar17 | ~uVar10) ^ uVar13);
      uVar5 = uVar17 + (uVar2 >> 0xb | uVar2 * 0x200000);
      uVar2 = uVar15 + 0x655b59c3 + uVar10 + ((uVar5 | ~uVar13) ^ uVar17);
      uVar2 = uVar5 + (uVar2 >> 0x1a | uVar2 * 0x40);
      uVar13 = ((uVar2 | ~uVar17) ^ uVar5) + uVar8 + 0x8f0ccc92 + uVar13;
      uVar13 = uVar2 + (uVar13 >> 0x16 | uVar13 * 0x400);
      uVar17 = (uVar18 - 0x100b83) + uVar17 + ((uVar13 | ~uVar5) ^ uVar2);
      uVar10 = uVar13 + (uVar17 >> 0x11 | uVar17 * 0x8000);
      uVar17 = uVar6 + 0x85845dd1 + uVar5 + ((uVar10 | ~uVar2) ^ uVar13);
      uVar17 = uVar10 + (uVar17 >> 0xb | uVar17 * 0x200000);
      uVar12 = ((uVar17 | ~uVar13) ^ uVar10) + uVar12 + 0x6fa87e4f + uVar2;
      uVar12 = uVar17 + (uVar12 >> 0x1a | uVar12 * 0x40);
      uVar13 = ((uVar12 | ~uVar10) ^ uVar17) + uVar24 + 0xfe2ce6e0 + uVar13;
      uVar5 = uVar12 + (uVar13 >> 0x16 | uVar13 * 0x400);
      uVar13 = ((uVar5 | ~uVar17) ^ uVar12) + uVar3 + 0xa3014314 + uVar10;
      uVar2 = uVar5 + (uVar13 >> 0x11 | uVar13 * 0x8000);
      uVar13 = ((uVar2 | ~uVar12) ^ uVar5) + uVar14 + 0x4e0811a1 + uVar17;
      uVar13 = uVar2 + (uVar13 >> 0xb | uVar13 * 0x200000);
      uVar12 = uVar1 + 0xf7537e82 + uVar12 + ((uVar13 | ~uVar5) ^ uVar2);
      uVar1 = uVar13 + (uVar12 >> 0x1a | uVar12 * 0x40);
      local_30 = local_30 + uVar1;
      uVar12 = uVar7 + 0xbd3af235 + uVar5 + ((uVar1 | ~uVar2) ^ uVar13);
      uVar7 = uVar1 + (uVar12 >> 0x16 | uVar12 * 0x400);
      local_64 = local_64 + uVar7;
      uVar12 = uVar9 + 0x2ad7d2bb + uVar2 + ((uVar7 | ~uVar13) ^ uVar1);
      *param_1 = local_30;
      uVar12 = uVar7 + (uVar12 >> 0x11 | uVar12 * 0x8000);
      local_68 = local_68 + uVar12;
      param_1[3] = local_64;
      uVar7 = uVar22 + 0xeb86d391 + uVar13 + ((uVar12 | ~uVar1) ^ uVar7);
      param_1[2] = local_68;
      uVar4 = uVar4 + uVar12 + (uVar7 >> 0xb | uVar7 * 0x200000);
      param_1[1] = uVar4;
      param_2 = param_2 + 0x40;
    } while (local_2c != -1);
  }
  return;
}

