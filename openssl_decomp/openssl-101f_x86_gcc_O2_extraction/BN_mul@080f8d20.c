
int BN_mul(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  ulong uVar1;
  ulong uVar2;
  char cVar3;
  int iVar4;
  BIGNUM *pBVar5;
  int iVar6;
  BIGNUM *a_00;
  int iVar7;
  BIGNUM *pBVar8;
  
  uVar1 = a->top;
  uVar2 = b->top;
  if ((uVar1 == 0) || (uVar2 == 0)) {
    BN_set_word(r,0);
    return 1;
  }
  iVar6 = uVar1 + uVar2;
  BN_CTX_start(ctx);
  if (((a == r) || (a_00 = r, b == r)) && (a_00 = BN_CTX_get(ctx), a_00 == (BIGNUM *)0x0))
  goto LAB_080f8f49;
  a_00->neg = a->neg ^ b->neg;
  iVar4 = uVar1 - uVar2;
  if ((iVar4 == 0) && (uVar1 == 8)) {
    if ((a_00->dmax < 0x10) && (pBVar5 = bn_expand2(a_00,0x10), pBVar5 == (BIGNUM *)0x0)) {
      iVar6 = 0;
      goto LAB_080f8eba;
    }
    a_00->top = 0x10;
    bn_mul_comba8(a_00->d,a->d,b->d);
    iVar6 = a_00->top;
  }
  else if (((int)uVar1 < 0x10) || (((int)uVar2 < 0x10 || (2 < iVar4 + 1U)))) {
    if ((a_00->dmax < (int)(uVar1 + uVar2)) &&
       (pBVar5 = bn_expand2(a_00,iVar6), pBVar5 == (BIGNUM *)0x0)) {
      iVar6 = 0;
      goto LAB_080f8eba;
    }
    a_00->top = uVar1 + uVar2;
    bn_mul_normal(a_00->d,a->d,uVar1,b->d,uVar2);
    iVar6 = a_00->top;
  }
  else {
    if (iVar4 == -1) {
      iVar4 = BN_num_bits_word(uVar2);
      cVar3 = (char)iVar4;
    }
    else {
      iVar4 = BN_num_bits_word(uVar1);
      cVar3 = (char)iVar4;
    }
    iVar4 = 1 << (cVar3 - 1U & 0x1f);
    pBVar5 = BN_CTX_get(ctx);
    if (pBVar5 == (BIGNUM *)0x0) {
LAB_080f8f49:
      iVar6 = 0;
      goto LAB_080f8eba;
    }
    if ((iVar4 < (int)uVar1) || (iVar4 < (int)uVar2)) {
      iVar7 = iVar4 << 3;
      if ((pBVar5->dmax < iVar7) && (pBVar8 = bn_expand2(pBVar5,iVar7), pBVar8 == (BIGNUM *)0x0))
      goto LAB_080f8f49;
      if ((a_00->dmax < iVar7) && (pBVar8 = bn_expand2(a_00,iVar7), pBVar8 == (BIGNUM *)0x0)) {
        iVar6 = 0;
        goto LAB_080f8eba;
      }
      bn_mul_part_recursive(a_00->d,a->d,b->d,iVar4,uVar1 - iVar4,uVar2 - iVar4,pBVar5->d);
    }
    else {
      iVar7 = iVar4 * 4;
      if ((iVar7 - pBVar5->dmax != 0 && pBVar5->dmax <= iVar7) &&
         (pBVar8 = bn_expand2(pBVar5,iVar7), pBVar8 == (BIGNUM *)0x0)) goto LAB_080f8f49;
      if ((a_00->dmax < iVar7) && (pBVar8 = bn_expand2(a_00,iVar7), pBVar8 == (BIGNUM *)0x0)) {
        iVar6 = 0;
        goto LAB_080f8eba;
      }
      bn_mul_recursive(a_00->d,a->d,b->d,iVar4,uVar1 - iVar4,uVar2 - iVar4,pBVar5->d);
    }
    a_00->top = iVar6;
  }
  if (0 < iVar6) {
    do {
      if (a_00->d[iVar6 + -1] != 0) break;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    a_00->top = iVar6;
  }
  iVar6 = 1;
  if (a_00 != r) {
    BN_copy(r,a_00);
  }
LAB_080f8eba:
  BN_CTX_end(ctx);
  return iVar6;
}

