
void CRYPTO_gcm128_init(undefined4 *param_1,undefined4 param_2,code *param_3)

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
  undefined4 *puVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  
  *param_1 = 0;
  puVar17 = (undefined4 *)((uint)(param_1 + 1) & 0xfffffffc);
  for (uVar5 = (uint)((int)param_1 + (0x178 - (int)(undefined4 *)((uint)(param_1 + 1) & 0xfffffffc))
                     ) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar17 = 0;
    puVar17 = puVar17 + 1;
  }
  param_1[0x5c] = param_3;
  param_1[0x5d] = param_2;
  (*param_3)(param_1 + 0x14,param_1 + 0x14,param_2);
  uVar5 = param_1[0x14];
  uVar3 = param_1[0x15];
  uVar1 = uVar5 >> 0x18 | (uVar5 & 0xff0000) >> 8 | (uVar5 & 0xff00) << 8 | uVar5 << 0x18;
  uVar12 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  uVar4 = param_1[0x16];
  uVar6 = param_1[0x17];
  uVar2 = uVar4 >> 0x18 | (uVar4 & 0xff0000) >> 8 | (uVar4 & 0xff00) << 8 | uVar4 << 0x18;
  uVar11 = uVar6 >> 0x18;
  uVar13 = uVar11 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
  param_1[0x14] = uVar12;
  param_1[0x38] = uVar12;
  param_1[0x16] = uVar13;
  param_1[0x17] = uVar2;
  param_1[0x3a] = uVar13;
  param_1[0x3b] = uVar2;
  uVar18 = uVar13 >> 1 | (uVar4 >> 0x18) << 0x1f;
  param_1[0x15] = uVar1;
  param_1[0x39] = uVar1;
  uVar6 = (uVar3 >> 0x18) << 0x1f | uVar2 >> 1;
  param_1[0x18] = 0;
  uVar5 = uVar12 >> 1 | (uVar5 >> 0x18) << 0x1f;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  uVar7 = -(uVar11 & 1) & 0xe1000000 ^ uVar1 >> 1;
  param_1[0x28] = uVar5;
  param_1[0x29] = uVar7;
  param_1[0x2a] = uVar18;
  param_1[0x2b] = uVar6;
  uVar19 = uVar18 >> 1 | (uVar2 >> 1) << 0x1f;
  uVar8 = (uVar12 >> 1) << 0x1f | uVar6 >> 1;
  uVar3 = uVar5 >> 1 | (uVar1 >> 1) << 0x1f;
  param_1[0x22] = uVar19;
  param_1[0x23] = uVar8;
  uVar9 = -((uVar11 & 2) >> 1) & 0xe1000000 ^ uVar7 >> 1;
  uVar20 = uVar19 >> 1 | (uVar6 >> 1) << 0x1f;
  param_1[0x20] = uVar3;
  param_1[0x21] = uVar9;
  uVar14 = (uVar5 >> 1) << 0x1f | uVar8 >> 1;
  uVar10 = uVar3 >> 1 | (uVar7 >> 1) << 0x1f;
  param_1[0x1c] = uVar10;
  uVar4 = -((uVar11 & 4) >> 2) & 0xe1000000 ^ uVar9 >> 1;
  param_1[0x1d] = uVar4;
  param_1[0x1e] = uVar20;
  param_1[0x1f] = uVar14;
  uVar11 = uVar3 ^ uVar10;
  uVar15 = uVar9 ^ uVar4;
  param_1[0x25] = uVar15;
  param_1[0x24] = uVar11;
  uVar16 = uVar20 ^ uVar19;
  uVar21 = uVar8 ^ uVar14;
  param_1[0x26] = uVar16;
  param_1[0x27] = uVar21;
  param_1[0x2c] = uVar5 ^ uVar10;
  param_1[0x2d] = uVar7 ^ uVar4;
  param_1[0x2f] = uVar14 ^ uVar6;
  param_1[0x2e] = uVar20 ^ uVar18;
  param_1[0x3d] = uVar4 ^ uVar1;
  param_1[0x31] = uVar7 ^ uVar9;
  param_1[0x30] = uVar5 ^ uVar3;
  param_1[0x32] = uVar19 ^ uVar18;
  param_1[0x33] = uVar8 ^ uVar6;
  param_1[0x34] = uVar5 ^ uVar11;
  param_1[0x35] = uVar7 ^ uVar15;
  param_1[0x37] = uVar21 ^ uVar6;
  param_1[0x36] = uVar16 ^ uVar18;
  param_1[0x3c] = uVar10 ^ uVar12;
  param_1[0x3e] = uVar20 ^ uVar13;
  param_1[0x40] = uVar12 ^ uVar3;
  param_1[0x3f] = uVar14 ^ uVar2;
  param_1[0x41] = uVar9 ^ uVar1;
  param_1[0x44] = uVar11 ^ uVar12;
  param_1[0x42] = uVar19 ^ uVar13;
  param_1[0x43] = uVar8 ^ uVar2;
  param_1[0x47] = uVar21 ^ uVar2;
  param_1[0x45] = uVar15 ^ uVar1;
  param_1[0x46] = uVar16 ^ uVar13;
  param_1[0x48] = uVar5 ^ uVar12;
  param_1[0x49] = uVar7 ^ uVar1;
  param_1[0x4a] = uVar13 ^ uVar18;
  param_1[0x4b] = uVar2 ^ uVar6;
  param_1[0x4c] = uVar5 ^ uVar10 ^ uVar12;
  param_1[0x4d] = uVar7 ^ uVar4 ^ uVar1;
  param_1[0x4e] = uVar20 ^ uVar18 ^ uVar13;
  param_1[0x4f] = uVar14 ^ uVar6 ^ uVar2;
  param_1[0x50] = uVar5 ^ uVar3 ^ uVar12;
  param_1[0x51] = uVar7 ^ uVar9 ^ uVar1;
  param_1[0x55] = uVar1 ^ uVar7 ^ uVar15;
  param_1[0x52] = uVar19 ^ uVar18 ^ uVar13;
  param_1[0x53] = uVar8 ^ uVar6 ^ uVar2;
  param_1[0x54] = uVar5 ^ uVar11 ^ uVar12;
  param_1[0x56] = uVar16 ^ uVar18 ^ uVar13;
  param_1[0x57] = uVar21 ^ uVar6 ^ uVar2;
  return;
}
