
void gcm_ghash_4bit(uint *param_1,int param_2,int param_3,int param_4)

{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int local_28;
  
  local_28 = param_3 + param_4;
  uStack_2c = DAT_0008845c;
  uStack_30 = DAT_00088458;
  uStack_34 = DAT_00088454;
  uStack_38 = DAT_00088450;
  uStack_3c = DAT_0008844c;
  uStack_40 = DAT_00088448;
  uStack_44 = DAT_00088444;
  uStack_48 = rem_4bit;
  uVar14 = (uint)*(byte *)(param_3 + 0xf);
  uVar15 = (uint)*(byte *)((int)param_1 + 0xf);
  do {
    iVar3 = 0xe;
    puVar9 = (uint *)(param_2 + ((uVar14 ^ uVar15) & 0xf) * 0x10);
    puVar13 = (uint *)(param_2 + ((uVar14 ^ uVar15) & 0xf0));
    uVar15 = *puVar13 ^ *puVar9 >> 4 ^ puVar9[1] << 0x1c;
    uVar5 = puVar13[1] ^ puVar9[1] >> 4 ^ puVar9[2] << 0x1c;
    uVar7 = puVar13[2] ^ puVar9[2] >> 4 ^ puVar9[3] << 0x1c;
    uVar14 = (uint)(*(byte *)(param_3 + 0xe) ^ *(byte *)((int)param_1 + 0xe));
    uVar16 = uVar14 & 0xf0;
    uVar14 = uVar14 & 0xf;
    uVar10 = puVar13[3] ^ puVar9[3] >> 4 ^
             (uint)*(ushort *)((int)&uStack_48 + (*puVar9 & 0xf) * 2) << 0x10;
    do {
      puVar9 = (uint *)(param_2 + uVar14 * 0x10);
      iVar3 = iVar3 + -1;
      bVar17 = -1 < iVar3;
      uVar14 = (uVar15 & 0xf) * 2;
      uVar15 = *puVar9 ^ uVar15 >> 4 ^ uVar5 << 0x1c;
      uVar5 = puVar9[1] ^ uVar5 >> 4;
      puVar1 = (ushort *)((int)&uStack_48 + uVar14);
      uVar8 = puVar9[2] ^ uVar7 >> 4;
      if (bVar17) {
        uVar14 = (uint)*(byte *)(param_3 + iVar3);
      }
      uVar11 = puVar9[3] ^ uVar10 >> 4;
      puVar9 = (uint *)(param_2 + uVar16);
      uVar16 = (uVar15 & 0xf) * 2;
      uVar12 = *puVar9;
      uVar4 = uVar12 ^ uVar15 >> 4;
      if (bVar17) {
        uVar12 = (uint)*(byte *)((int)param_1 + iVar3);
      }
      uVar15 = uVar4 ^ uVar5 << 0x1c;
      uVar6 = puVar9[1] ^ (uVar5 ^ uVar7 << 0x1c) >> 4;
      puVar2 = (ushort *)((int)&uStack_48 + uVar16);
      uVar5 = uVar6 ^ uVar8 << 0x1c;
      uVar8 = puVar9[2] ^ (uVar8 ^ uVar10 << 0x1c) >> 4;
      uVar7 = uVar8 ^ uVar11 << 0x1c;
      if (bVar17) {
        uVar14 = uVar14 ^ uVar12;
      }
      uVar11 = puVar9[3] ^ (uVar11 ^ (uint)*puVar1 << 0x10) >> 4;
      if (bVar17) {
        uVar16 = uVar14 & 0xf0;
        uVar14 = uVar14 & 0xf;
      }
      uVar10 = uVar11 ^ (uint)*puVar2 << 0x10;
    } while (bVar17);
    iVar3 = param_3 + 0x10;
    param_1[3] = uVar4 << 0x18 | (uVar15 >> 8 & 0xff) << 0x10 | (uVar15 >> 0x10 & 0xff) << 8 |
                 uVar15 >> 0x18;
    param_1[2] = uVar6 << 0x18 | (uVar5 >> 8 & 0xff) << 0x10 | (uVar5 >> 0x10 & 0xff) << 8 |
                 uVar5 >> 0x18;
    if (iVar3 != local_28) {
      uVar14 = (uint)*(byte *)(param_3 + 0x1f);
    }
    param_1[1] = uVar8 << 0x18 | (uVar7 >> 8 & 0xff) << 0x10 | (uVar7 >> 0x10 & 0xff) << 8 |
                 uVar7 >> 0x18;
    *param_1 = uVar11 << 0x18 | (uVar10 >> 8 & 0xff) << 0x10 | (uVar10 >> 0x10 & 0xff) << 8 |
               uVar10 >> 0x18;
    param_3 = iVar3;
  } while (iVar3 != local_28);
  return;
}

