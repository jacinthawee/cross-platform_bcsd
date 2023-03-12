
void gost_dec(int *param_1,byte *param_2,undefined *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int local_30;
  
  if (0 < param_4) {
    local_30 = 0;
    do {
      local_30 = local_30 + 1;
      uVar10 = (uint)param_2[2] << 0x10 | (uint)param_2[1] << 8 | (uint)*param_2 |
               (uint)param_2[3] << 0x18;
      uVar2 = *param_1 + uVar10;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      iVar3 = param_1[3];
      iVar4 = param_1[5];
      uVar9 = ((uint)param_2[4] | (uint)param_2[6] << 0x10 | (uint)param_2[5] << 8 |
              (uint)param_2[7] << 0x18) ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      iVar1 = param_1[4];
      uVar2 = param_1[1] + uVar9;
      iVar5 = param_1[6];
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      iVar6 = param_1[7];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = param_1[2] + uVar10;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar9 + iVar3;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar10 + iVar1;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar9 + iVar4;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar10 + iVar5;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar9 + iVar6;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar10 + iVar6;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar9 + iVar5;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar10 + iVar4;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar9 + iVar1;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar10 + iVar3;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = param_1[2] + uVar9;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = param_1[1] + uVar10;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = *param_1 + uVar9;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar10 + iVar6;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar9 + iVar5;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar10 + iVar4;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar9 + iVar1;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = uVar10 + iVar3;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = param_1[2] + uVar9;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = param_1[1] + uVar10;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = *param_1 + uVar9;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = iVar6 + uVar10;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = iVar5 + uVar9;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = iVar4 + uVar10;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = iVar1 + uVar9;
      uVar2 = param_1[(uVar2 * 0x100 >> 0x18) + 0x108] |
              param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = iVar3 + uVar10;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = param_1[2] + uVar9;
      uVar2 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = param_1[1] + uVar10;
      uVar2 = param_1[(uVar2 >> 0x18) + 8] | param_1[(uVar2 & 0xff) + 0x308] |
              param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      uVar9 = uVar9 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      uVar2 = *param_1 + uVar9;
      uVar8 = param_1[(uVar2 & 0xff) + 0x308];
      uVar7 = param_1[(uVar2 >> 0x18) + 8];
      uVar11 = param_1[(uVar2 * 0x100 >> 0x18) + 0x108];
      uVar2 = param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
      *param_3 = (char)uVar9;
      uVar2 = uVar8 | uVar7 | uVar11 | uVar2;
      param_3[2] = (char)(uVar9 >> 0x10);
      param_3[3] = (char)(uVar9 >> 0x18);
      uVar10 = uVar10 ^ (uVar2 >> 0x15 | uVar2 << 0xb);
      param_3[1] = (char)(uVar9 >> 8);
      param_3[4] = (char)uVar10;
      param_3[5] = (char)(uVar10 >> 8);
      param_3[6] = (char)(uVar10 >> 0x10);
      param_3[7] = (char)(uVar10 >> 0x18);
      param_3 = param_3 + 8;
      param_2 = param_2 + 8;
    } while (local_30 != param_4);
  }
  return;
}

