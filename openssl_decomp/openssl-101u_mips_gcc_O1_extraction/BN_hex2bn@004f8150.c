
int BN_hex2bn(BIGNUM **a,char *str)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  BIGNUM *pBVar4;
  uint *puVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  BIGNUM *a_00;
  
  if (str == (char *)0x0) {
    return 0;
  }
  cVar1 = *str;
  if (cVar1 == '\0') {
    return 0;
  }
  if (cVar1 == '-') {
    str = str + 1;
  }
  uVar13 = (uint)(cVar1 == '-');
  iVar14 = 0;
  piVar3 = (int *)(*(code *)PTR___ctype_b_loc_006a9938)();
  pbVar6 = (byte *)str;
  while (bVar2 = *pbVar6, pbVar6 = pbVar6 + 1, (*(ushort *)(*piVar3 + (uint)bVar2 * 2) & 0x10) != 0)
  {
    iVar14 = iVar14 + 1;
    a_00 = (BIGNUM *)0x0;
    if (iVar14 == 0x20000000) {
LAB_004f81e0:
      pBVar4 = *a;
LAB_004f81e4:
      if (pBVar4 != (BIGNUM *)0x0) {
        return 0;
      }
      BN_free(a_00);
      return 0;
    }
  }
  iVar15 = uVar13 + iVar14;
  if (a == (BIGNUM **)0x0) {
    return iVar15;
  }
  a_00 = *a;
  if (a_00 == (BIGNUM *)0x0) {
    a_00 = BN_new();
    if (a_00 == (BIGNUM *)0x0) {
      return 0;
    }
  }
  else {
    BN_set_word(a_00,0);
  }
  if (0x7fffffe0 < iVar14 * 4) goto LAB_004f81e0;
  iVar8 = iVar14 * 4 + 0x1f >> 5;
  if ((a_00->dmax < iVar8) && (pBVar4 = bn_expand2(a_00,iVar8), pBVar4 == (BIGNUM *)0x0)) {
    pBVar4 = *a;
    goto LAB_004f81e4;
  }
  if (iVar14 == 0) {
    a_00->top = 0;
    goto LAB_004f8528;
  }
  puVar12 = a_00->d;
  puVar5 = puVar12;
  iVar8 = iVar14;
  do {
    iVar11 = 8;
    if (iVar8 < 9) {
      iVar11 = iVar8;
    }
    iVar9 = (int)(char)((byte *)str)[iVar8 - iVar11];
    uVar7 = iVar9 - 0x30;
    if (((9 < uVar7) && (uVar7 = iVar9 - 0x57, 5 < iVar9 - 0x61U)) && (uVar7 = 0, iVar9 - 0x41U < 6)
       ) {
      uVar7 = iVar9 - 0x37;
    }
    if (iVar11 + -1 != 0) {
      iVar9 = (int)(char)((byte *)str)[iVar8 - (iVar11 + -1)];
      uVar10 = iVar9 - 0x30;
      if (9 < uVar10) {
        if (iVar9 - 0x61U < 6) {
          uVar10 = iVar9 - 0x57;
        }
        else if (iVar9 - 0x41U < 6) {
          uVar10 = iVar9 - 0x37;
        }
        else {
          uVar10 = 0;
        }
      }
      uVar7 = uVar7 << 4 | uVar10;
      if (iVar11 + -2 != 0) {
        iVar9 = (int)(char)((byte *)str)[iVar8 - (iVar11 + -2)];
        uVar10 = iVar9 - 0x30;
        if (9 < uVar10) {
          if (iVar9 - 0x61U < 6) {
            uVar10 = iVar9 - 0x57;
          }
          else if (iVar9 - 0x41U < 6) {
            uVar10 = iVar9 - 0x37;
          }
          else {
            uVar10 = 0;
          }
        }
        uVar7 = uVar7 << 4 | uVar10;
        if (iVar11 + -3 != 0) {
          iVar9 = (int)(char)((byte *)str)[iVar8 - (iVar11 + -3)];
          uVar10 = iVar9 - 0x30;
          if (9 < uVar10) {
            if (iVar9 - 0x61U < 6) {
              uVar10 = iVar9 - 0x57;
            }
            else if (iVar9 - 0x41U < 6) {
              uVar10 = iVar9 - 0x37;
            }
            else {
              uVar10 = 0;
            }
          }
          uVar7 = uVar10 | uVar7 << 4;
          if (iVar11 + -4 != 0) {
            iVar9 = (int)(char)((byte *)str)[iVar8 - (iVar11 + -4)];
            uVar10 = iVar9 - 0x30;
            if (9 < uVar10) {
              if (iVar9 - 0x61U < 6) {
                uVar10 = iVar9 - 0x57;
              }
              else if (iVar9 - 0x41U < 6) {
                uVar10 = iVar9 - 0x37;
              }
              else {
                uVar10 = 0;
              }
            }
            uVar7 = uVar10 | uVar7 << 4;
            if (iVar11 + -5 != 0) {
              iVar9 = (int)(char)((byte *)str)[iVar8 - (iVar11 + -5)];
              uVar10 = iVar9 - 0x30;
              if (9 < uVar10) {
                if (iVar9 - 0x61U < 6) {
                  uVar10 = iVar9 - 0x57;
                }
                else if (iVar9 - 0x41U < 6) {
                  uVar10 = iVar9 - 0x37;
                }
                else {
                  uVar10 = 0;
                }
              }
              uVar7 = uVar10 | uVar7 << 4;
              if (iVar11 + -6 != 0) {
                iVar9 = (int)(char)((byte *)str)[iVar8 - (iVar11 + -6)];
                uVar10 = iVar9 - 0x30;
                if (((9 < uVar10) && (uVar10 = iVar9 - 0x57, 5 < iVar9 - 0x61U)) &&
                   (uVar10 = 0, iVar9 - 0x41U < 6)) {
                  uVar10 = iVar9 - 0x37;
                }
                uVar7 = uVar10 | uVar7 << 4;
                if (iVar11 != 7) {
                  iVar11 = (int)(char)((byte *)str)[iVar8 + -1];
                  uVar10 = iVar11 - 0x30;
                  if (9 < uVar10) {
                    if (iVar11 - 0x61U < 6) {
                      uVar10 = iVar11 - 0x57;
                    }
                    else if (iVar11 - 0x41U < 6) {
                      uVar10 = iVar11 - 0x37;
                    }
                    else {
                      uVar10 = 0;
                    }
                  }
                  uVar7 = uVar7 << 4 | uVar10;
                }
              }
            }
          }
        }
      }
    }
    iVar8 = iVar8 + -8;
    *puVar5 = uVar7;
    puVar5 = puVar5 + 1;
  } while (0 < iVar8);
  uVar7 = iVar14 - 1U >> 3;
  iVar14 = uVar7 + 1;
  a_00->top = iVar14;
  puVar12 = puVar12 + (uVar7 - 1);
  do {
    if (puVar12[1] != 0) break;
    iVar14 = iVar14 + -1;
    puVar12 = puVar12 + -1;
  } while (iVar14 != 0);
  a_00->top = iVar14;
LAB_004f8528:
  a_00->neg = uVar13;
  *a = a_00;
  return iVar15;
}

