
int BN_mod_exp_mont_consttime
              (BIGNUM *rr,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *in_mont)

{
  BN_MONT_CTX *pBVar1;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  int extraout_r1;
  int iVar5;
  int iVar6;
  ulong *puVar7;
  ulong **ppuVar8;
  ulong *puVar10;
  BIGNUM *pBVar11;
  BN_MONT_CTX *pBVar12;
  int iVar13;
  int *piVar14;
  BN_CTX **ppBVar15;
  undefined auStack_90 [4];
  int local_8c;
  BIGNUM *local_88;
  BIGNUM *local_84;
  int local_80;
  BIGNUM *local_7c;
  BIGNUM *local_78;
  BN_MONT_CTX *local_74;
  BN_MONT_CTX *local_70;
  int local_6c;
  BN_MONT_CTX *local_68;
  BN_MONT_CTX *local_64;
  BIGNUM *local_60;
  BN_MONT_CTX *local_5c;
  BIGNUM local_54;
  BIGNUM local_40;
  ulong *local_2c;
  ulong **ppuVar9;
  
  ppBVar15 = (BN_CTX **)&stack0xffffff68;
  iVar13 = m->top;
  pBVar11 = (BIGNUM *)&__stack_chk_guard;
  local_2c = __stack_chk_guard;
  local_5c = in_mont;
  if ((iVar13 < 1) || (-1 < (int)(*m->d << 0x1f))) {
    pBVar12 = (BN_MONT_CTX *)0x0;
    ERR_put_error(3,0x7c,0x66,"bn_exp.c",0x28d);
    goto LAB_00086ab8;
  }
  local_60 = (BIGNUM *)BN_num_bits(p);
  if (local_60 == (BIGNUM *)0x0) {
    pBVar12 = (BN_MONT_CTX *)m->top;
    if (((pBVar12 == (BN_MONT_CTX *)0x1) && (*m->d == 1)) && (m->neg == 0)) {
      BN_set_word(rr,0);
    }
    else {
      pBVar12 = (BN_MONT_CTX *)BN_set_word(rr,1);
    }
    goto LAB_00086ab8;
  }
  BN_CTX_start(ctx);
  if (local_5c == (BN_MONT_CTX *)0x0) {
    pBVar12 = BN_MONT_CTX_new();
    local_70 = pBVar12;
    if (pBVar12 != (BN_MONT_CTX *)0x0) {
      pBVar12 = (BN_MONT_CTX *)BN_MONT_CTX_set(pBVar12,m,ctx);
      if (pBVar12 != (BN_MONT_CTX *)0x0) goto LAB_00086b18;
      local_64 = pBVar12;
      local_68 = pBVar12;
      local_74 = pBVar12;
      goto LAB_00086e86;
    }
  }
  else {
    local_70 = local_5c;
LAB_00086b18:
    if ((int)local_60 < 0x3aa) {
      if ((int)local_60 < 0x133) {
        if ((int)local_60 < 0x5a) {
          if ((int)local_60 < 0x17) {
            local_8c = 2;
            local_6c = 2;
            local_80 = 1;
          }
          else {
            local_8c = 8;
            local_6c = 8;
            local_80 = 3;
          }
        }
        else {
          local_8c = 0x10;
          local_6c = 0x10;
          local_80 = 4;
        }
      }
      else {
        local_8c = 0x20;
        local_6c = 0x20;
        local_80 = 5;
      }
    }
    else {
      local_8c = 0x40;
      local_80 = 6;
      local_6c = 0x40;
    }
    iVar3 = iVar13 * 2;
    if (iVar13 * 2 < local_8c) {
      iVar3 = local_8c;
    }
    local_68 = (BN_MONT_CTX *)((local_8c * iVar13 + iVar3) * 4);
    if ((int)local_68 < 0xc00) {
      ppBVar15 = (BN_CTX **)(&stack0xffffff68 + -(int)&local_68->flags);
      local_74 = (BN_MONT_CTX *)0x0;
      local_64 = (BN_MONT_CTX *)(((uint)(auStack_90 + -(int)&local_68->flags) & 0xffffffc0) + 0x40);
      memset(local_64,0,(size_t)local_68);
LAB_00086b66:
      local_40.dmax = iVar13;
      local_78 = &local_70->RR;
      local_54.d = (ulong *)((int)local_64->n0 + iVar13 * 4 * local_8c + -0x40);
      local_54.dmax = iVar13;
      local_40.top = 0;
      local_54.top = 0;
      local_40.neg = 0;
      local_54.neg = 0;
      local_40.flags = 2;
      local_54.flags = 2;
      local_40.d = local_54.d + iVar13;
      pBVar2 = BN_value_one();
      *ppBVar15 = ctx;
      pBVar12 = (BN_MONT_CTX *)BN_mod_mul_montgomery(&local_54,pBVar2,local_78,local_70,*ppBVar15);
      if (pBVar12 != (BN_MONT_CTX *)0x0) {
        if ((a->neg == 0) && (iVar3 = BN_ucmp(a,m), iVar3 < 0)) {
          *ppBVar15 = ctx;
          local_7c = &local_40;
          pBVar12 = (BN_MONT_CTX *)BN_mod_mul_montgomery(&local_40,a,local_78,local_70,*ppBVar15);
          pBVar2 = local_7c;
        }
        else {
          local_7c = &local_40;
          *ppBVar15 = ctx;
          pBVar12 = (BN_MONT_CTX *)BN_div((BIGNUM *)0x0,local_7c,a,m,*ppBVar15);
          pBVar2 = local_7c;
          if (pBVar12 == (BN_MONT_CTX *)0x0) goto LAB_00086bd6;
          *ppBVar15 = ctx;
          pBVar12 = (BN_MONT_CTX *)BN_mod_mul_montgomery(pBVar2,pBVar2,local_78,local_70,*ppBVar15);
          pBVar2 = local_7c;
        }
        local_7c = pBVar2;
        if (pBVar12 != (BN_MONT_CTX *)0x0) {
          iVar3 = local_54.top;
          if (iVar13 <= local_54.top) {
            iVar3 = iVar13;
          }
          if (0 < iVar3) {
            iVar5 = 0;
            puVar10 = local_54.d;
            do {
              puVar7 = puVar10 + 1;
              *(ulong *)((int)local_64->n0 + iVar5 + -0x40) = *puVar10;
              iVar5 = iVar5 + local_6c * 4;
              puVar10 = puVar7;
            } while (puVar7 != local_54.d + iVar3);
          }
          iVar3 = local_40.top;
          if (iVar13 <= local_40.top) {
            iVar3 = iVar13;
          }
          if (0 < iVar3) {
            pBVar12 = local_64;
            ppuVar8 = (ulong **)local_40.d;
            do {
              ppuVar9 = ppuVar8 + 1;
              (pBVar12->RR).d = *ppuVar8;
              pBVar12 = (BN_MONT_CTX *)(pBVar12->n0 + local_6c + -0x10);
              ppuVar8 = ppuVar9;
            } while (ppuVar9 != (ulong **)local_40.d + iVar3);
          }
          if (local_80 == 1) {
            local_6c = 0;
            local_60 = (BIGNUM *)((int)&local_60[-1].flags + 3);
LAB_00086d4c:
            local_78 = pBVar11;
            iVar3 = local_6c - (int)local_60;
            pBVar11 = local_60;
            do {
              BN_is_bit_set(p,(int)pBVar11);
              pBVar11 = (BIGNUM *)((int)&pBVar11[-1].flags + 3);
            } while (-1 < iVar3 + (int)pBVar11);
            local_60 = (BIGNUM *)((int)&local_60[-1].flags + 3);
            if (-1 < local_6c) {
              local_60 = (BIGNUM *)((int)local_60 - local_6c);
            }
            pBVar11 = local_78;
          }
          else {
            *ppBVar15 = ctx;
            pBVar12 = (BN_MONT_CTX *)
                      BN_mod_mul_montgomery(&local_54,pBVar2,pBVar2,local_70,*ppBVar15);
            pBVar1 = local_70;
            pBVar2 = local_7c;
            if (pBVar12 == (BN_MONT_CTX *)0x0) goto LAB_00086bd6;
            iVar3 = local_54.top;
            if (iVar13 <= local_54.top) {
              iVar3 = iVar13;
            }
            if (0 < iVar3) {
              pBVar12 = local_64;
              puVar10 = local_54.d;
              do {
                puVar7 = puVar10 + 1;
                (pBVar12->RR).top = *puVar10;
                pBVar12 = (BN_MONT_CTX *)(pBVar12->n0 + local_6c + -0x10);
                puVar10 = puVar7;
              } while (puVar7 != local_54.d + iVar3);
            }
            if (3 < local_6c) {
              local_88 = p;
              iVar5 = local_6c * 4;
              local_78 = (BIGNUM *)&__stack_chk_guard;
              piVar14 = &(local_64->RR).dmax;
              local_84 = rr;
              iVar3 = 3;
              do {
                *ppBVar15 = ctx;
                pBVar12 = (BN_MONT_CTX *)
                          BN_mod_mul_montgomery(&local_54,pBVar2,&local_54,pBVar1,*ppBVar15);
                pBVar11 = local_78;
                if (pBVar12 == (BN_MONT_CTX *)0x0) goto LAB_00086bd6;
                iVar4 = local_54.top;
                if (iVar13 <= local_54.top) {
                  iVar4 = iVar13;
                }
                if (0 < iVar4) {
                  iVar6 = 0;
                  puVar10 = local_54.d;
                  do {
                    puVar7 = puVar10 + 1;
                    *(ulong *)((int)piVar14 + iVar6) = *puVar10;
                    iVar6 = iVar6 + iVar5;
                    puVar10 = puVar7;
                  } while (puVar7 != local_54.d + iVar4);
                }
                iVar3 = iVar3 + 1;
                piVar14 = piVar14 + 1;
                p = local_88;
                rr = local_84;
              } while (iVar3 != local_6c);
            }
            local_60 = (BIGNUM *)((int)&local_60[-1].flags + 3);
            __aeabi_idivmod(local_60,local_80);
            local_6c = extraout_r1;
            if (-1 < extraout_r1) goto LAB_00086d4c;
          }
          *ppBVar15 = (BN_CTX *)local_80;
          pBVar12 = (BN_MONT_CTX *)MOD_EXP_CTIME_COPY_FROM_PREBUF(&local_54,iVar13,local_64);
          pBVar2 = local_60;
          pBVar1 = local_70;
          iVar3 = local_80;
          if (pBVar12 != (BN_MONT_CTX *)0x0) {
            if (-1 < (int)local_60) {
              local_6c = iVar13;
              local_78 = rr;
              local_60 = pBVar11;
              do {
                iVar5 = 0;
                iVar13 = 0;
                do {
                  *ppBVar15 = ctx;
                  pBVar12 = (BN_MONT_CTX *)
                            BN_mod_mul_montgomery(&local_54,&local_54,&local_54,pBVar1,*ppBVar15);
                  pBVar11 = local_60;
                  if (pBVar12 == (BN_MONT_CTX *)0x0) goto LAB_00086bd6;
                  iVar4 = BN_is_bit_set(p,(int)pBVar2);
                  iVar13 = iVar13 + 1;
                  pBVar2 = (BIGNUM *)((int)&pBVar2[-1].flags + 3);
                  iVar5 = iVar5 * 2 + iVar4;
                } while (iVar13 < iVar3);
                *ppBVar15 = (BN_CTX *)iVar3;
                pBVar12 = (BN_MONT_CTX *)
                          MOD_EXP_CTIME_COPY_FROM_PREBUF(local_7c,local_6c,local_64,iVar5);
                pBVar11 = local_60;
                if (pBVar12 == (BN_MONT_CTX *)0x0) goto LAB_00086bd6;
                *ppBVar15 = ctx;
                pBVar12 = (BN_MONT_CTX *)
                          BN_mod_mul_montgomery(&local_54,&local_54,local_7c,pBVar1,*ppBVar15);
                pBVar11 = local_60;
                if (pBVar12 == (BN_MONT_CTX *)0x0) goto LAB_00086bd6;
                rr = local_78;
              } while (-1 < (int)pBVar2);
            }
            pBVar12 = (BN_MONT_CTX *)BN_from_montgomery(rr,&local_54,local_70,ctx);
            if (pBVar12 != (BN_MONT_CTX *)0x0) {
              pBVar12 = (BN_MONT_CTX *)0x1;
            }
          }
        }
      }
    }
    else {
      local_74 = (BN_MONT_CTX *)CRYPTO_malloc((int)local_68->n0,"bn_exp.c",0x2c5);
      if (local_74 != (BN_MONT_CTX *)0x0) {
        local_64 = (BN_MONT_CTX *)(((uint)local_74 & 0xffffffc0) + 0x40);
        memset(local_64,0,(size_t)local_68);
        goto LAB_00086b66;
      }
      local_64 = local_74;
      pBVar12 = local_74;
    }
LAB_00086bd6:
    if (local_5c == (BN_MONT_CTX *)0x0) {
LAB_00086e86:
      BN_MONT_CTX_free(local_70);
    }
    if ((local_64 != (BN_MONT_CTX *)0x0) &&
       (OPENSSL_cleanse(local_64,(size_t)local_68), local_74 != (BN_MONT_CTX *)0x0)) {
      CRYPTO_free(local_74);
    }
  }
  BN_CTX_end(ctx);
LAB_00086ab8:
  if (local_2c != pBVar11->d) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (int)pBVar12;
}

