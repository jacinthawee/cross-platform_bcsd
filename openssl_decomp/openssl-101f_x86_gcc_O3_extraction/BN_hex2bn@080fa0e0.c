
int BN_hex2bn(BIGNUM **a,char *str)

{
  char cVar1;
  uint *puVar2;
  ushort **ppuVar3;
  int iVar4;
  uint uVar5;
  BIGNUM *pBVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint *local_34;
  BIGNUM *local_30;
  uint local_2c;
  
  if ((str == (char *)0x0) || (cVar1 = *str, cVar1 == '\0')) {
    return 0;
  }
  if (cVar1 == '-') {
    str = str + 1;
  }
  local_2c = (uint)(cVar1 == '-');
  ppuVar3 = __ctype_b_loc();
  iVar10 = 0;
  while ((*(byte *)((int)*ppuVar3 + (uint)(byte)str[iVar10] * 2 + 1) & 0x10) != 0) {
    iVar10 = iVar10 + 1;
  }
  if (a != (BIGNUM **)0x0) {
    local_30 = *a;
    if (local_30 == (BIGNUM *)0x0) {
      local_30 = BN_new();
      if (local_30 == (BIGNUM *)0x0) {
        return 0;
      }
    }
    else {
      BN_set_word(local_30,0);
    }
    iVar4 = iVar10 * 4 + 0x1f >> 5;
    if ((local_30->dmax < iVar4) && (pBVar6 = bn_expand2(local_30,iVar4), pBVar6 == (BIGNUM *)0x0))
    {
      if (*a != (BIGNUM *)0x0) {
        return 0;
      }
      BN_free(local_30);
      return 0;
    }
    if (iVar10 == 0) {
      local_30->top = 0;
    }
    else {
      puVar2 = local_30->d;
      iVar4 = iVar10;
      local_34 = puVar2;
      do {
        iVar8 = 8;
        if (iVar4 < 9) {
          iVar8 = iVar4;
        }
        iVar7 = (int)str[iVar4 - iVar8];
        uVar5 = iVar7 - 0x30U;
        if ((9 < iVar7 - 0x30U) && (uVar5 = iVar7 - 0x57, 5 < iVar7 - 0x61U)) {
          uVar5 = 0;
          if (iVar7 - 0x41U < 6) {
            uVar5 = iVar7 - 0x37;
          }
        }
        if (iVar8 + -1 != 0) {
          iVar7 = (int)str[iVar4 - (iVar8 + -1)];
          uVar9 = iVar7 - 0x30U;
          if ((9 < iVar7 - 0x30U) && (uVar9 = iVar7 - 0x57, 5 < iVar7 - 0x61U)) {
            uVar9 = 0;
            if (iVar7 - 0x41U < 6) {
              uVar9 = iVar7 - 0x37;
            }
          }
          uVar5 = uVar5 << 4 | uVar9;
          if (iVar8 + -2 != 0) {
            iVar7 = (int)str[iVar4 - (iVar8 + -2)];
            uVar9 = iVar7 - 0x30U;
            if ((9 < iVar7 - 0x30U) && (uVar9 = iVar7 - 0x57, 5 < iVar7 - 0x61U)) {
              uVar9 = 0;
              if (iVar7 - 0x41U < 6) {
                uVar9 = iVar7 - 0x37;
              }
            }
            uVar5 = uVar5 << 4 | uVar9;
            if (iVar8 + -3 != 0) {
              iVar7 = (int)str[iVar4 - (iVar8 + -3)];
              uVar9 = iVar7 - 0x30U;
              if ((9 < iVar7 - 0x30U) && (uVar9 = iVar7 - 0x57, 5 < iVar7 - 0x61U)) {
                uVar9 = 0;
                if (iVar7 - 0x41U < 6) {
                  uVar9 = iVar7 - 0x37;
                }
              }
              uVar5 = uVar5 << 4 | uVar9;
              if (iVar8 + -4 != 0) {
                iVar7 = (int)str[iVar4 - (iVar8 + -4)];
                uVar9 = iVar7 - 0x30U;
                if ((9 < iVar7 - 0x30U) && (uVar9 = iVar7 - 0x57, 5 < iVar7 - 0x61U)) {
                  uVar9 = 0;
                  if (iVar7 - 0x41U < 6) {
                    uVar9 = iVar7 - 0x37;
                  }
                }
                uVar5 = uVar5 << 4 | uVar9;
                if (iVar8 + -5 != 0) {
                  iVar7 = (int)str[iVar4 - (iVar8 + -5)];
                  uVar9 = iVar7 - 0x30U;
                  if ((9 < iVar7 - 0x30U) && (uVar9 = iVar7 - 0x57, 5 < iVar7 - 0x61U)) {
                    uVar9 = 0;
                    if (iVar7 - 0x41U < 6) {
                      uVar9 = iVar7 - 0x37;
                    }
                  }
                  uVar5 = uVar5 << 4 | uVar9;
                  if (iVar8 + -6 != 0) {
                    iVar7 = (int)str[iVar4 - (iVar8 + -6)];
                    uVar9 = iVar7 - 0x30U;
                    if ((9 < iVar7 - 0x30U) && (uVar9 = iVar7 - 0x57, 5 < iVar7 - 0x61U)) {
                      uVar9 = 0;
                      if (iVar7 - 0x41U < 6) {
                        uVar9 = iVar7 - 0x37;
                      }
                    }
                    uVar5 = uVar5 << 4 | uVar9;
                    if (iVar8 != 7) {
                      iVar8 = (int)str[iVar4 + -1];
                      uVar9 = iVar8 - 0x30;
                      if (9 < uVar9) {
                        if (iVar8 - 0x61U < 6) {
                          uVar9 = iVar8 - 0x57;
                        }
                        else {
                          uVar9 = iVar8 - 0x37;
                          if (5 < iVar8 - 0x41U) {
                            uVar9 = 0;
                          }
                        }
                      }
                      uVar5 = uVar5 << 4 | uVar9;
                    }
                  }
                }
              }
            }
          }
        }
        iVar4 = iVar4 + -8;
        *local_34 = uVar5;
        local_34 = local_34 + 1;
      } while (0 < iVar4);
      iVar4 = (iVar10 - 1U >> 3) + 1;
      local_30->top = iVar4;
      do {
        if (puVar2[iVar4 + -1] != 0) break;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      local_30->top = iVar4;
    }
    local_30->neg = local_2c;
    *a = local_30;
  }
  return local_2c + iVar10;
}

