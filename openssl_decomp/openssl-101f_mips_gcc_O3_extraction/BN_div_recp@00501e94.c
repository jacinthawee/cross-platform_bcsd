
int BN_div_recp(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BN_RECP_CTX *recp,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  BIGNUM *r;
  int iVar2;
  int iVar3;
  BIGNUM *a;
  int iVar4;
  
  BN_CTX_start(ctx);
  pBVar1 = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  if (dv == (BIGNUM *)0x0) {
    dv = BN_CTX_get(ctx);
  }
  if (rem == (BIGNUM *)0x0) {
    rem = BN_CTX_get(ctx);
  }
  if ((((pBVar1 != (BIGNUM *)0x0) && (r != (BIGNUM *)0x0)) && (dv != (BIGNUM *)0x0)) &&
     (rem != (BIGNUM *)0x0)) {
    iVar2 = BN_ucmp(m,&recp->N);
    if (iVar2 < 0) {
      BN_set_word(dv,0);
      pBVar1 = BN_copy(rem,m);
      if (pBVar1 != (BIGNUM *)0x0) {
        BN_CTX_end(ctx);
        return 1;
      }
      return 0;
    }
    iVar3 = BN_num_bits(m);
    iVar2 = recp->num_bits << 1;
    if (iVar2 <= iVar3) {
      iVar2 = iVar3;
    }
    iVar3 = iVar2;
    if (recp->shift != iVar2) {
      BN_CTX_start(ctx);
      a = BN_CTX_get(ctx);
      if (((a == (BIGNUM *)0x0) || (iVar4 = BN_set_bit(a,iVar2), iVar4 == 0)) ||
         (iVar4 = (*(code *)PTR_BN_div_006a967c)(&recp->Nr,0,a,recp,ctx), iVar4 == 0)) {
        iVar3 = -1;
      }
      BN_CTX_end(ctx);
      recp->shift = iVar3;
    }
    if (((iVar3 != -1) && (iVar3 = BN_rshift(pBVar1,m,recp->num_bits), iVar3 != 0)) &&
       ((iVar3 = BN_mul(r,pBVar1,&recp->Nr,ctx), iVar3 != 0 &&
        (iVar2 = BN_rshift(dv,r,iVar2 - recp->num_bits), iVar2 != 0)))) {
      dv->neg = 0;
      iVar2 = BN_mul(r,&recp->N,dv,ctx);
      if ((iVar2 != 0) && (iVar2 = (*(code *)PTR_BN_usub_006a96d4)(rem,m,r), iVar2 != 0)) {
        iVar2 = 4;
        rem->neg = 0;
        do {
          iVar2 = iVar2 + -1;
          iVar3 = BN_ucmp(rem,&recp->N);
          if (iVar3 < 0) {
            iVar2 = 0;
            if (rem->top != 0) {
              iVar2 = m->neg;
            }
            rem->neg = iVar2;
            iVar2 = 1;
            dv->neg = m->neg ^ (recp->N).neg;
            goto LAB_0050204c;
          }
          if (iVar2 == 0) {
            (*(code *)PTR_ERR_put_error_006a9030)(3,0x82,0x65,"bn_recp.c",0xc2);
            goto LAB_00502048;
          }
          iVar3 = (*(code *)PTR_BN_usub_006a96d4)(rem,rem,recp);
          if (iVar3 == 0) goto LAB_00502048;
          iVar3 = BN_add_word(dv,1);
        } while (iVar3 != 0);
        iVar2 = 0;
        goto LAB_0050204c;
      }
    }
  }
LAB_00502048:
  iVar2 = 0;
LAB_0050204c:
  BN_CTX_end(ctx);
  return iVar2;
}

