
int BN_dec2bn(BIGNUM **a,char *str)

{
  char cVar1;
  ushort **ppuVar2;
  BIGNUM *pBVar3;
  int words;
  ulong *puVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  ulong uVar8;
  ulong w;
  int iVar9;
  BIGNUM *a_00;
  
  if ((str != (char *)0x0) && (cVar1 = *str, cVar1 != '\0')) {
    if (cVar1 == '-') {
      str = str + 1;
    }
    iVar5 = 0;
    uVar7 = (uint)(cVar1 == '-');
    ppuVar2 = __ctype_b_loc();
    while (((*ppuVar2)[(byte)str[iVar5]] & 0x800) != 0) {
      iVar5 = iVar5 + 1;
    }
    iVar9 = uVar7 + iVar5;
    if (a == (BIGNUM **)0x0) {
      return iVar9;
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
    words = iVar5 * 4 + 0x1f >> 5;
    if ((words <= a_00->dmax) || (pBVar3 = bn_expand2(a_00,words), pBVar3 != (BIGNUM *)0x0)) {
      pbVar6 = (byte *)(str + -1);
      iVar5 = ((iVar5 / 9) * 9 - iVar5) + 9;
      uVar8 = 0;
      if (iVar5 == 9) {
        iVar5 = 0;
      }
      while( true ) {
        pbVar6 = pbVar6 + 1;
        iVar5 = iVar5 + 1;
        w = ((uint)*pbVar6 + uVar8 * 10) - 0x30;
        if (*pbVar6 == 0) break;
        uVar8 = w;
        if (iVar5 == 9) {
          BN_mul_word(a_00,1000000000);
          uVar8 = 0;
          iVar5 = 0;
          BN_add_word(a_00,w);
        }
      }
      iVar5 = a_00->top;
      a_00->neg = uVar7;
      if (0 < iVar5) {
        puVar4 = a_00->d + iVar5 + 0x3fffffff;
        do {
          if (*puVar4 != 0) break;
          iVar5 = iVar5 + -1;
          puVar4 = puVar4 + -1;
        } while (iVar5 != 0);
        a_00->top = iVar5;
      }
      *a = a_00;
      return iVar9;
    }
    if (*a == (BIGNUM *)0x0) {
      BN_free(a_00);
      return 0;
    }
  }
  return 0;
}

