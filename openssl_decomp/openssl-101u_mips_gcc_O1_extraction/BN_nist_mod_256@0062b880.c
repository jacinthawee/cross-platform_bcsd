
int BN_nist_mod_256(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int **ppiVar5;
  uint *puVar6;
  ulong **ppuVar7;
  ulong uVar8;
  BIGNUM *pBVar9;
  BIGNUM *pBVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  ulong *puVar14;
  ulong *puVar15;
  code *pcVar16;
  uint uVar17;
  ulong *puVar18;
  BIGNUM *unaff_s4;
  uint uVar19;
  int *piVar20;
  ulong *puVar21;
  BIGNUM *unaff_s5;
  uint uVar22;
  int iVar23;
  uint unaff_s6;
  ulong *puVar24;
  ulong *puVar25;
  uint unaff_s7;
  ulong *puVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint unaff_s8;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint auStack_1a8 [4];
  uint uStack_198;
  uint uStack_194;
  uint uStack_190;
  uint uStack_18c;
  uint uStack_188;
  uint uStack_184;
  uint uStack_180;
  uint uStack_17c;
  uint uStack_178;
  uint uStack_174;
  uint uStack_170;
  uint uStack_16c;
  uint uStack_168;
  int iStack_164;
  undefined *puStack_160;
  BIGNUM *pBStack_15c;
  BIGNUM *pBStack_158;
  uint uStack_154;
  BIGNUM *pBStack_150;
  BIGNUM *pBStack_14c;
  uint uStack_148;
  uint uStack_144;
  uint uStack_140;
  code *pcStack_13c;
  undefined *puStack_128;
  BN_CTX *pBStack_11c;
  uint uStack_114;
  uint uStack_110;
  uint uStack_10c;
  uint uStack_108;
  uint uStack_104;
  uint uStack_100;
  ulong *puStack_fc;
  uint uStack_f8;
  uint uStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  ulong *puStack_e8;
  BIGNUM aBStack_e4 [2];
  BIGNUM *pBStack_b4;
  BIGNUM *pBStack_b0;
  uint uStack_ac;
  undefined *puStack_a8;
  BIGNUM *pBStack_a4;
  BIGNUM *pBStack_a0;
  BIGNUM *pBStack_9c;
  uint uStack_98;
  int *local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  ulong *local_48;
  BIGNUM BStack_44;
  BIGNUM *local_24;
  
  puStack_a8 = PTR___stack_chk_guard_006a9ae8;
  uStack_ac = a->neg;
  local_24 = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pBStack_158 = a;
  if (uStack_ac == 0) {
    unaff_s5 = (BIGNUM *)a->top;
    unaff_s4 = (BIGNUM *)a->d;
    iVar4 = (*(code *)PTR_BN_ucmp_006a7fb4)(a,_bignum_nist_p_256_sqr_6188);
    if (-1 < iVar4) goto LAB_0062b8f8;
    iVar4 = (*(code *)PTR_BN_ucmp_006a7fb4)(_bignum_nist_p_256);
    if (iVar4 == 0) {
      pBStack_158 = (BIGNUM *)0x0;
      uStack_ac = 1;
      (*(code *)PTR_BN_set_word_006a7730)(r);
    }
    else if (iVar4 < 1) {
      pBVar10 = unaff_s4;
      if (a != r) {
        if (r->dmax < 8) {
          pBStack_158 = (BIGNUM *)&DAT_00000008;
          iVar4 = (*(code *)PTR_bn_expand2_006a8524)(r);
          a = unaff_s4;
          if (iVar4 == 0) goto LAB_0062b918;
          puVar21 = unaff_s4->d;
        }
        else {
          puVar21 = unaff_s4->d;
        }
        pBVar10 = (BIGNUM *)r->d;
        pBVar10->d = puVar21;
        pBVar10->top = unaff_s4->top;
        pBVar10->dmax = unaff_s4->dmax;
        pBVar10->neg = unaff_s4->neg;
        pBVar10->flags = unaff_s4->flags;
        pBVar10[1].d = unaff_s4[1].d;
        pBVar10[1].top = unaff_s4[1].top;
        pBVar10[1].dmax = unaff_s4[1].dmax;
      }
      if ((int)unaff_s5 < 9) {
        piVar20 = (int *)0x0;
        ppiVar5 = &local_64;
        bVar1 = true;
LAB_0062ba28:
        iVar4 = 4;
        if (bVar1) {
          iVar4 = (int)piVar20 * -4 + 0x20;
        }
        (*(code *)PTR_memset_006a99f4)(ppiVar5 + (int)piVar20,0,iVar4);
      }
      else {
        piVar20 = &unaff_s5[-1].neg;
        ppiVar5 = (int **)(*(code *)PTR_memcpy_006a9aec)
                                    (&local_64,&unaff_s4[1].neg,(int)unaff_s5 * 4 + -0x20);
        bVar1 = (int)piVar20 < 8;
        if (bVar1) goto LAB_0062ba28;
      }
      pcVar16 = (code *)PTR_bn_sub_words_006a8580;
      puVar18 = pBVar10->d;
      puVar21 = (ulong *)((int)puVar18 + (int)local_64);
      puVar14 = (ulong *)((int)puVar21 + local_60);
      puVar25 = (ulong *)((int)puVar14 - local_58);
      puVar15 = (ulong *)((int)puVar25 - local_54);
      uVar33 = pBVar10->flags;
      puVar26 = pBVar10[1].d;
      puVar24 = (ulong *)((int)puVar15 - local_50);
      uVar32 = pBVar10[1].top;
      uVar31 = pBVar10[1].dmax;
      pBVar10->d = (ulong *)((int)puVar24 - local_4c);
      iVar4 = (((((uint)(puVar14 < puVar21) + (uint)(puVar21 < puVar18)) - (uint)(puVar14 < puVar25)
                ) - (uint)(puVar25 < puVar15)) - (uint)(puVar15 < puVar24)) -
              (uint)(puVar24 < (ulong *)((int)puVar24 - local_4c));
      uVar34 = pBVar10->top + iVar4;
      uVar17 = local_60 + uVar34;
      uVar19 = uVar17 + local_5c;
      unaff_s6 = uVar19 - local_54;
      uVar29 = unaff_s6 - local_50;
      uVar27 = uVar29 - local_4c;
      iVar4 = (((((uint)(uVar19 < uVar17) +
                 (uint)(uVar17 < local_60) + (uint)(uVar34 < (uint)pBVar10->top) + (iVar4 >> 0x1f))
                - (uint)(uVar19 < unaff_s6)) - (uint)(unaff_s6 < uVar29)) - (uint)(uVar29 < uVar27))
              - (uint)(uVar27 < uVar27 - (int)local_48);
      pBVar10->top = uVar27 - (int)local_48;
      uVar17 = pBVar10->dmax + iVar4;
      uVar19 = local_5c + uVar17;
      uVar29 = local_58 + uVar19;
      uVar34 = uVar29 - local_50;
      uVar27 = uVar34 - local_4c;
      iVar4 = ((((uint)(uVar29 < local_58) +
                (uint)(uVar19 < local_5c) + (uint)(uVar17 < (uint)pBVar10->dmax) + (iVar4 >> 0x1f))
               - (uint)(uVar29 < uVar34)) - (uint)(uVar34 < uVar27)) -
              (uint)(uVar27 < uVar27 - (int)local_48);
      pBVar10->dmax = uVar27 - (int)local_48;
      uVar27 = pBVar10->neg + iVar4;
      uVar29 = local_58 + uVar27;
      uVar22 = local_58 + uVar29;
      uVar34 = local_54 + uVar22;
      uVar17 = local_54 + uVar34;
      uVar19 = local_50 + uVar17;
      uVar28 = uVar19 - (int)local_48;
      uVar30 = uVar28 - (int)local_64;
      iVar4 = ((((uint)(uVar19 < local_50) +
                (uint)(uVar17 < local_54) +
                (uint)(uVar34 < local_54) +
                (uint)(uVar22 < local_58) +
                (uint)(uVar29 < local_58) + (uint)(uVar27 < (uint)pBVar10->neg) + (iVar4 >> 0x1f)) -
               (uint)(uVar19 < uVar28)) - (uint)(uVar28 < uVar30)) -
              (uint)(uVar30 < uVar30 - local_60);
      pBVar10->neg = uVar30 - local_60;
      uVar29 = uVar33 + iVar4;
      uVar19 = local_54 + uVar29;
      uVar34 = local_54 + uVar19;
      uVar27 = local_50 + uVar34;
      uVar22 = local_50 + uVar27;
      uVar17 = local_4c + uVar22;
      uVar28 = uVar17 - local_60;
      pBVar10->flags = uVar28 - local_5c;
      iVar4 = (((uint)(uVar17 < local_4c) +
               (uint)(uVar22 < local_50) +
               (uint)(uVar27 < local_50) +
               (uint)(uVar34 < local_54) +
               (uint)(uVar19 < local_54) + (uint)(uVar29 < uVar33) + (iVar4 >> 0x1f)) -
              (uint)(uVar17 < uVar28)) - (uint)(uVar28 < uVar28 - local_5c);
      puVar15 = (ulong *)((int)puVar26 + iVar4);
      uVar29 = local_50 + (int)puVar15;
      uVar17 = local_50 + uVar29;
      uVar34 = local_4c + uVar17;
      uVar19 = local_4c + uVar34;
      puVar21 = (ulong *)((int)local_48 + uVar19);
      puVar18 = (ulong *)((int)puVar21 - local_5c);
      pBVar10[1].d = (ulong *)((int)puVar18 - local_58);
      iVar4 = (((uint)(puVar21 < local_48) +
               (uint)(uVar19 < local_4c) +
               (uint)(uVar34 < local_4c) +
               (uint)(uVar17 < local_50) +
               (uint)(uVar29 < local_50) + (uint)(puVar15 < puVar26) + (iVar4 >> 0x1f)) -
              (uint)(puVar21 < puVar18)) - (uint)(puVar18 < (ulong *)((int)puVar18 - local_58));
      uVar29 = uVar32 + iVar4;
      uVar34 = local_4c + uVar29;
      uVar19 = local_4c + uVar34;
      puVar15 = (ulong *)((int)local_48 + uVar19);
      puVar21 = (ulong *)((int)local_48 + (int)puVar15);
      uVar27 = local_4c + (int)puVar21;
      uVar17 = local_50 + uVar27;
      uVar22 = uVar17 - (int)local_64;
      pBVar10[1].top = uVar22 - local_60;
      iVar4 = (((uint)(uVar17 < local_50) +
               (uint)(uVar27 < local_4c) +
               (uint)(puVar21 < local_48) +
               (uint)(puVar15 < local_48) +
               (uint)(uVar19 < local_4c) +
               (uint)(uVar34 < local_4c) + (uint)(uVar29 < uVar32) + (iVar4 >> 0x1f)) -
              (uint)(uVar17 < uVar22)) - (uint)(uVar22 < uVar22 - local_60);
      uVar17 = uVar31 + iVar4;
      puVar15 = (ulong *)((int)local_48 + uVar17);
      puVar21 = (ulong *)((int)local_48 + (int)puVar15);
      puVar18 = (ulong *)((int)local_48 + (int)puVar21);
      piVar20 = (int *)((int)local_64 + (int)puVar18);
      piVar13 = (int *)((int)piVar20 - local_5c);
      piVar12 = (int *)((int)piVar13 - local_58);
      piVar11 = (int *)((int)piVar12 - local_54);
      uVar17 = (((((uint)(piVar20 < local_64) +
                  (uint)(puVar18 < local_48) +
                  (uint)(puVar21 < local_48) +
                  (uint)(puVar15 < local_48) + (uint)(uVar17 < uVar31) + (iVar4 >> 0x1f)) -
                 (uint)(piVar20 < piVar13)) - (uint)(piVar13 < piVar12)) - (uint)(piVar12 < piVar11)
               ) - (uint)(piVar11 < (int *)((int)piVar11 - local_50));
      pBVar10[1].dmax = (int)(int *)((int)piVar11 - local_50);
      if (((int)uVar17 < 0) || (uVar17 == 0)) {
        if (((int)uVar17 >> 0x1f | uVar17) == 0) {
          unaff_s5 = (BIGNUM *)0xffffffff;
        }
        else {
          iVar4 = (*(code *)PTR_bn_add_words_006a8584)
                            (pBVar10,pBVar10,_nist_p_256 + ~uVar17 * 0x20,8);
          unaff_s5 = (BIGNUM *)-iVar4;
          pcVar16 = (code *)(((uint)pcVar16 ^ (uint)PTR_bn_add_words_006a8584) & (uint)unaff_s5 ^
                            (uint)PTR_bn_add_words_006a8584);
        }
      }
      else {
        iVar4 = (*(code *)PTR_bn_sub_words_006a8580)
                          (pBVar10,pBVar10,_nist_p_256 + (uVar17 - 1) * 0x20,8);
        unaff_s5 = (BIGNUM *)-iVar4;
      }
      unaff_s4 = &BStack_44;
      ctx = (BN_CTX *)&DAT_00000008;
      pBStack_158 = pBVar10;
      iVar4 = (*pcVar16)(unaff_s4,pBVar10,_nist_p_256);
      puVar21 = r->d;
      ppuVar7 = (ulong **)
                (((uint)pBVar10 ^ (uint)unaff_s4) & (uint)unaff_s5 & -iVar4 ^ (uint)unaff_s4);
      pBVar10->d = *ppuVar7;
      pBVar10->top = (int)ppuVar7[1];
      pBVar10->dmax = (int)ppuVar7[2];
      pBVar10->neg = (int)ppuVar7[3];
      pBVar10->flags = (int)ppuVar7[4];
      pBVar10[1].d = ppuVar7[5];
      pBVar10[1].top = (int)ppuVar7[6];
      pBVar10[1].dmax = (int)ppuVar7[7];
      r->top = 8;
      a = pBVar10;
      if (puVar21[7] == 0) {
        if (puVar21[6] == 0) {
          if (puVar21[5] == 0) {
            if (puVar21[4] == 0) {
              if (puVar21[3] == 0) {
                if (puVar21[2] == 0) {
                  if (puVar21[1] == 0) {
                    uStack_ac = 1;
                    r->top = (uint)(*puVar21 != 0);
                  }
                  else {
                    uStack_ac = 1;
                    r->top = 2;
                  }
                }
                else {
                  uStack_ac = 1;
                  r->top = 3;
                }
              }
              else {
                uStack_ac = 1;
                r->top = 4;
              }
            }
            else {
              uStack_ac = 1;
              r->top = 5;
            }
          }
          else {
            uStack_ac = 1;
            r->top = 6;
          }
        }
        else {
          uStack_ac = 1;
          r->top = 7;
        }
      }
      else {
        uStack_ac = 1;
        r->top = 8;
      }
    }
    else if (a == r) {
      uStack_ac = 1;
    }
    else {
      pBStack_158 = a;
      iVar4 = (*(code *)PTR_BN_copy_006a8450)(r);
      uStack_ac = (uint)(iVar4 != 0);
    }
  }
  else {
LAB_0062b8f8:
    uStack_ac = (*(code *)PTR_BN_nnmod_006a8548)(r,a,_bignum_nist_p_256);
  }
LAB_0062b918:
  if (local_24 == *(BIGNUM **)puStack_a8) {
    return uStack_ac;
  }
  pBStack_15c = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_160 = PTR___stack_chk_guard_006a9ae8;
  uStack_154 = pBStack_158->neg;
  puStack_128 = &_gp;
  pBStack_b4 = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pBStack_150 = unaff_s4;
  pBStack_14c = unaff_s5;
  pBStack_b0 = a;
  pBStack_a4 = r;
  pBStack_a0 = unaff_s4;
  pBStack_9c = unaff_s5;
  uStack_98 = unaff_s6;
  pBVar10 = pBStack_158;
  if (uStack_154 == 0) {
    pBStack_150 = (BIGNUM *)pBStack_158->top;
    pBStack_14c = (BIGNUM *)pBStack_158->d;
    pBStack_11c = ctx;
    iVar4 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBStack_158,_bignum_nist_p_384_sqr_6219);
    if (-1 < iVar4) goto LAB_0062c060;
    iVar4 = (**(code **)(puStack_128 + -0x6e2c))(_bignum_nist_p_384);
    if (iVar4 == 0) {
      pBVar10 = (BIGNUM *)0x0;
      uStack_154 = 1;
      (**(code **)(puStack_128 + -0x76b0))(pBStack_15c);
    }
    else if (iVar4 < 1) {
      pBStack_158 = pBStack_14c;
      if (pBStack_158 != pBStack_15c) {
        if (pBStack_15c->dmax < 0xc) {
          pBVar10 = (BIGNUM *)&SUB_0000000c;
          iVar4 = (**(code **)(puStack_128 + -0x68bc))(pBStack_15c);
          if (iVar4 == 0) goto LAB_0062c080;
          puVar21 = pBStack_14c->d;
        }
        else {
          puVar21 = pBStack_14c->d;
        }
        pBStack_158 = (BIGNUM *)pBStack_15c->d;
        pBStack_158->d = puVar21;
        pBStack_158->top = pBStack_14c->top;
        pBStack_158->dmax = pBStack_14c->dmax;
        pBStack_158->neg = pBStack_14c->neg;
        pBStack_158->flags = pBStack_14c->flags;
        pBStack_158[1].d = pBStack_14c[1].d;
        pBStack_158[1].top = pBStack_14c[1].top;
        pBStack_158[1].dmax = pBStack_14c[1].dmax;
        pBStack_158[1].neg = pBStack_14c[1].neg;
        pBStack_158[1].flags = pBStack_14c[1].flags;
        pBStack_158[2].d = pBStack_14c[2].d;
        pBStack_158[2].top = pBStack_14c[2].top;
      }
      if ((int)pBStack_150 < 0xd) {
        piVar20 = (int *)0x0;
        puVar6 = &uStack_114;
        bVar1 = true;
LAB_0062c1b8:
        iVar4 = 4;
        if (bVar1) {
          iVar4 = (int)piVar20 * -4 + 0x30;
        }
        (**(code **)(puStack_128 + -0x53ec))(puVar6 + (int)piVar20,0,iVar4);
      }
      else {
        piVar20 = &pBStack_150[-1].dmax;
        puVar6 = (uint *)(**(code **)(puStack_128 + -0x52f4))
                                   (&uStack_114,&pBStack_14c[2].dmax,(int)pBStack_150 * 4 + -0x30);
        bVar1 = (int)piVar20 < 0xc;
        if (bVar1) goto LAB_0062c1b8;
      }
      puVar15 = (ulong *)((int)pBStack_158->d + uStack_114);
      puVar21 = (ulong *)((int)puVar15 + uStack_f0);
      puVar18 = (ulong *)((int)puVar21 + uStack_f4);
      uVar27 = pBStack_158->neg;
      puVar25 = pBStack_158[1].d;
      iVar4 = ((uint)(puVar18 < puVar21) +
              (uint)(puVar21 < puVar15) + (uint)(puVar15 < pBStack_158->d)) -
              (uint)(puVar18 < (ulong *)((int)puVar18 - (int)puStack_e8));
      uVar22 = pBStack_158[1].top;
      uVar17 = pBStack_158->top + iVar4;
      uVar34 = pBStack_158[1].dmax;
      uVar29 = uVar17 + uStack_110;
      pBStack_158->d = (ulong *)((int)puVar18 - (int)puStack_e8);
      pcVar16 = *(code **)(puStack_128 + -0x6860);
      puVar21 = (ulong *)((int)puStack_e8 + uVar29 + uStack_ec);
      puVar15 = (ulong *)((int)puVar21 - uStack_114);
      iVar4 = (((uint)(puVar21 < puStack_e8) +
               (uint)(uVar29 + uStack_ec < uVar29) +
               (uint)(uVar29 < uVar17) + (uint)(uVar17 < (uint)pBStack_158->top) + (iVar4 >> 0x1f))
              - (uint)(puVar21 < puVar15)) - (uint)(puVar15 < (ulong *)((int)puVar15 - uStack_f4));
      pBStack_158->top = (int)(ulong *)((int)puVar15 - uStack_f4);
      uVar17 = pBStack_158->dmax + iVar4;
      puVar21 = (ulong *)((int)puStack_e8 + uVar17 + uStack_10c);
      puVar15 = (ulong *)((int)puVar21 - uStack_110);
      iVar4 = (((uint)(puVar21 < puStack_e8) +
               (uint)(uVar17 + uStack_10c < uVar17) +
               (uint)(uVar17 < (uint)pBStack_158->dmax) + (iVar4 >> 0x1f)) -
              (uint)(puVar21 < puVar15)) - (uint)(puVar15 < (ulong *)((int)puVar15 - uStack_f0));
      pBStack_158->dmax = (int)(ulong *)((int)puVar15 - uStack_f0);
      uVar29 = uVar27 + iVar4;
      uVar28 = uStack_114 + uVar29 + uStack_108;
      uVar17 = uStack_f4 + uVar28;
      uVar19 = uStack_f0 + uVar17;
      unaff_s8 = uVar19 - uStack_10c;
      uVar31 = unaff_s8 - uStack_ec;
      pBStack_158->neg = uVar31 - (int)puStack_e8;
      iVar4 = ((((uint)(uVar19 < uStack_f0) +
                (uint)(uVar17 < uStack_f4) +
                (uint)(uVar28 < uStack_114) +
                (uint)(uVar29 + uStack_108 < uVar29) + (uint)(uVar29 < uVar27) + (iVar4 >> 0x1f)) -
               (uint)(uVar19 < unaff_s8)) - (uint)(unaff_s8 < uVar31)) -
              (uint)(uVar31 < uVar31 - (int)puStack_e8);
      uVar28 = pBStack_158->flags + iVar4;
      uVar32 = uStack_f0 + uVar28;
      uVar19 = uStack_f0 + uVar32;
      uVar17 = uStack_110 + uVar19 + uStack_104;
      uVar31 = uStack_114 + uVar17;
      uVar29 = uStack_f4 + uVar31;
      uVar33 = uStack_ec + uVar29;
      uVar27 = uVar33 - uStack_108;
      unaff_s7 = uVar27 - (int)puStack_e8;
      iVar4 = ((((uint)(uVar33 < uStack_ec) +
                (uint)(uVar29 < uStack_f4) +
                (uint)(uVar31 < uStack_114) +
                (uint)(uVar17 < uStack_110) +
                (uint)(uVar19 + uStack_104 < uVar19) +
                (uint)(uVar19 < uStack_f0) +
                (uint)(uVar32 < uStack_f0) +
                (uint)(uVar28 < (uint)pBStack_158->flags) + (iVar4 >> 0x1f)) -
               (uint)(uVar33 < uVar27)) - (uint)(uVar27 < unaff_s7)) -
              (uint)(unaff_s7 < unaff_s7 - (int)puStack_e8);
      pBStack_158->flags = unaff_s7 - (int)puStack_e8;
      puVar21 = (ulong *)((int)puVar25 + iVar4);
      uVar19 = uStack_ec + (int)puVar21;
      unaff_s6 = (uint)(puVar21 < puVar25);
      uVar28 = uStack_ec + uVar19;
      uVar17 = uStack_10c + uVar28 + uStack_100;
      uVar27 = uStack_110 + uVar17;
      uVar29 = uStack_f0 + uVar27;
      puVar21 = (ulong *)((int)puStack_e8 + uVar29);
      pBStack_158[1].d = (ulong *)((int)puVar21 - uStack_104);
      iVar4 = unaff_s6 +
              (((uint)(puVar21 < puStack_e8) +
               (uint)(uVar29 < uStack_f0) +
               (uint)(uVar27 < uStack_110) +
               (uint)(uVar17 < uStack_10c) +
               (uint)(uVar28 + uStack_100 < uVar28) +
               (uint)(uVar28 < uStack_ec) + (uint)(uVar19 < uStack_ec) + (iVar4 >> 0x1f)) -
              (uint)(puVar21 < (ulong *)((int)puVar21 - uStack_104)));
      uVar29 = uVar22 + iVar4;
      puVar15 = (ulong *)((int)puStack_e8 + uVar29);
      puVar21 = (ulong *)((int)puStack_e8 + (int)puVar15);
      uVar17 = uStack_108 + (int)(ulong *)((int)puVar21 + (int)puStack_fc);
      uVar19 = uStack_10c + uVar17;
      uVar27 = uStack_ec + uVar19;
      pBStack_158[1].top = uVar27 - uStack_100;
      iVar4 = ((uint)(uVar27 < uStack_ec) +
              (uint)(uVar19 < uStack_10c) +
              (uint)(uVar17 < uStack_108) +
              (uint)((ulong *)((int)puVar21 + (int)puStack_fc) < puVar21) +
              (uint)(puVar21 < puStack_e8) +
              (uint)(puVar15 < puStack_e8) + (uint)(uVar29 < uVar22) + (iVar4 >> 0x1f)) -
              (uint)(uVar27 < uVar27 - uStack_100);
      uVar19 = uVar34 + iVar4;
      uVar29 = uStack_104 + uVar19 + uStack_f8;
      uVar17 = uStack_108 + uVar29;
      puVar21 = (ulong *)((int)puStack_e8 + uVar17);
      uVar27 = pBStack_158[1].neg;
      iVar4 = ((uint)(puVar21 < puStack_e8) +
              (uint)(uVar17 < uStack_108) +
              (uint)(uVar29 < uStack_104) +
              (uint)(uVar19 + uStack_f8 < uVar19) + (uint)(uVar19 < uVar34) + (iVar4 >> 0x1f)) -
              (uint)(puVar21 < (ulong *)((int)puVar21 - (int)puStack_fc));
      pBStack_158[1].dmax = (int)(ulong *)((int)puVar21 - (int)puStack_fc);
      uVar17 = pBStack_158[1].neg + iVar4;
      uVar34 = uStack_f4 + uVar17;
      uVar29 = uStack_100 + uVar34;
      uVar19 = uStack_104 + uVar29;
      pBStack_158[1].neg = uVar19 - uStack_f8;
      iVar4 = ((uint)(uVar19 < uStack_104) +
              (uint)(uVar29 < uStack_100) +
              (uint)(uVar34 < uStack_f4) + (uint)(uVar17 < uVar27) + (iVar4 >> 0x1f)) -
              (uint)(uVar19 < uVar19 - uStack_f8);
      uVar34 = pBStack_158[1].flags;
      uVar17 = pBStack_158[1].flags + iVar4;
      uVar29 = uStack_f0 + uVar17;
      puVar21 = (ulong *)((int)puStack_fc + uVar29);
      uVar19 = uStack_100 + (int)puVar21;
      pBStack_158[1].flags = uVar19 - uStack_f4;
      puVar18 = pBStack_158[2].d;
      iVar4 = ((uint)(uVar19 < uStack_100) +
              (uint)(puVar21 < puStack_fc) +
              (uint)(uVar29 < uStack_f0) + (uint)(uVar17 < uVar34) + (iVar4 >> 0x1f)) -
              (uint)(uVar19 < uVar19 - uStack_f4);
      puVar21 = (ulong *)((int)puVar18 + iVar4);
      uVar29 = uStack_ec + (int)puVar21;
      uVar17 = uStack_f8 + uVar29;
      puVar15 = (ulong *)((int)puStack_fc + uVar17);
      pBStack_158[2].d = (ulong *)((int)puVar15 - uStack_f0);
      iVar4 = ((uint)(puVar15 < puStack_fc) +
              (uint)(uVar17 < uStack_f8) +
              (uint)(uVar29 < uStack_ec) + (uint)(puVar21 < puVar18) + (iVar4 >> 0x1f)) -
              (uint)(puVar15 < (ulong *)((int)puVar15 - uStack_f0));
      uVar17 = pBStack_158[2].top + iVar4;
      puVar21 = (ulong *)((int)puStack_e8 + uVar17);
      uVar34 = uStack_f4 + (int)puVar21;
      uVar29 = uStack_f8 + uVar34;
      uVar17 = ((uint)(uVar29 < uStack_f8) +
               (uint)(uVar34 < uStack_f4) +
               (uint)(puVar21 < puStack_e8) +
               (uint)(uVar17 < (uint)pBStack_158[2].top) + (iVar4 >> 0x1f)) -
               (uint)(uVar29 < uVar29 - uStack_ec);
      pBStack_158[2].top = uVar29 - uStack_ec;
      if (((int)uVar17 < 0) || (uVar17 == 0)) {
        if (((int)uVar17 >> 0x1f | uVar17) == 0) {
          pBStack_14c = (BIGNUM *)0xffffffff;
        }
        else {
          iVar4 = (**(code **)(puStack_128 + -0x685c))
                            (pBStack_158,pBStack_158,_nist_p_384 + ~uVar17 * 0x30,0xc);
          pBStack_14c = (BIGNUM *)-iVar4;
          pcVar16 = (code *)(((uint)pcVar16 ^ *(uint *)(puStack_128 + -0x685c)) & (uint)pBStack_14c
                            ^ *(uint *)(puStack_128 + -0x685c));
        }
      }
      else {
        iVar4 = (**(code **)(puStack_128 + -0x6860))
                          (pBStack_158,pBStack_158,_nist_p_384 + (uVar17 - 1) * 0x30,0xc);
        pBStack_14c = (BIGNUM *)-iVar4;
      }
      pBStack_150 = aBStack_e4;
      pBVar10 = pBStack_158;
      iVar4 = (*pcVar16)(pBStack_150,pBStack_158,_nist_p_384);
      puVar21 = pBStack_15c->d;
      ppuVar7 = (ulong **)
                (((uint)pBStack_158 ^ (uint)pBStack_150) & (uint)pBStack_14c & -iVar4 ^
                (uint)pBStack_150);
      pBStack_158->d = *ppuVar7;
      pBStack_158->top = (int)ppuVar7[1];
      pBStack_158->dmax = (int)ppuVar7[2];
      pBStack_158->neg = (int)ppuVar7[3];
      pBStack_158->flags = (int)ppuVar7[4];
      pBStack_158[1].d = ppuVar7[5];
      pBStack_158[1].top = (int)ppuVar7[6];
      pBStack_158[1].dmax = (int)ppuVar7[7];
      pBStack_158[1].neg = (int)ppuVar7[8];
      pBStack_158[1].flags = (int)ppuVar7[9];
      pBStack_158[2].d = ppuVar7[10];
      pBStack_158[2].top = (int)ppuVar7[0xb];
      pBStack_15c->top = (int)&SUB_0000000c;
      if (puVar21[0xb] == 0) {
        if (puVar21[10] == 0) {
          if (puVar21[9] == 0) {
            if (puVar21[8] == 0) {
              if (puVar21[7] == 0) {
                if (puVar21[6] == 0) {
                  if (puVar21[5] == 0) {
                    if (puVar21[4] == 0) {
                      if (puVar21[3] == 0) {
                        if (puVar21[2] == 0) {
                          if (puVar21[1] == 0) {
                            uStack_154 = 1;
                            pBStack_15c->top = (uint)(*puVar21 != 0);
                          }
                          else {
                            uStack_154 = 1;
                            pBStack_15c->top = (int)&SUB_00000002;
                          }
                        }
                        else {
                          uStack_154 = 1;
                          pBStack_15c->top = 3;
                        }
                      }
                      else {
                        uStack_154 = 1;
                        pBStack_15c->top = (int)&SUB_00000004;
                      }
                    }
                    else {
                      uStack_154 = 1;
                      pBStack_15c->top = (int)&DAT_00000005;
                    }
                  }
                  else {
                    uStack_154 = 1;
                    pBStack_15c->top = (int)&DAT_00000006;
                  }
                }
                else {
                  uStack_154 = 1;
                  pBStack_15c->top = (int)&DAT_00000007;
                }
              }
              else {
                uStack_154 = 1;
                pBStack_15c->top = (int)&DAT_00000008;
              }
            }
            else {
              uStack_154 = 1;
              pBStack_15c->top = (int)&DAT_00000009;
            }
          }
          else {
            uStack_154 = 1;
            pBStack_15c->top = (int)&DAT_0000000a;
          }
        }
        else {
          uStack_154 = 1;
          pBStack_15c->top = (int)&DAT_0000000b;
        }
      }
      else {
        uStack_154 = 1;
        pBStack_15c->top = (int)&SUB_0000000c;
      }
    }
    else if (pBStack_158 == pBStack_15c) {
      uStack_154 = 1;
    }
    else {
      pBVar10 = pBStack_158;
      iVar4 = (**(code **)(puStack_128 + -0x6990))(pBStack_15c);
      uStack_154 = (uint)(iVar4 != 0);
    }
  }
  else {
LAB_0062c060:
    uStack_154 = (**(code **)(puStack_128 + -0x6898))(pBStack_15c,pBStack_158,_bignum_nist_p_384);
  }
LAB_0062c080:
  if (pBStack_b4 == *(BIGNUM **)puStack_160) {
    return uStack_154;
  }
  pcStack_13c = BN_nist_mod_521;
  pBVar9 = pBStack_b4;
  (**(code **)(puStack_128 + -0x5330))();
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  uVar17 = pBVar10->neg;
  iStack_164 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_148 = unaff_s6;
  uStack_144 = unaff_s7;
  uStack_140 = unaff_s8;
  if (uVar17 == 0) {
    iVar23 = pBVar10->top;
    puVar21 = pBVar10->d;
    iVar4 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBVar10,_bignum_nist_p_521_sqr_6243);
    if (iVar4 < 0) {
      iVar4 = (*(code *)PTR_BN_ucmp_006a7fb4)(_bignum_nist_p_521,pBVar10);
      if (iVar4 == 0) {
        uVar17 = 1;
        (*(code *)PTR_BN_set_word_006a7730)(pBVar9,0);
        goto LAB_0062c9a0;
      }
      if (0 < iVar4) {
        if (pBVar10 == pBVar9) {
          uVar17 = 1;
        }
        else {
          iVar4 = (*(code *)PTR_BN_copy_006a8450)(pBVar9,pBVar10);
          uVar17 = (uint)(iVar4 != 0);
        }
        goto LAB_0062c9a0;
      }
      puVar15 = puVar21;
      if (pBVar10 != pBVar9) {
        if (pBVar9->dmax < 0x11) {
          iVar4 = (*(code *)PTR_bn_expand2_006a8524)(pBVar9,0x11);
          if (iVar4 == 0) goto LAB_0062c9a0;
          uVar8 = *puVar21;
        }
        else {
          uVar8 = *puVar21;
        }
        puVar15 = pBVar9->d;
        *puVar15 = uVar8;
        puVar15[1] = puVar21[1];
        puVar15[2] = puVar21[2];
        puVar15[3] = puVar21[3];
        puVar15[4] = puVar21[4];
        puVar15[5] = puVar21[5];
        puVar15[6] = puVar21[6];
        puVar15[7] = puVar21[7];
        puVar15[8] = puVar21[8];
        puVar15[9] = puVar21[9];
        puVar15[10] = puVar21[10];
        puVar15[0xb] = puVar21[0xb];
        puVar15[0xc] = puVar21[0xc];
        puVar15[0xd] = puVar21[0xd];
        puVar15[0xe] = puVar21[0xe];
        puVar15[0xf] = puVar21[0xf];
        puVar15[0x10] = puVar21[0x10];
      }
      puVar18 = puVar21 + 0x10;
      if (iVar23 < 0x11) {
        iVar23 = 0;
        bVar1 = true;
LAB_0062cb08:
        iVar4 = 4;
        if (bVar1) {
          iVar4 = iVar23 * -4 + 0x44;
        }
        (*(code *)PTR_memset_006a99f4)(auStack_1a8 + iVar23,0,iVar4);
      }
      else {
        puVar25 = auStack_1a8;
        do {
          uVar8 = *puVar18;
          puVar18 = puVar18 + 1;
          *puVar25 = uVar8;
          puVar25 = puVar25 + 1;
        } while (puVar18 != puVar21 + iVar23);
        iVar23 = iVar23 + -0x10;
        bVar1 = iVar23 < 0x11;
        if (bVar1) goto LAB_0062cb08;
      }
      puVar2 = PTR_bn_add_words_006a8584;
      uVar17 = auStack_1a8[1] << 0x17;
      auStack_1a8[1] = auStack_1a8[1] >> 9 | auStack_1a8[2] << 0x17;
      auStack_1a8[2] = auStack_1a8[2] >> 9 | auStack_1a8[3] << 0x17;
      uVar29 = uStack_170 << 0x17;
      uVar34 = uStack_174 << 0x17;
      auStack_1a8[3] = auStack_1a8[3] >> 9 | uStack_198 << 0x17;
      auStack_1a8[0] = auStack_1a8[0] >> 9 | uVar17;
      uStack_170 = uStack_170 >> 9 | uStack_16c << 0x17;
      uVar17 = uStack_168 << 0x17;
      uStack_168 = uStack_168 >> 9;
      uStack_16c = uStack_16c >> 9 | uVar17;
      uStack_198 = uStack_198 >> 9 | uStack_194 << 0x17;
      uStack_174 = uStack_174 >> 9 | uVar29;
      uStack_194 = uStack_194 >> 9 | uStack_190 << 0x17;
      uStack_190 = uStack_190 >> 9 | uStack_18c << 0x17;
      uStack_18c = uStack_18c >> 9 | uStack_188 << 0x17;
      uStack_188 = uStack_188 >> 9 | uStack_184 << 0x17;
      uStack_184 = uStack_184 >> 9 | uStack_180 << 0x17;
      uStack_180 = uStack_180 >> 9 | uStack_17c << 0x17;
      uStack_17c = uStack_17c >> 9 | uStack_178 << 0x17;
      uStack_178 = uStack_178 >> 9 | uVar34;
      puVar15[0x10] = puVar15[0x10] & 0x1ff;
      (*(code *)puVar2)(puVar15,puVar15,auStack_1a8,0x11);
      iVar4 = (*(code *)PTR_bn_sub_words_006a8580)(auStack_1a8,puVar15,_nist_p_521,0x11);
      puVar18 = (ulong *)((uint)auStack_1a8 ^ ((uint)puVar15 ^ (uint)auStack_1a8) & -iVar4);
      *puVar15 = *puVar18;
      puVar15[1] = puVar18[1];
      puVar15[2] = puVar18[2];
      puVar15[3] = puVar18[3];
      puVar15[4] = puVar18[4];
      puVar15[5] = puVar18[5];
      puVar15[6] = puVar18[6];
      puVar15[7] = puVar18[7];
      puVar15[8] = puVar18[8];
      puVar15[9] = puVar18[9];
      puVar15[10] = puVar18[10];
      puVar15[0xb] = puVar18[0xb];
      puVar15[0xc] = puVar18[0xc];
      puVar15[0xd] = puVar18[0xd];
      puVar15[0xe] = puVar18[0xe];
      puVar15[0xf] = puVar18[0xf];
      puVar21 = pBVar9->d;
      puVar15[0x10] = puVar18[0x10];
      pBVar9->top = (int)&DAT_00000011;
      if (puVar21[0x10] == 0) {
        if (puVar21[0xf] == 0) {
          if (puVar21[0xe] == 0) {
            if (puVar21[0xd] == 0) {
              if (puVar21[0xc] == 0) {
                if (puVar21[0xb] == 0) {
                  if (puVar21[10] == 0) {
                    if (puVar21[9] == 0) {
                      if (puVar21[8] == 0) {
                        if (puVar21[7] == 0) {
                          if (puVar21[6] == 0) {
                            if (puVar21[5] == 0) {
                              if (puVar21[4] == 0) {
                                if (puVar21[3] == 0) {
                                  uVar17 = 1;
                                  if (puVar21[2] == 0) {
                                    if (puVar21[1] != 0) goto LAB_0062cfd4;
                                    pBVar9->top = (uint)(*puVar21 != 0);
                                  }
                                  else {
                                    pBVar9->top = 3;
                                  }
                                }
                                else {
                                  uVar17 = 1;
                                  pBVar9->top = (int)&SUB_00000004;
                                }
                              }
                              else {
                                uVar17 = 1;
                                pBVar9->top = (int)&DAT_00000005;
                              }
                            }
                            else {
                              uVar17 = 1;
                              pBVar9->top = (int)&DAT_00000006;
                            }
                          }
                          else {
                            uVar17 = 1;
                            pBVar9->top = (int)&DAT_00000007;
                          }
                        }
                        else {
                          uVar17 = 1;
                          pBVar9->top = (int)&DAT_00000008;
                        }
                      }
                      else {
                        uVar17 = 1;
                        pBVar9->top = (int)&DAT_00000009;
                      }
                    }
                    else {
                      uVar17 = 1;
                      pBVar9->top = (int)&DAT_0000000a;
                    }
                  }
                  else {
                    uVar17 = 1;
                    pBVar9->top = (int)&DAT_0000000b;
                  }
                }
                else {
                  uVar17 = 1;
                  pBVar9->top = (int)&SUB_0000000c;
                }
              }
              else {
                uVar17 = 1;
                pBVar9->top = (int)&DAT_0000000d;
              }
            }
            else {
              uVar17 = 1;
              pBVar9->top = (int)&DAT_0000000e;
            }
          }
          else {
            uVar17 = 1;
            pBVar9->top = (int)&DAT_0000000f;
          }
        }
        else {
          uVar17 = 1;
          pBVar9->top = (int)&SUB_00000010;
        }
      }
      else {
        uVar17 = 1;
        pBVar9->top = (int)&DAT_00000011;
      }
      goto LAB_0062c9a0;
    }
  }
  uVar17 = (*(code *)PTR_BN_nnmod_006a8548)(pBVar9,pBVar10,_bignum_nist_p_521);
LAB_0062c9a0:
  while( true ) {
    if (iStack_164 == *(int *)puVar3) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0062cfd4:
    pBVar9->top = (int)&SUB_00000002;
  }
  return uVar17;
}

