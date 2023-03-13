
int BN_usub(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  ulong *puVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  bool bVar5;
  ulong *puVar6;
  ulong *puVar7;
  BIGNUM *pBVar8;
  ulong *puVar9;
  ulong uVar10;
  int iVar11;
  int iVar12;
  int words;
  int local_24;
  
  words = a->top;
  iVar11 = b->top;
  local_24 = words - iVar11;
  if (local_24 < 0) {
    ERR_put_error(3,0x73,100,"bn_add.c",0xb7);
    return 0;
  }
  if ((r->dmax < words) && (pBVar8 = bn_expand2(r,words), pBVar8 == (BIGNUM *)0x0)) {
    return 0;
  }
  bVar4 = false;
  puVar9 = a->d;
  puVar6 = b->d;
  iVar12 = 0;
  puVar1 = r->d;
  puVar7 = puVar1;
  if (iVar11 != 0) {
    do {
      uVar2 = puVar6[iVar12];
      uVar3 = puVar9[iVar12];
      uVar10 = (uVar3 - 1) - uVar2;
      bVar5 = !bVar4;
      bVar4 = uVar3 <= uVar2;
      if (bVar5) {
        bVar4 = uVar3 < uVar2;
        uVar10 = uVar3 - uVar2;
      }
      puVar1[iVar12] = uVar10;
      iVar12 = iVar12 + 1;
    } while (iVar11 != iVar12);
    puVar9 = puVar9 + iVar11;
    puVar7 = puVar1 + iVar11;
    if (bVar4) {
      puVar6 = puVar7;
      puVar7 = puVar9;
      if (local_24 == 0) {
        return 0;
      }
      do {
        puVar9 = puVar7 + 1;
        uVar10 = *puVar7;
        puVar7 = puVar6 + 1;
        local_24 = local_24 + -1;
        *puVar6 = uVar10 - 1;
        if (uVar10 != 0) goto LAB_081b72a4;
        puVar6 = puVar7;
        puVar7 = puVar9;
      } while (local_24 != 0);
      goto LAB_081b7260;
    }
  }
LAB_081b72a4:
  if ((((puVar9 != puVar7) && (local_24 != 0)) && (*puVar7 = *puVar9, local_24 != 1)) &&
     (puVar7[1] = puVar9[1], local_24 != 2)) {
    puVar7[2] = puVar9[2];
    iVar11 = local_24 + -4;
    if (local_24 != 3) {
      do {
        puVar7[3] = puVar9[3];
        if (((iVar11 == 0) || (puVar7[4] = puVar9[4], iVar11 == 1)) ||
           (puVar7[5] = puVar9[5], iVar11 == 2)) break;
        iVar11 = iVar11 + -4;
        puVar7[6] = puVar9[6];
        puVar7 = puVar7 + 4;
        puVar9 = puVar9 + 4;
      } while (iVar11 != -1);
    }
  }
LAB_081b7260:
  r->top = words;
  r->neg = 0;
  if (0 < words) {
    do {
      if (puVar1[words + -1] != 0) break;
      words = words + -1;
    } while (words != 0);
    r->top = words;
  }
  return 1;
}

