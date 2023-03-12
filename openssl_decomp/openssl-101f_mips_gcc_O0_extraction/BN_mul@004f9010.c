
int BN_mul(BIGNUM *r,BIGNUM *a,BIGNUM *b,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  ulong *puVar3;
  BIGNUM *a_00;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  ulong *puVar7;
  ulong uVar8;
  ulong uVar9;
  int iVar10;
  
  uVar8 = a->top;
  if ((uVar8 == 0) || (uVar9 = b->top, uVar9 == 0)) {
    BN_set_word(r,0);
    return 1;
  }
  iVar10 = uVar8 + uVar9;
  BN_CTX_start(ctx);
  if (((a == r) || (a_00 = r, b == r)) && (a_00 = BN_CTX_get(ctx), a_00 == (BIGNUM *)0x0)) {
    iVar10 = 0;
    goto LAB_004f9264;
  }
  iVar5 = uVar8 - uVar9;
  a_00->neg = a->neg ^ b->neg;
  if ((iVar5 == 0) && (uVar8 == 8)) {
    if ((a_00->dmax < 0x10) && (pBVar1 = bn_expand2(a_00,0x10), pBVar1 == (BIGNUM *)0x0))
    goto LAB_004f9260;
    puVar7 = b->d;
    puVar3 = a->d;
    a_00->top = 0x10;
    bn_mul_comba8(a_00->d,puVar3,puVar7);
    iVar10 = a_00->top;
  }
  else if (((int)uVar8 < 0x10) || (((int)uVar9 < 0x10 || (2 < iVar5 + 1U)))) {
    if ((a_00->dmax < iVar10) && (pBVar1 = bn_expand2(a_00,iVar10), pBVar1 == (BIGNUM *)0x0))
    goto LAB_004f9260;
    puVar7 = b->d;
    puVar3 = a->d;
    a_00->top = iVar10;
    bn_mul_normal(a_00->d,puVar3,uVar8,puVar7,uVar9);
    iVar10 = a_00->top;
  }
  else {
    if (iVar5 == -1) {
      iVar5 = BN_num_bits_word(uVar9);
    }
    else {
      iVar5 = BN_num_bits_word(uVar8);
    }
    iVar5 = 1 << (iVar5 - 1U & 0x1f);
    pBVar1 = BN_CTX_get(ctx);
    if (pBVar1 == (BIGNUM *)0x0) {
LAB_004f9260:
      iVar10 = 0;
      goto LAB_004f9264;
    }
    if ((iVar5 < (int)uVar8) || (iVar5 < (int)uVar9)) {
      iVar6 = iVar5 << 3;
      if (pBVar1->dmax < iVar6) {
        pBVar4 = bn_expand2(pBVar1,iVar6);
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_004f9260;
        iVar2 = a_00->dmax;
      }
      else {
        iVar2 = a_00->dmax;
      }
      if (iVar2 < iVar6) {
        pBVar4 = bn_expand2(a_00,iVar6);
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_004f9260;
        puVar3 = pBVar1->d;
      }
      else {
        puVar3 = pBVar1->d;
      }
      bn_mul_part_recursive(a_00->d,a->d,b->d,iVar5,uVar8 - iVar5,uVar9 - iVar5,puVar3);
      a_00->top = iVar10;
    }
    else {
      iVar6 = iVar5 << 2;
      if (pBVar1->dmax < iVar6) {
        pBVar4 = bn_expand2(pBVar1,iVar6);
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_004f9260;
        iVar2 = a_00->dmax;
      }
      else {
        iVar2 = a_00->dmax;
      }
      if (iVar2 < iVar6) {
        pBVar4 = bn_expand2(a_00,iVar6);
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_004f9260;
        puVar3 = pBVar1->d;
      }
      else {
        puVar3 = pBVar1->d;
      }
      bn_mul_recursive(a_00->d,a->d,b->d,iVar5,uVar8 - iVar5,uVar9 - iVar5,puVar3);
      a_00->top = iVar10;
    }
  }
  if (0 < iVar10) {
    puVar3 = a_00->d + iVar10 + -2;
    do {
      if (puVar3[1] != 0) break;
      iVar10 = iVar10 + -1;
      puVar3 = puVar3 + -1;
    } while (iVar10 != 0);
    a_00->top = iVar10;
  }
  if (a_00 == r) {
    iVar10 = 1;
  }
  else {
    iVar10 = 1;
    BN_copy(r,a_00);
  }
LAB_004f9264:
  BN_CTX_end(ctx);
  return iVar10;
}

