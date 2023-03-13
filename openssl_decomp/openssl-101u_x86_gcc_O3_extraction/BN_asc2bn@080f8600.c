
int BN_asc2bn(BIGNUM **a,char *str)

{
  char cVar1;
  ushort **ppuVar2;
  int iVar3;
  BIGNUM *pBVar4;
  ulong w;
  char *pcVar5;
  BIGNUM *a_00;
  int iVar6;
  int local_24;
  
  cVar1 = *str;
  pcVar5 = str;
  if (cVar1 == '-') {
    pcVar5 = str + 1;
    cVar1 = str[1];
  }
  if (cVar1 == '0') {
    local_24 = 0;
    if ((pcVar5[1] & 0xdfU) == 0x58) {
      local_24 = BN_hex2bn(a,pcVar5 + 2);
joined_r0x080f87d5:
      if (local_24 == 0) {
        return 0;
      }
      if (*str == '-') {
        (*a)->neg = 1;
      }
      return 1;
    }
  }
  else {
    if (cVar1 == '\0') {
      return 0;
    }
    if (cVar1 == '-') {
      pcVar5 = pcVar5 + 1;
      local_24 = 1;
    }
    else {
      local_24 = 0;
    }
  }
  ppuVar2 = __ctype_b_loc();
  iVar6 = 0;
  while ((*(byte *)((int)*ppuVar2 + (uint)(byte)pcVar5[iVar6] * 2 + 1) & 8) != 0) {
    iVar6 = iVar6 + 1;
    if (iVar6 == 0x20000000) {
      a_00 = (BIGNUM *)0x0;
LAB_080f8670:
      if (*a == (BIGNUM *)0x0) {
        BN_free(a_00);
      }
      return 0;
    }
  }
  if (a == (BIGNUM **)0x0) goto LAB_080f8785;
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
     ((iVar3 = iVar6 * 4 + 0x1f >> 5, a_00->dmax < iVar3 &&
      (pBVar4 = bn_expand2(a_00,iVar3), pBVar4 == (BIGNUM *)0x0)))) goto LAB_080f8670;
  iVar3 = ((iVar6 / 9) * 9 - iVar6) + 9;
  if (iVar3 == 9) {
    iVar3 = 0;
  }
  w = 0;
  while (cVar1 = *pcVar5, cVar1 != '\0') {
    while( true ) {
      iVar3 = iVar3 + 1;
      pcVar5 = pcVar5 + 1;
      w = cVar1 + -0x30 + w * 10;
      if (iVar3 != 9) break;
      BN_mul_word(a_00,1000000000);
      BN_add_word(a_00,w);
      cVar1 = *pcVar5;
      iVar3 = 0;
      w = 0;
      if (cVar1 == '\0') goto LAB_080f8750;
    }
  }
LAB_080f8750:
  a_00->neg = local_24;
  iVar3 = a_00->top;
  if (0 < iVar3) {
    do {
      if (a_00->d[iVar3 + -1] != 0) break;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    a_00->top = iVar3;
  }
  *a = a_00;
LAB_080f8785:
  local_24 = local_24 + iVar6;
  goto joined_r0x080f87d5;
}

