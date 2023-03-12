
int BN_generate_prime_ex(BIGNUM *ret,int bits,int safe,BIGNUM *add,BIGNUM *rem,BN_GENCB *cb)

{
  ushort uVar1;
  int iVar2;
  BN_CTX *ctx;
  BIGNUM *r;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  int iVar6;
  ulong uVar7;
  uint uVar8;
  BIGNUM *pBVar9;
  int iVar10;
  int iVar11;
  BN_MONT_CTX *pBVar12;
  ushort *puVar13;
  ushort *puVar14;
  int iVar15;
  BIGNUM *local_3c;
  ushort *local_30;
  
  if (bits < 0x514) {
    if (0x351 < bits) {
      iVar2 = 3;
      ctx = BN_CTX_new();
      goto joined_r0x004fdfb8;
    }
    if (bits < 0x28a) {
      if (bits < 0x226) {
        if (bits < 0x1c2) {
          if (bits < 400) {
            if (bits < 0x15e) {
              if (bits < 300) {
                if (bits < 0xfa) {
                  iVar2 = 0x1b;
                  if (bits < 200) {
                    if (0x95 < bits) {
                      iVar2 = 0x12;
                    }
                  }
                  else {
                    iVar2 = 0xf;
                  }
                }
                else {
                  iVar2 = 0xc;
                }
              }
              else {
                iVar2 = 9;
              }
            }
            else {
              iVar2 = 8;
            }
          }
          else {
            iVar2 = 7;
          }
        }
        else {
          iVar2 = 6;
        }
      }
      else {
        iVar2 = 5;
      }
    }
    else {
      iVar2 = 4;
    }
  }
  else {
    iVar2 = 2;
  }
  ctx = BN_CTX_new();
joined_r0x004fdfb8:
  if (ctx == (BN_CTX *)0x0) {
    return 0;
  }
  BN_CTX_start(ctx);
  r = BN_CTX_get(ctx);
  if (r == (BIGNUM *)0x0) {
LAB_004fde70:
    iVar2 = 0;
  }
  else {
    iVar15 = 0;
    local_30 = (ushort *)(primes + 2);
LAB_004fdde4:
    if (add != (BIGNUM *)0x0) {
      if (safe == 0) {
        BN_CTX_start(ctx);
        pBVar3 = BN_CTX_get(ctx);
        if ((((pBVar3 != (BIGNUM *)0x0) && (iVar6 = BN_rand(ret,bits,0,1), iVar6 != 0)) &&
            (iVar6 = (*(code *)PTR_BN_div_006a967c)(0,pBVar3,ret,add,ctx), iVar6 != 0)) &&
           (iVar6 = (*(code *)PTR_BN_sub_006a96cc)(ret,ret,pBVar3), iVar6 != 0)) {
          pBVar3 = rem;
          if (rem == (BIGNUM *)0x0) {
            iVar6 = BN_add_word(ret,1);
            goto joined_r0x004fe868;
          }
          while( true ) {
            iVar6 = (*(code *)PTR_BN_add_006a96c8)(ret,ret,pBVar3);
joined_r0x004fe868:
            puVar13 = local_30;
            if (iVar6 == 0) break;
            while( true ) {
              puVar14 = puVar13 + 1;
              uVar7 = BN_mod_word(ret,(uint)*puVar13);
              pBVar3 = add;
              if (uVar7 < 2) break;
              puVar13 = puVar14;
              if (puVar14 == (ushort *)"bn_recp.c") {
                BN_CTX_end(ctx);
                if (cb == (BN_GENCB *)0x0) goto LAB_004fe1c0;
                uVar8 = cb->ver;
                goto LAB_004fe188;
              }
            }
          }
        }
      }
      else {
        BN_CTX_start(ctx);
        pBVar3 = BN_CTX_get(ctx);
        pBVar4 = BN_CTX_get(ctx);
        pBVar5 = BN_CTX_get(ctx);
        if (((pBVar5 != (BIGNUM *)0x0) && (iVar6 = BN_rshift1(pBVar5,add), iVar6 != 0)) &&
           ((iVar6 = BN_rand(pBVar4,bits + -1,0,1), iVar6 != 0 &&
            ((iVar6 = (*(code *)PTR_BN_div_006a967c)(0,pBVar3,pBVar4,pBVar5,ctx), iVar6 != 0 &&
             (iVar6 = (*(code *)PTR_BN_sub_006a96cc)(pBVar4,pBVar4,pBVar3), iVar6 != 0)))))) {
          if (rem == (BIGNUM *)0x0) {
            iVar6 = BN_add_word(pBVar4,1);
          }
          else {
            iVar6 = BN_rshift1(pBVar3,rem);
            if (iVar6 == 0) goto LAB_004fde64;
            iVar6 = (*(code *)PTR_BN_add_006a96c8)(pBVar4,pBVar4,pBVar3);
          }
          if (((iVar6 != 0) && (iVar6 = BN_lshift1(ret,pBVar4), iVar6 != 0)) &&
             (iVar6 = BN_add_word(ret,1), puVar13 = local_30, iVar6 != 0)) {
            do {
              while( true ) {
                uVar1 = *puVar13;
                puVar13 = puVar13 + 1;
                uVar7 = BN_mod_word(ret,(uint)uVar1);
                if ((uVar7 != 0) && (uVar7 = BN_mod_word(pBVar4,(uint)uVar1), uVar7 != 0)) break;
                iVar6 = (*(code *)PTR_BN_add_006a96c8)(ret,ret,add);
                if ((iVar6 == 0) ||
                   (iVar6 = (*(code *)PTR_BN_add_006a96c8)(pBVar4,pBVar4,pBVar5), puVar13 = local_30
                   , iVar6 == 0)) goto LAB_004fde64;
              }
            } while (puVar13 != (ushort *)"bn_recp.c");
            BN_CTX_end(ctx);
            if (cb != (BN_GENCB *)0x0) goto LAB_004fe184;
            goto LAB_004fe388;
          }
        }
      }
LAB_004fde64:
      BN_CTX_end(ctx);
      goto LAB_004fde70;
    }
    iVar6 = probable_prime(ret,bits);
    if (iVar6 == 0) goto LAB_004fde70;
    if (cb != (BN_GENCB *)0x0) {
LAB_004fe184:
      uVar8 = cb->ver;
LAB_004fe188:
      if (uVar8 == 1) {
        if ((cb->cb).cb_1 != (_func_414 *)0x0) {
          (*(cb->cb).cb_1)(0,iVar15,cb->arg);
        }
      }
      else if ((uVar8 != 2) || (iVar6 = (*(cb->cb).cb_1)(0,iVar15,cb), iVar6 == 0))
      goto LAB_004fde70;
    }
    if (safe != 0) {
LAB_004fe388:
      iVar6 = BN_rshift1(r,ret);
      if (iVar6 != 0) goto code_r0x004fe39c;
      goto LAB_004fde70;
    }
LAB_004fe1c0:
    iVar6 = BN_is_prime_fasttest_ex(ret,iVar2,ctx,0,cb);
    if (iVar6 == -1) goto LAB_004fde70;
    if (iVar6 == 0) goto LAB_004fe1ec;
LAB_004fe36c:
    iVar2 = 1;
  }
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar2;
code_r0x004fe39c:
  iVar6 = 0;
  while( true ) {
    pBVar3 = BN_value_one();
    iVar11 = BN_cmp(ret,pBVar3);
    if ((iVar11 < 1) || (ret->top < 1)) break;
    if ((*ret->d & 1) == 0) {
      if (((ret->top != 1) || (*ret->d != 2)) || (ret->neg != 0)) break;
    }
    else {
      BN_CTX_start(ctx);
      local_3c = ret;
      if (ret->neg == 0) {
LAB_004fe4c0:
        pBVar3 = BN_CTX_get(ctx);
        pBVar4 = BN_CTX_get(ctx);
        pBVar5 = BN_CTX_get(ctx);
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_004fde64;
        pBVar9 = BN_copy(pBVar3,local_3c);
        if ((pBVar9 == (BIGNUM *)0x0) || (iVar11 = BN_sub_word(pBVar3,1), iVar11 == 0))
        goto LAB_004fe588;
        iVar11 = 1;
        if (pBVar3->top == 0) {
          iVar11 = 0;
          goto LAB_004fe58c;
        }
        while (iVar10 = BN_is_bit_set(pBVar3,iVar11), iVar10 == 0) {
          iVar11 = iVar11 + 1;
        }
        iVar10 = BN_rshift(pBVar4,pBVar3,iVar11);
        if ((iVar10 == 0) || (pBVar12 = BN_MONT_CTX_new(), pBVar12 == (BN_MONT_CTX *)0x0))
        goto LAB_004fe588;
        iVar10 = BN_MONT_CTX_set(pBVar12,local_3c,ctx);
        if ((iVar10 == 0) ||
           (((iVar10 = BN_pseudo_rand_range(pBVar5,pBVar3), iVar10 == 0 ||
             (iVar10 = BN_add_word(pBVar5,1), iVar10 == 0)) ||
            (iVar11 = witness(pBVar5,local_3c,pBVar3,pBVar4,iVar11,ctx,pBVar12), iVar11 == -1)))) {
          iVar11 = -1;
LAB_004fe6a4:
          BN_CTX_end(ctx);
        }
        else {
          if (iVar11 != 0) {
            iVar11 = 0;
            goto LAB_004fe6a4;
          }
          if (cb == (BN_GENCB *)0x0) {
LAB_004fe6a0:
            iVar11 = 1;
            goto LAB_004fe6a4;
          }
          if (cb->ver == 1) {
            if ((cb->cb).cb_1 != (_func_414 *)0x0) {
              (*(cb->cb).cb_1)(1,0,cb->arg);
            }
            goto LAB_004fe6a0;
          }
          if (cb->ver == 2) {
            iVar11 = (*(cb->cb).cb_1)(1,0,cb);
            if (iVar11 != 0) goto LAB_004fe6a0;
            iVar11 = -1;
            BN_CTX_end(ctx);
          }
          else {
            iVar11 = -1;
            BN_CTX_end(ctx);
          }
        }
        BN_MONT_CTX_free(pBVar12);
      }
      else {
        local_3c = BN_CTX_get(ctx);
        if (local_3c != (BIGNUM *)0x0) {
          BN_copy(local_3c,ret);
          local_3c->neg = 0;
          goto LAB_004fe4c0;
        }
LAB_004fe588:
        iVar11 = -1;
LAB_004fe58c:
        BN_CTX_end(ctx);
      }
      if (iVar11 == -1) goto LAB_004fde70;
      if (iVar11 == 0) {
        iVar15 = iVar15 + 1;
        goto LAB_004fdde4;
      }
    }
    pBVar3 = BN_value_one();
    iVar11 = BN_cmp(r,pBVar3);
    if ((iVar11 < 1) || (r->top < 1)) break;
    if ((*r->d & 1) == 0) {
      if ((r->top != 1) || (*r->d != 2)) break;
      if (r->neg != 0) {
        iVar15 = iVar15 + 1;
        goto LAB_004fdde4;
      }
    }
    else {
      BN_CTX_start(ctx);
      local_3c = r;
      if (r->neg == 0) {
LAB_004fe23c:
        pBVar3 = BN_CTX_get(ctx);
        pBVar4 = BN_CTX_get(ctx);
        pBVar5 = BN_CTX_get(ctx);
        if (pBVar5 == (BIGNUM *)0x0) goto LAB_004fde64;
        pBVar9 = BN_copy(pBVar3,local_3c);
        if ((pBVar9 == (BIGNUM *)0x0) || (iVar11 = BN_sub_word(pBVar3,1), iVar11 == 0))
        goto LAB_004fe304;
        iVar11 = 1;
        if (pBVar3->top == 0) {
          iVar11 = 0;
          goto LAB_004fe308;
        }
        while (iVar10 = BN_is_bit_set(pBVar3,iVar11), iVar10 == 0) {
          iVar11 = iVar11 + 1;
        }
        iVar10 = BN_rshift(pBVar4,pBVar3,iVar11);
        if ((iVar10 == 0) || (pBVar12 = BN_MONT_CTX_new(), pBVar12 == (BN_MONT_CTX *)0x0))
        goto LAB_004fe304;
        iVar10 = BN_MONT_CTX_set(pBVar12,local_3c,ctx);
        if ((iVar10 == 0) ||
           (((iVar10 = BN_pseudo_rand_range(pBVar5,pBVar3), iVar10 == 0 ||
             (iVar10 = BN_add_word(pBVar5,1), iVar10 == 0)) ||
            (iVar11 = witness(pBVar5,local_3c,pBVar3,pBVar4,iVar11,ctx,pBVar12), iVar11 == -1)))) {
          iVar11 = -1;
LAB_004fe7bc:
          BN_CTX_end(ctx);
        }
        else {
          if (iVar11 != 0) {
            iVar11 = 0;
            goto LAB_004fe7bc;
          }
          if (cb == (BN_GENCB *)0x0) {
LAB_004fe7b8:
            iVar11 = 1;
            goto LAB_004fe7bc;
          }
          if (cb->ver == 1) {
            if ((cb->cb).cb_1 != (_func_414 *)0x0) {
              (*(cb->cb).cb_1)(1,0,cb->arg);
            }
            goto LAB_004fe7b8;
          }
          if (cb->ver == 2) {
            iVar11 = (*(cb->cb).cb_1)(1,0,cb);
            if (iVar11 != 0) goto LAB_004fe7b8;
            iVar11 = -1;
            BN_CTX_end(ctx);
          }
          else {
            iVar11 = -1;
            BN_CTX_end(ctx);
          }
        }
        BN_MONT_CTX_free(pBVar12);
      }
      else {
        local_3c = BN_CTX_get(ctx);
        if (local_3c != (BIGNUM *)0x0) {
          BN_copy(local_3c,r);
          local_3c->neg = 0;
          goto LAB_004fe23c;
        }
LAB_004fe304:
        iVar11 = -1;
LAB_004fe308:
        BN_CTX_end(ctx);
      }
      if (iVar11 == -1) goto LAB_004fde70;
      if (iVar11 == 0) break;
    }
    if (cb != (BN_GENCB *)0x0) {
      if (cb->ver == 1) {
        if ((cb->cb).cb_1 != (_func_414 *)0x0) {
          (*(cb->cb).cb_1)(2,iVar15,cb->arg);
        }
      }
      else if ((cb->ver != 2) || (iVar11 = (*(cb->cb).cb_1)(2,iVar15,cb), iVar11 == 0))
      goto LAB_004fde70;
    }
    iVar6 = iVar6 + 1;
    if (iVar2 == iVar6) goto LAB_004fe36c;
  }
LAB_004fe1ec:
  iVar15 = iVar15 + 1;
  goto LAB_004fdde4;
}

