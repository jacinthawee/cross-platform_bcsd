
int BN_mod_exp2_mont(BIGNUM *r,BIGNUM *a1,BIGNUM *p1,BIGNUM *a2,BIGNUM *p2,BIGNUM *m,BN_CTX *ctx,
                    BN_MONT_CTX *m_ctx)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong *puVar5;
  undefined4 uVar6;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  BIGNUM *unaff_s3;
  BIGNUM *unaff_s4;
  BIGNUM *unaff_s5;
  BIGNUM *unaff_s6;
  BIGNUM *unaff_s7;
  code *pcVar9;
  BIGNUM *local_154;
  int local_150;
  BIGNUM *local_14c;
  BN_MONT_CTX *local_148;
  int local_144;
  int local_140;
  int local_13c;
  int local_138;
  BIGNUM *local_12c;
  BIGNUM local_128 [6];
  BIGNUM *local_ac;
  BIGNUM local_a8 [6];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_154 = a2;
  if ((*m->d & 1) == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x76,0x66,"bn_exp2.c",0x8a);
    pBVar8 = (BIGNUM *)0x0;
    p1 = unaff_s6;
    goto LAB_005f12e0;
  }
  unaff_s5 = (BIGNUM *)(*(code *)PTR_BN_num_bits_006a71f4)(p1);
  unaff_s7 = (BIGNUM *)(*(code *)PTR_BN_num_bits_006a71f4)(p2);
  if ((unaff_s5 == (BIGNUM *)0x0) && (unaff_s7 == (BIGNUM *)0x0)) {
    if (local_2c != *(int *)puVar1) goto LAB_005f19a0;
                    /* WARNING: Could not recover jumptable at 0x005f13c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*(code *)PTR_BN_set_word_006a7730)(r,1);
    return iVar2;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(ctx);
  iVar2 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
  local_150 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
  unaff_s4 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
  local_12c = unaff_s4;
  local_14c = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
  local_ac = local_14c;
  if ((((iVar2 != 0) && (local_150 != 0)) && (unaff_s4 != (BIGNUM *)0x0)) &&
     (local_14c != (BIGNUM *)0x0)) {
    local_148 = m_ctx;
    if (m_ctx == (BN_MONT_CTX *)0x0) {
      local_148 = (BN_MONT_CTX *)(*(code *)PTR_BN_MONT_CTX_new_006a8560)();
      if (local_148 == (BN_MONT_CTX *)0x0) goto LAB_005f12c8;
      iVar3 = (*(code *)PTR_BN_MONT_CTX_set_006a8564)(local_148,m,ctx);
      if (iVar3 == 0) {
        pBVar8 = (BIGNUM *)0x0;
        goto LAB_005f1454;
      }
    }
    if ((int)unaff_s5 < 0x2a0) {
      if ((int)unaff_s5 < 0xf0) {
        if ((int)unaff_s5 < 0x50) {
          local_140 = 1;
          local_144 = 4;
          if ((int)unaff_s5 < 0x18) {
            local_144 = 1;
          }
          else {
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
    if ((int)unaff_s7 < 0x2a0) {
      if ((int)unaff_s7 < 0xf0) {
        if ((int)unaff_s7 < 0x50) {
          local_138 = 1;
          local_13c = 4;
          if ((int)unaff_s7 < 0x18) {
            local_13c = 1;
          }
          else {
            local_138 = 3;
          }
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
    if (((a1->neg != 0) || (iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(a1,m), pBVar8 = a1, -1 < iVar3))
       && (iVar3 = BN_div((BIGNUM *)0x0,unaff_s4,a1,m,ctx), pBVar8 = unaff_s4, iVar3 == 0))
    goto LAB_005f1490;
    a1 = pBVar8;
    if (a1->top != 0) {
      pBVar8 = &local_148->RR;
      iVar3 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)(unaff_s4,a1,pBVar8,local_148,ctx);
      if (iVar3 == 0) goto LAB_005f1490;
      if (local_140 != 1) {
        iVar3 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)(iVar2,unaff_s4,unaff_s4,local_148,ctx)
        ;
        if (iVar3 == 0) goto LAB_005f1490;
        unaff_s4 = local_128;
        a1 = (BIGNUM *)0x1;
        do {
          puVar5 = (ulong *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
          unaff_s4->d = puVar5;
          if (puVar5 == (ulong *)0x0) {
            pBVar8 = (BIGNUM *)0x0;
            goto LAB_005f1448;
          }
          iVar3 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)
                            (puVar5,unaff_s4[-1].flags,iVar2,local_148,ctx);
          if (iVar3 == 0) goto LAB_005f1490;
          a1 = (BIGNUM *)((int)&a1->d + 1);
          unaff_s4 = (BIGNUM *)&unaff_s4->top;
        } while ((int)a1 < local_144);
      }
      if (((a2->neg != 0) ||
          (iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(a2,m), pBVar7 = a2, -1 < iVar3)) &&
         (iVar3 = BN_div((BIGNUM *)0x0,local_14c,a2,m,ctx), pBVar7 = local_14c, iVar3 == 0))
      goto LAB_005f1490;
      local_154 = pBVar7;
      if (local_154->top != 0) {
        iVar3 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)
                          (local_14c,local_154,pBVar8,local_148,ctx);
        if (iVar3 == 0) goto LAB_005f1490;
        if (local_138 != 1) {
          iVar3 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)
                            (iVar2,local_14c,local_14c,local_148,ctx);
          if (iVar3 == 0) goto LAB_005f1490;
          a1 = local_a8;
          iVar3 = 1;
          do {
            puVar5 = (ulong *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
            a1->d = puVar5;
            if (puVar5 == (ulong *)0x0) {
              pBVar8 = (BIGNUM *)0x0;
              goto LAB_005f1448;
            }
            iVar4 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)
                              (puVar5,a1[-1].flags,iVar2,local_148,ctx);
            if (iVar4 == 0) goto LAB_005f1490;
            iVar3 = iVar3 + 1;
            a1 = (BIGNUM *)&a1->top;
          } while (iVar3 < local_13c);
        }
        uVar6 = (*(code *)PTR_BN_value_one_006a8554)();
        iVar2 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)(local_150,uVar6,pBVar8,local_148,ctx);
        if (iVar2 == 0) goto LAB_005f1490;
        if ((int)unaff_s7 <= (int)unaff_s5) {
          unaff_s7 = unaff_s5;
        }
        if ((int)unaff_s7 < 1) goto LAB_005f1980;
        unaff_s7 = (BIGNUM *)((int)&unaff_s7[-1].flags + 2);
        local_14c = (BIGNUM *)0x1;
        m = (BIGNUM *)0x0;
        unaff_s4 = (BIGNUM *)0x0;
        unaff_s5 = (BIGNUM *)0x0;
        a1 = (BIGNUM *)0x0;
        local_144 = 2 - local_138;
        local_140 = 2 - local_140;
        goto LAB_005f1738;
      }
    }
    pBVar8 = (BIGNUM *)0x1;
    (*(code *)PTR_BN_set_word_006a7730)(r,0);
LAB_005f1448:
    do {
      if (m_ctx == (BN_MONT_CTX *)0x0) {
LAB_005f1454:
        (*(code *)PTR_BN_MONT_CTX_free_006a8568)(local_148);
      }
LAB_005f12d0:
      (*(code *)PTR_BN_CTX_end_006a8530)(ctx);
      m = pBVar8;
      unaff_s3 = a1;
LAB_005f12e0:
      a1 = unaff_s3;
      if (local_2c == *(int *)puVar1) {
        return (int)pBVar8;
      }
LAB_005f19a0:
      pcVar9 = (code *)PTR___stack_chk_fail_006a9ab0;
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005f19ac:
      iVar2 = (*pcVar9)(p2,local_154);
      if (iVar2 != 0) goto LAB_005f1764;
      if (a1 == (BIGNUM *)0x0) goto LAB_005f17ec;
LAB_005f19c8:
      if (unaff_s4 == local_154) {
        iVar2 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)
                          (local_150,local_150,
                           *(undefined4 *)((int)local_128 + ((int)a1 >> 1) * 4 + -4),local_148,ctx);
        if (iVar2 == 0) goto LAB_005f1490;
        a1 = (BIGNUM *)0x0;
        local_14c = (BIGNUM *)0x0;
      }
      m = (BIGNUM *)0x0;
LAB_005f17ec:
      if (unaff_s7 != (BIGNUM *)0xffffffff) {
        if (local_14c == (BIGNUM *)0x0) goto LAB_005f18e8;
        unaff_s7 = (BIGNUM *)((int)&unaff_s7[-1].flags + 3);
        local_14c = (BIGNUM *)0x1;
LAB_005f1738:
        do {
          local_154 = (BIGNUM *)((int)&unaff_s7->d + 1);
          if (a1 == (BIGNUM *)0x0) {
            iVar2 = (*(code *)PTR_BN_is_bit_set_006a8538)(p1,local_154);
            if (iVar2 == 0) {
              if (m == (BIGNUM *)0x0) {
                iVar2 = (*(code *)PTR_BN_is_bit_set_006a8538)
                                  (p2,(undefined *)((int)&unaff_s7->d + 1));
                if (iVar2 != 0) goto LAB_005f1764;
                goto LAB_005f17ec;
              }
            }
            else {
              unaff_s4 = (BIGNUM *)((int)&unaff_s7->d + local_140);
              while (iVar2 = (*(code *)PTR_BN_is_bit_set_006a8538)(p1,unaff_s4), iVar2 == 0) {
                unaff_s4 = (BIGNUM *)((int)&unaff_s4->d + 1);
              }
              a1 = (BIGNUM *)0x1;
              pBVar8 = unaff_s7;
              if ((int)unaff_s7 < (int)unaff_s4) goto LAB_005f1744;
              do {
                pBVar7 = (BIGNUM *)((int)&pBVar8[-1].flags + 3);
                a1 = (BIGNUM *)((int)a1 * 2);
                iVar2 = (*(code *)PTR_BN_is_bit_set_006a8538)(p1,pBVar8);
                if (iVar2 != 0) {
                  a1 = (BIGNUM *)((int)&a1->d + 1);
                }
                pBVar8 = pBVar7;
              } while ((int)unaff_s4 <= (int)pBVar7);
              pcVar9 = (code *)PTR_BN_is_bit_set_006a8538;
              if (m == (BIGNUM *)0x0) goto LAB_005f19ac;
LAB_005f1894:
              if (a1 != (BIGNUM *)0x0) goto LAB_005f17d8;
            }
          }
          else {
LAB_005f1744:
            if (m == (BIGNUM *)0x0) {
              iVar2 = (*(code *)PTR_BN_is_bit_set_006a8538)(p2,local_154);
              if (iVar2 == 0) goto LAB_005f19c8;
LAB_005f1764:
              unaff_s5 = (BIGNUM *)((int)&unaff_s7->d + local_144);
              while (iVar2 = (*(code *)PTR_BN_is_bit_set_006a8538)(p2,unaff_s5), iVar2 == 0) {
                unaff_s5 = (BIGNUM *)((int)&unaff_s5->d + 1);
              }
              m = (BIGNUM *)0x1;
              pBVar8 = unaff_s7;
              if ((int)unaff_s7 < (int)unaff_s5) goto LAB_005f1894;
              do {
                pBVar7 = (BIGNUM *)((int)&pBVar8[-1].flags + 3);
                m = (BIGNUM *)((int)m * 2);
                iVar2 = (*(code *)PTR_BN_is_bit_set_006a8538)(p2,pBVar8);
                if (iVar2 != 0) {
                  m = (BIGNUM *)((int)&m->d + 1);
                }
                pBVar8 = pBVar7;
              } while ((int)unaff_s5 <= (int)pBVar7);
              if (a1 != (BIGNUM *)0x0) goto LAB_005f17d8;
            }
            else {
LAB_005f17d8:
              if (local_154 == unaff_s4) {
                iVar2 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)
                                  (local_150,local_150,
                                   *(undefined4 *)((int)local_128 + ((int)a1 >> 1) * 4 + -4),
                                   local_148,ctx);
                if (iVar2 == 0) goto LAB_005f1490;
                local_14c = (BIGNUM *)0x0;
                a1 = (BIGNUM *)0x0;
              }
            }
            if (m == (BIGNUM *)0x0) goto LAB_005f17ec;
          }
          if (local_154 != unaff_s5) goto LAB_005f17ec;
          iVar2 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)
                            (local_150,local_150,
                             *(undefined4 *)((int)local_a8 + ((int)m >> 1) * 4 + -4),local_148,ctx);
          if (iVar2 == 0) goto LAB_005f1490;
          if (unaff_s7 == (BIGNUM *)0xffffffff) break;
          m = (BIGNUM *)0x0;
LAB_005f18e8:
          iVar2 = (*(code *)PTR_BN_mod_mul_montgomery_006a8558)
                            (local_150,local_150,local_150,local_148,ctx);
          if (iVar2 == 0) goto LAB_005f1490;
          local_14c = (BIGNUM *)0x0;
          unaff_s7 = (BIGNUM *)((int)&unaff_s7[-1].flags + 3);
        } while( true );
      }
LAB_005f1980:
      iVar2 = (*(code *)PTR_BN_from_montgomery_006a856c)(r,local_150,local_148,ctx);
      pBVar8 = (BIGNUM *)(uint)(iVar2 != 0);
    } while( true );
  }
LAB_005f12c8:
  pBVar8 = (BIGNUM *)0x0;
  goto LAB_005f12d0;
LAB_005f1490:
  pBVar8 = (BIGNUM *)0x0;
  goto LAB_005f1448;
}

