
int BN_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  BIGNUM *a_01;
  int n;
  
  if ((*(byte *)&p->flags & 4) != 0) {
    ERR_put_error(3,0x7b,0x42,"bn_exp.c",0x8c);
    return -1;
  }
  BN_CTX_start(ctx);
  if ((r == a) || (p == r)) {
    a_01 = BN_CTX_get(ctx);
    a_00 = BN_CTX_get(ctx);
    if ((a_01 != (BIGNUM *)0x0) &&
       ((a_00 != (BIGNUM *)0x0 && (pBVar1 = BN_copy(a_00,a), pBVar1 != (BIGNUM *)0x0))))
    goto LAB_080f3f2c;
LAB_080f3fd0:
    n = 0;
  }
  else {
    a_00 = BN_CTX_get(ctx);
    if ((a_00 == (BIGNUM *)0x0) ||
       ((r == (BIGNUM *)0x0 || (pBVar1 = BN_copy(a_00,a), a_01 = r, pBVar1 == (BIGNUM *)0x0)))) {
      n = 0;
      goto LAB_080f3ff2;
    }
LAB_080f3f2c:
    iVar2 = BN_num_bits(p);
    if ((p->top < 1) || ((*(byte *)p->d & 1) == 0)) {
      n = 0;
      iVar3 = BN_set_word(a_01,1);
      if (iVar3 != 0) goto LAB_080f3f69;
    }
    else {
      pBVar1 = BN_copy(a_01,a);
      if (pBVar1 == (BIGNUM *)0x0) goto LAB_080f3fd0;
LAB_080f3f69:
      n = 1;
      if (1 < iVar2) {
        do {
          iVar3 = BN_sqr(a_00,a_00,ctx);
          if ((iVar3 == 0) ||
             ((iVar3 = BN_is_bit_set(p,n), iVar3 != 0 &&
              (iVar3 = BN_mul(a_01,a_01,a_00,ctx), iVar3 == 0)))) goto LAB_080f3fd0;
          n = n + 1;
        } while (iVar2 != n);
        n = 1;
      }
    }
  }
  if (r != a_01) {
    BN_copy(r,a_01);
  }
LAB_080f3ff2:
  BN_CTX_end(ctx);
  return n;
}

