
int BN_mod_exp_recp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  BN_MONT_CTX *pBVar4;
  uint *puVar5;
  uint uVar6;
  undefined *puVar7;
  char *a_00;
  int *piVar8;
  int iVar9;
  undefined4 uVar10;
  undefined *puVar11;
  BIGNUM *pBVar12;
  BN_MONT_CTX *pBVar13;
  BN_MONT_CTX *pBVar14;
  BN_MONT_CTX *pBVar15;
  BN_MONT_CTX *pBVar16;
  char *mod;
  char *mont;
  BN_MONT_CTX *unaff_s1;
  BN_CTX *ctx_00;
  BN_MONT_CTX *pBVar17;
  BN_RECP_CTX *unaff_s3;
  BN_MONT_CTX *pBVar18;
  BN_MONT_CTX *unaff_s4;
  int iVar19;
  BN_MONT_CTX *unaff_s5;
  BN_MONT_CTX *unaff_s6;
  int iVar20;
  int iVar21;
  BN_MONT_CTX *unaff_s7;
  undefined *puVar22;
  undefined *puVar23;
  undefined *puVar24;
  undefined *puVar25;
  undefined *puVar26;
  undefined *puVar27;
  undefined *puVar28;
  BN_MONT_CTX *unaff_s8;
  BIGNUM **ppBVar29;
  code *pcVar30;
  undefined auStackY_110 [16];
  BN_MONT_CTX *local_ec;
  BN_MONT_CTX *local_e8;
  undefined auStack_e0 [180];
  BN_MONT_CTX *local_2c;
  
  pBVar17 = (BN_MONT_CTX *)PTR___stack_chk_guard_006aabf0;
  local_2c = *(BN_MONT_CTX **)PTR___stack_chk_guard_006aabf0;
  if ((p->flags & 4U) != 0) {
    pBVar15 = (BN_MONT_CTX *)0x42;
    mod = "bn_exp.c";
    pBVar14 = (BN_MONT_CTX *)0x7d;
    (*(code *)PTR_ERR_put_error_006a9030)(3);
    pBVar4 = (BN_MONT_CTX *)0xffffffff;
    goto LAB_004f3278;
  }
  pBVar14 = (BN_MONT_CTX *)a;
  pBVar15 = (BN_MONT_CTX *)p;
  mod = (char *)m;
  unaff_s4 = (BN_MONT_CTX *)BN_num_bits(p);
  unaff_s6 = (BN_MONT_CTX *)r;
  if (unaff_s4 == (BN_MONT_CTX *)0x0) {
    pBVar14 = (BN_MONT_CTX *)0x1;
    pBVar4 = (BN_MONT_CTX *)BN_set_word(r,1);
    unaff_s1 = (BN_MONT_CTX *)p;
    unaff_s7 = (BN_MONT_CTX *)m;
    goto LAB_004f3278;
  }
  BN_CTX_start(ctx);
  unaff_s5 = (BN_MONT_CTX *)BN_CTX_get(ctx);
  unaff_s8 = (BN_MONT_CTX *)BN_CTX_get(ctx);
  auStack_e0._52_4_ = unaff_s8;
  if ((unaff_s5 == (BN_MONT_CTX *)0x0) || (unaff_s8 == (BN_MONT_CTX *)0x0)) goto LAB_004f3250;
  BN_RECP_CTX_init((BN_RECP_CTX *)(BN_MONT_CTX *)auStack_e0);
  pBVar14 = (BN_MONT_CTX *)m;
  if (m->neg == 0) {
    pBVar15 = (BN_MONT_CTX *)ctx;
    iVar3 = BN_RECP_CTX_set((BN_RECP_CTX *)(BN_MONT_CTX *)auStack_e0,m,ctx);
    if (0 < iVar3) {
LAB_004f30a8:
      pBVar15 = (BN_MONT_CTX *)m;
      mod = (char *)ctx;
      iVar3 = BN_nnmod((BIGNUM *)unaff_s8,a,m,ctx);
      pBVar14 = (BN_MONT_CTX *)a;
      if (iVar3 != 0) {
        if ((unaff_s8->RR).d == (ulong *)0x0) {
          pBVar14 = (BN_MONT_CTX *)0x0;
          pBVar4 = (BN_MONT_CTX *)0x1;
          BN_set_word(r,0);
          goto LAB_004f3254;
        }
        if ((int)unaff_s4 < 0x2a0) {
          if (0xef < (int)unaff_s4) {
            local_ec = (BN_MONT_CTX *)0x10;
            local_e8 = (BN_MONT_CTX *)&DAT_00000005;
            goto LAB_004f3318;
          }
          if (0x4f < (int)unaff_s4) {
            local_ec = (BN_MONT_CTX *)0x8;
            local_e8 = (BN_MONT_CTX *)&SUB_00000004;
            goto LAB_004f3318;
          }
          if (0x17 < (int)unaff_s4) {
            local_ec = (BN_MONT_CTX *)0x4;
            local_e8 = (BN_MONT_CTX *)0x3;
            goto LAB_004f3318;
          }
          local_e8 = (BN_MONT_CTX *)0x1;
        }
        else {
          local_ec = (BN_MONT_CTX *)0x20;
          local_e8 = (BN_MONT_CTX *)&DAT_00000006;
LAB_004f3318:
          pBVar14 = unaff_s8;
          pBVar15 = unaff_s8;
          mod = (char *)(BN_MONT_CTX *)auStack_e0;
          iVar3 = BN_mod_mul_reciprocal
                            ((BIGNUM *)unaff_s5,(BIGNUM *)unaff_s8,(BIGNUM *)unaff_s8,
                             (BN_RECP_CTX *)(BN_MONT_CTX *)auStack_e0,ctx);
          if (iVar3 == 0) goto LAB_004f3250;
          unaff_s8 = (BN_MONT_CTX *)(auStack_e0 + 0x38);
          m = (BIGNUM *)0x1;
          do {
            pBVar12 = BN_CTX_get(ctx);
            unaff_s8->ri = (int)pBVar12;
            if (pBVar12 == (BIGNUM *)0x0) goto LAB_004f3250;
            pBVar14 = (BN_MONT_CTX *)unaff_s8[-1].flags;
            pBVar15 = unaff_s5;
            mod = (char *)(BN_MONT_CTX *)auStack_e0;
            iVar3 = BN_mod_mul_reciprocal
                              (pBVar12,(BIGNUM *)pBVar14,(BIGNUM *)unaff_s5,
                               (BN_RECP_CTX *)(BN_MONT_CTX *)auStack_e0,ctx);
            if (iVar3 == 0) goto LAB_004f3250;
            m = (BIGNUM *)((int)&((BN_MONT_CTX *)m)->ri + 1);
            unaff_s8 = (BN_MONT_CTX *)&unaff_s8->RR;
          } while ((int)m < (int)local_ec);
        }
        pBVar14 = (BN_MONT_CTX *)0x1;
        iVar3 = BN_set_word(r,1);
        if (iVar3 != 0) {
          bVar1 = true;
          pBVar4 = (BN_MONT_CTX *)((int)&unaff_s4[-1].flags + 3);
          do {
            while (local_ec = pBVar4, pBVar14 = local_ec, iVar3 = BN_is_bit_set(p,(int)local_ec),
                  iVar3 != 0) {
              unaff_s5 = (BN_MONT_CTX *)0x1;
              if (local_e8 == (BN_MONT_CTX *)0x1) {
                unaff_s4 = (BN_MONT_CTX *)0x0;
              }
              else {
                m = (BIGNUM *)((int)&local_ec[-1].flags + 3);
                unaff_s4 = (BN_MONT_CTX *)0x0;
                if (-1 < (int)m) {
                  unaff_s8 = (BN_MONT_CTX *)0x1;
                  do {
                    iVar3 = BN_is_bit_set(p,(int)m);
                    if (iVar3 != 0) {
                      unaff_s5 = (BN_MONT_CTX *)
                                 ((int)unaff_s5 << ((int)unaff_s8 - (int)unaff_s4 & 0x1fU) | 1);
                      unaff_s4 = unaff_s8;
                    }
                    unaff_s8 = (BN_MONT_CTX *)((int)&unaff_s8->ri + 1);
                  } while ((unaff_s8 != local_e8) &&
                          (m = (BIGNUM *)((int)&((BN_MONT_CTX *)((int)m + -0x4c))->flags + 3),
                          (BN_MONT_CTX *)m != (BN_MONT_CTX *)0xffffffff));
                }
              }
              if (!bVar1) {
                unaff_s8 = (BN_MONT_CTX *)0x0;
                do {
                  pBVar14 = (BN_MONT_CTX *)r;
                  pBVar15 = (BN_MONT_CTX *)r;
                  mod = (char *)(BN_MONT_CTX *)auStack_e0;
                  iVar3 = BN_mod_mul_reciprocal(r,r,r,(BN_RECP_CTX *)(BN_MONT_CTX *)auStack_e0,ctx);
                  if (iVar3 == 0) goto LAB_004f3250;
                  unaff_s8 = (BN_MONT_CTX *)((int)&unaff_s8->ri + 1);
                } while ((int)unaff_s8 <= (int)unaff_s4);
              }
              pBVar15 = *(BN_MONT_CTX **)(auStack_e0 + ((int)unaff_s5 >> 1) * 4 + 0x34);
              pBVar14 = (BN_MONT_CTX *)r;
              mod = (char *)(BN_MONT_CTX *)auStack_e0;
              iVar3 = BN_mod_mul_reciprocal
                                (r,r,(BIGNUM *)pBVar15,(BN_RECP_CTX *)(BN_MONT_CTX *)auStack_e0,ctx)
              ;
              if (iVar3 == 0) goto LAB_004f3250;
              pBVar18 = (BN_MONT_CTX *)((int)&unaff_s4->ri + 1);
              pBVar4 = (BN_MONT_CTX *)((int)local_ec - (int)pBVar18);
              local_ec = pBVar18;
              if ((int)pBVar4 < 0) goto LAB_004f3410;
              bVar1 = false;
            }
            if ((!bVar1) &&
               (pBVar14 = (BN_MONT_CTX *)r, pBVar15 = (BN_MONT_CTX *)r,
               mod = (char *)(BN_MONT_CTX *)auStack_e0,
               iVar3 = BN_mod_mul_reciprocal(r,r,r,(BN_RECP_CTX *)(BN_MONT_CTX *)auStack_e0,ctx),
               iVar3 == 0)) {
              pBVar4 = (BN_MONT_CTX *)0x0;
              unaff_s4 = local_ec;
              goto LAB_004f3254;
            }
            pBVar4 = (BN_MONT_CTX *)((int)&local_ec[-1].flags + 3);
          } while (local_ec != (BN_MONT_CTX *)0x0);
LAB_004f3410:
          pBVar4 = (BN_MONT_CTX *)0x1;
          unaff_s4 = local_ec;
          goto LAB_004f3254;
        }
      }
    }
LAB_004f3250:
    pBVar4 = (BN_MONT_CTX *)0x0;
  }
  else {
    pBVar12 = BN_copy((BIGNUM *)unaff_s5,m);
    if (pBVar12 == (BIGNUM *)0x0) goto LAB_004f3250;
    (unaff_s5->RR).dmax = 0;
    pBVar14 = unaff_s5;
    pBVar15 = (BN_MONT_CTX *)ctx;
    iVar3 = BN_RECP_CTX_set((BN_RECP_CTX *)(BN_MONT_CTX *)auStack_e0,(BIGNUM *)unaff_s5,ctx);
    if (0 < iVar3) goto LAB_004f30a8;
    pBVar4 = (BN_MONT_CTX *)0x0;
  }
LAB_004f3254:
  unaff_s3 = (BN_RECP_CTX *)auStack_e0;
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(unaff_s3);
  unaff_s1 = pBVar4;
  unaff_s7 = (BN_MONT_CTX *)m;
LAB_004f3278:
  if (local_2c == *(BN_MONT_CTX **)pBVar17) {
    return (int)pBVar4;
  }
  pcVar30 = BN_mod_exp_mont_consttime;
  pBVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar27 = auStackY_110;
  do {
    puVar2 = PTR___stack_chk_guard_006aabf0;
    puVar5 = (uint *)*(int *)mod;
    puVar11 = puVar27 + -0xa8;
    puVar28 = puVar27 + -0xa8;
    puVar7 = puVar27 + -0xa8;
    *(BN_MONT_CTX **)(puVar27 + -8) = unaff_s8;
    *(BN_CTX **)(puVar27 + -0x28) = ctx;
    uVar6 = *puVar5;
    *(BN_RECP_CTX **)(puVar27 + -0x1c) = unaff_s3;
    *(undefined4 *)(puVar27 + -0x5c) = *(undefined4 *)(puVar27 + 0x14);
    *(code **)(puVar27 + -4) = pcVar30;
    *(BN_MONT_CTX **)(puVar27 + -0xc) = unaff_s7;
    *(BN_MONT_CTX **)(puVar27 + -0x10) = unaff_s6;
    *(BN_MONT_CTX **)(puVar27 + -0x14) = unaff_s5;
    *(BN_MONT_CTX **)(puVar27 + -0x18) = unaff_s4;
    *(BN_MONT_CTX **)(puVar27 + -0x20) = pBVar17;
    *(BN_MONT_CTX **)(puVar27 + -0x24) = unaff_s1;
    *(undefined **)(puVar27 + -0x90) = &_gp;
    *(BN_MONT_CTX **)(puVar27 + -100) = pBVar4;
    pBVar18 = *(BN_MONT_CTX **)(puVar27 + 0x10);
    *(undefined4 *)(puVar27 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006aabf0;
    if ((uVar6 & 1) == 0) {
      pBVar16 = (BN_MONT_CTX *)0x66;
      mont = "bn_exp.c";
      *(undefined4 *)(puVar27 + -0x98) = 599;
      a_00 = &DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(3);
      pBVar15 = (BN_MONT_CTX *)0x0;
      puVar24 = *(undefined **)(puVar27 + -0x90);
    }
    else {
      pBVar17 = (BN_MONT_CTX *)((BIGNUM *)((int)mod + 4))->d;
      a_00 = (char *)pBVar14;
      pBVar16 = pBVar15;
      mont = mod;
      unaff_s5 = (BN_MONT_CTX *)BN_num_bits((BIGNUM *)pBVar15);
      unaff_s4 = pBVar15;
      if (unaff_s5 == (BN_MONT_CTX *)0x0) {
        a_00 = (char *)0x1;
        pBVar15 = (BN_MONT_CTX *)BN_set_word(*(BIGNUM **)(puVar27 + -100),1);
        puVar24 = *(undefined **)(puVar27 + -0x90);
        unaff_s1 = (BN_MONT_CTX *)mod;
        unaff_s6 = pBVar14;
        puVar11 = puVar27 + -0xa8;
      }
      else {
        BN_CTX_start((BN_CTX *)pBVar18);
        puVar22 = *(undefined **)(puVar27 + -0x90);
        *(int *)(puVar27 + -0x60) = *(int *)(puVar27 + -0x5c);
        if (*(int *)(puVar27 + -0x5c) == 0) {
          pBVar4 = BN_MONT_CTX_new();
          *(BN_MONT_CTX **)(puVar27 + -0x60) = pBVar4;
          if (pBVar4 != (BN_MONT_CTX *)0x0) {
            a_00 = mod;
            pBVar16 = pBVar18;
            iVar3 = BN_MONT_CTX_set(pBVar4,(BIGNUM *)mod,(BN_CTX *)pBVar18);
            puVar22 = *(undefined **)(puVar27 + -0x90);
            if (iVar3 != 0) goto LAB_004f352c;
            pBVar15 = (BN_MONT_CTX *)0x0;
            *(undefined4 *)(puVar27 + -0x68) = 0;
            *(undefined4 *)(puVar27 + -0x6c) = 0;
            *(undefined4 *)(puVar27 + -0x74) = 0;
            puVar28 = puVar27 + -0xa8;
LAB_004f3c20:
            BN_MONT_CTX_free(*(BN_MONT_CTX **)(puVar27 + -0x60));
            puVar25 = *(undefined **)(puVar27 + -0x90);
            goto LAB_004f3c2c;
          }
LAB_004f3c4c:
          pBVar15 = (BN_MONT_CTX *)0x0;
        }
        else {
LAB_004f352c:
          if ((int)unaff_s5 < 0x3aa) {
            if ((int)unaff_s5 < 0x133) {
              if ((int)unaff_s5 < 0x5a) {
                pBVar4 = (BN_MONT_CTX *)&DAT_00000008;
                if ((int)unaff_s5 < 0x17) {
                  pBVar4 = (BN_MONT_CTX *)&SUB_00000002;
                }
                uVar10 = 3;
                *(BN_MONT_CTX **)(puVar27 + -0x78) = pBVar4;
                if ((int)unaff_s5 < 0x17) {
                  uVar10 = 1;
                }
                *(undefined4 *)(puVar27 + -0x84) = uVar10;
                unaff_s7 = pBVar4;
              }
              else {
                unaff_s7 = (BN_MONT_CTX *)&SUB_00000010;
                *(undefined4 *)(puVar27 + -0x78) = 0x10;
                pBVar4 = *(BN_MONT_CTX **)(puVar27 + -0x78);
                *(undefined4 *)(puVar27 + -0x84) = 4;
              }
            }
            else {
              unaff_s7 = (BN_MONT_CTX *)&DAT_00000020;
              *(undefined4 *)(puVar27 + -0x78) = 0x20;
              pBVar4 = *(BN_MONT_CTX **)(puVar27 + -0x78);
              *(undefined4 *)(puVar27 + -0x84) = 5;
            }
          }
          else {
            *(undefined4 *)(puVar27 + -0x78) = 0x40;
            pBVar4 = *(BN_MONT_CTX **)(puVar27 + -0x78);
            *(undefined4 *)(puVar27 + -0x84) = 6;
            unaff_s7 = (BN_MONT_CTX *)&DAT_00000040;
          }
          pBVar16 = pBVar4;
          if ((int)pBVar4 <= (int)(BN_MONT_CTX *)((int)pBVar17 << 1)) {
            pBVar16 = (BN_MONT_CTX *)((int)pBVar17 << 1);
          }
          iVar3 = ((int)pBVar16->n0 + (int)pBVar17 * (int)pBVar4 + -0x40) * 4;
          *(int *)(puVar27 + -0x6c) = iVar3;
          if (iVar3 < 0xc00) {
            pcVar30 = *(code **)(puVar22 + -0x53e0);
            puVar28 = puVar27 + -(iVar3 + 0x48) + -0xa8;
            puVar7 = puVar27 + -(iVar3 + 0x48) + -0x90;
            *(undefined **)(puVar27 + -0x68) = puVar7 + (0x40 - ((uint)puVar7 & 0x3f));
            (*pcVar30)(puVar7 + (0x40 - ((uint)puVar7 & 0x3f)),0);
            *(undefined4 *)(puVar27 + -0x74) = 0;
          }
          else {
            a_00 = "bn_exp.c";
            pBVar16 = (BN_MONT_CTX *)0x27f;
            uVar6 = (**(code **)(puVar22 + -0x7dd8))(iVar3 + 0x40);
            *(uint *)(puVar27 + -0x74) = uVar6;
            if (uVar6 == 0) {
              if (*(int *)(puVar27 + -0x5c) != 0) goto LAB_004f3c4c;
              *(undefined4 *)(puVar27 + -0x68) = 0;
              pBVar15 = (BN_MONT_CTX *)0x0;
              puVar28 = puVar27 + -0xa8;
              goto LAB_004f3c20;
            }
            pcVar30 = *(code **)(*(int *)(puVar27 + -0x90) + -0x53e0);
            iVar3 = (uVar6 - (uVar6 & 0x3f)) + 0x40;
            *(int *)(puVar27 + -0x68) = iVar3;
            (*pcVar30)(iVar3,0,*(undefined4 *)(puVar27 + -0x6c));
          }
          iVar3 = (int)pBVar17 * 4;
          *(BN_MONT_CTX **)(puVar27 + -0x38) = pBVar17;
          *(int *)(puVar27 + -0x80) = iVar3;
          *(undefined4 *)(puVar27 + -0x30) = 2;
          *(undefined4 *)(puVar27 + -0x44) = 2;
          *(BN_MONT_CTX **)(puVar27 + -0x4c) = pBVar17;
          *(undefined **)(puVar27 + -0x70) = puVar27 + -0x54;
          *(undefined4 *)(puVar27 + -0x3c) = 0;
          *(undefined4 *)(puVar27 + -0x50) = 0;
          *(undefined4 *)(puVar27 + -0x34) = 0;
          *(int *)(puVar27 + -0x54) = iVar3 * (int)unaff_s7 + *(int *)(puVar27 + -0x68);
          *(undefined4 *)(puVar27 + -0x48) = 0;
          *(int *)(puVar27 + -0x40) = iVar3 * (int)unaff_s7 + *(int *)(puVar27 + -0x68) + iVar3;
          *(int *)(puVar27 + -0x7c) = *(int *)(puVar27 + -0x60) + 4;
          a_00 = (char *)BN_value_one();
          mont = *(char **)(puVar27 + -0x60);
          pBVar16 = *(BN_MONT_CTX **)(puVar27 + -0x7c);
          pBVar12 = *(BIGNUM **)(puVar27 + -0x70);
          *(BN_MONT_CTX **)(puVar28 + 0x10) = pBVar18;
          iVar3 = BN_mod_mul_montgomery
                            (pBVar12,(BIGNUM *)a_00,(BIGNUM *)pBVar16,(BN_MONT_CTX *)mont,
                             *(BN_CTX **)(puVar28 + 0x10));
          puVar23 = *(undefined **)(puVar27 + -0x90);
          if (iVar3 == 0) {
LAB_004f3694:
            pBVar15 = (BN_MONT_CTX *)0x0;
LAB_004f3698:
            pcVar30 = *(code **)(puVar23 + -0x7d6c);
            if (*(int *)(puVar27 + -0x5c) == 0) goto LAB_004f3c20;
            a_00 = *(char **)(puVar27 + -0x6c);
          }
          else {
            if ((pBVar14->RR).dmax != 0) {
LAB_004f366c:
              a_00 = puVar27 + -0x40;
              pcVar30 = *(code **)(puVar23 + -0x6864);
              *(BN_MONT_CTX **)(puVar28 + 0x10) = pBVar18;
              *(char **)(puVar27 + -0x88) = a_00;
              pBVar16 = pBVar14;
              iVar3 = (*pcVar30)(0);
              puVar23 = *(undefined **)(puVar27 + -0x90);
              mont = mod;
              if (iVar3 != 0) {
                a_00 = *(char **)(puVar27 + -0x88);
                mont = *(char **)(puVar27 + -0x60);
                pBVar16 = *(BN_MONT_CTX **)(puVar27 + -0x7c);
                *(BN_MONT_CTX **)(puVar28 + 0x10) = pBVar18;
                iVar3 = BN_mod_mul_montgomery
                                  ((BIGNUM *)a_00,(BIGNUM *)a_00,(BIGNUM *)pBVar16,
                                   (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar28 + 0x10));
                puVar23 = *(undefined **)(puVar27 + -0x90);
                if (iVar3 != 0) {
                  pBVar4 = *(BN_MONT_CTX **)(puVar27 + -0x50);
                  goto LAB_004f3844;
                }
              }
              goto LAB_004f3694;
            }
            iVar3 = BN_ucmp((BIGNUM *)pBVar14,(BIGNUM *)mod);
            puVar23 = *(undefined **)(puVar27 + -0x90);
            if (-1 < iVar3) goto LAB_004f366c;
            mont = *(char **)(puVar27 + -0x60);
            pBVar16 = *(BN_MONT_CTX **)(puVar27 + -0x7c);
            *(BIGNUM **)(puVar27 + -0x88) = (BIGNUM *)(puVar27 + -0x40);
            *(BN_MONT_CTX **)(puVar28 + 0x10) = pBVar18;
            a_00 = (char *)pBVar14;
            iVar3 = BN_mod_mul_montgomery
                              ((BIGNUM *)(puVar27 + -0x40),(BIGNUM *)pBVar14,(BIGNUM *)pBVar16,
                               (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar28 + 0x10));
            puVar23 = *(undefined **)(puVar27 + -0x90);
            if (iVar3 == 0) goto LAB_004f3694;
            pBVar4 = *(BN_MONT_CTX **)(puVar27 + -0x50);
LAB_004f3844:
            if ((int)pBVar17 <= (int)pBVar4) {
              pBVar4 = pBVar17;
            }
            iVar3 = 0;
            if ((int)pBVar4 << 2 != 0) {
              puVar7 = *(undefined **)(puVar27 + -0x68);
              do {
                puVar11 = (undefined *)(*(int *)(puVar27 + -0x54) + iVar3);
                iVar3 = iVar3 + 1;
                *puVar7 = *puVar11;
                puVar7 = puVar7 + (int)unaff_s7;
              } while (iVar3 != (int)pBVar4 << 2);
            }
            pBVar4 = *(BN_MONT_CTX **)(puVar27 + -0x3c);
            if ((int)pBVar17 <= (int)*(BN_MONT_CTX **)(puVar27 + -0x3c)) {
              pBVar4 = pBVar17;
            }
            if ((int)pBVar4 << 2 != 0) {
              puVar7 = (undefined *)(*(int *)(puVar27 + -0x68) + 1);
              iVar3 = 0;
              do {
                puVar11 = (undefined *)(*(int *)(puVar27 + -0x40) + iVar3);
                iVar3 = iVar3 + 1;
                *puVar7 = *puVar11;
                puVar7 = puVar7 + (int)unaff_s7;
              } while (iVar3 != (int)pBVar4 << 2);
            }
            a_00 = *(char **)(puVar27 + -0x88);
            if (*(int *)(puVar27 + -0x84) == 1) {
              *(undefined4 *)(puVar27 + -0x7c) = 0;
              iVar3 = *(int *)(puVar27 + -0x7c);
LAB_004f39c4:
              puVar7 = (undefined *)((int)&unaff_s5[-1].flags + 3);
              pBVar14 = (BN_MONT_CTX *)0x0;
              *(int *)(puVar27 + -0x78) = iVar3 - (int)puVar7;
              do {
                puVar11 = puVar7 + -1;
                iVar3 = BN_is_bit_set((BIGNUM *)pBVar15,(int)puVar7);
                pBVar14 = (BN_MONT_CTX *)((int)pBVar14 * 2 + iVar3);
                puVar7 = puVar11;
              } while (-1 < (int)(puVar11 + *(int *)(puVar27 + -0x78)));
              iVar3 = *(int *)(puVar27 + -0x7c);
              if (iVar3 < 0) {
                iVar3 = 0;
              }
              unaff_s5 = (BN_MONT_CTX *)((int)unaff_s5 + (-2 - iVar3));
            }
            else {
              mont = *(char **)(puVar27 + -0x60);
              pBVar12 = *(BIGNUM **)(puVar27 + -0x70);
              *(BN_MONT_CTX **)(puVar28 + 0x10) = pBVar18;
              pBVar16 = (BN_MONT_CTX *)a_00;
              iVar3 = BN_mod_mul_montgomery
                                (pBVar12,(BIGNUM *)a_00,(BIGNUM *)a_00,(BN_MONT_CTX *)mont,
                                 *(BN_CTX **)(puVar28 + 0x10));
              puVar23 = *(undefined **)(puVar27 + -0x90);
              if (iVar3 == 0) goto LAB_004f3694;
              pBVar14 = *(BN_MONT_CTX **)(puVar27 + -0x50);
              if ((int)pBVar17 <= (int)*(BN_MONT_CTX **)(puVar27 + -0x50)) {
                pBVar14 = pBVar17;
              }
              if ((int)pBVar14 << 2 != 0) {
                puVar7 = (undefined *)(*(int *)(puVar27 + -0x68) + 2);
                iVar3 = 0;
                do {
                  puVar11 = (undefined *)(*(int *)(puVar27 + -0x54) + iVar3);
                  iVar3 = iVar3 + 1;
                  *puVar7 = *puVar11;
                  puVar7 = puVar7 + (int)unaff_s7;
                } while ((int)pBVar14 << 2 != iVar3);
              }
              iVar3 = *(int *)(puVar27 + -0x68);
              if (3 < *(int *)(puVar27 + -0x78)) {
                iVar21 = *(int *)(puVar27 + -0x78);
                pBVar14 = (BN_MONT_CTX *)(iVar3 + 3);
                do {
                  pBVar16 = *(BN_MONT_CTX **)(puVar27 + -0x70);
                  mont = *(char **)(puVar27 + -0x60);
                  a_00 = *(char **)(puVar27 + -0x88);
                  *(BN_MONT_CTX **)(puVar28 + 0x10) = pBVar18;
                  iVar19 = BN_mod_mul_montgomery
                                     ((BIGNUM *)pBVar16,(BIGNUM *)a_00,(BIGNUM *)pBVar16,
                                      (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar28 + 0x10));
                  puVar23 = *(undefined **)(puVar27 + -0x90);
                  if (iVar19 == 0) goto LAB_004f3694;
                  pBVar4 = *(BN_MONT_CTX **)(puVar27 + -0x50);
                  if ((int)pBVar17 <= (int)*(BN_MONT_CTX **)(puVar27 + -0x50)) {
                    pBVar4 = pBVar17;
                  }
                  iVar19 = 0;
                  pBVar13 = pBVar14;
                  if ((int)pBVar4 << 2 != 0) {
                    do {
                      puVar7 = (undefined *)(*(int *)(puVar27 + -0x54) + iVar19);
                      iVar19 = iVar19 + 1;
                      *(undefined *)&pBVar13->ri = *puVar7;
                      pBVar13 = (BN_MONT_CTX *)((int)unaff_s7->n0 + (int)(pBVar13->n0 + -0x20));
                    } while (iVar19 != (int)pBVar4 << 2);
                  }
                  pBVar14 = (BN_MONT_CTX *)((int)&pBVar14->ri + 1);
                } while (pBVar14 != (BN_MONT_CTX *)(iVar3 + iVar21));
              }
              pBVar4 = (BN_MONT_CTX *)((int)&unaff_s5[-1].flags + 3);
              if (*(int *)(puVar27 + -0x84) == 0) {
                trap(7);
              }
              iVar3 = (int)pBVar4 % *(int *)(puVar27 + -0x84);
              *(int *)(puVar27 + -0x7c) = iVar3;
              if (-1 < iVar3) goto LAB_004f39c4;
              pBVar14 = (BN_MONT_CTX *)0x0;
              unaff_s5 = pBVar4;
            }
            if ((int)pBVar17 <= *(int *)(puVar27 + -0x4c)) {
LAB_004f3a24:
              if (*(int *)(puVar27 + -0x80) != 0) {
                puVar7 = (undefined *)((int)pBVar14->n0 + *(int *)(puVar27 + -0x68) + -0x40);
                iVar3 = 0;
                do {
                  puVar11 = (undefined *)(*(int *)(puVar27 + -0x54) + iVar3);
                  iVar3 = iVar3 + 1;
                  *puVar11 = *puVar7;
                  puVar7 = puVar7 + (int)unaff_s7;
                } while (iVar3 != *(int *)(puVar27 + -0x80));
              }
              *(BN_MONT_CTX **)(puVar27 + -0x50) = pBVar17;
              if (0 < (int)pBVar17) {
                iVar3 = *(int *)(puVar27 + -0x54) + *(int *)(puVar27 + -0x80) + -8;
                pBVar4 = pBVar17;
                do {
                  if (*(int *)(iVar3 + 4) != 0) break;
                  pBVar4 = (BN_MONT_CTX *)((int)&pBVar4[-1].flags + 3);
                  iVar3 = iVar3 + -4;
                } while (pBVar4 != (BN_MONT_CTX *)0x0);
                *(BN_MONT_CTX **)(puVar27 + -0x50) = pBVar4;
              }
              *(int *)(puVar27 + -0x78) = *(int *)(puVar27 + -0x80) + -4;
              pBVar4 = unaff_s5;
              do {
                unaff_s5 = pBVar4;
                if ((int)unaff_s5 < 0) {
                  pBVar16 = *(BN_MONT_CTX **)(puVar27 + -0x60);
                  a_00 = *(char **)(puVar27 + -0x70);
                  mont = (char *)pBVar18;
                  iVar3 = BN_from_montgomery(*(BIGNUM **)(puVar27 + -100),(BIGNUM *)a_00,pBVar16,
                                             (BN_CTX *)pBVar18);
                  puVar23 = *(undefined **)(puVar27 + -0x90);
                  pBVar15 = (BN_MONT_CTX *)(uint)(iVar3 != 0);
                  goto LAB_004f3698;
                }
                pBVar14 = (BN_MONT_CTX *)0x0;
                pBVar4 = (BN_MONT_CTX *)((int)unaff_s5 - *(int *)(puVar27 + -0x84));
                pBVar13 = unaff_s5;
                do {
                  a_00 = *(char **)(puVar27 + -0x70);
                  mont = *(char **)(puVar27 + -0x60);
                  *(BN_MONT_CTX **)(puVar28 + 0x10) = pBVar18;
                  pBVar16 = (BN_MONT_CTX *)a_00;
                  iVar3 = BN_mod_mul_montgomery
                                    ((BIGNUM *)a_00,(BIGNUM *)a_00,(BIGNUM *)a_00,
                                     (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar28 + 0x10));
                  puVar23 = *(undefined **)(puVar27 + -0x90);
                  unaff_s5 = pBVar13;
                  if (iVar3 == 0) goto LAB_004f3694;
                  unaff_s5 = (BN_MONT_CTX *)((int)&pBVar13[-1].flags + 3);
                  iVar3 = BN_is_bit_set((BIGNUM *)pBVar15,(int)pBVar13);
                  pBVar14 = (BN_MONT_CTX *)((int)pBVar14 * 2 + iVar3);
                  pBVar13 = unaff_s5;
                } while (unaff_s5 != pBVar4);
                iVar3 = *(int *)(puVar27 + -0x80);
                if (*(int *)(puVar27 + -0x38) < (int)pBVar17) {
                  a_00 = (char *)pBVar17;
                  pBVar12 = bn_expand2(*(BIGNUM **)(puVar27 + -0x88),(int)pBVar17);
                  puVar25 = *(undefined **)(puVar27 + -0x90);
                  if (pBVar12 == (BIGNUM *)0x0) goto LAB_004f3cb8;
                  iVar3 = *(int *)(puVar27 + -0x80);
                }
                if (iVar3 != 0) {
                  puVar7 = (undefined *)((int)pBVar14->n0 + *(int *)(puVar27 + -0x68) + -0x40);
                  iVar3 = 0;
                  do {
                    puVar11 = (undefined *)(*(int *)(puVar27 + -0x40) + iVar3);
                    iVar3 = iVar3 + 1;
                    *puVar11 = *puVar7;
                    puVar7 = puVar7 + (int)unaff_s7;
                  } while (iVar3 != *(int *)(puVar27 + -0x80));
                }
                *(BN_MONT_CTX **)(puVar27 + -0x3c) = pBVar17;
                if (0 < (int)pBVar17) {
                  pBVar16 = pBVar17;
                  piVar8 = (int *)(*(int *)(puVar27 + -0x40) + *(int *)(puVar27 + -0x78));
                  do {
                    if (*piVar8 != 0) break;
                    pBVar16 = (BN_MONT_CTX *)((int)&pBVar16[-1].flags + 3);
                    piVar8 = piVar8 + -1;
                  } while (pBVar16 != (BN_MONT_CTX *)0x0);
                  *(BN_MONT_CTX **)(puVar27 + -0x3c) = pBVar16;
                }
                a_00 = *(char **)(puVar27 + -0x70);
                mont = *(char **)(puVar27 + -0x60);
                pBVar16 = *(BN_MONT_CTX **)(puVar27 + -0x88);
                *(BN_MONT_CTX **)(puVar28 + 0x10) = pBVar18;
                iVar3 = BN_mod_mul_montgomery
                                  ((BIGNUM *)a_00,(BIGNUM *)a_00,(BIGNUM *)pBVar16,
                                   (BN_MONT_CTX *)mont,*(BN_CTX **)(puVar28 + 0x10));
                puVar23 = *(undefined **)(puVar27 + -0x90);
              } while (iVar3 != 0);
              goto LAB_004f3694;
            }
            a_00 = (char *)pBVar17;
            pBVar12 = bn_expand2(*(BIGNUM **)(puVar27 + -0x70),(int)pBVar17);
            puVar25 = *(undefined **)(puVar27 + -0x90);
            if (pBVar12 != (BIGNUM *)0x0) goto LAB_004f3a24;
LAB_004f3cb8:
            pBVar15 = (BN_MONT_CTX *)0x0;
            if (*(int *)(puVar27 + -0x5c) == 0) goto LAB_004f3c20;
LAB_004f3c2c:
            pcVar30 = *(code **)(puVar25 + -0x7d6c);
            puVar7 = puVar28;
            if (*(int *)(puVar27 + -0x68) == 0) goto LAB_004f36cc;
            a_00 = *(char **)(puVar27 + -0x6c);
          }
          (*pcVar30)(*(undefined4 *)(puVar27 + -0x68));
          puVar7 = puVar28;
          if (*(int *)(puVar27 + -0x74) != 0) {
            (**(code **)(*(int *)(puVar27 + -0x90) + -0x7f58))(*(int *)(puVar27 + -0x74));
          }
        }
LAB_004f36cc:
        BN_CTX_end((BN_CTX *)pBVar18);
        puVar24 = *(undefined **)(puVar27 + -0x90);
        unaff_s1 = pBVar15;
        unaff_s6 = pBVar14;
        puVar11 = puVar7;
      }
    }
    pBVar4 = *(BN_MONT_CTX **)(puVar27 + -0x2c);
    if (pBVar4 == *(BN_MONT_CTX **)puVar2) {
      return (int)pBVar15;
    }
    pcVar30 = BN_mod_exp_mont;
    (**(code **)(puVar24 + -0x5328))();
    puVar28 = PTR___stack_chk_guard_006aabf0;
    puVar26 = &_gp;
    *(undefined **)(puVar11 + -0x28) = puVar2;
    *(BN_MONT_CTX **)(puVar11 + -0x18) = unaff_s4;
    uVar6 = (pBVar16->RR).neg;
    *(BN_MONT_CTX **)(puVar11 + -0x20) = pBVar17;
    *(BN_MONT_CTX **)(puVar11 + -0x24) = unaff_s1;
    *(code **)(puVar11 + -4) = pcVar30;
    uVar6 = uVar6 & 4;
    *(undefined **)(puVar11 + -8) = puVar27 + -0xa8;
    *(BN_MONT_CTX **)(puVar11 + -0xc) = unaff_s7;
    *(BN_MONT_CTX **)(puVar11 + -0x10) = unaff_s6;
    *(BN_MONT_CTX **)(puVar11 + -0x14) = unaff_s5;
    *(BN_MONT_CTX **)(puVar11 + -0x1c) = pBVar18;
    *(undefined **)(puVar11 + -0xd0) = &_gp;
    ctx_00 = *(BN_CTX **)(puVar11 + 0x10);
    iVar3 = *(int *)(puVar11 + 0x14);
    *(undefined4 *)(puVar11 + -0x2c) = *(undefined4 *)PTR___stack_chk_guard_006aabf0;
    if (uVar6 == 0) {
      if (((int)((BIGNUM *)((int)mont + 4))->d < 1) || ((*(uint *)*(int *)mont & 1) == 0)) {
        *(undefined4 *)(puVar11 + -0xd8) = 0x196;
        (*(code *)PTR_ERR_put_error_006a9030)(3,0x6d,0x66,"bn_exp.c");
        puVar26 = *(undefined **)(puVar11 + -0xd0);
        pBVar4 = pBVar18;
        pBVar16 = unaff_s7;
        goto LAB_004f3da0;
      }
      iVar21 = BN_num_bits((BIGNUM *)pBVar16);
      puVar26 = *(undefined **)(puVar11 + -0xd0);
      if (iVar21 != 0) {
        BN_CTX_start(ctx_00);
        unaff_s5 = (BN_MONT_CTX *)BN_CTX_get(ctx_00);
        pBVar12 = BN_CTX_get(ctx_00);
        *(BIGNUM **)(puVar11 + -0xc4) = pBVar12;
        pBVar17 = (BN_MONT_CTX *)BN_CTX_get(ctx_00);
        *(BN_MONT_CTX **)(puVar11 + -0xac) = pBVar17;
        if (((unaff_s5 == (BN_MONT_CTX *)0x0) || (*(int *)(puVar11 + -0xc4) == 0)) ||
           (pBVar17 == (BN_MONT_CTX *)0x0)) {
LAB_004f4148:
          uVar6 = 0;
          goto LAB_004f3ecc;
        }
        *(int *)(puVar11 + -0xc0) = iVar3;
        if (iVar3 == 0) {
          *(BN_MONT_CTX **)(puVar11 + -0xbc) = pBVar17;
          pBVar17 = BN_MONT_CTX_new();
          *(BN_MONT_CTX **)(puVar11 + -0xc0) = pBVar17;
          if (pBVar17 == (BN_MONT_CTX *)0x0) goto LAB_004f4148;
          iVar19 = BN_MONT_CTX_set(pBVar17,(BIGNUM *)mont,ctx_00);
          pBVar17 = *(BN_MONT_CTX **)(puVar11 + -0xbc);
          if (iVar19 == 0) {
            uVar6 = 0;
            goto LAB_004f41a8;
          }
        }
        if (((BIGNUM *)((int)a_00 + 4))->dmax == 0) {
          *(BN_MONT_CTX **)(puVar11 + -0xbc) = pBVar17;
          iVar19 = BN_ucmp((BIGNUM *)a_00,(BIGNUM *)mont);
          pBVar17 = *(BN_MONT_CTX **)(puVar11 + -0xbc);
          if (-1 < iVar19) goto LAB_004f3ea0;
        }
        else {
LAB_004f3ea0:
          *(BN_MONT_CTX **)(puVar11 + -0xbc) = pBVar17;
          iVar19 = BN_nnmod((BIGNUM *)pBVar17,(BIGNUM *)a_00,(BIGNUM *)mont,ctx_00);
          if (iVar19 == 0) goto LAB_004f3ec0;
          pBVar17 = *(BN_MONT_CTX **)(puVar11 + -0xbc);
          a_00 = (char *)pBVar17;
        }
        if (((BIGNUM *)((int)a_00 + 4))->d == (ulong *)0x0) {
          uVar6 = 1;
          BN_set_word((BIGNUM *)pBVar4,0);
          goto LAB_004f3ec4;
        }
        *(BN_CTX **)(puVar11 + -0xd8) = ctx_00;
        pBVar12 = &(*(BN_MONT_CTX **)(puVar11 + -0xc0))->RR;
        *(BN_MONT_CTX **)(puVar11 + -0xbc) = pBVar17;
        *(BIGNUM **)(puVar11 + -0xb4) = pBVar12;
        iVar19 = BN_mod_mul_montgomery
                           ((BIGNUM *)pBVar17,(BIGNUM *)a_00,pBVar12,
                            *(BN_MONT_CTX **)(puVar11 + -0xc0),*(BN_CTX **)(puVar11 + -0xd8));
        if (iVar19 == 0) goto LAB_004f3ec0;
        pBVar12 = *(BIGNUM **)(puVar11 + -0xbc);
        if (iVar21 < 0x2a0) {
          if (iVar21 < 0xf0) {
            if (iVar21 < 0x50) {
              if (iVar21 < 0x18) {
                *(undefined4 *)(puVar11 + -0xb8) = 1;
                goto LAB_004f3fe8;
              }
              *(undefined4 *)(puVar11 + -0xbc) = 4;
              *(undefined4 *)(puVar11 + -0xb8) = 3;
            }
            else {
              *(undefined4 *)(puVar11 + -0xbc) = 8;
              *(undefined4 *)(puVar11 + -0xb8) = 4;
            }
          }
          else {
            *(undefined4 *)(puVar11 + -0xbc) = 0x10;
            *(undefined4 *)(puVar11 + -0xb8) = 5;
          }
        }
        else {
          *(undefined4 *)(puVar11 + -0xbc) = 0x20;
          *(undefined4 *)(puVar11 + -0xb8) = 6;
        }
        *(BN_CTX **)(puVar11 + -0xd8) = ctx_00;
        iVar19 = BN_mod_mul_montgomery
                           ((BIGNUM *)unaff_s5,pBVar12,pBVar12,*(BN_MONT_CTX **)(puVar11 + -0xc0),
                            *(BN_CTX **)(puVar11 + -0xd8));
        if (iVar19 == 0) goto LAB_004f3ec0;
        ppBVar29 = (BIGNUM **)(puVar11 + -0xa8);
        iVar19 = 1;
        do {
          pBVar12 = BN_CTX_get(ctx_00);
          *ppBVar29 = pBVar12;
          if (pBVar12 == (BIGNUM *)0x0) {
            uVar6 = 0;
            goto LAB_004f3ec4;
          }
          *(BN_CTX **)(puVar11 + -0xd8) = ctx_00;
          iVar9 = BN_mod_mul_montgomery
                            (pBVar12,ppBVar29[-1],(BIGNUM *)unaff_s5,
                             *(BN_MONT_CTX **)(puVar11 + -0xc0),*(BN_CTX **)(puVar11 + -0xd8));
          if (iVar9 == 0) goto LAB_004f3ec0;
          iVar19 = iVar19 + 1;
          ppBVar29 = ppBVar29 + 1;
        } while (iVar19 < *(int *)(puVar11 + -0xbc));
LAB_004f3fe8:
        pBVar12 = BN_value_one();
        *(BN_CTX **)(puVar11 + -0xd8) = ctx_00;
        iVar19 = BN_mod_mul_montgomery
                           (*(BIGNUM **)(puVar11 + -0xc4),pBVar12,*(BIGNUM **)(puVar11 + -0xb4),
                            *(BN_MONT_CTX **)(puVar11 + -0xc0),*(BN_CTX **)(puVar11 + -0xd8));
        if (iVar19 == 0) goto LAB_004f3ec0;
        *(int *)(puVar11 + -0xbc) = iVar21 + -1;
        iVar21 = *(int *)(puVar11 + -0xbc);
        *(undefined4 *)(puVar11 + -0xb4) = 1;
        goto LAB_004f4030;
      }
      pBVar18 = pBVar4;
      unaff_s7 = pBVar16;
      if (*(int *)(puVar11 + -0x2c) == *(int *)puVar28) {
        iVar3 = BN_set_word((BIGNUM *)pBVar4,1);
        return iVar3;
      }
      break;
    }
    pcVar30 = *(code **)(puVar11 + -4);
    if (*(int *)(puVar11 + -0x2c) != *(int *)PTR___stack_chk_guard_006aabf0) break;
    unaff_s8 = *(BN_MONT_CTX **)(puVar11 + -8);
    unaff_s7 = *(BN_MONT_CTX **)(puVar11 + -0xc);
    unaff_s6 = *(BN_MONT_CTX **)(puVar11 + -0x10);
    unaff_s5 = *(BN_MONT_CTX **)(puVar11 + -0x14);
    unaff_s4 = *(BN_MONT_CTX **)(puVar11 + -0x18);
    unaff_s3 = *(BN_RECP_CTX **)(puVar11 + -0x1c);
    ctx = *(BN_CTX **)(puVar11 + -0x28);
    *(int *)(puVar11 + 0x14) = iVar3;
    *(BN_CTX **)(puVar11 + 0x10) = ctx_00;
    pBVar17 = *(BN_MONT_CTX **)(puVar11 + -0x20);
    unaff_s1 = *(BN_MONT_CTX **)(puVar11 + -0x24);
    pBVar14 = (BN_MONT_CTX *)a_00;
    pBVar15 = pBVar16;
    mod = mont;
    puVar27 = puVar11;
  } while( true );
LAB_004f42f0:
  (**(code **)(puVar26 + -0x5328))();
  pBVar4 = pBVar18;
  pBVar16 = unaff_s7;
LAB_004f42fc:
  iVar19 = 0;
LAB_004f40b0:
  iVar9 = *(int *)(puVar11 + -0xb4);
  do {
    if (iVar9 == 0) {
      iVar21 = 0;
      pBVar12 = *(BIGNUM **)(puVar11 + -0xc4);
      do {
        *(BN_CTX **)(puVar11 + -0xd8) = ctx_00;
        iVar9 = BN_mod_mul_montgomery
                          (pBVar12,pBVar12,pBVar12,*(BN_MONT_CTX **)(puVar11 + -0xc0),
                           *(BN_CTX **)(puVar11 + -0xd8));
        if (iVar9 == 0) goto LAB_004f3ec0;
        iVar21 = iVar21 + 1;
        pBVar12 = *(BIGNUM **)(puVar11 + -0xc4);
      } while (iVar21 <= iVar19);
    }
    *(BN_CTX **)(puVar11 + -0xd8) = ctx_00;
    iVar21 = BN_mod_mul_montgomery
                       (*(BIGNUM **)(puVar11 + -0xc4),*(BIGNUM **)(puVar11 + -0xc4),
                        *(BIGNUM **)(puVar11 + ((int)unaff_s5 >> 1) * 4 + -0xac),
                        *(BN_MONT_CTX **)(puVar11 + -0xc0),*(BN_CTX **)(puVar11 + -0xd8));
    if (iVar21 == 0) break;
    iVar21 = *(int *)(puVar11 + -0xbc) - (iVar19 + 1);
    *(int *)(puVar11 + -0xbc) = iVar21;
    if (iVar21 < 0) {
LAB_004f4278:
      iVar21 = BN_from_montgomery((BIGNUM *)pBVar4,*(BIGNUM **)(puVar11 + -0xc4),
                                  *(BN_MONT_CTX **)(puVar11 + -0xc0),ctx_00);
      uVar6 = (uint)(iVar21 != 0);
      goto LAB_004f3ec4;
    }
    *(undefined4 *)(puVar11 + -0xb4) = 0;
LAB_004f4030:
    while (iVar19 = BN_is_bit_set((BIGNUM *)pBVar16,iVar21), iVar19 == 0) {
      pBVar12 = *(BIGNUM **)(puVar11 + -0xc4);
      if (*(int *)(puVar11 + -0xb4) == 0) {
        *(BN_CTX **)(puVar11 + -0xd8) = ctx_00;
        iVar21 = BN_mod_mul_montgomery
                           (pBVar12,pBVar12,pBVar12,*(BN_MONT_CTX **)(puVar11 + -0xc0),
                            *(BN_CTX **)(puVar11 + -0xd8));
        if (iVar21 == 0) {
          uVar6 = 0;
          goto LAB_004f3ec4;
        }
      }
      iVar21 = *(int *)(puVar11 + -0xbc) + -1;
      if (*(int *)(puVar11 + -0xbc) == 0) goto LAB_004f4278;
      *(int *)(puVar11 + -0xbc) = iVar21;
    }
    unaff_s5 = (BN_MONT_CTX *)0x1;
    if (*(int *)(puVar11 + -0xb8) == 1) goto LAB_004f42fc;
    iVar21 = iVar21 + -1;
    iVar19 = 0;
    if (iVar21 < 0) goto LAB_004f40b0;
    iVar20 = 1;
    do {
      iVar9 = BN_is_bit_set((BIGNUM *)pBVar16,iVar21);
      if (iVar9 != 0) {
        unaff_s5 = (BN_MONT_CTX *)((int)unaff_s5 << (iVar20 - iVar19 & 0x1fU) | 1);
        iVar19 = iVar20;
      }
      iVar20 = iVar20 + 1;
      if (iVar20 == *(int *)(puVar11 + -0xb8)) goto LAB_004f40b0;
      iVar21 = iVar21 + -1;
      iVar9 = *(int *)(puVar11 + -0xb4);
    } while (iVar21 != -1);
  } while( true );
LAB_004f3ec0:
  uVar6 = 0;
LAB_004f3ec4:
  if (iVar3 == 0) {
LAB_004f41a8:
    BN_MONT_CTX_free(*(BN_MONT_CTX **)(puVar11 + -0xc0));
  }
LAB_004f3ecc:
  BN_CTX_end(ctx_00);
  puVar26 = *(undefined **)(puVar11 + -0xd0);
LAB_004f3da0:
  pBVar18 = pBVar4;
  unaff_s7 = pBVar16;
  if (*(int *)(puVar11 + -0x2c) == *(int *)puVar28) {
    return uVar6;
  }
  goto LAB_004f42f0;
}

