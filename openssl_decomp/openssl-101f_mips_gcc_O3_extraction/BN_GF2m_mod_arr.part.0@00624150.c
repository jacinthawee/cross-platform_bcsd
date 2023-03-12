
undefined4 BN_GF2m_mod_arr_part_0(uint **param_1,uint *param_2)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  uVar10 = *param_2;
  puVar7 = *param_1;
  if ((int)uVar10 < 0) {
    uVar10 = uVar10 + 0x1f;
  }
  iVar8 = (int)param_1[1] + -1;
  iVar11 = (int)uVar10 >> 5;
  bVar1 = iVar11 < iVar8;
  if (bVar1) {
    do {
      while( true ) {
        uVar10 = puVar7[iVar8];
        if (uVar10 != 0) break;
        iVar8 = iVar8 + -1;
        bVar1 = iVar11 < iVar8;
LAB_006241ac:
        if (!bVar1) goto LAB_006241b4;
      }
      puVar7[iVar8] = 0;
      uVar4 = param_2[1];
      puVar5 = param_2 + 2;
      if (uVar4 == 0) {
        uVar4 = *param_2;
      }
      else {
        do {
          uVar4 = *param_2 - uVar4;
          uVar9 = uVar4 + 0x1f;
          if (-1 < (int)uVar4) {
            uVar9 = uVar4;
          }
          uVar4 = uVar4 & 0x8000001f;
          if ((int)uVar4 < 0) {
            uVar4 = (uVar4 - 1 | 0xffffffe0) + 1;
          }
          iVar3 = iVar8 - ((int)uVar9 >> 5);
          puVar7[iVar3] = puVar7[iVar3] ^ uVar10 >> (uVar4 & 0x1f);
          if (uVar4 != 0) {
            puVar7[iVar3 + -1] = puVar7[iVar3 + -1] ^ uVar10 << (0x20 - uVar4 & 0x1f);
          }
          uVar4 = *puVar5;
          puVar5 = puVar5 + 1;
        } while (uVar4 != 0);
        uVar4 = *param_2;
      }
      uVar4 = uVar4 & 0x8000001f;
      if ((int)uVar4 < 0) {
        uVar4 = (uVar4 - 1 | 0xffffffe0) + 1;
      }
      puVar7[iVar8 - iVar11] = puVar7[iVar8 - iVar11] ^ uVar10 >> (uVar4 & 0x1f);
      if (uVar4 == 0) goto LAB_006241ac;
      puVar7[(iVar8 - iVar11) + -1] =
           puVar7[(iVar8 - iVar11) + -1] ^ uVar10 << (0x20 - uVar4 & 0x1f);
    } while (bVar1);
  }
LAB_006241b4:
  if (iVar11 == iVar8) {
    uVar10 = *param_2 & 0x8000001f;
    if ((int)uVar10 < 0) {
      uVar10 = (uVar10 - 1 | 0xffffffe0) + 1;
    }
    puVar5 = puVar7 + iVar11;
    uVar4 = *puVar5;
    uVar9 = uVar4 >> (uVar10 & 0x1f);
    while (uVar9 != 0) {
      if (uVar10 == 0) {
        uVar10 = 0;
      }
      else {
        uVar10 = (uVar4 << (0x20 - uVar10 & 0x1f)) >> (0x20 - uVar10 & 0x1f);
      }
      *puVar5 = uVar10;
      *puVar7 = *puVar7 ^ uVar9;
      uVar10 = param_2[1];
      puVar2 = param_2 + 2;
      while (uVar10 != 0) {
        uVar4 = uVar10 + 0x1f;
        if (-1 < (int)uVar10) {
          uVar4 = uVar10;
        }
        uVar10 = uVar10 & 0x8000001f;
        if ((int)uVar10 < 0) {
          uVar10 = (uVar10 - 1 | 0xffffffe0) + 1;
        }
        uVar6 = uVar9 >> (0x20 - uVar10 & 0x1f);
        puVar7[(int)uVar4 >> 5] = puVar7[(int)uVar4 >> 5] ^ uVar9 << (uVar10 & 0x1f);
        if ((uVar10 != 0) && (uVar6 != 0)) {
          puVar7[((int)uVar4 >> 5) + 1] = puVar7[((int)uVar4 >> 5) + 1] ^ uVar6;
        }
        uVar10 = *puVar2;
        puVar2 = puVar2 + 1;
      }
      uVar10 = *param_2 & 0x8000001f;
      if ((int)uVar10 < 0) {
        uVar10 = (uVar10 - 1 | 0xffffffe0) + 1;
      }
      uVar4 = *puVar5;
      uVar9 = uVar4 >> (uVar10 & 0x1f);
    }
  }
  puVar5 = param_1[1];
  if (0 < (int)puVar5) {
    puVar7 = puVar7 + (int)puVar5 + -2;
    do {
      if (puVar7[1] != 0) break;
      puVar5 = (uint *)((int)puVar5 + -1);
      puVar7 = puVar7 + -1;
    } while (puVar5 != (uint *)0x0);
    param_1[1] = puVar5;
  }
  return 1;
}

