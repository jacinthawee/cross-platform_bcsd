
int BN_dec2bn(BIGNUM **a,char *str)

{
  ulong w;
  char cVar1;
  ushort **ppuVar2;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *a_00;
  int iVar5;
  ulong uVar6;
  uint uVar7;
  
  if ((str == (char *)0x0) || (cVar1 = *str, cVar1 == '\0')) {
    return 0;
  }
  if (cVar1 == '-') {
    str = str + 1;
  }
  uVar7 = (uint)(cVar1 == '-');
  ppuVar2 = __ctype_b_loc();
  iVar5 = 0;
  while ((*(byte *)((int)*ppuVar2 + (uint)(byte)str[iVar5] * 2 + 1) & 8) != 0) {
    iVar5 = iVar5 + 1;
  }
  if (a != (BIGNUM **)0x0) {
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
    iVar3 = iVar5 * 4 + 0x1f >> 5;
    if ((a_00->dmax < iVar3) && (pBVar4 = bn_expand2(a_00,iVar3), pBVar4 == (BIGNUM *)0x0)) {
      if (*a != (BIGNUM *)0x0) {
        return 0;
      }
      BN_free(a_00);
      return 0;
    }
    iVar3 = ((iVar5 / 9) * 9 - iVar5) + 9;
    if (iVar3 == 9) {
      iVar3 = 0;
    }
    uVar6 = 0;
    while (cVar1 = *str, cVar1 != '\0') {
      while( true ) {
        iVar3 = iVar3 + 1;
        str = str + 1;
        w = cVar1 + -0x30 + uVar6 * 10;
        uVar6 = w;
        if (iVar3 != 9) break;
        BN_mul_word(a_00,1000000000);
        uVar6 = 0;
        BN_add_word(a_00,w);
        cVar1 = *str;
        iVar3 = 0;
        if (cVar1 == '\0') goto LAB_080fa570;
      }
    }
LAB_080fa570:
    iVar3 = a_00->top;
    a_00->neg = uVar7;
    if (0 < iVar3) {
      do {
        if (a_00->d[iVar3 + -1] != 0) break;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      a_00->top = iVar3;
    }
    *a = a_00;
  }
  return uVar7 + iVar5;
}

