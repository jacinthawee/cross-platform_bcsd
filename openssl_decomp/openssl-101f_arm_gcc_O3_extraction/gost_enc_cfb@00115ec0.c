
void gost_enc_cfb(int *param_1,byte *param_2,byte *param_3,undefined *param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int local_30;
  
  uVar3 = (uint)*param_2;
  uVar14 = (uint)param_2[1];
  uVar13 = (uint)param_2[2];
  uVar8 = (uint)param_2[3];
  uVar12 = (uint)param_2[4];
  uVar10 = (uint)param_2[5];
  uVar6 = (uint)param_2[6];
  uVar1 = (uint)param_2[7];
  if (0 < param_5) {
    local_30 = 0;
    do {
      uVar11 = uVar13 << 0x10 | uVar14 << 8 | uVar3 | uVar8 << 0x18;
      uVar3 = *param_1 + uVar11;
      uVar3 = param_1[(uVar3 & 0xff) + 0x308] | param_1[(uVar3 >> 0x18) + 8] |
              param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
      iVar5 = param_1[3];
      uVar10 = (uVar6 << 0x10 | uVar10 << 8 | uVar12 | uVar1 << 0x18) ^
               (uVar3 >> 0x15 | uVar3 << 0xb);
      local_30 = local_30 + 1;
      uVar1 = param_1[1] + uVar10;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      iVar4 = param_1[4];
      iVar2 = param_1[5];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[2] + uVar11;
      iVar7 = param_1[6];
      iVar9 = param_1[7];
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar10 + iVar5;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar11 + iVar4;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar10 + iVar2;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar11 + iVar7;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar10 + iVar9;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = *param_1 + uVar11;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[1] + uVar10;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[2] + uVar11;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar10 + iVar5;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar11 + iVar4;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar10 + iVar2;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar11 + iVar7;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar10 + iVar9;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = *param_1 + uVar11;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[1] + uVar10;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[2] + uVar11;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar10 + iVar5;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar11 + iVar4;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar10 + iVar2;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar11 + iVar7;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = uVar10 + iVar9;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = iVar9 + uVar11;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = iVar7 + uVar10;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = iVar2 + uVar11;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = iVar4 + uVar10;
      uVar1 = param_1[(uVar1 * 0x10000 >> 0x18) + 0x208] |
              param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = iVar5 + uVar11;
      uVar1 = param_1[(uVar1 * 0x100 >> 0x18) + 0x108] |
              param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[2] + uVar10;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar1 = param_1[1] + uVar11;
      uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
              param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
      uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
      uVar13 = *param_1 + uVar10;
      uVar8 = param_1[(uVar13 & 0xff) + 0x308];
      uVar3 = (*param_3 ^ uVar10) & 0xff;
      uVar1 = param_1[(uVar13 >> 0x18) + 8];
      uVar6 = param_1[(uVar13 * 0x100 >> 0x18) + 0x108];
      uVar13 = param_1[(uVar13 * 0x10000 >> 0x18) + 0x208];
      *param_4 = (char)uVar3;
      uVar13 = uVar1 | uVar8 | uVar6 | uVar13;
      uVar11 = uVar11 ^ (uVar13 >> 0x15 | uVar13 << 0xb);
      uVar14 = ((uint)param_3[1] ^ uVar10 >> 8) & 0xff;
      param_4[1] = (char)uVar14;
      uVar13 = ((uint)param_3[2] ^ uVar10 >> 0x10) & 0xff;
      param_4[2] = (char)uVar13;
      uVar8 = (uint)param_3[3] ^ uVar10 >> 0x18;
      param_4[3] = (char)uVar8;
      uVar12 = (param_3[4] ^ uVar11) & 0xff;
      param_4[4] = (char)uVar12;
      uVar10 = ((uint)param_3[5] ^ uVar11 >> 8) & 0xff;
      param_4[5] = (char)uVar10;
      uVar6 = ((uint)param_3[6] ^ uVar11 >> 0x10) & 0xff;
      param_4[6] = (char)uVar6;
      uVar1 = (uint)param_3[7] ^ uVar11 >> 0x18;
      param_4[7] = (char)uVar1;
      param_4 = param_4 + 8;
      param_3 = param_3 + 8;
    } while (local_30 != param_5);
  }
  return;
}

