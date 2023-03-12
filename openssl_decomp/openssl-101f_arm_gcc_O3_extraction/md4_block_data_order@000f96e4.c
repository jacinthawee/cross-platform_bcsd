
void md4_block_data_order(int *param_1,byte *param_2,int param_3)

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
  int local_60;
  int local_2c;
  
  local_2c = param_3 + -1;
  local_60 = *param_1;
  uVar11 = param_1[3];
  uVar3 = param_1[1];
  uVar1 = param_1[2];
  if (param_3 != 0) {
    do {
      uVar7 = (uint)param_2[2] << 0x10 | (uint)param_2[1] << 8 | (uint)*param_2 |
              (uint)param_2[3] << 0x18;
      uVar12 = ((uVar11 ^ uVar1) & uVar3 ^ uVar11) + uVar7 + local_60;
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar8 = (uint)param_2[6] << 0x10 | (uint)param_2[5] << 8 | (uint)param_2[4] |
              (uint)param_2[7] << 0x18;
      uVar4 = ((uVar1 ^ uVar3) & uVar12 ^ uVar1) + uVar8 + uVar11;
      uVar4 = uVar4 >> 0x19 | uVar4 * 0x80;
      uVar20 = (uint)param_2[10] << 0x10 | (uint)param_2[9] << 8 | (uint)param_2[8] |
               (uint)param_2[0xb] << 0x18;
      uVar9 = ((uVar12 ^ uVar3) & uVar4 ^ uVar3) + uVar20 + uVar1;
      uVar9 = uVar9 >> 0x15 | uVar9 * 0x800;
      uVar18 = (uint)param_2[0xe] << 0x10 | (uint)param_2[0xd] << 8 | (uint)param_2[0xc] |
               (uint)param_2[0xf] << 0x18;
      uVar2 = ((uVar4 ^ uVar12) & uVar9 ^ uVar12) + uVar18 + uVar3;
      uVar2 = uVar2 >> 0xd | uVar2 * 0x80000;
      uVar21 = (uint)param_2[0x12] << 0x10 | (uint)param_2[0x11] << 8 | (uint)param_2[0x10] |
               (uint)param_2[0x13] << 0x18;
      uVar12 = (uVar2 & (uVar9 ^ uVar4) ^ uVar4) + uVar12 + uVar21;
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar22 = (uint)param_2[0x16] << 0x10 | (uint)param_2[0x15] << 8 | (uint)param_2[0x14] |
               (uint)param_2[0x17] << 0x18;
      uVar4 = (uVar12 & (uVar2 ^ uVar9) ^ uVar9) + uVar4 + uVar22;
      uVar4 = uVar4 >> 0x19 | uVar4 * 0x80;
      uVar14 = (uint)param_2[0x1a] << 0x10 | (uint)param_2[0x19] << 8 | (uint)param_2[0x18] |
               (uint)param_2[0x1b] << 0x18;
      uVar9 = (uVar4 & (uVar12 ^ uVar2) ^ uVar2) + uVar9 + uVar14;
      uVar9 = uVar9 >> 0x15 | uVar9 * 0x800;
      uVar13 = (uint)param_2[0x1e] << 0x10 | (uint)param_2[0x1d] << 8 | (uint)param_2[0x1c] |
               (uint)param_2[0x1f] << 0x18;
      uVar17 = (uint)param_2[0x22] << 0x10 | (uint)param_2[0x21] << 8 | (uint)param_2[0x20] |
               (uint)param_2[0x23] << 0x18;
      uVar2 = (uVar9 & (uVar4 ^ uVar12) ^ uVar12) + uVar2 + uVar13;
      uVar2 = uVar2 >> 0xd | uVar2 * 0x80000;
      uVar12 = (uVar2 & (uVar9 ^ uVar4) ^ uVar4) + uVar12 + uVar17;
      uVar10 = (uint)param_2[0x26] << 0x10 | (uint)param_2[0x25] << 8 | (uint)param_2[0x24] |
               (uint)param_2[0x27] << 0x18;
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar4 = (uVar12 & (uVar2 ^ uVar9) ^ uVar9) + uVar4 + uVar10;
      uVar4 = uVar4 >> 0x19 | uVar4 * 0x80;
      uVar5 = (uint)param_2[0x2a] << 0x10 | (uint)param_2[0x29] << 8 | (uint)param_2[0x28] |
              (uint)param_2[0x2b] << 0x18;
      uVar9 = ((uVar12 ^ uVar2) & uVar4 ^ uVar2) + uVar9 + uVar5;
      uVar9 = uVar9 >> 0x15 | uVar9 * 0x800;
      uVar6 = (uint)param_2[0x2e] << 0x10 | (uint)param_2[0x2d] << 8 | (uint)param_2[0x2c] |
              (uint)param_2[0x2f] << 0x18;
      uVar2 = ((uVar4 ^ uVar12) & uVar9 ^ uVar12) + uVar2 + uVar6;
      uVar2 = uVar2 >> 0xd | uVar2 * 0x80000;
      uVar16 = (uint)param_2[0x32] << 0x10 | (uint)param_2[0x31] << 8 | (uint)param_2[0x30] |
               (uint)param_2[0x33] << 0x18;
      uVar12 = ((uVar9 ^ uVar4) & uVar2 ^ uVar4) + uVar12 + uVar16;
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar23 = (uint)param_2[0x36] << 0x10 | (uint)param_2[0x35] << 8 | (uint)param_2[0x34] |
               (uint)param_2[0x37] << 0x18;
      uVar4 = ((uVar2 ^ uVar9) & uVar12 ^ uVar9) + uVar4 + uVar23;
      uVar4 = uVar4 >> 0x19 | uVar4 * 0x80;
      uVar15 = (uint)param_2[0x3a] << 0x10 | (uint)param_2[0x39] << 8 | (uint)param_2[0x38] |
               (uint)param_2[0x3b] << 0x18;
      uVar9 = (uVar4 & (uVar12 ^ uVar2) ^ uVar2) + uVar9 + uVar15;
      uVar9 = uVar9 >> 0x15 | uVar9 * 0x800;
      uVar19 = (uint)param_2[0x3e] << 0x10 | (uint)param_2[0x3d] << 8 | (uint)param_2[0x3c] |
               (uint)param_2[0x3f] << 0x18;
      local_2c = local_2c + -1;
      uVar2 = (uVar9 & (uVar4 ^ uVar12) ^ uVar12) + uVar2 + uVar19;
      uVar2 = uVar2 >> 0xd | uVar2 * 0x80000;
      uVar12 = ((uVar9 | uVar4) & uVar2 | uVar9 & uVar4) + uVar12 + uVar7 + 0x5a827999;
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar4 = ((uVar2 | uVar9) & uVar12 | uVar2 & uVar9) + uVar4 + uVar21 + 0x5a827999;
      uVar4 = uVar4 >> 0x1b | uVar4 * 0x20;
      uVar9 = ((uVar12 | uVar2) & uVar4 | uVar12 & uVar2) + uVar9 + uVar17 + 0x5a827999;
      uVar9 = uVar9 >> 0x17 | uVar9 * 0x200;
      uVar2 = ((uVar4 | uVar12) & uVar9 | uVar4 & uVar12) + uVar2 + uVar16 + 0x5a827999;
      uVar2 = uVar2 >> 0x13 | uVar2 * 0x2000;
      uVar12 = ((uVar9 | uVar4) & uVar2 | uVar9 & uVar4) + uVar12 + uVar8 + 0x5a827999;
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar4 = ((uVar2 | uVar9) & uVar12 | uVar2 & uVar9) + uVar4 + uVar22 + 0x5a827999;
      uVar4 = uVar4 >> 0x1b | uVar4 * 0x20;
      uVar9 = (uVar4 & (uVar12 | uVar2) | uVar12 & uVar2) + uVar9 + uVar10 + 0x5a827999;
      uVar9 = uVar9 >> 0x17 | uVar9 * 0x200;
      uVar2 = (uVar9 & (uVar4 | uVar12) | uVar4 & uVar12) + uVar2 + uVar23 + 0x5a827999;
      uVar2 = uVar2 >> 0x13 | uVar2 * 0x2000;
      uVar12 = ((uVar9 | uVar4) & uVar2 | uVar9 & uVar4) + uVar12 + uVar20 + 0x5a827999;
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar4 = ((uVar2 | uVar9) & uVar12 | uVar2 & uVar9) + uVar4 + uVar14 + 0x5a827999;
      uVar4 = uVar4 >> 0x1b | uVar4 * 0x20;
      uVar9 = ((uVar12 | uVar2) & uVar4 | uVar12 & uVar2) + uVar9 + uVar5 + 0x5a827999;
      uVar9 = uVar9 >> 0x17 | uVar9 * 0x200;
      uVar2 = ((uVar4 | uVar12) & uVar9 | uVar4 & uVar12) + uVar2 + uVar15 + 0x5a827999;
      uVar2 = uVar2 >> 0x13 | uVar2 * 0x2000;
      uVar12 = ((uVar9 | uVar4) & uVar2 | uVar9 & uVar4) + uVar12 + uVar18 + 0x5a827999;
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar4 = uVar4 + uVar13 + 0x5a827999 + (uVar12 & (uVar2 | uVar9) | uVar2 & uVar9);
      uVar4 = uVar4 >> 0x1b | uVar4 * 0x20;
      uVar9 = uVar9 + uVar6 + 0x5a827999 + (uVar4 & (uVar12 | uVar2) | uVar12 & uVar2);
      uVar9 = uVar9 >> 0x17 | uVar9 * 0x200;
      uVar2 = uVar2 + uVar19 + 0x5a827999 + (uVar9 & (uVar4 | uVar12) | uVar4 & uVar12);
      uVar2 = uVar2 >> 0x13 | uVar2 * 0x2000;
      uVar12 = uVar12 + uVar7 + 0x6ed9eba1 + (uVar9 ^ uVar4 ^ uVar2);
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar4 = uVar4 + uVar17 + 0x6ed9eba1 + (uVar2 ^ uVar9 ^ uVar12);
      uVar4 = uVar4 >> 0x17 | uVar4 * 0x200;
      uVar9 = uVar9 + uVar21 + 0x6ed9eba1 + (uVar12 ^ uVar2 ^ uVar4);
      uVar9 = uVar9 >> 0x15 | uVar9 * 0x800;
      uVar2 = uVar2 + uVar16 + 0x6ed9eba1 + (uVar4 ^ uVar12 ^ uVar9);
      uVar2 = uVar2 >> 0x11 | uVar2 * 0x8000;
      uVar12 = uVar12 + uVar20 + 0x6ed9eba1 + (uVar9 ^ uVar4 ^ uVar2);
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar4 = uVar4 + uVar5 + 0x6ed9eba1 + (uVar2 ^ uVar9 ^ uVar12);
      uVar4 = uVar4 >> 0x17 | uVar4 * 0x200;
      uVar9 = uVar9 + uVar14 + 0x6ed9eba1 + (uVar12 ^ uVar2 ^ uVar4);
      uVar9 = uVar9 >> 0x15 | uVar9 * 0x800;
      uVar2 = uVar2 + uVar15 + 0x6ed9eba1 + (uVar4 ^ uVar12 ^ uVar9);
      uVar2 = uVar2 >> 0x11 | uVar2 * 0x8000;
      uVar12 = uVar12 + uVar8 + 0x6ed9eba1 + (uVar9 ^ uVar4 ^ uVar2);
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar4 = uVar4 + uVar10 + 0x6ed9eba1 + (uVar2 ^ uVar9 ^ uVar12);
      uVar4 = uVar4 >> 0x17 | uVar4 * 0x200;
      uVar9 = uVar9 + uVar22 + 0x6ed9eba1 + (uVar12 ^ uVar2 ^ uVar4);
      uVar9 = uVar9 >> 0x15 | uVar9 * 0x800;
      uVar2 = uVar2 + uVar23 + 0x6ed9eba1 + (uVar4 ^ uVar12 ^ uVar9);
      uVar2 = uVar2 >> 0x11 | uVar2 * 0x8000;
      uVar12 = uVar12 + uVar18 + 0x6ed9eba1 + (uVar9 ^ uVar4 ^ uVar2);
      uVar12 = uVar12 >> 0x1d | uVar12 * 8;
      uVar4 = uVar4 + uVar6 + 0x6ed9eba1 + (uVar2 ^ uVar9 ^ uVar12);
      uVar4 = uVar4 >> 0x17 | uVar4 * 0x200;
      uVar9 = uVar9 + uVar13 + 0x6ed9eba1 + (uVar12 ^ uVar2 ^ uVar4);
      uVar9 = uVar9 >> 0x15 | uVar9 * 0x800;
      uVar2 = uVar2 + uVar19 + 0x6ed9eba1 + (uVar4 ^ uVar12 ^ uVar9);
      uVar1 = uVar1 + uVar9;
      uVar3 = uVar3 + (uVar2 >> 0x11 | uVar2 * 0x8000);
      local_60 = local_60 + uVar12;
      uVar11 = uVar11 + uVar4;
      *param_1 = local_60;
      param_1[3] = uVar11;
      param_1[2] = uVar1;
      param_1[1] = uVar3;
      param_2 = param_2 + 0x40;
    } while (local_2c != -1);
  }
  return;
}

