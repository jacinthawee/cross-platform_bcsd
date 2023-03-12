
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
LAB_00501c98:
    iVar2 = 0;
    goto LAB_00501c9c;
  }
  if (y != (BIGNUM *)0x0) {
    if (y == x) {
      iVar2 = BN_sqr(pBVar1,y,ctx);
    }
    else {
      iVar2 = BN_mul(pBVar1,x,y,ctx);
    }
    x = pBVar1;
    if (iVar2 == 0) goto LAB_00501c98;
  }
  BN_CTX_start(ctx);
  pBVar1 = BN_CTX_get(ctx);
  r_00 = BN_CTX_get(ctx);
  a = BN_CTX_get(ctx);
  if (r == (BIGNUM *)0x0) {
    r = BN_CTX_get(ctx);
  }
  if ((((pBVar1 == (BIGNUM *)0x0) || (r_00 == (BIGNUM *)0x0)) || (a == (BIGNUM *)0x0)) ||
     (r == (BIGNUM *)0x0)) goto LAB_00501c64;
  iVar2 = BN_ucmp(x,&recp->N);
  if (iVar2 < 0) {
    BN_set_word(a,0);
    pBVar1 = BN_copy(r,x);
    if (pBVar1 != (BIGNUM *)0x0) {
      iVar2 = 1;
      BN_CTX_end(ctx);
      goto LAB_00501c9c;
    }
    goto LAB_00501c98;
  }
  iVar3 = BN_num_bits(x);
  iVar2 = recp->num_bits << 1;
  if (iVar2 <= iVar3) {
    iVar2 = iVar3;
  }
  iVar3 = iVar2;
  if (recp->shift != iVar2) {
    BN_CTX_start(ctx);
    a_00 = BN_CTX_get(ctx);
    if (((a_00 == (BIGNUM *)0x0) || (iVar4 = BN_set_bit(a_00,iVar2), iVar4 == 0)) ||
       (iVar4 = (*(code *)PTR_BN_div_006a967c)(&recp->Nr,0,a_00,recp,ctx), iVar4 == 0)) {
      iVar3 = -1;
    }
    BN_CTX_end(ctx);
    recp->shift = iVar3;
  }
  if (((iVar3 == -1) || (iVar3 = BN_rshift(pBVar1,x,recp->num_bits), iVar3 == 0)) ||
     ((iVar3 = BN_mul(r_00,pBVar1,&recp->Nr,ctx), iVar3 == 0 ||
      (iVar2 = BN_rshift(a,r_00,iVar2 - recp->num_bits), iVar2 == 0)))) {
LAB_00501c64:
    iVar2 = 0;
  }
  else {
    a->neg = 0;
    iVar2 = BN_mul(r_00,&recp->N,a,ctx);
    if ((iVar2 == 0) || (iVar2 = (*(code *)PTR_BN_usub_006a96d4)(r,x,r_00), iVar2 == 0))
    goto LAB_00501c64;
    iVar2 = 4;
    r->neg = 0;
    do {
      iVar2 = iVar2 + -1;
      iVar3 = BN_ucmp(r,&recp->N);
      if (iVar3 < 0) {
        iVar2 = r->top;
        if (iVar2 != 0) {
          iVar2 = x->neg;
        }
        r->neg = iVar2;
        iVar2 = 1;
        a->neg = x->neg ^ (recp->N).neg;
        goto LAB_00501c68;
      }
      if (iVar2 == 0) {
        (*(code *)PTR_ERR_put_error_006a9030)(3,0x82,0x65,"bn_recp.c",0xc2);
        goto LAB_00501c68;
      }
      iVar3 = (*(code *)PTR_BN_usub_006a96d4)(r,r,recp);
      if (iVar3 == 0) goto LAB_00501c64;
      iVar3 = BN_add_word(a,1);
    } while (iVar3 != 0);
    iVar2 = 0;
  }
LAB_00501c68:
  BN_CTX_end(ctx);
LAB_00501c9c:
  BN_CTX_end(ctx);
  return iVar2;
}

