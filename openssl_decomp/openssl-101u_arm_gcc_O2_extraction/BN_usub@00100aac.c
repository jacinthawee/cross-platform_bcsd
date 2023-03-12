
int BN_usub(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  ulong *puVar1;
  uint uVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ulong *puVar7;
  ulong *puVar8;
  ulong *puVar9;
  ulong uVar10;
  int iVar11;
  int words;
  int iVar12;
  uint unaff_r11;
  ulong *puVar13;
  bool bVar14;
  
  words = a->top;
  iVar5 = b->top;
  iVar12 = words - iVar5;
  if (iVar12 < 0) {
    ERR_put_error(3,0x73,100,"bn_add.c",0xb7);
    return 0;
  }
  if ((r->dmax < words) && (pBVar3 = bn_expand2(r,words), pBVar3 == (BIGNUM *)0x0)) {
    return 0;
  }
  puVar1 = r->d;
  puVar9 = a->d;
  puVar8 = puVar1;
  if (iVar5 != 0) {
    uVar4 = 0;
    iVar11 = iVar5;
    puVar8 = b->d;
    puVar7 = puVar1;
    puVar13 = puVar9;
    do {
      uVar2 = *puVar13;
      uVar6 = *puVar8;
      uVar10 = (uVar2 - 1) - uVar6;
      if (uVar2 <= uVar6) {
        unaff_r11 = 1;
      }
      if (uVar2 >= uVar6 && uVar2 != uVar6) {
        unaff_r11 = 0;
      }
      bVar14 = uVar4 == 0;
      uVar4 = unaff_r11;
      if (bVar14) {
        uVar4 = (uint)(uVar2 < uVar6);
        uVar10 = uVar2 - uVar6;
      }
      iVar11 = iVar11 + -1;
      *puVar7 = uVar10;
      puVar8 = puVar8 + 1;
      puVar7 = puVar7 + 1;
      puVar13 = puVar13 + 1;
    } while (iVar11 != 0);
    puVar9 = puVar9 + iVar5;
    puVar7 = puVar1 + iVar5;
    puVar8 = puVar7;
    if (uVar4 != 0) {
      puVar8 = puVar9;
      if (iVar12 == 0) {
        return 0;
      }
      do {
        puVar9 = puVar8 + 1;
        uVar10 = *puVar8;
        iVar12 = iVar12 + -1;
        puVar8 = puVar7 + 1;
        *puVar7 = uVar10 - 1;
        if (uVar10 != 0) goto LAB_00100b7e;
        puVar7 = puVar8;
        puVar8 = puVar9;
      } while (iVar12 != 0);
      goto LAB_00100b48;
    }
  }
LAB_00100b7e:
  if ((((puVar8 != puVar9) && (iVar12 != 0)) && (*puVar8 = *puVar9, iVar12 != 1)) &&
     ((puVar8[1] = puVar9[1], iVar12 != 2 && (puVar8[2] = puVar9[2], iVar12 != 3)))) {
    do {
      iVar5 = iVar12 + -4;
      puVar8[3] = puVar9[3];
      if ((iVar5 == 0) ||
         ((puVar8[4] = puVar9[4], iVar5 == 1 || (puVar8[5] = puVar9[5], iVar5 == 2)))) break;
      puVar8[6] = puVar9[6];
      bVar14 = iVar12 != 7;
      puVar8 = puVar8 + 4;
      puVar9 = puVar9 + 4;
      iVar12 = iVar5;
    } while (bVar14);
  }
LAB_00100b48:
  r->top = words;
  r->neg = 0;
  if (words < 1) {
    return 1;
  }
  puVar8 = puVar1 + words + 0x3fffffff;
  do {
    if (*puVar8 != 0) break;
    words = words + -1;
    puVar8 = puVar8 + -1;
  } while (words != 0);
  r->top = words;
  return 1;
}

