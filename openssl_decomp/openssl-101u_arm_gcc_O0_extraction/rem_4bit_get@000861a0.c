
void rem_4bit_get(uint *param_1,int param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  uint in_r12;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  
  iVar3 = 0xe;
  puVar10 = (uint *)(param_2 + (in_r12 & 0xf) * 0x10);
  puVar13 = (uint *)(param_2 + (in_r12 & 0xf0));
  uVar4 = *puVar13 ^ *puVar10 >> 4 ^ puVar10[1] << 0x1c;
  uVar6 = puVar13[1] ^ puVar10[1] >> 4 ^ puVar10[2] << 0x1c;
  uVar8 = puVar13[2] ^ puVar10[2] >> 4 ^ puVar10[3] << 0x1c;
  uVar15 = *(byte *)((int)param_1 + 0xe) & 0xf0;
  uVar11 = puVar13[3] ^ puVar10[3] >> 4 ^
           (uint)*(ushort *)((int)&rem_4bit + (*puVar10 & 0xf) * 2) << 0x10;
  uVar14 = *(byte *)((int)param_1 + 0xe) & 0xf;
  do {
    puVar10 = (uint *)(param_2 + uVar14 * 0x10);
    iVar3 = iVar3 + -1;
    bVar16 = -1 < iVar3;
    uVar14 = (uVar4 & 0xf) * 2;
    uVar4 = *puVar10 ^ uVar4 >> 4 ^ uVar6 << 0x1c;
    uVar6 = puVar10[1] ^ uVar6 >> 4;
    puVar1 = (ushort *)((int)&rem_4bit + uVar14);
    uVar9 = puVar10[2] ^ uVar8 >> 4;
    if (bVar16) {
      uVar14 = (uint)*(byte *)((int)param_1 + iVar3);
    }
    uVar12 = puVar10[3] ^ uVar11 >> 4;
    puVar10 = (uint *)(param_2 + uVar15);
    uVar15 = (uVar4 & 0xf) * 2;
    uVar5 = *puVar10 ^ uVar4 >> 4;
    uVar4 = uVar5 ^ uVar6 << 0x1c;
    uVar7 = puVar10[1] ^ (uVar6 ^ uVar8 << 0x1c) >> 4;
    puVar2 = (ushort *)((int)&rem_4bit + uVar15);
    uVar6 = uVar7 ^ uVar9 << 0x1c;
    uVar9 = puVar10[2] ^ (uVar9 ^ uVar11 << 0x1c) >> 4;
    uVar8 = uVar9 ^ uVar12 << 0x1c;
    uVar12 = puVar10[3] ^ (uVar12 ^ (uint)*puVar1 << 0x10) >> 4;
    if (bVar16) {
      uVar15 = uVar14 & 0xf0;
      uVar14 = uVar14 & 0xf;
    }
    uVar11 = uVar12 ^ (uint)*puVar2 << 0x10;
  } while (bVar16);
  param_1[3] = uVar5 << 0x18 | (uVar4 >> 8 & 0xff) << 0x10 | (uVar4 >> 0x10 & 0xff) << 8 |
               uVar4 >> 0x18;
  param_1[2] = uVar7 << 0x18 | (uVar6 >> 8 & 0xff) << 0x10 | (uVar6 >> 0x10 & 0xff) << 8 |
               uVar6 >> 0x18;
  param_1[1] = uVar9 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
               uVar8 >> 0x18;
  *param_1 = uVar12 << 0x18 | (uVar11 >> 8 & 0xff) << 0x10 | (uVar11 >> 0x10 & 0xff) << 8 |
             uVar11 >> 0x18;
  return;
}

