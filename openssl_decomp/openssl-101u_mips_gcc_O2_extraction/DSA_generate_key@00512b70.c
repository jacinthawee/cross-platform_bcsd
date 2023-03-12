
int DSA_generate_key(DSA *a)

{
  undefined *puVar1;
  int iVar2;
  BN_CTX *c;
  BIGNUM *pBVar3;
  BIGNUM *rnd;
  BIGNUM *a_00;
  _func_1741 *p_Var4;
  BIGNUM local_38;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  p_Var4 = a->meth->dsa_keygen;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (p_Var4 == (_func_1741 *)0x0) {
    c = BN_CTX_new();
    if (c == (BN_CTX *)0x0) {
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
          if (iVar2 == 0) {
            iVar2 = 0;
            goto LAB_00512c48;
          }
        } while (rnd->top == 0);
        a_00 = a->pub_key;
        if ((a_00 == (BIGNUM *)0x0) && (a_00 = BN_new(), a_00 == (BIGNUM *)0x0)) {
          iVar2 = 0;
        }
        else {
          pBVar3 = rnd;
          if ((a->flags & 2U) == 0) {
            BN_init(&local_38);
            local_38.d = rnd->d;
            local_38.top = rnd->top;
            local_38.dmax = rnd->dmax;
            local_38.neg = rnd->neg;
            local_38.flags = local_38.flags & 1U | rnd->flags & 0xfffffffeU | 6;
            pBVar3 = &local_38;
          }
          iVar2 = (*(code *)PTR_BN_mod_exp_006a795c)(a_00,a->g,pBVar3,a->p,c);
          if (iVar2 == 0) {
            iVar2 = 0;
            if (a->pub_key == (BIGNUM *)0x0) {
              BN_free(a_00);
            }
          }
          else {
            a->priv_key = rnd;
            iVar2 = 1;
            a->pub_key = a_00;
          }
        }
LAB_00512c48:
        if (a->priv_key == (BIGNUM *)0x0) {
          BN_free(rnd);
        }
      }
      BN_CTX_free(c);
    }
  }
  else {
    iVar2 = (*p_Var4)(a);
  }
  if (local_24 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    default_DSA_method = local_24;
    return (int)&_gp_1;
  }
  return iVar2;
}

