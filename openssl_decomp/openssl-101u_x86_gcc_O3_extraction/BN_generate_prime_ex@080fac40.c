
/* WARNING: Restarted to delay deadcode elimination for space: stack */

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
  BIGNUM *pBVar7;
  int iVar8;
  BN_MONT_CTX *pBVar9;
  ushort *puVar10;
  int local_44;
  int local_3c;
  int local_38;
  BIGNUM *local_34;
  
  local_38 = 2;
  if ((((((bits < 0x514) && (local_38 = 3, bits < 0x352)) && (local_38 = 4, bits < 0x28a)) &&
       ((local_38 = 5, bits < 0x226 && (local_38 = 6, bits < 0x1c2)))) && (local_38 = 7, bits < 400)
      ) && (((local_38 = 8, bits < 0x15e && (local_38 = 9, bits < 300)) &&
            ((local_38 = 0xc, bits < 0xfa && (local_38 = 0xf, bits < 200)))))) {
    local_38 = (uint)(bits < 0x96) * 9 + 0x12;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_start(ctx);
  r = BN_CTX_get(ctx);
  if (r != (BIGNUM *)0x0) {
    local_3c = 0;
    do {
      if (add != (BIGNUM *)0x0) {
        if (safe == 0) {
          BN_CTX_start(ctx);
          pBVar2 = BN_CTX_get(ctx);
          if ((((pBVar2 != (BIGNUM *)0x0) && (iVar5 = BN_rand(ret,bits,0,1), iVar5 != 0)) &&
              (iVar5 = BN_div((BIGNUM *)0x0,pBVar2,ret,add,ctx), iVar5 != 0)) &&
             (iVar5 = BN_sub(ret,ret,pBVar2), iVar5 != 0)) {
            pBVar2 = rem;
            if (rem == (BIGNUM *)0x0) {
              iVar5 = BN_add_word(ret,1);
              goto joined_r0x080fb695;
            }
            while( true ) {
              iVar5 = BN_add(ret,ret,pBVar2);
joined_r0x080fb695:
              if (iVar5 == 0) break;
              puVar10 = (ushort *)(primes + 2);
              while (uVar6 = BN_mod_word(ret,(uint)*puVar10), pBVar2 = add, 1 < uVar6) {
                puVar10 = puVar10 + 1;
                if (puVar10 == (ushort *)"bn_recp.c") {
                  BN_CTX_end(ctx);
                  if (cb == (BN_GENCB *)0x0) goto LAB_080fb07f;
                  goto LAB_080fb053;
                }
              }
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
              if (iVar5 == 0) goto LAB_080fad32;
              iVar5 = BN_add(pBVar3,pBVar3,pBVar2);
            }
            if ((iVar5 != 0) && (iVar5 = BN_lshift1(ret,pBVar3), iVar5 != 0)) {
              iVar5 = BN_add_word(ret,1);
              while (iVar5 != 0) {
                puVar10 = (ushort *)(primes + 2);
                while( true ) {
                  uVar1 = *puVar10;
                  uVar6 = BN_mod_word(ret,(uint)uVar1);
                  if ((uVar6 == 0) || (uVar6 = BN_mod_word(pBVar3,(uint)uVar1), uVar6 == 0)) break;
                  puVar10 = puVar10 + 1;
                  if (puVar10 == (ushort *)"bn_recp.c") {
                    BN_CTX_end(ctx);
                    if (cb != (BN_GENCB *)0x0) goto LAB_080fb053;
                    goto LAB_080fb0d0;
                  }
                }
                iVar5 = BN_add(ret,ret,add);
                if (iVar5 == 0) break;
                iVar5 = BN_add(pBVar3,pBVar3,pBVar4);
              }
            }
          }
        }
LAB_080fad32:
        BN_CTX_end(ctx);
        break;
      }
      iVar5 = probable_prime();
      if (iVar5 == 0) break;
      if (cb != (BN_GENCB *)0x0) {
LAB_080fb053:
        if (cb->ver == 1) {
          if ((cb->cb).cb_1 != (_func_414 *)0x0) {
            (*(cb->cb).cb_1)(0,local_3c,cb->arg);
          }
        }
        else if ((cb->ver != 2) || (iVar5 = (*(cb->cb).cb_1)(0,local_3c,cb), iVar5 == 0)) break;
      }
      if (safe == 0) {
LAB_080fb07f:
        iVar5 = BN_is_prime_fasttest_ex(ret,local_38,ctx,0,cb);
        if (iVar5 == -1) break;
        if (iVar5 != 0) goto LAB_080fb460;
      }
      else {
LAB_080fb0d0:
        iVar5 = BN_rshift1(r,ret);
        if (iVar5 == 0) break;
        local_44 = 0;
        while( true ) {
          pBVar2 = BN_value_one();
          iVar5 = BN_cmp(ret,pBVar2);
          if ((iVar5 < 1) || (ret->top < 1)) break;
          if ((*ret->d & 1) == 0) {
            if (((ret->top != 1) || (*ret->d != 2)) || (ret->neg != 0)) break;
          }
          else {
            BN_CTX_start(ctx);
            if (ret->neg == 0) {
              local_34 = ret;
LAB_080fb22b:
              pBVar2 = BN_CTX_get(ctx);
              pBVar3 = BN_CTX_get(ctx);
              pBVar4 = BN_CTX_get(ctx);
              if (pBVar4 == (BIGNUM *)0x0) goto LAB_080fad32;
              pBVar7 = BN_copy(pBVar2,local_34);
              if ((pBVar7 == (BIGNUM *)0x0) || (iVar5 = BN_sub_word(pBVar2,1), iVar5 == 0))
              goto LAB_080fb2e0;
              if (pBVar2->top == 0) {
                iVar5 = 0;
                goto LAB_080fb2e5;
              }
              iVar5 = 1;
              while (iVar8 = BN_is_bit_set(pBVar2,iVar5), iVar8 == 0) {
                iVar5 = iVar5 + 1;
              }
              iVar5 = BN_rshift(pBVar3,pBVar2,iVar5);
              if ((iVar5 == 0) || (pBVar9 = BN_MONT_CTX_new(), pBVar9 == (BN_MONT_CTX *)0x0))
              goto LAB_080fb2e0;
              iVar5 = BN_MONT_CTX_set(pBVar9,local_34,ctx);
              if ((iVar5 == 0) ||
                 (((iVar5 = BN_pseudo_rand_range(pBVar4,pBVar2), iVar5 == 0 ||
                   (iVar5 = BN_add_word(pBVar4,1), iVar5 == 0)) || (iVar5 = witness(), iVar5 == -1))
                 )) {
                iVar5 = -1;
LAB_080fb58a:
                BN_CTX_end(ctx);
              }
              else {
                if (iVar5 != 0) {
                  iVar5 = 0;
                  goto LAB_080fb58a;
                }
                if (cb == (BN_GENCB *)0x0) {
LAB_080fb585:
                  iVar5 = 1;
                  goto LAB_080fb58a;
                }
                if (cb->ver == 1) {
                  if ((cb->cb).cb_1 != (_func_414 *)0x0) {
                    (*(cb->cb).cb_1)(1,0,cb->arg);
                  }
                  goto LAB_080fb585;
                }
                if ((cb->ver == 2) && (iVar5 = (*(cb->cb).cb_1)(1,0,cb), iVar5 != 0))
                goto LAB_080fb585;
                iVar5 = -1;
                BN_CTX_end(ctx);
              }
              BN_MONT_CTX_free(pBVar9);
            }
            else {
              local_34 = BN_CTX_get(ctx);
              if (local_34 != (BIGNUM *)0x0) {
                BN_copy(local_34,ret);
                local_34->neg = 0;
                goto LAB_080fb22b;
              }
LAB_080fb2e0:
              iVar5 = -1;
LAB_080fb2e5:
              BN_CTX_end(ctx);
            }
            if (iVar5 == -1) goto LAB_080fad3e;
            if (iVar5 == 0) break;
          }
          pBVar2 = BN_value_one();
          iVar5 = BN_cmp(r,pBVar2);
          if ((iVar5 < 1) || (r->top < 1)) break;
          if ((*r->d & 1) == 0) {
            if (((r->top != 1) || (*r->d != 2)) || (r->neg != 0)) break;
          }
          else {
            BN_CTX_start(ctx);
            local_34 = r;
            if (r->neg == 0) {
LAB_080fb359:
              pBVar2 = BN_CTX_get(ctx);
              pBVar3 = BN_CTX_get(ctx);
              pBVar4 = BN_CTX_get(ctx);
              if (pBVar4 == (BIGNUM *)0x0) goto LAB_080fad32;
              pBVar7 = BN_copy(pBVar2,local_34);
              if ((pBVar7 == (BIGNUM *)0x0) || (iVar5 = BN_sub_word(pBVar2,1), iVar5 == 0))
              goto LAB_080fb408;
              if (pBVar2->top == 0) {
                iVar5 = 0;
                goto LAB_080fb40d;
              }
              iVar5 = 1;
              while (iVar8 = BN_is_bit_set(pBVar2,iVar5), iVar8 == 0) {
                iVar5 = iVar5 + 1;
              }
              iVar5 = BN_rshift(pBVar3,pBVar2,iVar5);
              if ((iVar5 == 0) || (pBVar9 = BN_MONT_CTX_new(), pBVar9 == (BN_MONT_CTX *)0x0))
              goto LAB_080fb408;
              iVar5 = BN_MONT_CTX_set(pBVar9,local_34,ctx);
              if ((iVar5 == 0) ||
                 (((iVar5 = BN_pseudo_rand_range(pBVar4,pBVar2), iVar5 == 0 ||
                   (iVar5 = BN_add_word(pBVar4,1), iVar5 == 0)) || (iVar5 = witness(), iVar5 == -1))
                 )) {
                iVar5 = -1;
LAB_080fb665:
                BN_CTX_end(ctx);
              }
              else {
                if (iVar5 != 0) {
                  iVar5 = 0;
                  goto LAB_080fb665;
                }
                if (cb == (BN_GENCB *)0x0) {
LAB_080fb660:
                  iVar5 = 1;
                  goto LAB_080fb665;
                }
                if (cb->ver == 1) {
                  if ((cb->cb).cb_1 != (_func_414 *)0x0) {
                    (*(cb->cb).cb_1)(1,0,cb->arg);
                  }
                  goto LAB_080fb660;
                }
                if ((cb->ver == 2) && (iVar5 = (*(cb->cb).cb_1)(1,0,cb), iVar5 != 0))
                goto LAB_080fb660;
                iVar5 = -1;
                BN_CTX_end(ctx);
              }
              BN_MONT_CTX_free(pBVar9);
            }
            else {
              local_34 = BN_CTX_get(ctx);
              if (local_34 != (BIGNUM *)0x0) {
                BN_copy(local_34,r);
                local_34->neg = 0;
                goto LAB_080fb359;
              }
LAB_080fb408:
              iVar5 = -1;
LAB_080fb40d:
              BN_CTX_end(ctx);
            }
            if (iVar5 == -1) goto LAB_080fad3e;
            if (iVar5 == 0) break;
          }
          if (cb != (BN_GENCB *)0x0) {
            if (cb->ver == 1) {
              if ((cb->cb).cb_1 != (_func_414 *)0x0) {
                (*(cb->cb).cb_1)(2,local_3c,cb->arg);
              }
            }
            else if ((cb->ver != 2) || (iVar5 = (*(cb->cb).cb_1)(2,local_3c,cb), iVar5 == 0))
            goto LAB_080fad3e;
          }
          local_44 = local_44 + 1;
          if (local_38 == local_44) goto LAB_080fb460;
        }
      }
      local_3c = local_3c + 1;
    } while( true );
  }
LAB_080fad3e:
  iVar5 = 0;
LAB_080fad40:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar5;
LAB_080fb460:
  iVar5 = 1;
  goto LAB_080fad40;
}

