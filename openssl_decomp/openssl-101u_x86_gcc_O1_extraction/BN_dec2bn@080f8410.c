
int BN_dec2bn(BIGNUM **a,char *str)

{
  int iVar1;
  char cVar2;
  ushort **ppuVar3;
  int words;
  BIGNUM *pBVar4;
  int iVar5;
  ulong w;
  BIGNUM *a_00;
  uint uVar6;
  
  if ((str == (char *)0x0) || (cVar2 = *str, cVar2 == '\0')) {
    return 0;
  }
  if (cVar2 == '-') {
    str = str + 1;
  }
  uVar6 = (uint)(cVar2 == '-');
  ppuVar3 = __ctype_b_loc();
  iVar5 = 0;
  while ((*(byte *)((int)*ppuVar3 + (uint)(byte)str[iVar5] * 2 + 1) & 8) != 0) {
    iVar5 = iVar5 + 1;
    if (iVar5 == 0x20000000) {
      a_00 = (BIGNUM *)0x0;
LAB_080f8458:
      if (*a != (BIGNUM *)0x0) {
        return 0;
      }
      BN_free(a_00);
      return 0;
    }
  }
  iVar1 = uVar6 + iVar5;
  if (a == (BIGNUM **)0x0) {
    return iVar1;
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
  if ((0x7fffffe0 < iVar5 * 4) ||
     ((words = iVar5 * 4 + 0x1f >> 5, a_00->dmax < words &&
      (pBVar4 = bn_expand2(a_00,words), pBVar4 == (BIGNUM *)0x0)))) goto LAB_080f8458;
  iVar5 = ((iVar5 / 9) * 9 - iVar5) + 9;
  if (iVar5 == 9) {
    iVar5 = 0;
  }
  w = 0;
  while (cVar2 = *str, cVar2 != '\0') {
    while( true ) {
      iVar5 = iVar5 + 1;
      str = str + 1;
      w = cVar2 + -0x30 + w * 10;
      if (iVar5 != 9) break;
      BN_mul_word(a_00,1000000000);
      BN_add_word(a_00,w);
      cVar2 = *str;
      iVar5 = 0;
      w = 0;
      if (cVar2 == '\0') goto LAB_080f8540;
    }
  }
LAB_080f8540:
  iVar5 = a_00->top;
  a_00->neg = uVar6;
  if (0 < iVar5) {
    do {
      if (a_00->d[iVar5 + -1] != 0) break;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    a_00->top = iVar5;
  }
  *a = a_00;
  return iVar1;
}

