
int BN_div_recp(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BN_RECP_CTX *recp,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  BIGNUM *r;
  int iVar2;
  int iVar3;
  BIGNUM *a;
  int iVar4;
  undefined *puVar5;
  BIGNUM *rem_00;
  
  BN_CTX_start(ctx);
  pBVar1 = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  if (dv == (BIGNUM *)0x0) {
    dv = BN_CTX_get(ctx);
  }
  if (rem == (BIGNUM *)0x0) {
    rem = BN_CTX_get(ctx);
  }
  if ((r != (BIGNUM *)0x0 && pBVar1 != (BIGNUM *)0x0) &&
     (rem_00 = (BIGNUM *)(uint)(rem == (BIGNUM *)0x0 || dv == (BIGNUM *)0x0),
     rem != (BIGNUM *)0x0 && dv != (BIGNUM *)0x0)) {
    iVar2 = BN_ucmp(m,&recp->N);
    if (iVar2 < 0) {
      BN_set_word(dv,(ulong)rem_00);
      pBVar1 = BN_copy(rem,m);
      if (pBVar1 != (BIGNUM *)0x0) {
        BN_CTX_end(ctx);
        return 1;
      }
      BN_CTX_end(ctx);
      return 0;
    }
    iVar3 = BN_num_bits(m);
    iVar4 = recp->shift;
    iVar2 = recp->num_bits * 2;
    if (iVar2 < iVar3) {
      iVar2 = iVar3;
    }
    if (iVar4 != iVar2) {
      BN_CTX_start(ctx);
      a = BN_CTX_get(ctx);
      if (((a == (BIGNUM *)0x0) || (iVar4 = BN_set_bit(a,iVar2), iVar4 == 0)) ||
         (iVar3 = BN_div(&recp->Nr,rem_00,a,&recp->N,ctx), iVar4 = iVar2, iVar3 == 0)) {
        iVar4 = -1;
      }
      BN_CTX_end(ctx);
      recp->shift = iVar4;
    }
    if (((iVar4 != -1) && (iVar4 = BN_rshift(pBVar1,m,recp->num_bits), iVar4 != 0)) &&
       ((iVar4 = BN_mul(r,pBVar1,&recp->Nr,ctx), iVar4 != 0 &&
        (iVar2 = BN_rshift(dv,r,iVar2 - recp->num_bits), iVar2 != 0)))) {
      dv->neg = 0;
      iVar2 = BN_mul(r,&recp->N,dv,ctx);
      if ((iVar2 != 0) && (iVar2 = BN_usub(rem,m,r), iVar2 != 0)) {
        rem->neg = 0;
        puVar5 = &DAT_00000004;
        do {
          iVar2 = BN_ucmp(rem,&recp->N);
          if (iVar2 < 0) {
            iVar2 = rem->top;
            if (iVar2 != 0) {
              iVar2 = m->neg;
            }
            rem->neg = iVar2;
            puVar5 = (undefined *)0x1;
            dv->neg = m->neg ^ (recp->N).neg;
            goto LAB_0008df88;
          }
          puVar5 = puVar5 + -1;
          if (puVar5 == (undefined *)0x0) {
            ERR_put_error(3,0x82,0x65,"bn_recp.c",0xce);
            goto LAB_0008df88;
          }
          iVar2 = BN_usub(rem,rem,&recp->N);
        } while ((iVar2 != 0) && (iVar2 = BN_add_word(dv,1), iVar2 != 0));
      }
    }
  }
  puVar5 = (undefined *)0x0;
LAB_0008df88:
  BN_CTX_end(ctx);
  return (int)puVar5;
}

