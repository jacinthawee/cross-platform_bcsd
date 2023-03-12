
BIGNUM * ec_wNAF_mul(ulong **param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BIGNUM *param_5
                    ,BIGNUM *param_6,BN_CTX *param_7)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  BN_CTX *pBVar4;
  undefined4 uVar5;
  BIGNUM *pBVar6;
  ulong **ppuVar7;
  ulong *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  BIGNUM *pBVar12;
  ulong *puVar13;
  BIGNUM *pBVar14;
  undefined4 uVar15;
  uint uVar16;
  BIGNUM *pBVar17;
  BIGNUM *unaff_s1;
  BIGNUM *pBVar18;
  BIGNUM *unaff_s2;
  BIGNUM *unaff_s3;
  BIGNUM *pBVar19;
  ulong **unaff_s5;
  ulong **ppuVar20;
  BIGNUM *unaff_s6;
  BIGNUM *unaff_s7;
  BIGNUM *local_80;
  BIGNUM *local_7c;
  BIGNUM *local_78;
  BN_CTX *local_74;
  BIGNUM *local_70;
  BIGNUM *local_6c;
  BIGNUM *local_68;
  BIGNUM *local_64;
  BN_CTX *local_60;
  uint local_5c;
  int local_58;
  BIGNUM *local_50;
  EC_POINT *local_4c;
  BIGNUM *local_44;
  int local_40;
  ulong **local_34;
  BIGNUM *local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_7c = param_5;
  local_74 = param_7;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_80 = param_3;
  if (*param_1 == param_2->d) {
    if (param_3 == (BIGNUM *)0x0) {
      if (param_4 == (BIGNUM *)0x0) {
        pBVar6 = (BIGNUM *)EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
        goto LAB_0050396c;
      }
    }
    else if (param_4 == (BIGNUM *)0x0) {
LAB_00503a00:
      local_60 = (BN_CTX *)0x0;
      pBVar4 = local_60;
      if ((param_7 == (BN_CTX *)0x0) &&
         (local_74 = BN_CTX_new(), pBVar4 = local_74, local_74 == (BN_CTX *)0x0)) {
        pBVar6 = (BIGNUM *)0x0;
        unaff_s1 = pBVar6;
        goto LAB_0050396c;
      }
      local_60 = pBVar4;
      if (param_3 == (BIGNUM *)0x0) {
        local_5c = 0;
        iVar10 = 0;
        bVar1 = false;
        local_58 = 0;
        local_40 = 0;
        local_44 = (BIGNUM *)0x0;
        local_4c = (EC_POINT *)0x0;
LAB_00503a84:
        local_50 = (BIGNUM *)((int)&param_4->d + local_5c);
        iVar9 = (int)local_50 * 4;
        unaff_s3 = (BIGNUM *)(CAST_S_table3 + 0x110);
        unaff_s1 = (BIGNUM *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar9,"ec_mult.c",0x1ad);
        local_68 = (BIGNUM *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar9,"ec_mult.c",0x1ae);
        local_6c = (BIGNUM *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar9 + 4,"ec_mult.c",0x1af);
        pBVar6 = (BIGNUM *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar9,"ec_mult.c",0x1b1);
        if (local_6c != (BIGNUM *)0x0) {
          local_6c->d = (ulong *)0x0;
        }
        unaff_s2 = local_6c;
        local_78 = unaff_s1;
        local_64 = pBVar6;
        if ((((unaff_s1 == (BIGNUM *)0x0) || (local_68 == (BIGNUM *)0x0)) ||
            (local_6c == (BIGNUM *)0x0)) ||
           (pBVar18 = (BIGNUM *)((int)&param_4->d + iVar10), pBVar6 == (BIGNUM *)0x0)) {
          param_6 = (BIGNUM *)0x0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbb,0x41,"ec_mult.c",0x1b8);
          if (local_60 == (BN_CTX *)0x0) goto LAB_00503c94;
        }
        else {
          local_70 = pBVar18;
          if (pBVar18 == (BIGNUM *)0x0) {
            local_34 = (ulong **)0x0;
            pBVar19 = (BIGNUM *)0x0;
            ppuVar20 = local_34;
          }
          else {
            pBVar19 = (BIGNUM *)0x0;
            ppuVar20 = (ulong **)0x0;
            pBVar17 = (BIGNUM *)0x0;
            unaff_s2 = local_68;
            unaff_s6 = local_6c;
            do {
              pBVar12 = param_3;
              if (param_4 <= pBVar17) {
                uVar16 = BN_num_bits(param_3);
                if (uVar16 < 2000) goto LAB_00503b90;
                ppuVar20 = ppuVar20 + 8;
                puVar13 = (ulong *)&DAT_00000006;
                (&unaff_s1->d)[(int)pBVar17] = (ulong *)&DAT_00000006;
                unaff_s6->top = 0;
              }
              else {
                uVar16 = BN_num_bits((BIGNUM *)param_6->d);
                if (uVar16 < 2000) {
LAB_00503b90:
                  puVar13 = (ulong *)&DAT_00000005;
                  if (uVar16 < 800) {
                    puVar13 = (ulong *)&SUB_00000004;
                    if (uVar16 < 300) {
                      puVar13 = (ulong *)0x3;
                      if (uVar16 < 0x46) {
                        puVar13 = (ulong *)&SUB_00000002;
                        puVar8 = puVar13;
                        if (uVar16 < 0x14) {
                          puVar13 = (ulong *)0x1;
                          puVar8 = puVar13;
                        }
                      }
                      else {
                        puVar8 = (ulong *)&SUB_00000004;
                      }
                    }
                    else {
                      puVar8 = (ulong *)&DAT_00000008;
                    }
                  }
                  else {
                    puVar8 = (ulong *)&SUB_00000010;
                  }
                  ppuVar20 = (ulong **)((int)ppuVar20 + (int)puVar8);
                  (&unaff_s1->d)[(int)pBVar17] = puVar13;
                  unaff_s6->top = 0;
                  if (param_4 <= pBVar17) goto LAB_00503bec;
                }
                else {
                  ppuVar20 = ppuVar20 + 8;
                  puVar13 = (ulong *)&DAT_00000006;
                  (&unaff_s1->d)[(int)pBVar17] = (ulong *)&DAT_00000006;
                  unaff_s6->top = 0;
                }
                pBVar12 = (BIGNUM *)param_6->d;
              }
LAB_00503bec:
              puVar13 = (ulong *)compute_wNAF(pBVar12,puVar13,unaff_s2);
              unaff_s6->d = puVar13;
              if (puVar13 == (ulong *)0x0) goto LAB_00503c74;
              ppuVar7 = &unaff_s2->d;
              pBVar17 = (BIGNUM *)((int)&pBVar17->d + 1);
              unaff_s2 = (BIGNUM *)&unaff_s2->top;
              unaff_s6 = (BIGNUM *)&unaff_s6->top;
              if (pBVar19 < (BIGNUM *)*ppuVar7) {
                pBVar19 = (BIGNUM *)*ppuVar7;
              }
              param_6 = (BIGNUM *)&param_6->top;
            } while (pBVar17 != pBVar18);
          }
          local_34 = ppuVar20;
          if (local_5c == 0) {
LAB_00504068:
            param_6 = (BIGNUM *)
                      (*(code *)PTR_CRYPTO_malloc_006a7008)((int)local_34 * 4 + 4,"ec_mult.c",0x243)
            ;
            if (param_6 == (BIGNUM *)0x0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbb,0x41,"ec_mult.c",0x245);
              unaff_s3 = pBVar19;
            }
            else {
              local_80 = (BIGNUM *)(&param_6->d + (int)local_34);
              local_80->d = (ulong *)0x0;
              unaff_s2 = param_6;
              if (pBVar18 != (BIGNUM *)0x0) {
                pBVar17 = (BIGNUM *)0x0;
                unaff_s3 = unaff_s1;
                unaff_s6 = unaff_s1;
                do {
                  puVar13 = unaff_s3->d;
                  (&pBVar6->d)[(int)pBVar17] = (ulong *)unaff_s2;
                  if (1 << ((int)puVar13 - 1U & 0x1f) != 0) {
                    unaff_s6 = (BIGNUM *)0x0;
                    do {
                      puVar13 = (ulong *)EC_POINT_new((EC_GROUP *)param_1);
                      unaff_s2->d = puVar13;
                      if (puVar13 == (ulong *)0x0) goto LAB_00503c78;
                      unaff_s6 = (BIGNUM *)((int)&unaff_s6->d + 1);
                      unaff_s2 = (BIGNUM *)&unaff_s2->top;
                    } while (unaff_s6 < (BIGNUM *)(1 << ((int)unaff_s3->d - 1U & 0x1f)));
                  }
                  pBVar17 = (BIGNUM *)((int)&pBVar17->d + 1);
                  unaff_s3 = (BIGNUM *)&unaff_s3->top;
                } while (pBVar17 != pBVar18);
              }
              if (local_80 == unaff_s2) {
                unaff_s2 = (BIGNUM *)EC_POINT_new((EC_GROUP *)param_1);
                unaff_s3 = pBVar19;
                if (unaff_s2 != (BIGNUM *)0x0) {
                  unaff_s6 = pBVar6;
                  if (pBVar18 == (BIGNUM *)0x0) goto LAB_00503e28;
                  local_80 = (BIGNUM *)0x0;
                  goto LAB_0050448c;
                }
              }
              else {
                (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbb,0x44,"ec_mult.c",0x256);
                unaff_s3 = pBVar19;
              }
            }
          }
          else if (local_58 == 0) {
            if (bVar1) goto LAB_00504068;
            param_6 = (BIGNUM *)0x0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbb,0x44,"ec_mult.c",0x1d6);
            unaff_s3 = pBVar19;
          }
          else {
            local_30 = (BIGNUM *)0x0;
            ppuVar20 = param_1;
            pBVar17 = param_2;
            if (bVar1) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbb,0x44,"ec_mult.c",0x1df);
            }
            else {
              puVar13 = *(ulong **)(local_58 + 0xc);
              (&unaff_s1->d)[(int)param_4] = puVar13;
              ppuVar7 = (ulong **)compute_wNAF(param_3,puVar13,&local_30);
              if (ppuVar7 != (ulong **)0x0) {
                if (local_30 <= pBVar19) {
                  (&local_6c->d)[(int)param_4] = (ulong *)ppuVar7;
                  (&local_6c->d + (int)param_4)[1] = (ulong *)0x0;
                  local_50 = (BIGNUM *)((int)&param_4->d + 1);
                  (&local_68->d)[(int)param_4] = (ulong *)local_30;
                  (&pBVar6->d)[(int)param_4] = *(ulong **)(local_58 + 0x10);
                  if (pBVar19 < local_30) {
                    pBVar19 = local_30;
                  }
                  goto LAB_00504068;
                }
                pBVar12 = local_50;
                if (local_30 < (BIGNUM *)((int)local_44 * local_5c)) {
                  if (local_44 == (BIGNUM *)0x0) {
                    trap(7);
                  }
                  uVar16 = (uint)((undefined *)((int)&local_30[-1].flags + 3) + (int)local_44) /
                           (uint)local_44;
                  pBVar12 = (BIGNUM *)((int)&param_4->d + uVar16);
                  if (*(uint *)(local_58 + 8) < uVar16) {
                    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbb,0x44,"ec_mult.c",0x20c);
                    goto LAB_00503c74;
                  }
                }
                local_50 = pBVar12;
                puVar13 = *(ulong **)(local_58 + 0x10);
                if (param_4 < local_50) {
                  local_80 = (BIGNUM *)((int)&local_50[-1].flags + 3);
                  unaff_s6 = (BIGNUM *)(&local_68->d + (int)param_4);
                  unaff_s2 = (BIGNUM *)(&local_6c->d + (int)param_4);
                  ppuVar20 = ppuVar7;
                  pBVar17 = (BIGNUM *)(&pBVar6->d + (int)param_4);
                  pBVar12 = param_4;
                  do {
                    if (pBVar12 < local_80) {
                      unaff_s6->d = (ulong *)local_44;
                      if (local_30 < local_44) {
                        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbb,0x44,"ec_mult.c",0x21a);
                        param_4 = pBVar12;
                        goto LAB_00503c74;
                      }
                      pBVar14 = (BIGNUM *)unaff_s6->d;
                      local_30 = (BIGNUM *)((int)local_30 - (int)local_44);
                    }
                    else {
                      unaff_s6->d = (ulong *)local_30;
                      pBVar14 = local_30;
                    }
                    puVar2 = PTR_CRYPTO_malloc_006a7008;
                    unaff_s2->top = 0;
                    pBVar12 = (BIGNUM *)((int)&pBVar12->d + 1);
                    puVar8 = (ulong *)(*(code *)puVar2)(pBVar14,"ec_mult.c",0x226);
                    unaff_s2->d = puVar8;
                    if (puVar8 == (ulong *)0x0) {
                      uVar15 = 0x41;
                      uVar5 = 0x228;
LAB_005043b4:
                      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbb,uVar15,"ec_mult.c",uVar5);
                      (*(code *)PTR_CRYPTO_free_006a6e88)(ppuVar7);
                      param_4 = pBVar12;
                      goto LAB_00503c74;
                    }
                    (*(code *)PTR_memcpy_006a9aec)(puVar8,ppuVar20,unaff_s6->d);
                    if (pBVar19 < (BIGNUM *)unaff_s6->d) {
                      pBVar19 = (BIGNUM *)unaff_s6->d;
                    }
                    if (*puVar13 == 0) {
                      uVar15 = 0x44;
                      uVar5 = 0x231;
                      goto LAB_005043b4;
                    }
                    ppuVar20 = (ulong **)((int)ppuVar20 + (int)local_44);
                    pBVar17->d = puVar13;
                    unaff_s6 = (BIGNUM *)&unaff_s6->top;
                    puVar13 = puVar13 + local_40;
                    unaff_s2 = (BIGNUM *)&unaff_s2->top;
                    pBVar17 = (BIGNUM *)&pBVar17->top;
                  } while (pBVar12 < local_50);
                }
                (*(code *)PTR_CRYPTO_free_006a6e88)(ppuVar7);
                goto LAB_00504068;
              }
            }
LAB_00503c74:
            param_6 = (BIGNUM *)0x0;
            unaff_s3 = pBVar19;
            param_1 = ppuVar20;
            param_2 = pBVar17;
          }
LAB_00503c78:
          if (local_60 == (BN_CTX *)0x0) {
            pBVar6 = (BIGNUM *)0x0;
            goto LAB_00503e78;
          }
        }
      }
      else {
        local_4c = EC_GROUP_get0_generator((EC_GROUP *)param_1);
        if (local_4c != (EC_POINT *)0x0) {
          local_58 = EC_EX_DATA_get_data(param_1[0x11],ec_pre_comp_dup,ec_pre_comp_free,
                                         ec_pre_comp_clear_free);
          if (local_58 == 0) {
            local_40 = 0;
            iVar10 = 1;
            local_44 = (BIGNUM *)0x0;
            bVar1 = true;
            local_5c = 1;
          }
          else if ((*(int *)(local_58 + 8) == 0) ||
                  (iVar10 = EC_POINT_cmp((EC_GROUP *)param_1,local_4c,
                                         **(EC_POINT ***)(local_58 + 0x10),local_74), iVar10 != 0))
          {
            local_58 = 0;
            iVar10 = 1;
            local_40 = 0;
            local_44 = (BIGNUM *)0x0;
            bVar1 = true;
            local_5c = 1;
          }
          else {
            unaff_s2 = *(BIGNUM **)(local_58 + 4);
            uVar16 = BN_num_bits(param_3);
            local_5c = *(uint *)(local_58 + 8);
            local_40 = 1 << (*(int *)(local_58 + 0xc) - 1U & 0x1f);
            if (*(int *)(local_58 + 0x14) != local_5c * local_40) {
              uVar15 = 0x44;
              uVar5 = 0x19f;
              goto LAB_00503fb0;
            }
            if (unaff_s2 == (BIGNUM *)0x0) {
              trap(7);
            }
            bVar1 = false;
            iVar10 = 0;
            uVar16 = uVar16 / (uint)unaff_s2 + 1;
            local_44 = unaff_s2;
            if (uVar16 <= local_5c) {
              local_5c = uVar16;
            }
          }
          goto LAB_00503a84;
        }
        uVar15 = 0x71;
        uVar5 = 0x180;
LAB_00503fb0:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbb,uVar15,"ec_mult.c",uVar5);
        if (local_60 == (BN_CTX *)0x0) {
          pBVar6 = (BIGNUM *)0x0;
          local_64 = (BIGNUM *)0x0;
          goto LAB_00503d38;
        }
        local_64 = (BIGNUM *)0x0;
        param_6 = (BIGNUM *)0x0;
        local_68 = (BIGNUM *)0x0;
        local_6c = (BIGNUM *)0x0;
        local_78 = (BIGNUM *)0x0;
      }
      BN_CTX_free(local_60);
LAB_00503c94:
      pBVar6 = (BIGNUM *)0x0;
      if (local_78 != (BIGNUM *)0x0) goto LAB_00503e78;
      goto LAB_00503ca0;
    }
    ppuVar20 = &param_5->d;
    if ((ulong *)**ppuVar20 == *param_1) {
      pBVar6 = (BIGNUM *)0x0;
      do {
        param_5 = (BIGNUM *)&param_5->top;
        pBVar6 = (BIGNUM *)((int)&pBVar6->d + 1);
        if (param_4 == pBVar6) goto LAB_00503a00;
      } while ((ulong *)**ppuVar20 == **(ulong ***)param_5);
    }
    uVar5 = 0x172;
  }
  else {
    uVar5 = 0x168;
    param_1 = unaff_s5;
    param_2 = unaff_s7;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xbb,0x65,"ec_mult.c",uVar5);
  pBVar6 = (BIGNUM *)0x0;
LAB_0050396c:
  if (local_2c == *(int *)puVar3) {
    return pBVar6;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pBVar6 = param_6;
  param_6 = unaff_s3;
  pBVar19 = unaff_s6;
  while (iVar10 = EC_POINT_copy((EC_POINT *)*pBVar6->d,local_4c), unaff_s3 = param_6,
        unaff_s6 = pBVar19, iVar10 != 0) {
    while( true ) {
      unaff_s6 = pBVar19;
      if ((ulong *)0x1 < unaff_s1->d) {
        iVar10 = EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)unaff_s2,(EC_POINT *)*pBVar6->d,
                              local_74);
        unaff_s3 = param_6;
        if (iVar10 == 0) goto LAB_00503e48;
        iVar10 = 0;
        if (1 < (uint)(1 << ((int)unaff_s1->d - 1U & 0x1f))) {
          uVar16 = 1;
          do {
            iVar9 = EC_POINT_add((EC_GROUP *)param_1,(EC_POINT *)pBVar6->d[uVar16],
                                 *(EC_POINT **)((int)pBVar6->d + iVar10),(EC_POINT *)unaff_s2,
                                 local_74);
            if (iVar9 == 0) goto LAB_00503e48;
            uVar16 = uVar16 + 1;
            iVar10 = iVar10 + 4;
          } while (uVar16 < (uint)(1 << ((int)unaff_s1->d - 1U & 0x1f)));
        }
      }
      unaff_s1 = (BIGNUM *)&unaff_s1->top;
      local_7c = (BIGNUM *)&local_7c->top;
      local_80 = (BIGNUM *)((int)&local_80->d + 1);
      pBVar6 = (BIGNUM *)&pBVar6->top;
      if (local_80 == local_70) goto LAB_00503e28;
LAB_0050448c:
      if (param_4 <= local_80) break;
      iVar10 = EC_POINT_copy((EC_POINT *)*pBVar6->d,(EC_POINT *)local_7c->d);
      unaff_s3 = param_6;
      unaff_s6 = pBVar19;
      if (iVar10 == 0) goto LAB_00503e48;
    }
  }
  goto LAB_00503e48;
LAB_00503e28:
  iVar10 = EC_POINTs_make_affine((EC_GROUP *)param_1,(size_t)local_34,(EC_POINT **)param_6,local_74)
  ;
  unaff_s3 = pBVar19;
  if (iVar10 == 0) {
LAB_00503e48:
    pBVar6 = (BIGNUM *)0x0;
  }
  else {
    local_70 = (BIGNUM *)0x0;
    pBVar6 = (BIGNUM *)0x1;
    while (unaff_s3 = (BIGNUM *)((int)&unaff_s3[-1].flags + 3), param_4 = pBVar6, local_80 = param_6
          , local_7c = unaff_s2, -1 < (int)unaff_s3) {
      if ((pBVar6 == (BIGNUM *)0x0) &&
         (iVar10 = EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_2,local_74
                               ), iVar10 == 0)) goto LAB_00503e48;
      pBVar17 = (BIGNUM *)0x0;
      pBVar18 = local_6c;
      pBVar19 = local_68;
      param_4 = local_64;
      if (local_50 != (BIGNUM *)0x0) {
        do {
          if ((unaff_s3 < (BIGNUM *)pBVar19->d) &&
             (uVar16 = (uint)(char)*(EC_POINT *)((int)pBVar18->d + (int)unaff_s3), uVar16 != 0)) {
            uVar11 = uVar16;
            if ((int)uVar16 < 0) {
              uVar11 = -uVar16;
            }
            unaff_s6 = pBVar19;
            if ((BIGNUM *)(uVar16 >> 0x1f) != local_70) {
              if ((pBVar6 == (BIGNUM *)0x0) &&
                 (iVar10 = EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,local_74),
                 iVar10 == 0)) goto LAB_00503e48;
              local_70 = (BIGNUM *)((uint)local_70 ^ 1);
            }
            if (pBVar6 == (BIGNUM *)0x0) {
              iVar10 = EC_POINT_add((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_2,
                                    (EC_POINT *)param_4->d[(int)uVar11 >> 1],local_74);
              if (iVar10 == 0) goto LAB_00503e48;
            }
            else {
              iVar10 = EC_POINT_copy((EC_POINT *)param_2,(EC_POINT *)param_4->d[(int)uVar11 >> 1]);
              if (iVar10 == 0) goto LAB_00503e48;
              pBVar6 = (BIGNUM *)0x0;
            }
          }
          pBVar17 = (BIGNUM *)((int)&pBVar17->d + 1);
          unaff_s6 = (BIGNUM *)&pBVar19->top;
          pBVar18 = (BIGNUM *)&pBVar18->top;
          pBVar19 = unaff_s6;
          param_4 = (BIGNUM *)&param_4->top;
        } while (local_50 != pBVar17);
      }
    }
    if (pBVar6 == (BIGNUM *)0x0) {
      if (local_70 == (BIGNUM *)0x0) {
        pBVar6 = (BIGNUM *)0x1;
      }
      else {
        iVar10 = EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,local_74);
        pBVar6 = (BIGNUM *)(uint)(iVar10 != 0);
      }
    }
    else {
      iVar10 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
      pBVar6 = (BIGNUM *)(uint)(iVar10 != 0);
    }
  }
  if (local_60 != (BN_CTX *)0x0) {
    BN_CTX_free(local_60);
  }
  EC_POINT_free((EC_POINT *)unaff_s2);
LAB_00503e78:
  (*(code *)PTR_CRYPTO_free_006a6e88)(local_78);
LAB_00503ca0:
  if (local_68 != (BIGNUM *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_68);
  }
  if (local_6c != (BIGNUM *)0x0) {
    puVar13 = local_6c->d;
    unaff_s2 = local_6c;
    while (puVar13 != (ulong *)0x0) {
      unaff_s2 = (BIGNUM *)&unaff_s2->top;
      (*(code *)PTR_CRYPTO_free_006a6e88)();
      puVar13 = *(ulong **)unaff_s2;
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_6c);
  }
  if (param_6 != (BIGNUM *)0x0) {
    puVar13 = param_6->d;
    unaff_s2 = param_6;
    while (puVar13 != (ulong *)0x0) {
      unaff_s2 = (BIGNUM *)&unaff_s2->top;
      EC_POINT_clear_free((EC_POINT *)puVar13);
      puVar13 = *(ulong **)unaff_s2;
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(param_6);
  }
LAB_00503d38:
  unaff_s1 = pBVar6;
  if (local_64 != (BIGNUM *)0x0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_64);
  }
  goto LAB_0050396c;
}

