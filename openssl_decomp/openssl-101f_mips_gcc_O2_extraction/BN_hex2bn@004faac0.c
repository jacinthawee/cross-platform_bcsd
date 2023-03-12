
int BN_hex2bn(BIGNUM **a,char *str)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  BIGNUM *pBVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  BIGNUM *a_00;
  
  if (str == (char *)0x0) {
    return 0;
  }
  cVar1 = *str;
  if (cVar1 != '\0') {
    if (cVar1 == '-') {
      str = str + 1;
    }
    uVar13 = (uint)(cVar1 == '-');
    iVar14 = 0;
    piVar3 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
    pbVar7 = (byte *)str;
    while (bVar2 = *pbVar7, pbVar7 = pbVar7 + 1,
          (*(ushort *)(*piVar3 + (uint)bVar2 * 2) & 0x10) != 0) {
      iVar14 = iVar14 + 1;
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
    iVar9 = iVar14 * 4 + 0x1f >> 5;
    if ((iVar9 <= a_00->dmax) || (pBVar6 = bn_expand2(a_00,iVar9), pBVar6 != (BIGNUM *)0x0)) {
      if (iVar14 == 0) {
        a_00->top = 0;
      }
      else {
        puVar11 = a_00->d;
        iVar9 = iVar14;
        puVar12 = puVar11;
        do {
          iVar10 = 8;
          if (iVar9 < 9) {
            iVar10 = iVar9;
          }
          iVar4 = (int)(char)((byte *)str)[iVar9 - iVar10];
          uVar8 = iVar4 - 0x30;
          if (((9 < uVar8) && (uVar8 = iVar4 - 0x57, 5 < iVar4 - 0x61U)) &&
             (uVar8 = 0, iVar4 - 0x41U < 6)) {
            uVar8 = iVar4 - 0x37;
          }
          if (iVar10 + -1 != 0) {
            iVar4 = (int)(char)((byte *)str)[iVar9 - (iVar10 + -1)];
            uVar5 = iVar4 - 0x30;
            if (9 < uVar5) {
              if (iVar4 - 0x61U < 6) {
                uVar5 = iVar4 - 0x57;
              }
              else if (iVar4 - 0x41U < 6) {
                uVar5 = iVar4 - 0x37;
              }
              else {
                uVar5 = 0;
              }
            }
            uVar8 = uVar8 << 4 | uVar5;
            if (iVar10 + -2 != 0) {
              iVar4 = (int)(char)((byte *)str)[iVar9 - (iVar10 + -2)];
              uVar5 = iVar4 - 0x30;
              if (9 < uVar5) {
                if (iVar4 - 0x61U < 6) {
                  uVar5 = iVar4 - 0x57;
                }
                else if (iVar4 - 0x41U < 6) {
                  uVar5 = iVar4 - 0x37;
                }
                else {
                  uVar5 = 0;
                }
              }
              uVar8 = uVar8 << 4 | uVar5;
              if (iVar10 + -3 != 0) {
                iVar4 = (int)(char)((byte *)str)[iVar9 - (iVar10 + -3)];
                uVar5 = iVar4 - 0x30;
                if (9 < uVar5) {
                  if (iVar4 - 0x61U < 6) {
                    uVar5 = iVar4 - 0x57;
                  }
                  else if (iVar4 - 0x41U < 6) {
                    uVar5 = iVar4 - 0x37;
                  }
                  else {
                    uVar5 = 0;
                  }
                }
                uVar8 = uVar8 << 4 | uVar5;
                if (iVar10 + -4 != 0) {
                  iVar4 = (int)(char)((byte *)str)[iVar9 - (iVar10 + -4)];
                  uVar5 = iVar4 - 0x30;
                  if (9 < uVar5) {
                    if (iVar4 - 0x61U < 6) {
                      uVar5 = iVar4 - 0x57;
                    }
                    else if (iVar4 - 0x41U < 6) {
                      uVar5 = iVar4 - 0x37;
                    }
                    else {
                      uVar5 = 0;
                    }
                  }
                  uVar8 = uVar5 | uVar8 << 4;
                  if (iVar10 + -5 != 0) {
                    iVar4 = (int)(char)((byte *)str)[iVar9 - (iVar10 + -5)];
                    uVar5 = iVar4 - 0x30;
                    if (9 < uVar5) {
                      if (iVar4 - 0x61U < 6) {
                        uVar5 = iVar4 - 0x57;
                      }
                      else if (iVar4 - 0x41U < 6) {
                        uVar5 = iVar4 - 0x37;
                      }
                      else {
                        uVar5 = 0;
                      }
                    }
                    uVar8 = uVar5 | uVar8 << 4;
                    if (iVar10 + -6 != 0) {
                      iVar4 = (int)(char)((byte *)str)[iVar9 - (iVar10 + -6)];
                      uVar5 = iVar4 - 0x30;
                      if (((9 < uVar5) && (uVar5 = iVar4 - 0x57, 5 < iVar4 - 0x61U)) &&
                         (uVar5 = 0, iVar4 - 0x41U < 6)) {
                        uVar5 = iVar4 - 0x37;
                      }
                      uVar8 = uVar5 | uVar8 << 4;
                      if (iVar10 != 7) {
                        iVar10 = (int)(char)((byte *)str)[iVar9 + -1];
                        uVar5 = iVar10 - 0x30;
                        if (9 < uVar5) {
                          if (iVar10 - 0x61U < 6) {
                            uVar5 = iVar10 - 0x57;
                          }
                          else if (iVar10 - 0x41U < 6) {
                            uVar5 = iVar10 - 0x37;
                          }
                          else {
                            uVar5 = 0;
                          }
                        }
                        uVar8 = uVar8 << 4 | uVar5;
                      }
                    }
                  }
                }
              }
            }
          }
          iVar9 = iVar9 + -8;
          *puVar12 = uVar8;
          puVar12 = puVar12 + 1;
        } while (0 < iVar9);
        uVar8 = iVar14 - 1U >> 3;
        iVar14 = uVar8 + 1;
        a_00->top = iVar14;
        puVar11 = puVar11 + (uVar8 - 1);
        do {
          if (puVar11[1] != 0) break;
          iVar14 = iVar14 + -1;
          puVar11 = puVar11 + -1;
        } while (iVar14 != 0);
        a_00->top = iVar14;
      }
      a_00->neg = uVar13;
      *a = a_00;
      return iVar15;
    }
    if (*a != (BIGNUM *)0x0) {
      return 0;
    }
    BN_free(a_00);
  }
  return 0;
}

