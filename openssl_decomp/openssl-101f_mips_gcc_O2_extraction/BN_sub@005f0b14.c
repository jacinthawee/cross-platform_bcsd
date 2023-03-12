
/* WARNING: Type propagation algorithm not settling */

int BN_sub(BIGNUM *r,BIGNUM *a,BIGNUM *b)

{
  bool bVar1;
  uint uVar2;
  BIGNUM *a_00;
  undefined *puVar3;
  int iVar4;
  ulong uVar5;
  ulong *puVar6;
  BIGNUM *pBVar7;
  ulong *puVar8;
  int iVar9;
  ulong *puVar10;
  int iVar11;
  
  bVar1 = a->neg == 0;
  if (bVar1) {
    iVar4 = b->neg;
    pBVar7 = a;
    a_00 = b;
  }
  else {
    iVar4 = b->neg;
    pBVar7 = b;
    a_00 = a;
  }
  uVar2 = (uint)!bVar1;
  if (iVar4 == 0) {
    iVar4 = a_00->top;
    if (a_00->top < pBVar7->top) {
      iVar4 = pBVar7->top;
    }
    if ((iVar4 <= r->dmax) || (iVar4 = (*(code *)PTR_bn_expand2_006a9680)(r), iVar4 != 0)) {
      iVar4 = (*(code *)PTR_BN_ucmp_006a9678)(pBVar7,a_00);
      if (iVar4 < 0) {
        iVar4 = BN_usub(r,a_00,pBVar7);
        if (iVar4 != 0) {
          r->neg = 1;
          return 1;
        }
      }
      else {
        iVar4 = BN_usub(r,pBVar7,a_00);
        if (iVar4 != 0) {
          r->neg = 0;
          return 1;
        }
      }
    }
    return 0;
  }
  iVar11 = a->top;
  iVar9 = b->top;
  pBVar7 = a;
  iVar4 = iVar9;
  if (iVar11 < iVar9) {
    pBVar7 = b;
    b = a;
    iVar4 = iVar11;
    iVar11 = iVar9;
  }
  if ((r->dmax <= iVar11) && (iVar9 = (*(code *)PTR_bn_expand2_006a9680)(r,iVar11 + 1), iVar9 == 0))
  {
    return 0;
  }
  puVar3 = PTR_bn_add_words_006a96a8;
  puVar8 = pBVar7->d;
  puVar10 = r->d;
  iVar9 = iVar11 - iVar4;
  puVar6 = b->d;
  r->top = iVar11;
  iVar11 = (*(code *)puVar3)(puVar10,puVar8,puVar6,iVar4);
  puVar10 = puVar10 + iVar4;
  puVar8 = puVar8 + iVar4;
  if (iVar11 != 0) {
    if (iVar9 == 0) {
LAB_005f0cac:
      *puVar10 = 1;
      r->top = r->top + 1;
      goto LAB_005f0cc4;
    }
    uVar5 = *puVar8 + 1;
    *puVar10 = uVar5;
    while( true ) {
      puVar10 = puVar10 + 1;
      puVar8 = puVar8 + 1;
      iVar9 = iVar9 + -1;
      if (uVar5 != 0) break;
      if (iVar9 == 0) goto LAB_005f0cac;
      uVar5 = *puVar8 + 1;
      *puVar10 = uVar5;
    }
  }
  if ((iVar9 != 0) && (iVar9 = iVar9 + -1, puVar8 != puVar10)) {
    do {
      iVar9 = iVar9 + -1;
      *puVar10 = *puVar8;
      puVar10 = puVar10 + 1;
      puVar8 = puVar8 + 1;
    } while (iVar9 != -1);
    r->neg = uVar2;
    return 1;
  }
LAB_005f0cc4:
  r->neg = uVar2;
  return 1;
}

