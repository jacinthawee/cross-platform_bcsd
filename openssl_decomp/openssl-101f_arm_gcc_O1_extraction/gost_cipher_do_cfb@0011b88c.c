
undefined4 gost_cipher_do_cfb(int param_1,uint *param_2,uint *param_3,byte *param_4)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  uint *puVar11;
  byte *pbVar12;
  uint *puVar13;
  byte bVar14;
  bool bVar15;
  bool bVar16;
  
  pbVar8 = *(byte **)(param_1 + 0x50);
  if (pbVar8 == (byte *)0x0) {
    pbVar12 = &DAT_00000008;
    pbVar3 = param_4;
  }
  else {
    pbVar9 = param_4;
    if (param_4 != (byte *)0x0) {
      pbVar9 = (byte *)0x1;
    }
    if ((byte *)0x7 < pbVar8) {
      pbVar9 = (byte *)0x0;
    }
    if (pbVar9 != (byte *)0x0) {
      iVar6 = *(int *)(param_1 + 8);
      pbVar9 = (byte *)0x0;
      puVar11 = param_2;
      puVar7 = (uint *)((int)param_3 + 1);
      pbVar3 = pbVar8 + param_1 + 0x2f;
      do {
        param_3 = puVar7;
        pbVar9 = pbVar9 + 1;
        pbVar8 = pbVar8 + 1;
        if (iVar6 == 0) {
          pbVar3[9] = *(byte *)((int)param_3 + -1);
        }
        bVar14 = pbVar3[1] ^ *(byte *)((int)param_3 + -1);
        param_2 = (uint *)((int)puVar11 + 1);
        *(byte *)puVar11 = bVar14;
        iVar6 = *(int *)(param_1 + 8);
        if (iVar6 != 0) {
          pbVar3[9] = bVar14;
        }
        puVar11 = param_2;
        puVar7 = (uint *)((int)param_3 + 1);
        pbVar3 = pbVar3 + 1;
      } while (pbVar8 < &DAT_00000008 && pbVar9 < param_4);
    }
    if (pbVar8 != &DAT_00000008) {
      *(byte **)(param_1 + 0x50) = pbVar8;
      return 1;
    }
    pbVar12 = pbVar9 + 8;
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(byte **)(param_1 + 0x24) = *(byte **)(param_1 + 0x3c);
    pbVar3 = *(byte **)(param_1 + 0x3c);
    pbVar8 = pbVar9;
  }
  if (pbVar12 < param_4) {
    puVar13 = (uint *)(param_1 + 0x20);
    iVar6 = (int)pbVar12 - (int)param_2;
    puVar11 = param_3;
    puVar7 = param_2;
    do {
      while( true ) {
        iVar10 = *(int *)(param_1 + 0x60);
        pbVar8 = (byte *)((int)puVar7 + iVar6);
        if ((*(int *)(iVar10 + 8) != 0) && (*(int *)(iVar10 + 4) == 0x400)) {
          cryptopro_key_meshing(iVar10 + 0xc,puVar13);
        }
        gostcrypt(iVar10 + 0xc,puVar13,param_1 + 0x30);
        iVar1 = *(int *)(param_1 + 8);
        *(uint *)(iVar10 + 4) = (*(uint *)(iVar10 + 4) & 0x3ff) + 8;
        if (iVar1 == 0) {
          uVar4 = puVar11[1];
          *puVar13 = *puVar11;
          *(uint *)(param_1 + 0x24) = uVar4;
        }
        param_3 = puVar11 + 2;
        *(byte *)puVar7 = *(byte *)(param_1 + 0x30) ^ *(byte *)puVar11;
        *(byte *)((int)puVar7 + 1) = *(byte *)(param_1 + 0x31) ^ *(byte *)((int)puVar11 + 1);
        *(byte *)((int)puVar7 + 2) = *(byte *)(param_1 + 0x32) ^ *(byte *)((int)puVar11 + 2);
        *(byte *)((int)puVar7 + 3) = *(byte *)(param_1 + 0x33) ^ *(byte *)((int)puVar11 + 3);
        *(byte *)(puVar7 + 1) = *(byte *)(param_1 + 0x34) ^ *(byte *)(puVar11 + 1);
        *(byte *)((int)puVar7 + 5) = *(byte *)(param_1 + 0x35) ^ *(byte *)((int)puVar11 + 5);
        *(byte *)((int)puVar7 + 6) = *(byte *)(param_1 + 0x36) ^ *(byte *)((int)puVar11 + 6);
        *(byte *)((int)puVar7 + 7) = *(byte *)(param_1 + 0x37) ^ *(byte *)((int)puVar11 + 7);
        puVar11 = param_3;
        if (*(int *)(param_1 + 8) != 0) break;
        param_2 = puVar7 + 2;
        pbVar3 = (byte *)((int)param_2 + iVar6);
        puVar7 = param_2;
        if (param_4 <= pbVar3) goto LAB_0011b9f8;
      }
      param_2 = puVar7 + 2;
      uVar4 = *puVar7;
      *(uint *)(param_1 + 0x24) = puVar7[1];
      pbVar3 = (byte *)((int)param_2 + iVar6);
      *puVar13 = uVar4;
      puVar7 = param_2;
    } while (pbVar3 < param_4);
  }
LAB_0011b9f8:
  if (param_4 <= pbVar8) {
    pbVar3 = (byte *)0x0;
  }
  if (param_4 <= pbVar8) {
    *(byte **)(param_1 + 0x50) = pbVar3;
    return 1;
  }
  iVar6 = *(int *)(param_1 + 0x60);
  puVar11 = (uint *)(param_1 + 0x30);
  if ((*(int *)(iVar6 + 8) != 0) && (*(int *)(iVar6 + 4) == 0x400)) {
    cryptopro_key_meshing(iVar6 + 0xc,param_1 + 0x20);
  }
  gostcrypt(iVar6 + 0xc,param_1 + 0x20,puVar11);
  iVar10 = *(int *)(param_1 + 8);
  *(uint *)(iVar6 + 4) = (*(uint *)(iVar6 + 4) & 0x3ff) + 8;
  uVar4 = (int)param_4 - (int)pbVar8;
  if (iVar10 == 0) {
    memcpy((void *)(param_1 + 0x38),param_3,uVar4);
  }
  puVar7 = param_2 + 1;
  uVar2 = (uint)(puVar7 <= param_3);
  bVar16 = param_2 <= (uint *)(param_1 + 0x34);
  bVar15 = (uint *)(param_1 + 0x34) == param_2;
  if (bVar16 && !bVar15) {
    bVar16 = puVar11 <= puVar7;
    bVar15 = puVar7 == puVar11;
  }
  if (param_3 + 1 <= param_2) {
    uVar2 = 1;
  }
  uVar2 = (!bVar16 || bVar15) & uVar2;
  if (uVar4 < 7) {
    uVar2 = 0;
  }
  if ((((uint)param_2 | (uint)param_3) & 3) != 0) {
    uVar2 = 0;
  }
  if (uVar2 == 0) {
    do {
      *(byte *)((int)param_2 + uVar2) =
           *(byte *)((int)param_3 + uVar2) ^ *(byte *)(param_1 + uVar2 + 0x30);
      uVar2 = uVar2 + 1;
    } while (uVar4 != uVar2);
  }
  else {
    uVar5 = uVar4 >> 2;
    uVar2 = uVar4 & 0xfffffffc;
    if (uVar5 != 0) {
      *param_2 = *(uint *)(param_1 + 0x30) ^ *param_3;
      if ((((1 < uVar5) && (param_2[1] = param_3[1] ^ *(uint *)(param_1 + 0x34), 2 < uVar5)) &&
          (param_2[2] = param_3[2] ^ *(uint *)(param_1 + 0x38), 3 < uVar5)) &&
         (((param_2[3] = param_3[3] ^ *(uint *)(param_1 + 0x3c), 4 < uVar5 &&
           (param_2[4] = param_3[4] ^ *(uint *)(param_1 + 0x40), 5 < uVar5)) &&
          ((param_2[5] = param_3[5] ^ *(uint *)(param_1 + 0x44), 6 < uVar5 &&
           (param_2[6] = param_3[6] ^ *(uint *)(param_1 + 0x48), 7 < uVar5)))))) {
        param_2[7] = param_3[7] ^ *(uint *)(param_1 + 0x4c);
      }
      pbVar8 = pbVar8 + uVar2;
      if (uVar4 == uVar2) goto LAB_0011bb52;
    }
    iVar6 = uVar2 + 1;
    *(byte *)((int)param_2 + (uVar4 & 0xfffffffc)) =
         *(byte *)((int)param_3 + (uVar4 & 0xfffffffc)) ^ *(byte *)(param_1 + uVar2 + 0x30);
    if (pbVar8 + 1 < param_4) {
      iVar10 = uVar2 + 2;
      *(byte *)((int)param_2 + iVar6) =
           *(byte *)(param_1 + iVar6 + 0x30) ^ *(byte *)((int)param_3 + iVar6);
      if (pbVar8 + 2 < param_4) {
        *(byte *)((int)param_2 + iVar10) =
             *(byte *)(param_1 + iVar10 + 0x30) ^ *(byte *)((int)param_3 + iVar10);
      }
    }
  }
LAB_0011bb52:
  *(uint *)(param_1 + 0x50) = uVar4;
  if (*(int *)(param_1 + 8) != 0) {
    memcpy((void *)(param_1 + 0x38),param_2,uVar4);
  }
  return 1;
}

