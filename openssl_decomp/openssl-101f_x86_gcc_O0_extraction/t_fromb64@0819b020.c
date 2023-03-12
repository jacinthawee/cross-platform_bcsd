
uint __regparm3 t_fromb64(byte *param_1,char *param_2)

{
  size_t sVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  size_t sVar5;
  char *pcVar6;
  int iVar7;
  size_t sVar8;
  uint uVar9;
  uint uVar10;
  byte bVar11;
  byte *pbVar12;
  byte *pbVar13;
  size_t sVar14;
  size_t sVar15;
  bool bVar16;
  
  cVar4 = *param_2;
  while ((cVar4 != '\0' && (((byte)(cVar4 - 9U) < 2 || (cVar4 == ' '))))) {
    param_2 = param_2 + 1;
    cVar4 = *param_2;
  }
  sVar5 = strlen(param_2);
  if ((int)sVar5 < 1) {
    bVar11 = param_1[-1];
    sVar15 = 0;
    sVar5 = 0;
    *param_1 = bVar11;
LAB_0819b246:
    bVar16 = bVar11 == 0;
  }
  else {
    sVar14 = 0;
    do {
      pcVar6 = strchr("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./",
                      (int)param_2[sVar14]);
      if (pcVar6 == (char *)0x0) {
        sVar5 = sVar14;
        sVar8 = sVar14 - 1;
        sVar15 = sVar14;
        break;
      }
      param_1[sVar14] = (char)pcVar6 + 0x20;
      sVar1 = sVar14 + 1;
      sVar8 = sVar14;
      sVar14 = sVar1;
      sVar15 = sVar5;
    } while (sVar5 != sVar1);
    do {
      bVar11 = param_1[sVar8];
      param_1[sVar5] = bVar11;
      if ((int)(sVar8 - 1) < 0) goto LAB_0819b246;
      param_1[sVar5] = param_1[sVar8 - 1] << 6 | bVar11;
      bVar11 = (byte)((int)(param_1[sVar8 - 1] & 0x3c) >> 2);
      param_1[sVar5 - 1] = bVar11;
      sVar14 = sVar5 - 1;
      if ((int)(sVar8 - 2) < 0) {
LAB_0819b137:
        sVar5 = sVar14;
        bVar16 = bVar11 == 0;
        goto LAB_0819b144;
      }
      param_1[sVar5 - 1] = bVar11 | param_1[sVar8 - 2] << 4;
      bVar11 = (byte)((int)(param_1[sVar8 - 2] & 0x30) >> 4);
      param_1[sVar5 - 2] = bVar11;
      sVar14 = sVar5 - 2;
      if ((int)(sVar8 - 3) < 0) goto LAB_0819b137;
      param_1[sVar5 - 2] = bVar11 | param_1[sVar8 - 3] << 2;
      sVar5 = sVar5 - 3;
      sVar8 = sVar8 - 4;
      param_1[sVar5] = 0;
    } while (-1 < (int)sVar8);
    bVar16 = true;
  }
LAB_0819b144:
  if (((int)sVar5 <= (int)sVar15) && (bVar16)) {
    do {
      sVar5 = sVar5 + 1;
      if (param_1[sVar5] != 0) break;
    } while ((int)sVar5 <= (int)sVar15);
  }
  if ((int)sVar15 < (int)sVar5) {
    uVar9 = 0;
  }
  else {
    uVar9 = (sVar15 - sVar5) + 1;
    if ((param_1 + sVar5 < param_1 + 4 && (sVar5 != 0xfffffffc && -1 < (int)(sVar5 + 4)) ||
         uVar9 < 10) || ((((uint)(param_1 + sVar5) | (uint)param_1) & 3) != 0)) {
      pbVar12 = param_1 + sVar5;
      do {
        pbVar13 = pbVar12 + 1;
        pbVar12[-sVar5] = *pbVar12;
        pbVar12 = pbVar13;
      } while (param_1 + sVar15 + 1 != pbVar13);
    }
    else {
      uVar2 = ((sVar15 - sVar5) - 3 >> 2) + 1;
      uVar10 = 0;
      iVar3 = uVar2 * 4;
      do {
        *(undefined4 *)(param_1 + uVar10 * 4) = *(undefined4 *)(param_1 + sVar5 + uVar10 * 4);
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar2);
      iVar7 = sVar5 + iVar3;
      if (((iVar3 - uVar9 != 0) && (param_1[uVar2 * 4] = param_1[iVar7], iVar7 + 1 <= (int)sVar15))
         && (param_1[iVar3 + 1] = param_1[iVar7 + 1], iVar7 + 2 <= (int)sVar15)) {
        param_1[iVar3 + 2] = param_1[iVar7 + 2];
      }
    }
  }
  return uVar9;
}

