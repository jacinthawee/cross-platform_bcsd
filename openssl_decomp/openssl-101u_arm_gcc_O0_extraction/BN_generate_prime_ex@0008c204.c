
int BN_generate_prime_ex(BIGNUM *ret,int bits,int safe,BIGNUM *add,BIGNUM *rem,BN_GENCB *cb)

{
  ushort uVar1;
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  BIGNUM *pBVar8;
  int iVar9;
  BN_MONT_CTX *pBVar10;
  uint uVar11;
  int iVar12;
  BIGNUM *local_4c;
  int local_48;
  
  if (bits < 0x514) {
    if (bits < 0x352) {
      if (bits < 0x28a) {
        if (bits < 0x226) {
          if (bits < 0x1c2) {
            if (bits < 400) {
              if (bits < 0x15e) {
                if (bits < 300) {
                  if (bits < 0xfa) {
                    if (bits < 200) {
                      if (bits < 0x96) {
                        iVar12 = 0x1b;
                      }
                      else {
                        iVar12 = 0x12;
                      }
                    }
                    else {
                      iVar12 = 0xf;
                    }
                  }
                  else {
                    iVar12 = 0xc;
                  }
                }
                else {
                  iVar12 = 9;
                }
              }
              else {
                iVar12 = 8;
              }
            }
            else {
              iVar12 = 7;
            }
          }
          else {
            iVar12 = 6;
          }
        }
        else {
          iVar12 = 5;
        }
      }
      else {
        iVar12 = 4;
      }
    }
    else {
      iVar12 = 3;
    }
  }
  else {
    iVar12 = 2;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_start(ctx);
  r = BN_CTX_get(ctx);
  if (r != (BIGNUM *)0x0) {
    local_48 = 0;
    do {
      if (add != (BIGNUM *)0x0) {
        if (safe == 0) {
          BN_CTX_start(ctx);
          pBVar2 = BN_CTX_get(ctx);
          if ((((pBVar2 != (BIGNUM *)0x0) && (iVar5 = BN_rand(ret,bits,0,1), iVar5 != 0)) &&
              (iVar5 = BN_div((BIGNUM *)0x0,pBVar2,ret,add,ctx), iVar5 != 0)) &&
             (iVar5 = BN_sub(ret,ret,pBVar2), iVar5 != 0)) {
            if (rem == (BIGNUM *)0x0) {
              iVar5 = BN_add_word(ret,1);
            }
            else {
              iVar5 = BN_add(ret,ret,rem);
            }
            if (iVar5 != 0) {
              iVar5 = 1;
              do {
                while( true ) {
                  iVar7 = iVar5 * 2;
                  iVar5 = iVar5 + 1;
                  uVar6 = BN_mod_word(ret,(uint)*(ushort *)(&primes + iVar7));
                  if (1 < uVar6) break;
                  iVar5 = 1;
                  iVar7 = BN_add(ret,ret,add);
                  if (iVar7 == 0) goto LAB_0008c29e;
                }
              } while (iVar5 < 0x800);
              BN_CTX_end(ctx);
              goto LAB_0008c484;
            }
          }
        }
        else {
          BN_CTX_start(ctx);
          pBVar2 = BN_CTX_get(ctx);
          pBVar3 = BN_CTX_get(ctx);
          pBVar4 = BN_CTX_get(ctx);
          if (((pBVar4 != (BIGNUM *)0x0) && (iVar5 = BN_rshift1(pBVar4,add), iVar5 != 0)) &&
             ((iVar5 = BN_rand(pBVar3,bits + -1,0,1), iVar5 != 0 &&
              ((iVar5 = BN_div((BIGNUM *)0x0,pBVar2,pBVar3,pBVar4,ctx), iVar5 != 0 &&
               (iVar5 = BN_sub(pBVar3,pBVar3,pBVar2), iVar5 != 0)))))) {
            if (rem == (BIGNUM *)0x0) {
              iVar5 = BN_add_word(pBVar3,1);
            }
            else {
              iVar5 = BN_rshift1(pBVar2,rem);
              if (iVar5 == 0) goto LAB_0008c29e;
              iVar5 = BN_add(pBVar3,pBVar3,pBVar2);
            }
            if (((iVar5 != 0) && (iVar5 = BN_lshift1(ret,pBVar3), iVar5 != 0)) &&
               (iVar5 = BN_add_word(ret,1), iVar5 != 0)) {
              iVar5 = 1;
              do {
                while( true ) {
                  uVar1 = *(ushort *)(&primes + iVar5 * 2);
                  uVar6 = BN_mod_word(ret,(uint)uVar1);
                  if ((uVar6 != 0) && (uVar6 = BN_mod_word(pBVar3,(uint)uVar1), uVar6 != 0)) break;
                  iVar5 = 1;
                  iVar7 = BN_add(ret,ret,add);
                  if ((iVar7 == 0) || (iVar7 = BN_add(pBVar3,pBVar3,pBVar4), iVar7 == 0))
                  goto LAB_0008c29e;
                }
                iVar5 = iVar5 + 1;
              } while (iVar5 < 0x800);
              BN_CTX_end(ctx);
              goto LAB_0008c484;
            }
          }
        }
LAB_0008c29e:
        iVar12 = 0;
        BN_CTX_end(ctx);
        goto LAB_0008c2a6;
      }
      iVar5 = probable_prime(ret,bits);
      if (iVar5 == 0) break;
LAB_0008c484:
      if (cb != (BN_GENCB *)0x0) {
        if (cb->ver == 1) {
          if ((cb->cb).cb_1 != (_func_414 *)0x0) {
            (*(cb->cb).cb_1)(0,local_48,cb->arg);
          }
        }
        else if ((cb->ver != 2) || (iVar5 = (*(cb->cb).cb_1)(0,local_48,cb), iVar5 == 0)) break;
      }
      if (safe == 0) {
        iVar5 = BN_is_prime_fasttest_ex(ret,iVar12,ctx,0,cb);
        if (iVar5 == -1) break;
        if (iVar5 != 0) goto LAB_0008c56e;
      }
      else {
        iVar5 = BN_rshift1(r,ret);
        if (iVar5 == 0) break;
        iVar5 = 0;
        while( true ) {
          pBVar2 = BN_value_one();
          iVar7 = BN_cmp(ret,pBVar2);
          if ((iVar7 < 1) || (ret->top < 1)) break;
          if ((int)(*ret->d << 0x1f) < 0) {
            BN_CTX_start(ctx);
            local_4c = ret;
            if (ret->neg == 0) {
LAB_0008c598:
              pBVar2 = BN_CTX_get(ctx);
              pBVar3 = BN_CTX_get(ctx);
              pBVar4 = BN_CTX_get(ctx);
              if (((pBVar4 == (BIGNUM *)0x0) ||
                  (pBVar8 = BN_copy(pBVar2,local_4c), pBVar8 == (BIGNUM *)0x0)) ||
                 (iVar7 = BN_sub_word(pBVar2,1), iVar7 == 0)) goto LAB_0008c602;
              uVar11 = pBVar2->top;
              iVar7 = 1;
              if (uVar11 == 0) goto LAB_0008c5d2;
              while (iVar9 = BN_is_bit_set(pBVar2,iVar7), iVar9 == 0) {
                iVar7 = iVar7 + 1;
              }
              iVar9 = BN_rshift(pBVar3,pBVar2,iVar7);
              if ((iVar9 == 0) || (pBVar10 = BN_MONT_CTX_new(), pBVar10 == (BN_MONT_CTX *)0x0))
              goto LAB_0008c602;
              iVar9 = BN_MONT_CTX_set(pBVar10,local_4c,ctx);
              if (((iVar9 == 0) ||
                  ((iVar9 = BN_pseudo_rand_range(pBVar4,pBVar2), iVar9 == 0 ||
                   (iVar9 = BN_add_word(pBVar4,1), iVar9 == 0)))) ||
                 (iVar7 = witness(pBVar4,local_4c,pBVar2,pBVar3,iVar7,ctx,pBVar10), iVar7 == -1)) {
LAB_0008c846:
                uVar11 = 0xffffffff;
LAB_0008c75a:
                BN_CTX_end(ctx);
              }
              else {
                if (iVar7 != 0) {
                  uVar11 = 0;
                  goto LAB_0008c75a;
                }
                if (cb == (BN_GENCB *)0x0) {
LAB_0008c756:
                  uVar11 = 1;
                  goto LAB_0008c75a;
                }
                if (cb->ver == 1) {
                  if ((cb->cb).cb_1 != (_func_414 *)0x0) {
                    (*(cb->cb).cb_1)(1,0,cb->arg);
                  }
                  goto LAB_0008c756;
                }
                if (cb->ver == 2) {
                  iVar7 = (*(cb->cb).cb_1)(1,0,cb);
                  if (iVar7 == 0) goto LAB_0008c846;
                  goto LAB_0008c756;
                }
                uVar11 = 0xffffffff;
                BN_CTX_end(ctx);
              }
              BN_MONT_CTX_free(pBVar10);
            }
            else {
              local_4c = BN_CTX_get(ctx);
              if (local_4c != (BIGNUM *)0x0) {
                BN_copy(local_4c,ret);
                local_4c->neg = 0;
                goto LAB_0008c598;
              }
LAB_0008c602:
              uVar11 = 0xffffffff;
LAB_0008c5d2:
              BN_CTX_end(ctx);
            }
            if (uVar11 == 0xffffffff) goto LAB_0008c2c8;
          }
          else {
            if ((ret->top != 1) || (*ret->d != 2)) break;
            uVar11 = count_leading_zeroes(ret->neg);
            uVar11 = uVar11 >> 5;
          }
          if (uVar11 == 0) break;
          pBVar2 = BN_value_one();
          iVar7 = BN_cmp(r,pBVar2);
          if ((iVar7 < 1) || (r->top < 1)) break;
          if ((int)(*r->d << 0x1f) < 0) {
            BN_CTX_start(ctx);
            local_4c = r;
            if (r->neg == 0) {
LAB_0008c62e:
              pBVar2 = BN_CTX_get(ctx);
              pBVar3 = BN_CTX_get(ctx);
              pBVar4 = BN_CTX_get(ctx);
              if (((pBVar4 == (BIGNUM *)0x0) ||
                  (pBVar8 = BN_copy(pBVar2,local_4c), pBVar8 == (BIGNUM *)0x0)) ||
                 (iVar7 = BN_sub_word(pBVar2,1), iVar7 == 0)) goto LAB_0008c698;
              uVar11 = pBVar2->top;
              iVar7 = 1;
              if (uVar11 == 0) goto LAB_0008c668;
              while (iVar9 = BN_is_bit_set(pBVar2,iVar7), iVar9 == 0) {
                iVar7 = iVar7 + 1;
              }
              iVar9 = BN_rshift(pBVar3,pBVar2,iVar7);
              if ((iVar9 == 0) || (pBVar10 = BN_MONT_CTX_new(), pBVar10 == (BN_MONT_CTX *)0x0))
              goto LAB_0008c698;
              iVar9 = BN_MONT_CTX_set(pBVar10,local_4c,ctx);
              if (((iVar9 == 0) ||
                  ((iVar9 = BN_pseudo_rand_range(pBVar4,pBVar2), iVar9 == 0 ||
                   (iVar9 = BN_add_word(pBVar4,1), iVar9 == 0)))) ||
                 (iVar7 = witness(pBVar4,local_4c,pBVar2,pBVar3,iVar7,ctx,pBVar10), iVar7 == -1)) {
LAB_0008c84c:
                uVar11 = 0xffffffff;
LAB_0008c7f0:
                BN_CTX_end(ctx);
              }
              else {
                if (iVar7 != 0) {
                  uVar11 = 0;
                  goto LAB_0008c7f0;
                }
                if (cb == (BN_GENCB *)0x0) {
LAB_0008c7ec:
                  uVar11 = 1;
                  goto LAB_0008c7f0;
                }
                if (cb->ver == 1) {
                  if ((cb->cb).cb_1 != (_func_414 *)0x0) {
                    (*(cb->cb).cb_1)(1,0,cb->arg);
                  }
                  goto LAB_0008c7ec;
                }
                if (cb->ver == 2) {
                  iVar7 = (*(cb->cb).cb_1)(1,0,cb);
                  if (iVar7 == 0) goto LAB_0008c84c;
                  goto LAB_0008c7ec;
                }
                uVar11 = 0xffffffff;
                BN_CTX_end(ctx);
              }
              BN_MONT_CTX_free(pBVar10);
            }
            else {
              local_4c = BN_CTX_get(ctx);
              if (local_4c != (BIGNUM *)0x0) {
                BN_copy(local_4c,r);
                local_4c->neg = 0;
                goto LAB_0008c62e;
              }
LAB_0008c698:
              uVar11 = 0xffffffff;
LAB_0008c668:
              BN_CTX_end(ctx);
            }
            if (uVar11 == 0xffffffff) goto LAB_0008c2c8;
          }
          else {
            if ((r->top != 1) || (*r->d != 2)) break;
            uVar11 = count_leading_zeroes(r->neg);
            uVar11 = uVar11 >> 5;
          }
          if (uVar11 == 0) break;
          if (cb != (BN_GENCB *)0x0) {
            if (cb->ver == 1) {
              if ((cb->cb).cb_1 != (_func_414 *)0x0) {
                (*(cb->cb).cb_1)(2,local_48,cb->arg);
              }
            }
            else if ((cb->ver != 2) || (iVar7 = (*(cb->cb).cb_1)(2,local_48,cb), iVar7 == 0))
            goto LAB_0008c2c8;
          }
          iVar5 = iVar5 + 1;
          if (iVar12 <= iVar5) goto LAB_0008c56e;
        }
      }
      local_48 = local_48 + 1;
    } while( true );
  }
LAB_0008c2c8:
  iVar12 = 0;
LAB_0008c2a6:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar12;
LAB_0008c56e:
  iVar12 = 1;
  goto LAB_0008c2a6;
}

