
void gost_enc_with_key(uint *param_1,byte *param_2,byte *param_3,undefined *param_4)

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
  
  uVar8 = (uint)param_2[2] << 0x10 | (uint)param_2[3] << 0x18 | (uint)*param_2 |
          (uint)param_2[1] << 8;
  *param_1 = uVar8;
  uVar3 = (uint)param_2[6] << 0x10 | (uint)param_2[5] << 8 | (uint)param_2[4] |
          (uint)param_2[7] << 0x18;
  param_1[1] = uVar3;
  uVar4 = (uint)param_2[10] << 0x10 | (uint)param_2[9] << 8 | (uint)param_2[8] |
          (uint)param_2[0xb] << 0x18;
  param_1[2] = uVar4;
  uVar5 = (uint)param_2[0xe] << 0x10 | (uint)param_2[0xd] << 8 | (uint)param_2[0xc] |
          (uint)param_2[0xf] << 0x18;
  param_1[3] = uVar5;
  uVar6 = (uint)param_2[0x12] << 0x10 | (uint)param_2[0x11] << 8 | (uint)param_2[0x10] |
          (uint)param_2[0x13] << 0x18;
  param_1[4] = uVar6;
  uVar2 = (uint)param_2[0x16] << 0x10 | (uint)param_2[0x15] << 8 | (uint)param_2[0x14] |
          (uint)param_2[0x17] << 0x18;
  param_1[5] = uVar2;
  uVar7 = (uint)param_2[0x1a] << 0x10 | (uint)param_2[0x19] << 8 | (uint)param_2[0x18] |
          (uint)param_2[0x1b] << 0x18;
  param_1[6] = uVar7;
  uVar1 = (uint)param_2[0x1e] << 0x10 | (uint)param_2[0x1d] << 8 | (uint)param_2[0x1c] |
          (uint)param_2[0x1f] << 0x18;
  param_1[7] = uVar1;
  uVar10 = (uint)param_3[2] << 0x10 | (uint)param_3[1] << 8 | (uint)*param_3 |
           (uint)param_3[3] << 0x18;
  uVar9 = uVar8 + uVar10;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = ((uint)param_3[6] << 0x10 | (uint)param_3[5] << 8 | (uint)param_3[4] |
           (uint)param_3[7] << 0x18) ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar3 + uVar11;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar4 + uVar10;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar5 + uVar11;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar6 + uVar10;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar11 + uVar2;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar10 + uVar7;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar1 + uVar11;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar8 + uVar10;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar3 + uVar11;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar4 + uVar10;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar5 + uVar11;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar6 + uVar10;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar11 + uVar2;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar10 + uVar7;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar1 + uVar11;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar8 + uVar10;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar3 + uVar11;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar4 + uVar10;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar5 + uVar11;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar6 + uVar10;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar11 + uVar2;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar10 + uVar7;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar9 = uVar1 + uVar11;
  uVar9 = param_1[(uVar9 & 0xff) + 0x308] | param_1[(uVar9 >> 0x18) + 8] |
          param_1[(uVar9 * 0x100 >> 0x18) + 0x108] | param_1[(uVar9 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar9 >> 0x15 | uVar9 << 0xb);
  uVar1 = uVar1 + uVar10;
  uVar1 = param_1[(uVar1 & 0xff) + 0x308] | param_1[(uVar1 >> 0x18) + 8] |
          param_1[(uVar1 * 0x100 >> 0x18) + 0x108] | param_1[(uVar1 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
  uVar7 = uVar7 + uVar11;
  uVar1 = param_1[(uVar7 * 0x10000 >> 0x18) + 0x208] |
          param_1[(uVar7 & 0xff) + 0x308] | param_1[(uVar7 >> 0x18) + 8] |
          param_1[(uVar7 * 0x100 >> 0x18) + 0x108];
  uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
  uVar2 = uVar2 + uVar10;
  uVar1 = param_1[(uVar2 & 0xff) + 0x308] | param_1[(uVar2 >> 0x18) + 8] |
          param_1[(uVar2 * 0x100 >> 0x18) + 0x108] | param_1[(uVar2 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
  uVar6 = uVar6 + uVar11;
  uVar1 = param_1[(uVar6 >> 0x18) + 8] | param_1[(uVar6 & 0xff) + 0x308] |
          param_1[(uVar6 * 0x100 >> 0x18) + 0x108] | param_1[(uVar6 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
  uVar5 = uVar5 + uVar10;
  uVar1 = param_1[(uVar5 >> 0x18) + 8] | param_1[(uVar5 & 0xff) + 0x308] |
          param_1[(uVar5 * 0x100 >> 0x18) + 0x108] | param_1[(uVar5 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
  uVar4 = uVar4 + uVar11;
  uVar1 = param_1[(uVar4 & 0xff) + 0x308] | param_1[(uVar4 >> 0x18) + 8] |
          param_1[(uVar4 * 0x100 >> 0x18) + 0x108] | param_1[(uVar4 * 0x10000 >> 0x18) + 0x208];
  uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
  uVar3 = uVar3 + uVar10;
  uVar1 = param_1[(uVar3 >> 0x18) + 8] | param_1[(uVar3 & 0xff) + 0x308] |
          param_1[(uVar3 * 0x100 >> 0x18) + 0x108] | param_1[(uVar3 * 0x10000 >> 0x18) + 0x208];
  uVar11 = uVar11 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
  uVar8 = uVar8 + uVar11;
  uVar5 = param_1[(uVar8 & 0xff) + 0x308];
  uVar4 = param_1[(uVar8 >> 0x18) + 8];
  uVar6 = param_1[(uVar8 * 0x100 >> 0x18) + 0x108];
  uVar1 = param_1[(uVar8 * 0x10000 >> 0x18) + 0x208];
  *param_4 = (char)uVar11;
  uVar1 = uVar5 | uVar4 | uVar6 | uVar1;
  param_4[3] = (char)(uVar11 >> 0x18);
  param_4[1] = (char)(uVar11 >> 8);
  uVar10 = uVar10 ^ (uVar1 >> 0x15 | uVar1 << 0xb);
  param_4[2] = (char)(uVar11 >> 0x10);
  param_4[4] = (char)uVar10;
  param_4[5] = (char)(uVar10 >> 8);
  param_4[6] = (char)(uVar10 >> 0x10);
  param_4[7] = (char)(uVar10 >> 0x18);
  return;
}

