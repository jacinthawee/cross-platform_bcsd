
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
  undefined4 uVar10;
  int iVar11;
  BIGNUM *pBVar12;
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
    iVar11 = 0x168;
LAB_0008fe0e:
    ERR_put_error(0x10,0xbb,0x65,"ec_mult.c",iVar11);
    return (BIGNUM *)0x0;
  }
  if (param_3 == (BIGNUM *)0x0 && param_4 == (BIGNUM *)0x0) {
    pBVar14 = (BIGNUM *)EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
    return pBVar14;
  }
  pBVar14 = (BIGNUM *)0x0;
  if (param_4 != (BIGNUM *)0x0) {
    iVar11 = **param_5;
    ppiVar1 = param_5;
    while (*param_1 == iVar11) {
      pBVar14 = (BIGNUM *)((int)&pBVar14->d + 1);
      if (pBVar14 == param_4) goto LAB_0008fe5c;
      ppiVar1 = ppiVar1 + 1;
      iVar11 = **ppiVar1;
    }
    iVar11 = 0x172;
    goto LAB_0008fe0e;
  }
LAB_0008fe5c:
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
      iVar9 = 0x180;
      iVar11 = 0x71;
LAB_00090148:
      ERR_put_error(0x10,0xbb,iVar11,"ec_mult.c",iVar9);
      pBVar14 = local_4c;
      pBVar7 = local_4c;
      pBVar8 = local_4c;
      local_70 = local_4c;
      local_68 = local_4c;
      local_64 = local_4c;
      goto LAB_0009000a;
    }
    local_6c = (BIGNUM *)EC_EX_DATA_get_data(param_1[0x11],0x8fb7d,0x8fd39,0x8fd8d);
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
          iVar11 = BN_num_bits(param_3);
          pBVar14 = (BIGNUM *)local_6c->dmax;
          local_44 = (BIGNUM *)(1 << (local_6c->neg - 1U & 0xff));
          if (local_6c[1].d != (ulong *)((int)pBVar14 * (int)local_44)) {
            iVar9 = 0x19f;
            iVar11 = 0x44;
            goto LAB_00090148;
          }
          iVar11 = __udivsi3(iVar11,local_48);
          local_58 = (BIGNUM *)(iVar11 + 1U);
          if (pBVar14 <= (BIGNUM *)(iVar11 + 1U)) {
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
  iVar11 = (int)local_50 * 4;
  local_70 = (BIGNUM *)CRYPTO_malloc(iVar11,"ec_mult.c",0x1ad);
  local_64 = (BIGNUM *)CRYPTO_malloc(iVar11,"ec_mult.c",0x1ae);
  pBVar14 = (BIGNUM *)CRYPTO_malloc(iVar11 + 4,"ec_mult.c",0x1af);
  local_68 = (BIGNUM *)CRYPTO_malloc(iVar11,"ec_mult.c",0x1b1);
  if (pBVar14 != (BIGNUM *)0x0) {
    pBVar14->d = (ulong *)0x0;
  }
  if ((local_64 == (BIGNUM *)0x0 || local_70 == (BIGNUM *)0x0) ||
     (local_68 == (BIGNUM *)0x0 || pBVar14 == (BIGNUM *)0x0)) {
    ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x1b8);
    local_4c = (BIGNUM *)0x0;
    pBVar7 = (BIGNUM *)0x0;
    pBVar8 = (BIGNUM *)0x0;
    goto LAB_0009000a;
  }
  pBVar15 = (BIGNUM *)0x0;
  pBVar12 = (BIGNUM *)((int)&param_4->d + (int)&local_4c->d);
  pBVar8 = pBVar15;
  pBVar7 = local_64;
  pBVar19 = pBVar15;
  pBVar18 = pBVar15;
  local_40 = pBVar12;
  local_3c = pBVar12;
  if (pBVar12 != (BIGNUM *)0x0) {
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
                iVar11 = 1;
                uVar10 = 1;
              }
              else {
                iVar11 = 2;
                uVar10 = 2;
              }
            }
            else {
              iVar11 = 4;
              uVar10 = 3;
            }
          }
          else {
            iVar11 = 8;
            uVar10 = 4;
          }
        }
        else {
          iVar11 = 0x10;
          uVar10 = 5;
        }
      }
      else {
        uVar10 = 6;
        iVar11 = 0x20;
      }
      pBVar15 = (BIGNUM *)((int)&pBVar15->d + iVar11);
      *(undefined4 *)((int)&pBVar19->d + (int)&local_70->d) = uVar10;
      *(undefined4 *)((int)&pBVar19->top + (int)&pBVar14->d) = 0;
      pBVar4 = param_3;
      if (pBVar18 < param_4) {
        pBVar4 = *(BIGNUM **)((int)&pBVar19->d + param_6);
      }
      iVar11 = compute_wNAF(pBVar4,uVar10,pBVar7);
      *(int *)((int)&pBVar19->d + (int)&pBVar14->d) = iVar11;
      if (iVar11 == 0) goto LAB_000900e0;
      pBVar18 = (BIGNUM *)((int)&pBVar18->d + 1);
      local_40 = pBVar8;
      if (pBVar8 < (BIGNUM *)pBVar7->d) {
        local_40 = (BIGNUM *)pBVar7->d;
      }
      pBVar8 = local_40;
      pBVar7 = (BIGNUM *)&pBVar7->top;
      pBVar19 = (BIGNUM *)&pBVar19->top;
      local_3c = pBVar15;
    } while (pBVar18 != pBVar12);
  }
  if (local_58 != (BIGNUM *)0x0) {
    if (local_6c != (BIGNUM *)0x0) {
      local_2c[0] = (BIGNUM *)0x0;
      if (local_4c == (BIGNUM *)0x0) {
        iVar11 = (int)param_4 * 4;
        puVar6 = (ulong *)local_6c->neg;
        (&local_70->d)[(int)param_4] = puVar6;
        puVar6 = (ulong *)compute_wNAF(param_3,puVar6,local_2c);
        if (puVar6 != (ulong *)0x0) {
          if (local_40 < local_2c[0]) {
            if (local_2c[0] < (BIGNUM *)((int)local_48 * (int)local_58)) {
              uVar5 = __udivsi3((undefined *)((int)&local_2c[0][-1].flags + 3) + (int)local_48);
              if ((uint)local_6c->dmax < uVar5) {
                iVar11 = 0x20c;
                goto LAB_000900d0;
              }
              local_50 = (BIGNUM *)((int)&param_4->d + uVar5);
            }
            piVar20 = (int *)local_6c->flags;
            if (param_4 < local_50) {
              local_78 = &pBVar14->d + (int)param_4;
              __src = puVar6;
              pBVar8 = param_4;
              do {
                ppBVar17 = (BIGNUM **)((int)&local_64->d + iVar11);
                if (pBVar8 < (BIGNUM *)((int)&local_50[-1].flags + 3)) {
                  *(BIGNUM **)((int)&local_64->d + iVar11) = local_48;
                  if (local_2c[0] < local_48) {
                    iVar11 = 0x21a;
                    goto LAB_000900d0;
                  }
                  pBVar7 = *(BIGNUM **)((int)&local_64->d + iVar11);
                  local_2c[0] = (BIGNUM *)((int)local_2c[0] - (int)local_48);
                }
                else {
                  *(BIGNUM **)((int)&local_64->d + iVar11) = local_2c[0];
                  pBVar7 = local_2c[0];
                }
                pBVar8 = (BIGNUM *)((int)&pBVar8->d + 1);
                local_78 = local_78 + 1;
                *local_78 = (ulong *)0x0;
                __dest = CRYPTO_malloc((int)pBVar7,"ec_mult.c",0x226);
                *(void **)((int)&pBVar14->d + iVar11) = __dest;
                if (__dest == (void *)0x0) {
                  ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x228);
                  CRYPTO_free(puVar6);
                  goto LAB_000900e0;
                }
                memcpy(__dest,__src,(size_t)*ppBVar17);
                pBVar7 = *ppBVar17;
                if (local_40 < pBVar7) {
                  local_40 = pBVar7;
                }
                if (*piVar20 == 0) {
                  ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x231);
                  CRYPTO_free(puVar6);
                  goto LAB_000900e0;
                }
                *(int **)((int)&local_68->d + iVar11) = piVar20;
                piVar20 = piVar20 + (int)local_44;
                iVar11 = iVar11 + 4;
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
          goto LAB_000901da;
        }
      }
      else {
        iVar11 = 0x1df;
LAB_000900d0:
        ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",iVar11);
      }
LAB_000900e0:
      local_4c = (BIGNUM *)0x0;
      pBVar7 = (BIGNUM *)0x0;
      pBVar8 = (BIGNUM *)0x0;
      goto LAB_0009000a;
    }
    if (local_4c != (BIGNUM *)0x1) {
      ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x1d6);
      local_4c = local_6c;
      pBVar7 = local_6c;
      pBVar8 = local_6c;
      goto LAB_0009000a;
    }
  }
LAB_000901da:
  ppuVar3 = &local_3c->d;
  local_4c = (BIGNUM *)CRYPTO_malloc((int)ppuVar3 * 4 + 4,"ec_mult.c",0x243);
  if (local_4c == (BIGNUM *)0x0) {
    ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x245);
    pBVar7 = local_4c;
    pBVar8 = local_4c;
  }
  else {
    (&local_4c->d)[(int)ppuVar3] = (ulong *)0x0;
    pBVar19 = local_4c;
    if (pBVar12 != (BIGNUM *)0x0) {
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
            if (pBVar7 == (BIGNUM *)0x0) goto LAB_0009000a;
            pBVar8 = pBVar19;
          } while (uVar5 < (uint)(1 << ((uint)((int)(&local_70->d)[(int)pBVar18] + -1) & 0xff)));
        }
        pBVar18 = (BIGNUM *)((int)&pBVar18->d + 1);
      } while (pBVar18 != pBVar12);
    }
    if (pBVar19 == (BIGNUM *)(&local_4c->d + (int)ppuVar3)) {
      pBVar7 = (BIGNUM *)EC_POINT_new((EC_GROUP *)param_1);
      pBVar8 = pBVar7;
      if (pBVar7 != (BIGNUM *)0x0) {
        iVar11 = 0;
        for (local_6c = (BIGNUM *)0x0; local_6c != pBVar12;
            local_6c = (BIGNUM *)((int)&local_6c->d + 1)) {
          ppEVar16 = *(EC_POINT ***)((int)&local_68->d + iVar11);
          if (local_6c < param_4) {
            pBVar8 = (BIGNUM *)EC_POINT_copy(*ppEVar16,*(EC_POINT **)((int)param_5 + iVar11));
          }
          else {
            pBVar8 = (BIGNUM *)EC_POINT_copy(*ppEVar16,(EC_POINT *)local_54);
          }
          if (pBVar8 == (BIGNUM *)0x0) goto LAB_0009000a;
          if (1 < *(uint *)((int)&local_70->d + iVar11)) {
            pBVar8 = (BIGNUM *)
                     EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)pBVar7,
                                  **(EC_POINT ***)((int)&local_68->d + iVar11),param_7);
            if (pBVar8 == (BIGNUM *)0x0) goto LAB_0009000a;
            if (1 < (uint)(1 << (*(int *)((int)&local_70->d + iVar11) - 1U & 0xff))) {
              uVar5 = 1;
              do {
                iVar13 = *(int *)((int)&local_68->d + iVar11);
                iVar9 = uVar5 * 4;
                iVar2 = uVar5 * 4;
                uVar5 = uVar5 + 1;
                pBVar8 = (BIGNUM *)
                         EC_POINT_add((EC_GROUP *)param_1,*(EC_POINT **)(iVar13 + iVar2),
                                      *(EC_POINT **)(iVar13 + iVar9 + -4),(EC_POINT *)pBVar7,param_7
                                     );
                if (pBVar8 == (BIGNUM *)0x0) goto LAB_0009000a;
              } while (uVar5 < (uint)(1 << (*(int *)((int)&local_70->d + iVar11) - 1U & 0xff)));
            }
          }
          iVar11 = iVar11 + 4;
        }
        pBVar8 = (BIGNUM *)
                 EC_POINTs_make_affine
                           ((EC_GROUP *)param_1,(size_t)local_3c,(EC_POINT **)local_4c,param_7);
        if (pBVar8 != (BIGNUM *)0x0) {
          pBVar8 = (BIGNUM *)0x1;
          local_78 = (ulong **)0x0;
          while (local_40 = (BIGNUM *)((int)&local_40[-1].flags + 3), -1 < (int)local_40) {
            if ((pBVar8 == (BIGNUM *)0x0) &&
               (iVar11 = EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_2,
                                      param_7), iVar11 == 0)) goto LAB_0009000a;
            pBVar19 = (BIGNUM *)0x0;
            if (local_50 != (BIGNUM *)0x0) {
              do {
                if ((local_40 < (BIGNUM *)(&local_64->d)[(int)pBVar19]) &&
                   (iVar11 = (int)(char)*(EC_POINT *)
                                         ((int)(&pBVar14->d)[(int)pBVar19] + (int)local_40),
                   iVar11 != 0)) {
                  iVar9 = iVar11 >> 0x1f;
                  if (iVar11 < 0) {
                    iVar11 = -iVar11;
                  }
                  if (-(int)local_78 != iVar9) {
                    if ((pBVar8 == (BIGNUM *)0x0) &&
                       (iVar9 = EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,param_7),
                       iVar9 == 0)) goto LAB_0009000a;
                    local_78 = (ulong **)((uint)local_78 ^ 1);
                  }
                  if (pBVar8 == (BIGNUM *)0x0) {
                    iVar11 = EC_POINT_add((EC_GROUP *)param_1,(EC_POINT *)param_2,
                                          (EC_POINT *)param_2,
                                          (EC_POINT *)(&local_68->d)[(int)pBVar19][iVar11 >> 1],
                                          param_7);
                    if (iVar11 == 0) goto LAB_0009000a;
                  }
                  else {
                    pBVar8 = (BIGNUM *)
                             EC_POINT_copy((EC_POINT *)param_2,
                                           (EC_POINT *)(&local_68->d)[(int)pBVar19][iVar11 >> 1]);
                    if (pBVar8 == (BIGNUM *)0x0) goto LAB_0009000a;
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
      ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x256);
      pBVar7 = (BIGNUM *)0x0;
      pBVar8 = (BIGNUM *)0x0;
    }
  }
LAB_0009000a:
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

