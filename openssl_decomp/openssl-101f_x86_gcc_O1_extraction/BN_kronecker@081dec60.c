
int BN_kronecker(BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *pBVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  uint n;
  bool bVar5;
  uint local_24;
  
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  a_01 = BN_CTX_get(ctx);
  if ((a_01 == (BIGNUM *)0x0) || (pBVar1 = BN_copy(a_00,a), pBVar1 == (BIGNUM *)0x0)) {
LAB_081ded00:
    BN_CTX_end(ctx);
    return -2;
  }
  pBVar1 = BN_copy(a_01,b);
  bVar5 = pBVar1 == (BIGNUM *)0x0;
  if (bVar5) {
LAB_081dee98:
    local_24 = 0xfffffffe;
  }
  else {
    if (a_01->top == 0) {
      local_24 = 0;
      if (a_00->top == 1) {
        local_24 = (uint)(*a_00->d == 1);
      }
      goto LAB_081decd6;
    }
    if (((0 < a_00->top) && ((*(byte *)a_00->d & 1) != 0)) ||
       ((0 < a_01->top && ((*(byte *)a_01->d & 1) != 0)))) {
      uVar4 = 0;
      while (iVar2 = BN_is_bit_set(a_01,uVar4), iVar2 == 0) {
        uVar4 = uVar4 + 1;
      }
      iVar2 = BN_rshift(a_01,a_01,uVar4);
      bVar5 = iVar2 == 0;
      if (bVar5) goto LAB_081dee98;
      iVar2 = a_00->top;
      if ((uVar4 & 1) == 0) {
        local_24 = 1;
      }
      else {
        local_24 = 0;
        if (iVar2 != 0) {
          local_24 = *(uint *)(tab_6037 + (*a_00->d & 7) * 4);
        }
      }
      uVar4 = local_24;
      if (a_01->neg != 0) {
        a_01->neg = 0;
        uVar4 = -local_24;
        if (a_00->neg == 0) {
          uVar4 = local_24;
        }
      }
      while (pBVar1 = a_00, iVar2 != 0) {
        n = 0;
        while (iVar2 = BN_is_bit_set(pBVar1,n), iVar2 == 0) {
          n = n + 1;
        }
        iVar2 = BN_rshift(pBVar1,pBVar1,n);
        if (iVar2 == 0) goto LAB_081ded00;
        local_24 = uVar4;
        if ((n & 1) != 0) {
          if (a_01->top == 0) {
            local_24 = 0;
          }
          else {
            local_24 = uVar4 * *(int *)(tab_6037 + (*a_01->d & 7) * 4);
          }
        }
        if (pBVar1->neg == 0) {
          if (pBVar1->top != 0) {
            uVar3 = *pBVar1->d;
            goto LAB_081dee2e;
          }
        }
        else {
          uVar3 = 0xffffffff;
          if (pBVar1->top != 0) {
            uVar3 = ~*pBVar1->d;
          }
LAB_081dee2e:
          if ((a_01->top != 0) && ((uVar3 & *a_01->d & 2) != 0)) {
            local_24 = -local_24;
          }
        }
        iVar2 = BN_nnmod(a_01,a_01,pBVar1,ctx);
        bVar5 = iVar2 == 0;
        if (bVar5) goto LAB_081decd6;
        iVar2 = a_01->top;
        pBVar1->neg = 0;
        a_00 = a_01;
        a_01 = pBVar1;
        uVar4 = local_24;
      }
      if ((a_01->top == 1) && (*a_01->d == 1)) {
        local_24 = 0;
        if (a_01->neg == 0) {
          local_24 = uVar4;
        }
        goto LAB_081decd6;
      }
    }
    local_24 = 0;
  }
LAB_081decd6:
  BN_CTX_end(ctx);
  uVar4 = 0xfffffffe;
  if (!bVar5) {
    uVar4 = local_24;
  }
  return uVar4;
}

