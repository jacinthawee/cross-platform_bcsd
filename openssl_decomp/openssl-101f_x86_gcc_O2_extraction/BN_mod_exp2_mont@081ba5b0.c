
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
  BIGNUM *b;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int n;
  int n_00;
  int in_GS_OFFSET;
  int local_16c;
  BIGNUM *local_160;
  BN_MONT_CTX *local_14c;
  int local_148;
  int local_140;
  int local_13c;
  int local_138;
  BIGNUM *apBStack_124 [32];
  BIGNUM *apBStack_a4 [33];
  int local_20;
  
  local_160 = a2;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(byte *)m->d & 1) == 0) {
    ERR_put_error(3,0x76,0x66,"bn_exp2.c",0x8a);
    uVar3 = 0;
  }
  else {
    uVar2 = BN_num_bits(p1);
    uVar3 = BN_num_bits(p2);
    if ((uVar2 | uVar3) == 0) {
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        iVar6 = BN_set_word(r,1);
        return iVar6;
      }
      goto LAB_081bad7b;
    }
    BN_CTX_start(ctx);
    pBVar4 = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    pBVar5 = BN_CTX_get(ctx);
    apBStack_124[1] = pBVar5;
    rem = BN_CTX_get(ctx);
    apBStack_a4[1] = rem;
    if (((r_00 == (BIGNUM *)0x0 || pBVar4 == (BIGNUM *)0x0) || pBVar5 == (BIGNUM *)0x0) ||
       (rem == (BIGNUM *)0x0)) {
LAB_081ba790:
      uVar3 = 0;
    }
    else {
      local_14c = m_ctx;
      if (m_ctx == (BN_MONT_CTX *)0x0) {
        local_14c = BN_MONT_CTX_new();
        if (local_14c == (BN_MONT_CTX *)0x0) goto LAB_081ba790;
        iVar6 = BN_MONT_CTX_set(local_14c,m,ctx);
        if (iVar6 != 0) goto LAB_081ba6c8;
        uVar3 = 0;
      }
      else {
LAB_081ba6c8:
        if ((int)uVar2 < 0x2a0) {
          if ((int)uVar2 < 0xf0) {
            if ((int)uVar2 < 0x50) {
              local_148 = (uint)(0x17 < (int)uVar2) * 3 + 1;
              local_140 = (uint)(0x17 < (int)uVar2) * 2 + 1;
            }
            else {
              local_148 = 8;
              local_140 = 4;
            }
          }
          else {
            local_148 = 0x10;
            local_140 = 5;
          }
        }
        else {
          local_148 = 0x20;
          local_140 = 6;
        }
        if ((int)uVar3 < 0x2a0) {
          if ((int)uVar3 < 0xf0) {
            if ((int)uVar3 < 0x50) {
              local_13c = (uint)(0x17 < (int)uVar3) * 3 + 1;
              local_138 = (uint)(0x17 < (int)uVar3) * 2 + 1;
            }
            else {
              local_13c = 8;
              local_138 = 4;
            }
          }
          else {
            local_13c = 0x10;
            local_138 = 5;
          }
        }
        else {
          local_13c = 0x20;
          local_138 = 6;
        }
        if (((a1->neg == 0) && (iVar6 = BN_ucmp(a1,m), iVar6 < 0)) ||
           (iVar6 = BN_div((BIGNUM *)0x0,pBVar5,a1,m,ctx), a1 = pBVar5, iVar6 != 0)) {
          if (a1->top != 0) {
            b = &local_14c->RR;
            iVar6 = BN_mod_mul_montgomery(pBVar5,a1,b,local_14c,ctx);
            if (iVar6 != 0) {
              if (local_140 != 1) {
                iVar6 = BN_mod_mul_montgomery(pBVar4,pBVar5,pBVar5,local_14c,ctx);
                if (iVar6 == 0) goto LAB_081ba988;
                iVar6 = 1;
                do {
                  pBVar5 = BN_CTX_get(ctx);
                  apBStack_124[iVar6 + 1] = pBVar5;
                  if ((pBVar5 == (BIGNUM *)0x0) ||
                     (iVar7 = BN_mod_mul_montgomery(pBVar5,apBStack_124[iVar6],pBVar4,local_14c,ctx)
                     , iVar7 == 0)) goto LAB_081ba988;
                  iVar6 = iVar6 + 1;
                } while (iVar6 < local_148);
              }
              if (((a2->neg == 0) && (iVar6 = BN_ucmp(a2,m), iVar6 < 0)) ||
                 (iVar6 = BN_div((BIGNUM *)0x0,rem,a2,m,ctx), local_160 = rem, iVar6 != 0)) {
                if (local_160->top == 0) goto LAB_081ba9b0;
                iVar6 = BN_mod_mul_montgomery(rem,local_160,b,local_14c,ctx);
                if (iVar6 != 0) {
                  if (local_138 != 1) {
                    iVar6 = BN_mod_mul_montgomery(pBVar4,rem,rem,local_14c,ctx);
                    if (iVar6 == 0) goto LAB_081ba988;
                    iVar6 = 1;
                    do {
                      pBVar5 = BN_CTX_get(ctx);
                      apBStack_a4[iVar6 + 1] = pBVar5;
                      if ((pBVar5 == (BIGNUM *)0x0) ||
                         (iVar7 = BN_mod_mul_montgomery
                                            (pBVar5,apBStack_a4[iVar6],pBVar4,local_14c,ctx),
                         iVar7 == 0)) goto LAB_081ba988;
                      iVar6 = iVar6 + 1;
                    } while (iVar6 < local_13c);
                  }
                  pBVar4 = BN_value_one();
                  iVar6 = BN_mod_mul_montgomery(r_00,pBVar4,b,local_14c,ctx);
                  if (iVar6 != 0) {
                    if ((int)uVar3 <= (int)uVar2) {
                      uVar3 = uVar2;
                    }
                    if (0 < (int)uVar3) {
                      local_16c = uVar3 - 2;
                      n_00 = 0;
                      iVar6 = 0;
                      bVar1 = true;
                      n = 0;
                      iVar7 = 0;
                      do {
                        iVar8 = local_16c + 1;
                        if (iVar7 == 0) {
                          iVar9 = BN_is_bit_set(p1,iVar8);
                          if (iVar9 != 0) {
                            n = (2 - local_140) + local_16c;
                            while (iVar7 = BN_is_bit_set(p1,n), iVar7 == 0) {
                              n = n + 1;
                            }
                            iVar7 = 1;
                            if (n <= local_16c) {
                              iVar7 = 1;
                              iVar9 = local_16c;
                              do {
                                iVar10 = BN_is_bit_set(p1,iVar9);
                                iVar7 = (iVar7 * 2 + 1) - (uint)(iVar10 == 0);
                                iVar9 = iVar9 + -1;
                              } while (n <= iVar9);
                            }
                            goto LAB_081bab70;
                          }
                          if (iVar6 == 0) goto LAB_081bacf4;
                        }
                        else {
LAB_081bab70:
                          if (iVar6 == 0) {
LAB_081bacf4:
                            iVar6 = 0;
                            iVar9 = BN_is_bit_set(p2,iVar8);
                            if (iVar9 != 0) {
                              n_00 = (2 - local_138) + local_16c;
                              while (iVar6 = BN_is_bit_set(p2,n_00), iVar6 == 0) {
                                n_00 = n_00 + 1;
                              }
                              iVar6 = 1;
                              for (iVar9 = local_16c; n_00 <= iVar9; iVar9 = iVar9 + -1) {
                                iVar10 = BN_is_bit_set(p2,iVar9);
                                iVar6 = (iVar6 * 2 + 1) - (uint)(iVar10 == 0);
                              }
                            }
                          }
                          if ((iVar7 != 0) && (iVar8 == n)) {
                            iVar7 = BN_mod_mul_montgomery
                                              (r_00,r_00,apBStack_124[(iVar7 >> 1) + 1],local_14c,
                                               ctx);
                            if (iVar7 == 0) goto LAB_081ba988;
                            bVar1 = false;
                            iVar7 = 0;
                          }
                        }
                        if ((iVar6 == 0) || (iVar8 != n_00)) {
                          if (local_16c == -1) break;
                          if (!bVar1) goto LAB_081bacbd;
                          bVar1 = true;
                        }
                        else {
                          iVar6 = BN_mod_mul_montgomery
                                            (r_00,r_00,apBStack_a4[(iVar6 >> 1) + 1],local_14c,ctx);
                          if (iVar6 == 0) goto LAB_081ba988;
                          if (local_16c == -1) break;
                          iVar6 = 0;
LAB_081bacbd:
                          iVar8 = BN_mod_mul_montgomery(r_00,r_00,r_00,local_14c,ctx);
                          if (iVar8 == 0) goto LAB_081ba988;
                          bVar1 = false;
                        }
                        local_16c = local_16c + -1;
                      } while( true );
                    }
                    iVar6 = BN_from_montgomery(r,r_00,local_14c,ctx);
                    uVar3 = (uint)(iVar6 != 0);
                    goto LAB_081ba98a;
                  }
                }
              }
            }
            goto LAB_081ba988;
          }
LAB_081ba9b0:
          uVar3 = 1;
          BN_set_word(r,0);
        }
        else {
LAB_081ba988:
          uVar3 = 0;
        }
LAB_081ba98a:
        if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_081ba792;
      }
      BN_MONT_CTX_free(local_14c);
    }
LAB_081ba792:
    BN_CTX_end(ctx);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
LAB_081bad7b:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

