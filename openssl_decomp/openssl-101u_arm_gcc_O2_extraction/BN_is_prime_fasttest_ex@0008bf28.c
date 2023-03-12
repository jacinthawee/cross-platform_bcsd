
int BN_is_prime_fasttest_ex(BIGNUM *p,int nchecks,BN_CTX *ctx,int do_trial_division,BN_GENCB *cb)

{
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *rnd;
  BIGNUM *pBVar5;
  int iVar6;
  BN_MONT_CTX *mont;
  int iVar7;
  BN_CTX *ctx_00;
  BN_MONT_CTX *pBVar8;
  ushort *puVar9;
  
  pBVar1 = BN_value_one();
  iVar2 = BN_cmp(p,pBVar1);
  if (iVar2 < 1) {
    return 0;
  }
  if (nchecks == 0) {
    iVar2 = BN_num_bits(p);
    if (iVar2 < 0x514) {
      iVar2 = BN_num_bits(p);
      if (iVar2 < 0x352) {
        iVar2 = BN_num_bits(p);
        if (iVar2 < 0x28a) {
          iVar2 = BN_num_bits(p);
          if (iVar2 < 0x226) {
            iVar2 = BN_num_bits(p);
            if (iVar2 < 0x1c2) {
              iVar2 = BN_num_bits(p);
              if (iVar2 < 400) {
                iVar2 = BN_num_bits(p);
                if (iVar2 < 0x15e) {
                  iVar2 = BN_num_bits(p);
                  if (iVar2 < 300) {
                    iVar2 = BN_num_bits(p);
                    if (iVar2 < 0xfa) {
                      iVar2 = BN_num_bits(p);
                      if (iVar2 < 200) {
                        iVar2 = BN_num_bits(p);
                        if (iVar2 < 0x96) {
                          nchecks = 0x1b;
                        }
                        else {
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
    if (*p->d == 2) {
      uVar3 = count_leading_zeroes(p->neg);
      return uVar3 >> 5;
    }
    return 0;
  }
  if (do_trial_division != 0) {
    puVar9 = (ushort *)&primes;
    do {
      puVar9 = puVar9 + 1;
      uVar4 = BN_mod_word(p,(uint)*puVar9);
      if (uVar4 == 0) {
        return 0;
      }
    } while (puVar9 != (ushort *)&DAT_00158d72);
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
LAB_0008c03a:
    a = BN_CTX_get(ctx_00);
    r = BN_CTX_get(ctx_00);
    rnd = BN_CTX_get(ctx_00);
    if (((rnd != (BIGNUM *)0x0) && (pBVar5 = BN_copy(a,pBVar1), pBVar5 != (BIGNUM *)0x0)) &&
       (iVar2 = BN_sub_word(a,1), iVar2 != 0)) {
      pBVar8 = (BN_MONT_CTX *)a->top;
      iVar2 = 1;
      mont = pBVar8;
      if (pBVar8 == (BN_MONT_CTX *)0x0) goto LAB_0008c070;
      while (iVar6 = BN_is_bit_set(a,iVar2), iVar6 == 0) {
        iVar2 = iVar2 + 1;
      }
      iVar6 = BN_rshift(r,a,iVar2);
      if ((iVar6 != 0) && (mont = BN_MONT_CTX_new(), mont != (BN_MONT_CTX *)0x0)) {
        iVar6 = BN_MONT_CTX_set(mont,pBVar1,ctx_00);
        if (iVar6 == 0) {
LAB_0008c142:
          pBVar8 = (BN_MONT_CTX *)0xffffffff;
        }
        else {
          if (0 < nchecks) {
            iVar6 = 0;
            do {
              iVar7 = BN_pseudo_rand_range(rnd,a);
              if (((iVar7 == 0) || (iVar7 = BN_add_word(rnd,1), iVar7 == 0)) ||
                 (iVar7 = witness(rnd,pBVar1,a,r,iVar2,ctx_00,mont), iVar7 == -1))
              goto LAB_0008c142;
              if (iVar7 != 0) {
                pBVar8 = (BN_MONT_CTX *)0x0;
                goto LAB_0008c070;
              }
              if (cb != (BN_GENCB *)0x0) {
                if (cb->ver == 1) {
                  if ((cb->cb).cb_1 != (_func_414 *)0x0) {
                    (*(cb->cb).cb_1)(1,iVar6,cb->arg);
                  }
                }
                else if ((cb->ver != 2) || (iVar7 = (*(cb->cb).cb_1)(1,iVar6,cb), iVar7 == 0))
                goto LAB_0008c142;
              }
              iVar6 = iVar6 + 1;
            } while (iVar6 != nchecks);
          }
          pBVar8 = (BN_MONT_CTX *)0x1;
        }
        goto LAB_0008c070;
      }
    }
  }
  else {
    pBVar1 = BN_CTX_get(ctx_00);
    if (pBVar1 != (BIGNUM *)0x0) {
      BN_copy(pBVar1,p);
      pBVar1->neg = 0;
      goto LAB_0008c03a;
    }
  }
  pBVar8 = (BN_MONT_CTX *)0xffffffff;
  mont = (BN_MONT_CTX *)0x0;
LAB_0008c070:
  BN_CTX_end(ctx_00);
  if (ctx == (BN_CTX *)0x0) {
    BN_CTX_free(ctx_00);
  }
  if (mont != (BN_MONT_CTX *)0x0) {
    BN_MONT_CTX_free(mont);
    return (int)pBVar8;
  }
  return (int)pBVar8;
}

