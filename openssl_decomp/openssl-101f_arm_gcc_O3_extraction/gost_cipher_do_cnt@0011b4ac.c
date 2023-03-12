
undefined4 gost_cipher_do_cnt(int param_1,uint *param_2,uint *param_3,byte *param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint *puVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  
  pbVar4 = *(byte **)(param_1 + 0x50);
  if (pbVar4 == (byte *)0x0) {
    pbVar8 = &DAT_00000008;
  }
  else {
    pbVar5 = param_4;
    if (param_4 != (byte *)0x0) {
      pbVar5 = (byte *)0x1;
    }
    if ((byte *)0x7 < pbVar4) {
      pbVar5 = (byte *)0x0;
    }
    if (pbVar5 != (byte *)0x0) {
      pbVar5 = (byte *)0x0;
      pbVar8 = pbVar4;
      puVar3 = param_3;
      puVar6 = param_2;
      do {
        pbVar4 = pbVar8 + 1;
        pbVar5 = pbVar5 + 1;
        param_3 = (uint *)((int)puVar3 + 1);
        param_2 = (uint *)((int)puVar6 + 1);
        *(byte *)puVar6 = *(byte *)puVar3 ^ pbVar8[param_1 + 0x30];
        pbVar8 = pbVar4;
        puVar3 = param_3;
        puVar6 = param_2;
      } while (pbVar5 < param_4 && pbVar4 < &DAT_00000008);
    }
    if (pbVar4 != &DAT_00000008) {
      *(byte **)(param_1 + 0x50) = pbVar4;
      return 1;
    }
    pbVar8 = pbVar5 + 8;
    *(undefined4 *)(param_1 + 0x50) = 0;
    pbVar4 = pbVar5;
  }
  pbVar5 = param_4;
  if (pbVar8 < param_4) {
    iVar1 = -(int)param_2;
    iVar7 = (int)pbVar8 - (int)param_3;
    pbVar5 = pbVar8 + iVar1;
    puVar3 = param_2;
    puVar6 = param_3;
    do {
      gost_cnt_next(*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,param_1 + 0x30);
      param_3 = puVar6 + 2;
      pbVar4 = pbVar8 + iVar1 + (int)puVar3;
      param_2 = puVar3 + 2;
      *(byte *)puVar3 = *(byte *)(param_1 + 0x30) ^ *(byte *)puVar6;
      *(byte *)((int)puVar3 + 1) = *(byte *)(param_1 + 0x31) ^ *(byte *)((int)puVar6 + 1);
      *(byte *)((int)puVar3 + 2) = *(byte *)(param_1 + 0x32) ^ *(byte *)((int)puVar6 + 2);
      *(byte *)((int)puVar3 + 3) = *(byte *)(param_1 + 0x33) ^ *(byte *)((int)puVar6 + 3);
      *(byte *)(puVar3 + 1) = *(byte *)(param_1 + 0x34) ^ *(byte *)(puVar6 + 1);
      *(byte *)((int)puVar3 + 5) = *(byte *)(param_1 + 0x35) ^ *(byte *)((int)puVar6 + 5);
      *(byte *)((int)puVar3 + 6) = *(byte *)(param_1 + 0x36) ^ *(byte *)((int)puVar6 + 6);
      *(byte *)((int)puVar3 + 7) = *(byte *)(param_1 + 0x37) ^ *(byte *)((int)puVar6 + 7);
      puVar3 = param_2;
      puVar6 = param_3;
    } while ((byte *)((int)param_3 + iVar7) < param_4);
  }
  if (param_4 <= pbVar4) {
    pbVar5 = (byte *)0x0;
  }
  if (param_4 <= pbVar4) {
    *(byte **)(param_1 + 0x50) = pbVar5;
    return 1;
  }
  puVar6 = (uint *)(param_1 + 0x30);
  gost_cnt_next(*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,puVar6);
  puVar3 = param_2 + 1;
  bVar13 = param_2 <= (uint *)(param_1 + 0x34);
  bVar11 = (uint *)(param_1 + 0x34) == param_2;
  if (bVar13 && !bVar11) {
    bVar13 = puVar6 <= puVar3;
    bVar11 = puVar3 == puVar6;
  }
  uVar10 = (int)param_4 - (int)pbVar4;
  bVar14 = param_2 <= param_3 + 1;
  bVar12 = param_3 + 1 == param_2;
  if (bVar14 && !bVar12) {
    bVar14 = param_3 <= puVar3;
    bVar12 = puVar3 == param_3;
  }
  if ((((uint)param_2 | (uint)param_3) & 3) != 0 ||
      (uVar10 < 7 || (bVar14 && !bVar12 || bVar13 && !bVar11))) {
    iVar1 = -(int)pbVar4;
    do {
      pbVar4[(int)param_2 + iVar1] = pbVar4[(int)param_3 + iVar1] ^ pbVar4[iVar1 + param_1 + 0x30];
      pbVar4 = pbVar4 + 1;
    } while (pbVar4 != param_4);
  }
  else {
    uVar2 = uVar10 >> 2;
    uVar9 = uVar10 & 0xfffffffc;
    if (uVar2 != 0) {
      *param_2 = *(uint *)(param_1 + 0x30) ^ *param_3;
      if ((((1 < uVar2) && (param_2[1] = param_3[1] ^ *(uint *)(param_1 + 0x34), 2 < uVar2)) &&
          (param_2[2] = param_3[2] ^ *(uint *)(param_1 + 0x38), 3 < uVar2)) &&
         (((param_2[3] = param_3[3] ^ *(uint *)(param_1 + 0x3c), 4 < uVar2 &&
           (param_2[4] = param_3[4] ^ *(uint *)(param_1 + 0x40), 5 < uVar2)) &&
          ((param_2[5] = param_3[5] ^ *(uint *)(param_1 + 0x44), 6 < uVar2 &&
           (param_2[6] = param_3[6] ^ *(uint *)(param_1 + 0x48), 7 < uVar2)))))) {
        param_2[7] = param_3[7] ^ *(uint *)(param_1 + 0x4c);
      }
      pbVar4 = pbVar4 + uVar9;
      if (uVar10 == uVar9) goto LAB_0011b6e0;
    }
    iVar1 = uVar9 + 1;
    *(byte *)((int)param_2 + (uVar10 & 0xfffffffc)) =
         *(byte *)((int)param_3 + (uVar10 & 0xfffffffc)) ^ *(byte *)(param_1 + uVar9 + 0x30);
    if (pbVar4 + 1 < param_4) {
      iVar7 = uVar9 + 2;
      *(byte *)((int)param_2 + iVar1) =
           *(byte *)(param_1 + iVar1 + 0x30) ^ *(byte *)((int)param_3 + iVar1);
      if (pbVar4 + 2 < param_4) {
        *(byte *)((int)param_2 + iVar7) =
             *(byte *)(param_1 + iVar7 + 0x30) ^ *(byte *)((int)param_3 + iVar7);
      }
    }
  }
LAB_0011b6e0:
  *(uint *)(param_1 + 0x50) = uVar10;
  return 1;
}

