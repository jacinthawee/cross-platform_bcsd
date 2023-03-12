
int BN_hex2bn(BIGNUM **a,char *str)

{
  char cVar1;
  ushort **ppuVar2;
  uint uVar3;
  BIGNUM *pBVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  BIGNUM *a_00;
  ulong *puVar11;
  uint *puVar12;
  uint local_34;
  
  if ((str != (char *)0x0) && (cVar1 = *str, cVar1 != '\0')) {
    if (cVar1 == '-') {
      str = str + 1;
    }
    iVar10 = 0;
    local_34 = (uint)(cVar1 == '-');
    ppuVar2 = __ctype_b_loc();
    while (((*ppuVar2)[(byte)str[iVar10]] & 0x1000) != 0) {
      iVar10 = iVar10 + 1;
    }
    if (a == (BIGNUM **)0x0) {
      return local_34 + iVar10;
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
    iVar5 = iVar10 * 4 + 0x1f >> 5;
    if ((iVar5 <= a_00->dmax) || (pBVar4 = bn_expand2(a_00,iVar5), pBVar4 != (BIGNUM *)0x0)) {
      if (iVar10 == 0) {
        a_00->top = 0;
      }
      else {
        puVar11 = a_00->d;
        puVar12 = puVar11 + -1;
        iVar5 = iVar10;
        do {
          iVar8 = 0;
          iVar9 = 8;
          if (iVar5 < 9) {
            iVar9 = iVar5;
          }
          uVar3 = 0;
          do {
            uVar7 = (uint)(byte)str[iVar8 + (iVar5 - iVar9)];
            uVar6 = uVar7 - 0x30;
            if (9 < uVar6) {
              uVar6 = uVar7 - 0x57;
              if ((5 < uVar7 - 0x61) && (uVar6 = 0, uVar7 - 0x41 < 6)) {
                uVar6 = uVar7 - 0x37;
              }
            }
            iVar8 = iVar8 + 1;
            uVar3 = uVar6 | uVar3 << 4;
          } while (0 < iVar9 - iVar8);
          iVar5 = iVar5 + -8;
          puVar12 = puVar12 + 1;
          *puVar12 = uVar3;
        } while (0 < iVar5);
        uVar3 = iVar10 - 1U >> 3;
        iVar5 = uVar3 + 1;
        a_00->top = iVar5;
        puVar11 = puVar11 + uVar3;
        do {
          if (*puVar11 != 0) break;
          iVar5 = iVar5 + -1;
          puVar11 = puVar11 + -1;
        } while (iVar5 != 0);
        a_00->top = iVar5;
      }
      a_00->neg = local_34;
      *a = a_00;
      return local_34 + iVar10;
    }
    if (*a == (BIGNUM *)0x0) {
      BN_free(a_00);
      return 0;
    }
  }
  return 0;
}

