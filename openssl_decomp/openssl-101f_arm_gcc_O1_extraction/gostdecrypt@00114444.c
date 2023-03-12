
void gostdecrypt(int *param_1,byte *param_2,undefined *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  uVar11 = (uint)param_2[2] << 0x10 | (uint)param_2[1] << 8 | (uint)*param_2 |
           (uint)param_2[3] << 0x18;
  uVar2 = *param_1 + uVar11;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  iVar4 = param_1[4];
  iVar3 = param_1[2];
  uVar10 = ((uint)param_2[6] << 0x10 | (uint)param_2[5] << 8 | (uint)param_2[4] |
           (uint)param_2[7] << 0x18) ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  iVar1 = param_1[3];
  uVar2 = param_1[1] + uVar10;
  iVar5 = param_1[5];
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  iVar6 = param_1[6];
  iVar8 = param_1[7];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar11 + iVar3;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar1;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar11 + iVar4;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar5;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar11 + iVar6;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar8;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar11 + iVar8;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar6;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar11 + iVar5;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar4;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar11 + iVar1;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar3;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = param_1[1] + uVar11;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = *param_1 + uVar10;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar11 + iVar8;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar6;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar11 + iVar5;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar4;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar11 + iVar1;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = uVar10 + iVar3;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = param_1[1] + uVar11;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = *param_1 + uVar10;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = iVar8 + uVar11;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = iVar6 + uVar10;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = iVar5 + uVar11;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = iVar4 + uVar10;
  uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = iVar1 + uVar11;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = iVar3 + uVar10;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = param_1[1] + uVar11;
  uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  uVar2 = *param_1 + uVar10;
  uVar9 = param_1[(uVar2 & 0xff) + 0x308];
  uVar12 = param_1[(uVar2 >> 0x18) + 8];
  uVar7 = param_1[(uVar2 * 0x100 >> 0x18) + 0x108];
  uVar2 = param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  *param_3 = (char)uVar10;
  uVar2 = uVar9 | uVar12 | uVar7 | uVar2;
  param_3[3] = (char)(uVar10 >> 0x18);
  param_3[1] = (char)(uVar10 >> 8);
  uVar11 = uVar11 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
  param_3[2] = (char)(uVar10 >> 0x10);
  param_3[4] = (char)uVar11;
  param_3[5] = (char)(uVar11 >> 8);
  param_3[6] = (char)(uVar11 >> 0x10);
  param_3[7] = (char)(uVar11 >> 0x18);
  return;
}

