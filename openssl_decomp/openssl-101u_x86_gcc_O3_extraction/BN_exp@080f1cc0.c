
int BN_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *a_01;
  int iVar3;
  int n;
  
  if ((*(byte *)&p->flags & 4) != 0) {
    ERR_put_error(3,0x7b,0x42,"bn_exp.c",0x8b);
    return -1;
  }
  BN_CTX_start(ctx);
  if ((r == a) || (a_01 = r, p == r)) {
    a_01 = BN_CTX_get(ctx);
  }
  a_00 = BN_CTX_get(ctx);
  if (((a_01 != (BIGNUM *)0x0) && (a_00 != (BIGNUM *)0x0)) &&
     (pBVar1 = BN_copy(a_00,a), pBVar1 != (BIGNUM *)0x0)) {
    iVar3 = BN_num_bits(p);
    if ((p->top < 1) || ((*(byte *)p->d & 1) == 0)) {
      pBVar1 = (BIGNUM *)BN_set_word(a_01,1);
    }
    else {
      pBVar1 = BN_copy(a_01,a);
    }
    if (pBVar1 != (BIGNUM *)0x0) {
      n = 1;
      if (1 < iVar3) {
        do {
          iVar2 = BN_sqr(a_00,a_00,ctx);
          if ((iVar2 == 0) ||
             ((iVar2 = BN_is_bit_set(p,n), iVar2 != 0 &&
              (iVar2 = BN_mul(a_01,a_01,a_00,ctx), iVar2 == 0)))) goto LAB_080f1d17;
          n = n + 1;
        } while (iVar3 != n);
      }
      if (a_01 != r) {
        BN_copy(r,a_01);
      }
      iVar3 = 1;
      goto LAB_080f1d19;
    }
  }
LAB_080f1d17:
  iVar3 = 0;
LAB_080f1d19:
  BN_CTX_end(ctx);
  return iVar3;
}

