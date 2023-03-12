
int BN_sub_word(BIGNUM *a,ulong w)

{
  ulong *puVar1;
  ulong *puVar2;
  BIGNUM *pBVar3;
  ulong uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
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
    if (a->neg != 0) {
      a->neg = 0;
      iVar7 = 0;
      while (iVar7 < iVar6) {
        uVar5 = w + a->d[iVar7];
        w = (ulong)(uVar5 < w);
        a->d[iVar7] = uVar5;
        if (w == 0) goto LAB_004fa65c;
        iVar7 = iVar7 + 1;
        iVar6 = a->top;
      }
      if (iVar7 == iVar6) {
        if (a->dmax <= iVar7) {
          iVar6 = 0;
          pBVar3 = bn_expand2(a,iVar7 + 1);
          if (pBVar3 == (BIGNUM *)0x0) goto LAB_004fa664;
          iVar6 = a->top;
        }
        a->top = iVar6 + 1;
        a->d[iVar7] = w;
        a->neg = 1;
        return 1;
      }
LAB_004fa65c:
      iVar6 = 1;
LAB_004fa664:
      a->neg = 1;
      return iVar6;
    }
    if (iVar6 == 1) {
      puVar1 = a->d;
      uVar5 = *puVar1;
      iVar6 = 0;
      if (uVar5 < w) {
        *puVar1 = w - uVar5;
        a->neg = 1;
        return 1;
      }
      uVar4 = uVar5 - w;
    }
    else {
      puVar1 = a->d;
      uVar4 = *puVar1;
      iVar6 = 0;
      puVar2 = puVar1;
      if (uVar4 < w) {
        do {
          puVar1 = puVar2 + 1;
          iVar6 = iVar6 + 1;
          *puVar2 = uVar4 - w;
          uVar4 = *puVar1;
          w = 1;
          puVar2 = puVar1;
        } while (uVar4 == 0);
      }
      uVar4 = uVar4 - w;
    }
    *puVar1 = uVar4;
    if (uVar4 == 0) {
      if (a->top + -1 != iVar6) {
        return 1;
      }
      a->top = iVar6;
    }
  }
  return 1;
}

