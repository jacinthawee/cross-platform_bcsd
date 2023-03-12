
int BN_dec2bn(BIGNUM **a,char *str)

{
  char cVar1;
  ushort **ppuVar2;
  BIGNUM *pBVar3;
  int words;
  ulong *puVar4;
  ulong uVar5;
  ulong w;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  BIGNUM *a_00;
  
  if ((str == (char *)0x0) || (cVar1 = *str, cVar1 == '\0')) {
    return 0;
  }
  if (cVar1 == '-') {
    str = str + 1;
  }
  iVar6 = 0;
  uVar7 = (uint)(cVar1 == '-');
  ppuVar2 = __ctype_b_loc();
  while (((*ppuVar2)[(byte)str[iVar6]] & 0x800) != 0) {
    iVar6 = iVar6 + 1;
    if (iVar6 == 0x20000000) {
      a_00 = (BIGNUM *)0x0;
LAB_0008aa3a:
      if (*a != (BIGNUM *)0x0) {
        return 0;
      }
      BN_free(a_00);
      return 0;
    }
  }
  iVar8 = uVar7 + iVar6;
  if (a == (BIGNUM **)0x0) {
    return iVar8;
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
  if ((0x7fffffe0 < iVar6 * 4) ||
     ((words = iVar6 * 4 + 0x1f >> 5, a_00->dmax < words &&
      (pBVar3 = bn_expand2(a_00,words), pBVar3 == (BIGNUM *)0x0)))) goto LAB_0008aa3a;
  pbVar9 = (byte *)(str + -1);
  uVar5 = ((iVar6 / 9) * 9 - iVar6) + 9;
  w = 0;
  if (uVar5 == 9) {
    uVar5 = 0;
  }
  while( true ) {
    pbVar9 = pbVar9 + 1;
    uVar5 = uVar5 + 1;
    w = ((uint)*pbVar9 + w * 10) - 0x30;
    if (*pbVar9 == 0) break;
    if (uVar5 == 9) {
      BN_mul_word(a_00,1000000000);
      uVar5 = 0;
      BN_add_word(a_00,w);
      w = uVar5;
    }
  }
  iVar6 = a_00->top;
  a_00->neg = uVar7;
  if (0 < iVar6) {
    puVar4 = a_00->d + iVar6 + 0x3fffffff;
    do {
      if (*puVar4 != 0) break;
      iVar6 = iVar6 + -1;
      puVar4 = puVar4 + -1;
    } while (iVar6 != 0);
    a_00->top = iVar6;
  }
  *a = a_00;
  return iVar8;
}

