
BIGNUM * BN_mod_sqrt(BIGNUM *ret,BIGNUM *a,BIGNUM *n,BN_CTX *ctx)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  int iVar6;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  code *pcVar9;
  undefined4 extraout_EDX;
  BIGNUM *local_38;
  int local_30;
  
  iVar3 = n->top;
  if (iVar3 < 1) goto LAB_081df218;
  uVar1 = *n->d;
  if ((uVar1 & 1) == 0) {
    if (iVar3 != 1) goto LAB_081df218;
LAB_081df1d4:
    if (uVar1 != 2) {
LAB_081df218:
      ERR_put_error(3,0x79,0x70,"bn_sqrt.c",0x5b);
      return (BIGNUM *)0x0;
    }
    if (ret != (BIGNUM *)0x0) {
      uVar2 = BN_is_bit_set(a,0);
      iVar3 = BN_set_word(ret,uVar2);
joined_r0x081df41f:
      if (iVar3 == 0) {
        return (BIGNUM *)0x0;
      }
      return ret;
    }
    pBVar8 = BN_new();
    if (pBVar8 != (BIGNUM *)0x0) {
      uVar2 = BN_is_bit_set(a,0);
      iVar3 = BN_set_word(pBVar8,uVar2);
      if (iVar3 != 0) {
        return pBVar8;
      }
LAB_081df460:
      BN_free(pBVar8);
      return (BIGNUM *)0x0;
    }
  }
  else {
    if ((iVar3 == 1) && (uVar1 == 1)) goto LAB_081df1d4;
    if (a->top == 0) {
      if (ret != (BIGNUM *)0x0) {
        iVar3 = BN_set_word(ret,0);
        goto joined_r0x081df41f;
      }
LAB_081df4c0:
      pBVar8 = BN_new();
      if (pBVar8 != (BIGNUM *)0x0) {
        if ((a->top == 1) && (*a->d == 1)) goto LAB_081df48f;
LAB_081df4dc:
        uVar2 = 0;
LAB_081df4a0:
        iVar3 = BN_set_word(pBVar8,uVar2);
        if (iVar3 != 0) {
          return pBVar8;
        }
        if (ret == pBVar8) {
          return (BIGNUM *)0x0;
        }
        goto LAB_081df460;
      }
    }
    else {
      if (((a->top == 1) && (*a->d == 1)) && (a->neg == 0)) {
        pBVar8 = ret;
        if (ret == (BIGNUM *)0x0) goto LAB_081df4c0;
LAB_081df48f:
        uVar2 = 1;
        if (a->neg != 0) goto LAB_081df4dc;
        goto LAB_081df4a0;
      }
      BN_CTX_start(ctx);
      pBVar8 = BN_CTX_get(ctx);
      pBVar4 = BN_CTX_get(ctx);
      pBVar5 = BN_CTX_get(ctx);
      r = BN_CTX_get(ctx);
      r_00 = BN_CTX_get(ctx);
      r_01 = BN_CTX_get(ctx);
      if (r_01 != (BIGNUM *)0x0) {
        if (ret == (BIGNUM *)0x0) {
          local_38 = BN_new();
          if (local_38 != (BIGNUM *)0x0) {
            iVar3 = BN_nnmod(pBVar8,a,n,ctx);
            if (iVar3 != 0) goto LAB_081df2fc;
LAB_081df3c2:
            BN_clear_free(local_38);
          }
        }
        else {
          iVar3 = BN_nnmod(pBVar8,a,n,ctx);
          if (iVar3 != 0) {
            local_38 = ret;
LAB_081df2fc:
            iVar3 = 1;
            while (iVar6 = BN_is_bit_set(n,iVar3), iVar6 == 0) {
              iVar3 = iVar3 + 1;
            }
            if (iVar3 == 1) {
              iVar3 = BN_rshift(pBVar5,n,2);
              if (iVar3 != 0) {
                pBVar5->neg = 0;
                iVar3 = BN_add_word(pBVar5,1);
                if (iVar3 != 0) {
                  pBVar4 = (BIGNUM *)BN_mod_exp(local_38,pBVar8,pBVar5,n,ctx);
joined_r0x081df6d9:
                  if ((pBVar4 != (BIGNUM *)0x0) &&
                     (iVar3 = BN_mod_sqr(r_00,local_38,n,ctx), iVar3 != 0)) {
                    iVar3 = BN_cmp(r_00,pBVar8);
                    if (iVar3 == 0) goto LAB_081df3e0;
                    iVar3 = 0x18a;
LAB_081df632:
                    ERR_put_error(3,0x79,0x6f,"bn_sqrt.c",iVar3);
                  }
                }
              }
            }
            else if (iVar3 == 2) {
              iVar3 = BN_mod_lshift1_quick(r,pBVar8,n);
              if ((iVar3 != 0) && (iVar3 = BN_rshift(pBVar5,n,3), iVar3 != 0)) {
                pBVar5->neg = 0;
                iVar3 = BN_mod_exp(pBVar4,r,pBVar5,n,ctx);
                if ((((iVar3 != 0) &&
                     ((iVar3 = BN_mod_sqr(r_01,pBVar4,n,ctx), iVar3 != 0 &&
                      (iVar3 = BN_mod_mul(r,r,r_01,n,ctx), iVar3 != 0)))) &&
                    (iVar3 = BN_sub_word(r,1), iVar3 != 0)) &&
                   ((iVar3 = BN_mod_mul(r_00,pBVar8,pBVar4,n,ctx), iVar3 != 0 &&
                    (iVar3 = BN_mod_mul(r_00,r_00,r,n,ctx), iVar3 != 0)))) {
LAB_081df5d9:
                  pBVar4 = BN_copy(local_38,r_00);
                  goto joined_r0x081df6d9;
                }
              }
            }
            else {
              pBVar7 = BN_copy(pBVar5,n);
              if (pBVar7 != (BIGNUM *)0x0) {
                pBVar5->neg = 0;
                uVar2 = 2;
                do {
                  if ((int)uVar2 < 0x16) {
LAB_081df3a1:
                    iVar6 = BN_set_word(r_01,uVar2);
                    if (iVar6 == 0) goto LAB_081df3b8;
                  }
                  else {
                    iVar6 = BN_num_bits(n);
                    iVar6 = BN_pseudo_rand(r_01,iVar6,0,0);
                    if (iVar6 == 0) goto LAB_081df3b8;
                    iVar6 = BN_ucmp(r_01,n);
                    if (-1 < iVar6) {
                      pcVar9 = BN_add;
                      if (n->neg == 0) {
                        pcVar9 = BN_sub;
                      }
                      iVar6 = (*pcVar9)(r_01,r_01,n,extraout_EDX);
                      if (iVar6 == 0) goto LAB_081df3b8;
                    }
                    if (r_01->top == 0) goto LAB_081df3a1;
                  }
                  iVar6 = BN_kronecker(r_01,pBVar5,ctx);
                  if (iVar6 < -1) goto LAB_081df3b8;
                  if (iVar6 == 0) {
                    iVar3 = 0xf9;
LAB_081df710:
                    ERR_put_error(3,0x79,0x70,"bn_sqrt.c",iVar3);
                    goto LAB_081df3b8;
                  }
                  if (iVar6 != 1) {
                    if (iVar6 == -1) {
                      iVar6 = BN_rshift(pBVar5,pBVar5,iVar3);
                      if ((iVar6 == 0) || (iVar6 = BN_mod_exp(r_01,r_01,pBVar5,n,ctx), iVar6 == 0))
                      goto LAB_081df3b8;
                      if ((r_01->top == 1) && ((*r_01->d == 1 && (r_01->neg == 0)))) {
                        iVar3 = 0x114;
                        goto LAB_081df710;
                      }
                      iVar6 = BN_rshift1(r,pBVar5);
                      if (iVar6 == 0) goto LAB_081df3b8;
                      if (r->top == 0) {
                        iVar6 = BN_nnmod(r,pBVar8,n,ctx);
                        if (iVar6 == 0) goto LAB_081df3b8;
                        if (r->top == 0) {
LAB_081df8da:
                          BN_set_word(local_38,0);
                          goto LAB_081df3e0;
                        }
                        iVar6 = BN_set_word(r_00,1);
                        if (iVar6 == 0) goto LAB_081df3b8;
                      }
                      else {
                        iVar6 = BN_mod_exp(r_00,pBVar8,r,n,ctx);
                        if (iVar6 == 0) goto LAB_081df3b8;
                        if (r_00->top == 0) goto LAB_081df8da;
                      }
                      iVar6 = BN_mod_sqr(pBVar4,r_00,n,ctx);
                      if ((iVar6 == 0) ||
                         (iVar6 = BN_mod_mul(pBVar4,pBVar4,pBVar8,n,ctx), iVar6 == 0))
                      goto LAB_081df3b8;
                      iVar6 = BN_mod_mul(r_00,r_00,pBVar8,n,ctx);
                      goto joined_r0x081df83b;
                    }
                    break;
                  }
                  uVar2 = uVar2 + 1;
                } while (uVar2 != 0x52);
                ERR_put_error(3,0x79,0x71,"bn_sqrt.c",0x105);
              }
            }
LAB_081df3b8:
            if (ret != local_38) goto LAB_081df3c2;
          }
        }
      }
    }
  }
  local_38 = (BIGNUM *)0x0;
LAB_081df3e0:
  BN_CTX_end(ctx);
  return local_38;
joined_r0x081df83b:
  if (iVar6 == 0) goto LAB_081df3b8;
  if (((pBVar4->top == 1) && (*pBVar4->d == 1)) && (pBVar4->neg == 0)) goto LAB_081df5d9;
  iVar6 = BN_mod_sqr(r,pBVar4,n,ctx);
  if (iVar6 == 0) goto LAB_081df3b8;
  local_30 = 1;
  while (((r->top != 1 || (*r->d != 1)) || (r->neg != 0))) {
    local_30 = local_30 + 1;
    if (iVar3 == local_30) {
      iVar3 = 0x168;
      goto LAB_081df632;
    }
    iVar6 = BN_mod_mul(r,r,r,n,ctx);
    if (iVar6 == 0) goto LAB_081df3b8;
  }
  pBVar5 = BN_copy(r,r_01);
  if (pBVar5 == (BIGNUM *)0x0) goto LAB_081df3b8;
  iVar3 = iVar3 - local_30;
  while (iVar3 = iVar3 + -1, 0 < iVar3) {
    iVar6 = BN_mod_sqr(r,r,n,ctx);
    if (iVar6 == 0) goto LAB_081df3b8;
  }
  iVar3 = BN_mod_mul(r_01,r,r,n,ctx);
  if ((iVar3 == 0) || (iVar3 = BN_mod_mul(r_00,r_00,r,n,ctx), iVar3 == 0)) goto LAB_081df3b8;
  iVar6 = BN_mod_mul(pBVar4,pBVar4,r_01,n,ctx);
  iVar3 = local_30;
  goto joined_r0x081df83b;
}
