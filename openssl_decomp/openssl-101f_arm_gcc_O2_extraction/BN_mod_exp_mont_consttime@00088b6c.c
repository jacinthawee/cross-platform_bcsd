
int BN_mod_exp_mont_consttime
              (BIGNUM *rr,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *in_mont)

{
  undefined *puVar1;
  BIGNUM *pBVar2;
  BN_MONT_CTX *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  int extraout_r1;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  BIGNUM *pBVar11;
  int iVar12;
  BN_MONT_CTX *pBVar13;
  BN_MONT_CTX *__s;
  int iVar14;
  BN_CTX **ppBVar15;
  undefined auStack_90 [4];
  int local_8c;
  int local_88;
  BIGNUM *local_84;
  BN_MONT_CTX *local_80;
  int local_7c;
  int local_78;
  BN_MONT_CTX *local_74;
  BIGNUM *local_70;
  BN_MONT_CTX *local_6c;
  BIGNUM *local_68;
  BIGNUM *local_64;
  BN_MONT_CTX *local_60;
  BN_MONT_CTX *local_5c;
  BIGNUM local_54;
  BIGNUM local_40;
  ulong *local_2c;
  
  ppBVar15 = (BN_CTX **)&stack0xffffff68;
  pBVar11 = (BIGNUM *)&__TMC_END__;
  pBVar13 = (BN_MONT_CTX *)(*m->d & 1);
  local_2c = __TMC_END__;
  iVar12 = m->top;
  local_5c = in_mont;
  local_70 = rr;
  local_68 = a;
  local_64 = p;
  if (pBVar13 == (BN_MONT_CTX *)0x0) {
    ERR_put_error(3,0x7c,0x66,"bn_exp.c",599);
    goto LAB_00088ca6;
  }
  pBVar3 = (BN_MONT_CTX *)BN_num_bits(p);
  if (pBVar3 == (BN_MONT_CTX *)0x0) {
    pBVar13 = (BN_MONT_CTX *)BN_set_word(local_70,1);
    goto LAB_00088ca6;
  }
  BN_CTX_start(ctx);
  if (local_5c == (BN_MONT_CTX *)0x0) {
    pBVar13 = BN_MONT_CTX_new();
    local_6c = pBVar13;
    if (pBVar13 != (BN_MONT_CTX *)0x0) {
      pBVar13 = (BN_MONT_CTX *)BN_MONT_CTX_set(pBVar13,m,ctx);
      if (pBVar13 != (BN_MONT_CTX *)0x0) goto LAB_00088bbe;
      local_60 = pBVar13;
      local_74 = pBVar13;
      __s = pBVar13;
      goto LAB_00088d1c;
    }
  }
  else {
    local_6c = local_5c;
LAB_00088bbe:
    if ((int)pBVar3 < 0x3aa) {
      if ((int)pBVar3 < 0x133) {
        if ((int)pBVar3 < 0x5a) {
          if ((int)pBVar3 < 0x17) {
            iVar14 = 2;
            local_78 = 2;
            iVar5 = 2;
            local_88 = 1;
          }
          else {
            iVar14 = 8;
            iVar5 = 8;
            local_78 = 8;
            local_88 = 3;
          }
        }
        else {
          iVar14 = 0x10;
          local_78 = 0x10;
          local_88 = 4;
          iVar5 = 0x10;
        }
      }
      else {
        iVar14 = 0x20;
        local_78 = 0x20;
        iVar5 = 0x20;
        local_88 = 5;
      }
    }
    else {
      iVar14 = 0x40;
      iVar5 = 0x40;
      local_88 = 6;
      local_78 = 0x40;
    }
    iVar9 = iVar12 * 2;
    if (iVar12 * 2 < iVar5) {
      iVar9 = iVar5;
    }
    local_60 = (BN_MONT_CTX *)((iVar5 * iVar12 + iVar9) * 4);
    if ((int)local_60 < 0xc00) {
      ppBVar15 = (BN_CTX **)(&stack0xffffff68 + -(int)&local_60->flags);
      local_74 = (BN_MONT_CTX *)0x0;
      __s = (BN_MONT_CTX *)(((uint)(auStack_90 + -(int)&local_60->flags) & 0xffffffc0) + 0x40);
      memset(__s,0,(size_t)local_60);
LAB_00088c08:
      local_7c = iVar12 * 4;
      local_54.d = (ulong *)((int)__s->n0 + iVar12 * 4 * iVar14 + -0x40);
      local_40.top = 0;
      local_80 = (BN_MONT_CTX *)&local_6c->RR;
      local_54.top = 0;
      local_40.neg = 0;
      local_54.neg = 0;
      local_40.flags = 2;
      local_54.flags = 2;
      local_40.dmax = iVar12;
      local_54.dmax = iVar12;
      local_40.d = local_54.d + iVar12;
      pBVar4 = BN_value_one();
      *ppBVar15 = ctx;
      pBVar13 = (BN_MONT_CTX *)
                BN_mod_mul_montgomery(&local_54,pBVar4,(BIGNUM *)local_80,local_6c,*ppBVar15);
      if (pBVar13 != (BN_MONT_CTX *)0x0) {
        if ((local_68->neg == 0) && (iVar5 = BN_ucmp(local_68,m), iVar5 < 0)) {
          *ppBVar15 = ctx;
          local_84 = &local_40;
          pBVar13 = (BN_MONT_CTX *)
                    BN_mod_mul_montgomery(&local_40,local_68,(BIGNUM *)local_80,local_6c,*ppBVar15);
          pBVar4 = local_84;
        }
        else {
          local_84 = &local_40;
          *ppBVar15 = ctx;
          pBVar13 = (BN_MONT_CTX *)BN_div((BIGNUM *)0x0,local_84,local_68,m,*ppBVar15);
          pBVar4 = local_84;
          if (pBVar13 == (BN_MONT_CTX *)0x0) goto LAB_00088c7a;
          *ppBVar15 = ctx;
          pBVar13 = (BN_MONT_CTX *)
                    BN_mod_mul_montgomery(pBVar4,pBVar4,(BIGNUM *)local_80,local_6c,*ppBVar15);
          pBVar4 = local_84;
        }
        local_84 = pBVar4;
        if (pBVar13 != (BN_MONT_CTX *)0x0) {
          iVar5 = local_54.top;
          if (iVar12 <= local_54.top) {
            iVar5 = iVar12;
          }
          if (iVar5 * 4 != 0) {
            iVar8 = 0;
            iVar9 = iVar8;
            do {
              puVar1 = (undefined *)((int)local_54.d + iVar9);
              iVar9 = iVar9 + 1;
              *(undefined *)((int)__s->n0 + iVar8 + -0x40) = *puVar1;
              iVar8 = iVar8 + iVar14;
            } while (iVar9 != iVar5 * 4);
          }
          iVar5 = local_40.top;
          if (iVar12 <= local_40.top) {
            iVar5 = iVar12;
          }
          if (iVar5 * 4 != 0) {
            iVar9 = 0;
            pBVar13 = __s;
            do {
              puVar1 = (undefined *)((int)local_40.d + iVar9);
              iVar9 = iVar9 + 1;
              *(undefined *)((int)&pBVar13->ri + 1) = *puVar1;
              pBVar13 = (BN_MONT_CTX *)((int)pBVar13->n0 + iVar14 + -0x40);
            } while (iVar9 != iVar5 * 4);
          }
          if (local_88 == 1) {
            pBVar4 = (BIGNUM *)((int)&pBVar3[-1].flags + 3);
            local_68 = pBVar4;
            local_78 = 0;
LAB_00088e7a:
            pBVar2 = local_64;
            local_80 = __s;
            iVar9 = local_78 - (int)pBVar4;
            local_8c = iVar12;
            iVar5 = 0;
            do {
              iVar12 = BN_is_bit_set(pBVar2,(int)pBVar4);
              pBVar4 = (BIGNUM *)((int)&pBVar4[-1].flags + 3);
              iVar5 = iVar5 * 2 + iVar12;
            } while (-1 < iVar9 + (int)pBVar4);
            local_68 = (BIGNUM *)((int)&local_68[-1].flags + 3);
            if (-1 < local_78) {
              local_68 = (BIGNUM *)((int)local_68 - local_78);
            }
            iVar12 = local_8c;
            __s = local_80;
          }
          else {
            *ppBVar15 = ctx;
            pBVar13 = (BN_MONT_CTX *)
                      BN_mod_mul_montgomery(&local_54,pBVar4,pBVar4,local_6c,*ppBVar15);
            iVar5 = local_78;
            pBVar4 = local_84;
            if (pBVar13 == (BN_MONT_CTX *)0x0) goto LAB_00088c7a;
            iVar9 = local_54.top;
            if (iVar12 <= local_54.top) {
              iVar9 = iVar12;
            }
            if (iVar9 * 4 != 0) {
              iVar8 = 0;
              pBVar13 = __s;
              do {
                puVar1 = (undefined *)((int)local_54.d + iVar8);
                iVar8 = iVar8 + 1;
                *(undefined *)((int)&pBVar13->ri + 2) = *puVar1;
                pBVar13 = (BN_MONT_CTX *)((int)pBVar13->n0 + iVar14 + -0x40);
              } while (iVar8 != iVar9 * 4);
            }
            if (3 < local_78) {
              local_80 = pBVar3;
              local_68 = (BIGNUM *)&__TMC_END__;
              iVar9 = 3;
              do {
                *ppBVar15 = ctx;
                pBVar13 = (BN_MONT_CTX *)
                          BN_mod_mul_montgomery(&local_54,pBVar4,&local_54,local_6c,*ppBVar15);
                pBVar11 = local_68;
                if (pBVar13 == (BN_MONT_CTX *)0x0) goto LAB_00088c7a;
                iVar8 = local_54.top;
                if (iVar12 <= local_54.top) {
                  iVar8 = iVar12;
                }
                if (iVar8 * 4 != 0) {
                  iVar10 = 0;
                  iVar6 = iVar9;
                  do {
                    puVar1 = (undefined *)((int)local_54.d + iVar10);
                    iVar10 = iVar10 + 1;
                    *(undefined *)((int)__s->n0 + iVar6 + -0x40) = *puVar1;
                    iVar6 = iVar6 + iVar14;
                  } while (iVar10 != iVar8 * 4);
                }
                iVar9 = iVar9 + 1;
                pBVar3 = local_80;
              } while (iVar9 != iVar5);
            }
            pBVar4 = (BIGNUM *)((int)&pBVar3[-1].flags + 3);
            local_68 = pBVar4;
            __aeabi_idivmod(pBVar4,local_88);
            local_78 = extraout_r1;
            if (-1 < extraout_r1) goto LAB_00088e7a;
            iVar5 = 0;
          }
          if ((iVar12 <= local_54.dmax) ||
             (pBVar13 = (BN_MONT_CTX *)bn_expand2(&local_54,iVar12), pBVar13 != (BN_MONT_CTX *)0x0))
          {
            pBVar2 = local_64;
            pBVar4 = local_68;
            pBVar3 = local_6c;
            iVar9 = local_88;
            if (local_7c != 0) {
              iVar8 = 0;
              do {
                iVar6 = iVar5 + -0x40;
                iVar5 = iVar5 + iVar14;
                *(undefined *)((int)local_54.d + iVar8) = *(undefined *)((int)__s->n0 + iVar6);
                iVar8 = iVar8 + 1;
              } while (iVar8 != local_7c);
            }
            local_54.top = iVar12;
            if (0 < iVar12) {
              piVar7 = (int *)((int)local_54.d + local_7c + -4);
              do {
                if (*piVar7 != 0) break;
                local_54.top = local_54.top + -1;
                piVar7 = piVar7 + -1;
              } while (local_54.top != 0);
            }
            if (-1 < (int)local_68) {
              local_88 = iVar14;
              local_78 = iVar12;
              local_80 = __s;
              local_8c = local_7c + -4;
              local_68 = pBVar11;
              do {
                iVar14 = 0;
                iVar12 = 0;
                do {
                  *ppBVar15 = ctx;
                  pBVar13 = (BN_MONT_CTX *)
                            BN_mod_mul_montgomery(&local_54,&local_54,&local_54,pBVar3,*ppBVar15);
                  pBVar11 = local_68;
                  __s = local_80;
                  if (pBVar13 == (BN_MONT_CTX *)0x0) goto LAB_00088c7a;
                  iVar5 = BN_is_bit_set(pBVar2,(int)pBVar4);
                  iVar12 = iVar12 + 1;
                  pBVar4 = (BIGNUM *)((int)&pBVar4[-1].flags + 3);
                  iVar14 = iVar14 * 2 + iVar5;
                } while (iVar12 < iVar9);
                if ((local_40.dmax < local_78) &&
                   (pBVar13 = (BN_MONT_CTX *)bn_expand2(local_84,local_78), pBVar11 = local_68,
                   __s = local_80, pBVar13 == (BN_MONT_CTX *)0x0)) goto LAB_00088c7a;
                if (local_7c != 0) {
                  iVar12 = 0;
                  do {
                    iVar5 = iVar14 + -0x40;
                    iVar14 = iVar14 + local_88;
                    *(undefined *)((int)local_40.d + iVar12) =
                         *(undefined *)((int)local_80->n0 + iVar5);
                    iVar12 = iVar12 + 1;
                  } while (iVar12 != local_7c);
                }
                local_40.top = local_78;
                if (0 < local_78) {
                  piVar7 = (int *)((int)local_40.d + local_8c);
                  do {
                    if (*piVar7 != 0) break;
                    local_40.top = local_40.top + -1;
                    piVar7 = piVar7 + -1;
                  } while (local_40.top != 0);
                }
                *ppBVar15 = ctx;
                pBVar13 = (BN_MONT_CTX *)
                          BN_mod_mul_montgomery(&local_54,&local_54,local_84,pBVar3,*ppBVar15);
                pBVar11 = local_68;
                __s = local_80;
                if (pBVar13 == (BN_MONT_CTX *)0x0) goto LAB_00088c7a;
              } while (-1 < (int)pBVar4);
            }
            pBVar13 = (BN_MONT_CTX *)BN_from_montgomery(local_70,&local_54,local_6c,ctx);
            if (pBVar13 != (BN_MONT_CTX *)0x0) {
              pBVar13 = (BN_MONT_CTX *)0x1;
            }
          }
        }
      }
    }
    else {
      local_74 = (BN_MONT_CTX *)CRYPTO_malloc((int)local_60->n0,"bn_exp.c",0x27f);
      pBVar13 = local_74;
      __s = local_74;
      if (local_74 != (BN_MONT_CTX *)0x0) {
        __s = (BN_MONT_CTX *)(((uint)local_74 & 0xffffffc0) + 0x40);
        memset(__s,0,(size_t)local_60);
        goto LAB_00088c08;
      }
    }
LAB_00088c7a:
    if (local_5c == (BN_MONT_CTX *)0x0) {
LAB_00088d1c:
      BN_MONT_CTX_free(local_6c);
    }
    if ((__s != (BN_MONT_CTX *)0x0) &&
       (OPENSSL_cleanse(__s,(size_t)local_60), local_74 != (BN_MONT_CTX *)0x0)) {
      CRYPTO_free(local_74);
    }
  }
  BN_CTX_end(ctx);
LAB_00088ca6:
  if (local_2c != pBVar11->d) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)pBVar13;
}

