
undefined4 BN_from_montgomery_word(BIGNUM *param_1,BIGNUM *param_2,int param_3)

{
  int iVar1;
  ulong uVar2;
  uint uVar3;
  BIGNUM *pBVar4;
  ulong uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  ulong *puVar10;
  int iVar11;
  ulong uVar12;
  uint *puVar13;
  ulong *puVar14;
  ulong *ap;
  ulong *puVar15;
  
  iVar7 = *(int *)(param_3 + 0x1c);
  if (iVar7 == 0) {
    param_1->top = 0;
    return 1;
  }
  iVar11 = iVar7 * 2;
  if ((iVar11 - param_2->dmax == 0 || iVar11 < param_2->dmax) ||
     (pBVar4 = bn_expand2(param_2,iVar11), pBVar4 != (BIGNUM *)0x0)) {
    iVar1 = param_2->top;
    puVar14 = *(ulong **)(param_3 + 0x18);
    puVar15 = param_2->d;
    param_2->neg = *(uint *)(param_3 + 0x24) ^ param_2->neg;
    if (iVar11 - iVar1 != 0 && iVar1 <= iVar11) {
      memset(puVar15 + iVar1,0,(iVar11 - iVar1) * 4);
    }
    param_2->top = iVar11;
    iVar11 = *(int *)(param_3 + 0x40);
    if (iVar7 < 1) {
      iVar1 = 0;
    }
    else {
      iVar9 = 0;
      iVar1 = 0;
      puVar13 = puVar15 + iVar7;
      do {
        iVar9 = iVar9 + 1;
        uVar2 = bn_mul_add_words(puVar15,puVar14,iVar7,*puVar15 * iVar11);
        uVar6 = *puVar13;
        uVar3 = uVar2 + iVar1 + uVar6;
        *puVar13 = uVar3;
        if (uVar6 != uVar3) {
          iVar1 = 1;
        }
        if (uVar6 < uVar3) {
          iVar1 = 0;
        }
        puVar15 = puVar15 + 1;
        puVar13 = puVar13 + 1;
      } while (iVar9 != iVar7);
    }
    if ((iVar7 <= param_1->dmax) || (pBVar4 = bn_expand2(param_1,iVar7), pBVar4 != (BIGNUM *)0x0)) {
      puVar15 = param_1->d;
      ap = param_2->d + iVar7;
      param_1->neg = param_2->neg;
      param_1->top = iVar7;
      iVar11 = iVar7;
      uVar2 = bn_sub_words(puVar15,ap,puVar14,iVar7);
      if (iVar7 < 5) {
        iVar11 = 0;
      }
      uVar3 = (uint)puVar15 & ~(iVar1 - uVar2) | iVar1 - uVar2 & (uint)ap;
      if (4 < iVar7) {
        uVar6 = iVar7 - 5U >> 2;
        iVar11 = uVar3 + 4;
        puVar14 = ap + 1;
        puVar10 = puVar15 + 1;
        do {
          uVar12 = *(ulong *)(iVar11 + -4);
          uVar5 = *(ulong *)(iVar11 + 4);
          uVar8 = *(undefined4 *)((int)puVar14 + (uVar3 - (int)ap));
          puVar14[-1] = 0;
          uVar2 = *(ulong *)(iVar11 + 8);
          *(undefined4 *)((int)ap + iVar11 + -uVar3) = 0;
          puVar10[-1] = uVar12;
          puVar14[1] = 0;
          *(undefined4 *)((int)puVar15 + iVar11 + -uVar3) = uVar8;
          iVar11 = iVar11 + 0x10;
          puVar14[2] = 0;
          puVar10[2] = uVar2;
          puVar10[1] = uVar5;
          puVar14 = puVar14 + 4;
          puVar10 = puVar10 + 4;
        } while (iVar11 != uVar3 + uVar6 * 0x10 + 0x14);
        iVar11 = (uVar6 + 1) * 4;
      }
      if (iVar11 < iVar7) {
        iVar1 = iVar11 * 4;
        iVar9 = 0;
        do {
          *(undefined4 *)((int)puVar15 + iVar9 + iVar1) = *(undefined4 *)(uVar3 + iVar1 + iVar9);
          *(undefined4 *)((int)ap + iVar9 + iVar1) = 0;
          iVar9 = iVar9 + 4;
        } while (iVar9 != (iVar7 - iVar11) * 4);
      }
      iVar7 = param_2->top;
      if (0 < iVar7) {
        puVar15 = param_2->d + iVar7 + 0x3fffffff;
        do {
          if (*puVar15 != 0) break;
          iVar7 = iVar7 + -1;
          puVar15 = puVar15 + -1;
        } while (iVar7 != 0);
        param_2->top = iVar7;
      }
      iVar7 = param_1->top;
      if (iVar7 < 1) {
        return 1;
      }
      puVar15 = param_1->d + iVar7 + 0x3fffffff;
      do {
        if (*puVar15 != 0) break;
        iVar7 = iVar7 + -1;
        puVar15 = puVar15 + -1;
      } while (iVar7 != 0);
      param_1->top = iVar7;
      return 1;
    }
  }
  return 0;
}

