
int BN_is_prime_ex(BIGNUM *p,int nchecks,BN_CTX *ctx,BN_GENCB *cb)

{
  BIGNUM *pBVar1;
  int iVar2;
  BIGNUM *a;
  BIGNUM *r;
  BIGNUM *rnd;
  BIGNUM *pBVar3;
  int iVar4;
  BN_MONT_CTX *mont;
  BN_CTX *ctx_00;
  int local_2c;
  
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
                        nchecks = 0x1b;
                        if (0x95 < iVar2) {
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
  ctx_00 = ctx;
  if ((ctx == (BN_CTX *)0x0) && (ctx_00 = BN_CTX_new(), ctx_00 == (BN_CTX *)0x0)) {
    return -1;
  }
  BN_CTX_start(ctx_00);
  pBVar1 = p;
  if (p->neg == 0) {
LAB_004fac0c:
    a = BN_CTX_get(ctx_00);
    r = BN_CTX_get(ctx_00);
    rnd = BN_CTX_get(ctx_00);
    if (((rnd == (BIGNUM *)0x0) || (pBVar3 = BN_copy(a,pBVar1), pBVar3 == (BIGNUM *)0x0)) ||
       (iVar2 = BN_sub_word(a,1), iVar2 == 0)) goto LAB_004fadf8;
    iVar2 = 1;
    if (a->top == 0) {
      iVar2 = 0;
      goto LAB_004fadfc;
    }
    while (iVar4 = BN_is_bit_set(a,iVar2), iVar4 == 0) {
      iVar2 = iVar2 + 1;
    }
    iVar4 = BN_rshift(r,a,iVar2);
    if ((iVar4 == 0) || (mont = BN_MONT_CTX_new(), mont == (BN_MONT_CTX *)0x0)) goto LAB_004fadf8;
    iVar4 = BN_MONT_CTX_set(mont,pBVar1,ctx_00);
    if (iVar4 == 0) {
LAB_004faf50:
      iVar2 = -1;
    }
    else {
      if (0 < nchecks) {
        local_2c = 0;
        do {
          iVar4 = BN_pseudo_rand_range(rnd,a);
          if (((iVar4 == 0) || (iVar4 = BN_add_word(rnd,1), iVar4 == 0)) ||
             (iVar4 = witness(rnd,pBVar1,a,r,iVar2,ctx_00,mont), iVar4 == -1)) goto LAB_004faf50;
          if (iVar4 != 0) {
            iVar2 = 0;
            goto LAB_004faf20;
          }
          if (cb != (BN_GENCB *)0x0) {
            if (cb->ver == 1) {
              if ((cb->cb).cb_1 != (_func_414 *)0x0) {
                (*(cb->cb).cb_1)(1,local_2c,cb->arg);
              }
            }
            else {
              if (cb->ver != 2) {
                iVar2 = -1;
                BN_CTX_end(ctx_00);
                goto joined_r0x004fad98;
              }
              iVar4 = (*(cb->cb).cb_1)(1,local_2c,cb);
              if (iVar4 == 0) goto LAB_004faf50;
            }
          }
          local_2c = local_2c + 1;
        } while (local_2c != nchecks);
      }
      iVar2 = 1;
    }
LAB_004faf20:
    BN_CTX_end(ctx_00);
joined_r0x004fad98:
    if (ctx != (BN_CTX *)0x0) goto LAB_004fae28;
  }
  else {
    pBVar1 = BN_CTX_get(ctx_00);
    if (pBVar1 != (BIGNUM *)0x0) {
      BN_copy(pBVar1,p);
      pBVar1->neg = 0;
      goto LAB_004fac0c;
    }
LAB_004fadf8:
    iVar2 = -1;
LAB_004fadfc:
    BN_CTX_end(ctx_00);
    if (ctx != (BN_CTX *)0x0) {
      return iVar2;
    }
    mont = (BN_MONT_CTX *)0x0;
  }
  BN_CTX_free(ctx_00);
  if (mont == (BN_MONT_CTX *)0x0) {
    return iVar2;
  }
LAB_004fae28:
  BN_MONT_CTX_free(mont);
  return iVar2;
}

