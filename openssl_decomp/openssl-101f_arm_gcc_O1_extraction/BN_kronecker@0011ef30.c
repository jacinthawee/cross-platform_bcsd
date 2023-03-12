
int BN_kronecker(BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *pBVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  a_01 = BN_CTX_get(ctx);
  if (a_01 == (BIGNUM *)0x0) {
    uVar2 = 0xfffffffe;
    goto LAB_0011ef9a;
  }
  pBVar1 = BN_copy(a_00,a);
  if ((pBVar1 == (BIGNUM *)0x0) || (pBVar1 = BN_copy(a_01,b), pBVar1 == (BIGNUM *)0x0))
  goto LAB_0011ef5c;
  uVar2 = a_01->top;
  if (uVar2 == 0) {
    if (a_00->top == 1) {
      uVar2 = count_leading_zeroes(*a_00->d - 1);
      uVar2 = uVar2 >> 5;
    }
    goto LAB_0011ef9a;
  }
  if ((a_00->top < 1) || (-1 < (int)(*a_00->d << 0x1f))) {
    if (0 < (int)uVar2) {
      uVar2 = *a_01->d & 1;
      if (uVar2 == 0) goto LAB_0011ef9a;
      goto LAB_0011efc0;
    }
  }
  else {
LAB_0011efc0:
    iVar6 = 0;
    while (iVar3 = BN_is_bit_set(a_01,iVar6), iVar3 == 0) {
      iVar6 = iVar6 + 1;
    }
    iVar3 = BN_rshift(a_01,a_01,iVar6);
    if (iVar3 == 0) {
LAB_0011ef5c:
      BN_CTX_end(ctx);
      return -2;
    }
    uVar5 = a_00->top;
    if (iVar6 << 0x1f < 0) {
      uVar2 = uVar5;
      if (uVar5 != 0) {
        uVar2 = *a_00->d & 7;
      }
      uVar2 = *(uint *)(&tab_8691 + uVar2 * 4);
    }
    else {
      uVar2 = 1;
    }
    if ((a_01->neg != 0) && (a_01->neg = 0, a_00->neg != 0)) {
      uVar2 = -uVar2;
    }
    while (pBVar1 = a_00, uVar5 != 0) {
      iVar6 = 0;
      while (iVar3 = BN_is_bit_set(pBVar1,iVar6), iVar3 == 0) {
        iVar6 = iVar6 + 1;
      }
      iVar3 = BN_rshift(pBVar1,pBVar1,iVar6);
      if (iVar3 == 0) goto LAB_0011ef5c;
      uVar5 = a_01->top;
      if (iVar6 << 0x1f < 0) {
        uVar4 = uVar5;
        if (uVar5 != 0) {
          uVar4 = *a_01->d & 7;
        }
        uVar2 = *(int *)(&tab_8691 + uVar4 * 4) * uVar2;
      }
      if (pBVar1->neg == 0) {
        uVar4 = pBVar1->top;
        if (uVar4 != 0) {
          uVar4 = *pBVar1->d;
        }
      }
      else if (pBVar1->top == 0) {
        uVar4 = 0xffffffff;
      }
      else {
        uVar4 = ~*pBVar1->d;
      }
      if ((uVar5 != 0) && ((*a_01->d & 2 & uVar4) != 0)) {
        uVar2 = -uVar2;
      }
      iVar6 = BN_nnmod(a_01,a_01,pBVar1,ctx);
      if (iVar6 == 0) goto LAB_0011ef5c;
      uVar5 = a_01->top;
      pBVar1->neg = 0;
      a_00 = a_01;
      a_01 = pBVar1;
    }
    if ((a_01->top == 1) && (*a_01->d == 1)) {
      if (a_01->neg != 0) {
        uVar2 = 0;
      }
      goto LAB_0011ef9a;
    }
  }
  uVar2 = 0;
LAB_0011ef9a:
  BN_CTX_end(ctx);
  return uVar2;
}

