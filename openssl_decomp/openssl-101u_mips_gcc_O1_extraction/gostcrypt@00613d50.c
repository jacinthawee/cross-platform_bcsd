
void gostcrypt(int *param_1,byte *param_2,undefined *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  
  iVar7 = *param_1;
  uVar14 = (uint)param_2[1] << 8 | (uint)param_2[2] << 0x10 | (uint)*param_2 |
           (uint)param_2[3] << 0x18;
  iVar1 = param_1[1];
  uVar8 = uVar14 + iVar7;
  iVar2 = param_1[2];
  iVar4 = param_1[3];
  iVar6 = param_1[4];
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^
           ((uint)param_2[5] << 8 | (uint)param_2[6] << 0x10 | (uint)param_2[4] |
           (uint)param_2[7] << 0x18);
  uVar8 = uVar12 + iVar1;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = uVar14 + iVar2;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = uVar12 + iVar4;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = uVar14 + iVar6;
  iVar9 = param_1[5];
  iVar10 = param_1[6];
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  iVar13 = param_1[7];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = uVar12 + iVar9;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = uVar14 + iVar10;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = uVar12 + iVar13;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar7 + uVar14;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar1 + uVar12;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar2 + uVar14;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar4 + uVar12;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar6 + uVar14;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar9 + uVar12;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar10 + uVar14;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar13 + uVar12;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar7 + uVar14;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar1 + uVar12;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar2 + uVar14;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar4 + uVar12;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar6 + uVar14;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar9 + uVar12;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar10 + uVar14;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar13 + uVar12;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar13 + uVar14;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar10 + uVar12;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar9 + uVar14;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar6 + uVar12;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar4 + uVar14;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar2 + uVar12;
  uVar8 = param_1[(uVar8 >> 0x18) + 8] | param_1[(uVar8 & 0xff) + 0x308] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  uVar8 = iVar1 + uVar14;
  uVar8 = param_1[(uVar8 & 0xff) + 0x308] | param_1[(uVar8 >> 0x18) + 8] |
          param_1[(uVar8 * 0x100 >> 0x18) + 0x108] | param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  uVar12 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar12;
  uVar8 = iVar7 + uVar12;
  uVar5 = param_1[(uVar8 & 0xff) + 0x308];
  uVar3 = param_1[(uVar8 >> 0x18) + 8];
  uVar11 = param_1[(uVar8 * 0x100 >> 0x18) + 0x108];
  uVar8 = param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  *param_3 = (char)uVar12;
  param_3[1] = (char)(uVar12 >> 8);
  uVar8 = uVar5 | uVar3 | uVar11 | uVar8;
  param_3[2] = (char)(uVar12 >> 0x10);
  param_3[3] = (char)(uVar12 >> 0x18);
  uVar14 = (uVar8 >> 0x15) + uVar8 * 0x800 ^ uVar14;
  param_3[4] = (char)uVar14;
  param_3[5] = (char)(uVar14 >> 8);
  param_3[6] = (char)(uVar14 >> 0x10);
  param_3[7] = (char)(uVar14 >> 0x18);
  return;
}

