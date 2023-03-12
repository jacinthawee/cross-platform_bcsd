
int BN_add_word(BIGNUM *a,ulong w)

{
  BIGNUM *pBVar1;
  ulong *puVar2;
  int iVar3;
  ulong *puVar4;
  ulong uVar5;
  uint uVar6;
  int iVar7;
  
  if (w == 0) {
    return 1;
  }
  iVar3 = a->top;
  if (iVar3 == 0) {
    iVar3 = BN_set_word(a,w);
    return iVar3;
  }
  iVar7 = a->neg;
  if (iVar7 == 0) {
    while (iVar7 < iVar3) {
      uVar6 = a->d[iVar7] + w;
      a->d[iVar7] = uVar6;
      iVar7 = iVar7 + 1;
      w = (ulong)(uVar6 < w);
      if (w == 0) {
        return 1;
      }
      iVar3 = a->top;
    }
    if (iVar3 != iVar7) {
      return 1;
    }
    iVar7 = iVar3;
    if (a->dmax <= iVar3) {
      pBVar1 = bn_expand2(a,iVar3 + 1);
      if (pBVar1 == (BIGNUM *)0x0) {
        return 0;
      }
      iVar7 = a->top;
    }
    a->top = iVar7 + 1;
    a->d[iVar3] = w;
    return 1;
  }
  puVar2 = a->d;
  iVar7 = 0;
  a->neg = 0;
  uVar5 = *puVar2;
  if (iVar3 == 1) {
    if (uVar5 < w) {
      *puVar2 = w - uVar5;
      a->neg = 1;
      iVar3 = a->top;
      goto LAB_0008bacc;
    }
  }
  else if (uVar5 < w) {
    do {
      puVar4 = puVar2 + 1;
      *puVar2 = uVar5 - w;
      uVar5 = *puVar4;
      iVar7 = iVar7 + 1;
      w = 1;
      puVar2 = puVar4;
    } while (uVar5 == 0);
    w = 1;
  }
  *puVar2 = uVar5 - w;
  if (uVar5 - w == 0) {
    iVar3 = a->top;
    if (iVar7 == a->top + -1) {
      a->top = iVar7;
      iVar3 = iVar7;
    }
  }
  else {
    iVar3 = a->top;
  }
LAB_0008bacc:
  if (iVar3 == 0) {
    return 1;
  }
  uVar6 = count_leading_zeroes(a->neg);
  a->neg = uVar6 >> 5;
  return 1;
}

