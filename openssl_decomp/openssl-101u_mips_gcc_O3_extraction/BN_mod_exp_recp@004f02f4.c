
int BN_mod_exp_recp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  BN_MONT_CTX *pBVar2;
  undefined *puVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  uint uVar6;
  BIGNUM *pBVar7;
  ulong **ppuVar8;
  int iVar9;
  int iVar10;
  BIGNUM *pBVar11;
  int *piVar12;
  ulong *puVar13;
  BIGNUM *pBVar14;
  char *mod;
  undefined *puVar15;
  BIGNUM *y;
  BIGNUM *unaff_s3;
  BIGNUM *unaff_s4;
  BIGNUM *unaff_s5;
  BIGNUM *unaff_s6;
  BIGNUM *pBVar16;
  BIGNUM *unaff_s7;
  int iVar17;
  code *pcVar18;
  undefined *puVar19;
  undefined *puVar20;
  BIGNUM *unaff_s8;
  undefined auStackY_1b0 [16];
  undefined4 uStackY_1a0;
  undefined *puStackY_198;
  BIGNUM *pBStackY_190;
  int iStackY_18c;
  BIGNUM *pBStackY_188;
  BIGNUM *pBStackY_184;
  BIGNUM *pBStackY_180;
  uint uStackY_17c;
  BIGNUM *pBStackY_178;
  int iStackY_174;
  BIGNUM *pBStackY_170;
  BN_MONT_CTX *pBStackY_16c;
  undefined auStackY_164 [16];
  int iStackY_154;
  BIGNUM BStackY_150;
  int iStackY_13c;
  int iStackY_138;
  undefined *puStackY_134;
  BN_CTX *pBStackY_130;
  BIGNUM *pBStackY_12c;
  BIGNUM *pBStackY_128;
  BIGNUM *pBStackY_124;
  BIGNUM *pBStackY_120;
  BIGNUM *pBStackY_11c;
  BIGNUM *pBStackY_118;
  code *pcStackY_114;
  BN_CTX *in_stack_ffffff00;
  BN_MONT_CTX *pBStack_fc;
  BN_RECP_CTX *local_f0;
  BIGNUM *local_ec;
  BIGNUM *local_e8;
  BN_RECP_CTX BStack_e0;
  BIGNUM *local_ac;
  BIGNUM local_a8 [6];
  BIGNUM *local_2c;
  
  puStackY_134 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  if ((p->flags & 4U) == 0) {
    pBVar14 = a;
    y = p;
    mod = (char *)m;
    unaff_s3 = (BIGNUM *)BN_num_bits(p);
    unaff_s4 = r;
    if (unaff_s3 == (BIGNUM *)0x0) {
      iStackY_138 = m->top;
      unaff_s7 = m;
      unaff_s8 = a;
      if (((iStackY_138 == 1) && (*m->d == 1)) && (m->neg == 0)) {
        pBVar14 = (BIGNUM *)0x0;
        BN_set_word(r,0);
      }
      else {
        pBVar14 = (BIGNUM *)0x1;
        iStackY_138 = BN_set_word(r,1);
      }
    }
    else {
      BN_CTX_start(ctx);
      unaff_s6 = BN_CTX_get(ctx);
      unaff_s5 = BN_CTX_get(ctx);
      local_ac = unaff_s5;
      if ((unaff_s6 == (BIGNUM *)0x0) || (unaff_s5 == (BIGNUM *)0x0)) {
LAB_004f0650:
        iStackY_138 = 0;
      }
      else {
        BN_RECP_CTX_init(&BStack_e0);
        pBVar14 = m;
        if (m->neg != 0) {
          pBVar4 = BN_copy(unaff_s6,m);
          if (pBVar4 != (BIGNUM *)0x0) {
            unaff_s6->neg = 0;
            pBVar14 = unaff_s6;
            y = (BIGNUM *)ctx;
            iVar17 = BN_RECP_CTX_set(&BStack_e0,unaff_s6,ctx);
            if (0 < iVar17) goto LAB_004f0480;
          }
          goto LAB_004f0650;
        }
        y = (BIGNUM *)ctx;
        iVar17 = BN_RECP_CTX_set(&BStack_e0,m,ctx);
        if (iVar17 < 1) {
          iStackY_138 = 0;
        }
        else {
LAB_004f0480:
          pBVar14 = a;
          y = m;
          mod = (char *)ctx;
          iVar17 = BN_nnmod(unaff_s5,a,m,ctx);
          if (iVar17 == 0) goto LAB_004f0650;
          if (unaff_s5->top == 0) {
            pBVar14 = (BIGNUM *)0x0;
            iStackY_138 = 1;
            BN_set_word(r,0);
            goto LAB_004f0654;
          }
          if ((int)unaff_s3 < 0x2a0) {
            if (0xef < (int)unaff_s3) {
              a = (BIGNUM *)&SUB_00000010;
              local_ec = (BIGNUM *)&DAT_00000005;
              goto LAB_004f06f0;
            }
            if (0x4f < (int)unaff_s3) {
              a = (BIGNUM *)&DAT_00000008;
              local_ec = (BIGNUM *)&SUB_00000004;
              goto LAB_004f06f0;
            }
            if (0x17 < (int)unaff_s3) {
              a = (BIGNUM *)&SUB_00000004;
              local_ec = (BIGNUM *)0x3;
              goto LAB_004f06f0;
            }
            local_ec = (BIGNUM *)0x1;
          }
          else {
            a = (BIGNUM *)&DAT_00000020;
            local_ec = (BIGNUM *)&DAT_00000006;
LAB_004f06f0:
            pBVar14 = unaff_s5;
            y = unaff_s5;
            mod = (char *)&BStack_e0;
            in_stack_ffffff00 = ctx;
            iVar17 = BN_mod_mul_reciprocal(unaff_s6,unaff_s5,unaff_s5,&BStack_e0,ctx);
            if (iVar17 == 0) goto LAB_004f0650;
            unaff_s5 = local_a8;
            m = (BIGNUM *)0x1;
            do {
              pBVar4 = BN_CTX_get(ctx);
              unaff_s5->d = (ulong *)pBVar4;
              if (pBVar4 == (BIGNUM *)0x0) {
                iStackY_138 = 0;
                goto LAB_004f0654;
              }
              pBVar14 = (BIGNUM *)unaff_s5[-1].flags;
              y = unaff_s6;
              mod = (char *)&BStack_e0;
              in_stack_ffffff00 = ctx;
              iVar17 = BN_mod_mul_reciprocal(pBVar4,pBVar14,unaff_s6,&BStack_e0,ctx);
              if (iVar17 == 0) goto LAB_004f0650;
              m = (BIGNUM *)((int)&m->d + 1);
              unaff_s5 = (BIGNUM *)&unaff_s5->top;
            } while ((int)m < (int)a);
          }
          pBVar14 = (BIGNUM *)0x1;
          iVar17 = BN_set_word(r,1);
          if (iVar17 == 0) goto LAB_004f0650;
          m = (BIGNUM *)0xffffffff;
          bVar1 = true;
          pBVar4 = (BIGNUM *)((int)&unaff_s3[-1].flags + 3);
          do {
            while (local_e8 = pBVar4, pBVar14 = local_e8, iVar17 = BN_is_bit_set(p,(int)local_e8),
                  iVar17 != 0) {
              unaff_s6 = (BIGNUM *)0x1;
              if (local_ec == (BIGNUM *)0x1) {
                unaff_s3 = (BIGNUM *)0x0;
              }
              else {
                a = (BIGNUM *)((int)&local_e8[-1].flags + 3);
                unaff_s3 = (BIGNUM *)0x0;
                if (-1 < (int)a) {
                  unaff_s5 = (BIGNUM *)0x1;
                  do {
                    iVar17 = BN_is_bit_set(p,(int)a);
                    if (iVar17 != 0) {
                      unaff_s6 = (BIGNUM *)
                                 ((int)unaff_s6 << ((int)unaff_s5 - (int)unaff_s3 & 0x1fU) | 1);
                      unaff_s3 = unaff_s5;
                    }
                    unaff_s5 = (BIGNUM *)((int)&unaff_s5->d + 1);
                    pBVar14 = (BIGNUM *)((int)&a[-1].flags + 3);
                  } while ((unaff_s5 != local_ec) && (a = pBVar14, pBVar14 != (BIGNUM *)0xffffffff))
                  ;
                }
              }
              if (!bVar1) {
                unaff_s5 = (BIGNUM *)0x0;
                do {
                  pBVar14 = r;
                  y = r;
                  mod = (char *)&BStack_e0;
                  in_stack_ffffff00 = ctx;
                  iVar17 = BN_mod_mul_reciprocal(r,r,r,&BStack_e0,ctx);
                  if (iVar17 == 0) goto LAB_004f0650;
                  unaff_s5 = (BIGNUM *)((int)&unaff_s5->d + 1);
                } while ((int)unaff_s5 <= (int)unaff_s3);
              }
              y = *(BIGNUM **)((int)local_a8 + ((int)unaff_s6 >> 1) * 4 + -4);
              pBVar14 = r;
              mod = (char *)&BStack_e0;
              in_stack_ffffff00 = ctx;
              iVar17 = BN_mod_mul_reciprocal(r,r,y,&BStack_e0,ctx);
              if (iVar17 == 0) goto LAB_004f0650;
              pBVar5 = (BIGNUM *)((int)&unaff_s3->d + 1);
              pBVar4 = (BIGNUM *)((int)local_e8 - (int)pBVar5);
              local_e8 = pBVar5;
              if ((int)pBVar4 < 0) goto LAB_004f0798;
              bVar1 = false;
            }
            if ((!bVar1) &&
               (pBVar14 = r, y = r, mod = (char *)&BStack_e0, in_stack_ffffff00 = ctx,
               iVar17 = BN_mod_mul_reciprocal(r,r,r,&BStack_e0,ctx), iVar17 == 0)) {
              iStackY_138 = 0;
              unaff_s3 = local_e8;
              goto LAB_004f0654;
            }
            pBVar4 = (BIGNUM *)((int)&local_e8[-1].flags + 3);
          } while (local_e8 != (BIGNUM *)0x0);
LAB_004f0798:
          iStackY_138 = 1;
          unaff_s3 = local_e8;
        }
      }
LAB_004f0654:
      local_f0 = &BStack_e0;
      BN_CTX_end(ctx);
      BN_RECP_CTX_free(local_f0);
      unaff_s7 = m;
      unaff_s8 = a;
    }
  }
  else {
    y = (BIGNUM *)0x42;
    mod = "bn_exp.c";
    in_stack_ffffff00 = (BN_CTX *)0x10e;
    pBVar14 = (BIGNUM *)0x7d;
    iStackY_138 = -1;
    (*(code *)PTR_ERR_put_error_006a7f34)(3);
  }
  if (local_2c == *(BIGNUM **)puStackY_134) {
    return iStackY_138;
  }
  pcStackY_114 = BN_mod_exp_mont_consttime;
  pBVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  puVar15 = auStackY_1b0;
  puVar19 = auStackY_1b0;
  puVar20 = auStackY_1b0;
  iVar17 = ((BIGNUM *)mod)->top;
  pBStackY_130 = ctx;
  puStackY_198 = &_gp;
  iStackY_13c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pBStackY_12c = unaff_s3;
  pBStackY_128 = unaff_s4;
  pBStackY_124 = unaff_s5;
  pBStackY_120 = unaff_s6;
  pBStackY_11c = unaff_s7;
  pBStackY_118 = unaff_s8;
  if ((iVar17 < 1) || ((*((BIGNUM *)mod)->d & 1) == 0)) {
    uStackY_1a0 = 0x28d;
    y = (BIGNUM *)0x0;
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7c,0x66,"bn_exp.c");
    pBVar4 = unaff_s3;
    pBVar14 = unaff_s5;
    puVar19 = auStackY_1b0;
    goto LAB_004f089c;
  }
  pBVar5 = (BIGNUM *)BN_num_bits(y);
  if (pBVar5 == (BIGNUM *)0x0) {
    y = (BIGNUM *)((BIGNUM *)mod)->top;
    if (((y == (BIGNUM *)0x1) && (*((BIGNUM *)mod)->d == 1)) && (((BIGNUM *)mod)->neg == 0)) {
      BN_set_word(pBVar4,0);
      puVar19 = auStackY_1b0;
      goto LAB_004f089c;
    }
    y = (BIGNUM *)BN_set_word(pBVar4,1);
    puVar19 = auStackY_1b0;
    goto LAB_004f089c;
  }
  pBStackY_170 = pBVar5;
  BN_CTX_start(in_stack_ffffff00);
  pBStackY_16c = pBStack_fc;
  if (pBStack_fc == (BN_MONT_CTX *)0x0) {
    pBStackY_16c = BN_MONT_CTX_new();
    if (pBStackY_16c == (BN_MONT_CTX *)0x0) goto LAB_004f0f90;
    iVar9 = BN_MONT_CTX_set(pBStackY_16c,(BIGNUM *)mod,in_stack_ffffff00);
    if (iVar9 == 0) {
      y = (BIGNUM *)0x0;
      pBStackY_170 = (BIGNUM *)0x0;
      iStackY_174 = 0;
      uStackY_17c = 0;
      goto LAB_004f0f68;
    }
  }
  if ((int)pBStackY_170 < 0x3aa) {
    if ((int)pBStackY_170 < 0x133) {
      if ((int)pBStackY_170 < 0x5a) {
        pBStackY_178 = (BIGNUM *)&DAT_00000008;
        if ((int)pBStackY_170 < 0x17) {
          pBStackY_178 = (BIGNUM *)&SUB_00000002;
        }
        iStackY_18c = 3;
        pBStackY_180 = pBStackY_178;
        if ((int)pBStackY_170 < 0x17) {
          iStackY_18c = 1;
        }
      }
      else {
        pBStackY_180 = (BIGNUM *)0x10;
        pBStackY_178 = (BIGNUM *)&SUB_00000010;
        iStackY_18c = 4;
      }
    }
    else {
      pBStackY_180 = (BIGNUM *)0x20;
      pBStackY_178 = (BIGNUM *)&DAT_00000020;
      iStackY_18c = 5;
    }
  }
  else {
    pBStackY_180 = (BIGNUM *)0x40;
    pBStackY_178 = (BIGNUM *)&DAT_00000040;
    iStackY_18c = 6;
  }
  pBVar5 = pBStackY_178;
  if ((int)pBStackY_178 <= (int)(BIGNUM *)(iVar17 << 1)) {
    pBVar5 = (BIGNUM *)(iVar17 << 1);
  }
  iStackY_174 = (int)((int)&pBVar5->d + iVar17 * (int)pBStackY_178) * 4;
  pBStackY_180 = pBStackY_178;
  if (iStackY_174 < 0xc00) {
    pBStackY_184 = pBStackY_170;
    puVar19 = auStackY_1b0 + -(iStackY_174 + 0x48);
    uVar6 = (int)&puStackY_198 + -(iStackY_174 + 0x48);
    pBStackY_170 = (BIGNUM *)((uVar6 - (uVar6 & 0x3f)) + 0x40);
    (**(code **)(puStackY_198 + -0x53ec))(pBStackY_170,0);
    uStackY_17c = 0;
  }
  else {
    uStackY_17c = (**(code **)(puStackY_198 + -0x7dd8))(iStackY_174 + 0x40,"bn_exp.c",0x2c5);
    if (uStackY_17c == 0) {
      if (pBStack_fc == (BN_MONT_CTX *)0x0) {
        pBStackY_170 = (BIGNUM *)0x0;
        y = (BIGNUM *)0x0;
        puVar15 = auStackY_1b0;
        goto LAB_004f0f68;
      }
LAB_004f0f90:
      y = (BIGNUM *)0x0;
      goto LAB_004f0b1c;
    }
    pBStackY_184 = pBStackY_170;
    pBStackY_170 = (BIGNUM *)((uStackY_17c - (uStackY_17c & 0x3f)) + 0x40);
    (**(code **)(puStackY_198 + -0x53ec))(pBStackY_170,0,iStackY_174);
  }
  iVar9 = iVar17 * 4 * (int)pBStackY_178;
  pBStackY_188 = pBStackY_184;
  BStackY_150.flags = 2;
  iStackY_154 = 2;
  pBStackY_178 = (BIGNUM *)auStackY_164;
  BStackY_150.dmax = iVar17;
  pBStackY_184 = &pBStackY_16c->RR;
  auStackY_164._0_4_ = (ulong **)((int)&pBStackY_170->d + iVar9);
  auStackY_164._8_4_ = iVar17;
  BStackY_150.top = 0;
  auStackY_164._4_4_ = 0;
  BStackY_150.neg = 0;
  BStackY_150.d = (ulong *)(auStackY_164._0_4_ + iVar17);
  auStackY_164._12_4_ = 0;
  pBVar7 = BN_value_one();
  pBVar2 = pBStackY_16c;
  pBVar16 = pBStackY_178;
  pBVar5 = pBStackY_184;
  *(BN_CTX **)(puVar19 + 0x10) = in_stack_ffffff00;
  iVar9 = BN_mod_mul_montgomery(pBVar16,pBVar7,pBVar5,pBVar2,*(BN_CTX **)(puVar19 + 0x10));
  if (iVar9 == 0) goto LAB_004f0ae8;
  if (pBVar14->neg == 0) {
    iVar9 = BN_ucmp(pBVar14,(BIGNUM *)mod);
    pBVar2 = pBStackY_16c;
    pBVar5 = pBStackY_184;
    if (iVar9 < 0) {
      pBStackY_190 = pBStackY_188;
      pBStackY_188 = &BStackY_150;
      *(BN_CTX **)(puVar19 + 0x10) = in_stack_ffffff00;
      iVar9 = BN_mod_mul_montgomery(&BStackY_150,pBVar14,pBVar5,pBVar2,*(BN_CTX **)(puVar19 + 0x10))
      ;
      pBVar5 = pBStackY_190;
      pBVar16 = pBStackY_188;
      pBVar7 = pBStackY_178;
      pBVar2 = pBStackY_16c;
      goto joined_r0x004f0fdc;
    }
  }
  pcVar18 = *(code **)(puStackY_198 + -0x6884);
  pBStackY_190 = pBStackY_188;
  *(BN_CTX **)(puVar19 + 0x10) = in_stack_ffffff00;
  pBStackY_188 = &BStackY_150;
  iVar9 = (*pcVar18)(0,&BStackY_150,pBVar14,mod);
  pBVar2 = pBStackY_16c;
  pBVar16 = pBStackY_184;
  pBVar5 = pBStackY_188;
  if (iVar9 == 0) goto LAB_004f0ae8;
  *(BN_CTX **)(puVar19 + 0x10) = in_stack_ffffff00;
  iVar9 = BN_mod_mul_montgomery(pBVar5,pBVar5,pBVar16,pBVar2,*(BN_CTX **)(puVar19 + 0x10));
  pBVar5 = pBStackY_190;
  pBVar16 = pBStackY_188;
  pBVar7 = pBStackY_178;
  pBVar2 = pBStackY_16c;
joined_r0x004f0fdc:
  pBStackY_190 = pBVar5;
  pBStackY_188 = pBVar16;
  pBStackY_178 = pBVar7;
  pBStackY_16c = pBVar2;
  if (iVar9 == 0) goto LAB_004f0ae8;
  iVar9 = auStackY_164._4_4_;
  if (iVar17 <= auStackY_164._4_4_) {
    iVar9 = iVar17;
  }
  if (0 < iVar9) {
    ppuVar8 = auStackY_164._0_4_;
    pBVar11 = pBStackY_170;
    do {
      puVar13 = *ppuVar8;
      ppuVar8 = ppuVar8 + 1;
      pBVar11->d = puVar13;
      pBVar11 = (BIGNUM *)(&pBVar11->d + (int)pBStackY_180);
    } while (ppuVar8 != auStackY_164._0_4_ + iVar9);
  }
  iVar9 = BStackY_150.top;
  if (iVar17 <= BStackY_150.top) {
    iVar9 = iVar17;
  }
  if (0 < iVar9) {
    piVar12 = &pBStackY_170->top;
    ppuVar8 = (ulong **)BStackY_150.d;
    do {
      puVar13 = *ppuVar8;
      ppuVar8 = ppuVar8 + 1;
      *piVar12 = (int)puVar13;
      piVar12 = piVar12 + (int)pBStackY_180;
    } while (ppuVar8 != (ulong **)BStackY_150.d + iVar9);
  }
  if (iStackY_18c == 1) {
    pBStackY_190 = (BIGNUM *)0x0;
    pBVar14 = (BIGNUM *)((int)&pBVar5[-1].flags + 3);
  }
  else {
    pBStackY_184 = pBVar5;
    *(BN_CTX **)(puVar19 + 0x10) = in_stack_ffffff00;
    iVar9 = BN_mod_mul_montgomery(pBVar7,pBVar16,pBVar16,pBVar2,*(BN_CTX **)(puVar19 + 0x10));
    pBVar16 = pBStackY_180;
    pBVar5 = pBStackY_184;
    if (iVar9 == 0) goto LAB_004f0ae8;
    iVar9 = auStackY_164._4_4_;
    if (iVar17 <= auStackY_164._4_4_) {
      iVar9 = iVar17;
    }
    if (0 < iVar9) {
      piVar12 = &pBStackY_170->dmax;
      ppuVar8 = auStackY_164._0_4_;
      do {
        puVar13 = *ppuVar8;
        ppuVar8 = ppuVar8 + 1;
        *piVar12 = (int)puVar13;
        piVar12 = piVar12 + (int)pBStackY_180;
      } while (auStackY_164._0_4_ + iVar9 != ppuVar8);
    }
    if (3 < (int)pBStackY_180) {
      pBVar14 = (BIGNUM *)&pBStackY_170->neg;
      pBStackY_184 = (BIGNUM *)(&pBStackY_170->d + (int)pBStackY_180);
      pBStackY_180 = pBVar5;
      do {
        pBVar2 = pBStackY_16c;
        pBVar7 = pBStackY_178;
        pBVar5 = pBStackY_188;
        *(BN_CTX **)(puVar19 + 0x10) = in_stack_ffffff00;
        iVar9 = BN_mod_mul_montgomery(pBVar7,pBVar5,pBVar7,pBVar2,*(BN_CTX **)(puVar19 + 0x10));
        if (iVar9 == 0) goto LAB_004f0ae8;
        iVar9 = auStackY_164._4_4_;
        if (iVar17 <= auStackY_164._4_4_) {
          iVar9 = iVar17;
        }
        if (0 < iVar9) {
          ppuVar8 = auStackY_164._0_4_;
          pBVar5 = pBVar14;
          do {
            puVar13 = *ppuVar8;
            ppuVar8 = ppuVar8 + 1;
            pBVar5->d = puVar13;
            pBVar5 = (BIGNUM *)(&pBVar5->d + (int)pBVar16);
          } while (ppuVar8 != auStackY_164._0_4_ + iVar9);
        }
        pBVar14 = (BIGNUM *)&pBVar14->top;
        pBVar5 = pBStackY_180;
      } while (pBVar14 != pBStackY_184);
    }
    pBVar14 = (BIGNUM *)((int)&pBVar5[-1].flags + 3);
    if (iStackY_18c == 0) {
      trap(7);
    }
    pBStackY_190 = (BIGNUM *)((int)pBVar14 % iStackY_18c);
    if ((int)(BIGNUM *)((int)pBVar14 % iStackY_18c) < 0) goto LAB_004f0ff4;
  }
  puVar15 = (undefined *)0x0;
  pBStackY_184 = (BIGNUM *)((int)pBStackY_190 - (int)pBVar14);
  pBVar5 = pBVar14;
  do {
    pBStackY_180 = (BIGNUM *)((int)puVar15 << 1);
    pBVar16 = (BIGNUM *)((int)&pBVar5[-1].flags + 3);
    iVar9 = BN_is_bit_set(y,(int)pBVar5);
    puVar15 = (undefined *)((int)&pBStackY_180->d + iVar9);
    pBVar5 = pBVar16;
  } while (-1 < (int)((int)&pBVar16->d + (int)&pBStackY_184->d));
  pBVar5 = pBStackY_190;
  if ((int)pBStackY_190 < 0) {
    pBVar5 = (BIGNUM *)0x0;
  }
  pBVar14 = (BIGNUM *)((int)pBVar14 + (-1 - (int)pBVar5));
  do {
    pBVar16 = pBStackY_170;
    pBVar5 = pBStackY_178;
    *(int *)(puVar19 + 0x10) = iStackY_18c;
    iVar9 = MOD_EXP_CTIME_COPY_FROM_PREBUF(pBVar5,iVar17,pBVar16,puVar15);
    if (iVar9 == 0) {
LAB_004f0ae8:
      y = (BIGNUM *)0x0;
    }
    else {
      do {
        if ((int)pBVar14 < 0) {
          iVar9 = BN_from_montgomery(pBVar4,pBStackY_178,pBStackY_16c,in_stack_ffffff00);
          y = (BIGNUM *)(uint)(iVar9 != 0);
          goto LAB_004f0aec;
        }
        iVar9 = 0;
        pBStackY_180 = (BIGNUM *)((int)pBVar14 - iStackY_18c);
        do {
          pBVar2 = pBStackY_16c;
          pBVar5 = pBStackY_178;
          *(BN_CTX **)(puVar19 + 0x10) = in_stack_ffffff00;
          iVar10 = BN_mod_mul_montgomery(pBVar5,pBVar5,pBVar5,pBVar2,*(BN_CTX **)(puVar19 + 0x10));
          if (iVar10 == 0) goto LAB_004f0ae8;
          iVar10 = BN_is_bit_set(y,(int)pBVar14);
          pBVar16 = pBStackY_170;
          pBVar5 = pBStackY_188;
          pBVar14 = (BIGNUM *)((int)&pBVar14[-1].flags + 3);
          iVar9 = iVar9 * 2 + iVar10;
        } while (pBVar14 != pBStackY_180);
        *(int *)(puVar19 + 0x10) = iStackY_18c;
        iVar9 = MOD_EXP_CTIME_COPY_FROM_PREBUF(pBVar5,iVar17,pBVar16,iVar9);
        pBVar2 = pBStackY_16c;
        pBVar16 = pBStackY_178;
        if (iVar9 == 0) goto LAB_004f0ae8;
        *(BN_CTX **)(puVar19 + 0x10) = in_stack_ffffff00;
        iVar9 = BN_mod_mul_montgomery(pBVar16,pBVar16,pBVar5,pBVar2,*(BN_CTX **)(puVar19 + 0x10));
      } while (iVar9 != 0);
      y = (BIGNUM *)0x0;
    }
LAB_004f0aec:
    pcVar18 = *(code **)(puStackY_198 + -0x7d6c);
    puVar15 = puVar19;
    if (pBStack_fc == (BN_MONT_CTX *)0x0) {
LAB_004f0f68:
      BN_MONT_CTX_free(pBStackY_16c);
      puVar20 = puVar15;
      if (pBStackY_170 != (BIGNUM *)0x0) {
        pcVar18 = *(code **)(puStackY_198 + -0x7d6c);
        goto LAB_004f0af4;
      }
    }
    else {
LAB_004f0af4:
      (*pcVar18)(pBStackY_170,iStackY_174);
      puVar20 = puVar15;
      if (uStackY_17c != 0) {
        (**(code **)(puStackY_198 + -0x7f58))(uStackY_17c);
      }
    }
LAB_004f0b1c:
    BN_CTX_end(in_stack_ffffff00);
    puVar19 = puVar20;
LAB_004f089c:
    if (iStackY_13c == *(int *)puVar3) {
      return (int)y;
    }
    (**(code **)(puStackY_198 + -0x5330))();
LAB_004f0ff4:
    puVar15 = (undefined *)0x0;
  } while( true );
}

