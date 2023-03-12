
int BN_is_prime_fasttest_ex(BIGNUM *p,int nchecks,BN_CTX *ctx,int do_trial_division,BN_GENCB *cb)

{
  ushort uVar1;
  BIGNUM *pBVar2;
  int iVar3;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *rnd;
  BIGNUM *pBVar4;
  int iVar5;
  ulong uVar6;
  BN_CTX *ctx_00;
  ushort *puVar7;
  BN_MONT_CTX *mont;
  int local_2c;
  
  pBVar2 = BN_value_one();
  iVar3 = BN_cmp(p,pBVar2);
  if (iVar3 < 1) {
    return 0;
  }
  if (nchecks == 0) {
    iVar3 = BN_num_bits(p);
    if (iVar3 < 0x514) {
      iVar3 = BN_num_bits(p);
      if (iVar3 < 0x352) {
        iVar3 = BN_num_bits(p);
        if (iVar3 < 0x28a) {
          iVar3 = BN_num_bits(p);
          if (iVar3 < 0x226) {
            iVar3 = BN_num_bits(p);
            if (iVar3 < 0x1c2) {
              iVar3 = BN_num_bits(p);
              if (iVar3 < 400) {
                iVar3 = BN_num_bits(p);
                if (iVar3 < 0x15e) {
                  iVar3 = BN_num_bits(p);
                  if (iVar3 < 300) {
                    iVar3 = BN_num_bits(p);
                    if (iVar3 < 0xfa) {
                      iVar3 = BN_num_bits(p);
                      if (iVar3 < 200) {
                        iVar3 = BN_num_bits(p);
                        nchecks = 0x1b;
                        if (0x95 < iVar3) {
                          nchecks = 0x12;
                        }
                      }
                      else {
                        nchecks = 0xf;
                      }
                    }
                    else {
                      nchecks = 0xc;
                    }
                  }
                  else {
                    nchecks = 9;
                  }
                }
                else {
                  nchecks = 8;
                }
              }
              else {
                nchecks = 7;
              }
            }
            else {
              nchecks = 6;
            }
          }
          else {
            nchecks = 5;
          }
        }
        else {
          nchecks = 4;
        }
      }
      else {
        nchecks = 3;
      }
    }
    else {
      nchecks = 2;
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
      uVar1 = *puVar7;
      puVar7 = puVar7 + 1;
      uVar6 = BN_mod_word(p,(uint)uVar1);
      if (uVar6 == 0) {
        return 0;
      }
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
        iVar3 = (*(cb->cb).cb_1)(1,-1,cb);
        if (iVar3 == 0) {
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
  pBVar2 = p;
  if (p->neg == 0) {
LAB_004fb1ac:
    a = BN_CTX_get(ctx_00);
    r = BN_CTX_get(ctx_00);
    rnd = BN_CTX_get(ctx_00);
    if (((rnd != (BIGNUM *)0x0) && (pBVar4 = BN_copy(a,pBVar2), pBVar4 != (BIGNUM *)0x0)) &&
       (iVar3 = BN_sub_word(a,1), iVar3 != 0)) {
      mont = (BN_MONT_CTX *)0x0;
      if (a->top == 0) {
        iVar3 = 0;
        goto LAB_004fb3e0;
      }
      iVar3 = 1;
      while (iVar5 = BN_is_bit_set(a,iVar3), iVar5 == 0) {
        iVar3 = iVar3 + 1;
      }
      iVar5 = BN_rshift(r,a,iVar3);
      if ((iVar5 != 0) && (mont = BN_MONT_CTX_new(), mont != (BN_MONT_CTX *)0x0)) {
        iVar5 = BN_MONT_CTX_set(mont,pBVar2,ctx_00);
        if (iVar5 == 0) {
LAB_004fb358:
          iVar3 = -1;
        }
        else {
          if (0 < nchecks) {
            local_2c = 0;
            do {
              iVar5 = BN_pseudo_rand_range(rnd,a);
              if (((iVar5 == 0) || (iVar5 = BN_add_word(rnd,1), iVar5 == 0)) ||
                 (iVar5 = witness(rnd,pBVar2,a,r,iVar3,ctx_00,mont), iVar5 == -1))
              goto LAB_004fb358;
              if (iVar5 != 0) {
                iVar3 = 0;
                goto LAB_004fb3e0;
              }
              if (cb != (BN_GENCB *)0x0) {
                if (cb->ver == 1) {
                  if ((cb->cb).cb_1 != (_func_414 *)0x0) {
                    (*(cb->cb).cb_1)(1,local_2c,cb->arg);
                  }
                }
                else if ((cb->ver != 2) || (iVar5 = (*(cb->cb).cb_1)(1,local_2c,cb), iVar5 == 0))
                goto LAB_004fb358;
              }
              local_2c = local_2c + 1;
            } while (nchecks != local_2c);
          }
          iVar3 = 1;
        }
        goto LAB_004fb3e0;
      }
    }
  }
  else {
    pBVar2 = BN_CTX_get(ctx_00);
    if (pBVar2 != (BIGNUM *)0x0) {
      BN_copy(pBVar2,p);
      pBVar2->neg = 0;
      goto LAB_004fb1ac;
    }
  }
  mont = (BN_MONT_CTX *)0x0;
  iVar3 = -1;
LAB_004fb3e0:
  BN_CTX_end(ctx_00);
  if (ctx == (BN_CTX *)0x0) {
    BN_CTX_free(ctx_00);
  }
  if (mont != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(mont);
    return iVar3;
  }
  return iVar3;
}

