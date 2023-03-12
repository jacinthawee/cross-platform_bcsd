
int BN_sqr(BIGNUM *r,BIGNUM *a,BN_CTX *ctx)

{
  BIGNUM *a_00;
  int iVar1;
  BIGNUM *a_01;
  BIGNUM *pBVar2;
  ulong *puVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  undefined auStack_a0 [128];
  
  uVar6 = a->top;
  if ((int)uVar6 < 1) {
    r->top = 0;
    r->neg = 0;
    return 1;
  }
  BN_CTX_start(ctx);
  a_01 = r;
  if (a == r) {
    a_01 = BN_CTX_get(ctx);
  }
  a_00 = BN_CTX_get(ctx);
  if ((a_01 == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0) ||
     ((iVar5 = uVar6 * 2, a_01->dmax < iVar5 &&
      (pBVar2 = bn_expand2(a_01,iVar5), pBVar2 == (BIGNUM *)0x0)))) goto LAB_0008ca9a;
  if (uVar6 == 4) {
    bn_sqr_comba4(a_01->d,a->d);
  }
  else if (uVar6 == 8) {
    bn_sqr_comba8(a_01->d,a->d);
  }
  else if ((int)uVar6 < 0x10) {
    bn_sqr_normal(a_01->d,a->d,uVar6,auStack_a0);
  }
  else {
    iVar1 = BN_num_bits_word(uVar6);
    iVar4 = a_00->dmax;
    if (uVar6 == 1 << (iVar1 - 1U & 0xff)) {
      iVar1 = uVar6 * 4;
      if ((iVar1 - iVar4 != 0 && iVar4 <= iVar1) &&
         (pBVar2 = bn_expand2(a_00,iVar1), pBVar2 == (BIGNUM *)0x0)) goto LAB_0008ca9a;
      bn_sqr_recursive(a_01->d,a->d,uVar6,a_00->d);
    }
    else {
      if ((iVar4 < iVar5) && (pBVar2 = bn_expand2(a_00,iVar5), pBVar2 == (BIGNUM *)0x0)) {
LAB_0008ca9a:
        iVar5 = 0;
        goto LAB_0008ca9c;
      }
      bn_sqr_normal(a_01->d,a->d,uVar6,a_00->d);
    }
  }
  puVar3 = a->d;
  a_01->neg = 0;
  if (puVar3[uVar6 + 0x3fffffff] == (puVar3[uVar6 + 0x3fffffff] & 0xffff)) {
    iVar5 = iVar5 + -1;
  }
  a_01->top = iVar5;
  if (a_01 == r) {
    iVar5 = 1;
  }
  else {
    BN_copy(r,a_01);
    iVar5 = 1;
  }
LAB_0008ca9c:
  BN_CTX_end(ctx);
  return iVar5;
}

