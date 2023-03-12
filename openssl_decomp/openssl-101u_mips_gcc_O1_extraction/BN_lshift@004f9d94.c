
int BN_lshift(BIGNUM *r,BIGNUM *a,int n)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong *puVar3;
  BIGNUM *pBVar4;
  ulong *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulong *puVar10;
  int iVar11;
  
  if (n < 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x91,0x77,"bn_shift.c",0x8d);
    iVar11 = 0;
  }
  else {
    iVar11 = n >> 5;
    iVar6 = iVar11 + a->top;
    r->neg = a->neg;
    if (r->dmax <= iVar6) {
      pBVar4 = bn_expand2(r,iVar6 + 1);
      if (pBVar4 == (BIGNUM *)0x0) {
        return 0;
      }
      iVar6 = iVar11 + a->top;
    }
    puVar5 = r->d;
    uVar8 = n & 0x1f;
    puVar10 = a->d;
    puVar5[iVar6] = 0;
    if (uVar8 == 0) {
      iVar6 = a->top + -1;
      if (-1 < iVar6) {
        puVar2 = puVar10 + a->top;
        puVar3 = puVar5 + iVar11 + iVar6;
        do {
          puVar1 = puVar2 + -1;
          puVar2 = puVar2 + -1;
          *puVar3 = *puVar1;
          puVar3 = puVar3 + -1;
        } while (puVar10 != puVar2);
      }
    }
    else {
      iVar6 = a->top;
      if (-1 < iVar6 + -1) {
        uVar9 = puVar5[iVar11 + iVar6];
        puVar2 = puVar10 + iVar6;
        puVar3 = puVar5 + iVar11 + iVar6 + -1;
        do {
          puVar1 = puVar2 + -1;
          puVar2 = puVar2 + -1;
          uVar7 = *puVar1 >> (0x20 - uVar8 & 0x1f) | uVar9;
          uVar9 = *puVar1 << uVar8;
          puVar3[1] = uVar7;
          *puVar3 = uVar9;
          puVar3 = puVar3 + -1;
        } while (puVar10 != puVar2);
      }
    }
    (*(code *)PTR_memset_006a99f4)(puVar5,0,iVar11 << 2);
    iVar11 = iVar11 + a->top;
    iVar6 = iVar11 + 1;
    r->top = iVar6;
    if (iVar6 < 1) {
      return 1;
    }
    puVar5 = r->d + iVar11 + -1;
    do {
      if (puVar5[1] != 0) break;
      iVar6 = iVar6 + -1;
      puVar5 = puVar5 + -1;
    } while (iVar6 != 0);
    iVar11 = 1;
    r->top = iVar6;
  }
  return iVar11;
}

