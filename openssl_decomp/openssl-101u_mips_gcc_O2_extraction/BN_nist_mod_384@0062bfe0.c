
int BN_nist_mod_384(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  uint *puVar4;
  ulong **ppuVar5;
  ulong uVar6;
  BIGNUM *pBVar7;
  BIGNUM *pBVar8;
  ulong *puVar9;
  code *pcVar10;
  uint uVar11;
  ulong *puVar12;
  undefined *unaff_s4;
  undefined *puVar13;
  uint uVar14;
  ulong *puVar15;
  BIGNUM *unaff_s5;
  uint uVar16;
  int iVar17;
  uint unaff_s6;
  ulong *puVar18;
  uint unaff_s7;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint unaff_s8;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint auStack_120 [4];
  uint uStack_110;
  uint uStack_10c;
  uint uStack_108;
  uint uStack_104;
  uint uStack_100;
  uint uStack_fc;
  uint uStack_f8;
  uint uStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  uint uStack_e8;
  uint uStack_e4;
  uint uStack_e0;
  int iStack_dc;
  undefined *puStack_d8;
  BIGNUM *pBStack_d4;
  BIGNUM *pBStack_d0;
  uint uStack_cc;
  undefined *puStack_c8;
  BIGNUM *pBStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  code *pcStack_b4;
  undefined *local_a0;
  BN_CTX *local_94;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  ulong *local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  ulong *local_60;
  undefined auStack_5c [48];
  BIGNUM *local_2c;
  
  puStack_d8 = PTR___stack_chk_guard_006a9ae8;
  uStack_cc = a->neg;
  local_a0 = &_gp;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pBVar7 = a;
  if (uStack_cc == 0) {
    unaff_s4 = (undefined *)a->top;
    unaff_s5 = (BIGNUM *)a->d;
    local_94 = ctx;
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(a,_bignum_nist_p_384_sqr_6219);
    if (-1 < iVar3) goto LAB_0062c060;
    iVar3 = (**(code **)(local_a0 + -0x6e2c))(_bignum_nist_p_384);
    if (iVar3 == 0) {
      pBVar7 = (BIGNUM *)0x0;
      uStack_cc = 1;
      (**(code **)(local_a0 + -0x76b0))(r);
    }
    else if (iVar3 < 1) {
      pBVar8 = unaff_s5;
      if (a != r) {
        if (r->dmax < 0xc) {
          pBVar7 = (BIGNUM *)&SUB_0000000c;
          iVar3 = (**(code **)(local_a0 + -0x68bc))(r);
          a = unaff_s5;
          if (iVar3 == 0) goto LAB_0062c080;
          puVar15 = unaff_s5->d;
        }
        else {
          puVar15 = unaff_s5->d;
        }
        pBVar8 = (BIGNUM *)r->d;
        pBVar8->d = puVar15;
        pBVar8->top = unaff_s5->top;
        pBVar8->dmax = unaff_s5->dmax;
        pBVar8->neg = unaff_s5->neg;
        pBVar8->flags = unaff_s5->flags;
        pBVar8[1].d = unaff_s5[1].d;
        pBVar8[1].top = unaff_s5[1].top;
        pBVar8[1].dmax = unaff_s5[1].dmax;
        pBVar8[1].neg = unaff_s5[1].neg;
        pBVar8[1].flags = unaff_s5[1].flags;
        pBVar8[2].d = unaff_s5[2].d;
        pBVar8[2].top = unaff_s5[2].top;
      }
      if ((int)unaff_s4 < 0xd) {
        puVar13 = (undefined *)0x0;
        puVar4 = &local_8c;
        bVar1 = true;
LAB_0062c1b8:
        iVar3 = 4;
        if (bVar1) {
          iVar3 = (int)puVar13 * -4 + 0x30;
        }
        (**(code **)(local_a0 + -0x53ec))(puVar4 + (int)puVar13,0,iVar3);
      }
      else {
        puVar13 = unaff_s4 + -0xc;
        puVar4 = (uint *)(**(code **)(local_a0 + -0x52f4))
                                   (&local_8c,&unaff_s5[2].dmax,(int)unaff_s4 * 4 + -0x30);
        bVar1 = (int)puVar13 < 0xc;
        if (bVar1) goto LAB_0062c1b8;
      }
      puVar9 = (ulong *)((int)pBVar8->d + local_8c);
      puVar15 = (ulong *)((int)puVar9 + local_68);
      puVar12 = (ulong *)((int)puVar15 + local_6c);
      uVar19 = pBVar8->neg;
      puVar18 = pBVar8[1].d;
      iVar3 = ((uint)(puVar12 < puVar15) + (uint)(puVar15 < puVar9) + (uint)(puVar9 < pBVar8->d)) -
              (uint)(puVar12 < (ulong *)((int)puVar12 - (int)local_60));
      uVar16 = pBVar8[1].top;
      uVar11 = pBVar8->top + iVar3;
      uVar25 = pBVar8[1].dmax;
      uVar21 = uVar11 + local_88;
      pBVar8->d = (ulong *)((int)puVar12 - (int)local_60);
      pcVar10 = *(code **)(local_a0 + -0x6860);
      puVar15 = (ulong *)((int)local_60 + uVar21 + local_64);
      puVar9 = (ulong *)((int)puVar15 - local_8c);
      iVar3 = (((uint)(puVar15 < local_60) +
               (uint)(uVar21 + local_64 < uVar21) +
               (uint)(uVar21 < uVar11) + (uint)(uVar11 < (uint)pBVar8->top) + (iVar3 >> 0x1f)) -
              (uint)(puVar15 < puVar9)) - (uint)(puVar9 < (ulong *)((int)puVar9 - local_6c));
      pBVar8->top = (int)(ulong *)((int)puVar9 - local_6c);
      uVar11 = pBVar8->dmax + iVar3;
      puVar15 = (ulong *)((int)local_60 + uVar11 + local_84);
      puVar9 = (ulong *)((int)puVar15 - local_88);
      iVar3 = (((uint)(puVar15 < local_60) +
               (uint)(uVar11 + local_84 < uVar11) +
               (uint)(uVar11 < (uint)pBVar8->dmax) + (iVar3 >> 0x1f)) - (uint)(puVar15 < puVar9)) -
              (uint)(puVar9 < (ulong *)((int)puVar9 - local_68));
      pBVar8->dmax = (int)(ulong *)((int)puVar9 - local_68);
      uVar21 = uVar19 + iVar3;
      uVar20 = local_8c + uVar21 + local_80;
      uVar11 = local_6c + uVar20;
      uVar14 = local_68 + uVar11;
      unaff_s8 = uVar14 - local_84;
      uVar22 = unaff_s8 - local_64;
      pBVar8->neg = uVar22 - (int)local_60;
      iVar3 = ((((uint)(uVar14 < local_68) +
                (uint)(uVar11 < local_6c) +
                (uint)(uVar20 < local_8c) +
                (uint)(uVar21 + local_80 < uVar21) + (uint)(uVar21 < uVar19) + (iVar3 >> 0x1f)) -
               (uint)(uVar14 < unaff_s8)) - (uint)(unaff_s8 < uVar22)) -
              (uint)(uVar22 < uVar22 - (int)local_60);
      uVar20 = pBVar8->flags + iVar3;
      uVar23 = local_68 + uVar20;
      uVar14 = local_68 + uVar23;
      uVar11 = local_88 + uVar14 + local_7c;
      uVar22 = local_8c + uVar11;
      uVar21 = local_6c + uVar22;
      uVar24 = local_64 + uVar21;
      uVar19 = uVar24 - local_80;
      unaff_s7 = uVar19 - (int)local_60;
      iVar3 = ((((uint)(uVar24 < local_64) +
                (uint)(uVar21 < local_6c) +
                (uint)(uVar22 < local_8c) +
                (uint)(uVar11 < local_88) +
                (uint)(uVar14 + local_7c < uVar14) +
                (uint)(uVar14 < local_68) +
                (uint)(uVar23 < local_68) + (uint)(uVar20 < (uint)pBVar8->flags) + (iVar3 >> 0x1f))
               - (uint)(uVar24 < uVar19)) - (uint)(uVar19 < unaff_s7)) -
              (uint)(unaff_s7 < unaff_s7 - (int)local_60);
      pBVar8->flags = unaff_s7 - (int)local_60;
      puVar15 = (ulong *)((int)puVar18 + iVar3);
      uVar14 = local_64 + (int)puVar15;
      unaff_s6 = (uint)(puVar15 < puVar18);
      uVar20 = local_64 + uVar14;
      uVar11 = local_84 + uVar20 + local_78;
      uVar19 = local_88 + uVar11;
      uVar21 = local_68 + uVar19;
      puVar15 = (ulong *)((int)local_60 + uVar21);
      pBVar8[1].d = (ulong *)((int)puVar15 - local_7c);
      iVar3 = ((uint)(puVar15 < local_60) +
              (uint)(uVar21 < local_68) +
              (uint)(uVar19 < local_88) +
              (uint)(uVar11 < local_84) +
              (uint)(uVar20 + local_78 < uVar20) +
              (uint)(uVar20 < local_64) + (uint)(uVar14 < local_64) + unaff_s6 + (iVar3 >> 0x1f)) -
              (uint)(puVar15 < (ulong *)((int)puVar15 - local_7c));
      uVar21 = uVar16 + iVar3;
      puVar9 = (ulong *)((int)local_60 + uVar21);
      puVar15 = (ulong *)((int)local_60 + (int)puVar9);
      uVar11 = local_80 + (int)(ulong *)((int)puVar15 + (int)local_74);
      uVar14 = local_84 + uVar11;
      uVar19 = local_64 + uVar14;
      pBVar8[1].top = uVar19 - local_78;
      iVar3 = ((uint)(uVar19 < local_64) +
              (uint)(uVar14 < local_84) +
              (uint)(uVar11 < local_80) +
              (uint)((ulong *)((int)puVar15 + (int)local_74) < puVar15) +
              (uint)(puVar15 < local_60) +
              (uint)(puVar9 < local_60) + (uint)(uVar21 < uVar16) + (iVar3 >> 0x1f)) -
              (uint)(uVar19 < uVar19 - local_78);
      uVar14 = uVar25 + iVar3;
      uVar21 = local_7c + uVar14 + local_70;
      uVar11 = local_80 + uVar21;
      puVar15 = (ulong *)((int)local_60 + uVar11);
      uVar19 = pBVar8[1].neg;
      iVar3 = ((uint)(puVar15 < local_60) +
              (uint)(uVar11 < local_80) +
              (uint)(uVar21 < local_7c) +
              (uint)(uVar14 + local_70 < uVar14) + (uint)(uVar14 < uVar25) + (iVar3 >> 0x1f)) -
              (uint)(puVar15 < (ulong *)((int)puVar15 - (int)local_74));
      pBVar8[1].dmax = (int)(ulong *)((int)puVar15 - (int)local_74);
      uVar11 = pBVar8[1].neg + iVar3;
      uVar25 = local_6c + uVar11;
      uVar21 = local_78 + uVar25;
      uVar14 = local_7c + uVar21;
      pBVar8[1].neg = uVar14 - local_70;
      iVar3 = ((uint)(uVar14 < local_7c) +
              (uint)(uVar21 < local_78) +
              (uint)(uVar25 < local_6c) + (uint)(uVar11 < uVar19) + (iVar3 >> 0x1f)) -
              (uint)(uVar14 < uVar14 - local_70);
      uVar25 = pBVar8[1].flags;
      uVar11 = pBVar8[1].flags + iVar3;
      uVar21 = local_68 + uVar11;
      puVar15 = (ulong *)((int)local_74 + uVar21);
      uVar14 = local_78 + (int)puVar15;
      pBVar8[1].flags = uVar14 - local_6c;
      puVar12 = pBVar8[2].d;
      iVar3 = ((uint)(uVar14 < local_78) +
              (uint)(puVar15 < local_74) +
              (uint)(uVar21 < local_68) + (uint)(uVar11 < uVar25) + (iVar3 >> 0x1f)) -
              (uint)(uVar14 < uVar14 - local_6c);
      puVar15 = (ulong *)((int)puVar12 + iVar3);
      uVar21 = local_64 + (int)puVar15;
      uVar11 = local_70 + uVar21;
      puVar9 = (ulong *)((int)local_74 + uVar11);
      pBVar8[2].d = (ulong *)((int)puVar9 - local_68);
      iVar3 = ((uint)(puVar9 < local_74) +
              (uint)(uVar11 < local_70) +
              (uint)(uVar21 < local_64) + (uint)(puVar15 < puVar12) + (iVar3 >> 0x1f)) -
              (uint)(puVar9 < (ulong *)((int)puVar9 - local_68));
      uVar11 = pBVar8[2].top + iVar3;
      puVar15 = (ulong *)((int)local_60 + uVar11);
      uVar25 = local_6c + (int)puVar15;
      uVar21 = local_70 + uVar25;
      uVar11 = ((uint)(uVar21 < local_70) +
               (uint)(uVar25 < local_6c) +
               (uint)(puVar15 < local_60) + (uint)(uVar11 < (uint)pBVar8[2].top) + (iVar3 >> 0x1f))
               - (uint)(uVar21 < uVar21 - local_64);
      pBVar8[2].top = uVar21 - local_64;
      if (((int)uVar11 < 0) || (uVar11 == 0)) {
        if (((int)uVar11 >> 0x1f | uVar11) == 0) {
          unaff_s5 = (BIGNUM *)0xffffffff;
        }
        else {
          iVar3 = (**(code **)(local_a0 + -0x685c))(pBVar8,pBVar8,_nist_p_384 + ~uVar11 * 0x30,0xc);
          unaff_s5 = (BIGNUM *)-iVar3;
          pcVar10 = (code *)(((uint)pcVar10 ^ *(uint *)(local_a0 + -0x685c)) & (uint)unaff_s5 ^
                            *(uint *)(local_a0 + -0x685c));
        }
      }
      else {
        iVar3 = (**(code **)(local_a0 + -0x6860))
                          (pBVar8,pBVar8,_nist_p_384 + (uVar11 - 1) * 0x30,0xc);
        unaff_s5 = (BIGNUM *)-iVar3;
      }
      unaff_s4 = auStack_5c;
      pBVar7 = pBVar8;
      iVar3 = (*pcVar10)(unaff_s4,pBVar8,_nist_p_384);
      puVar15 = r->d;
      ppuVar5 = (ulong **)
                (((uint)pBVar8 ^ (uint)unaff_s4) & (uint)unaff_s5 & -iVar3 ^ (uint)unaff_s4);
      pBVar8->d = *ppuVar5;
      pBVar8->top = (int)ppuVar5[1];
      pBVar8->dmax = (int)ppuVar5[2];
      pBVar8->neg = (int)ppuVar5[3];
      pBVar8->flags = (int)ppuVar5[4];
      pBVar8[1].d = ppuVar5[5];
      pBVar8[1].top = (int)ppuVar5[6];
      pBVar8[1].dmax = (int)ppuVar5[7];
      pBVar8[1].neg = (int)ppuVar5[8];
      pBVar8[1].flags = (int)ppuVar5[9];
      pBVar8[2].d = ppuVar5[10];
      pBVar8[2].top = (int)ppuVar5[0xb];
      r->top = 0xc;
      a = pBVar8;
      if (puVar15[0xb] == 0) {
        if (puVar15[10] == 0) {
          if (puVar15[9] == 0) {
            if (puVar15[8] == 0) {
              if (puVar15[7] == 0) {
                if (puVar15[6] == 0) {
                  if (puVar15[5] == 0) {
                    if (puVar15[4] == 0) {
                      if (puVar15[3] == 0) {
                        if (puVar15[2] == 0) {
                          if (puVar15[1] == 0) {
                            uStack_cc = 1;
                            r->top = (uint)(*puVar15 != 0);
                          }
                          else {
                            uStack_cc = 1;
                            r->top = 2;
                          }
                        }
                        else {
                          uStack_cc = 1;
                          r->top = 3;
                        }
                      }
                      else {
                        uStack_cc = 1;
                        r->top = 4;
                      }
                    }
                    else {
                      uStack_cc = 1;
                      r->top = 5;
                    }
                  }
                  else {
                    uStack_cc = 1;
                    r->top = 6;
                  }
                }
                else {
                  uStack_cc = 1;
                  r->top = 7;
                }
              }
              else {
                uStack_cc = 1;
                r->top = 8;
              }
            }
            else {
              uStack_cc = 1;
              r->top = 9;
            }
          }
          else {
            uStack_cc = 1;
            r->top = 10;
          }
        }
        else {
          uStack_cc = 1;
          r->top = 0xb;
        }
      }
      else {
        uStack_cc = 1;
        r->top = 0xc;
      }
    }
    else if (a == r) {
      uStack_cc = 1;
    }
    else {
      pBVar7 = a;
      iVar3 = (**(code **)(local_a0 + -0x6990))(r);
      uStack_cc = (uint)(iVar3 != 0);
    }
  }
  else {
LAB_0062c060:
    uStack_cc = (**(code **)(local_a0 + -0x6898))(r,a,_bignum_nist_p_384);
  }
LAB_0062c080:
  if (local_2c == *(BIGNUM **)puStack_d8) {
    return uStack_cc;
  }
  pcStack_b4 = BN_nist_mod_521;
  pBVar8 = local_2c;
  (**(code **)(local_a0 + -0x5330))();
  puVar13 = PTR___stack_chk_guard_006a9ae8;
  uVar11 = pBVar7->neg;
  iStack_dc = *(int *)PTR___stack_chk_guard_006a9ae8;
  pBStack_d4 = r;
  pBStack_d0 = a;
  puStack_c8 = unaff_s4;
  pBStack_c4 = unaff_s5;
  uStack_c0 = unaff_s6;
  uStack_bc = unaff_s7;
  uStack_b8 = unaff_s8;
  if (uVar11 == 0) {
    iVar17 = pBVar7->top;
    puVar15 = pBVar7->d;
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBVar7,_bignum_nist_p_521_sqr_6243);
    if (iVar3 < 0) {
      iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(_bignum_nist_p_521,pBVar7);
      if (iVar3 == 0) {
        uVar11 = 1;
        (*(code *)PTR_BN_set_word_006a7730)(pBVar8,0);
        goto LAB_0062c9a0;
      }
      if (0 < iVar3) {
        if (pBVar7 == pBVar8) {
          uVar11 = 1;
        }
        else {
          iVar3 = (*(code *)PTR_BN_copy_006a8450)(pBVar8,pBVar7);
          uVar11 = (uint)(iVar3 != 0);
        }
        goto LAB_0062c9a0;
      }
      puVar9 = puVar15;
      if (pBVar7 != pBVar8) {
        if (pBVar8->dmax < 0x11) {
          iVar3 = (*(code *)PTR_bn_expand2_006a8524)(pBVar8,0x11);
          if (iVar3 == 0) goto LAB_0062c9a0;
          uVar6 = *puVar15;
        }
        else {
          uVar6 = *puVar15;
        }
        puVar9 = pBVar8->d;
        *puVar9 = uVar6;
        puVar9[1] = puVar15[1];
        puVar9[2] = puVar15[2];
        puVar9[3] = puVar15[3];
        puVar9[4] = puVar15[4];
        puVar9[5] = puVar15[5];
        puVar9[6] = puVar15[6];
        puVar9[7] = puVar15[7];
        puVar9[8] = puVar15[8];
        puVar9[9] = puVar15[9];
        puVar9[10] = puVar15[10];
        puVar9[0xb] = puVar15[0xb];
        puVar9[0xc] = puVar15[0xc];
        puVar9[0xd] = puVar15[0xd];
        puVar9[0xe] = puVar15[0xe];
        puVar9[0xf] = puVar15[0xf];
        puVar9[0x10] = puVar15[0x10];
      }
      puVar12 = puVar15 + 0x10;
      if (iVar17 < 0x11) {
        iVar17 = 0;
        bVar1 = true;
LAB_0062cb08:
        iVar3 = 4;
        if (bVar1) {
          iVar3 = iVar17 * -4 + 0x44;
        }
        (*(code *)PTR_memset_006a99f4)(auStack_120 + iVar17,0,iVar3);
      }
      else {
        puVar18 = auStack_120;
        do {
          uVar6 = *puVar12;
          puVar12 = puVar12 + 1;
          *puVar18 = uVar6;
          puVar18 = puVar18 + 1;
        } while (puVar12 != puVar15 + iVar17);
        iVar17 = iVar17 + -0x10;
        bVar1 = iVar17 < 0x11;
        if (bVar1) goto LAB_0062cb08;
      }
      puVar2 = PTR_bn_add_words_006a8584;
      uVar11 = auStack_120[1] << 0x17;
      auStack_120[1] = auStack_120[1] >> 9 | auStack_120[2] << 0x17;
      auStack_120[2] = auStack_120[2] >> 9 | auStack_120[3] << 0x17;
      uVar21 = uStack_e8 << 0x17;
      uVar25 = uStack_ec << 0x17;
      auStack_120[3] = auStack_120[3] >> 9 | uStack_110 << 0x17;
      auStack_120[0] = auStack_120[0] >> 9 | uVar11;
      uStack_e8 = uStack_e8 >> 9 | uStack_e4 << 0x17;
      uVar11 = uStack_e0 << 0x17;
      uStack_e0 = uStack_e0 >> 9;
      uStack_e4 = uStack_e4 >> 9 | uVar11;
      uStack_110 = uStack_110 >> 9 | uStack_10c << 0x17;
      uStack_ec = uStack_ec >> 9 | uVar21;
      uStack_10c = uStack_10c >> 9 | uStack_108 << 0x17;
      uStack_108 = uStack_108 >> 9 | uStack_104 << 0x17;
      uStack_104 = uStack_104 >> 9 | uStack_100 << 0x17;
      uStack_100 = uStack_100 >> 9 | uStack_fc << 0x17;
      uStack_fc = uStack_fc >> 9 | uStack_f8 << 0x17;
      uStack_f8 = uStack_f8 >> 9 | uStack_f4 << 0x17;
      uStack_f4 = uStack_f4 >> 9 | uStack_f0 << 0x17;
      uStack_f0 = uStack_f0 >> 9 | uVar25;
      puVar9[0x10] = puVar9[0x10] & 0x1ff;
      (*(code *)puVar2)(puVar9,puVar9,auStack_120,0x11);
      iVar3 = (*(code *)PTR_bn_sub_words_006a8580)(auStack_120,puVar9,_nist_p_521,0x11);
      puVar12 = (ulong *)((uint)auStack_120 ^ ((uint)puVar9 ^ (uint)auStack_120) & -iVar3);
      *puVar9 = *puVar12;
      puVar9[1] = puVar12[1];
      puVar9[2] = puVar12[2];
      puVar9[3] = puVar12[3];
      puVar9[4] = puVar12[4];
      puVar9[5] = puVar12[5];
      puVar9[6] = puVar12[6];
      puVar9[7] = puVar12[7];
      puVar9[8] = puVar12[8];
      puVar9[9] = puVar12[9];
      puVar9[10] = puVar12[10];
      puVar9[0xb] = puVar12[0xb];
      puVar9[0xc] = puVar12[0xc];
      puVar9[0xd] = puVar12[0xd];
      puVar9[0xe] = puVar12[0xe];
      puVar9[0xf] = puVar12[0xf];
      puVar15 = pBVar8->d;
      puVar9[0x10] = puVar12[0x10];
      pBVar8->top = (int)&DAT_00000011;
      if (puVar15[0x10] == 0) {
        if (puVar15[0xf] == 0) {
          if (puVar15[0xe] == 0) {
            if (puVar15[0xd] == 0) {
              if (puVar15[0xc] == 0) {
                if (puVar15[0xb] == 0) {
                  if (puVar15[10] == 0) {
                    if (puVar15[9] == 0) {
                      if (puVar15[8] == 0) {
                        if (puVar15[7] == 0) {
                          if (puVar15[6] == 0) {
                            if (puVar15[5] == 0) {
                              if (puVar15[4] == 0) {
                                if (puVar15[3] == 0) {
                                  uVar11 = 1;
                                  if (puVar15[2] == 0) {
                                    if (puVar15[1] != 0) goto LAB_0062cfd4;
                                    pBVar8->top = (uint)(*puVar15 != 0);
                                  }
                                  else {
                                    pBVar8->top = 3;
                                  }
                                }
                                else {
                                  uVar11 = 1;
                                  pBVar8->top = (int)&SUB_00000004;
                                }
                              }
                              else {
                                uVar11 = 1;
                                pBVar8->top = (int)&DAT_00000005;
                              }
                            }
                            else {
                              uVar11 = 1;
                              pBVar8->top = (int)&DAT_00000006;
                            }
                          }
                          else {
                            uVar11 = 1;
                            pBVar8->top = (int)&DAT_00000007;
                          }
                        }
                        else {
                          uVar11 = 1;
                          pBVar8->top = (int)&DAT_00000008;
                        }
                      }
                      else {
                        uVar11 = 1;
                        pBVar8->top = (int)&DAT_00000009;
                      }
                    }
                    else {
                      uVar11 = 1;
                      pBVar8->top = (int)&DAT_0000000a;
                    }
                  }
                  else {
                    uVar11 = 1;
                    pBVar8->top = (int)&DAT_0000000b;
                  }
                }
                else {
                  uVar11 = 1;
                  pBVar8->top = (int)&SUB_0000000c;
                }
              }
              else {
                uVar11 = 1;
                pBVar8->top = (int)&DAT_0000000d;
              }
            }
            else {
              uVar11 = 1;
              pBVar8->top = (int)&DAT_0000000e;
            }
          }
          else {
            uVar11 = 1;
            pBVar8->top = (int)&DAT_0000000f;
          }
        }
        else {
          uVar11 = 1;
          pBVar8->top = (int)&SUB_00000010;
        }
      }
      else {
        uVar11 = 1;
        pBVar8->top = (int)&DAT_00000011;
      }
      goto LAB_0062c9a0;
    }
  }
  uVar11 = (*(code *)PTR_BN_nnmod_006a8548)(pBVar8,pBVar7,_bignum_nist_p_521);
LAB_0062c9a0:
  while( true ) {
    if (iStack_dc == *(int *)puVar13) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0062cfd4:
    pBVar8->top = (int)&SUB_00000002;
  }
  return uVar11;
}

