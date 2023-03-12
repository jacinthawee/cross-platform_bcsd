
int RSA_blinding_on(RSA *rsa,BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *pBVar3;
  CRYPTO_THREADID *id;
  BN_CTX *ctx_00;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *b;
  BIGNUM *pBVar4;
  BIGNUM *a;
  undefined4 in_stack_ffffffb0;
  undefined4 in_stack_ffffffb4;
  BIGNUM local_3c;
  
  if (rsa->blinding != (BN_BLINDING *)0x0) {
    BN_BLINDING_free(rsa->blinding);
    rsa->blinding = (BN_BLINDING *)0x0;
    rsa->flags = rsa->flags & 0xfffffff7U | 0x80;
  }
  ctx_00 = ctx;
  if ((ctx == (BN_CTX *)0x0) && (ctx_00 = BN_CTX_new(), ctx_00 == (BN_CTX *)0x0)) {
    rsa->blinding = (BN_BLINDING *)0x0;
    return 0;
  }
  BN_CTX_start(ctx_00);
  pBVar1 = BN_CTX_get(ctx_00);
  if (pBVar1 == (BIGNUM *)0x0) {
    ERR_put_error(4,0x88,0x41,"rsa_crpt.c",0xcc);
    pBVar3 = pBVar1;
    goto LAB_000970d0;
  }
  pBVar1 = rsa->e;
  pBVar4 = pBVar1;
  if (pBVar1 != (BIGNUM *)0x0) {
LAB_00097082:
    iVar2 = RAND_status();
    if (((iVar2 == 0) && (pBVar1 = rsa->d, pBVar1 != (BIGNUM *)0x0)) && (pBVar1->d != (ulong *)0x0))
    {
      RAND_add(pBVar1->d,pBVar1->dmax << 2,(double)CONCAT44(in_stack_ffffffb4,in_stack_ffffffb0));
    }
    if (rsa->flags << 0x17 < 0) {
      pBVar1 = rsa->n;
    }
    else {
      pBVar3 = rsa->n;
      pBVar1 = &local_3c;
      local_3c.d = pBVar3->d;
      local_3c.top = pBVar3->top;
      local_3c.dmax = pBVar3->dmax;
      local_3c.neg = pBVar3->neg;
      local_3c.flags = local_3c.flags & 1U | pBVar3->flags & 0xfffffffeU | 6;
    }
    pBVar3 = (BIGNUM *)
             BN_BLINDING_create_param
                       ((BN_BLINDING *)0x0,pBVar4,pBVar1,ctx_00,(bn_mod_exp *)rsa->meth->bn_mod_exp,
                        rsa->_method_mod_n);
    pBVar1 = pBVar4;
    if (pBVar3 == (BIGNUM *)0x0) {
      ERR_put_error(4,0x88,3,"rsa_crpt.c",0xeb);
    }
    else {
      id = BN_BLINDING_thread_id((BN_BLINDING *)pBVar3);
      CRYPTO_THREADID_current(id);
    }
    goto LAB_000970d0;
  }
  a = rsa->d;
  pBVar3 = rsa->p;
  pBVar4 = rsa->q;
  if ((pBVar3 != (BIGNUM *)0x0 && a != (BIGNUM *)0x0) && (pBVar4 != (BIGNUM *)0x0)) {
    BN_CTX_start(ctx_00);
    r = BN_CTX_get(ctx_00);
    r_00 = BN_CTX_get(ctx_00);
    r_01 = BN_CTX_get(ctx_00);
    if (r_01 != (BIGNUM *)0x0) {
      b = BN_value_one();
      iVar2 = BN_sub(r_00,pBVar3,b);
      if (iVar2 != 0) {
        pBVar3 = BN_value_one();
        iVar2 = BN_sub(r_01,pBVar4,pBVar3);
        if ((iVar2 != 0) && (iVar2 = BN_mul(r,r_00,r_01,ctx_00), iVar2 != 0)) {
          pBVar4 = BN_mod_inverse((BIGNUM *)0x0,a,r,ctx_00);
          BN_CTX_end(ctx_00);
          if (pBVar4 != (BIGNUM *)0x0) goto LAB_00097082;
          goto LAB_00097196;
        }
      }
    }
    BN_CTX_end(ctx_00);
  }
LAB_00097196:
  ERR_put_error(4,0x88,0x8c,"rsa_crpt.c",0xd3);
  pBVar3 = (BIGNUM *)0x0;
LAB_000970d0:
  BN_CTX_end(ctx_00);
  if (ctx == (BN_CTX *)0x0) {
    BN_CTX_free(ctx_00);
  }
  if (rsa->e == (BIGNUM *)0x0) {
    BN_free(pBVar1);
  }
  rsa->blinding = (BN_BLINDING *)pBVar3;
  if (pBVar3 != (BIGNUM *)0x0) {
    pBVar3 = (BIGNUM *)0x1;
    rsa->flags = rsa->flags & 0xffffff7fU | 8;
  }
  return (int)pBVar3;
}

