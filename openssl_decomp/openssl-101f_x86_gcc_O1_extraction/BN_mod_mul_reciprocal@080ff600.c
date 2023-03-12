
int BN_mod_mul_reciprocal(BIGNUM *r,BIGNUM *x,BIGNUM *y,BN_RECP_CTX *recp,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *r_00;
  BIGNUM *a;
  int iVar3;
  BIGNUM *a_00;
  int iVar4;
  
  BN_CTX_start(ctx);
  pBVar1 = BN_CTX_get(ctx);
  if (pBVar1 == (BIGNUM *)0x0) {
LAB_080ff6e0:
    iVar2 = 0;
  }
  else {
    if (y != (BIGNUM *)0x0) {
      if (y == x) {
        iVar2 = BN_sqr(pBVar1,y,ctx);
      }
      else {
        iVar2 = BN_mul(pBVar1,x,y,ctx);
      }
      x = pBVar1;
      if (iVar2 == 0) goto LAB_080ff6e0;
    }
    BN_CTX_start(ctx);
    pBVar1 = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    a = BN_CTX_get(ctx);
    if (r == (BIGNUM *)0x0) {
      r = BN_CTX_get(ctx);
    }
    if ((((pBVar1 != (BIGNUM *)0x0) && (r_00 != (BIGNUM *)0x0)) && (a != (BIGNUM *)0x0)) &&
       (r != (BIGNUM *)0x0)) {
      iVar2 = BN_ucmp(x,&recp->N);
      if (iVar2 < 0) {
        BN_set_word(a,0);
        pBVar1 = BN_copy(r,x);
        if (pBVar1 != (BIGNUM *)0x0) {
          iVar2 = 1;
          BN_CTX_end(ctx);
          goto LAB_080ff6ad;
        }
        goto LAB_080ff6e0;
      }
      iVar3 = BN_num_bits(x);
      iVar2 = recp->num_bits * 2;
      if (SBORROW4(iVar3,iVar2) == iVar3 + recp->num_bits * -2 < 0) {
        iVar2 = iVar3;
      }
      iVar3 = iVar2;
      if (recp->shift != iVar2) {
        BN_CTX_start(ctx);
        a_00 = BN_CTX_get(ctx);
        if (((a_00 == (BIGNUM *)0x0) || (iVar4 = BN_set_bit(a_00,iVar2), iVar4 == 0)) ||
           (iVar4 = BN_div(&recp->Nr,(BIGNUM *)0x0,a_00,&recp->N,ctx), iVar4 == 0)) {
          iVar3 = -1;
        }
        BN_CTX_end(ctx);
        recp->shift = iVar3;
      }
      if (((iVar3 != -1) && (iVar3 = BN_rshift(pBVar1,x,recp->num_bits), iVar3 != 0)) &&
         ((iVar3 = BN_mul(r_00,pBVar1,&recp->Nr,ctx), iVar3 != 0 &&
          (iVar2 = BN_rshift(a,r_00,iVar2 - recp->num_bits), iVar2 != 0)))) {
        a->neg = 0;
        iVar2 = BN_mul(r_00,&recp->N,a,ctx);
        if ((iVar2 != 0) && (iVar2 = BN_usub(r,x,r_00), iVar2 != 0)) {
          iVar2 = 4;
          r->neg = 0;
          while( true ) {
            iVar3 = BN_ucmp(r,&recp->N);
            if (iVar3 < 0) {
              iVar2 = r->top;
              if (iVar2 != 0) {
                iVar2 = x->neg;
              }
              r->neg = iVar2;
              iVar2 = 1;
              a->neg = x->neg ^ (recp->N).neg;
              goto LAB_080ff6a1;
            }
            iVar2 = iVar2 + -1;
            if (iVar2 == 0) break;
            iVar3 = BN_usub(r,r,&recp->N);
            if ((iVar3 == 0) || (iVar3 = BN_add_word(a,1), iVar3 == 0)) goto LAB_080ff69f;
          }
          ERR_put_error(3,0x82,0x65,"bn_recp.c",0xc2);
        }
      }
    }
LAB_080ff69f:
    iVar2 = 0;
LAB_080ff6a1:
    BN_CTX_end(ctx);
  }
LAB_080ff6ad:
  BN_CTX_end(ctx);
  return iVar2;
}

