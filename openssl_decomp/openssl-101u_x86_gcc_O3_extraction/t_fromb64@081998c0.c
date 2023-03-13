
uint __regparm3 t_fromb64(uint param_1,char *param_2)

{
  uint uVar1;
  char cVar2;
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  undefined *puVar11;
  undefined *puVar12;
  size_t sVar13;
  
  cVar2 = *param_2;
  while ((cVar2 != '\0' && (((byte)(cVar2 - 9U) < 2 || (cVar2 == ' '))))) {
    param_2 = param_2 + 1;
    cVar2 = *param_2;
  }
  sVar13 = 0;
  sVar4 = strlen(param_2);
  if (0 < (int)sVar4) {
    do {
      pcVar5 = strchr("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./",
                      (int)param_2[sVar13]);
      if (pcVar5 == (char *)0x0) {
        if (sVar13 == 0) {
          return 0;
        }
        break;
      }
      *(char *)(param_1 + sVar13) = (char)pcVar5 + '`';
      sVar13 = sVar13 + 1;
    } while (sVar4 != sVar13);
    iVar7 = sVar13 - 1;
    sVar4 = sVar13;
    do {
      bVar10 = *(byte *)(param_1 + iVar7);
      *(byte *)(param_1 + sVar4) = bVar10;
      sVar3 = sVar4;
      if (iVar7 + -1 < 0) {
LAB_081999de:
        sVar4 = sVar3;
        if (bVar10 != 0) goto LAB_08199a08;
        break;
      }
      *(byte *)(param_1 + sVar4) = *(char *)((param_1 - 1) + iVar7) << 6 | bVar10;
      bVar10 = (byte)((int)(*(byte *)((param_1 - 1) + iVar7) & 0x3c) >> 2);
      *(byte *)((param_1 - 1) + sVar4) = bVar10;
      sVar3 = sVar4 - 1;
      if (iVar7 + -2 < 0) goto LAB_081999de;
      *(byte *)((param_1 - 1) + sVar4) = bVar10 | *(char *)((param_1 - 2) + iVar7) << 4;
      bVar10 = (byte)((int)(*(byte *)((param_1 - 2) + iVar7) & 0x30) >> 4);
      *(byte *)((param_1 - 2) + sVar4) = bVar10;
      sVar3 = sVar4 - 2;
      if (iVar7 + -3 < 0) goto LAB_081999de;
      *(byte *)((param_1 - 2) + sVar4) = bVar10 | *(char *)((param_1 - 3) + iVar7) << 2;
      sVar4 = sVar4 - 3;
      iVar7 = iVar7 + -4;
      *(undefined *)(param_1 + sVar4) = 0;
    } while (-1 < iVar7);
    do {
      if ((int)sVar13 < (int)sVar4) {
        return 0;
      }
      sVar4 = sVar4 + 1;
    } while (*(char *)(param_1 + sVar4) == '\0');
LAB_08199a08:
    if ((int)sVar4 <= (int)sVar13) {
      uVar8 = (sVar13 - sVar4) + 1;
      puVar11 = (undefined *)(param_1 + sVar4);
      if ((((sVar4 == 0xfffffffc || (int)(sVar4 + 4) < 0) || (undefined *)(param_1 + 4) <= puVar11)
           && 9 < uVar8) && ((((uint)puVar11 | param_1) & 3) == 0)) {
        uVar1 = ((sVar13 - sVar4) - 3 >> 2) + 1;
        uVar9 = 0;
        iVar7 = uVar1 * 4;
        do {
          *(undefined4 *)(param_1 + uVar9 * 4) = *(undefined4 *)(puVar11 + uVar9 * 4);
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar1);
        iVar6 = sVar4 + iVar7;
        if (((iVar7 - uVar8 != 0) &&
            (*(undefined *)(param_1 + uVar1 * 4) = *(undefined *)(param_1 + iVar6),
            iVar6 + 1 <= (int)sVar13)) &&
           (*(undefined *)(param_1 + 1 + iVar7) = *(undefined *)(param_1 + 1 + iVar6),
           iVar6 + 2 <= (int)sVar13)) {
          *(undefined *)(param_1 + 2 + iVar7) = *(undefined *)(param_1 + 2 + iVar6);
        }
      }
      else {
        do {
          puVar12 = puVar11 + 1;
          puVar11[-sVar4] = *puVar11;
          puVar11 = puVar12;
        } while (puVar12 != (undefined *)(param_1 + 1 + sVar13));
      }
      return uVar8;
    }
  }
  return 0;
}

