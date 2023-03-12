
BIGNUM * BN_mod_sqrt(BIGNUM *ret,BIGNUM *a,BIGNUM *n,BN_CTX *ctx)

{
  code *pcVar1;
  ulong uVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *r_01;
  int iVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  BIGNUM *r_02;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar8 = n->top;
  if (iVar8 < 1) {
LAB_0011f15a:
    ERR_put_error(3,0x79,0x70,"bn_sqrt.c",0x5e);
    return (BIGNUM *)0x0;
  }
  uVar9 = *n->d;
  if ((uVar9 & 1) == 0) {
    if ((iVar8 != 1) || (uVar9 != 2)) goto LAB_0011f15a;
    if (ret != (BIGNUM *)0x0) {
      uVar2 = BN_is_bit_set(a,0);
      iVar8 = BN_set_word(ret,uVar2);
      if (iVar8 != 0) {
        return ret;
      }
      return (BIGNUM *)0x0;
    }
    pBVar7 = BN_new();
    if (pBVar7 != (BIGNUM *)0x0) {
      uVar2 = BN_is_bit_set(a,0);
      iVar8 = BN_set_word(pBVar7,uVar2);
      if (iVar8 != 0) {
        return pBVar7;
      }
      BN_free(pBVar7);
      return (BIGNUM *)0x0;
    }
  }
  else {
    if ((iVar8 == 1) && (uVar9 == 1)) goto LAB_0011f15a;
    iVar8 = a->top;
    if ((iVar8 == 0) || (((iVar8 == 1 && (*a->d == 1)) && (a->neg == 0)))) {
      pBVar7 = ret;
      if (ret != (BIGNUM *)0x0) {
LAB_0011f12e:
        if ((iVar8 == 1) && (*a->d == 1)) {
          uVar9 = count_leading_zeroes(a->neg);
          uVar2 = uVar9 >> 5;
        }
        else {
          uVar2 = 0;
        }
        pBVar3 = (BIGNUM *)BN_set_word(pBVar7,uVar2);
        pBVar4 = pBVar7;
        if ((pBVar3 == (BIGNUM *)0x0) && (pBVar4 = pBVar3, pBVar7 != ret)) {
          BN_free(pBVar7);
        }
        return pBVar4;
      }
      pBVar7 = BN_new();
      if (pBVar7 != (BIGNUM *)0x0) {
        iVar8 = a->top;
        goto LAB_0011f12e;
      }
    }
    else {
      BN_CTX_start(ctx);
      pBVar7 = BN_CTX_get(ctx);
      pBVar4 = BN_CTX_get(ctx);
      pBVar3 = BN_CTX_get(ctx);
      r = BN_CTX_get(ctx);
      r_00 = BN_CTX_get(ctx);
      r_01 = BN_CTX_get(ctx);
      if ((r_01 != (BIGNUM *)0x0) &&
         ((r_02 = ret, ret != (BIGNUM *)0x0 || (r_02 = BN_new(), r_02 != (BIGNUM *)0x0)))) {
        iVar5 = BN_nnmod(pBVar7,a,n,ctx);
        iVar8 = 1;
        if (iVar5 != 0) {
          while (iVar5 = BN_is_bit_set(n,iVar8), iVar5 == 0) {
            iVar8 = iVar8 + 1;
          }
          if (iVar8 == 1) {
            iVar8 = BN_rshift(pBVar3,n,2);
            if (iVar8 != 0) {
              pBVar3->neg = 0;
              iVar8 = BN_add_word(pBVar3,1);
              if (iVar8 != 0) {
                pBVar4 = (BIGNUM *)BN_mod_exp(r_02,pBVar7,pBVar3,n,ctx);
joined_r0x0011f3f2:
                if ((pBVar4 != (BIGNUM *)0x0) && (iVar8 = BN_mod_sqr(r_00,r_02,n,ctx), iVar8 != 0))
                {
                  iVar8 = BN_cmp(r_00,pBVar7);
                  if (iVar8 == 0) goto LAB_0011f1de;
                  iVar8 = 0x178;
LAB_0011f3a0:
                  ERR_put_error(3,0x79,0x6f,"bn_sqrt.c",iVar8);
                }
              }
            }
          }
          else if (iVar8 == 2) {
            iVar8 = BN_mod_lshift1_quick(r,pBVar7,n);
            if ((iVar8 != 0) && (iVar8 = BN_rshift(pBVar3,n,3), iVar8 != 0)) {
              pBVar3->neg = 0;
              iVar8 = BN_mod_exp(pBVar4,r,pBVar3,n,ctx);
              if ((iVar8 != 0) &&
                 ((((iVar8 = BN_mod_sqr(r_01,pBVar4,n,ctx), iVar8 != 0 &&
                    (iVar8 = BN_mod_mul(r,r,r_01,n,ctx), iVar8 != 0)) &&
                   (iVar8 = BN_sub_word(r,1), iVar8 != 0)) &&
                  ((iVar8 = BN_mod_mul(r_00,pBVar7,pBVar4,n,ctx), iVar8 != 0 &&
                   (iVar8 = BN_mod_mul(r_00,r_00,r,n,ctx), iVar8 != 0)))))) {
LAB_0011f36a:
                pBVar4 = BN_copy(r_02,r_00);
                goto joined_r0x0011f3f2;
              }
            }
          }
          else {
            pBVar6 = BN_copy(pBVar3,n);
            if (pBVar6 != (BIGNUM *)0x0) {
              uVar2 = 2;
              pBVar3->neg = 0;
              do {
                if ((int)uVar2 < 0x16) {
LAB_0011f260:
                  iVar5 = BN_set_word(r_01,uVar2);
                  if (iVar5 == 0) goto LAB_0011f1d6;
                }
                else {
                  iVar5 = BN_num_bits(n);
                  iVar5 = BN_pseudo_rand(r_01,iVar5,0,0);
                  if (iVar5 == 0) goto LAB_0011f1d6;
                  iVar5 = BN_ucmp(r_01,n);
                  if (-1 < iVar5) {
                    pcVar1 = BN_sub;
                    if (n->neg != 0) {
                      pcVar1 = BN_add;
                    }
                    iVar5 = (*(pcVar1 + 1))(r_01,r_01,n);
                    if (iVar5 == 0) goto LAB_0011f1d6;
                  }
                  if (r_01->top == 0) goto LAB_0011f260;
                }
                iVar5 = BN_kronecker(r_01,pBVar3,ctx);
                if (iVar5 + 1 < 0 != SCARRY4(iVar5,1)) goto LAB_0011f1d6;
                if (iVar5 == 0) {
                  iVar8 = 0xec;
LAB_0011f416:
                  ERR_put_error(3,0x79,0x70,"bn_sqrt.c",iVar8);
                  goto LAB_0011f1d6;
                }
                if (iVar5 != 1) {
                  if (iVar5 == -1) {
                    iVar5 = BN_rshift(pBVar3,pBVar3,iVar8);
                    if ((iVar5 == 0) || (iVar5 = BN_mod_exp(r_01,r_01,pBVar3,n,ctx), iVar5 == 0))
                    goto LAB_0011f1d6;
                    if ((r_01->top == 1) && ((*r_01->d == 1 && (r_01->neg == 0)))) {
                      iVar8 = 0x105;
                      goto LAB_0011f416;
                    }
                    iVar5 = BN_rshift1(r,pBVar3);
                    if (iVar5 == 0) goto LAB_0011f1d6;
                    if (r->top == 0) {
                      iVar5 = BN_nnmod(r,pBVar7,n,ctx);
                      if (iVar5 == 0) goto LAB_0011f1d6;
                      uVar2 = r->top;
                      if (uVar2 == 0) {
LAB_0011f562:
                        BN_set_word(r_02,uVar2);
                        goto LAB_0011f1de;
                      }
                      iVar5 = BN_set_word(r_00,1);
                      if (iVar5 == 0) goto LAB_0011f1d6;
                    }
                    else {
                      iVar5 = BN_mod_exp(r_00,pBVar7,r,n,ctx);
                      if (iVar5 == 0) goto LAB_0011f1d6;
                      uVar2 = r_00->top;
                      if (uVar2 == 0) goto LAB_0011f562;
                    }
                    iVar5 = BN_mod_sqr(pBVar4,r_00,n,ctx);
                    if ((iVar5 == 0) || (iVar5 = BN_mod_mul(pBVar4,pBVar4,pBVar7,n,ctx), iVar5 == 0)
                       ) goto LAB_0011f1d6;
                    iVar5 = BN_mod_mul(r_00,r_00,pBVar7,n,ctx);
                    goto joined_r0x0011f4e0;
                  }
                  break;
                }
                uVar2 = uVar2 + 1;
              } while (uVar2 != 0x52);
              ERR_put_error(3,0x79,0x71,"bn_sqrt.c",0xf9);
            }
          }
        }
LAB_0011f1d6:
        if (ret != r_02) {
          BN_clear_free(r_02);
          r_02 = (BIGNUM *)0x0;
          goto LAB_0011f1de;
        }
      }
    }
  }
  r_02 = (BIGNUM *)0x0;
LAB_0011f1de:
  BN_CTX_end(ctx);
  return r_02;
joined_r0x0011f4e0:
  if (iVar5 == 0) goto LAB_0011f1d6;
  if (((pBVar4->top == 1) && (*pBVar4->d == 1)) && (pBVar4->neg == 0)) goto LAB_0011f36a;
  iVar5 = BN_mod_sqr(r,pBVar4,n,ctx);
  if (iVar5 == 0) goto LAB_0011f1d6;
  iVar10 = 1;
  while (((r->top != 1 || (*r->d != 1)) || (r->neg != 0))) {
    iVar10 = iVar10 + 1;
    if (iVar10 == iVar8) {
      iVar8 = 0x15a;
      goto LAB_0011f3a0;
    }
    iVar5 = BN_mod_mul(r,r,r,n,ctx);
    if (iVar5 == 0) goto LAB_0011f1d6;
  }
  pBVar3 = BN_copy(r,r_01);
  if (pBVar3 == (BIGNUM *)0x0) goto LAB_0011f1d6;
  iVar8 = iVar8 - iVar10;
  while (iVar8 = iVar8 + -1, 0 < iVar8) {
    iVar5 = BN_mod_sqr(r,r,n,ctx);
    if (iVar5 == 0) goto LAB_0011f1d6;
  }
  iVar8 = BN_mod_mul(r_01,r,r,n,ctx);
  if ((iVar8 == 0) || (iVar8 = BN_mod_mul(r_00,r_00,r,n,ctx), iVar8 == 0)) goto LAB_0011f1d6;
  iVar5 = BN_mod_mul(pBVar4,pBVar4,r_01,n,ctx);
  iVar8 = iVar10;
  goto joined_r0x0011f4e0;
}

