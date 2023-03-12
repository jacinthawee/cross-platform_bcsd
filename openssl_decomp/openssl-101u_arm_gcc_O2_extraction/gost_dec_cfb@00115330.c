
void gost_dec_cfb(int *param_1,byte *param_2,byte *param_3,byte *param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint local_30;
  int local_2c;
  
  bVar1 = *param_2;
  bVar8 = param_2[2];
  bVar2 = param_2[3];
  bVar3 = param_2[4];
  bVar4 = param_2[1];
  bVar5 = param_2[5];
  bVar6 = param_2[6];
  bVar7 = param_2[7];
  if (0 < param_5) {
    local_2c = 0;
    do {
      local_30 = (uint)bVar1;
      uVar18 = (uint)bVar8 << 0x10 | (uint)bVar4 << 8 | local_30 | (uint)bVar2 << 0x18;
      uVar11 = *param_1 + uVar18;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      iVar12 = param_1[3];
      uVar19 = ((uint)bVar3 | (uint)bVar6 << 0x10 | (uint)bVar5 << 8 | (uint)bVar7 << 0x18) ^
               (uVar11 >> 0x15 | uVar11 << 0xb);
      local_2c = local_2c + 1;
      uVar11 = param_1[1] + uVar19;
      bVar1 = *param_3;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      iVar10 = param_1[4];
      iVar9 = param_1[5];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      iVar14 = param_1[6];
      uVar11 = param_1[2] + uVar18;
      iVar16 = param_1[7];
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar19 + iVar12;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar18 + iVar10;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar19 + iVar9;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar18 + iVar14;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar19 + iVar16;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = *param_1 + uVar18;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = param_1[1] + uVar19;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = param_1[2] + uVar18;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar19 + iVar12;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar18 + iVar10;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar19 + iVar9;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar18 + iVar14;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar19 + iVar16;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = *param_1 + uVar18;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = param_1[1] + uVar19;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = param_1[2] + uVar18;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar19 + iVar12;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar18 + iVar10;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar19 + iVar9;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar18 + iVar14;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = uVar19 + iVar16;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = iVar16 + uVar18;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = iVar14 + uVar19;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = iVar9 + uVar18;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = iVar10 + uVar19;
      uVar11 = param_1[(uVar11 * 0x10000 >> 0x18) + 0x208] |
               param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = iVar12 + uVar18;
      uVar11 = param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = param_1[2] + uVar19;
      uVar11 = param_1[(uVar11 & 0xff) + 0x308] | param_1[(uVar11 >> 0x18) + 8] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar18 = uVar18 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar11 = param_1[1] + uVar18;
      uVar11 = param_1[(uVar11 >> 0x18) + 8] | param_1[(uVar11 & 0xff) + 0x308] |
               param_1[(uVar11 * 0x100 >> 0x18) + 0x108] |
               param_1[(uVar11 * 0x10000 >> 0x18) + 0x208];
      uVar19 = uVar19 ^ (uVar11 >> 0x15 | uVar11 << 0xb);
      uVar13 = *param_1 + uVar19;
      uVar17 = param_1[(uVar13 & 0xff) + 0x308];
      uVar15 = param_1[(uVar13 >> 0x18) + 8];
      uVar11 = param_1[(uVar13 * 0x100 >> 0x18) + 0x108];
      uVar13 = param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      *param_4 = bVar1 ^ (byte)uVar19;
      bVar4 = param_3[1];
      uVar13 = uVar17 | uVar15 | uVar11 | uVar13;
      param_4[1] = bVar4 ^ (byte)(uVar19 >> 8);
      bVar8 = param_3[2];
      uVar18 = uVar18 ^ (uVar13 >> 0x15 | uVar13 << 0xb);
      param_4[2] = bVar8 ^ (byte)(uVar19 >> 0x10);
      bVar2 = param_3[3];
      param_4[3] = bVar2 ^ (byte)(uVar19 >> 0x18);
      bVar3 = param_3[4];
      param_4[4] = bVar3 ^ (byte)uVar18;
      bVar5 = param_3[5];
      param_4[5] = bVar5 ^ (byte)(uVar18 >> 8);
      bVar6 = param_3[6];
      param_4[6] = bVar6 ^ (byte)(uVar18 >> 0x10);
      bVar7 = param_3[7];
      param_4[7] = bVar7 ^ (byte)(uVar18 >> 0x18);
      param_4 = param_4 + 8;
      param_3 = param_3 + 8;
    } while (local_2c != param_5);
  }
  return;
}

