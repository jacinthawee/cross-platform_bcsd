
int BN_is_prime_fasttest_ex(BIGNUM *p,int nchecks,BN_CTX *ctx,int do_trial_division,BN_GENCB *cb)

{
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *rnd;
  BIGNUM *pBVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  BN_CTX *ctx_00;
  BN_MONT_CTX *mont;
  ushort *puVar7;
  int local_2c;
  
  pBVar1 = BN_value_one();
  iVar2 = BN_cmp(p,pBVar1);
  if (iVar2 < 1) {
    return 0;
  }
  if (nchecks == 0) {
    iVar2 = BN_num_bits(p);
    nchecks = 2;
    if (iVar2 < 0x514) {
      iVar2 = BN_num_bits(p);
      nchecks = 3;
      if (iVar2 < 0x352) {
        iVar2 = BN_num_bits(p);
        nchecks = 4;
        if (iVar2 < 0x28a) {
          iVar2 = BN_num_bits(p);
          nchecks = 5;
          if (iVar2 < 0x226) {
            iVar2 = BN_num_bits(p);
            nchecks = 6;
            if (iVar2 < 0x1c2) {
              iVar2 = BN_num_bits(p);
              nchecks = 7;
              if (iVar2 < 400) {
                iVar2 = BN_num_bits(p);
                nchecks = 8;
                if (iVar2 < 0x15e) {
                  iVar2 = BN_num_bits(p);
                  nchecks = 9;
                  if (iVar2 < 300) {
                    iVar2 = BN_num_bits(p);
                    nchecks = 0xc;
                    if (iVar2 < 0xfa) {
                      iVar2 = BN_num_bits(p);
                      nchecks = 0xf;
                      if (iVar2 < 200) {
                        iVar2 = BN_num_bits(p);
                        nchecks = (uint)(iVar2 < 0x96) * 9 + 0x12;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (p->top < 1) {
    return 0;
  }
  if ((*p->d & 1) == 0) {
    if (p->top != 1) {
      return 0;
    }
    if (*p->d != 2) {
      return 0;
    }
    if (p->neg != 0) {
      return 0;
    }
    return 1;
  }
  if (do_trial_division != 0) {
    puVar7 = (ushort *)(primes + 2);
    do {
      uVar4 = BN_mod_word(p,(uint)*puVar7);
      if (uVar4 == 0) {
        return 0;
      }
      puVar7 = puVar7 + 1;
    } while (puVar7 != (ushort *)"bn_recp.c");
    if (cb != (BN_GENCB *)0x0) {
      if (cb->ver == 1) {
        if ((cb->cb).cb_1 != (_func_414 *)0x0) {
          (*(cb->cb).cb_1)(1,-1,cb->arg);
        }
      }
      else {
        if (cb->ver != 2) {
          return -1;
        }
        iVar2 = (*(cb->cb).cb_1)(1,-1,cb);
        if (iVar2 == 0) {
          return -1;
        }
      }
    }
  }
  ctx_00 = ctx;
  if ((ctx == (BN_CTX *)0x0) && (ctx_00 = BN_CTX_new(), ctx_00 == (BN_CTX *)0x0)) {
    return -1;
  }
  BN_CTX_start(ctx_00);
  pBVar1 = p;
  if (p->neg == 0) {
LAB_080fc5b3:
    a = BN_CTX_get(ctx_00);
    r = BN_CTX_get(ctx_00);
    rnd = BN_CTX_get(ctx_00);
    if (((rnd != (BIGNUM *)0x0) && (pBVar3 = BN_copy(a,pBVar1), pBVar3 != (BIGNUM *)0x0)) &&
       (iVar2 = BN_sub_word(a,1), iVar2 != 0)) {
      if (a->top == 0) {
        mont = (BN_MONT_CTX *)0x0;
        local_2c = 0;
        goto LAB_080fc60d;
      }
      iVar2 = 1;
      while (iVar5 = BN_is_bit_set(a,iVar2), iVar5 == 0) {
        iVar2 = iVar2 + 1;
      }
      iVar5 = BN_rshift(r,a,iVar2);
      if ((iVar5 != 0) && (mont = BN_MONT_CTX_new(), mont != (BN_MONT_CTX *)0x0)) {
        iVar5 = BN_MONT_CTX_set(mont,pBVar1,ctx_00);
        local_2c = -1;
        if (iVar5 != 0) {
          if (nchecks < 1) {
            local_2c = 1;
          }
          else {
            iVar5 = 0;
            do {
              iVar6 = BN_pseudo_rand_range(rnd,a);
              if (((iVar6 == 0) || (iVar6 = BN_add_word(rnd,1), iVar6 == 0)) ||
                 (iVar6 = witness(r,iVar2,ctx_00,mont), iVar6 == -1)) {
LAB_080fc903:
                local_2c = -1;
                goto LAB_080fc60d;
              }
              if (iVar6 != 0) {
                local_2c = 0;
                goto LAB_080fc60d;
              }
              if (cb != (BN_GENCB *)0x0) {
                if (cb->ver == 1) {
                  if ((cb->cb).cb_1 != (_func_414 *)0x0) {
                    (*(cb->cb).cb_1)(1,iVar5,cb->arg);
                  }
                }
                else if ((cb->ver != 2) || (iVar6 = (*(cb->cb).cb_1)(1,iVar5,cb), iVar6 == 0))
                goto LAB_080fc903;
              }
              iVar5 = iVar5 + 1;
            } while (nchecks != iVar5);
            local_2c = 1;
          }
        }
        goto LAB_080fc60d;
      }
    }
  }
  else {
    pBVar1 = BN_CTX_get(ctx_00);
    if (pBVar1 != (BIGNUM *)0x0) {
      BN_copy(pBVar1,p);
      pBVar1->neg = 0;
      goto LAB_080fc5b3;
    }
  }
  mont = (BN_MONT_CTX *)0x0;
  local_2c = -1;
LAB_080fc60d:
  BN_CTX_end(ctx_00);
  if (ctx == (BN_CTX *)0x0) {
    BN_CTX_free(ctx_00);
  }
  if (mont != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(mont);
    return local_2c;
  }
  return local_2c;
}

