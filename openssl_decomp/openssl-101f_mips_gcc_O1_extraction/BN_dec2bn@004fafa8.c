
int BN_dec2bn(BIGNUM **a,char *str)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  ulong *puVar4;
  BIGNUM *pBVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  ulong w;
  int iVar9;
  int iVar10;
  BIGNUM *a_00;
  
  if (str == (char *)0x0) {
    return 0;
  }
  cVar1 = *str;
  if (cVar1 != '\0') {
    if (cVar1 == '-') {
      str = str + 1;
    }
    uVar8 = (uint)(cVar1 == '-');
    iVar10 = 0;
    piVar3 = (int *)(*(code *)PTR___ctype_b_loc_006aaa48)();
    pbVar6 = (byte *)str;
    while (bVar2 = *pbVar6, pbVar6 = pbVar6 + 1, (*(ushort *)(*piVar3 + (uint)bVar2 * 2) & 8) != 0)
    {
      iVar10 = iVar10 + 1;
    }
    iVar9 = uVar8 + iVar10;
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
    iVar7 = iVar10 * 4 + 0x1f >> 5;
    if ((iVar7 <= a_00->dmax) || (pBVar5 = bn_expand2(a_00,iVar7), pBVar5 != (BIGNUM *)0x0)) {
      w = 0;
      iVar10 = (iVar10 / 9) * 9 - iVar10;
      iVar7 = iVar10 + 9;
      if (iVar10 == 0) {
        iVar7 = 0;
      }
      do {
        bVar2 = *str;
        iVar10 = w * 10;
        while( true ) {
          if ((char)bVar2 == 0) {
            iVar10 = a_00->top;
            a_00->neg = uVar8;
            if (iVar10 < 1) goto LAB_004fb168;
            puVar4 = a_00->d + iVar10 + -2;
            goto LAB_004fb14c;
          }
          iVar7 = iVar7 + 1;
          str = (char *)((byte *)str + 1);
          w = (int)(char)bVar2 + iVar10 + -0x30;
          if (iVar7 != 9) break;
          BN_mul_word(a_00,1000000000);
          BN_add_word(a_00,w);
          bVar2 = *str;
          iVar7 = 0;
          iVar10 = 0;
        }
      } while( true );
    }
    if (*a != (BIGNUM *)0x0) {
      return 0;
    }
    BN_free(a_00);
  }
  return 0;
  while( true ) {
    iVar10 = iVar10 + -1;
    puVar4 = puVar4 + -1;
    if (iVar10 == 0) break;
LAB_004fb14c:
    if (puVar4[1] != 0) break;
  }
  a_00->top = iVar10;
LAB_004fb168:
  *a = a_00;
  return iVar9;
}

