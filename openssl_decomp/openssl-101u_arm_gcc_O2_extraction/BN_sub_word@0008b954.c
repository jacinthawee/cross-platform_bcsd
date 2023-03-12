
int BN_sub_word(BIGNUM *a,ulong w)

{
  ulong *puVar1;
  uint uVar2;
  ulong uVar3;
  ulong *puVar4;
  int iVar5;
  int iVar6;
  BIGNUM *pBVar7;
  
  if (w != 0) {
    iVar6 = a->top;
    if (iVar6 == 0) {
      iVar6 = BN_set_word(a,w);
      if (iVar6 == 0) {
        return 0;
      }
      BN_set_negative(a,1);
      return iVar6;
    }
    iVar5 = a->neg;
    if (iVar5 != 0) {
      iVar5 = 0;
      a->neg = 0;
      while (iVar5 < iVar6) {
        uVar2 = a->d[iVar5] + w;
        a->d[iVar5] = uVar2;
        iVar5 = iVar5 + 1;
        w = (ulong)(uVar2 < w);
        if (w == 0) goto LAB_0008b9f8;
        iVar6 = a->top;
      }
      if (iVar6 == iVar5) {
        iVar5 = iVar6;
        if (a->dmax <= iVar6) {
          pBVar7 = bn_expand2(a,iVar6 + 1);
          if (pBVar7 == (BIGNUM *)0x0) goto LAB_0008b9fa;
          iVar5 = a->top;
        }
        pBVar7 = (BIGNUM *)0x1;
        a->top = iVar5 + 1;
        a->d[iVar6] = w;
      }
      else {
LAB_0008b9f8:
        pBVar7 = (BIGNUM *)0x1;
      }
LAB_0008b9fa:
      a->neg = 1;
      return (int)pBVar7;
    }
    puVar4 = a->d;
    uVar3 = *puVar4;
    if (iVar6 == 1) {
      if (uVar3 < w) {
        *puVar4 = w - uVar3;
        a->neg = 1;
        return 1;
      }
    }
    else if (uVar3 < w) {
      do {
        puVar1 = puVar4 + 1;
        *puVar4 = uVar3 - w;
        uVar3 = *puVar1;
        iVar5 = iVar5 + 1;
        w = 1;
        puVar4 = puVar1;
      } while (uVar3 == 0);
      w = 1;
    }
    *puVar4 = uVar3 - w;
    if ((uVar3 - w == 0) && (a->top + -1 == iVar5)) {
      a->top = iVar5;
      return 1;
    }
  }
  return 1;
}

