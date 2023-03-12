
BIGNUM * ec_wNAF_mul(int *param_1,int *param_2,BIGNUM *param_3,BIGNUM *param_4,int **param_5,
                    int param_6,BN_CTX *param_7)

{
  int **ppiVar1;
  int iVar2;
  ulong **ppuVar3;
  BIGNUM *pBVar4;
  uint uVar5;
  ulong *puVar6;
  BIGNUM *pBVar7;
  void *__dest;
  BIGNUM *pBVar8;
  int iVar9;
  BIGNUM *pBVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  BIGNUM *pBVar14;
  BIGNUM *pBVar15;
  EC_POINT **ppEVar16;
  BIGNUM **ppBVar17;
  ulong *__src;
  BIGNUM *pBVar18;
  BIGNUM *pBVar19;
  int *piVar20;
  ulong **local_78;
  BIGNUM *local_70;
  BIGNUM *local_6c;
  BIGNUM *local_68;
  BIGNUM *local_64;
  BN_CTX *local_5c;
  BIGNUM *local_58;
  BIGNUM *local_54;
  BIGNUM *local_50;
  BIGNUM *local_4c;
  BIGNUM *local_48;
  BIGNUM *local_44;
  BIGNUM *local_40;
  BIGNUM *local_3c;
  BIGNUM *local_2c [2];
  
  if (*param_1 != *param_2) {
    iVar12 = 0x176;
LAB_000918ae:
    ERR_put_error(0x10,0xbb,0x65,"ec_mult.c",iVar12);
    return (BIGNUM *)0x0;
  }
  if (param_3 == (BIGNUM *)0x0 && param_4 == (BIGNUM *)0x0) {
    pBVar14 = (BIGNUM *)EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
    return pBVar14;
  }
  pBVar14 = (BIGNUM *)0x0;
  if (param_4 != (BIGNUM *)0x0) {
    iVar12 = **param_5;
    ppiVar1 = param_5;
    while (*param_1 == iVar12) {
      pBVar14 = (BIGNUM *)((int)&pBVar14->d + 1);
      if (pBVar14 == param_4) goto LAB_000918fc;
      ppiVar1 = ppiVar1 + 1;
      iVar12 = **ppiVar1;
    }
    iVar12 = 0x183;
    goto LAB_000918ae;
  }
LAB_000918fc:
  if (param_7 == (BN_CTX *)0x0) {
    param_7 = BN_CTX_new();
    local_5c = param_7;
    if (param_7 == (BN_CTX *)0x0) {
      return (BIGNUM *)0x0;
    }
  }
  else {
    local_5c = (BN_CTX *)0x0;
  }
  local_6c = param_3;
  local_58 = param_3;
  local_54 = param_3;
  local_4c = param_3;
  local_48 = param_3;
  local_44 = param_3;
  if (param_3 != (BIGNUM *)0x0) {
    local_4c = (BIGNUM *)EC_GROUP_get0_generator((EC_GROUP *)param_1);
    if (local_4c == (BIGNUM *)0x0) {
      iVar9 = 0x194;
      iVar12 = 0x71;
LAB_00091bdc:
      ERR_put_error(0x10,0xbb,iVar12,"ec_mult.c",iVar9);
      pBVar14 = local_4c;
      pBVar7 = local_4c;
      pBVar8 = local_4c;
      local_70 = local_4c;
      local_68 = local_4c;
      local_64 = local_4c;
      goto LAB_00091a9e;
    }
    local_6c = (BIGNUM *)EC_EX_DATA_get_data(param_1[0x11],0x9161d,0x917d9,0x9182d);
    local_54 = local_4c;
    if (local_6c == (BIGNUM *)0x0) {
      local_4c = (BIGNUM *)0x1;
      local_58 = (BIGNUM *)0x1;
      local_48 = local_6c;
      local_44 = local_6c;
    }
    else {
      local_48 = (BIGNUM *)local_6c->dmax;
      if (local_48 == (BIGNUM *)0x0) {
        local_4c = (BIGNUM *)0x1;
        local_58 = (BIGNUM *)0x1;
        local_6c = local_48;
        local_44 = local_48;
      }
      else {
        local_4c = (BIGNUM *)
                   EC_POINT_cmp((EC_GROUP *)param_1,(EC_POINT *)local_4c,
                                *(EC_POINT **)local_6c->flags,param_7);
        if (local_4c == (BIGNUM *)0x0) {
          local_48 = (BIGNUM *)local_6c->top;
          iVar12 = BN_num_bits(param_3);
          pBVar14 = (BIGNUM *)local_6c->dmax;
          local_44 = (BIGNUM *)(1 << (local_6c->neg - 1U & 0xff));
          if (local_6c[1].d != (ulong *)((int)pBVar14 * (int)local_44)) {
            iVar9 = 0x1ad;
            iVar12 = 0x44;
            goto LAB_00091bdc;
          }
          iVar12 = __udivsi3(iVar12,local_48);
          local_58 = (BIGNUM *)(iVar12 + 1U);
          if (pBVar14 <= (BIGNUM *)(iVar12 + 1U)) {
            local_58 = pBVar14;
          }
        }
        else {
          local_4c = (BIGNUM *)0x1;
          local_6c = (BIGNUM *)0x0;
          local_58 = (BIGNUM *)0x1;
          local_44 = (BIGNUM *)0x0;
          local_48 = (BIGNUM *)0x0;
        }
      }
    }
  }
  local_50 = (BIGNUM *)((int)&param_4->d + (int)&local_58->d);
  iVar12 = (int)local_50 * 4;
  local_70 = (BIGNUM *)CRYPTO_malloc(iVar12,"ec_mult.c",0x1bc);
  local_64 = (BIGNUM *)CRYPTO_malloc(iVar12,"ec_mult.c",0x1bd);
  pBVar14 = (BIGNUM *)CRYPTO_malloc(iVar12 + 4,"ec_mult.c",0x1be);
  local_68 = (BIGNUM *)CRYPTO_malloc(iVar12,"ec_mult.c",0x1bf);
  if ((local_64 == (BIGNUM *)0x0 || local_70 == (BIGNUM *)0x0) ||
     (local_68 == (BIGNUM *)0x0 || pBVar14 == (BIGNUM *)0x0)) {
    ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x1c3);
    local_4c = (BIGNUM *)0x0;
    pBVar7 = (BIGNUM *)0x0;
    pBVar8 = (BIGNUM *)0x0;
    goto LAB_00091a9e;
  }
  pBVar15 = (BIGNUM *)0x0;
  pBVar10 = (BIGNUM *)((int)&param_4->d + (int)&local_4c->d);
  pBVar14->d = (ulong *)0x0;
  pBVar8 = pBVar15;
  pBVar7 = local_64;
  pBVar19 = pBVar15;
  pBVar18 = pBVar15;
  local_40 = pBVar10;
  local_3c = pBVar10;
  if (pBVar10 != (BIGNUM *)0x0) {
    do {
      pBVar4 = param_3;
      if (pBVar18 < param_4) {
        pBVar4 = *(BIGNUM **)((int)&pBVar19->d + param_6);
      }
      uVar5 = BN_num_bits(pBVar4);
      if (uVar5 < 2000) {
        if (uVar5 < 800) {
          if (uVar5 < 300) {
            if (uVar5 < 0x46) {
              if (uVar5 < 0x14) {
                iVar12 = 1;
                uVar11 = 1;
              }
              else {
                iVar12 = 2;
                uVar11 = 2;
              }
            }
            else {
              iVar12 = 4;
              uVar11 = 3;
            }
          }
          else {
            iVar12 = 8;
            uVar11 = 4;
          }
        }
        else {
          iVar12 = 0x10;
          uVar11 = 5;
        }
      }
      else {
        uVar11 = 6;
        iVar12 = 0x20;
      }
      pBVar15 = (BIGNUM *)((int)&pBVar15->d + iVar12);
      *(undefined4 *)((int)&pBVar19->d + (int)&local_70->d) = uVar11;
      *(undefined4 *)((int)&pBVar19->top + (int)&pBVar14->d) = 0;
      pBVar4 = param_3;
      if (pBVar18 < param_4) {
        pBVar4 = *(BIGNUM **)((int)&pBVar19->d + param_6);
      }
      iVar12 = compute_wNAF(pBVar4,uVar11,pBVar7);
      *(int *)((int)&pBVar19->d + (int)&pBVar14->d) = iVar12;
      if (iVar12 == 0) goto LAB_00091b74;
      pBVar18 = (BIGNUM *)((int)&pBVar18->d + 1);
      local_40 = pBVar8;
      if (pBVar8 < (BIGNUM *)pBVar7->d) {
        local_40 = (BIGNUM *)pBVar7->d;
      }
      pBVar8 = local_40;
      pBVar7 = (BIGNUM *)&pBVar7->top;
      pBVar19 = (BIGNUM *)&pBVar19->top;
      local_3c = pBVar15;
    } while (pBVar18 != pBVar10);
  }
  if (local_58 != (BIGNUM *)0x0) {
    if (local_6c != (BIGNUM *)0x0) {
      local_2c[0] = (BIGNUM *)0x0;
      if (local_4c == (BIGNUM *)0x0) {
        iVar12 = (int)param_4 * 4;
        puVar6 = (ulong *)local_6c->neg;
        (&local_70->d)[(int)param_4] = puVar6;
        puVar6 = (ulong *)compute_wNAF(param_3,puVar6,local_2c);
        if (puVar6 != (ulong *)0x0) {
          if (local_40 < local_2c[0]) {
            if (local_2c[0] < (BIGNUM *)((int)local_48 * (int)local_58)) {
              uVar5 = __udivsi3((undefined *)((int)&local_2c[0][-1].flags + 3) + (int)local_48);
              if ((uint)local_6c->dmax < uVar5) {
                iVar12 = 0x217;
                goto LAB_00091b64;
              }
              local_50 = (BIGNUM *)((int)&param_4->d + uVar5);
            }
            piVar20 = (int *)local_6c->flags;
            if (param_4 < local_50) {
              local_78 = &pBVar14->d + (int)param_4;
              __src = puVar6;
              pBVar8 = param_4;
              do {
                ppBVar17 = (BIGNUM **)((int)&local_64->d + iVar12);
                if (pBVar8 < (BIGNUM *)((int)&local_50[-1].flags + 3)) {
                  *(BIGNUM **)((int)&local_64->d + iVar12) = local_48;
                  if (local_2c[0] < local_48) {
                    iVar12 = 0x228;
                    goto LAB_00091b64;
                  }
                  pBVar7 = *(BIGNUM **)((int)&local_64->d + iVar12);
                  local_2c[0] = (BIGNUM *)((int)local_2c[0] - (int)local_48);
                }
                else {
                  *(BIGNUM **)((int)&local_64->d + iVar12) = local_2c[0];
                  pBVar7 = local_2c[0];
                }
                pBVar8 = (BIGNUM *)((int)&pBVar8->d + 1);
                local_78 = local_78 + 1;
                *local_78 = (ulong *)0x0;
                __dest = CRYPTO_malloc((int)pBVar7,"ec_mult.c",0x233);
                *(void **)((int)&pBVar14->d + iVar12) = __dest;
                if (__dest == (void *)0x0) {
                  ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x236);
                  CRYPTO_free(puVar6);
                  goto LAB_00091b74;
                }
                memcpy(__dest,__src,(size_t)*ppBVar17);
                pBVar7 = *ppBVar17;
                if (local_40 < pBVar7) {
                  local_40 = pBVar7;
                }
                if (*piVar20 == 0) {
                  ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x240);
                  CRYPTO_free(puVar6);
                  goto LAB_00091b74;
                }
                *(int **)((int)&local_68->d + iVar12) = piVar20;
                piVar20 = piVar20 + (int)local_44;
                iVar12 = iVar12 + 4;
                __src = (ulong *)((int)__src + (int)local_48);
              } while (pBVar8 < local_50);
            }
            CRYPTO_free(puVar6);
          }
          else {
            local_50 = (BIGNUM *)((int)&param_4->d + 1);
            (&pBVar14->d)[(int)param_4] = puVar6;
            (&pBVar14->top)[(int)param_4] = 0;
            (&local_64->d)[(int)param_4] = (ulong *)local_2c[0];
            (&local_68->d)[(int)param_4] = (ulong *)local_6c->flags;
            if (local_40 < local_2c[0]) {
              local_40 = local_2c[0];
            }
          }
          goto LAB_00091c6e;
        }
      }
      else {
        iVar12 = 0x1ef;
LAB_00091b64:
        ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",iVar12);
      }
LAB_00091b74:
      local_4c = (BIGNUM *)0x0;
      pBVar7 = (BIGNUM *)0x0;
      pBVar8 = (BIGNUM *)0x0;
      goto LAB_00091a9e;
    }
    if (local_4c != (BIGNUM *)0x1) {
      ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x1e3);
      local_4c = local_6c;
      pBVar7 = local_6c;
      pBVar8 = local_6c;
      goto LAB_00091a9e;
    }
  }
LAB_00091c6e:
  ppuVar3 = &local_3c->d;
  local_4c = (BIGNUM *)CRYPTO_malloc((int)ppuVar3 * 4 + 4,"ec_mult.c",0x250);
  if (local_4c == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x253);
    pBVar7 = local_4c;
    pBVar8 = local_4c;
  }
  else {
    (&local_4c->d)[(int)ppuVar3] = (ulong *)0x0;
    pBVar19 = local_4c;
    if (pBVar10 != (BIGNUM *)0x0) {
      pBVar18 = (BIGNUM *)0x0;
      do {
        puVar6 = (&local_70->d)[(int)pBVar18];
        (&local_68->d)[(int)pBVar18] = (ulong *)pBVar19;
        if (1 << ((uint)((int)puVar6 + -1) & 0xff) != 0) {
          uVar5 = 0;
          pBVar8 = pBVar19;
          do {
            uVar5 = uVar5 + 1;
            pBVar7 = (BIGNUM *)EC_POINT_new((EC_GROUP *)param_1);
            pBVar19 = (BIGNUM *)&pBVar8->top;
            pBVar8->d = (ulong *)pBVar7;
            pBVar8 = pBVar7;
            if (pBVar7 == (BIGNUM *)0x0) goto LAB_00091a9e;
            pBVar8 = pBVar19;
          } while (uVar5 < (uint)(1 << ((uint)((int)(&local_70->d)[(int)pBVar18] + -1) & 0xff)));
        }
        pBVar18 = (BIGNUM *)((int)&pBVar18->d + 1);
      } while (pBVar18 != pBVar10);
    }
    if (pBVar19 == (BIGNUM *)(&local_4c->d + (int)ppuVar3)) {
      pBVar7 = (BIGNUM *)EC_POINT_new((EC_GROUP *)param_1);
      pBVar8 = pBVar7;
      if (pBVar7 != (BIGNUM *)0x0) {
        iVar12 = 0;
        for (local_6c = (BIGNUM *)0x0; local_6c != pBVar10;
            local_6c = (BIGNUM *)((int)&local_6c->d + 1)) {
          ppEVar16 = *(EC_POINT ***)((int)&local_68->d + iVar12);
          if (local_6c < param_4) {
            pBVar8 = (BIGNUM *)EC_POINT_copy(*ppEVar16,*(EC_POINT **)((int)param_5 + iVar12));
          }
          else {
            pBVar8 = (BIGNUM *)EC_POINT_copy(*ppEVar16,(EC_POINT *)local_54);
          }
          if (pBVar8 == (BIGNUM *)0x0) goto LAB_00091a9e;
          if (1 < *(uint *)((int)&local_70->d + iVar12)) {
            pBVar8 = (BIGNUM *)
                     EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)pBVar7,
                                  **(EC_POINT ***)((int)&local_68->d + iVar12),param_7);
            if (pBVar8 == (BIGNUM *)0x0) goto LAB_00091a9e;
            if (1 < (uint)(1 << (*(int *)((int)&local_70->d + iVar12) - 1U & 0xff))) {
              uVar5 = 1;
              do {
                iVar13 = *(int *)((int)&local_68->d + iVar12);
                iVar9 = uVar5 * 4;
                iVar2 = uVar5 * 4;
                uVar5 = uVar5 + 1;
                pBVar8 = (BIGNUM *)
                         EC_POINT_add((EC_GROUP *)param_1,*(EC_POINT **)(iVar13 + iVar2),
                                      *(EC_POINT **)(iVar13 + iVar9 + -4),(EC_POINT *)pBVar7,param_7
                                     );
                if (pBVar8 == (BIGNUM *)0x0) goto LAB_00091a9e;
              } while (uVar5 < (uint)(1 << (*(int *)((int)&local_70->d + iVar12) - 1U & 0xff)));
            }
          }
          iVar12 = iVar12 + 4;
        }
        pBVar8 = (BIGNUM *)
                 EC_POINTs_make_affine
                           ((EC_GROUP *)param_1,(size_t)local_3c,(EC_POINT **)local_4c,param_7);
        if (pBVar8 != (BIGNUM *)0x0) {
          pBVar8 = (BIGNUM *)0x1;
          local_78 = (ulong **)0x0;
          while (local_40 = (BIGNUM *)((int)&local_40[-1].flags + 3), -1 < (int)local_40) {
            if ((pBVar8 == (BIGNUM *)0x0) &&
               (iVar12 = EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_2,
                                      param_7), iVar12 == 0)) goto LAB_00091a9e;
            pBVar19 = (BIGNUM *)0x0;
            if (local_50 != (BIGNUM *)0x0) {
              do {
                if ((local_40 < (BIGNUM *)(&local_64->d)[(int)pBVar19]) &&
                   (iVar12 = (int)(char)*(EC_POINT *)
                                         ((int)(&pBVar14->d)[(int)pBVar19] + (int)local_40),
                   iVar12 != 0)) {
                  iVar9 = iVar12 >> 0x1f;
                  if (iVar12 < 0) {
                    iVar12 = -iVar12;
                  }
                  if (-(int)local_78 != iVar9) {
                    if ((pBVar8 == (BIGNUM *)0x0) &&
                       (iVar9 = EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,param_7),
                       iVar9 == 0)) goto LAB_00091a9e;
                    local_78 = (ulong **)((uint)local_78 ^ 1);
                  }
                  if (pBVar8 == (BIGNUM *)0x0) {
                    iVar12 = EC_POINT_add((EC_GROUP *)param_1,(EC_POINT *)param_2,
                                          (EC_POINT *)param_2,
                                          (EC_POINT *)(&local_68->d)[(int)pBVar19][iVar12 >> 1],
                                          param_7);
                    if (iVar12 == 0) goto LAB_00091a9e;
                  }
                  else {
                    pBVar8 = (BIGNUM *)
                             EC_POINT_copy((EC_POINT *)param_2,
                                           (EC_POINT *)(&local_68->d)[(int)pBVar19][iVar12 >> 1]);
                    if (pBVar8 == (BIGNUM *)0x0) goto LAB_00091a9e;
                    pBVar8 = (BIGNUM *)0x0;
                  }
                }
                pBVar19 = (BIGNUM *)((int)&pBVar19->d + 1);
              } while (pBVar19 != local_50);
            }
          }
          if (pBVar8 == (BIGNUM *)0x0) {
            if (local_78 == (ulong **)0x0) {
              pBVar8 = (BIGNUM *)0x1;
            }
            else {
              pBVar8 = (BIGNUM *)EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,param_7);
              if (pBVar8 != (BIGNUM *)0x0) {
                pBVar8 = (BIGNUM *)0x1;
              }
            }
          }
          else {
            pBVar8 = (BIGNUM *)EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
            if (pBVar8 != (BIGNUM *)0x0) {
              pBVar8 = (BIGNUM *)0x1;
            }
          }
        }
      }
    }
    else {
      ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x266);
      pBVar7 = (BIGNUM *)0x0;
      pBVar8 = (BIGNUM *)0x0;
    }
  }
LAB_00091a9e:
  if (local_5c != (BN_CTX *)0x0) {
    BN_CTX_free(local_5c);
  }
  if (pBVar7 != (BIGNUM *)0x0) {
    EC_POINT_free((EC_POINT *)pBVar7);
  }
  if (local_70 != (BIGNUM *)0x0) {
    CRYPTO_free(local_70);
  }
  if (local_64 != (BIGNUM *)0x0) {
    CRYPTO_free(local_64);
  }
  if (pBVar14 != (BIGNUM *)0x0) {
    puVar6 = pBVar14->d;
    pBVar7 = pBVar14;
    while (puVar6 != (ulong *)0x0) {
      CRYPTO_free(puVar6);
      pBVar7 = (BIGNUM *)&pBVar7->top;
      puVar6 = *(ulong **)pBVar7;
    }
    CRYPTO_free(pBVar14);
  }
  if (local_4c != (BIGNUM *)0x0) {
    puVar6 = local_4c->d;
    pBVar14 = local_4c;
    while (puVar6 != (ulong *)0x0) {
      EC_POINT_clear_free((EC_POINT *)puVar6);
      pBVar14 = (BIGNUM *)&pBVar14->top;
      puVar6 = *(ulong **)pBVar14;
    }
    CRYPTO_free(local_4c);
  }
  if (local_68 == (BIGNUM *)0x0) {
    return pBVar8;
  }
  CRYPTO_free(local_68);
  return pBVar8;
}

