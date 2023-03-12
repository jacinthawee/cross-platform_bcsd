
uint t_fromb64(uint param_1,byte *param_2)

{
  byte bVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  size_t sVar7;
  int iVar8;
  uint uVar9;
  size_t sVar10;
  undefined *puVar11;
  size_t sVar12;
  uint uVar13;
  size_t sVar14;
  bool bVar15;
  
  bVar1 = *param_2;
  while (bVar1 != 0) {
    bVar15 = 0x1f < bVar1;
    if (bVar1 != 0x20) {
      bVar15 = bVar1 != 9;
    }
    if (bVar15 && (bVar1 != 0x20 && bVar1 != 10)) break;
    param_2 = param_2 + 1;
    bVar1 = *param_2;
  }
  sVar2 = strlen((char *)param_2);
  if ((int)sVar2 < 1) {
    iVar4 = -1;
    sVar10 = 0;
  }
  else {
    sVar10 = 0;
    do {
      pcVar3 = strchr("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./",
                      (uint)param_2[sVar10]);
      if (pcVar3 == (char *)0x0) break;
      *(char *)(param_1 + sVar10) = (char)pcVar3 + '\x18';
      sVar10 = sVar10 + 1;
    } while (sVar2 != sVar10);
    iVar4 = sVar10 - 1;
  }
  iVar8 = param_1 + iVar4;
  sVar2 = sVar10;
  puVar11 = (undefined *)(param_1 + sVar10);
  do {
    bVar1 = *(byte *)(param_1 + iVar4);
    uVar6 = (uint)bVar1;
    sVar12 = sVar2 - 1;
    sVar14 = sVar2 - 2;
    *(byte *)(param_1 + sVar2) = bVar1;
    sVar7 = sVar2;
    if (iVar4 + -1 < 0) {
LAB_000ee3b2:
      if (uVar6 != 0) goto LAB_000ee3cc;
      break;
    }
    *(byte *)(param_1 + sVar2) = bVar1 | *(char *)(iVar8 + -1) << 6;
    sVar2 = sVar2 - 3;
    uVar9 = (uint)*(byte *)(iVar8 + -1) << 0x1a;
    uVar6 = uVar9 >> 0x1c;
    bVar1 = (byte)(uVar9 >> 0x18);
    puVar11[-1] = bVar1 >> 4;
    sVar7 = sVar12;
    if (iVar4 + -2 < 0) goto LAB_000ee3b2;
    puVar11[-1] = bVar1 >> 4 | *(char *)(iVar8 + -2) << 4;
    uVar9 = (uint)*(byte *)(iVar8 + -2) << 0x1a;
    uVar6 = uVar9 >> 0x1e;
    bVar1 = (byte)(uVar9 >> 0x18);
    puVar11[-2] = bVar1 >> 6;
    sVar7 = sVar14;
    if (iVar4 + -3 < 0) goto LAB_000ee3b2;
    pcVar3 = (char *)(iVar8 + -3);
    iVar4 = iVar4 + -4;
    iVar8 = iVar8 + -4;
    puVar11[-2] = bVar1 >> 6 | *pcVar3 << 2;
    puVar11 = puVar11 + -3;
    *puVar11 = 0;
    sVar7 = sVar2;
  } while (-1 < iVar4);
  if ((int)sVar7 <= (int)sVar10) {
    pcVar3 = (char *)(param_1 + sVar7);
    do {
      pcVar3 = pcVar3 + 1;
      sVar7 = sVar7 + 1;
      if (*pcVar3 != '\0') {
LAB_000ee3cc:
        if ((int)sVar10 < (int)sVar7) {
          return 0;
        }
        uVar9 = param_1 + sVar7;
        uVar6 = (sVar10 - sVar7) + 1;
        if (((uVar9 | param_1) & 3) == 0 &&
            (9 < uVar6 && (param_1 + 4 <= uVar9 || uVar9 + 4 <= param_1))) {
          iVar4 = 0;
          uVar5 = 0;
          uVar13 = uVar6 & 0xfffffffc;
          do {
            uVar5 = uVar5 + 1;
            *(undefined4 *)(param_1 + iVar4) = *(undefined4 *)(uVar9 + iVar4);
            iVar4 = iVar4 + 4;
          } while (uVar5 < uVar6 >> 2);
          iVar4 = sVar7 + uVar13;
          if (uVar13 != uVar6) {
            *(undefined *)(param_1 + (uVar6 & 0xfffffffc)) = *(undefined *)(param_1 + iVar4);
            if (iVar4 + 1 <= (int)sVar10) {
              *(undefined *)(param_1 + uVar13 + 1) = *(undefined *)(param_1 + iVar4 + 1);
              if (iVar4 + 2 <= (int)sVar10) {
                *(undefined *)(param_1 + uVar13 + 2) = *(undefined *)(param_1 + iVar4 + 2);
                return uVar6;
              }
              return uVar6;
            }
          }
        }
        else {
          puVar11 = (undefined *)(param_1 + (sVar7 - 1));
          do {
            puVar11 = puVar11 + 1;
            puVar11[-sVar7] = *puVar11;
          } while (puVar11 != (undefined *)(param_1 + sVar10));
        }
        return uVar6;
      }
    } while ((int)sVar7 <= (int)sVar10);
  }
  return 0;
}

