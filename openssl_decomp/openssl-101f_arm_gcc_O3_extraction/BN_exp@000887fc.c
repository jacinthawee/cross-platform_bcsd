
int BN_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (p->flags << 0x1d < 0) {
    ERR_put_error(3,0x7b,0x42,"bn_exp.c",0x8c);
    return -1;
  }
  BN_CTX_start(ctx);
  a_01 = r;
  if (r == a || r == p) {
    a_01 = BN_CTX_get(ctx);
  }
  a_00 = BN_CTX_get(ctx);
  if ((a_01 != (BIGNUM *)0x0 && a_00 != (BIGNUM *)0x0) &&
     (pBVar1 = BN_copy(a_00,a), pBVar1 != (BIGNUM *)0x0)) {
    iVar4 = BN_num_bits(p);
    if ((p->top < 1) || (-1 < (int)(*p->d << 0x1f))) {
      pBVar1 = (BIGNUM *)BN_set_word(a_01,1);
    }
    else {
      pBVar1 = BN_copy(a_01,a);
    }
    if (pBVar1 != (BIGNUM *)0x0) {
      if (1 < iVar4) {
        iVar3 = 1;
        do {
          iVar2 = BN_sqr(a_00,a_00,ctx);
          iVar5 = iVar3 + 1;
          if ((iVar2 == 0) ||
             ((iVar3 = BN_is_bit_set(p,iVar3), iVar3 != 0 &&
              (iVar3 = BN_mul(a_01,a_01,a_00,ctx), iVar3 == 0)))) goto LAB_00088834;
          iVar3 = iVar5;
        } while (iVar5 != iVar4);
      }
      iVar4 = 1;
      goto LAB_00088836;
    }
  }
LAB_00088834:
  iVar4 = 0;
LAB_00088836:
  if (r != a_01) {
    BN_copy(r,a_01);
  }
  BN_CTX_end(ctx);
  return iVar4;
}

