
int BN_mod_exp2_mont(BIGNUM *r,BIGNUM *a1,BIGNUM *p1,BIGNUM *a2,BIGNUM *p2,BIGNUM *m,BN_CTX *ctx,
                    BN_MONT_CTX *m_ctx)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  BIGNUM *pBVar4;
  BIGNUM *r_00;
  BIGNUM *pBVar5;
  BIGNUM *rem;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  BIGNUM *b;
  BIGNUM **ppBVar10;
  int iVar11;
  int n;
  int iVar12;
  BIGNUM *local_15c;
  uint local_158;
  BN_MONT_CTX *local_150;
  int local_14c;
  int local_148;
  int local_144;
  int local_140;
  BIGNUM *local_128 [32];
  BIGNUM *local_a8 [33];
  
  if ((*m->d & 1) == 0) {
    ERR_put_error(3,0x76,0x66,"bn_exp2.c",0x8a);
    return 0;
  }
  uVar2 = BN_num_bits(p1);
  uVar3 = BN_num_bits(p2);
  if ((uVar3 | uVar2) == 0) {
    iVar6 = BN_set_word(r,1);
    return iVar6;
  }
  BN_CTX_start(ctx);
  pBVar4 = BN_CTX_get(ctx);
  r_00 = BN_CTX_get(ctx);
  pBVar5 = BN_CTX_get(ctx);
  local_128[0] = pBVar5;
  rem = BN_CTX_get(ctx);
  local_a8[0] = rem;
  if (((r_00 == (BIGNUM *)0x0 || pBVar4 == (BIGNUM *)0x0) || (pBVar5 == (BIGNUM *)0x0)) ||
     (rem == (BIGNUM *)0x0)) {
LAB_00102128:
    iVar6 = 0;
    goto LAB_0010212a;
  }
  if (m_ctx == (BN_MONT_CTX *)0x0) {
    local_150 = BN_MONT_CTX_new();
    if (local_150 == (BN_MONT_CTX *)0x0) goto LAB_00102128;
    iVar6 = BN_MONT_CTX_set(local_150,m,ctx);
    if (iVar6 != 0) goto LAB_001020f4;
  }
  else {
    local_150 = m_ctx;
LAB_001020f4:
    if ((int)uVar2 < 0x2a0) {
      if ((int)uVar2 < 0xf0) {
        if ((int)uVar2 < 0x50) {
          if ((int)uVar2 < 0x18) {
            local_148 = 1;
            local_14c = 1;
          }
          else {
            local_148 = 4;
            local_14c = 3;
          }
        }
        else {
          local_148 = 8;
          local_14c = 4;
        }
      }
      else {
        local_148 = 0x10;
        local_14c = 5;
      }
    }
    else {
      local_148 = 0x20;
      local_14c = 6;
    }
    if ((int)uVar3 < 0x2a0) {
      if ((int)uVar3 < 0xf0) {
        if ((int)uVar3 < 0x50) {
          if ((int)uVar3 < 0x18) {
            local_144 = 1;
            local_140 = 1;
          }
          else {
            local_144 = 4;
            local_140 = 3;
          }
        }
        else {
          local_144 = 8;
          local_140 = 4;
        }
      }
      else {
        local_144 = 0x10;
        local_140 = 5;
      }
    }
    else {
      local_144 = 0x20;
      local_140 = 6;
    }
    if (((a1->neg == 0) && (iVar6 = BN_ucmp(a1,m), iVar6 < 0)) ||
       (iVar6 = BN_div((BIGNUM *)0x0,pBVar5,a1,m,ctx), a1 = pBVar5, iVar6 != 0)) {
      if (a1->top != 0) {
        b = &local_150->RR;
        iVar6 = BN_mod_mul_montgomery(pBVar5,a1,b,local_150,ctx);
        if (iVar6 != 0) {
          if (local_14c != 1) {
            iVar6 = BN_mod_mul_montgomery(pBVar4,pBVar5,pBVar5,local_150,ctx);
            if (iVar6 == 0) goto LAB_00102296;
            iVar6 = 1;
            ppBVar10 = local_128;
            do {
              iVar6 = iVar6 + 1;
              pBVar5 = BN_CTX_get(ctx);
              ppBVar10[1] = pBVar5;
              if ((pBVar5 == (BIGNUM *)0x0) ||
                 (iVar7 = BN_mod_mul_montgomery(pBVar5,*ppBVar10,pBVar4,local_150,ctx), iVar7 == 0))
              goto LAB_00102296;
              ppBVar10 = ppBVar10 + 1;
            } while (iVar6 < local_148);
          }
          if (((a2->neg == 0) && (iVar6 = BN_ucmp(a2,m), local_15c = a2, iVar6 < 0)) ||
             (iVar6 = BN_div((BIGNUM *)0x0,rem,a2,m,ctx), local_15c = rem, iVar6 != 0)) {
            if (local_15c->top == 0) goto LAB_001022a8;
            iVar6 = BN_mod_mul_montgomery(rem,local_15c,b,local_150,ctx);
            if (iVar6 != 0) {
              if (local_140 != 1) {
                iVar6 = BN_mod_mul_montgomery(pBVar4,rem,rem,local_150,ctx);
                if (iVar6 == 0) goto LAB_00102296;
                iVar6 = 1;
                ppBVar10 = local_a8;
                do {
                  iVar6 = iVar6 + 1;
                  pBVar5 = BN_CTX_get(ctx);
                  ppBVar10[1] = pBVar5;
                  if ((pBVar5 == (BIGNUM *)0x0) ||
                     (iVar7 = BN_mod_mul_montgomery(pBVar5,*ppBVar10,pBVar4,local_150,ctx),
                     iVar7 == 0)) goto LAB_00102296;
                  ppBVar10 = ppBVar10 + 1;
                } while (iVar6 < local_144);
              }
              pBVar4 = BN_value_one();
              iVar6 = BN_mod_mul_montgomery(r_00,pBVar4,b,local_150,ctx);
              if (iVar6 != 0) {
                if ((int)uVar2 < (int)uVar3) {
                  uVar2 = uVar3;
                }
                if (0 < (int)uVar2) {
                  iVar12 = uVar2 - 2;
                  n = 0;
                  iVar7 = 0;
                  uVar2 = 0;
                  iVar6 = 0;
                  bVar1 = true;
                  do {
                    iVar11 = iVar12 + 1;
                    if (uVar2 == 0) {
                      iVar8 = BN_is_bit_set(p1,iVar11);
                      local_158 = uVar2;
                      if (iVar8 != 0) {
                        n = (2 - local_14c) + iVar12;
                        while (iVar8 = BN_is_bit_set(p1,n), iVar8 == 0) {
                          n = n + 1;
                        }
                        if (iVar12 < n) {
                          uVar2 = 1;
                          local_158 = (uint)(iVar11 == n);
                        }
                        else {
                          uVar2 = 1;
                          iVar8 = iVar12;
                          do {
                            iVar9 = BN_is_bit_set(p1,iVar8);
                            uVar2 = uVar2 * 2;
                            iVar8 = iVar8 + -1;
                            if (iVar9 != 0) {
                              uVar2 = uVar2 + 1;
                            }
                          } while (n <= iVar8);
                          local_158 = uVar2;
                          if (uVar2 != 0) {
                            local_158 = 1;
                          }
                          if (iVar11 != n) {
                            local_158 = 0;
                          }
                        }
                      }
                    }
                    else {
                      uVar3 = count_leading_zeroes(iVar11 - n);
                      local_158 = uVar3 >> 5;
                    }
                    if ((iVar6 == 0) && (iVar8 = BN_is_bit_set(p2,iVar11), iVar8 != 0)) {
                      iVar7 = (2 - local_140) + iVar12;
                      while (iVar6 = BN_is_bit_set(p2,iVar7), iVar6 == 0) {
                        iVar7 = iVar7 + 1;
                      }
                      iVar6 = 1;
                      if (iVar7 <= iVar12) {
                        iVar6 = 1;
                        iVar8 = iVar12;
                        do {
                          iVar9 = BN_is_bit_set(p2,iVar8);
                          iVar6 = iVar6 * 2;
                          iVar8 = iVar8 + -1;
                          if (iVar9 != 0) {
                            iVar6 = iVar6 + 1;
                          }
                        } while (iVar7 <= iVar8);
                      }
                    }
                    if (local_158 != 0) {
                      iVar8 = BN_mod_mul_montgomery
                                        (r_00,r_00,local_128[(int)uVar2 >> 1],local_150,ctx);
                      if (iVar8 == 0) goto LAB_00102296;
                      uVar2 = 0;
                      bVar1 = false;
                    }
                    uVar3 = count_leading_zeroes(iVar7 - iVar11);
                    uVar3 = uVar3 >> 5;
                    if (iVar6 == 0) {
                      uVar3 = 0;
                    }
                    if (uVar3 == 0) {
                      if (iVar12 == -1) break;
                      if (!bVar1) goto LAB_001024a4;
                    }
                    else {
                      iVar6 = BN_mod_mul_montgomery(r_00,r_00,local_a8[iVar6 >> 1],local_150,ctx);
                      if (iVar6 == 0) goto LAB_00102296;
                      if (iVar12 == -1) break;
                      bVar1 = false;
                      iVar6 = 0;
LAB_001024a4:
                      iVar11 = BN_mod_mul_montgomery(r_00,r_00,r_00,local_150,ctx);
                      if (iVar11 == 0) goto LAB_00102296;
                    }
                    iVar12 = iVar12 + -1;
                  } while( true );
                }
                iVar6 = BN_from_montgomery(r,r_00,local_150,ctx);
                if (iVar6 != 0) {
                  iVar6 = 1;
                }
                goto LAB_00102298;
              }
            }
          }
        }
        goto LAB_00102296;
      }
LAB_001022a8:
      BN_set_word(r,0);
      iVar6 = 1;
    }
    else {
LAB_00102296:
      iVar6 = 0;
    }
LAB_00102298:
    if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_0010212a;
  }
  BN_MONT_CTX_free(local_150);
LAB_0010212a:
  BN_CTX_end(ctx);
  return iVar6;
}

