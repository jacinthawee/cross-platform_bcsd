
int BN_nist_mod_192(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

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
  uint auStack_2a0 [4];
  uint uStack_290;
  uint uStack_28c;
  uint uStack_288;
  uint uStack_284;
  uint uStack_280;
  uint uStack_27c;
  uint uStack_278;
  uint uStack_274;
  uint uStack_270;
  uint uStack_26c;
  uint uStack_268;
  uint uStack_264;
  uint uStack_260;
  int iStack_25c;
  undefined *puStack_258;
  BIGNUM *pBStack_254;
  BIGNUM *pBStack_250;
  uint uStack_24c;
  BIGNUM *pBStack_248;
  BIGNUM *pBStack_244;
  uint uStack_240;
  uint uStack_23c;
  uint uStack_238;
  code *pcStack_234;
  undefined *puStack_220;
  BN_CTX *pBStack_214;
  uint uStack_20c;
  uint uStack_208;
  uint uStack_204;
  uint uStack_200;
  uint uStack_1fc;
  uint uStack_1f8;
  ulong *puStack_1f4;
  uint uStack_1f0;
  uint uStack_1ec;
  uint uStack_1e8;
  uint uStack_1e4;
  ulong *puStack_1e0;
  BIGNUM aBStack_1dc [2];
  BIGNUM *pBStack_1ac;
  BIGNUM *pBStack_1a8;
  uint uStack_1a4;
  undefined *puStack_1a0;
  BIGNUM *pBStack_19c;
  BIGNUM *pBStack_198;
  BIGNUM *pBStack_194;
  uint uStack_190;
  uint *puStack_15c;
  uint uStack_158;
  uint uStack_154;
  uint uStack_150;
  uint uStack_14c;
  uint uStack_148;
  uint uStack_144;
  ulong *puStack_140;
  BIGNUM BStack_13c;
  BIGNUM *pBStack_11c;
  BIGNUM *pBStack_118;
  uint uStack_114;
  undefined *puStack_110;
  BIGNUM *pBStack_10c;
  BIGNUM *pBStack_108;
  BIGNUM *pBStack_104;
  uint uStack_d4;
  uint uStack_d0;
  uint uStack_cc;
  uint uStack_c8;
  uint uStack_c4;
  uint uStack_c0;
  ulong *puStack_bc;
  BIGNUM BStack_b8;
  BIGNUM *pBStack_9c;
  BIGNUM *pBStack_94;
  uint uStack_90;
  undefined *puStack_8c;
  BIGNUM *pBStack_88;
  BIGNUM *pBStack_84;
  BIGNUM *pBStack_80;
  code *pcStack_7c;
  undefined *local_68;
  BN_CTX *local_5c;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  ulong *local_40;
  undefined auStack_3c [24];
  BIGNUM *local_24;
  
  puStack_8c = PTR___stack_chk_guard_006aabf0;
  uStack_90 = a->neg;
  local_68 = &_gp;
  local_24 = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  pBStack_118 = a;
  if (uStack_90 == 0) {
    unaff_s4 = (BIGNUM *)a->top;
    unaff_s5 = (BIGNUM *)a->d;
    local_5c = ctx;
    iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(a,_bignum_nist_p_192_sqr_6116);
    ctx = local_5c;
    if (-1 < iVar3) goto LAB_0062b870;
    iVar3 = (**(code **)(local_68 + -0x6868))(_bignum_nist_p_192);
    if (iVar3 == 0) {
      pBStack_118 = (BIGNUM *)0x0;
      uStack_90 = 1;
      (**(code **)(local_68 + -0x76c0))(r);
    }
    else if (iVar3 < 1) {
      pBVar9 = unaff_s5;
      if (a != r) {
        if (r->dmax < 6) {
          pBStack_118 = (BIGNUM *)&DAT_00000006;
          iVar3 = (**(code **)(local_68 + -0x6860))(r);
          a = unaff_s5;
          if (iVar3 == 0) goto LAB_0062b890;
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
      }
      if ((int)unaff_s4 < 7) {
        puVar18 = (undefined *)0x0;
        puVar5 = &local_54;
        bVar1 = true;
LAB_0062b98c:
        iVar3 = 4;
        if (bVar1) {
          iVar3 = (int)puVar18 * -4 + 0x18;
        }
        (**(code **)(local_68 + -0x53e0))(puVar5 + (int)puVar18,0,iVar3);
      }
      else {
        puVar18 = (undefined *)((int)&unaff_s4[-1].neg + 2);
        puVar5 = (uint *)(**(code **)(local_68 + -0x52ec))
                                   (&local_54,&unaff_s5[1].top,(int)unaff_s4 * 4 + -0x18);
        bVar1 = (int)puVar18 < 6;
        if (bVar1) goto LAB_0062b98c;
      }
      uVar27 = pBVar9->top;
      puVar21 = (ulong *)((int)pBVar9->d + local_54);
      uVar22 = pBVar9->dmax;
      uVar34 = pBVar9->neg;
      uVar19 = pBVar9->flags;
      uVar29 = uVar27 + (uint)((ulong *)((int)puVar21 + local_44) < puVar21) +
                        (uint)(puVar21 < pBVar9->d);
      puVar17 = pBVar9[1].d;
      pBVar9->d = (ulong *)((int)puVar21 + local_44);
      uVar16 = uVar29 + local_50;
      pBVar9->top = uVar16 + (int)local_40;
      uVar29 = uVar22 + (uint)(uVar16 + (int)local_40 < uVar16) +
                        (uint)(uVar16 < uVar29) + (uint)(uVar29 < uVar27);
      uVar27 = local_54 + uVar29;
      uVar16 = local_44 + uVar27 + local_4c;
      pBVar9->dmax = uVar16;
      uVar16 = uVar34 + (uint)(uVar16 < local_44) +
                        (uint)(uVar27 + local_4c < uVar27) +
                        (uint)(uVar27 < local_54) + (uint)(uVar29 < uVar22);
      uVar29 = local_50 + uVar16;
      puVar21 = (ulong *)((int)local_40 + uVar29 + local_48);
      pBVar9->neg = (int)puVar21;
      uVar29 = uVar19 + (uint)(puVar21 < local_40) +
                        (uint)(uVar29 + local_48 < uVar29) +
                        (uint)(uVar29 < local_50) + (uint)(uVar16 < uVar34);
      uVar16 = local_4c + uVar29;
      uVar34 = local_44 + uVar16;
      pBVar9->flags = uVar34;
      puVar21 = (ulong *)((int)puVar17 +
                         (uint)(uVar34 < local_44) +
                         (uint)(uVar16 < local_4c) + (uint)(uVar29 < uVar19));
      uVar16 = local_48 + (int)puVar21;
      puVar14 = (ulong *)((int)local_40 + uVar16);
      iVar3 = (uint)(puVar14 < local_40) + (uint)(uVar16 < local_48) + (uint)(puVar21 < puVar17);
      pBVar9[1].d = puVar14;
      if (iVar3 == 0) {
        unaff_s4 = (BIGNUM *)0xffffffff;
      }
      else {
        iVar3 = (**(code **)(local_68 + -0x683c))(pBVar9,pBVar9,_nist_p_192 + (iVar3 + -1) * 0x18,6)
        ;
        unaff_s4 = (BIGNUM *)-iVar3;
      }
      ctx = (BN_CTX *)&DAT_00000006;
      pBStack_118 = pBVar9;
      iVar3 = (**(code **)(local_68 + -0x683c))(auStack_3c,pBVar9,_nist_p_192);
      puVar21 = r->d;
      ppuVar6 = (ulong **)
                (((uint)pBVar9 ^ (uint)auStack_3c) & (uint)unaff_s4 & -iVar3 ^ (uint)auStack_3c);
      pBVar9->d = *ppuVar6;
      pBVar9->top = (int)ppuVar6[1];
      pBVar9->dmax = (int)ppuVar6[2];
      pBVar9->neg = (int)ppuVar6[3];
      pBVar9->flags = (int)ppuVar6[4];
      pBVar9[1].d = ppuVar6[5];
      r->top = 6;
      a = pBVar9;
      if (puVar21[5] == 0) {
        if (puVar21[4] == 0) {
          if (puVar21[3] == 0) {
            if (puVar21[2] == 0) {
              if (puVar21[1] == 0) {
                uStack_90 = 1;
                r->top = (uint)(*puVar21 != 0);
              }
              else {
                uStack_90 = 1;
                r->top = 2;
              }
            }
            else {
              uStack_90 = 1;
              r->top = 3;
            }
          }
          else {
            uStack_90 = 1;
            r->top = 4;
          }
        }
        else {
          uStack_90 = 1;
          r->top = 5;
        }
      }
      else {
        uStack_90 = 1;
        r->top = 6;
      }
    }
    else if (a == r) {
      uStack_90 = 1;
    }
    else {
      pBStack_118 = a;
      iVar3 = (**(code **)(local_68 + -0x6970))(r);
      uStack_90 = (uint)(iVar3 != 0);
    }
  }
  else {
LAB_0062b870:
    uStack_90 = (**(code **)(local_68 + -0x687c))(r,a,_bignum_nist_p_192);
  }
LAB_0062b890:
  if (local_24 == *(BIGNUM **)puStack_8c) {
    return uStack_90;
  }
  pcStack_7c = BN_nist_mod_224;
  pBStack_10c = local_24;
  (**(code **)(local_68 + -0x5328))();
  puStack_110 = PTR___stack_chk_guard_006aabf0;
  uStack_114 = pBStack_118->neg;
  pBStack_9c = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  pBStack_108 = unaff_s4;
  pBStack_104 = unaff_s5;
  pBStack_94 = a;
  pBStack_88 = r;
  pBStack_84 = unaff_s4;
  pBStack_80 = unaff_s5;
  pBStack_1a8 = pBStack_118;
  if (uStack_114 == 0) {
    pBStack_108 = (BIGNUM *)pBStack_118->top;
    pBStack_104 = (BIGNUM *)pBStack_118->d;
    iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(pBStack_118,_bignum_nist_p_224_sqr_6152);
    if (-1 < iVar3) goto LAB_0062bd10;
    iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(_bignum_nist_p_224);
    if (iVar3 == 0) {
      pBStack_1a8 = (BIGNUM *)0x0;
      uStack_114 = 1;
      (*(code *)PTR_BN_set_word_006a8820)(pBStack_10c);
    }
    else if (iVar3 < 1) {
      pBStack_118 = pBStack_104;
      if (pBStack_118 != pBStack_10c) {
        if (pBStack_10c->dmax < 7) {
          pBStack_1a8 = (BIGNUM *)&DAT_00000007;
          iVar3 = (*(code *)PTR_bn_expand2_006a9680)(pBStack_10c);
          if (iVar3 == 0) goto LAB_0062bd30;
          puVar21 = pBStack_104->d;
        }
        else {
          puVar21 = pBStack_104->d;
        }
        pBStack_118 = (BIGNUM *)pBStack_10c->d;
        pBStack_118->d = puVar21;
        pBStack_118->top = pBStack_104->top;
        pBStack_118->dmax = pBStack_104->dmax;
        pBStack_118->neg = pBStack_104->neg;
        pBStack_118->flags = pBStack_104->flags;
        pBStack_118[1].d = pBStack_104[1].d;
        pBStack_118[1].top = pBStack_104[1].top;
      }
      if ((int)pBStack_108 < 8) {
        puVar18 = (undefined *)0x0;
        puVar5 = &uStack_d4;
        bVar1 = true;
LAB_0062be34:
        iVar3 = 4;
        if (bVar1) {
          iVar3 = (int)puVar18 * -4 + 0x1c;
        }
        (*(code *)PTR_memset_006aab00)(puVar5 + (int)puVar18,0,iVar3);
      }
      else {
        puVar18 = (undefined *)((int)&pBStack_108[-1].neg + 1);
        puVar5 = (uint *)(*(code *)PTR_memcpy_006aabf4)
                                   (&uStack_d4,&pBStack_104[1].dmax,(int)pBStack_108 * 4 + -0x1c);
        bVar1 = (int)puVar18 < 7;
        if (bVar1) goto LAB_0062be34;
      }
      puVar21 = pBStack_118->d;
      uVar16 = pBStack_118->top;
      puVar14 = (ulong *)((int)puVar21 - uStack_d4);
      pBStack_118->d = (ulong *)((int)puVar14 - uStack_c4);
      pcVar15 = (code *)PTR_bn_sub_words_006a96a4;
      iVar3 = -(uint)(puVar14 < (ulong *)((int)puVar14 - uStack_c4)) - (uint)(puVar21 < puVar14);
      uVar34 = pBStack_118->neg;
      uVar22 = uVar16 + iVar3;
      uVar27 = pBStack_118->flags;
      puVar17 = pBStack_118[1].d;
      uVar29 = uVar22 - uStack_d0;
      uVar19 = pBStack_118[1].top;
      pBStack_118->top = uVar29 - uStack_c0;
      iVar3 = (((uint)(uVar22 < uVar16) + (iVar3 >> 0x1f)) - (uint)(uVar22 < uVar29)) -
              (uint)(uVar29 < uVar29 - uStack_c0);
      uVar16 = pBStack_118->dmax + iVar3;
      uVar29 = uVar16 - uStack_cc;
      iVar3 = (((uint)(uVar16 < (uint)pBStack_118->dmax) + (iVar3 >> 0x1f)) -
              (uint)(uVar16 < uVar29)) - (uint)(uVar29 < uVar29 - (int)puStack_bc);
      pBStack_118->dmax = uVar29 - (int)puStack_bc;
      uVar16 = uVar34 + iVar3;
      uVar29 = uStack_d4 + uVar16;
      uVar22 = uStack_c4 + uVar29;
      pBStack_118->neg = uVar22 - uStack_c8;
      iVar3 = ((uint)(uVar22 < uStack_c4) +
              (uint)(uVar29 < uStack_d4) + (uint)(uVar16 < uVar34) + (iVar3 >> 0x1f)) -
              (uint)(uVar22 < uVar22 - uStack_c8);
      uVar16 = uVar27 + iVar3;
      uVar29 = uStack_d0 + uVar16;
      uVar34 = uStack_c0 + uVar29;
      pBStack_118->flags = uVar34 - uStack_c4;
      iVar3 = ((uint)(uVar34 < uStack_c0) +
              (uint)(uVar29 < uStack_d0) + (uint)(uVar16 < uVar27) + (iVar3 >> 0x1f)) -
              (uint)(uVar34 < uVar34 - uStack_c4);
      puVar21 = (ulong *)((int)puVar17 + iVar3);
      uVar16 = uStack_cc + (int)puVar21;
      puVar14 = (ulong *)((int)puStack_bc + uVar16);
      pBStack_118[1].d = (ulong *)((int)puVar14 - uStack_c0);
      iVar3 = ((uint)(puVar14 < puStack_bc) +
              (uint)(uVar16 < uStack_cc) + (uint)(puVar21 < puVar17) + (iVar3 >> 0x1f)) -
              (uint)(puVar14 < (ulong *)((int)puVar14 - uStack_c0));
      uVar16 = uVar19 + iVar3;
      uVar29 = uStack_c8 + uVar16;
      uVar16 = ((uint)(uVar29 < uStack_c8) + (uint)(uVar16 < uVar19) + (iVar3 >> 0x1f)) -
               (uint)(uVar29 < uVar29 - (int)puStack_bc);
      pBStack_118[1].top = uVar29 - (int)puStack_bc;
      if (((int)uVar16 < 0) || (uVar16 == 0)) {
        if (((int)uVar16 >> 0x1f | uVar16) == 0) {
          pBStack_104 = (BIGNUM *)0xffffffff;
        }
        else {
          iVar3 = (*(code *)PTR_bn_add_words_006a96a8)
                            (pBStack_118,pBStack_118,_nist_p_224 + ~uVar16 * 0x1c,7);
          pBStack_104 = (BIGNUM *)-iVar3;
          pcVar15 = (code *)(((uint)pcVar15 ^ (uint)PTR_bn_add_words_006a96a8) & (uint)pBStack_104 ^
                            (uint)PTR_bn_add_words_006a96a8);
        }
      }
      else {
        iVar3 = (*(code *)PTR_bn_sub_words_006a96a4)
                          (pBStack_118,pBStack_118,_nist_p_224 + (uVar16 - 1) * 0x1c,7);
        pBStack_104 = (BIGNUM *)-iVar3;
      }
      pBStack_108 = &BStack_b8;
      ctx = (BN_CTX *)&DAT_00000007;
      pBStack_1a8 = pBStack_118;
      iVar3 = (*pcVar15)(pBStack_108,pBStack_118,_nist_p_224);
      puVar21 = pBStack_10c->d;
      ppuVar6 = (ulong **)
                (((uint)pBStack_118 ^ (uint)pBStack_108) & (uint)pBStack_104 & -iVar3 ^
                (uint)pBStack_108);
      pBStack_118->d = *ppuVar6;
      pBStack_118->top = (int)ppuVar6[1];
      pBStack_118->dmax = (int)ppuVar6[2];
      pBStack_118->neg = (int)ppuVar6[3];
      pBStack_118->flags = (int)ppuVar6[4];
      pBStack_118[1].d = ppuVar6[5];
      pBStack_118[1].top = (int)ppuVar6[6];
      pBStack_10c->top = (int)&DAT_00000007;
      if (puVar21[6] == 0) {
        if (puVar21[5] == 0) {
          if (puVar21[4] == 0) {
            if (puVar21[3] == 0) {
              if (puVar21[2] == 0) {
                if (puVar21[1] == 0) {
                  uStack_114 = 1;
                  pBStack_10c->top = (uint)(*puVar21 != 0);
                }
                else {
                  uStack_114 = 1;
                  pBStack_10c->top = (int)&SUB_00000002;
                }
              }
              else {
                uStack_114 = 1;
                pBStack_10c->top = 3;
              }
            }
            else {
              uStack_114 = 1;
              pBStack_10c->top = (int)&SUB_00000004;
            }
          }
          else {
            uStack_114 = 1;
            pBStack_10c->top = (int)&DAT_00000005;
          }
        }
        else {
          uStack_114 = 1;
          pBStack_10c->top = (int)&DAT_00000006;
        }
      }
      else {
        uStack_114 = 1;
        pBStack_10c->top = (int)&DAT_00000007;
      }
    }
    else if (pBStack_118 == pBStack_10c) {
      uStack_114 = 1;
    }
    else {
      pBStack_1a8 = pBStack_118;
      iVar3 = (*(code *)PTR_BN_copy_006a9570)(pBStack_10c);
      uStack_114 = (uint)(iVar3 != 0);
    }
  }
  else {
LAB_0062bd10:
    uStack_114 = (*(code *)PTR_BN_nnmod_006a9664)(pBStack_10c,pBStack_118,_bignum_nist_p_224);
  }
LAB_0062bd30:
  if (pBStack_9c == *(BIGNUM **)puStack_110) {
    return uStack_114;
  }
  pBStack_19c = pBStack_9c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_1a0 = PTR___stack_chk_guard_006aabf0;
  uStack_1a4 = pBStack_1a8->neg;
  pBStack_11c = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  pBStack_198 = pBStack_108;
  pBStack_194 = pBStack_104;
  pBStack_250 = pBStack_1a8;
  if (uStack_1a4 == 0) {
    pBStack_194 = (BIGNUM *)pBStack_1a8->top;
    pBStack_198 = (BIGNUM *)pBStack_1a8->d;
    iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(pBStack_1a8,_bignum_nist_p_256_sqr_6183);
    if (-1 < iVar3) goto LAB_0062c278;
    iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(_bignum_nist_p_256);
    if (iVar3 == 0) {
      pBStack_250 = (BIGNUM *)0x0;
      uStack_1a4 = 1;
      (*(code *)PTR_BN_set_word_006a8820)(pBStack_19c);
    }
    else if (iVar3 < 1) {
      pBStack_1a8 = pBStack_198;
      if (pBStack_1a8 != pBStack_19c) {
        if (pBStack_19c->dmax < 8) {
          pBStack_250 = (BIGNUM *)&DAT_00000008;
          iVar3 = (*(code *)PTR_bn_expand2_006a9680)(pBStack_19c);
          if (iVar3 == 0) goto LAB_0062c298;
          puVar21 = pBStack_198->d;
        }
        else {
          puVar21 = pBStack_198->d;
        }
        pBStack_1a8 = (BIGNUM *)pBStack_19c->d;
        pBStack_1a8->d = puVar21;
        pBStack_1a8->top = pBStack_198->top;
        pBStack_1a8->dmax = pBStack_198->dmax;
        pBStack_1a8->neg = pBStack_198->neg;
        pBStack_1a8->flags = pBStack_198->flags;
        pBStack_1a8[1].d = pBStack_198[1].d;
        pBStack_1a8[1].top = pBStack_198[1].top;
        pBStack_1a8[1].dmax = pBStack_198[1].dmax;
      }
      if ((int)pBStack_194 < 9) {
        piVar20 = (int *)0x0;
        ppuVar4 = &puStack_15c;
        bVar1 = true;
LAB_0062c3a8:
        iVar3 = 4;
        if (bVar1) {
          iVar3 = (int)piVar20 * -4 + 0x20;
        }
        (*(code *)PTR_memset_006aab00)(ppuVar4 + (int)piVar20,0,iVar3);
      }
      else {
        piVar20 = &pBStack_194[-1].neg;
        ppuVar4 = (uint **)(*(code *)PTR_memcpy_006aabf4)
                                     (&puStack_15c,&pBStack_198[1].neg,(int)pBStack_194 * 4 + -0x20)
        ;
        bVar1 = (int)piVar20 < 8;
        if (bVar1) goto LAB_0062c3a8;
      }
      pcVar15 = (code *)PTR_bn_sub_words_006a96a4;
      puVar17 = pBStack_1a8->d;
      puVar21 = (ulong *)((int)puVar17 + (int)puStack_15c);
      puVar13 = (ulong *)((int)puVar21 + uStack_158);
      puVar25 = (ulong *)((int)puVar13 - uStack_150);
      puVar14 = (ulong *)((int)puVar25 - uStack_14c);
      uVar33 = pBStack_1a8->flags;
      puVar26 = pBStack_1a8[1].d;
      puVar24 = (ulong *)((int)puVar14 - uStack_148);
      uVar32 = pBStack_1a8[1].top;
      uVar31 = pBStack_1a8[1].dmax;
      pBStack_1a8->d = (ulong *)((int)puVar24 - uStack_144);
      iVar3 = (((((uint)(puVar13 < puVar21) + (uint)(puVar21 < puVar17)) - (uint)(puVar13 < puVar25)
                ) - (uint)(puVar25 < puVar14)) - (uint)(puVar14 < puVar24)) -
              (uint)(puVar24 < (ulong *)((int)puVar24 - uStack_144));
      uVar34 = pBStack_1a8->top + iVar3;
      uVar16 = uStack_158 + uVar34;
      uVar19 = uVar16 + uStack_154;
      unaff_s6 = uVar19 - uStack_14c;
      uVar29 = unaff_s6 - uStack_148;
      uVar27 = uVar29 - uStack_144;
      iVar3 = (((((uint)(uVar19 < uVar16) +
                 (uint)(uVar16 < uStack_158) +
                 (uint)(uVar34 < (uint)pBStack_1a8->top) + (iVar3 >> 0x1f)) -
                (uint)(uVar19 < unaff_s6)) - (uint)(unaff_s6 < uVar29)) - (uint)(uVar29 < uVar27)) -
              (uint)(uVar27 < uVar27 - (int)puStack_140);
      pBStack_1a8->top = uVar27 - (int)puStack_140;
      uVar16 = pBStack_1a8->dmax + iVar3;
      uVar19 = uStack_154 + uVar16;
      uVar29 = uStack_150 + uVar19;
      uVar34 = uVar29 - uStack_148;
      uVar27 = uVar34 - uStack_144;
      iVar3 = ((((uint)(uVar29 < uStack_150) +
                (uint)(uVar19 < uStack_154) +
                (uint)(uVar16 < (uint)pBStack_1a8->dmax) + (iVar3 >> 0x1f)) -
               (uint)(uVar29 < uVar34)) - (uint)(uVar34 < uVar27)) -
              (uint)(uVar27 < uVar27 - (int)puStack_140);
      pBStack_1a8->dmax = uVar27 - (int)puStack_140;
      uVar27 = pBStack_1a8->neg + iVar3;
      uVar29 = uStack_150 + uVar27;
      uVar22 = uStack_150 + uVar29;
      uVar34 = uStack_14c + uVar22;
      uVar16 = uStack_14c + uVar34;
      uVar19 = uStack_148 + uVar16;
      uVar28 = uVar19 - (int)puStack_140;
      uVar30 = uVar28 - (int)puStack_15c;
      iVar3 = ((((uint)(uVar19 < uStack_148) +
                (uint)(uVar16 < uStack_14c) +
                (uint)(uVar34 < uStack_14c) +
                (uint)(uVar22 < uStack_150) +
                (uint)(uVar29 < uStack_150) +
                (uint)(uVar27 < (uint)pBStack_1a8->neg) + (iVar3 >> 0x1f)) - (uint)(uVar19 < uVar28)
               ) - (uint)(uVar28 < uVar30)) - (uint)(uVar30 < uVar30 - uStack_158);
      pBStack_1a8->neg = uVar30 - uStack_158;
      uVar29 = uVar33 + iVar3;
      uVar19 = uStack_14c + uVar29;
      uVar34 = uStack_14c + uVar19;
      uVar27 = uStack_148 + uVar34;
      uVar22 = uStack_148 + uVar27;
      uVar16 = uStack_144 + uVar22;
      uVar28 = uVar16 - uStack_158;
      pBStack_1a8->flags = uVar28 - uStack_154;
      iVar3 = (((uint)(uVar16 < uStack_144) +
               (uint)(uVar22 < uStack_148) +
               (uint)(uVar27 < uStack_148) +
               (uint)(uVar34 < uStack_14c) +
               (uint)(uVar19 < uStack_14c) + (uint)(uVar29 < uVar33) + (iVar3 >> 0x1f)) -
              (uint)(uVar16 < uVar28)) - (uint)(uVar28 < uVar28 - uStack_154);
      puVar14 = (ulong *)((int)puVar26 + iVar3);
      uVar29 = uStack_148 + (int)puVar14;
      uVar16 = uStack_148 + uVar29;
      uVar34 = uStack_144 + uVar16;
      uVar19 = uStack_144 + uVar34;
      puVar21 = (ulong *)((int)puStack_140 + uVar19);
      puVar17 = (ulong *)((int)puVar21 - uStack_154);
      pBStack_1a8[1].d = (ulong *)((int)puVar17 - uStack_150);
      iVar3 = (((uint)(puVar21 < puStack_140) +
               (uint)(uVar19 < uStack_144) +
               (uint)(uVar34 < uStack_144) +
               (uint)(uVar16 < uStack_148) +
               (uint)(uVar29 < uStack_148) + (uint)(puVar14 < puVar26) + (iVar3 >> 0x1f)) -
              (uint)(puVar21 < puVar17)) - (uint)(puVar17 < (ulong *)((int)puVar17 - uStack_150));
      uVar29 = uVar32 + iVar3;
      uVar34 = uStack_144 + uVar29;
      uVar19 = uStack_144 + uVar34;
      puVar14 = (ulong *)((int)puStack_140 + uVar19);
      puVar21 = (ulong *)((int)puStack_140 + (int)puVar14);
      uVar27 = uStack_144 + (int)puVar21;
      uVar16 = uStack_148 + uVar27;
      uVar22 = uVar16 - (int)puStack_15c;
      pBStack_1a8[1].top = uVar22 - uStack_158;
      iVar3 = (((uint)(uVar16 < uStack_148) +
               (uint)(uVar27 < uStack_144) +
               (uint)(puVar21 < puStack_140) +
               (uint)(puVar14 < puStack_140) +
               (uint)(uVar19 < uStack_144) +
               (uint)(uVar34 < uStack_144) + (uint)(uVar29 < uVar32) + (iVar3 >> 0x1f)) -
              (uint)(uVar16 < uVar22)) - (uint)(uVar22 < uVar22 - uStack_158);
      uVar16 = uVar31 + iVar3;
      puVar14 = (ulong *)((int)puStack_140 + uVar16);
      puVar21 = (ulong *)((int)puStack_140 + (int)puVar14);
      puVar17 = (ulong *)((int)puStack_140 + (int)puVar21);
      puVar5 = (uint *)((int)puStack_15c + (int)puVar17);
      puVar12 = (uint *)((int)puVar5 - uStack_154);
      puVar11 = (uint *)((int)puVar12 - uStack_150);
      puVar10 = (uint *)((int)puVar11 - uStack_14c);
      uVar16 = (((((uint)(puVar5 < puStack_15c) +
                  (uint)(puVar17 < puStack_140) +
                  (uint)(puVar21 < puStack_140) +
                  (uint)(puVar14 < puStack_140) + (uint)(uVar16 < uVar31) + (iVar3 >> 0x1f)) -
                 (uint)(puVar5 < puVar12)) - (uint)(puVar12 < puVar11)) - (uint)(puVar11 < puVar10))
               - (uint)(puVar10 < (uint *)((int)puVar10 - uStack_148));
      pBStack_1a8[1].dmax = (int)(uint *)((int)puVar10 - uStack_148);
      if (((int)uVar16 < 0) || (uVar16 == 0)) {
        if (((int)uVar16 >> 0x1f | uVar16) == 0) {
          pBStack_194 = (BIGNUM *)0xffffffff;
        }
        else {
          iVar3 = (*(code *)PTR_bn_add_words_006a96a8)
                            (pBStack_1a8,pBStack_1a8,_nist_p_256 + ~uVar16 * 0x20,8);
          pBStack_194 = (BIGNUM *)-iVar3;
          pcVar15 = (code *)(((uint)pcVar15 ^ (uint)PTR_bn_add_words_006a96a8) & (uint)pBStack_194 ^
                            (uint)PTR_bn_add_words_006a96a8);
        }
      }
      else {
        iVar3 = (*(code *)PTR_bn_sub_words_006a96a4)
                          (pBStack_1a8,pBStack_1a8,_nist_p_256 + (uVar16 - 1) * 0x20,8);
        pBStack_194 = (BIGNUM *)-iVar3;
      }
      pBStack_198 = &BStack_13c;
      ctx = (BN_CTX *)&DAT_00000008;
      pBStack_250 = pBStack_1a8;
      iVar3 = (*pcVar15)(pBStack_198,pBStack_1a8,_nist_p_256);
      puVar21 = pBStack_19c->d;
      ppuVar6 = (ulong **)
                (((uint)pBStack_1a8 ^ (uint)pBStack_198) & (uint)pBStack_194 & -iVar3 ^
                (uint)pBStack_198);
      pBStack_1a8->d = *ppuVar6;
      pBStack_1a8->top = (int)ppuVar6[1];
      pBStack_1a8->dmax = (int)ppuVar6[2];
      pBStack_1a8->neg = (int)ppuVar6[3];
      pBStack_1a8->flags = (int)ppuVar6[4];
      pBStack_1a8[1].d = ppuVar6[5];
      pBStack_1a8[1].top = (int)ppuVar6[6];
      pBStack_1a8[1].dmax = (int)ppuVar6[7];
      pBStack_19c->top = (int)&DAT_00000008;
      if (puVar21[7] == 0) {
        if (puVar21[6] == 0) {
          if (puVar21[5] == 0) {
            if (puVar21[4] == 0) {
              if (puVar21[3] == 0) {
                if (puVar21[2] == 0) {
                  if (puVar21[1] == 0) {
                    uStack_1a4 = 1;
                    pBStack_19c->top = (uint)(*puVar21 != 0);
                  }
                  else {
                    uStack_1a4 = 1;
                    pBStack_19c->top = (int)&SUB_00000002;
                  }
                }
                else {
                  uStack_1a4 = 1;
                  pBStack_19c->top = 3;
                }
              }
              else {
                uStack_1a4 = 1;
                pBStack_19c->top = (int)&SUB_00000004;
              }
            }
            else {
              uStack_1a4 = 1;
              pBStack_19c->top = (int)&DAT_00000005;
            }
          }
          else {
            uStack_1a4 = 1;
            pBStack_19c->top = (int)&DAT_00000006;
          }
        }
        else {
          uStack_1a4 = 1;
          pBStack_19c->top = (int)&DAT_00000007;
        }
      }
      else {
        uStack_1a4 = 1;
        pBStack_19c->top = (int)&DAT_00000008;
      }
    }
    else if (pBStack_1a8 == pBStack_19c) {
      uStack_1a4 = 1;
    }
    else {
      pBStack_250 = pBStack_1a8;
      iVar3 = (*(code *)PTR_BN_copy_006a9570)(pBStack_19c);
      uStack_1a4 = (uint)(iVar3 != 0);
    }
  }
  else {
LAB_0062c278:
    uStack_1a4 = (*(code *)PTR_BN_nnmod_006a9664)(pBStack_19c,pBStack_1a8,_bignum_nist_p_256);
  }
LAB_0062c298:
  if (pBStack_11c == *(BIGNUM **)puStack_1a0) {
    return uStack_1a4;
  }
  pBStack_254 = pBStack_11c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_258 = PTR___stack_chk_guard_006aabf0;
  uStack_24c = pBStack_250->neg;
  puStack_220 = &_gp;
  pBStack_1ac = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  pBStack_248 = pBStack_198;
  pBStack_244 = pBStack_194;
  uStack_190 = unaff_s6;
  pBVar9 = pBStack_250;
  if (uStack_24c == 0) {
    pBStack_248 = (BIGNUM *)pBStack_250->top;
    pBStack_244 = (BIGNUM *)pBStack_250->d;
    pBStack_214 = ctx;
    iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(pBStack_250,_bignum_nist_p_384_sqr_6214);
    if (-1 < iVar3) goto LAB_0062c9e0;
    iVar3 = (**(code **)(puStack_220 + -0x6868))(_bignum_nist_p_384);
    if (iVar3 == 0) {
      pBVar9 = (BIGNUM *)0x0;
      uStack_24c = 1;
      (**(code **)(puStack_220 + -0x76c0))(pBStack_254);
    }
    else if (iVar3 < 1) {
      pBStack_250 = pBStack_244;
      if (pBStack_250 != pBStack_254) {
        if (pBStack_254->dmax < 0xc) {
          pBVar9 = (BIGNUM *)&SUB_0000000c;
          iVar3 = (**(code **)(puStack_220 + -0x6860))(pBStack_254);
          if (iVar3 == 0) goto LAB_0062ca00;
          puVar21 = pBStack_244->d;
        }
        else {
          puVar21 = pBStack_244->d;
        }
        pBStack_250 = (BIGNUM *)pBStack_254->d;
        pBStack_250->d = puVar21;
        pBStack_250->top = pBStack_244->top;
        pBStack_250->dmax = pBStack_244->dmax;
        pBStack_250->neg = pBStack_244->neg;
        pBStack_250->flags = pBStack_244->flags;
        pBStack_250[1].d = pBStack_244[1].d;
        pBStack_250[1].top = pBStack_244[1].top;
        pBStack_250[1].dmax = pBStack_244[1].dmax;
        pBStack_250[1].neg = pBStack_244[1].neg;
        pBStack_250[1].flags = pBStack_244[1].flags;
        pBStack_250[2].d = pBStack_244[2].d;
        pBStack_250[2].top = pBStack_244[2].top;
      }
      if ((int)pBStack_248 < 0xd) {
        piVar20 = (int *)0x0;
        puVar5 = &uStack_20c;
        bVar1 = true;
LAB_0062cb38:
        iVar3 = 4;
        if (bVar1) {
          iVar3 = (int)piVar20 * -4 + 0x30;
        }
        (**(code **)(puStack_220 + -0x53e0))(puVar5 + (int)piVar20,0,iVar3);
      }
      else {
        piVar20 = &pBStack_248[-1].dmax;
        puVar5 = (uint *)(**(code **)(puStack_220 + -0x52ec))
                                   (&uStack_20c,&pBStack_244[2].dmax,(int)pBStack_248 * 4 + -0x30);
        bVar1 = (int)piVar20 < 0xc;
        if (bVar1) goto LAB_0062cb38;
      }
      puVar14 = (ulong *)((int)pBStack_250->d + uStack_20c);
      puVar21 = (ulong *)((int)puVar14 + uStack_1e8);
      puVar17 = (ulong *)((int)puVar21 + uStack_1ec);
      uVar27 = pBStack_250->neg;
      puVar25 = pBStack_250[1].d;
      iVar3 = ((uint)(puVar17 < puVar21) +
              (uint)(puVar21 < puVar14) + (uint)(puVar14 < pBStack_250->d)) -
              (uint)(puVar17 < (ulong *)((int)puVar17 - (int)puStack_1e0));
      uVar22 = pBStack_250[1].top;
      uVar16 = pBStack_250->top + iVar3;
      uVar34 = pBStack_250[1].dmax;
      uVar29 = uVar16 + uStack_208;
      pBStack_250->d = (ulong *)((int)puVar17 - (int)puStack_1e0);
      pcVar15 = *(code **)(puStack_220 + -0x683c);
      puVar21 = (ulong *)((int)puStack_1e0 + uVar29 + uStack_1e4);
      puVar14 = (ulong *)((int)puVar21 - uStack_20c);
      iVar3 = (((uint)(puVar21 < puStack_1e0) +
               (uint)(uVar29 + uStack_1e4 < uVar29) +
               (uint)(uVar29 < uVar16) + (uint)(uVar16 < (uint)pBStack_250->top) + (iVar3 >> 0x1f))
              - (uint)(puVar21 < puVar14)) - (uint)(puVar14 < (ulong *)((int)puVar14 - uStack_1ec));
      pBStack_250->top = (int)(ulong *)((int)puVar14 - uStack_1ec);
      uVar16 = pBStack_250->dmax + iVar3;
      puVar21 = (ulong *)((int)puStack_1e0 + uVar16 + uStack_204);
      puVar14 = (ulong *)((int)puVar21 - uStack_208);
      iVar3 = (((uint)(puVar21 < puStack_1e0) +
               (uint)(uVar16 + uStack_204 < uVar16) +
               (uint)(uVar16 < (uint)pBStack_250->dmax) + (iVar3 >> 0x1f)) -
              (uint)(puVar21 < puVar14)) - (uint)(puVar14 < (ulong *)((int)puVar14 - uStack_1e8));
      pBStack_250->dmax = (int)(ulong *)((int)puVar14 - uStack_1e8);
      uVar29 = uVar27 + iVar3;
      uVar28 = uStack_20c + uVar29 + uStack_200;
      uVar16 = uStack_1ec + uVar28;
      uVar19 = uStack_1e8 + uVar16;
      unaff_s8 = uVar19 - uStack_204;
      uVar31 = unaff_s8 - uStack_1e4;
      pBStack_250->neg = uVar31 - (int)puStack_1e0;
      iVar3 = ((((uint)(uVar19 < uStack_1e8) +
                (uint)(uVar16 < uStack_1ec) +
                (uint)(uVar28 < uStack_20c) +
                (uint)(uVar29 + uStack_200 < uVar29) + (uint)(uVar29 < uVar27) + (iVar3 >> 0x1f)) -
               (uint)(uVar19 < unaff_s8)) - (uint)(unaff_s8 < uVar31)) -
              (uint)(uVar31 < uVar31 - (int)puStack_1e0);
      uVar28 = pBStack_250->flags + iVar3;
      uVar32 = uStack_1e8 + uVar28;
      uVar19 = uStack_1e8 + uVar32;
      uVar16 = uStack_208 + uVar19 + uStack_1fc;
      uVar31 = uStack_20c + uVar16;
      uVar29 = uStack_1ec + uVar31;
      uVar33 = uStack_1e4 + uVar29;
      uVar27 = uVar33 - uStack_200;
      unaff_s7 = uVar27 - (int)puStack_1e0;
      iVar3 = ((((uint)(uVar33 < uStack_1e4) +
                (uint)(uVar29 < uStack_1ec) +
                (uint)(uVar31 < uStack_20c) +
                (uint)(uVar16 < uStack_208) +
                (uint)(uVar19 + uStack_1fc < uVar19) +
                (uint)(uVar19 < uStack_1e8) +
                (uint)(uVar32 < uStack_1e8) +
                (uint)(uVar28 < (uint)pBStack_250->flags) + (iVar3 >> 0x1f)) -
               (uint)(uVar33 < uVar27)) - (uint)(uVar27 < unaff_s7)) -
              (uint)(unaff_s7 < unaff_s7 - (int)puStack_1e0);
      pBStack_250->flags = unaff_s7 - (int)puStack_1e0;
      puVar21 = (ulong *)((int)puVar25 + iVar3);
      uVar19 = uStack_1e4 + (int)puVar21;
      unaff_s6 = (uint)(puVar21 < puVar25);
      uVar28 = uStack_1e4 + uVar19;
      uVar16 = uStack_204 + uVar28 + uStack_1f8;
      uVar27 = uStack_208 + uVar16;
      uVar29 = uStack_1e8 + uVar27;
      puVar21 = (ulong *)((int)puStack_1e0 + uVar29);
      pBStack_250[1].d = (ulong *)((int)puVar21 - uStack_1fc);
      iVar3 = unaff_s6 +
              (((uint)(puVar21 < puStack_1e0) +
               (uint)(uVar29 < uStack_1e8) +
               (uint)(uVar27 < uStack_208) +
               (uint)(uVar16 < uStack_204) +
               (uint)(uVar28 + uStack_1f8 < uVar28) +
               (uint)(uVar28 < uStack_1e4) + (uint)(uVar19 < uStack_1e4) + (iVar3 >> 0x1f)) -
              (uint)(puVar21 < (ulong *)((int)puVar21 - uStack_1fc)));
      uVar29 = uVar22 + iVar3;
      puVar14 = (ulong *)((int)puStack_1e0 + uVar29);
      puVar21 = (ulong *)((int)puStack_1e0 + (int)puVar14);
      uVar16 = uStack_200 + (int)(ulong *)((int)puVar21 + (int)puStack_1f4);
      uVar19 = uStack_204 + uVar16;
      uVar27 = uStack_1e4 + uVar19;
      pBStack_250[1].top = uVar27 - uStack_1f8;
      iVar3 = ((uint)(uVar27 < uStack_1e4) +
              (uint)(uVar19 < uStack_204) +
              (uint)(uVar16 < uStack_200) +
              (uint)((ulong *)((int)puVar21 + (int)puStack_1f4) < puVar21) +
              (uint)(puVar21 < puStack_1e0) +
              (uint)(puVar14 < puStack_1e0) + (uint)(uVar29 < uVar22) + (iVar3 >> 0x1f)) -
              (uint)(uVar27 < uVar27 - uStack_1f8);
      uVar19 = uVar34 + iVar3;
      uVar29 = uStack_1fc + uVar19 + uStack_1f0;
      uVar16 = uStack_200 + uVar29;
      puVar21 = (ulong *)((int)puStack_1e0 + uVar16);
      uVar27 = pBStack_250[1].neg;
      iVar3 = ((uint)(puVar21 < puStack_1e0) +
              (uint)(uVar16 < uStack_200) +
              (uint)(uVar29 < uStack_1fc) +
              (uint)(uVar19 + uStack_1f0 < uVar19) + (uint)(uVar19 < uVar34) + (iVar3 >> 0x1f)) -
              (uint)(puVar21 < (ulong *)((int)puVar21 - (int)puStack_1f4));
      pBStack_250[1].dmax = (int)(ulong *)((int)puVar21 - (int)puStack_1f4);
      uVar16 = pBStack_250[1].neg + iVar3;
      uVar34 = uStack_1ec + uVar16;
      uVar29 = uStack_1f8 + uVar34;
      uVar19 = uStack_1fc + uVar29;
      pBStack_250[1].neg = uVar19 - uStack_1f0;
      iVar3 = ((uint)(uVar19 < uStack_1fc) +
              (uint)(uVar29 < uStack_1f8) +
              (uint)(uVar34 < uStack_1ec) + (uint)(uVar16 < uVar27) + (iVar3 >> 0x1f)) -
              (uint)(uVar19 < uVar19 - uStack_1f0);
      uVar34 = pBStack_250[1].flags;
      uVar16 = pBStack_250[1].flags + iVar3;
      uVar29 = uStack_1e8 + uVar16;
      puVar21 = (ulong *)((int)puStack_1f4 + uVar29);
      uVar19 = uStack_1f8 + (int)puVar21;
      pBStack_250[1].flags = uVar19 - uStack_1ec;
      puVar17 = pBStack_250[2].d;
      iVar3 = ((uint)(uVar19 < uStack_1f8) +
              (uint)(puVar21 < puStack_1f4) +
              (uint)(uVar29 < uStack_1e8) + (uint)(uVar16 < uVar34) + (iVar3 >> 0x1f)) -
              (uint)(uVar19 < uVar19 - uStack_1ec);
      puVar21 = (ulong *)((int)puVar17 + iVar3);
      uVar29 = uStack_1e4 + (int)puVar21;
      uVar16 = uStack_1f0 + uVar29;
      puVar14 = (ulong *)((int)puStack_1f4 + uVar16);
      pBStack_250[2].d = (ulong *)((int)puVar14 - uStack_1e8);
      iVar3 = ((uint)(puVar14 < puStack_1f4) +
              (uint)(uVar16 < uStack_1f0) +
              (uint)(uVar29 < uStack_1e4) + (uint)(puVar21 < puVar17) + (iVar3 >> 0x1f)) -
              (uint)(puVar14 < (ulong *)((int)puVar14 - uStack_1e8));
      uVar16 = pBStack_250[2].top + iVar3;
      puVar21 = (ulong *)((int)puStack_1e0 + uVar16);
      uVar34 = uStack_1ec + (int)puVar21;
      uVar29 = uStack_1f0 + uVar34;
      uVar16 = ((uint)(uVar29 < uStack_1f0) +
               (uint)(uVar34 < uStack_1ec) +
               (uint)(puVar21 < puStack_1e0) +
               (uint)(uVar16 < (uint)pBStack_250[2].top) + (iVar3 >> 0x1f)) -
               (uint)(uVar29 < uVar29 - uStack_1e4);
      pBStack_250[2].top = uVar29 - uStack_1e4;
      if (((int)uVar16 < 0) || (uVar16 == 0)) {
        if (((int)uVar16 >> 0x1f | uVar16) == 0) {
          pBStack_244 = (BIGNUM *)0xffffffff;
        }
        else {
          iVar3 = (**(code **)(puStack_220 + -0x6838))
                            (pBStack_250,pBStack_250,_nist_p_384 + ~uVar16 * 0x30,0xc);
          pBStack_244 = (BIGNUM *)-iVar3;
          pcVar15 = (code *)(((uint)pcVar15 ^ *(uint *)(puStack_220 + -0x6838)) & (uint)pBStack_244
                            ^ *(uint *)(puStack_220 + -0x6838));
        }
      }
      else {
        iVar3 = (**(code **)(puStack_220 + -0x683c))
                          (pBStack_250,pBStack_250,_nist_p_384 + (uVar16 - 1) * 0x30,0xc);
        pBStack_244 = (BIGNUM *)-iVar3;
      }
      pBStack_248 = aBStack_1dc;
      pBVar9 = pBStack_250;
      iVar3 = (*pcVar15)(pBStack_248,pBStack_250,_nist_p_384);
      puVar21 = pBStack_254->d;
      ppuVar6 = (ulong **)
                (((uint)pBStack_250 ^ (uint)pBStack_248) & (uint)pBStack_244 & -iVar3 ^
                (uint)pBStack_248);
      pBStack_250->d = *ppuVar6;
      pBStack_250->top = (int)ppuVar6[1];
      pBStack_250->dmax = (int)ppuVar6[2];
      pBStack_250->neg = (int)ppuVar6[3];
      pBStack_250->flags = (int)ppuVar6[4];
      pBStack_250[1].d = ppuVar6[5];
      pBStack_250[1].top = (int)ppuVar6[6];
      pBStack_250[1].dmax = (int)ppuVar6[7];
      pBStack_250[1].neg = (int)ppuVar6[8];
      pBStack_250[1].flags = (int)ppuVar6[9];
      pBStack_250[2].d = ppuVar6[10];
      pBStack_250[2].top = (int)ppuVar6[0xb];
      pBStack_254->top = (int)&SUB_0000000c;
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
                            uStack_24c = 1;
                            pBStack_254->top = (uint)(*puVar21 != 0);
                          }
                          else {
                            uStack_24c = 1;
                            pBStack_254->top = (int)&SUB_00000002;
                          }
                        }
                        else {
                          uStack_24c = 1;
                          pBStack_254->top = 3;
                        }
                      }
                      else {
                        uStack_24c = 1;
                        pBStack_254->top = (int)&SUB_00000004;
                      }
                    }
                    else {
                      uStack_24c = 1;
                      pBStack_254->top = (int)&DAT_00000005;
                    }
                  }
                  else {
                    uStack_24c = 1;
                    pBStack_254->top = (int)&DAT_00000006;
                  }
                }
                else {
                  uStack_24c = 1;
                  pBStack_254->top = (int)&DAT_00000007;
                }
              }
              else {
                uStack_24c = 1;
                pBStack_254->top = (int)&DAT_00000008;
              }
            }
            else {
              uStack_24c = 1;
              pBStack_254->top = (int)&DAT_00000009;
            }
          }
          else {
            uStack_24c = 1;
            pBStack_254->top = (int)&DAT_0000000a;
          }
        }
        else {
          uStack_24c = 1;
          pBStack_254->top = (int)&DAT_0000000b;
        }
      }
      else {
        uStack_24c = 1;
        pBStack_254->top = (int)&SUB_0000000c;
      }
    }
    else if (pBStack_250 == pBStack_254) {
      uStack_24c = 1;
    }
    else {
      pBVar9 = pBStack_250;
      iVar3 = (**(code **)(puStack_220 + -0x6970))(pBStack_254);
      uStack_24c = (uint)(iVar3 != 0);
    }
  }
  else {
LAB_0062c9e0:
    uStack_24c = (**(code **)(puStack_220 + -0x687c))(pBStack_254,pBStack_250,_bignum_nist_p_384);
  }
LAB_0062ca00:
  if (pBStack_1ac == *(BIGNUM **)puStack_258) {
    return uStack_24c;
  }
  pcStack_234 = BN_nist_mod_521;
  pBVar8 = pBStack_1ac;
  (**(code **)(puStack_220 + -0x5328))();
  puVar18 = PTR___stack_chk_guard_006aabf0;
  uVar16 = pBVar9->neg;
  iStack_25c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_240 = unaff_s6;
  uStack_23c = unaff_s7;
  uStack_238 = unaff_s8;
  if (uVar16 == 0) {
    iVar23 = pBVar9->top;
    puVar21 = pBVar9->d;
    iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(pBVar9,_bignum_nist_p_521_sqr_6238);
    if (iVar3 < 0) {
      iVar3 = (*(code *)PTR_BN_ucmp_006a9678)(_bignum_nist_p_521,pBVar9);
      if (iVar3 == 0) {
        uVar16 = 1;
        (*(code *)PTR_BN_set_word_006a8820)(pBVar8,0);
        goto LAB_0062d320;
      }
      if (0 < iVar3) {
        if (pBVar9 == pBVar8) {
          uVar16 = 1;
        }
        else {
          iVar3 = (*(code *)PTR_BN_copy_006a9570)(pBVar8,pBVar9);
          uVar16 = (uint)(iVar3 != 0);
        }
        goto LAB_0062d320;
      }
      puVar14 = puVar21;
      if (pBVar9 != pBVar8) {
        if (pBVar8->dmax < 0x11) {
          iVar3 = (*(code *)PTR_bn_expand2_006a9680)(pBVar8,0x11);
          if (iVar3 == 0) goto LAB_0062d320;
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
LAB_0062d488:
        iVar3 = 4;
        if (bVar1) {
          iVar3 = iVar23 * -4 + 0x44;
        }
        (*(code *)PTR_memset_006aab00)(auStack_2a0 + iVar23,0,iVar3);
      }
      else {
        puVar25 = auStack_2a0;
        do {
          uVar7 = *puVar17;
          puVar17 = puVar17 + 1;
          *puVar25 = uVar7;
          puVar25 = puVar25 + 1;
        } while (puVar17 != puVar21 + iVar23);
        iVar23 = iVar23 + -0x10;
        bVar1 = iVar23 < 0x11;
        if (bVar1) goto LAB_0062d488;
      }
      puVar2 = PTR_bn_add_words_006a96a8;
      uVar16 = auStack_2a0[1] << 0x17;
      auStack_2a0[1] = auStack_2a0[1] >> 9 | auStack_2a0[2] << 0x17;
      auStack_2a0[2] = auStack_2a0[2] >> 9 | auStack_2a0[3] << 0x17;
      uVar29 = uStack_268 << 0x17;
      uVar34 = uStack_26c << 0x17;
      auStack_2a0[3] = auStack_2a0[3] >> 9 | uStack_290 << 0x17;
      auStack_2a0[0] = auStack_2a0[0] >> 9 | uVar16;
      uStack_268 = uStack_268 >> 9 | uStack_264 << 0x17;
      uVar16 = uStack_260 << 0x17;
      uStack_260 = uStack_260 >> 9;
      uStack_264 = uStack_264 >> 9 | uVar16;
      uStack_290 = uStack_290 >> 9 | uStack_28c << 0x17;
      uStack_26c = uStack_26c >> 9 | uVar29;
      uStack_28c = uStack_28c >> 9 | uStack_288 << 0x17;
      uStack_288 = uStack_288 >> 9 | uStack_284 << 0x17;
      uStack_284 = uStack_284 >> 9 | uStack_280 << 0x17;
      uStack_280 = uStack_280 >> 9 | uStack_27c << 0x17;
      uStack_27c = uStack_27c >> 9 | uStack_278 << 0x17;
      uStack_278 = uStack_278 >> 9 | uStack_274 << 0x17;
      uStack_274 = uStack_274 >> 9 | uStack_270 << 0x17;
      uStack_270 = uStack_270 >> 9 | uVar34;
      puVar14[0x10] = puVar14[0x10] & 0x1ff;
      (*(code *)puVar2)(puVar14,puVar14,auStack_2a0,0x11);
      iVar3 = (*(code *)PTR_bn_sub_words_006a96a4)(auStack_2a0,puVar14,_nist_p_521,0x11);
      puVar17 = (ulong *)((uint)auStack_2a0 ^ ((uint)puVar14 ^ (uint)auStack_2a0) & -iVar3);
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
                                    if (puVar21[1] != 0) goto LAB_0062d954;
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
      goto LAB_0062d320;
    }
  }
  uVar16 = (*(code *)PTR_BN_nnmod_006a9664)(pBVar8,pBVar9,_bignum_nist_p_521);
LAB_0062d320:
  while( true ) {
    if (iStack_25c == *(int *)puVar18) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0062d954:
    pBVar8->top = (int)&SUB_00000002;
  }
  return uVar16;
}

