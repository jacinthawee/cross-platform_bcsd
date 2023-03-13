
int BN_sub_word(BIGNUM *a,ulong w)

{
  uint uVar1;
  BIGNUM *pBVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  
  if (w != 0) {
    iVar3 = a->top;
    if (iVar3 == 0) {
      iVar3 = BN_set_word(a,w);
      if (iVar3 == 0) {
        return 0;
      }
      BN_set_negative(a,1);
      return iVar3;
    }
    if (a->neg != 0) {
      a->neg = 0;
      iVar6 = 0;
      while (iVar6 < iVar3) {
        uVar1 = a->d[iVar6] + w;
        a->d[iVar6] = uVar1;
        iVar6 = iVar6 + 1;
        if (w <= uVar1) goto LAB_080f9f82;
        w = (uint)(uVar1 < w);
        iVar3 = a->top;
      }
      if (iVar6 == iVar3) {
        if (a->dmax == iVar6 || a->dmax < iVar6) {
          pBVar2 = bn_expand2(a,iVar6 + 1);
          if (pBVar2 == (BIGNUM *)0x0) {
            iVar3 = 0;
            goto LAB_080f9f87;
          }
          iVar3 = a->top;
        }
        a->top = iVar3 + 1;
        a->d[iVar6] = w;
      }
LAB_080f9f82:
      iVar3 = 1;
LAB_080f9f87:
      a->neg = 1;
      return iVar3;
    }
    puVar5 = a->d;
    uVar1 = *puVar5;
    if (iVar3 == 1) {
      if (uVar1 < w) {
        *puVar5 = w - uVar1;
        goto LAB_080f9f87;
      }
      iVar3 = 0;
    }
    else {
      iVar3 = 0;
      puVar4 = puVar5;
      if (uVar1 < w) {
        do {
          puVar5 = puVar4 + 1;
          iVar3 = iVar3 + 1;
          *puVar4 = uVar1 - w;
          uVar1 = *puVar5;
          w = 1;
          puVar4 = puVar5;
        } while (uVar1 == 0);
      }
    }
    *puVar5 = uVar1 - w;
    if ((uVar1 - w == 0) && (a->top + -1 == iVar3)) {
      a->top = iVar3;
    }
  }
  return 1;
}

