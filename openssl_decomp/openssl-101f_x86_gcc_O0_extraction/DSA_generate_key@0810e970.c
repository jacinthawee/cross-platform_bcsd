
int DSA_generate_key(DSA *a)

{
  _func_1741 *p_Var1;
  int iVar2;
  BN_CTX *ctx;
  BIGNUM *p;
  BIGNUM *rnd;
  BIGNUM *r;
  int in_GS_OFFSET;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  p_Var1 = a->meth->dsa_keygen;
  if (p_Var1 == (_func_1741 *)0x0) {
    ctx = BN_CTX_new();
    if (ctx == (BN_CTX *)0x0) {
      iVar2 = 0;
    }
    else {
      rnd = a->priv_key;
      if ((rnd == (BIGNUM *)0x0) && (rnd = BN_new(), rnd == (BIGNUM *)0x0)) {
        iVar2 = 0;
      }
      else {
        do {
          iVar2 = BN_rand_range(rnd,a->q);
          if (iVar2 == 0) goto LAB_0810e9f2;
        } while (rnd->top == 0);
        r = a->pub_key;
        if ((r == (BIGNUM *)0x0) && (r = BN_new(), r == (BIGNUM *)0x0)) {
LAB_0810e9f2:
          iVar2 = 0;
        }
        else {
          p = rnd;
          if ((*(byte *)&a->flags & 2) == 0) {
            p = &local_34;
            BN_init(p);
            local_34.d = rnd->d;
            local_34.top = rnd->top;
            local_34.dmax = rnd->dmax;
            local_34.neg = rnd->neg;
            local_34.flags = rnd->flags & 0xfffffffeU | local_34.flags & 1U | 6;
          }
          iVar2 = BN_mod_exp(r,a->g,p,a->p,ctx);
          if (iVar2 == 0) {
            iVar2 = 0;
            if (a->pub_key == (BIGNUM *)0x0) {
              BN_free(r);
            }
          }
          else {
            a->priv_key = rnd;
            a->pub_key = r;
            iVar2 = 1;
          }
        }
        if (a->priv_key == (BIGNUM *)0x0) {
          BN_free(rnd);
        }
      }
      BN_CTX_free(ctx);
    }
  }
  else {
    iVar2 = (*p_Var1)(a);
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

