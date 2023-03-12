
uint t_fromb64(undefined4 *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  char *pcVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  undefined4 *puVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  undefined4 uVar22;
  
  cVar2 = *param_2;
  while ((iVar5 = (int)cVar2, iVar5 != 0 && ((iVar5 == 0x20 || ((iVar5 - 9U & 0xff) < 2))))) {
    param_2 = param_2 + 1;
    cVar2 = *param_2;
  }
  iVar5 = (*(code *)PTR_strlen_006aab30)(param_2);
  if (iVar5 < 1) {
    iVar5 = 0;
    iVar6 = -1;
  }
  else {
    iVar11 = 0;
    puVar13 = param_1;
    do {
      cVar2 = *param_2;
      param_2 = param_2 + 1;
      iVar6 = (*(code *)PTR_strchr_006aab34)
                        ("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./",
                         (int)cVar2);
      iVar9 = iVar11 + 1;
      if (iVar6 == 0) {
        iVar6 = iVar11 + -1;
        iVar5 = iVar11;
        break;
      }
      *(char *)puVar13 = (char)iVar6 + -0x40;
      iVar6 = iVar11;
      iVar11 = iVar9;
      puVar13 = (undefined4 *)((int)puVar13 + 1);
    } while (iVar5 != iVar9);
  }
  pbVar10 = (byte *)((int)param_1 + iVar6);
  pbVar7 = (byte *)((int)param_1 + iVar5);
  iVar11 = iVar5;
  do {
    bVar4 = *pbVar10;
    uVar12 = (uint)bVar4;
    iVar16 = iVar6 + -1;
    iVar18 = iVar6 + -2;
    iVar20 = iVar6 + -3;
    iVar21 = iVar11 + -1;
    iVar6 = iVar6 + -4;
    *pbVar7 = bVar4;
    iVar9 = iVar11;
    if (iVar16 < 0) {
LAB_005cb058:
      iVar11 = iVar9;
      if (uVar12 != 0) goto LAB_005cb090;
      break;
    }
    iVar16 = iVar11 + -2;
    iVar11 = iVar11 + -3;
    *pbVar7 = pbVar10[-1] << 6 | bVar4;
    uVar12 = ((uint)pbVar10[-1] << 0x1a) >> 0x1c;
    bVar4 = (byte)(((uint)pbVar10[-1] << 0x1a) >> 0x18);
    pbVar7[-1] = bVar4 >> 4;
    iVar9 = iVar21;
    if (iVar18 < 0) goto LAB_005cb058;
    pbVar7[-1] = pbVar10[-2] << 4 | bVar4 >> 4;
    uVar12 = ((uint)pbVar10[-2] << 0x1a) >> 0x1e;
    bVar4 = (byte)(((uint)pbVar10[-2] << 0x1a) >> 0x18);
    pbVar7[-2] = bVar4 >> 6;
    iVar9 = iVar16;
    if (iVar20 < 0) goto LAB_005cb058;
    bVar3 = pbVar10[-3];
    pbVar10 = pbVar10 + -4;
    pbVar7[-3] = 0;
    pbVar7[-2] = bVar3 << 2 | bVar4 >> 6;
    pbVar7 = pbVar7 + -3;
  } while (-1 < iVar6);
  pcVar8 = (char *)((int)param_1 + iVar11);
  iVar9 = iVar11;
  do {
    if (iVar5 < iVar9) {
      return 0;
    }
    pcVar1 = pcVar8 + 1;
    iVar9 = iVar9 + 1;
    pcVar8 = pcVar8 + 1;
  } while (*pcVar1 == '\0');
LAB_005cb090:
  puVar13 = (undefined4 *)((int)param_1 + iVar9);
  if (iVar5 < iVar9) {
    return 0;
  }
  uVar12 = (iVar5 - iVar9) + 1;
  if ((((uint)puVar13 & 3) == 0 && (iVar9 + 4 < 1 || param_1 + 1 <= puVar13)) && (8 < uVar12)) {
    uVar19 = 0;
    uVar15 = ((iVar5 - iVar9) - 3U >> 2) + 1;
    uVar14 = uVar15 * 4;
    puVar17 = param_1;
    do {
      uVar22 = *puVar13;
      uVar19 = uVar19 + 1;
      puVar13 = puVar13 + 1;
      *puVar17 = uVar22;
      puVar17 = puVar17 + 1;
    } while (uVar19 < uVar15);
    iVar9 = iVar9 + uVar14;
    if (uVar14 != uVar12) {
      *(char *)(param_1 + uVar15) = *(char *)((int)param_1 + iVar9);
      if (iVar9 + 1 <= iVar5) {
        *(char *)((int)param_1 + uVar14 + 1) = *(char *)((int)param_1 + iVar9 + 1);
        if (iVar9 + 2 <= iVar5) {
          *(char *)((int)param_1 + uVar14 + 2) = *(char *)((int)param_1 + iVar9 + 2);
        }
      }
    }
  }
  else {
    puVar17 = param_1;
    do {
      cVar2 = *(char *)puVar13;
      puVar13 = (undefined4 *)((int)puVar13 + 1);
      *(char *)puVar17 = cVar2;
      puVar17 = (undefined4 *)((int)puVar17 + 1);
    } while (puVar13 != (undefined4 *)((int)param_1 + iVar5 + 1));
  }
  return uVar12;
}

