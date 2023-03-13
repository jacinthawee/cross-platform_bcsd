
int RSA_blinding_on(RSA *rsa,BN_CTX *ctx)

{
  BIGNUM *a;
  BIGNUM *pBVar1;
  int iVar2;
  BN_BLINDING *pBVar3;
  CRYPTO_THREADID *id;
  BN_CTX *ctx_00;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  BIGNUM *b;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  int in_GS_OFFSET;
  int line;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (rsa->blinding != (BN_BLINDING *)0x0) {
    BN_BLINDING_free(rsa->blinding);
    rsa->blinding = (BN_BLINDING *)0x0;
    rsa->flags = rsa->flags & 0xfffffff7U | 0x80;
  }
  ctx_00 = ctx;
  if ((ctx == (BN_CTX *)0x0) && (ctx_00 = BN_CTX_new(), ctx_00 == (BN_CTX *)0x0)) {
    rsa->blinding = (BN_BLINDING *)0x0;
    iVar2 = 0;
    goto LAB_0810c1f7;
  }
  BN_CTX_start(ctx_00);
  pBVar1 = BN_CTX_get(ctx_00);
  if (pBVar1 == (BIGNUM *)0x0) {
    line = 0xcc;
    iVar2 = 0x41;
LAB_0810c308:
    pBVar3 = (BN_BLINDING *)0x0;
    ERR_put_error(4,0x88,iVar2,"rsa_crpt.c",line);
  }
  else {
    pBVar1 = rsa->e;
    pBVar5 = pBVar1;
    if (pBVar1 == (BIGNUM *)0x0) {
      pBVar5 = rsa->q;
      pBVar4 = rsa->p;
      a = rsa->d;
      if ((a != (BIGNUM *)0x0 && pBVar4 != (BIGNUM *)0x0) && (pBVar5 != (BIGNUM *)0x0)) {
        BN_CTX_start(ctx_00);
        r = BN_CTX_get(ctx_00);
        r_00 = BN_CTX_get(ctx_00);
        r_01 = BN_CTX_get(ctx_00);
        if (r_01 != (BIGNUM *)0x0) {
          b = BN_value_one();
          iVar2 = BN_sub(r_00,pBVar4,b);
          if (iVar2 != 0) {
            pBVar4 = BN_value_one();
            iVar2 = BN_sub(r_01,pBVar5,pBVar4);
            if ((iVar2 != 0) && (iVar2 = BN_mul(r,r_00,r_01,ctx_00), iVar2 != 0)) {
              pBVar5 = BN_mod_inverse((BIGNUM *)0x0,a,r,ctx_00);
              BN_CTX_end(ctx_00);
              if (pBVar5 != (BIGNUM *)0x0) goto LAB_0810c14b;
              goto LAB_0810c2f3;
            }
          }
        }
        BN_CTX_end(ctx_00);
      }
LAB_0810c2f3:
      line = 0xd3;
      iVar2 = 0x8c;
      goto LAB_0810c308;
    }
LAB_0810c14b:
    iVar2 = RAND_status();
    if (((iVar2 == 0) && (pBVar1 = rsa->d, pBVar1 != (BIGNUM *)0x0)) && (pBVar1->d != (ulong *)0x0))
    {
      RAND_add(pBVar1->d,pBVar1->dmax << 2,0.0);
    }
    pBVar1 = rsa->n;
    if ((*(byte *)((int)&rsa->flags + 1) & 1) == 0) {
      local_34.d = pBVar1->d;
      local_34.top = pBVar1->top;
      local_34.dmax = pBVar1->dmax;
      local_34.neg = pBVar1->neg;
      local_34.flags = pBVar1->flags & 0xfffffffeU | local_34.flags & 1U | 6;
      pBVar1 = &local_34;
    }
    pBVar3 = BN_BLINDING_create_param
                       ((BN_BLINDING *)0x0,pBVar5,pBVar1,ctx_00,(bn_mod_exp *)rsa->meth->bn_mod_exp,
                        rsa->_method_mod_n);
    pBVar1 = pBVar5;
    if (pBVar3 == (BN_BLINDING *)0x0) {
      ERR_put_error(4,0x88,3,"rsa_crpt.c",0xeb);
    }
    else {
      id = BN_BLINDING_thread_id(pBVar3);
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
  rsa->blinding = pBVar3;
  if (pBVar3 == (BN_BLINDING *)0x0) {
    iVar2 = 0;
  }
  else {
    rsa->flags = rsa->flags & 0xffffff7fU | 8;
    iVar2 = 1;
  }
LAB_0810c1f7:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

