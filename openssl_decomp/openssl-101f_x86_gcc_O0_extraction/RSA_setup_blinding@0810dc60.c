
BN_BLINDING * RSA_setup_blinding(RSA *rsa,BN_CTX *ctx)

{
  BIGNUM *a;
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BN_BLINDING *pBVar4;
  CRYPTO_THREADID *id;
  BN_CTX *ctx_00;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *b;
  BIGNUM *pBVar5;
  int in_GS_OFFSET;
  int line;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  ctx_00 = ctx;
  if ((ctx == (BN_CTX *)0x0) && (ctx_00 = BN_CTX_new(), ctx_00 == (BN_CTX *)0x0)) {
    pBVar4 = (BN_BLINDING *)0x0;
    goto LAB_0810dd42;
  }
  BN_CTX_start(ctx_00);
  pBVar1 = BN_CTX_get(ctx_00);
  if (pBVar1 == (BIGNUM *)0x0) {
    line = 0xd0;
    iVar2 = 0x41;
LAB_0810de50:
    pBVar4 = (BN_BLINDING *)0x0;
    ERR_put_error(4,0x88,iVar2,"rsa_crpt.c",line);
  }
  else {
    pBVar3 = rsa->e;
    pBVar1 = pBVar3;
    if (pBVar3 == (BIGNUM *)0x0) {
      pBVar1 = rsa->q;
      pBVar5 = rsa->p;
      a = rsa->d;
      if ((a != (BIGNUM *)0x0 && pBVar5 != (BIGNUM *)0x0) && (pBVar1 != (BIGNUM *)0x0)) {
        BN_CTX_start(ctx_00);
        r = BN_CTX_get(ctx_00);
        r_00 = BN_CTX_get(ctx_00);
        r_01 = BN_CTX_get(ctx_00);
        if (r_01 != (BIGNUM *)0x0) {
          b = BN_value_one();
          iVar2 = BN_sub(r_00,pBVar5,b);
          if (iVar2 != 0) {
            pBVar5 = BN_value_one();
            iVar2 = BN_sub(r_01,pBVar1,pBVar5);
            if ((iVar2 != 0) && (iVar2 = BN_mul(r,r_00,r_01,ctx_00), iVar2 != 0)) {
              pBVar1 = BN_mod_inverse((BIGNUM *)0x0,a,r,ctx_00);
              BN_CTX_end(ctx_00);
              if (pBVar1 != (BIGNUM *)0x0) goto LAB_0810dcb3;
              goto LAB_0810de3b;
            }
          }
        }
        BN_CTX_end(ctx_00);
      }
LAB_0810de3b:
      line = 0xd9;
      iVar2 = 0x8c;
      pBVar1 = pBVar3;
      goto LAB_0810de50;
    }
LAB_0810dcb3:
    iVar2 = RAND_status();
    if (((iVar2 == 0) && (pBVar3 = rsa->d, pBVar3 != (BIGNUM *)0x0)) && (pBVar3->d != (ulong *)0x0))
    {
      RAND_add(pBVar3->d,pBVar3->dmax << 2,0.0);
    }
    pBVar3 = rsa->n;
    if ((*(byte *)((int)&rsa->flags + 1) & 1) == 0) {
      local_34.d = pBVar3->d;
      local_34.top = pBVar3->top;
      local_34.dmax = pBVar3->dmax;
      local_34.neg = pBVar3->neg;
      local_34.flags = pBVar3->flags & 0xfffffffeU | local_34.flags & 1U | 6;
      pBVar3 = &local_34;
    }
    pBVar4 = BN_BLINDING_create_param
                       ((BN_BLINDING *)0x0,pBVar1,pBVar3,ctx_00,(bn_mod_exp *)rsa->meth->bn_mod_exp,
                        rsa->_method_mod_n);
    if (pBVar4 == (BN_BLINDING *)0x0) {
      ERR_put_error(4,0x88,3,"rsa_crpt.c",0xf5);
    }
    else {
      id = BN_BLINDING_thread_id(pBVar4);
      CRYPTO_THREADID_current(id);
    }
  }
  BN_CTX_end(ctx_00);
  if (ctx == (BN_CTX *)0x0) {
    BN_CTX_free(ctx_00);
  }
  if (rsa->e == (BIGNUM *)0x0) {
    BN_free(pBVar1);
  }
LAB_0810dd42:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pBVar4;
}

