
int BN_add_word(BIGNUM *a,ulong w)

{
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  
  if (w == 0) {
    return 1;
  }
  iVar3 = a->top;
  if (iVar3 == 0) {
    iVar3 = BN_set_word(a,w);
    return iVar3;
  }
  if (a->neg == 0) {
    iVar2 = 0;
    while (iVar2 < iVar3) {
      uVar4 = w + a->d[iVar2];
      w = (ulong)(uVar4 < w);
      a->d[iVar2] = uVar4;
      if (w == 0) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      iVar3 = a->top;
    }
    if (iVar2 != iVar3) {
      return 1;
    }
    if (a->dmax <= iVar2) {
      pBVar1 = bn_expand2(a,iVar2 + 1);
      if (pBVar1 == (BIGNUM *)0x0) {
        return 0;
      }
      iVar3 = a->top;
    }
    a->top = iVar3 + 1;
    a->d[iVar2] = w;
    return 1;
  }
  a->neg = 0;
  puVar5 = a->d;
  if (iVar3 == 1) {
    uVar4 = *puVar5;
    if (w <= uVar4) {
      iVar3 = 0;
      goto LAB_004fa480;
    }
    *puVar5 = w - uVar4;
    a->neg = 1;
  }
  else {
    uVar4 = *puVar5;
    iVar3 = 0;
    puVar6 = puVar5;
    if (uVar4 < w) {
      do {
        puVar5 = puVar6 + 1;
        uVar7 = uVar4 - w;
        iVar3 = iVar3 + 1;
        uVar4 = *puVar5;
        *puVar6 = uVar7;
        w = 1;
        puVar6 = puVar5;
      } while (uVar4 == 0);
    }
LAB_004fa480:
    *puVar5 = uVar4 - w;
    if (uVar4 - w == 0) {
      iVar2 = a->top;
      if (iVar3 == a->top + -1) {
        a->top = iVar3;
        iVar2 = iVar3;
      }
      goto LAB_004fa49c;
    }
  }
  iVar2 = a->top;
LAB_004fa49c:
  if (iVar2 != 0) {
    a->neg = (uint)(a->neg == 0);
  }
  return 1;
}

