
int BN_nist_mod_224(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  uint **ppuVar4;
  uint *puVar5;
  ulong **ppuVar6;
  ulong uVar7;
  BIGNUM *pBVar8;
  BIGNUM *pBVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  ulong *puVar13;
  ulong *puVar14;
  code *pcVar15;
  uint uVar16;
  ulong *puVar17;
  BIGNUM *unaff_s4;
  undefined *puVar18;
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
  uint auStack_228 [4];
  uint uStack_218;
  uint uStack_214;
  uint uStack_210;
  uint uStack_20c;
  uint uStack_208;
  uint uStack_204;
  uint uStack_200;
  uint uStack_1fc;
  uint uStack_1f8;
  uint uStack_1f4;
  uint uStack_1f0;
  uint uStack_1ec;
  uint uStack_1e8;
  int iStack_1e4;
  undefined *puStack_1e0;
  BIGNUM *pBStack_1dc;
  BIGNUM *pBStack_1d8;
  uint uStack_1d4;
  BIGNUM *pBStack_1d0;
  BIGNUM *pBStack_1cc;
  uint uStack_1c8;
  uint uStack_1c4;
  uint uStack_1c0;
  code *pcStack_1bc;
  undefined *puStack_1a8;
  BN_CTX *pBStack_19c;
  uint uStack_194;
  uint uStack_190;
  uint uStack_18c;
  uint uStack_188;
  uint uStack_184;
  uint uStack_180;
  ulong *puStack_17c;
  uint uStack_178;
  uint uStack_174;
  uint uStack_170;
  uint uStack_16c;
  ulong *puStack_168;
  BIGNUM aBStack_164 [2];
  BIGNUM *pBStack_134;
  BIGNUM *pBStack_130;
  uint uStack_12c;
  undefined *puStack_128;
  BIGNUM *pBStack_124;
  BIGNUM *pBStack_120;
  BIGNUM *pBStack_11c;
  uint uStack_118;
  uint *puStack_e4;
  uint uStack_e0;
  uint uStack_dc;
  uint uStack_d8;
  uint uStack_d4;
  uint uStack_d0;
  uint uStack_cc;
  ulong *puStack_c8;
  BIGNUM BStack_c4;
  BIGNUM *pBStack_a4;
  BIGNUM *pBStack_a0;
  uint uStack_9c;
  undefined *puStack_98;
  BIGNUM *pBStack_94;
  BIGNUM *pBStack_90;
  BIGNUM *pBStack_8c;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  ulong *local_44;
  BIGNUM BStack_40;
  BIGNUM *local_24;
  
  puStack_98 = PTR___stack_chk_guard_006a9ae8;
  uStack_9c = a->neg;
  local_24 = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pBStack_130 = a;
  if (uStack_9c == 0) {
    unaff_s4 = (BIGNUM *)a->top;
    unaff_s5 = (BIGNUM *)a->d;
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(a,_bignum_nist_p_224_sqr_6157);
    if (-1 < iVar3) goto LAB_0062b390;
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(_bignum_nist_p_224);
    if (iVar3 == 0) {
      pBStack_130 = (BIGNUM *)0x0;
      uStack_9c = 1;
      (*(code *)PTR_BN_set_word_006a7730)(r);
    }
    else if (iVar3 < 1) {
      pBVar9 = unaff_s5;
      if (a != r) {
        if (r->dmax < 7) {
          pBStack_130 = (BIGNUM *)&DAT_00000007;
          iVar3 = (*(code *)PTR_bn_expand2_006a8524)(r);
          a = unaff_s5;
          if (iVar3 == 0) goto LAB_0062b3b0;
          puVar21 = unaff_s5->d;
        }
        else {
          puVar21 = unaff_s5->d;
        }
        pBVar9 = (BIGNUM *)r->d;
        pBVar9->d = puVar21;
        pBVar9->top = unaff_s5->top;
        pBVar9->dmax = unaff_s5->dmax;
        pBVar9->neg = unaff_s5->neg;
        pBVar9->flags = unaff_s5->flags;
        pBVar9[1].d = unaff_s5[1].d;
        pBVar9[1].top = unaff_s5[1].top;
      }
      if ((int)unaff_s4 < 8) {
        puVar18 = (undefined *)0x0;
        puVar5 = &local_5c;
        bVar1 = true;
LAB_0062b4b4:
        iVar3 = 4;
        if (bVar1) {
          iVar3 = (int)puVar18 * -4 + 0x1c;
        }
        (*(code *)PTR_memset_006a99f4)(puVar5 + (int)puVar18,0,iVar3);
      }
      else {
        puVar18 = (undefined *)((int)&unaff_s4[-1].neg + 1);
        puVar5 = (uint *)(*(code *)PTR_memcpy_006a9aec)
                                   (&local_5c,&unaff_s5[1].dmax,(int)unaff_s4 * 4 + -0x1c);
        bVar1 = (int)puVar18 < 7;
        if (bVar1) goto LAB_0062b4b4;
      }
      puVar21 = pBVar9->d;
      uVar16 = pBVar9->top;
      puVar14 = (ulong *)((int)puVar21 - local_5c);
      pBVar9->d = (ulong *)((int)puVar14 - local_4c);
      pcVar15 = (code *)PTR_bn_sub_words_006a8580;
      iVar3 = -(uint)(puVar14 < (ulong *)((int)puVar14 - local_4c)) - (uint)(puVar21 < puVar14);
      uVar34 = pBVar9->neg;
      uVar22 = uVar16 + iVar3;
      uVar27 = pBVar9->flags;
      puVar17 = pBVar9[1].d;
      uVar29 = uVar22 - local_58;
      uVar19 = pBVar9[1].top;
      pBVar9->top = uVar29 - local_48;
      iVar3 = (((uint)(uVar22 < uVar16) + (iVar3 >> 0x1f)) - (uint)(uVar22 < uVar29)) -
              (uint)(uVar29 < uVar29 - local_48);
      uVar16 = pBVar9->dmax + iVar3;
      uVar29 = uVar16 - local_54;
      iVar3 = (((uint)(uVar16 < (uint)pBVar9->dmax) + (iVar3 >> 0x1f)) - (uint)(uVar16 < uVar29)) -
              (uint)(uVar29 < uVar29 - (int)local_44);
      pBVar9->dmax = uVar29 - (int)local_44;
      uVar16 = uVar34 + iVar3;
      uVar29 = local_5c + uVar16;
      uVar22 = local_4c + uVar29;
      pBVar9->neg = uVar22 - local_50;
      iVar3 = ((uint)(uVar22 < local_4c) +
              (uint)(uVar29 < local_5c) + (uint)(uVar16 < uVar34) + (iVar3 >> 0x1f)) -
              (uint)(uVar22 < uVar22 - local_50);
      uVar16 = uVar27 + iVar3;
      uVar29 = local_58 + uVar16;
      uVar34 = local_48 + uVar29;
      pBVar9->flags = uVar34 - local_4c;
      iVar3 = ((uint)(uVar34 < local_48) +
              (uint)(uVar29 < local_58) + (uint)(uVar16 < uVar27) + (iVar3 >> 0x1f)) -
              (uint)(uVar34 < uVar34 - local_4c);
      puVar21 = (ulong *)((int)puVar17 + iVar3);
      uVar16 = local_54 + (int)puVar21;
      puVar14 = (ulong *)((int)local_44 + uVar16);
      pBVar9[1].d = (ulong *)((int)puVar14 - local_48);
      iVar3 = ((uint)(puVar14 < local_44) +
              (uint)(uVar16 < local_54) + (uint)(puVar21 < puVar17) + (iVar3 >> 0x1f)) -
              (uint)(puVar14 < (ulong *)((int)puVar14 - local_48));
      uVar16 = uVar19 + iVar3;
      uVar29 = local_50 + uVar16;
      uVar16 = ((uint)(uVar29 < local_50) + (uint)(uVar16 < uVar19) + (iVar3 >> 0x1f)) -
               (uint)(uVar29 < uVar29 - (int)local_44);
      pBVar9[1].top = uVar29 - (int)local_44;
      if (((int)uVar16 < 0) || (uVar16 == 0)) {
        if (((int)uVar16 >> 0x1f | uVar16) == 0) {
          unaff_s5 = (BIGNUM *)0xffffffff;
        }
        else {
          iVar3 = (*(code *)PTR_bn_add_words_006a8584)(pBVar9,pBVar9,_nist_p_224 + ~uVar16 * 0x1c,7)
          ;
          unaff_s5 = (BIGNUM *)-iVar3;
          pcVar15 = (code *)(((uint)pcVar15 ^ (uint)PTR_bn_add_words_006a8584) & (uint)unaff_s5 ^
                            (uint)PTR_bn_add_words_006a8584);
        }
      }
      else {
        iVar3 = (*(code *)PTR_bn_sub_words_006a8580)
                          (pBVar9,pBVar9,_nist_p_224 + (uVar16 - 1) * 0x1c,7);
        unaff_s5 = (BIGNUM *)-iVar3;
      }
      unaff_s4 = &BStack_40;
      ctx = (BN_CTX *)&DAT_00000007;
      pBStack_130 = pBVar9;
      iVar3 = (*pcVar15)(unaff_s4,pBVar9,_nist_p_224);
      puVar21 = r->d;
      ppuVar6 = (ulong **)
                (((uint)pBVar9 ^ (uint)unaff_s4) & (uint)unaff_s5 & -iVar3 ^ (uint)unaff_s4);
      pBVar9->d = *ppuVar6;
      pBVar9->top = (int)ppuVar6[1];
      pBVar9->dmax = (int)ppuVar6[2];
      pBVar9->neg = (int)ppuVar6[3];
      pBVar9->flags = (int)ppuVar6[4];
      pBVar9[1].d = ppuVar6[5];
      pBVar9[1].top = (int)ppuVar6[6];
      r->top = 7;
      a = pBVar9;
      if (puVar21[6] == 0) {
        if (puVar21[5] == 0) {
          if (puVar21[4] == 0) {
            if (puVar21[3] == 0) {
              if (puVar21[2] == 0) {
                if (puVar21[1] == 0) {
                  uStack_9c = 1;
                  r->top = (uint)(*puVar21 != 0);
                }
                else {
                  uStack_9c = 1;
                  r->top = 2;
                }
              }
              else {
                uStack_9c = 1;
                r->top = 3;
              }
            }
            else {
              uStack_9c = 1;
              r->top = 4;
            }
          }
          else {
            uStack_9c = 1;
            r->top = 5;
          }
        }
        else {
          uStack_9c = 1;
          r->top = 6;
        }
      }
      else {
        uStack_9c = 1;
        r->top = 7;
      }
    }
    else if (a == r) {
      uStack_9c = 1;
    }
    else {
      pBStack_130 = a;
      iVar3 = (*(code *)PTR_BN_copy_006a8450)(r);
      uStack_9c = (uint)(iVar3 != 0);
    }
  }
  else {
LAB_0062b390:
    uStack_9c = (*(code *)PTR_BN_nnmod_006a8548)(r,a,_bignum_nist_p_224);
  }
LAB_0062b3b0:
  if (local_24 == *(BIGNUM **)puStack_98) {
    return uStack_9c;
  }
  pBStack_124 = local_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_128 = PTR___stack_chk_guard_006a9ae8;
  uStack_12c = pBStack_130->neg;
  pBStack_a4 = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pBStack_120 = unaff_s4;
  pBStack_11c = unaff_s5;
  pBStack_a0 = a;
  pBStack_94 = r;
  pBStack_90 = unaff_s4;
  pBStack_8c = unaff_s5;
  pBStack_1d8 = pBStack_130;
  if (uStack_12c == 0) {
    pBStack_11c = (BIGNUM *)pBStack_130->top;
    pBStack_120 = (BIGNUM *)pBStack_130->d;
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBStack_130,_bignum_nist_p_256_sqr_6188);
    if (-1 < iVar3) goto LAB_0062b8f8;
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(_bignum_nist_p_256);
    if (iVar3 == 0) {
      pBStack_1d8 = (BIGNUM *)0x0;
      uStack_12c = 1;
      (*(code *)PTR_BN_set_word_006a7730)(pBStack_124);
    }
    else if (iVar3 < 1) {
      pBStack_130 = pBStack_120;
      if (pBStack_130 != pBStack_124) {
        if (pBStack_124->dmax < 8) {
          pBStack_1d8 = (BIGNUM *)&DAT_00000008;
          iVar3 = (*(code *)PTR_bn_expand2_006a8524)(pBStack_124);
          if (iVar3 == 0) goto LAB_0062b918;
          puVar21 = pBStack_120->d;
        }
        else {
          puVar21 = pBStack_120->d;
        }
        pBStack_130 = (BIGNUM *)pBStack_124->d;
        pBStack_130->d = puVar21;
        pBStack_130->top = pBStack_120->top;
        pBStack_130->dmax = pBStack_120->dmax;
        pBStack_130->neg = pBStack_120->neg;
        pBStack_130->flags = pBStack_120->flags;
        pBStack_130[1].d = pBStack_120[1].d;
        pBStack_130[1].top = pBStack_120[1].top;
        pBStack_130[1].dmax = pBStack_120[1].dmax;
      }
      if ((int)pBStack_11c < 9) {
        piVar20 = (int *)0x0;
        ppuVar4 = &puStack_e4;
        bVar1 = true;
LAB_0062ba28:
        iVar3 = 4;
        if (bVar1) {
          iVar3 = (int)piVar20 * -4 + 0x20;
        }
        (*(code *)PTR_memset_006a99f4)(ppuVar4 + (int)piVar20,0,iVar3);
      }
      else {
        piVar20 = &pBStack_11c[-1].neg;
        ppuVar4 = (uint **)(*(code *)PTR_memcpy_006a9aec)
                                     (&puStack_e4,&pBStack_120[1].neg,(int)pBStack_11c * 4 + -0x20);
        bVar1 = (int)piVar20 < 8;
        if (bVar1) goto LAB_0062ba28;
      }
      pcVar15 = (code *)PTR_bn_sub_words_006a8580;
      puVar17 = pBStack_130->d;
      puVar21 = (ulong *)((int)puVar17 + (int)puStack_e4);
      puVar13 = (ulong *)((int)puVar21 + uStack_e0);
      puVar25 = (ulong *)((int)puVar13 - uStack_d8);
      puVar14 = (ulong *)((int)puVar25 - uStack_d4);
      uVar33 = pBStack_130->flags;
      puVar26 = pBStack_130[1].d;
      puVar24 = (ulong *)((int)puVar14 - uStack_d0);
      uVar32 = pBStack_130[1].top;
      uVar31 = pBStack_130[1].dmax;
      pBStack_130->d = (ulong *)((int)puVar24 - uStack_cc);
      iVar3 = (((((uint)(puVar13 < puVar21) + (uint)(puVar21 < puVar17)) - (uint)(puVar13 < puVar25)
                ) - (uint)(puVar25 < puVar14)) - (uint)(puVar14 < puVar24)) -
              (uint)(puVar24 < (ulong *)((int)puVar24 - uStack_cc));
      uVar34 = pBStack_130->top + iVar3;
      uVar16 = uStack_e0 + uVar34;
      uVar19 = uVar16 + uStack_dc;
      unaff_s6 = uVar19 - uStack_d4;
      uVar29 = unaff_s6 - uStack_d0;
      uVar27 = uVar29 - uStack_cc;
      iVar3 = (((((uint)(uVar19 < uVar16) +
                 (uint)(uVar16 < uStack_e0) +
                 (uint)(uVar34 < (uint)pBStack_130->top) + (iVar3 >> 0x1f)) -
                (uint)(uVar19 < unaff_s6)) - (uint)(unaff_s6 < uVar29)) - (uint)(uVar29 < uVar27)) -
              (uint)(uVar27 < uVar27 - (int)puStack_c8);
      pBStack_130->top = uVar27 - (int)puStack_c8;
      uVar16 = pBStack_130->dmax + iVar3;
      uVar19 = uStack_dc + uVar16;
      uVar29 = uStack_d8 + uVar19;
      uVar34 = uVar29 - uStack_d0;
      uVar27 = uVar34 - uStack_cc;
      iVar3 = ((((uint)(uVar29 < uStack_d8) +
                (uint)(uVar19 < uStack_dc) +
                (uint)(uVar16 < (uint)pBStack_130->dmax) + (iVar3 >> 0x1f)) -
               (uint)(uVar29 < uVar34)) - (uint)(uVar34 < uVar27)) -
              (uint)(uVar27 < uVar27 - (int)puStack_c8);
      pBStack_130->dmax = uVar27 - (int)puStack_c8;
      uVar27 = pBStack_130->neg + iVar3;
      uVar29 = uStack_d8 + uVar27;
      uVar22 = uStack_d8 + uVar29;
      uVar34 = uStack_d4 + uVar22;
      uVar16 = uStack_d4 + uVar34;
      uVar19 = uStack_d0 + uVar16;
      uVar28 = uVar19 - (int)puStack_c8;
      uVar30 = uVar28 - (int)puStack_e4;
      iVar3 = ((((uint)(uVar19 < uStack_d0) +
                (uint)(uVar16 < uStack_d4) +
                (uint)(uVar34 < uStack_d4) +
                (uint)(uVar22 < uStack_d8) +
                (uint)(uVar29 < uStack_d8) +
                (uint)(uVar27 < (uint)pBStack_130->neg) + (iVar3 >> 0x1f)) - (uint)(uVar19 < uVar28)
               ) - (uint)(uVar28 < uVar30)) - (uint)(uVar30 < uVar30 - uStack_e0);
      pBStack_130->neg = uVar30 - uStack_e0;
      uVar29 = uVar33 + iVar3;
      uVar19 = uStack_d4 + uVar29;
      uVar34 = uStack_d4 + uVar19;
      uVar27 = uStack_d0 + uVar34;
      uVar22 = uStack_d0 + uVar27;
      uVar16 = uStack_cc + uVar22;
      uVar28 = uVar16 - uStack_e0;
      pBStack_130->flags = uVar28 - uStack_dc;
      iVar3 = (((uint)(uVar16 < uStack_cc) +
               (uint)(uVar22 < uStack_d0) +
               (uint)(uVar27 < uStack_d0) +
               (uint)(uVar34 < uStack_d4) +
               (uint)(uVar19 < uStack_d4) + (uint)(uVar29 < uVar33) + (iVar3 >> 0x1f)) -
              (uint)(uVar16 < uVar28)) - (uint)(uVar28 < uVar28 - uStack_dc);
      puVar14 = (ulong *)((int)puVar26 + iVar3);
      uVar29 = uStack_d0 + (int)puVar14;
      uVar16 = uStack_d0 + uVar29;
      uVar34 = uStack_cc + uVar16;
      uVar19 = uStack_cc + uVar34;
      puVar21 = (ulong *)((int)puStack_c8 + uVar19);
      puVar17 = (ulong *)((int)puVar21 - uStack_dc);
      pBStack_130[1].d = (ulong *)((int)puVar17 - uStack_d8);
      iVar3 = (((uint)(puVar21 < puStack_c8) +
               (uint)(uVar19 < uStack_cc) +
               (uint)(uVar34 < uStack_cc) +
               (uint)(uVar16 < uStack_d0) +
               (uint)(uVar29 < uStack_d0) + (uint)(puVar14 < puVar26) + (iVar3 >> 0x1f)) -
              (uint)(puVar21 < puVar17)) - (uint)(puVar17 < (ulong *)((int)puVar17 - uStack_d8));
      uVar29 = uVar32 + iVar3;
      uVar34 = uStack_cc + uVar29;
      uVar19 = uStack_cc + uVar34;
      puVar14 = (ulong *)((int)puStack_c8 + uVar19);
      puVar21 = (ulong *)((int)puStack_c8 + (int)puVar14);
      uVar27 = uStack_cc + (int)puVar21;
      uVar16 = uStack_d0 + uVar27;
      uVar22 = uVar16 - (int)puStack_e4;
      pBStack_130[1].top = uVar22 - uStack_e0;
      iVar3 = (((uint)(uVar16 < uStack_d0) +
               (uint)(uVar27 < uStack_cc) +
               (uint)(puVar21 < puStack_c8) +
               (uint)(puVar14 < puStack_c8) +
               (uint)(uVar19 < uStack_cc) +
               (uint)(uVar34 < uStack_cc) + (uint)(uVar29 < uVar32) + (iVar3 >> 0x1f)) -
              (uint)(uVar16 < uVar22)) - (uint)(uVar22 < uVar22 - uStack_e0);
      uVar16 = uVar31 + iVar3;
      puVar14 = (ulong *)((int)puStack_c8 + uVar16);
      puVar21 = (ulong *)((int)puStack_c8 + (int)puVar14);
      puVar17 = (ulong *)((int)puStack_c8 + (int)puVar21);
      puVar5 = (uint *)((int)puStack_e4 + (int)puVar17);
      puVar12 = (uint *)((int)puVar5 - uStack_dc);
      puVar11 = (uint *)((int)puVar12 - uStack_d8);
      puVar10 = (uint *)((int)puVar11 - uStack_d4);
      uVar16 = (((((uint)(puVar5 < puStack_e4) +
                  (uint)(puVar17 < puStack_c8) +
                  (uint)(puVar21 < puStack_c8) +
                  (uint)(puVar14 < puStack_c8) + (uint)(uVar16 < uVar31) + (iVar3 >> 0x1f)) -
                 (uint)(puVar5 < puVar12)) - (uint)(puVar12 < puVar11)) - (uint)(puVar11 < puVar10))
               - (uint)(puVar10 < (uint *)((int)puVar10 - uStack_d0));
      pBStack_130[1].dmax = (int)(uint *)((int)puVar10 - uStack_d0);
      if (((int)uVar16 < 0) || (uVar16 == 0)) {
        if (((int)uVar16 >> 0x1f | uVar16) == 0) {
          pBStack_11c = (BIGNUM *)0xffffffff;
        }
        else {
          iVar3 = (*(code *)PTR_bn_add_words_006a8584)
                            (pBStack_130,pBStack_130,_nist_p_256 + ~uVar16 * 0x20,8);
          pBStack_11c = (BIGNUM *)-iVar3;
          pcVar15 = (code *)(((uint)pcVar15 ^ (uint)PTR_bn_add_words_006a8584) & (uint)pBStack_11c ^
                            (uint)PTR_bn_add_words_006a8584);
        }
      }
      else {
        iVar3 = (*(code *)PTR_bn_sub_words_006a8580)
                          (pBStack_130,pBStack_130,_nist_p_256 + (uVar16 - 1) * 0x20,8);
        pBStack_11c = (BIGNUM *)-iVar3;
      }
      pBStack_120 = &BStack_c4;
      ctx = (BN_CTX *)&DAT_00000008;
      pBStack_1d8 = pBStack_130;
      iVar3 = (*pcVar15)(pBStack_120,pBStack_130,_nist_p_256);
      puVar21 = pBStack_124->d;
      ppuVar6 = (ulong **)
                (((uint)pBStack_130 ^ (uint)pBStack_120) & (uint)pBStack_11c & -iVar3 ^
                (uint)pBStack_120);
      pBStack_130->d = *ppuVar6;
      pBStack_130->top = (int)ppuVar6[1];
      pBStack_130->dmax = (int)ppuVar6[2];
      pBStack_130->neg = (int)ppuVar6[3];
      pBStack_130->flags = (int)ppuVar6[4];
      pBStack_130[1].d = ppuVar6[5];
      pBStack_130[1].top = (int)ppuVar6[6];
      pBStack_130[1].dmax = (int)ppuVar6[7];
      pBStack_124->top = (int)&DAT_00000008;
      if (puVar21[7] == 0) {
        if (puVar21[6] == 0) {
          if (puVar21[5] == 0) {
            if (puVar21[4] == 0) {
              if (puVar21[3] == 0) {
                if (puVar21[2] == 0) {
                  if (puVar21[1] == 0) {
                    uStack_12c = 1;
                    pBStack_124->top = (uint)(*puVar21 != 0);
                  }
                  else {
                    uStack_12c = 1;
                    pBStack_124->top = (int)&SUB_00000002;
                  }
                }
                else {
                  uStack_12c = 1;
                  pBStack_124->top = 3;
                }
              }
              else {
                uStack_12c = 1;
                pBStack_124->top = (int)&SUB_00000004;
              }
            }
            else {
              uStack_12c = 1;
              pBStack_124->top = (int)&DAT_00000005;
            }
          }
          else {
            uStack_12c = 1;
            pBStack_124->top = (int)&DAT_00000006;
          }
        }
        else {
          uStack_12c = 1;
          pBStack_124->top = (int)&DAT_00000007;
        }
      }
      else {
        uStack_12c = 1;
        pBStack_124->top = (int)&DAT_00000008;
      }
    }
    else if (pBStack_130 == pBStack_124) {
      uStack_12c = 1;
    }
    else {
      pBStack_1d8 = pBStack_130;
      iVar3 = (*(code *)PTR_BN_copy_006a8450)(pBStack_124);
      uStack_12c = (uint)(iVar3 != 0);
    }
  }
  else {
LAB_0062b8f8:
    uStack_12c = (*(code *)PTR_BN_nnmod_006a8548)(pBStack_124,pBStack_130,_bignum_nist_p_256);
  }
LAB_0062b918:
  if (pBStack_a4 == *(BIGNUM **)puStack_128) {
    return uStack_12c;
  }
  pBStack_1dc = pBStack_a4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_1e0 = PTR___stack_chk_guard_006a9ae8;
  uStack_1d4 = pBStack_1d8->neg;
  puStack_1a8 = &_gp;
  pBStack_134 = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pBStack_1d0 = pBStack_120;
  pBStack_1cc = pBStack_11c;
  uStack_118 = unaff_s6;
  pBVar9 = pBStack_1d8;
  if (uStack_1d4 == 0) {
    pBStack_1d0 = (BIGNUM *)pBStack_1d8->top;
    pBStack_1cc = (BIGNUM *)pBStack_1d8->d;
    pBStack_19c = ctx;
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBStack_1d8,_bignum_nist_p_384_sqr_6219);
    if (-1 < iVar3) goto LAB_0062c060;
    iVar3 = (**(code **)(puStack_1a8 + -0x6e2c))(_bignum_nist_p_384);
    if (iVar3 == 0) {
      pBVar9 = (BIGNUM *)0x0;
      uStack_1d4 = 1;
      (**(code **)(puStack_1a8 + -0x76b0))(pBStack_1dc);
    }
    else if (iVar3 < 1) {
      pBStack_1d8 = pBStack_1cc;
      if (pBStack_1d8 != pBStack_1dc) {
        if (pBStack_1dc->dmax < 0xc) {
          pBVar9 = (BIGNUM *)&SUB_0000000c;
          iVar3 = (**(code **)(puStack_1a8 + -0x68bc))(pBStack_1dc);
          if (iVar3 == 0) goto LAB_0062c080;
          puVar21 = pBStack_1cc->d;
        }
        else {
          puVar21 = pBStack_1cc->d;
        }
        pBStack_1d8 = (BIGNUM *)pBStack_1dc->d;
        pBStack_1d8->d = puVar21;
        pBStack_1d8->top = pBStack_1cc->top;
        pBStack_1d8->dmax = pBStack_1cc->dmax;
        pBStack_1d8->neg = pBStack_1cc->neg;
        pBStack_1d8->flags = pBStack_1cc->flags;
        pBStack_1d8[1].d = pBStack_1cc[1].d;
        pBStack_1d8[1].top = pBStack_1cc[1].top;
        pBStack_1d8[1].dmax = pBStack_1cc[1].dmax;
        pBStack_1d8[1].neg = pBStack_1cc[1].neg;
        pBStack_1d8[1].flags = pBStack_1cc[1].flags;
        pBStack_1d8[2].d = pBStack_1cc[2].d;
        pBStack_1d8[2].top = pBStack_1cc[2].top;
      }
      if ((int)pBStack_1d0 < 0xd) {
        piVar20 = (int *)0x0;
        puVar5 = &uStack_194;
        bVar1 = true;
LAB_0062c1b8:
        iVar3 = 4;
        if (bVar1) {
          iVar3 = (int)piVar20 * -4 + 0x30;
        }
        (**(code **)(puStack_1a8 + -0x53ec))(puVar5 + (int)piVar20,0,iVar3);
      }
      else {
        piVar20 = &pBStack_1d0[-1].dmax;
        puVar5 = (uint *)(**(code **)(puStack_1a8 + -0x52f4))
                                   (&uStack_194,&pBStack_1cc[2].dmax,(int)pBStack_1d0 * 4 + -0x30);
        bVar1 = (int)piVar20 < 0xc;
        if (bVar1) goto LAB_0062c1b8;
      }
      puVar14 = (ulong *)((int)pBStack_1d8->d + uStack_194);
      puVar21 = (ulong *)((int)puVar14 + uStack_170);
      puVar17 = (ulong *)((int)puVar21 + uStack_174);
      uVar27 = pBStack_1d8->neg;
      puVar25 = pBStack_1d8[1].d;
      iVar3 = ((uint)(puVar17 < puVar21) +
              (uint)(puVar21 < puVar14) + (uint)(puVar14 < pBStack_1d8->d)) -
              (uint)(puVar17 < (ulong *)((int)puVar17 - (int)puStack_168));
      uVar22 = pBStack_1d8[1].top;
      uVar16 = pBStack_1d8->top + iVar3;
      uVar34 = pBStack_1d8[1].dmax;
      uVar29 = uVar16 + uStack_190;
      pBStack_1d8->d = (ulong *)((int)puVar17 - (int)puStack_168);
      pcVar15 = *(code **)(puStack_1a8 + -0x6860);
      puVar21 = (ulong *)((int)puStack_168 + uVar29 + uStack_16c);
      puVar14 = (ulong *)((int)puVar21 - uStack_194);
      iVar3 = (((uint)(puVar21 < puStack_168) +
               (uint)(uVar29 + uStack_16c < uVar29) +
               (uint)(uVar29 < uVar16) + (uint)(uVar16 < (uint)pBStack_1d8->top) + (iVar3 >> 0x1f))
              - (uint)(puVar21 < puVar14)) - (uint)(puVar14 < (ulong *)((int)puVar14 - uStack_174));
      pBStack_1d8->top = (int)(ulong *)((int)puVar14 - uStack_174);
      uVar16 = pBStack_1d8->dmax + iVar3;
      puVar21 = (ulong *)((int)puStack_168 + uVar16 + uStack_18c);
      puVar14 = (ulong *)((int)puVar21 - uStack_190);
      iVar3 = (((uint)(puVar21 < puStack_168) +
               (uint)(uVar16 + uStack_18c < uVar16) +
               (uint)(uVar16 < (uint)pBStack_1d8->dmax) + (iVar3 >> 0x1f)) -
              (uint)(puVar21 < puVar14)) - (uint)(puVar14 < (ulong *)((int)puVar14 - uStack_170));
      pBStack_1d8->dmax = (int)(ulong *)((int)puVar14 - uStack_170);
      uVar29 = uVar27 + iVar3;
      uVar28 = uStack_194 + uVar29 + uStack_188;
      uVar16 = uStack_174 + uVar28;
      uVar19 = uStack_170 + uVar16;
      unaff_s8 = uVar19 - uStack_18c;
      uVar31 = unaff_s8 - uStack_16c;
      pBStack_1d8->neg = uVar31 - (int)puStack_168;
      iVar3 = ((((uint)(uVar19 < uStack_170) +
                (uint)(uVar16 < uStack_174) +
                (uint)(uVar28 < uStack_194) +
                (uint)(uVar29 + uStack_188 < uVar29) + (uint)(uVar29 < uVar27) + (iVar3 >> 0x1f)) -
               (uint)(uVar19 < unaff_s8)) - (uint)(unaff_s8 < uVar31)) -
              (uint)(uVar31 < uVar31 - (int)puStack_168);
      uVar28 = pBStack_1d8->flags + iVar3;
      uVar32 = uStack_170 + uVar28;
      uVar19 = uStack_170 + uVar32;
      uVar16 = uStack_190 + uVar19 + uStack_184;
      uVar31 = uStack_194 + uVar16;
      uVar29 = uStack_174 + uVar31;
      uVar33 = uStack_16c + uVar29;
      uVar27 = uVar33 - uStack_188;
      unaff_s7 = uVar27 - (int)puStack_168;
      iVar3 = ((((uint)(uVar33 < uStack_16c) +
                (uint)(uVar29 < uStack_174) +
                (uint)(uVar31 < uStack_194) +
                (uint)(uVar16 < uStack_190) +
                (uint)(uVar19 + uStack_184 < uVar19) +
                (uint)(uVar19 < uStack_170) +
                (uint)(uVar32 < uStack_170) +
                (uint)(uVar28 < (uint)pBStack_1d8->flags) + (iVar3 >> 0x1f)) -
               (uint)(uVar33 < uVar27)) - (uint)(uVar27 < unaff_s7)) -
              (uint)(unaff_s7 < unaff_s7 - (int)puStack_168);
      pBStack_1d8->flags = unaff_s7 - (int)puStack_168;
      puVar21 = (ulong *)((int)puVar25 + iVar3);
      uVar19 = uStack_16c + (int)puVar21;
      unaff_s6 = (uint)(puVar21 < puVar25);
      uVar28 = uStack_16c + uVar19;
      uVar16 = uStack_18c + uVar28 + uStack_180;
      uVar27 = uStack_190 + uVar16;
      uVar29 = uStack_170 + uVar27;
      puVar21 = (ulong *)((int)puStack_168 + uVar29);
      pBStack_1d8[1].d = (ulong *)((int)puVar21 - uStack_184);
      iVar3 = unaff_s6 +
              (((uint)(puVar21 < puStack_168) +
               (uint)(uVar29 < uStack_170) +
               (uint)(uVar27 < uStack_190) +
               (uint)(uVar16 < uStack_18c) +
               (uint)(uVar28 + uStack_180 < uVar28) +
               (uint)(uVar28 < uStack_16c) + (uint)(uVar19 < uStack_16c) + (iVar3 >> 0x1f)) -
              (uint)(puVar21 < (ulong *)((int)puVar21 - uStack_184)));
      uVar29 = uVar22 + iVar3;
      puVar14 = (ulong *)((int)puStack_168 + uVar29);
      puVar21 = (ulong *)((int)puStack_168 + (int)puVar14);
      uVar16 = uStack_188 + (int)(ulong *)((int)puVar21 + (int)puStack_17c);
      uVar19 = uStack_18c + uVar16;
      uVar27 = uStack_16c + uVar19;
      pBStack_1d8[1].top = uVar27 - uStack_180;
      iVar3 = ((uint)(uVar27 < uStack_16c) +
              (uint)(uVar19 < uStack_18c) +
              (uint)(uVar16 < uStack_188) +
              (uint)((ulong *)((int)puVar21 + (int)puStack_17c) < puVar21) +
              (uint)(puVar21 < puStack_168) +
              (uint)(puVar14 < puStack_168) + (uint)(uVar29 < uVar22) + (iVar3 >> 0x1f)) -
              (uint)(uVar27 < uVar27 - uStack_180);
      uVar19 = uVar34 + iVar3;
      uVar29 = uStack_184 + uVar19 + uStack_178;
      uVar16 = uStack_188 + uVar29;
      puVar21 = (ulong *)((int)puStack_168 + uVar16);
      uVar27 = pBStack_1d8[1].neg;
      iVar3 = ((uint)(puVar21 < puStack_168) +
              (uint)(uVar16 < uStack_188) +
              (uint)(uVar29 < uStack_184) +
              (uint)(uVar19 + uStack_178 < uVar19) + (uint)(uVar19 < uVar34) + (iVar3 >> 0x1f)) -
              (uint)(puVar21 < (ulong *)((int)puVar21 - (int)puStack_17c));
      pBStack_1d8[1].dmax = (int)(ulong *)((int)puVar21 - (int)puStack_17c);
      uVar16 = pBStack_1d8[1].neg + iVar3;
      uVar34 = uStack_174 + uVar16;
      uVar29 = uStack_180 + uVar34;
      uVar19 = uStack_184 + uVar29;
      pBStack_1d8[1].neg = uVar19 - uStack_178;
      iVar3 = ((uint)(uVar19 < uStack_184) +
              (uint)(uVar29 < uStack_180) +
              (uint)(uVar34 < uStack_174) + (uint)(uVar16 < uVar27) + (iVar3 >> 0x1f)) -
              (uint)(uVar19 < uVar19 - uStack_178);
      uVar34 = pBStack_1d8[1].flags;
      uVar16 = pBStack_1d8[1].flags + iVar3;
      uVar29 = uStack_170 + uVar16;
      puVar21 = (ulong *)((int)puStack_17c + uVar29);
      uVar19 = uStack_180 + (int)puVar21;
      pBStack_1d8[1].flags = uVar19 - uStack_174;
      puVar17 = pBStack_1d8[2].d;
      iVar3 = ((uint)(uVar19 < uStack_180) +
              (uint)(puVar21 < puStack_17c) +
              (uint)(uVar29 < uStack_170) + (uint)(uVar16 < uVar34) + (iVar3 >> 0x1f)) -
              (uint)(uVar19 < uVar19 - uStack_174);
      puVar21 = (ulong *)((int)puVar17 + iVar3);
      uVar29 = uStack_16c + (int)puVar21;
      uVar16 = uStack_178 + uVar29;
      puVar14 = (ulong *)((int)puStack_17c + uVar16);
      pBStack_1d8[2].d = (ulong *)((int)puVar14 - uStack_170);
      iVar3 = ((uint)(puVar14 < puStack_17c) +
              (uint)(uVar16 < uStack_178) +
              (uint)(uVar29 < uStack_16c) + (uint)(puVar21 < puVar17) + (iVar3 >> 0x1f)) -
              (uint)(puVar14 < (ulong *)((int)puVar14 - uStack_170));
      uVar16 = pBStack_1d8[2].top + iVar3;
      puVar21 = (ulong *)((int)puStack_168 + uVar16);
      uVar34 = uStack_174 + (int)puVar21;
      uVar29 = uStack_178 + uVar34;
      uVar16 = ((uint)(uVar29 < uStack_178) +
               (uint)(uVar34 < uStack_174) +
               (uint)(puVar21 < puStack_168) +
               (uint)(uVar16 < (uint)pBStack_1d8[2].top) + (iVar3 >> 0x1f)) -
               (uint)(uVar29 < uVar29 - uStack_16c);
      pBStack_1d8[2].top = uVar29 - uStack_16c;
      if (((int)uVar16 < 0) || (uVar16 == 0)) {
        if (((int)uVar16 >> 0x1f | uVar16) == 0) {
          pBStack_1cc = (BIGNUM *)0xffffffff;
        }
        else {
          iVar3 = (**(code **)(puStack_1a8 + -0x685c))
                            (pBStack_1d8,pBStack_1d8,_nist_p_384 + ~uVar16 * 0x30,0xc);
          pBStack_1cc = (BIGNUM *)-iVar3;
          pcVar15 = (code *)(((uint)pcVar15 ^ *(uint *)(puStack_1a8 + -0x685c)) & (uint)pBStack_1cc
                            ^ *(uint *)(puStack_1a8 + -0x685c));
        }
      }
      else {
        iVar3 = (**(code **)(puStack_1a8 + -0x6860))
                          (pBStack_1d8,pBStack_1d8,_nist_p_384 + (uVar16 - 1) * 0x30,0xc);
        pBStack_1cc = (BIGNUM *)-iVar3;
      }
      pBStack_1d0 = aBStack_164;
      pBVar9 = pBStack_1d8;
      iVar3 = (*pcVar15)(pBStack_1d0,pBStack_1d8,_nist_p_384);
      puVar21 = pBStack_1dc->d;
      ppuVar6 = (ulong **)
                (((uint)pBStack_1d8 ^ (uint)pBStack_1d0) & (uint)pBStack_1cc & -iVar3 ^
                (uint)pBStack_1d0);
      pBStack_1d8->d = *ppuVar6;
      pBStack_1d8->top = (int)ppuVar6[1];
      pBStack_1d8->dmax = (int)ppuVar6[2];
      pBStack_1d8->neg = (int)ppuVar6[3];
      pBStack_1d8->flags = (int)ppuVar6[4];
      pBStack_1d8[1].d = ppuVar6[5];
      pBStack_1d8[1].top = (int)ppuVar6[6];
      pBStack_1d8[1].dmax = (int)ppuVar6[7];
      pBStack_1d8[1].neg = (int)ppuVar6[8];
      pBStack_1d8[1].flags = (int)ppuVar6[9];
      pBStack_1d8[2].d = ppuVar6[10];
      pBStack_1d8[2].top = (int)ppuVar6[0xb];
      pBStack_1dc->top = (int)&SUB_0000000c;
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
                            uStack_1d4 = 1;
                            pBStack_1dc->top = (uint)(*puVar21 != 0);
                          }
                          else {
                            uStack_1d4 = 1;
                            pBStack_1dc->top = (int)&SUB_00000002;
                          }
                        }
                        else {
                          uStack_1d4 = 1;
                          pBStack_1dc->top = 3;
                        }
                      }
                      else {
                        uStack_1d4 = 1;
                        pBStack_1dc->top = (int)&SUB_00000004;
                      }
                    }
                    else {
                      uStack_1d4 = 1;
                      pBStack_1dc->top = (int)&DAT_00000005;
                    }
                  }
                  else {
                    uStack_1d4 = 1;
                    pBStack_1dc->top = (int)&DAT_00000006;
                  }
                }
                else {
                  uStack_1d4 = 1;
                  pBStack_1dc->top = (int)&DAT_00000007;
                }
              }
              else {
                uStack_1d4 = 1;
                pBStack_1dc->top = (int)&DAT_00000008;
              }
            }
            else {
              uStack_1d4 = 1;
              pBStack_1dc->top = (int)&DAT_00000009;
            }
          }
          else {
            uStack_1d4 = 1;
            pBStack_1dc->top = (int)&DAT_0000000a;
          }
        }
        else {
          uStack_1d4 = 1;
          pBStack_1dc->top = (int)&DAT_0000000b;
        }
      }
      else {
        uStack_1d4 = 1;
        pBStack_1dc->top = (int)&SUB_0000000c;
      }
    }
    else if (pBStack_1d8 == pBStack_1dc) {
      uStack_1d4 = 1;
    }
    else {
      pBVar9 = pBStack_1d8;
      iVar3 = (**(code **)(puStack_1a8 + -0x6990))(pBStack_1dc);
      uStack_1d4 = (uint)(iVar3 != 0);
    }
  }
  else {
LAB_0062c060:
    uStack_1d4 = (**(code **)(puStack_1a8 + -0x6898))(pBStack_1dc,pBStack_1d8,_bignum_nist_p_384);
  }
LAB_0062c080:
  if (pBStack_134 == *(BIGNUM **)puStack_1e0) {
    return uStack_1d4;
  }
  pcStack_1bc = BN_nist_mod_521;
  pBVar8 = pBStack_134;
  (**(code **)(puStack_1a8 + -0x5330))();
  puVar18 = PTR___stack_chk_guard_006a9ae8;
  uVar16 = pBVar9->neg;
  iStack_1e4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_1c8 = unaff_s6;
  uStack_1c4 = unaff_s7;
  uStack_1c0 = unaff_s8;
  if (uVar16 == 0) {
    iVar23 = pBVar9->top;
    puVar21 = pBVar9->d;
    iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(pBVar9,_bignum_nist_p_521_sqr_6243);
    if (iVar3 < 0) {
      iVar3 = (*(code *)PTR_BN_ucmp_006a7fb4)(_bignum_nist_p_521,pBVar9);
      if (iVar3 == 0) {
        uVar16 = 1;
        (*(code *)PTR_BN_set_word_006a7730)(pBVar8,0);
        goto LAB_0062c9a0;
      }
      if (0 < iVar3) {
        if (pBVar9 == pBVar8) {
          uVar16 = 1;
        }
        else {
          iVar3 = (*(code *)PTR_BN_copy_006a8450)(pBVar8,pBVar9);
          uVar16 = (uint)(iVar3 != 0);
        }
        goto LAB_0062c9a0;
      }
      puVar14 = puVar21;
      if (pBVar9 != pBVar8) {
        if (pBVar8->dmax < 0x11) {
          iVar3 = (*(code *)PTR_bn_expand2_006a8524)(pBVar8,0x11);
          if (iVar3 == 0) goto LAB_0062c9a0;
          uVar7 = *puVar21;
        }
        else {
          uVar7 = *puVar21;
        }
        puVar14 = pBVar8->d;
        *puVar14 = uVar7;
        puVar14[1] = puVar21[1];
        puVar14[2] = puVar21[2];
        puVar14[3] = puVar21[3];
        puVar14[4] = puVar21[4];
        puVar14[5] = puVar21[5];
        puVar14[6] = puVar21[6];
        puVar14[7] = puVar21[7];
        puVar14[8] = puVar21[8];
        puVar14[9] = puVar21[9];
        puVar14[10] = puVar21[10];
        puVar14[0xb] = puVar21[0xb];
        puVar14[0xc] = puVar21[0xc];
        puVar14[0xd] = puVar21[0xd];
        puVar14[0xe] = puVar21[0xe];
        puVar14[0xf] = puVar21[0xf];
        puVar14[0x10] = puVar21[0x10];
      }
      puVar17 = puVar21 + 0x10;
      if (iVar23 < 0x11) {
        iVar23 = 0;
        bVar1 = true;
LAB_0062cb08:
        iVar3 = 4;
        if (bVar1) {
          iVar3 = iVar23 * -4 + 0x44;
        }
        (*(code *)PTR_memset_006a99f4)(auStack_228 + iVar23,0,iVar3);
      }
      else {
        puVar25 = auStack_228;
        do {
          uVar7 = *puVar17;
          puVar17 = puVar17 + 1;
          *puVar25 = uVar7;
          puVar25 = puVar25 + 1;
        } while (puVar17 != puVar21 + iVar23);
        iVar23 = iVar23 + -0x10;
        bVar1 = iVar23 < 0x11;
        if (bVar1) goto LAB_0062cb08;
      }
      puVar2 = PTR_bn_add_words_006a8584;
      uVar16 = auStack_228[1] << 0x17;
      auStack_228[1] = auStack_228[1] >> 9 | auStack_228[2] << 0x17;
      auStack_228[2] = auStack_228[2] >> 9 | auStack_228[3] << 0x17;
      uVar29 = uStack_1f0 << 0x17;
      uVar34 = uStack_1f4 << 0x17;
      auStack_228[3] = auStack_228[3] >> 9 | uStack_218 << 0x17;
      auStack_228[0] = auStack_228[0] >> 9 | uVar16;
      uStack_1f0 = uStack_1f0 >> 9 | uStack_1ec << 0x17;
      uVar16 = uStack_1e8 << 0x17;
      uStack_1e8 = uStack_1e8 >> 9;
      uStack_1ec = uStack_1ec >> 9 | uVar16;
      uStack_218 = uStack_218 >> 9 | uStack_214 << 0x17;
      uStack_1f4 = uStack_1f4 >> 9 | uVar29;
      uStack_214 = uStack_214 >> 9 | uStack_210 << 0x17;
      uStack_210 = uStack_210 >> 9 | uStack_20c << 0x17;
      uStack_20c = uStack_20c >> 9 | uStack_208 << 0x17;
      uStack_208 = uStack_208 >> 9 | uStack_204 << 0x17;
      uStack_204 = uStack_204 >> 9 | uStack_200 << 0x17;
      uStack_200 = uStack_200 >> 9 | uStack_1fc << 0x17;
      uStack_1fc = uStack_1fc >> 9 | uStack_1f8 << 0x17;
      uStack_1f8 = uStack_1f8 >> 9 | uVar34;
      puVar14[0x10] = puVar14[0x10] & 0x1ff;
      (*(code *)puVar2)(puVar14,puVar14,auStack_228,0x11);
      iVar3 = (*(code *)PTR_bn_sub_words_006a8580)(auStack_228,puVar14,_nist_p_521,0x11);
      puVar17 = (ulong *)((uint)auStack_228 ^ ((uint)puVar14 ^ (uint)auStack_228) & -iVar3);
      *puVar14 = *puVar17;
      puVar14[1] = puVar17[1];
      puVar14[2] = puVar17[2];
      puVar14[3] = puVar17[3];
      puVar14[4] = puVar17[4];
      puVar14[5] = puVar17[5];
      puVar14[6] = puVar17[6];
      puVar14[7] = puVar17[7];
      puVar14[8] = puVar17[8];
      puVar14[9] = puVar17[9];
      puVar14[10] = puVar17[10];
      puVar14[0xb] = puVar17[0xb];
      puVar14[0xc] = puVar17[0xc];
      puVar14[0xd] = puVar17[0xd];
      puVar14[0xe] = puVar17[0xe];
      puVar14[0xf] = puVar17[0xf];
      puVar21 = pBVar8->d;
      puVar14[0x10] = puVar17[0x10];
      pBVar8->top = (int)&DAT_00000011;
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
                                  uVar16 = 1;
                                  if (puVar21[2] == 0) {
                                    if (puVar21[1] != 0) goto LAB_0062cfd4;
                                    pBVar8->top = (uint)(*puVar21 != 0);
                                  }
                                  else {
                                    pBVar8->top = 3;
                                  }
                                }
                                else {
                                  uVar16 = 1;
                                  pBVar8->top = (int)&SUB_00000004;
                                }
                              }
                              else {
                                uVar16 = 1;
                                pBVar8->top = (int)&DAT_00000005;
                              }
                            }
                            else {
                              uVar16 = 1;
                              pBVar8->top = (int)&DAT_00000006;
                            }
                          }
                          else {
                            uVar16 = 1;
                            pBVar8->top = (int)&DAT_00000007;
                          }
                        }
                        else {
                          uVar16 = 1;
                          pBVar8->top = (int)&DAT_00000008;
                        }
                      }
                      else {
                        uVar16 = 1;
                        pBVar8->top = (int)&DAT_00000009;
                      }
                    }
                    else {
                      uVar16 = 1;
                      pBVar8->top = (int)&DAT_0000000a;
                    }
                  }
                  else {
                    uVar16 = 1;
                    pBVar8->top = (int)&DAT_0000000b;
                  }
                }
                else {
                  uVar16 = 1;
                  pBVar8->top = (int)&SUB_0000000c;
                }
              }
              else {
                uVar16 = 1;
                pBVar8->top = (int)&DAT_0000000d;
              }
            }
            else {
              uVar16 = 1;
              pBVar8->top = (int)&DAT_0000000e;
            }
          }
          else {
            uVar16 = 1;
            pBVar8->top = (int)&DAT_0000000f;
          }
        }
        else {
          uVar16 = 1;
          pBVar8->top = (int)&SUB_00000010;
        }
      }
      else {
        uVar16 = 1;
        pBVar8->top = (int)&DAT_00000011;
      }
      goto LAB_0062c9a0;
    }
  }
  uVar16 = (*(code *)PTR_BN_nnmod_006a8548)(pBVar8,pBVar9,_bignum_nist_p_521);
LAB_0062c9a0:
  while( true ) {
    if (iStack_1e4 == *(int *)puVar18) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0062cfd4:
    pBVar8->top = (int)&SUB_00000002;
  }
  return uVar16;
}

