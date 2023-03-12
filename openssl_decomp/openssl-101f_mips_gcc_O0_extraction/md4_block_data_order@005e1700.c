
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
  uint local_bc;
  int local_b8;
  int local_a4;
  
  local_b8 = *param_1;
  uVar1 = param_1[1];
  local_a4 = param_3 + -1;
  uVar2 = param_1[2];
  local_bc = param_1[3];
  if (param_3 != 0) {
    do {
      uVar4 = (uint)param_2[1] << 8 | (uint)param_2[2] << 0x10 | (uint)*param_2 |
              (uint)param_2[3] << 0x18;
      uVar3 = ((uVar2 ^ local_bc) & uVar1 ^ local_bc) + uVar4 + local_b8;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar5 = (uint)param_2[5] << 8 | (uint)param_2[6] << 0x10 | (uint)param_2[4] |
              (uint)param_2[7] << 0x18;
      uVar6 = ((uVar1 ^ uVar2) & uVar3 ^ uVar2) + uVar5 + local_bc;
      uVar9 = (uint)param_2[0xd] << 8 | (uint)param_2[0xe] << 0x10 | (uint)param_2[0xc] |
              (uint)param_2[0xf] << 0x18;
      uVar7 = (uVar6 >> 0x19) + uVar6 * 0x80;
      uVar22 = (uint)param_2[9] << 8 | (uint)param_2[10] << 0x10 | (uint)param_2[8] |
               (uint)param_2[0xb] << 0x18;
      uVar6 = ((uVar3 ^ uVar1) & uVar7 ^ uVar1) + uVar22 + uVar2;
      uVar6 = (uVar6 >> 0x15) + uVar6 * 0x800;
      uVar10 = ((uVar3 ^ uVar7) & uVar6 ^ uVar3) + uVar9 + uVar1;
      uVar10 = (uVar10 >> 0xd) + uVar10 * 0x80000;
      uVar8 = (uint)param_2[0x11] << 8 | (uint)param_2[0x12] << 0x10 | (uint)param_2[0x10] |
              (uint)param_2[0x13] << 0x18;
      uVar3 = ((uVar7 ^ uVar6) & uVar10 ^ uVar7) + uVar3 + uVar8;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar16 = (uint)param_2[0x15] << 8 | (uint)param_2[0x16] << 0x10 | (uint)param_2[0x14] |
               (uint)param_2[0x17] << 0x18;
      uVar7 = ((uVar6 ^ uVar10) & uVar3 ^ uVar6) + uVar7 + uVar16;
      uVar20 = (uint)param_2[0x19] << 8 | (uint)param_2[0x1a] << 0x10 | (uint)param_2[0x18] |
               (uint)param_2[0x1b] << 0x18;
      uVar7 = (uVar7 >> 0x19) + uVar7 * 0x80;
      uVar6 = ((uVar10 ^ uVar3) & uVar7 ^ uVar10) + uVar6 + uVar20;
      uVar6 = (uVar6 >> 0x15) + uVar6 * 0x800;
      uVar15 = (uint)param_2[0x1d] << 8 | (uint)param_2[0x1e] << 0x10 | (uint)param_2[0x1c] |
               (uint)param_2[0x1f] << 0x18;
      uVar11 = ((uVar3 ^ uVar7) & uVar6 ^ uVar3) + uVar10 + uVar15;
      uVar10 = (uint)param_2[0x21] << 8 | (uint)param_2[0x22] << 0x10 | (uint)param_2[0x20] |
               (uint)param_2[0x23] << 0x18;
      uVar11 = (uVar11 >> 0xd) + uVar11 * 0x80000;
      uVar3 = ((uVar7 ^ uVar6) & uVar11 ^ uVar7) + uVar3 + uVar10;
      uVar23 = (uint)param_2[0x25] << 8 | (uint)param_2[0x26] << 0x10 | (uint)param_2[0x24] |
               (uint)param_2[0x27] << 0x18;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar7 = ((uVar6 ^ uVar11) & uVar3 ^ uVar6) + uVar7 + uVar23;
      uVar13 = (uint)param_2[0x29] << 8 | (uint)param_2[0x2a] << 0x10 | (uint)param_2[0x28] |
               (uint)param_2[0x2b] << 0x18;
      uVar7 = (uVar7 >> 0x19) + uVar7 * 0x80;
      uVar6 = ((uVar11 ^ uVar3) & uVar7 ^ uVar11) + uVar6 + uVar13;
      uVar14 = (uint)param_2[0x2d] << 8 | (uint)param_2[0x2e] << 0x10 | (uint)param_2[0x2c] |
               (uint)param_2[0x2f] << 0x18;
      uVar6 = (uVar6 >> 0x15) + uVar6 * 0x800;
      uVar11 = ((uVar3 ^ uVar7) & uVar6 ^ uVar3) + uVar11 + uVar14;
      uVar11 = (uVar11 >> 0xd) + uVar11 * 0x80000;
      uVar19 = (uint)param_2[0x31] << 8 | (uint)param_2[0x32] << 0x10 | (uint)param_2[0x30] |
               (uint)param_2[0x33] << 0x18;
      uVar3 = ((uVar7 ^ uVar6) & uVar11 ^ uVar7) + uVar3 + uVar19;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar18 = (uint)param_2[0x35] << 8 | (uint)param_2[0x36] << 0x10 | (uint)param_2[0x34] |
               (uint)param_2[0x37] << 0x18;
      uVar7 = ((uVar6 ^ uVar11) & uVar3 ^ uVar6) + uVar7 + uVar18;
      uVar7 = (uVar7 >> 0x19) + uVar7 * 0x80;
      uVar21 = (uint)param_2[0x39] << 8 | (uint)param_2[0x3a] << 0x10 | (uint)param_2[0x38] |
               (uint)param_2[0x3b] << 0x18;
      uVar6 = ((uVar11 ^ uVar3) & uVar7 ^ uVar11) + uVar6 + uVar21;
      uVar6 = (uVar6 >> 0x15) + uVar6 * 0x800;
      uVar17 = (uint)param_2[0x3f] << 0x18 |
               (uint)param_2[0x3d] << 8 | (uint)param_2[0x3e] << 0x10 | (uint)param_2[0x3c];
      uVar11 = ((uVar3 ^ uVar7) & uVar6 ^ uVar3) + uVar11 + uVar17;
      uVar11 = (uVar11 >> 0xd) + uVar11 * 0x80000;
      uVar3 = ((uVar7 | uVar6) & uVar11 | uVar7 & uVar6) + uVar4 + 0x5a827999 + uVar3;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar7 = ((uVar6 | uVar11) & uVar3 | uVar6 & uVar11) + uVar8 + 0x5a827999 + uVar7;
      uVar7 = (uVar7 >> 0x1b) + uVar7 * 0x20;
      uVar6 = ((uVar11 | uVar3) & uVar7 | uVar11 & uVar3) + uVar10 + 0x5a827999 + uVar6;
      uVar6 = (uVar6 >> 0x17) + uVar6 * 0x200;
      uVar11 = ((uVar3 | uVar7) & uVar6 | uVar3 & uVar7) + uVar19 + 0x5a827999 + uVar11;
      uVar11 = (uVar11 >> 0x13) + uVar11 * 0x2000;
      uVar3 = ((uVar7 | uVar6) & uVar11 | uVar7 & uVar6) + uVar5 + 0x5a827999 + uVar3;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar7 = ((uVar6 | uVar11) & uVar3 | uVar6 & uVar11) + uVar16 + 0x5a827999 + uVar7;
      uVar7 = (uVar7 >> 0x1b) + uVar7 * 0x20;
      uVar6 = ((uVar11 | uVar3) & uVar7 | uVar11 & uVar3) + uVar23 + 0x5a827999 + uVar6;
      uVar6 = (uVar6 >> 0x17) + uVar6 * 0x200;
      uVar11 = ((uVar3 | uVar7) & uVar6 | uVar3 & uVar7) + uVar18 + 0x5a827999 + uVar11;
      uVar12 = (uVar11 >> 0x13) + uVar11 * 0x2000;
      uVar3 = ((uVar7 | uVar6) & uVar12 | uVar7 & uVar6) + uVar22 + 0x5a827999 + uVar3;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar7 = ((uVar6 | uVar12) & uVar3 | uVar6 & uVar12) + uVar20 + 0x5a827999 + uVar7;
      uVar7 = (uVar7 >> 0x1b) + uVar7 * 0x20;
      uVar6 = ((uVar12 | uVar3) & uVar7 | uVar12 & uVar3) + uVar13 + 0x5a827999 + uVar6;
      uVar11 = (uVar6 >> 0x17) + uVar6 * 0x200;
      uVar6 = ((uVar3 | uVar7) & uVar11 | uVar3 & uVar7) + uVar21 + 0x5a827999 + uVar12;
      uVar6 = (uVar6 >> 0x13) + uVar6 * 0x2000;
      uVar3 = ((uVar7 | uVar11) & uVar6 | uVar7 & uVar11) + uVar9 + 0x5a827999 + uVar3;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar7 = ((uVar11 | uVar6) & uVar3 | uVar11 & uVar6) + uVar15 + 0x5a827999 + uVar7;
      uVar7 = (uVar7 >> 0x1b) + uVar7 * 0x20;
      uVar11 = ((uVar6 | uVar3) & uVar7 | uVar6 & uVar3) + uVar14 + 0x5a827999 + uVar11;
      uVar11 = (uVar11 >> 0x17) + uVar11 * 0x200;
      uVar6 = ((uVar3 | uVar7) & uVar11 | uVar3 & uVar7) + uVar17 + 0x5a827999 + uVar6;
      uVar6 = (uVar6 >> 0x13) + uVar6 * 0x2000;
      uVar3 = (uVar7 ^ uVar11 ^ uVar6) + uVar4 + 0x6ed9eba1 + uVar3;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar4 = (uVar11 ^ uVar6 ^ uVar3) + uVar10 + 0x6ed9eba1 + uVar7;
      uVar7 = (uVar4 >> 0x17) + uVar4 * 0x200;
      uVar4 = (uVar6 ^ uVar3 ^ uVar7) + uVar8 + 0x6ed9eba1 + uVar11;
      uVar10 = (uVar4 >> 0x15) + uVar4 * 0x800;
      uVar4 = (uVar3 ^ uVar7 ^ uVar10) + uVar19 + 0x6ed9eba1 + uVar6;
      uVar4 = (uVar4 >> 0x11) + uVar4 * 0x8000;
      uVar3 = (uVar7 ^ uVar10 ^ uVar4) + uVar22 + 0x6ed9eba1 + uVar3;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar6 = (uVar10 ^ uVar4 ^ uVar3) + uVar13 + 0x6ed9eba1 + uVar7;
      uVar7 = (uVar6 >> 0x17) + uVar6 * 0x200;
      uVar6 = (uVar4 ^ uVar3 ^ uVar7) + uVar20 + 0x6ed9eba1 + uVar10;
      uVar6 = (uVar6 >> 0x15) + uVar6 * 0x800;
      uVar4 = (uVar3 ^ uVar7 ^ uVar6) + uVar21 + 0x6ed9eba1 + uVar4;
      uVar4 = (uVar4 >> 0x11) + uVar4 * 0x8000;
      uVar3 = (uVar7 ^ uVar6 ^ uVar4) + uVar5 + 0x6ed9eba1 + uVar3;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar5 = (uVar6 ^ uVar4 ^ uVar3) + uVar23 + 0x6ed9eba1 + uVar7;
      uVar5 = (uVar5 >> 0x17) + uVar5 * 0x200;
      uVar6 = (uVar4 ^ uVar3 ^ uVar5) + uVar16 + 0x6ed9eba1 + uVar6;
      uVar6 = (uVar6 >> 0x15) + uVar6 * 0x800;
      uVar4 = (uVar3 ^ uVar5 ^ uVar6) + uVar18 + 0x6ed9eba1 + uVar4;
      uVar4 = (uVar4 >> 0x11) + uVar4 * 0x8000;
      uVar3 = (uVar5 ^ uVar6 ^ uVar4) + uVar9 + 0x6ed9eba1 + uVar3;
      uVar3 = (uVar3 >> 0x1d) + uVar3 * 8;
      uVar5 = (uVar6 ^ uVar4 ^ uVar3) + uVar14 + 0x6ed9eba1 + uVar5;
      uVar5 = (uVar5 >> 0x17) + uVar5 * 0x200;
      uVar6 = (uVar4 ^ uVar3 ^ uVar5) + uVar15 + 0x6ed9eba1 + uVar6;
      uVar6 = (uVar6 >> 0x15) + uVar6 * 0x800;
      uVar4 = (uVar3 ^ uVar5 ^ uVar6) + uVar17 + 0x6ed9eba1 + uVar4;
      uVar2 = uVar6 + uVar2;
      local_b8 = uVar3 + local_b8;
      uVar1 = (uVar4 >> 0x11) + uVar4 * 0x8000 + uVar1;
      *param_1 = local_b8;
      local_bc = uVar5 + local_bc;
      param_1[2] = uVar2;
      local_a4 = local_a4 + -1;
      param_1[3] = local_bc;
      param_1[1] = uVar1;
      param_2 = param_2 + 0x40;
    } while (local_a4 != -1);
  }
  return;
}

