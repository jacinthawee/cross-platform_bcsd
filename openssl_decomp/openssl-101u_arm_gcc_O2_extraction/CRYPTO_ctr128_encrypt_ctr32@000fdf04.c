
void CRYPTO_ctr128_encrypt_ctr32
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,char *param_5,
               void *param_6,uint *param_7,code *param_8)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  bool bVar16;
  
  uVar12 = *param_7;
  pbVar2 = param_1;
  pbVar5 = param_2;
  if (uVar12 != 0 && param_3 != 0) {
    do {
      pbVar7 = (byte *)((int)param_6 + uVar12);
      uVar1 = uVar12 + 1 & 0xf;
      param_1 = pbVar2 + 1;
      uVar12 = uVar12 + 1 & 0xf;
      if (uVar1 != 0) {
        uVar1 = 1;
      }
      param_3 = param_3 - 1;
      uVar1 = uVar1 & 1;
      if (param_3 == 0) {
        uVar1 = 0;
      }
      param_2 = pbVar5 + 1;
      *pbVar5 = *pbVar2 ^ *pbVar7;
      pbVar2 = param_1;
      pbVar5 = param_2;
    } while (uVar1 != 0);
  }
  uVar1 = (uint)(byte)param_5[0xd] << 0x10 | (uint)(byte)param_5[0xc] << 0x18 |
          (uint)(byte)param_5[0xf] | (uint)(byte)param_5[0xe] << 8;
  for (; 0xf < param_3; param_3 = param_3 + uVar8 * -0x10) {
    uVar8 = param_3 >> 4;
    uVar11 = uVar8 + uVar1;
    if (CARRY4(uVar8,uVar1) == false) {
      (*param_8)(param_1,param_2,uVar8,param_4,param_5);
      param_5[0xf] = (char)uVar11;
      param_5[0xc] = (char)(uVar11 >> 0x18);
      param_5[0xd] = (char)(uVar11 >> 0x10);
      param_5[0xe] = (char)(uVar11 >> 8);
    }
    else {
      uVar8 = -uVar1;
      uVar11 = 0;
      (*param_8)(param_1,param_2,uVar8,param_4,param_5);
      uVar14 = (uint)(byte)param_5[10] + ((byte)param_5[0xb] + 1 >> 8);
      uVar1 = (uint)(byte)param_5[9] + (uVar14 >> 8);
      param_5[0xb] = (char)((byte)param_5[0xb] + 1);
      uVar10 = (uint)(byte)param_5[8] + (uVar1 >> 8);
      param_5[10] = (char)uVar14;
      uVar14 = (uint)(byte)param_5[7] + (uVar10 >> 8);
      param_5[9] = (char)uVar1;
      uVar3 = (uint)(byte)param_5[6] + (uVar14 >> 8);
      param_5[8] = (char)uVar10;
      uVar13 = (uint)(byte)param_5[5] + (uVar3 >> 8);
      param_5[7] = (char)uVar14;
      uVar1 = (uint)(byte)param_5[4] + (uVar13 >> 8);
      param_5[6] = (char)uVar3;
      uVar10 = (uint)(byte)param_5[3] + (uVar1 >> 8);
      param_5[4] = (char)uVar1;
      uVar1 = (uint)(byte)param_5[2] + (uVar10 >> 8);
      param_5[0xc] = '\0';
      param_5[2] = (char)uVar1;
      iVar4 = (uint)(byte)param_5[1] + (uVar1 >> 8);
      param_5[0xd] = '\0';
      param_5[0xe] = '\0';
      param_5[0xf] = '\0';
      param_5[5] = (char)uVar13;
      param_5[3] = (char)uVar10;
      param_5[1] = (char)iVar4;
      *param_5 = *param_5 + (char)((uint)iVar4 >> 8);
    }
    param_2 = param_2 + uVar8 * 0x10;
    param_1 = param_1 + uVar8 * 0x10;
    uVar1 = uVar11;
  }
  if (param_3 == 0) {
    *param_7 = uVar12;
    return;
  }
  memset(param_6,0,0x10);
  (*param_8)(param_6,param_6,1,param_4,param_5);
  iVar4 = uVar1 + 1;
  param_5[0xf] = (char)iVar4;
  param_5[0xc] = (char)((uint)iVar4 >> 0x18);
  param_5[0xd] = (char)((uint)iVar4 >> 0x10);
  param_5[0xe] = (char)((uint)iVar4 >> 8);
  if (iVar4 == 0) {
    uVar1 = (uint)(byte)param_5[10] + ((byte)param_5[0xb] + 1 >> 8);
    uVar8 = (uint)(byte)param_5[9] + (uVar1 >> 8);
    param_5[0xb] = (char)((byte)param_5[0xb] + 1);
    uVar11 = (uint)(byte)param_5[8] + (uVar8 >> 8);
    param_5[10] = (char)uVar1;
    uVar14 = (uint)(byte)param_5[7] + (uVar11 >> 8);
    param_5[9] = (char)uVar8;
    uVar10 = (uint)(byte)param_5[6] + (uVar14 >> 8);
    param_5[8] = (char)uVar11;
    uVar1 = (uint)(byte)param_5[5] + (uVar10 >> 8);
    param_5[7] = (char)uVar14;
    uVar8 = (uint)(byte)param_5[4] + (uVar1 >> 8);
    param_5[6] = (char)uVar10;
    uVar11 = (uint)(byte)param_5[3] + (uVar8 >> 8);
    param_5[5] = (char)uVar1;
    param_5[4] = (char)uVar8;
    uVar1 = (uint)(byte)param_5[2] + (uVar11 >> 8);
    param_5[2] = (char)uVar1;
    param_5[3] = (char)uVar11;
    iVar4 = (uint)(byte)param_5[1] + (uVar1 >> 8);
    param_5[1] = (char)iVar4;
    *param_5 = *param_5 + (char)((uint)iVar4 >> 8);
  }
  pbVar2 = param_2 + uVar12;
  pbVar5 = pbVar2 + 4;
  pbVar9 = param_1 + uVar12;
  pbVar7 = (byte *)((int)param_6 + uVar12);
  bVar16 = pbVar2 <= pbVar7 + 4;
  bVar15 = pbVar7 + 4 == pbVar2;
  if (bVar16 && !bVar15) {
    bVar16 = pbVar7 <= pbVar5;
    bVar15 = pbVar5 == pbVar7;
  }
  if ((((uint)pbVar2 | (uint)pbVar9 | (uint)pbVar7) & 3) != 0 ||
      (param_3 < 7 || (bVar16 && !bVar15 || pbVar2 < pbVar9 + 4 && pbVar9 < pbVar5))) {
    uVar1 = param_3 + uVar12;
    do {
      param_2[uVar12] = *(byte *)((int)param_6 + uVar12) ^ param_1[uVar12];
      uVar12 = uVar12 + 1;
    } while (uVar12 != uVar1);
  }
  else {
    iVar4 = 0;
    uVar1 = 0;
    uVar8 = param_3 & 0xfffffffc;
    do {
      uVar1 = uVar1 + 1;
      *(uint *)(pbVar2 + iVar4) = *(uint *)(pbVar9 + iVar4) ^ *(uint *)(pbVar7 + iVar4);
      iVar4 = iVar4 + 4;
    } while (uVar1 < param_3 >> 2);
    uVar1 = uVar8 + uVar12;
    if (param_3 != uVar8) {
      iVar4 = uVar1 + 1;
      param_2[uVar1] = *(byte *)((int)param_6 + uVar1) ^ param_1[uVar1];
      if (param_3 - 1 != uVar8) {
        iVar6 = uVar1 + 2;
        param_2[iVar4] = *(byte *)((int)param_6 + iVar4) ^ param_1[iVar4];
        if ((param_3 - 1) - uVar8 != 1) {
          uVar1 = param_3 + uVar12;
          param_2[iVar6] = *(byte *)((int)param_6 + iVar6) ^ param_1[iVar6];
          goto LAB_000fe15e;
        }
      }
      uVar1 = param_3 + uVar12;
    }
  }
LAB_000fe15e:
  *param_7 = uVar1;
  return;
}

