
uint t_fromb64(uint param_1,byte *param_2)

{
  byte bVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  size_t sVar8;
  uint uVar9;
  size_t sVar10;
  uint uVar11;
  size_t sVar12;
  bool bVar13;
  
  bVar1 = *param_2;
  while (bVar1 != 0) {
    bVar13 = 0x1f < bVar1;
    if (bVar1 != 0x20) {
      bVar13 = bVar1 != 9;
    }
    if (bVar13 && (bVar1 != 0x20 && bVar1 != 10)) break;
    param_2 = param_2 + 1;
    bVar1 = *param_2;
  }
  sVar2 = strlen((char *)param_2);
  if (0 < (int)sVar2) {
    sVar8 = 0;
    do {
      pcVar3 = strchr("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./",
                      (uint)param_2[sVar8]);
      if (pcVar3 == (char *)0x0) {
        if (sVar8 == 0) {
          return 0;
        }
        break;
      }
      *(char *)(param_1 + sVar8) = (char)pcVar3 + 'd';
      sVar8 = sVar8 + 1;
    } while (sVar2 != sVar8);
    iVar4 = sVar8 - 1;
    iVar7 = (sVar8 - 3) + param_1;
    sVar2 = sVar8;
    pcVar3 = (char *)(param_1 + sVar8);
    do {
      bVar1 = pcVar3[-1];
      sVar10 = sVar2 - 1;
      sVar12 = sVar2 - 2;
      *(byte *)(iVar7 + 3) = bVar1;
      if (iVar4 + -1 < 0) {
        if (bVar1 != 0) goto LAB_000ec4aa;
        break;
      }
      sVar2 = sVar2 - 3;
      *(byte *)(iVar7 + 3) = bVar1 | pcVar3[-2] << 6;
      uVar5 = ((uint)(byte)pcVar3[-2] << 0x1a) >> 0x1c;
      bVar1 = (byte)(((uint)(byte)pcVar3[-2] << 0x1a) >> 0x18);
      *(byte *)(iVar7 + 2) = bVar1 >> 4;
      if (iVar4 + -2 < 0) {
joined_r0x000ec542:
        sVar2 = sVar10;
        if (uVar5 != 0) goto LAB_000ec4aa;
        break;
      }
      *(byte *)(iVar7 + 2) = bVar1 >> 4 | pcVar3[-3] << 4;
      uVar5 = ((uint)(byte)pcVar3[-3] << 0x1a) >> 0x1e;
      bVar1 = (byte)(((uint)(byte)pcVar3[-3] << 0x1a) >> 0x18);
      *(byte *)(iVar7 + 1) = bVar1 >> 6;
      sVar10 = sVar12;
      if (iVar4 + -3 < 0) goto joined_r0x000ec542;
      pcVar3 = pcVar3 + -4;
      iVar4 = iVar4 + -4;
      *(byte *)(iVar7 + 1) = bVar1 >> 6 | *pcVar3 << 2;
      *(undefined *)(param_1 + sVar2) = 0;
      iVar7 = iVar7 + -3;
    } while (-1 < iVar4);
    if ((int)sVar2 <= (int)sVar8) {
      pcVar3 = (char *)(param_1 + sVar2);
      do {
        pcVar3 = pcVar3 + 1;
        sVar2 = sVar2 + 1;
        if (*pcVar3 != '\0') {
LAB_000ec4aa:
          if ((int)sVar8 < (int)sVar2) {
            return 0;
          }
          uVar9 = param_1 + sVar2;
          uVar5 = (sVar8 - sVar2) + 1;
          if (((uVar9 | param_1) & 3) == 0 &&
              (9 < uVar5 && (param_1 + 4 <= uVar9 || uVar9 + 4 <= param_1))) {
            iVar7 = 0;
            uVar6 = 0;
            uVar11 = uVar5 & 0xfffffffc;
            do {
              uVar6 = uVar6 + 1;
              *(undefined4 *)(param_1 + iVar7) = *(undefined4 *)(uVar9 + iVar7);
              iVar7 = iVar7 + 4;
            } while (uVar6 < uVar5 >> 2);
            iVar7 = sVar2 + uVar11;
            if (uVar11 != uVar5) {
              *(undefined *)(param_1 + (uVar5 & 0xfffffffc)) = *(undefined *)(param_1 + iVar7);
              if (iVar7 + 1 <= (int)sVar8) {
                *(undefined *)(param_1 + uVar11 + 1) = *(undefined *)(param_1 + iVar7 + 1);
                if (iVar7 + 2 <= (int)sVar8) {
                  *(undefined *)(param_1 + uVar11 + 2) = *(undefined *)(param_1 + iVar7 + 2);
                  return uVar5;
                }
                return uVar5;
              }
            }
          }
          else {
            pcVar3 = (char *)(param_1 + (sVar2 - 1));
            do {
              pcVar3 = pcVar3 + 1;
              pcVar3[-sVar2] = *pcVar3;
            } while (pcVar3 != (char *)(param_1 + sVar8));
          }
          return uVar5;
        }
      } while ((int)sVar2 <= (int)sVar8);
    }
  }
  return 0;
}

