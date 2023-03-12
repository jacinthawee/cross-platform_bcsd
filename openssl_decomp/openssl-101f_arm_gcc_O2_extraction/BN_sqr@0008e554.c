
int BN_sqr(BIGNUM *r,BIGNUM *a,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  BIGNUM *a_00;
  int iVar2;
  BIGNUM *pBVar3;
  int in_r3;
  ulong *puVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  undefined auStack_a0 [128];
  
  uVar6 = a->top;
  pBVar1 = r;
  if ((int)uVar6 < 1) {
    in_r3 = 0;
    pBVar1 = (BIGNUM *)0x1;
  }
  if ((int)uVar6 < 1) {
    r->top = in_r3;
    return (int)pBVar1;
  }
  BN_CTX_start(ctx);
  pBVar1 = r;
  if (a == r) {
    pBVar1 = BN_CTX_get(ctx);
  }
  a_00 = BN_CTX_get(ctx);
  if ((pBVar1 == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0) ||
     ((iVar7 = uVar6 * 2, pBVar1->dmax < iVar7 &&
      (pBVar3 = bn_expand2(pBVar1,iVar7), pBVar3 == (BIGNUM *)0x0)))) goto LAB_0008e58e;
  if (uVar6 == 4) {
    bn_sqr_comba4(pBVar1->d,a->d);
  }
  else if (uVar6 == 8) {
    bn_sqr_comba8(pBVar1->d,a->d);
  }
  else {
    if (0xf < (int)uVar6) {
      iVar2 = BN_num_bits_word(uVar6);
      iVar5 = a_00->dmax;
      if (uVar6 == 1 << (iVar2 - 1U & 0xff)) {
        iVar2 = uVar6 * 4;
        if ((iVar2 - iVar5 == 0 || iVar2 < iVar5) ||
           (pBVar3 = bn_expand2(a_00,iVar2), pBVar3 != (BIGNUM *)0x0)) {
          bn_sqr_recursive(pBVar1->d,a->d,uVar6,a_00->d);
          goto LAB_0008e5c4;
        }
      }
      else if ((iVar7 <= iVar5) || (pBVar3 = bn_expand2(a_00,iVar7), pBVar3 != (BIGNUM *)0x0)) {
        bn_sqr_normal(pBVar1->d,a->d,uVar6,a_00->d);
        goto LAB_0008e5c4;
      }
LAB_0008e58e:
      iVar7 = 0;
      goto LAB_0008e590;
    }
    bn_sqr_normal(pBVar1->d,a->d,uVar6,auStack_a0);
  }
LAB_0008e5c4:
  puVar4 = a->d;
  pBVar1->neg = 0;
  if (puVar4[uVar6 + 0x3fffffff] == (puVar4[uVar6 + 0x3fffffff] & 0xffff)) {
    iVar7 = iVar7 + -1;
  }
  pBVar1->top = iVar7;
  if (pBVar1 == r) {
    iVar7 = 1;
  }
  else {
    BN_copy(r,pBVar1);
    iVar7 = 1;
  }
LAB_0008e590:
  BN_CTX_end(ctx);
  return iVar7;
}

