
uint ec_wNAF_mul(int **param_1,int **param_2,BIGNUM *param_3,int **param_4,int **param_5,
                BIGNUM **param_6,BN_CTX *param_7)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  BN_CTX *pBVar4;
  undefined4 uVar5;
  uint uVar6;
  int **ppiVar7;
  BIGNUM **ppBVar8;
  int **ppiVar9;
  int **ppiVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  BIGNUM *pBVar14;
  BIGNUM *pBVar15;
  BIGNUM *pBVar16;
  undefined4 uVar17;
  int **ppiVar18;
  int *piVar19;
  uint **ppuVar20;
  int *piVar21;
  BIGNUM **unaff_s3;
  BIGNUM **ppBVar22;
  int **unaff_s5;
  int **unaff_s7;
  int **ppiVar23;
  int **local_80;
  int **local_7c;
  BIGNUM **local_78;
  BN_CTX *local_74;
  int **local_70;
  int *local_6c;
  uint **local_68;
  BN_CTX *local_64;
  int **local_60;
  uint local_5c;
  int local_58;
  int **local_50;
  EC_POINT *local_4c;
  BIGNUM **local_44;
  int local_40;
  int **local_34;
  BIGNUM **local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_7c = param_5;
  local_74 = param_7;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppBVar22 = unaff_s3;
  if (*param_1 == *param_2) {
    if (param_3 == (BIGNUM *)0x0) {
      if (param_4 == (int **)0x0) {
        uVar6 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
        goto LAB_00505ccc;
      }
    }
    else if (param_4 == (int **)0x0) {
LAB_00505d60:
      local_64 = (BN_CTX *)0x0;
      pBVar4 = local_64;
      if ((param_7 == (BN_CTX *)0x0) &&
         (local_74 = BN_CTX_new(), pBVar4 = local_74, local_74 == (BN_CTX *)0x0)) {
        uVar6 = 0;
        goto LAB_00505ccc;
      }
      local_64 = pBVar4;
      if (param_3 == (BIGNUM *)0x0) {
        local_5c = 0;
        iVar11 = 0;
        bVar1 = false;
        local_58 = 0;
        local_40 = 0;
        local_44 = (BIGNUM **)0x0;
        local_4c = (EC_POINT *)0x0;
      }
      else {
        local_4c = EC_GROUP_get0_generator((EC_GROUP *)param_1);
        if (local_4c == (EC_POINT *)0x0) {
          uVar17 = 0x71;
          uVar5 = 0x194;
LAB_005062d8:
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbb,uVar17,"ec_mult.c",uVar5);
          if (local_64 == (BN_CTX *)0x0) {
            uVar6 = 0;
            local_60 = (int **)0x0;
            goto LAB_00506058;
          }
          local_60 = (int **)0x0;
          param_6 = (BIGNUM **)0x0;
          local_68 = (uint **)0x0;
          local_6c = (int *)0x0;
          local_78 = (BIGNUM **)0x0;
          goto LAB_00505fa8;
        }
        local_58 = EC_EX_DATA_get_data(param_1[0x11],ec_pre_comp_dup,ec_pre_comp_free,
                                       ec_pre_comp_clear_free);
        if (local_58 == 0) {
          local_40 = 0;
          iVar11 = 1;
          local_44 = (BIGNUM **)0x0;
          bVar1 = true;
          local_5c = 1;
        }
        else if ((*(int *)(local_58 + 8) == 0) ||
                (iVar11 = EC_POINT_cmp((EC_GROUP *)param_1,local_4c,
                                       **(EC_POINT ***)(local_58 + 0x10),local_74), iVar11 != 0)) {
          local_58 = 0;
          iVar11 = 1;
          local_40 = 0;
          local_44 = (BIGNUM **)0x0;
          bVar1 = true;
          local_5c = 1;
        }
        else {
          local_44 = *(BIGNUM ***)(local_58 + 4);
          uVar6 = BN_num_bits(param_3);
          local_5c = *(uint *)(local_58 + 8);
          local_40 = 1 << (*(int *)(local_58 + 0xc) - 1U & 0x1f);
          if (*(int *)(local_58 + 0x14) != local_5c * local_40) {
            uVar17 = 0x44;
            uVar5 = 0x1ad;
            goto LAB_005062d8;
          }
          if (local_44 == (BIGNUM **)0x0) {
            trap(7);
          }
          bVar1 = false;
          iVar11 = 0;
          uVar6 = uVar6 / (uint)local_44 + 1;
          if (uVar6 <= local_5c) {
            local_5c = uVar6;
          }
        }
      }
      local_50 = (int **)(local_5c + (int)param_4);
      iVar12 = (int)local_50 * 4;
      unaff_s3 = (BIGNUM **)(CAST_S_table6 + 0x370);
      local_78 = (BIGNUM **)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar12,"ec_mult.c",0x1bc);
      local_68 = (uint **)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar12,"ec_mult.c",0x1bd);
      local_6c = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar12 + 4,"ec_mult.c",0x1be);
      local_60 = (int **)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar12,"ec_mult.c",0x1bf);
      if ((((local_78 == (BIGNUM **)0x0) || (local_68 == (uint **)0x0)) || (local_6c == (int *)0x0))
         || (ppiVar10 = (int **)(iVar11 + (int)param_4), local_60 == (int **)0x0)) {
        param_6 = (BIGNUM **)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbb,0x41,"ec_mult.c",0x1c3);
        if (local_64 == (BN_CTX *)0x0) goto LAB_00505fb4;
        goto LAB_00505fa8;
      }
      *local_6c = 0;
      local_70 = ppiVar10;
      if (ppiVar10 == (int **)0x0) {
        local_34 = (int **)0x0;
        ppBVar22 = (BIGNUM **)0x0;
        ppiVar7 = local_34;
      }
      else {
        ppBVar22 = (BIGNUM **)0x0;
        ppiVar7 = (int **)0x0;
        ppiVar18 = (int **)0x0;
        ppuVar20 = local_68;
        piVar19 = local_6c;
        do {
          pBVar14 = param_3;
          if (param_4 <= ppiVar18) {
            uVar6 = BN_num_bits(param_3);
            if (uVar6 < 2000) goto LAB_00506088;
            ppiVar7 = ppiVar7 + 8;
            pBVar15 = (BIGNUM *)&DAT_00000006;
            local_78[(int)ppiVar18] = (BIGNUM *)&DAT_00000006;
            piVar19[1] = 0;
          }
          else {
            uVar6 = BN_num_bits(*param_6);
            if (uVar6 < 2000) {
LAB_00506088:
              if (uVar6 < 800) {
                if (uVar6 < 300) {
                  if (uVar6 < 0x46) {
                    pBVar16 = (BIGNUM *)&SUB_00000002;
                    pBVar15 = pBVar16;
                    if (uVar6 < 0x14) {
                      pBVar16 = (BIGNUM *)0x1;
                      pBVar15 = pBVar16;
                    }
                  }
                  else {
                    pBVar16 = (BIGNUM *)&SUB_00000004;
                    pBVar15 = (BIGNUM *)0x3;
                  }
                }
                else {
                  pBVar16 = (BIGNUM *)&DAT_00000008;
                  pBVar15 = (BIGNUM *)&SUB_00000004;
                }
              }
              else {
                pBVar16 = (BIGNUM *)&SUB_00000010;
                pBVar15 = (BIGNUM *)&DAT_00000005;
              }
              ppiVar7 = (int **)((int)ppiVar7 + (int)pBVar16);
              local_78[(int)ppiVar18] = pBVar15;
              piVar19[1] = 0;
              if (param_4 > ppiVar18) {
                pBVar14 = *param_6;
              }
            }
            else {
              ppiVar7 = ppiVar7 + 8;
              pBVar15 = (BIGNUM *)&DAT_00000006;
              local_78[(int)ppiVar18] = (BIGNUM *)&DAT_00000006;
              piVar19[1] = 0;
              pBVar14 = *param_6;
            }
          }
          iVar11 = compute_wNAF(pBVar14,pBVar15,ppuVar20);
          *piVar19 = iVar11;
          if (iVar11 == 0) goto LAB_00505f94;
          ppBVar8 = (BIGNUM **)*ppuVar20;
          ppiVar18 = (int **)((int)ppiVar18 + 1);
          ppuVar20 = ppuVar20 + 1;
          piVar19 = piVar19 + 1;
          if (ppBVar22 < ppBVar8) {
            ppBVar22 = ppBVar8;
          }
          param_6 = param_6 + 1;
        } while (ppiVar10 != ppiVar18);
      }
      local_34 = ppiVar7;
      if (local_5c != 0) {
        if (local_58 != 0) {
          local_30 = (BIGNUM **)0x0;
          ppiVar7 = param_1;
          ppiVar18 = param_2;
          if (bVar1) {
            (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbb,0x44,"ec_mult.c",0x1ef);
          }
          else {
            pBVar14 = *(BIGNUM **)(local_58 + 0xc);
            local_78[(int)param_4] = pBVar14;
            ppiVar9 = (int **)compute_wNAF(param_3,pBVar14,&local_30);
            if (ppiVar9 != (int **)0x0) {
              if (ppBVar22 < local_30) {
                ppiVar23 = local_50;
                if (local_30 < (BIGNUM **)((int)local_44 * local_5c)) {
                  if (local_44 == (BIGNUM **)0x0) {
                    trap(7);
                  }
                  uVar6 = (uint)((undefined1 *)((int)local_30 + -1) + (int)local_44) /
                          (uint)local_44;
                  ppiVar23 = (int **)((int)param_4 + uVar6);
                  if (*(uint *)(local_58 + 8) < uVar6) {
                    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbb,0x44,"ec_mult.c",0x217);
                    goto LAB_00505f94;
                  }
                }
                local_50 = ppiVar23;
                piVar19 = *(int **)(local_58 + 0x10);
                if (param_4 < local_50) {
                  ppuVar20 = local_68 + (int)param_4;
                  piVar21 = local_6c + (int)param_4;
                  ppiVar7 = ppiVar9;
                  ppiVar18 = local_60 + (int)param_4;
                  ppiVar23 = param_4;
                  do {
                    if (ppiVar23 < (int **)((int)local_50 + -1)) {
                      *ppuVar20 = (uint *)local_44;
                      if (local_30 < local_44) {
                        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbb,0x44,"ec_mult.c",0x228);
                        param_4 = ppiVar23;
                        goto LAB_00505f94;
                      }
                      ppBVar8 = (BIGNUM **)*ppuVar20;
                      local_30 = (BIGNUM **)((int)local_30 - (int)local_44);
                    }
                    else {
                      *ppuVar20 = (uint *)local_30;
                      ppBVar8 = local_30;
                    }
                    puVar2 = PTR_CRYPTO_malloc_006a8108;
                    piVar21[1] = 0;
                    ppiVar23 = (int **)((int)ppiVar23 + 1);
                    iVar11 = (*(code *)puVar2)(ppBVar8,"ec_mult.c",0x233);
                    *piVar21 = iVar11;
                    if (iVar11 == 0) {
                      uVar17 = 0x41;
                      uVar5 = 0x236;
LAB_005066dc:
                      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbb,uVar17,"ec_mult.c",uVar5);
                      (*(code *)PTR_CRYPTO_free_006a7f88)(ppiVar9);
                      param_4 = ppiVar23;
                      goto LAB_00505f94;
                    }
                    (*(code *)PTR_memcpy_006aabf4)(iVar11,ppiVar7,*ppuVar20);
                    if (ppBVar22 < *ppuVar20) {
                      ppBVar22 = (BIGNUM **)*ppuVar20;
                    }
                    if (*piVar19 == 0) {
                      uVar17 = 0x44;
                      uVar5 = 0x240;
                      goto LAB_005066dc;
                    }
                    ppiVar7 = (int **)((int)ppiVar7 + (int)local_44);
                    *ppiVar18 = piVar19;
                    ppuVar20 = ppuVar20 + 1;
                    piVar19 = piVar19 + local_40;
                    piVar21 = piVar21 + 1;
                    ppiVar18 = ppiVar18 + 1;
                  } while (ppiVar23 < local_50);
                }
                (*(code *)PTR_CRYPTO_free_006a7f88)(ppiVar9);
              }
              else {
                local_6c[(int)param_4] = (int)ppiVar9;
                (local_6c + (int)param_4)[1] = 0;
                local_50 = (int **)((int)param_4 + 1);
                local_68[(int)param_4] = (uint *)local_30;
                local_60[(int)param_4] = *(int **)(local_58 + 0x10);
                if (ppBVar22 < local_30) {
                  ppBVar22 = local_30;
                }
              }
              goto LAB_00506390;
            }
          }
LAB_00505f94:
          param_6 = (BIGNUM **)0x0;
          unaff_s3 = ppBVar22;
          param_1 = ppiVar7;
          param_2 = ppiVar18;
          goto LAB_00505f98;
        }
        if (!bVar1) {
          param_6 = (BIGNUM **)0x0;
          (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbb,0x44,"ec_mult.c",0x1e3);
          unaff_s3 = ppBVar22;
          goto LAB_00505f98;
        }
      }
LAB_00506390:
      param_6 = (BIGNUM **)
                (*(code *)PTR_CRYPTO_malloc_006a8108)
                          ((int)((int)local_34 + 1) * 4,"ec_mult.c",0x250);
      if (param_6 == (BIGNUM **)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbb,0x41,"ec_mult.c",0x253);
        unaff_s3 = ppBVar22;
        goto LAB_00505f98;
      }
      param_6[(int)local_34] = (BIGNUM *)0x0;
      ppBVar8 = param_6;
      if (ppiVar10 != (int **)0x0) {
        ppiVar7 = (int **)0x0;
        unaff_s3 = local_78;
        do {
          pBVar14 = *unaff_s3;
          local_60[(int)ppiVar7] = (int *)ppBVar8;
          if (1 << ((uint)((int)&pBVar14[-1].flags + 3U) & 0x1f) != 0) {
            uVar6 = 0;
            do {
              pBVar14 = (BIGNUM *)EC_POINT_new((EC_GROUP *)param_1);
              *ppBVar8 = pBVar14;
              if (pBVar14 == (BIGNUM *)0x0) goto LAB_00505f98;
              uVar6 = uVar6 + 1;
              ppBVar8 = ppBVar8 + 1;
            } while (uVar6 < (uint)(1 << ((uint)((int)&(*unaff_s3)[-1].flags + 3U) & 0x1f)));
          }
          ppiVar7 = (int **)((int)ppiVar7 + 1);
          unaff_s3 = unaff_s3 + 1;
        } while (ppiVar7 != ppiVar10);
      }
      if (param_6 + (int)local_34 == ppBVar8) goto LAB_00506780;
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbb,0x44,"ec_mult.c",0x266);
      unaff_s3 = ppBVar22;
      goto LAB_00505f98;
    }
    ppiVar10 = (int **)*param_5;
    if (*ppiVar10 == *param_1) {
      ppiVar7 = (int **)0x0;
      do {
        param_5 = param_5 + 1;
        ppiVar7 = (int **)((int)ppiVar7 + 1);
        if (param_4 == ppiVar7) goto LAB_00505d60;
      } while (*ppiVar10 == (int *)**param_5);
    }
    uVar5 = 0x183;
  }
  else {
    uVar5 = 0x176;
    param_1 = unaff_s5;
    param_2 = unaff_s7;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xbb,0x65,"ec_mult.c",uVar5);
  uVar6 = 0;
LAB_00505ccc:
  do {
    if (local_2c == *(int *)puVar3) {
      return uVar6;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00506780:
    ppiVar10 = (int **)EC_POINT_new((EC_GROUP *)param_1);
    unaff_s3 = ppBVar22;
    if (ppiVar10 == (int **)0x0) {
LAB_00505f98:
      if (local_64 == (BN_CTX *)0x0) {
        uVar6 = 0;
        goto LAB_005061a0;
      }
LAB_00505fa8:
      BN_CTX_free(local_64);
LAB_00505fb4:
      uVar6 = 0;
      if (local_78 != (BIGNUM **)0x0) goto LAB_005061a0;
    }
    else {
      ppiVar7 = param_4;
      if (local_70 != (int **)0x0) {
        local_80 = (int **)0x0;
        ppiVar18 = local_60;
        ppBVar8 = local_78;
        do {
          if (local_80 < param_4) {
            iVar11 = EC_POINT_copy((EC_POINT *)**ppiVar18,(EC_POINT *)*local_7c);
          }
          else {
            iVar11 = EC_POINT_copy((EC_POINT *)**ppiVar18,local_4c);
          }
          unaff_s3 = param_6;
          if (iVar11 == 0) goto LAB_00506174;
          if ((BIGNUM *)0x1 < *ppBVar8) {
            iVar11 = EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)ppiVar10,(EC_POINT *)**ppiVar18,
                                  local_74);
            if (iVar11 == 0) goto LAB_00506174;
            iVar11 = 0;
            if (1 < (uint)(1 << ((uint)((int)&(*ppBVar8)[-1].flags + 3U) & 0x1f))) {
              uVar6 = 1;
              do {
                iVar12 = EC_POINT_add((EC_GROUP *)param_1,(EC_POINT *)(*ppiVar18)[uVar6],
                                      *(EC_POINT **)((int)*ppiVar18 + iVar11),(EC_POINT *)ppiVar10,
                                      local_74);
                if (iVar12 == 0) goto LAB_00506174;
                uVar6 = uVar6 + 1;
                iVar11 = iVar11 + 4;
              } while (uVar6 < (uint)(1 << ((uint)((int)&(*ppBVar8)[-1].flags + 3U) & 0x1f)));
            }
          }
          ppBVar8 = ppBVar8 + 1;
          local_7c = local_7c + 1;
          local_80 = (int **)((int)local_80 + 1);
          ppiVar18 = ppiVar18 + 1;
        } while (local_80 != local_70);
      }
      iVar11 = EC_POINTs_make_affine
                         ((EC_GROUP *)param_1,(size_t)local_34,(EC_POINT **)param_6,local_74);
      unaff_s3 = ppBVar22;
      if (iVar11 == 0) {
LAB_00506174:
        uVar6 = 0;
        param_4 = ppiVar7;
      }
      else {
        local_70 = (int **)0x0;
        param_4 = (int **)0x1;
        while (unaff_s3 = (BIGNUM **)((int)unaff_s3 + -1), local_7c = ppiVar10, -1 < (int)unaff_s3)
        {
          if ((param_4 == (int **)0x0) &&
             (iVar11 = EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_2,
                                    local_74), ppiVar7 = param_4, iVar11 == 0)) goto LAB_00506174;
          ppiVar18 = (int **)0x0;
          piVar19 = local_6c;
          ppuVar20 = local_68;
          ppiVar7 = local_60;
          if (local_50 != (int **)0x0) {
            do {
              if ((unaff_s3 < *ppuVar20) &&
                 (uVar6 = (uint)*(char *)(*piVar19 + (int)unaff_s3), uVar6 != 0)) {
                uVar13 = uVar6;
                if ((int)uVar6 < 0) {
                  uVar13 = -uVar6;
                }
                if ((int **)(uVar6 >> 0x1f) != local_70) {
                  if ((param_4 == (int **)0x0) &&
                     (iVar11 = EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,local_74),
                     iVar11 == 0)) goto LAB_00506174;
                  local_70 = (int **)((uint)local_70 ^ 1);
                }
                if (param_4 == (int **)0x0) {
                  iVar11 = EC_POINT_add((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_2,
                                        (EC_POINT *)(*ppiVar7)[(int)uVar13 >> 1],local_74);
                  if (iVar11 == 0) goto LAB_00506174;
                }
                else {
                  iVar11 = EC_POINT_copy((EC_POINT *)param_2,
                                         (EC_POINT *)(*ppiVar7)[(int)uVar13 >> 1]);
                  if (iVar11 == 0) goto LAB_00506174;
                  param_4 = (int **)0x0;
                }
              }
              ppiVar18 = (int **)((int)ppiVar18 + 1);
              piVar19 = piVar19 + 1;
              ppuVar20 = ppuVar20 + 1;
              ppiVar7 = ppiVar7 + 1;
            } while (local_50 != ppiVar18);
          }
        }
        if (param_4 == (int **)0x0) {
          if (local_70 == (int **)0x0) {
            uVar6 = 1;
          }
          else {
            iVar11 = EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,local_74);
            uVar6 = (uint)(iVar11 != 0);
          }
        }
        else {
          iVar11 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
          uVar6 = (uint)(iVar11 != 0);
        }
      }
      if (local_64 != (BN_CTX *)0x0) {
        BN_CTX_free(local_64);
      }
      EC_POINT_free((EC_POINT *)ppiVar10);
LAB_005061a0:
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_78);
    }
    if (local_68 != (uint **)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_68);
    }
    if (local_6c != (int *)0x0) {
      iVar11 = *local_6c;
      piVar19 = local_6c;
      while (iVar11 != 0) {
        piVar19 = piVar19 + 1;
        (*(code *)PTR_CRYPTO_free_006a7f88)();
        iVar11 = *piVar19;
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_6c);
    }
    if (param_6 != (BIGNUM **)0x0) {
      pBVar14 = *param_6;
      ppBVar22 = param_6;
      while (pBVar14 != (BIGNUM *)0x0) {
        ppBVar22 = ppBVar22 + 1;
        EC_POINT_clear_free((EC_POINT *)pBVar14);
        pBVar14 = *ppBVar22;
      }
      (*(code *)PTR_CRYPTO_free_006a7f88)(param_6);
    }
LAB_00506058:
    ppBVar22 = unaff_s3;
    if (local_60 != (int **)0x0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_60);
    }
  } while( true );
}

