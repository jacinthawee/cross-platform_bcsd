
int DSA_generate_key(DSA *a)

{
  int iVar1;
  BN_CTX *ctx;
  _func_1741 *p_Var2;
  BIGNUM *pBVar3;
  BIGNUM *rnd;
  BIGNUM *pBVar4;
  BIGNUM local_2c;
  
  p_Var2 = a->meth->dsa_keygen;
  if (p_Var2 != (_func_1741 *)0x0) {
    iVar1 = (*p_Var2)(a);
    return iVar1;
  }
  ctx = BN_CTX_new();
  if ((ctx == (BN_CTX *)0x0) ||
     ((rnd = a->priv_key, rnd == (BIGNUM *)0x0 && (rnd = BN_new(), rnd == (BIGNUM *)0x0)))) {
LAB_0009938a:
    pBVar4 = (BIGNUM *)0x0;
  }
  else {
    do {
      iVar1 = BN_rand_range(rnd,a->q);
      if (iVar1 == 0) goto LAB_0009931e;
    } while (rnd->top == 0);
    pBVar3 = a->pub_key;
    if ((pBVar3 == (BIGNUM *)0x0) && (pBVar3 = BN_new(), pBVar3 == (BIGNUM *)0x0)) {
LAB_0009931e:
      if (rnd == (BIGNUM *)0x0) goto LAB_0009938a;
LAB_00099322:
      pBVar3 = a->priv_key;
      pBVar4 = (BIGNUM *)0x0;
    }
    else {
      pBVar4 = rnd;
      if (-1 < a->flags << 0x1e) {
        BN_init(&local_2c);
        local_2c.d = rnd->d;
        local_2c.top = rnd->top;
        local_2c.dmax = rnd->dmax;
        local_2c.neg = rnd->neg;
        local_2c.flags = local_2c.flags & 1U | rnd->flags & 0xfffffffeU | 6;
        pBVar4 = &local_2c;
      }
      iVar1 = BN_mod_exp(pBVar3,a->g,pBVar4,a->p,ctx);
      if (iVar1 == 0) {
        pBVar4 = a->pub_key;
        if (pBVar4 != (BIGNUM *)0x0) goto LAB_00099322;
        BN_free(pBVar3);
        pBVar3 = a->priv_key;
      }
      else {
        a->priv_key = rnd;
        pBVar4 = (BIGNUM *)0x1;
        a->pub_key = pBVar3;
        pBVar3 = rnd;
      }
    }
    if (pBVar3 == (BIGNUM *)0x0) {
      BN_free(rnd);
    }
  }
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  return (int)pBVar4;
}

