
uint t_fromb64(undefined4 *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  char *pcVar9;
  uint uVar10;
  byte *pbVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  undefined4 *puVar22;
  
  cVar2 = *param_2;
  while ((iVar6 = (int)cVar2, iVar6 != 0 && ((iVar6 == 0x20 || ((iVar6 - 9U & 0xff) < 2))))) {
    param_2 = param_2 + 1;
    cVar2 = *param_2;
  }
  iVar6 = (*(code *)PTR_strlen_006a9a24)(param_2);
  if (0 < iVar6) {
    iVar21 = 0;
    puVar12 = param_1;
    do {
      cVar2 = *param_2;
      param_2 = param_2 + 1;
      iVar7 = (*(code *)PTR_strchr_006a9a28)
                        ("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz./",
                         (int)cVar2);
      if (iVar7 == 0) {
        if (iVar21 == 0) {
          return 0;
        }
        break;
      }
      iVar21 = iVar21 + 1;
      *(char *)puVar12 = (char)iVar7 + '\x10';
      puVar12 = (undefined4 *)((int)puVar12 + 1);
    } while (iVar6 != iVar21);
    pbVar11 = (byte *)((int)param_1 + iVar21);
    iVar7 = iVar21 + -1;
    pbVar8 = pbVar11;
    iVar6 = iVar21;
    do {
      bVar3 = pbVar11[-1];
      iVar15 = iVar7 + -1;
      iVar17 = iVar7 + -2;
      iVar18 = iVar7 + -3;
      iVar20 = iVar6 + -1;
      iVar7 = iVar7 + -4;
      *pbVar8 = bVar3;
      if (iVar15 < 0) {
        iVar20 = iVar6;
        if (bVar3 != 0) goto LAB_005c88d4;
        break;
      }
      iVar15 = iVar6 + -2;
      iVar6 = iVar6 + -3;
      *pbVar8 = pbVar11[-2] << 6 | bVar3;
      bVar3 = pbVar11[-2];
      bVar5 = (byte)(((uint)bVar3 << 0x1a) >> 0x18);
      pbVar8[-1] = bVar5 >> 4;
      if (iVar17 < 0) {
        if (((uint)bVar3 << 0x1a) >> 0x1c != 0) {
          bVar4 = iVar21 < iVar20;
          goto LAB_005c88d8;
        }
        break;
      }
      pbVar8[-1] = pbVar11[-3] << 4 | bVar5 >> 4;
      bVar3 = pbVar11[-3];
      bVar5 = (byte)(((uint)bVar3 << 0x1a) >> 0x18);
      pbVar8[-2] = bVar5 >> 6;
      if (iVar18 < 0) {
        iVar20 = iVar15;
        if (((uint)bVar3 << 0x1a) >> 0x1e != 0) {
          bVar4 = iVar21 < iVar15;
          goto LAB_005c88d8;
        }
        break;
      }
      bVar3 = pbVar11[-4];
      pbVar11 = pbVar11 + -4;
      pbVar8[-3] = 0;
      pbVar8[-2] = bVar3 << 2 | bVar5 >> 6;
      pbVar8 = pbVar8 + -3;
      iVar20 = iVar6;
    } while (-1 < iVar7);
    pcVar9 = (char *)((int)param_1 + iVar20);
    iVar6 = iVar20;
    if (iVar21 < iVar20) {
      return 0;
    }
    do {
      pcVar1 = pcVar9 + 1;
      iVar6 = iVar6 + 1;
      pcVar9 = pcVar9 + 1;
      if (*pcVar1 != '\0') {
LAB_005c88d4:
        bVar4 = iVar21 < iVar6;
        iVar20 = iVar6;
LAB_005c88d8:
        if (bVar4) {
          return 0;
        }
        puVar12 = (undefined4 *)((int)param_1 + iVar20);
        uVar10 = (iVar21 - iVar20) + 1;
        if ((((uint)puVar12 & 3) != 0 || puVar12 < param_1 + 1 && 0 < iVar20 + 4) || (uVar10 < 9)) {
          puVar22 = param_1;
          do {
            cVar2 = *(char *)puVar12;
            puVar12 = (undefined4 *)((int)puVar12 + 1);
            *(char *)puVar22 = cVar2;
            puVar22 = (undefined4 *)((int)puVar22 + 1);
          } while (puVar12 != (undefined4 *)((int)param_1 + iVar21 + 1));
          return uVar10;
        }
        uVar14 = 0;
        uVar13 = ((iVar21 - iVar20) - 3U >> 2) + 1;
        uVar16 = uVar13 * 4;
        puVar22 = param_1;
        do {
          uVar19 = *puVar12;
          uVar14 = uVar14 + 1;
          puVar12 = puVar12 + 1;
          *puVar22 = uVar19;
          puVar22 = puVar22 + 1;
        } while (uVar14 < uVar13);
        iVar20 = iVar20 + uVar16;
        if (uVar16 == uVar10) {
          return uVar10;
        }
        *(char *)(param_1 + uVar13) = *(char *)((int)param_1 + iVar20);
        if (iVar21 < iVar20 + 1) {
          return uVar10;
        }
        *(char *)((int)param_1 + uVar16 + 1) = *(char *)((int)param_1 + iVar20 + 1);
        if (iVar20 + 2 <= iVar21) {
          *(char *)((int)param_1 + uVar16 + 2) = *(char *)((int)param_1 + iVar20 + 2);
          return uVar10;
        }
        return uVar10;
      }
    } while (iVar6 <= iVar21);
  }
  return 0;
}

