
int BN_hex2bn(BIGNUM **a,char *str)

{
  char cVar1;
  ushort **ppuVar2;
  uint uVar3;
  BIGNUM *pBVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ulong *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  BIGNUM *a_00;
  uint *puVar14;
  
  if ((str == (char *)0x0) || (cVar1 = *str, cVar1 == '\0')) {
    return 0;
  }
  if (cVar1 == '-') {
    str = str + 1;
  }
  iVar12 = 0;
  uVar13 = (uint)(cVar1 == '-');
  ppuVar2 = __ctype_b_loc();
  while (((*ppuVar2)[(byte)str[iVar12]] & 0x1000) != 0) {
    iVar12 = iVar12 + 1;
    if (iVar12 == 0x20000000) {
      a_00 = (BIGNUM *)0x0;
LAB_0008a9b8:
      if (*a != (BIGNUM *)0x0) {
        return 0;
      }
      BN_free(a_00);
      return 0;
    }
  }
  iVar7 = uVar13 + iVar12;
  if (a == (BIGNUM **)0x0) {
    return iVar7;
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
  if ((0x7fffffe0 < iVar12 * 4) ||
     ((iVar5 = iVar12 * 4 + 0x1f >> 5, a_00->dmax < iVar5 &&
      (pBVar4 = bn_expand2(a_00,iVar5), pBVar4 == (BIGNUM *)0x0)))) goto LAB_0008a9b8;
  if (iVar12 == 0) {
    a_00->top = 0;
  }
  else {
    puVar9 = a_00->d;
    puVar14 = puVar9 + -1;
    iVar5 = iVar12;
    do {
      iVar10 = 0;
      iVar11 = 8;
      if (iVar5 < 9) {
        iVar11 = iVar5;
      }
      uVar3 = 0;
      do {
        uVar8 = (uint)(byte)str[iVar10 + (iVar5 - iVar11)];
        uVar6 = uVar8 - 0x30;
        if (9 < uVar6) {
          uVar6 = uVar8 - 0x57;
          if ((5 < uVar8 - 0x61) && (uVar6 = 0, uVar8 - 0x41 < 6)) {
            uVar6 = uVar8 - 0x37;
          }
        }
        iVar10 = iVar10 + 1;
        uVar3 = uVar6 | uVar3 << 4;
      } while (0 < iVar11 - iVar10);
      iVar5 = iVar5 + -8;
      puVar14 = puVar14 + 1;
      *puVar14 = uVar3;
    } while (0 < iVar5);
    uVar3 = iVar12 - 1U >> 3;
    iVar12 = uVar3 + 1;
    a_00->top = iVar12;
    puVar9 = puVar9 + uVar3;
    do {
      if (*puVar9 != 0) break;
      iVar12 = iVar12 + -1;
      puVar9 = puVar9 + -1;
    } while (iVar12 != 0);
    a_00->top = iVar12;
  }
  a_00->neg = uVar13;
  *a = a_00;
  return iVar7;
}

