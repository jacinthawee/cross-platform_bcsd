
int BN_is_prime_ex(BIGNUM *p,int nchecks,BN_CTX *ctx,BN_GENCB *cb)

{
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *rnd;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  BN_CTX *ctx_00;
  BN_MONT_CTX *local_2c;
  
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
  ctx_00 = ctx;
  if ((ctx == (BN_CTX *)0x0) && (ctx_00 = BN_CTX_new(), ctx_00 == (BN_CTX *)0x0)) {
    return -1;
  }
  BN_CTX_start(ctx_00);
  pBVar1 = p;
  if (p->neg == 0) {
LAB_080fc114:
    a = BN_CTX_get(ctx_00);
    r = BN_CTX_get(ctx_00);
    rnd = BN_CTX_get(ctx_00);
    if (((rnd == (BIGNUM *)0x0) || (pBVar3 = BN_copy(a,pBVar1), pBVar3 == (BIGNUM *)0x0)) ||
       (iVar2 = BN_sub_word(a,1), iVar2 == 0)) goto LAB_080fc1a0;
    iVar2 = 1;
    if (a->top == 0) {
      iVar2 = 0;
      goto LAB_080fc1a5;
    }
    while (iVar4 = BN_is_bit_set(a,iVar2), iVar4 == 0) {
      iVar2 = iVar2 + 1;
    }
    iVar4 = BN_rshift(r,a,iVar2);
    if ((iVar4 == 0) || (local_2c = BN_MONT_CTX_new(), local_2c == (BN_MONT_CTX *)0x0))
    goto LAB_080fc1a0;
    iVar4 = BN_MONT_CTX_set(local_2c,pBVar1,ctx_00);
    if (iVar4 == 0) {
LAB_080fc4f0:
      iVar2 = -1;
    }
    else {
      if (0 < nchecks) {
        iVar4 = 0;
        do {
          iVar5 = BN_pseudo_rand_range(rnd,a);
          if (((iVar5 == 0) || (iVar5 = BN_add_word(rnd,1), iVar5 == 0)) ||
             (iVar5 = witness(r,iVar2,ctx_00,local_2c), iVar5 == -1)) goto LAB_080fc4f0;
          if (iVar5 != 0) {
            iVar2 = 0;
            goto LAB_080fc4b8;
          }
          if (cb != (BN_GENCB *)0x0) {
            if (cb->ver == 1) {
              if ((cb->cb).cb_1 != (_func_414 *)0x0) {
                (*(cb->cb).cb_1)(1,iVar4,cb->arg);
              }
            }
            else {
              if (cb->ver != 2) {
                iVar2 = -1;
                BN_CTX_end(ctx_00);
                goto joined_r0x080fc458;
              }
              iVar5 = (*(cb->cb).cb_1)(1,iVar4,cb);
              if (iVar5 == 0) goto LAB_080fc4f0;
            }
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 != nchecks);
      }
      iVar2 = 1;
    }
LAB_080fc4b8:
    BN_CTX_end(ctx_00);
joined_r0x080fc458:
    if (ctx != (BN_CTX *)0x0) goto LAB_080fc1db;
  }
  else {
    pBVar1 = BN_CTX_get(ctx_00);
    if (pBVar1 != (BIGNUM *)0x0) {
      BN_copy(pBVar1,p);
      pBVar1->neg = 0;
      goto LAB_080fc114;
    }
LAB_080fc1a0:
    iVar2 = -1;
LAB_080fc1a5:
    BN_CTX_end(ctx_00);
    local_2c = (BN_MONT_CTX *)0x0;
    if (ctx != (BN_CTX *)0x0) {
      return iVar2;
    }
  }
  BN_CTX_free(ctx_00);
  if (local_2c == (BN_MONT_CTX *)0x0) {
    return iVar2;
  }
LAB_080fc1db:
  BN_MONT_CTX_free(local_2c);
  return iVar2;
}

