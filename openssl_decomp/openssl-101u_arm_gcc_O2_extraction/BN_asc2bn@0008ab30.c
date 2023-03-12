
int BN_asc2bn(BIGNUM **a,char *str)

{
  char cVar1;
  ushort **ppuVar2;
  BIGNUM *pBVar3;
  int iVar4;
  ulong *puVar5;
  ulong uVar6;
  char *pcVar7;
  ulong w;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  BIGNUM *a_00;
  
  cVar1 = *str;
  pcVar7 = str;
  if (cVar1 == '-') {
    cVar1 = str[1];
    pcVar7 = str + 1;
  }
  if (cVar1 == '0') {
    if ((pcVar7[1] & 0xdfU) == 0x58) {
      iVar9 = BN_hex2bn(a,pcVar7 + 2);
joined_r0x0008ab98:
      if (iVar9 == 0) {
        return 0;
      }
      if (*str != '-') {
        return 1;
      }
      (*a)->neg = 1;
      return 1;
    }
  }
  else {
    if (cVar1 == '\0') {
      return 0;
    }
    if (cVar1 == '-') {
      pcVar7 = pcVar7 + 1;
      iVar9 = 1;
      goto LAB_0008ab56;
    }
  }
  iVar9 = 0;
LAB_0008ab56:
  ppuVar2 = __ctype_b_loc();
  iVar8 = 0;
  while (((*ppuVar2)[(byte)pcVar7[iVar8]] & 0x800) != 0) {
    iVar8 = iVar8 + 1;
    if (iVar8 == 0x20000000) {
      a_00 = (BIGNUM *)0x0;
LAB_0008ab78:
      if (*a == (BIGNUM *)0x0) {
        BN_free(a_00);
      }
      return 0;
    }
  }
  if (a == (BIGNUM **)0x0) goto LAB_0008ac6a;
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
  if ((0x7fffffe0 < iVar8 * 4) ||
     ((iVar4 = iVar8 * 4 + 0x1f >> 5, a_00->dmax < iVar4 &&
      (pBVar3 = bn_expand2(a_00,iVar4), pBVar3 == (BIGNUM *)0x0)))) goto LAB_0008ab78;
  pbVar10 = (byte *)(pcVar7 + -1);
  uVar6 = ((iVar8 / 9) * 9 - iVar8) + 9;
  w = 0;
  if (uVar6 == 9) {
    uVar6 = 0;
  }
  while( true ) {
    pbVar10 = pbVar10 + 1;
    uVar6 = uVar6 + 1;
    w = ((uint)*pbVar10 + w * 10) - 0x30;
    if (*pbVar10 == 0) break;
    if (uVar6 == 9) {
      BN_mul_word(a_00,1000000000);
      uVar6 = 0;
      BN_add_word(a_00,w);
      w = uVar6;
    }
  }
  iVar4 = a_00->top;
  a_00->neg = iVar9;
  if (0 < iVar4) {
    puVar5 = a_00->d + iVar4 + 0x3fffffff;
    do {
      if (*puVar5 != 0) break;
      iVar4 = iVar4 + -1;
      puVar5 = puVar5 + -1;
    } while (iVar4 != 0);
    a_00->top = iVar4;
  }
  *a = a_00;
LAB_0008ac6a:
  iVar9 = iVar9 + iVar8;
  goto joined_r0x0008ab98;
}

