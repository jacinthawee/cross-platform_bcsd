
/* WARNING: Removing unreachable block (ram,0x081017bc) */
/* WARNING: Removing unreachable block (ram,0x081017cb) */
/* WARNING: Removing unreachable block (ram,0x081019c5) */
/* WARNING: Removing unreachable block (ram,0x081017e7) */
/* WARNING: Removing unreachable block (ram,0x081017fc) */
/* WARNING: Removing unreachable block (ram,0x081018da) */
/* WARNING: Removing unreachable block (ram,0x0810183e) */
/* WARNING: Removing unreachable block (ram,0x081019d7) */
/* WARNING: Removing unreachable block (ram,0x08101850) */
/* WARNING: Removing unreachable block (ram,0x081018e4) */
/* WARNING: Removing unreachable block (ram,0x0810185a) */
/* WARNING: Removing unreachable block (ram,0x08101991) */
/* WARNING: Removing unreachable block (ram,0x08101885) */
/* WARNING: Removing unreachable block (ram,0x0810189f) */
/* WARNING: Removing unreachable block (ram,0x081018a2) */
/* WARNING: Removing unreachable block (ram,0x08101962) */
/* WARNING: Removing unreachable block (ram,0x08101971) */
/* WARNING: Removing unreachable block (ram,0x081018b0) */
/* WARNING: Removing unreachable block (ram,0x08101943) */
/* WARNING: Removing unreachable block (ram,0x0810194e) */

uint ec_wNAF_mul(int *param_1,int *param_2,BIGNUM *param_3,uint param_4,int **param_5,int param_6,
                BN_CTX *param_7)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  EC_POINT *pEVar5;
  int iVar6;
  bool bVar7;
  uint *puVar8;
  EC_POINT **points;
  uint uVar9;
  void **ppvVar10;
  EC_POINT **ppEVar11;
  int in_GS_OFFSET;
  int iVar12;
  int *src;
  uint local_78;
  BN_CTX *local_74;
  void *local_6c;
  void **local_68;
  size_t local_64;
  uint local_60;
  int local_5c;
  uint *local_58;
  BN_CTX *local_54;
  void *local_50;
  uint local_4c;
  int local_48;
  int *local_40;
  int local_3c;
  
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  local_74 = param_7;
  if (*param_1 != *param_2) {
    iVar12 = 0x168;
LAB_08100f97:
    ERR_put_error(0x10,0xbb,0x65,"ec_mult.c",iVar12);
    uVar2 = 0;
    goto LAB_08100faf;
  }
  if ((param_3 == (BIGNUM *)0x0) && (param_4 == 0)) {
    uVar2 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
    goto LAB_08100faf;
  }
  if (param_4 != 0) {
    if (**param_5 == *param_1) {
      uVar2 = 0;
      do {
        uVar2 = uVar2 + 1;
        if (param_4 == uVar2) goto LAB_0810100a;
      } while (**param_5 == *param_5[uVar2]);
    }
    iVar12 = 0x172;
    goto LAB_08100f97;
  }
LAB_0810100a:
  local_54 = (BN_CTX *)0x0;
  if ((param_7 == (BN_CTX *)0x0) &&
     (local_74 = BN_CTX_new(), local_54 = local_74, local_74 == (BN_CTX *)0x0)) {
    local_50 = (void *)0x0;
    uVar2 = 0;
  }
  else {
    if (param_3 == (BIGNUM *)0x0) {
      local_4c = 0;
      iVar12 = 0;
      bVar7 = false;
      local_48 = 0;
      local_40 = (int *)0x0;
LAB_081010ab:
      local_3c = local_4c + param_4;
      iVar6 = local_3c * 4;
      local_6c = CRYPTO_malloc(iVar6,"ec_mult.c",0x1ad);
      local_58 = (uint *)CRYPTO_malloc(iVar6,"ec_mult.c",0x1ae);
      local_68 = (void **)CRYPTO_malloc(iVar6 + 4,"ec_mult.c",0x1af);
      local_50 = CRYPTO_malloc(iVar6,"ec_mult.c",0x1b1);
      if ((((local_68 == (void **)0x0) || (*local_68 = (void *)0x0, local_6c == (void *)0x0)) ||
          (local_58 == (uint *)0x0)) || (local_50 == (void *)0x0)) {
        points = (EC_POINT **)0x0;
        ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x1b8);
        if (local_54 != (BN_CTX *)0x0) goto LAB_081012b8;
        goto LAB_081012c7;
      }
      uVar2 = iVar12 + param_4;
      if (uVar2 == 0) {
        local_64 = 0;
        local_78 = 0;
      }
      else {
        uVar9 = 0;
        local_64 = 0;
        local_78 = 0;
        puVar8 = local_58;
        do {
          if (uVar9 < param_4) {
            uVar4 = BN_num_bits(*(BIGNUM **)(param_6 + uVar9 * 4));
            if (uVar4 < 2000) goto LAB_0810119d;
            local_64 = local_64 + 0x20;
            *(undefined4 *)((int)local_6c + uVar9 * 4) = 6;
            local_68[uVar9 + 1] = (void *)0x0;
          }
          else {
            uVar4 = BN_num_bits(param_3);
            if (uVar4 < 2000) {
LAB_0810119d:
              if (uVar4 < 800) {
                if (uVar4 < 300) {
                  if (uVar4 < 0x46) {
                    iVar12 = 2 - (uint)(uVar4 < 0x14);
                    local_5c = iVar12;
                  }
                  else {
                    local_5c = 4;
                    iVar12 = 3;
                  }
                }
                else {
                  local_5c = 8;
                  iVar12 = 4;
                }
              }
              else {
                local_5c = 0x10;
                iVar12 = 5;
              }
              *(int *)((int)local_6c + uVar9 * 4) = iVar12;
              local_64 = local_64 + local_5c;
              local_68[uVar9 + 1] = (void *)0x0;
            }
            else {
              local_64 = local_64 + 0x20;
              *(undefined4 *)((int)local_6c + uVar9 * 4) = 6;
              local_68[uVar9 + 1] = (void *)0x0;
            }
          }
          pvVar3 = (void *)compute_wNAF();
          local_68[uVar9] = pvVar3;
          if (pvVar3 == (void *)0x0) goto LAB_08101480;
          if (local_78 < *puVar8) {
            local_78 = *puVar8;
          }
          uVar9 = uVar9 + 1;
          puVar8 = puVar8 + 1;
        } while (uVar9 != uVar2);
      }
      if (local_4c == 0) {
LAB_0810166f:
        points = (EC_POINT **)CRYPTO_malloc(local_64 * 4 + 4,"ec_mult.c",0x243);
        if (points == (EC_POINT **)0x0) {
          ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x245);
          goto LAB_08101482;
        }
        points[local_64] = (EC_POINT *)0x0;
        ppEVar11 = points;
        if (uVar2 != 0) {
          uVar9 = 0;
          do {
            *(EC_POINT ***)((int)local_50 + uVar9 * 4) = ppEVar11;
            if (1 << ((char)*(undefined4 *)((int)local_6c + uVar9 * 4) - 1U & 0x1f) != 0) {
              uVar4 = 0;
              do {
                pEVar5 = EC_POINT_new((EC_GROUP *)param_1);
                *ppEVar11 = pEVar5;
                if (pEVar5 == (EC_POINT *)0x0) goto LAB_08101482;
                uVar4 = uVar4 + 1;
                ppEVar11 = ppEVar11 + 1;
              } while (uVar4 < (uint)(1 << ((char)*(undefined4 *)((int)local_6c + uVar9 * 4) - 1U &
                                           0x1f)));
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 != uVar2);
        }
        if (points + local_64 != ppEVar11) {
          ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x256);
          goto LAB_08101482;
        }
        pEVar5 = EC_POINT_new((EC_GROUP *)param_1);
        if (pEVar5 == (EC_POINT *)0x0) goto LAB_08101482;
        for (uVar9 = 0; uVar9 != uVar2; uVar9 = uVar9 + 1) {
          src = local_40;
          if (uVar9 < param_4) {
            src = param_5[uVar9];
          }
          iVar12 = EC_POINT_copy(**(EC_POINT ***)((int)local_50 + uVar9 * 4),(EC_POINT *)src);
          if (iVar12 == 0) goto LAB_081013ba;
          if (1 < *(uint *)((int)local_6c + uVar9 * 4)) {
            iVar12 = EC_POINT_dbl((EC_GROUP *)param_1,pEVar5,
                                  **(EC_POINT ***)((int)local_50 + uVar9 * 4),local_74);
            if (iVar12 == 0) goto LAB_081013ba;
            if (1 < (uint)(1 << ((char)*(undefined4 *)((int)local_6c + uVar9 * 4) - 1U & 0x1f))) {
              uVar4 = 1;
              do {
                iVar12 = *(int *)((int)local_50 + uVar9 * 4);
                iVar12 = EC_POINT_add((EC_GROUP *)param_1,
                                      *(EC_POINT **)(iVar12 + 4 + (uVar4 + 0x3fffffff) * 4),
                                      *(EC_POINT **)(iVar12 + (uVar4 + 0x3fffffff) * 4),pEVar5,
                                      local_74);
                if (iVar12 == 0) goto LAB_081013ba;
                uVar4 = uVar4 + 1;
              } while (uVar4 < (uint)(1 << ((char)*(undefined4 *)((int)local_6c + uVar9 * 4) - 1U &
                                           0x1f)));
            }
          }
        }
        iVar12 = EC_POINTs_make_affine((EC_GROUP *)param_1,local_64,points,local_74);
        if (iVar12 == 0) {
LAB_081013ba:
          uVar2 = 0;
        }
        else {
          bVar7 = true;
          local_64 = 0;
          while (local_60 = local_78 - 1, -1 < (int)local_60) {
            if ((!bVar7) &&
               (iVar12 = EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_2,
                                      local_74), iVar12 == 0)) goto LAB_081013ba;
            iVar12 = 0;
            local_78 = local_60;
            if (local_3c != 0) {
              do {
                if ((local_60 < local_58[iVar12]) &&
                   (uVar2 = (uint)*(char *)((int)local_68[iVar12] + local_60), uVar2 != 0)) {
                  if (local_64 != uVar2 >> 0x1f) {
                    if ((!bVar7) &&
                       (iVar6 = EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,local_74),
                       iVar6 == 0)) goto LAB_081013ba;
                    local_64 = local_64 ^ 1;
                  }
                  iVar6 = (int)((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f)) >> 1;
                  if (bVar7) {
                    iVar6 = EC_POINT_copy((EC_POINT *)param_2,
                                          *(EC_POINT **)
                                           (*(int *)((int)local_50 + iVar12 * 4) + iVar6 * 4));
                    if (iVar6 == 0) goto LAB_081013ba;
                    bVar7 = false;
                  }
                  else {
                    iVar6 = EC_POINT_add((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_2
                                         ,*(EC_POINT **)
                                           (*(int *)((int)local_50 + iVar12 * 4) + iVar6 * 4),
                                         local_74);
                    if (iVar6 == 0) goto LAB_081013ba;
                  }
                }
                iVar12 = iVar12 + 1;
              } while (local_3c != iVar12);
            }
          }
          if (bVar7) {
            iVar12 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
            uVar2 = (uint)(iVar12 != 0);
          }
          else {
            uVar2 = 1;
            if (local_64 != 0) {
              iVar12 = EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,local_74);
              uVar2 = (uint)(iVar12 != 0);
            }
          }
        }
        if (local_54 != (BN_CTX *)0x0) {
          BN_CTX_free(local_54);
        }
        EC_POINT_free(pEVar5);
      }
      else {
        if (local_48 == 0) {
          if (bVar7) goto LAB_0810166f;
          points = (EC_POINT **)0x0;
          ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x1d6);
        }
        else {
          if (bVar7) {
            ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x1df);
          }
          else {
            *(undefined4 *)((int)local_6c + param_4 * 4) = *(undefined4 *)(local_48 + 0xc);
            pvVar3 = (void *)compute_wNAF();
            if (pvVar3 != (void *)0x0) {
              local_3c = param_4 + 1;
              local_68[param_4] = pvVar3;
              local_68[param_4 + 1] = (void *)0x0;
              local_58[param_4] = 0;
              *(undefined4 *)((int)local_50 + param_4 * 4) = *(undefined4 *)(local_48 + 0x10);
              goto LAB_0810166f;
            }
          }
LAB_08101480:
          points = (EC_POINT **)0x0;
        }
LAB_08101482:
        if (local_54 != (BN_CTX *)0x0) goto LAB_081012b8;
        uVar2 = 0;
      }
LAB_081013e1:
      CRYPTO_free(local_6c);
    }
    else {
      local_40 = (int *)EC_GROUP_get0_generator((EC_GROUP *)param_1);
      if (local_40 != (int *)0x0) {
        local_48 = EC_EX_DATA_get_data(param_1[0x11],ec_pre_comp_dup,ec_pre_comp_free,
                                       ec_pre_comp_clear_free);
        if (local_48 == 0) {
          local_4c = 1;
          iVar12 = 1;
          bVar7 = true;
        }
        else if ((*(int *)(local_48 + 8) == 0) ||
                (iVar12 = EC_POINT_cmp((EC_GROUP *)param_1,(EC_POINT *)local_40,
                                       **(EC_POINT ***)(local_48 + 0x10),local_74), iVar12 != 0)) {
          local_4c = 1;
          iVar12 = 1;
          bVar7 = true;
          local_48 = 0;
        }
        else {
          uVar2 = *(uint *)(local_48 + 4);
          uVar9 = BN_num_bits(param_3);
          local_4c = *(uint *)(local_48 + 8);
          if (*(int *)(local_48 + 0x14) !=
              (1 << ((char)*(undefined4 *)(local_48 + 0xc) - 1U & 0x1f)) * local_4c) {
            ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x19f);
            goto LAB_0810158e;
          }
          bVar7 = false;
          uVar2 = uVar9 / uVar2 + 1;
          if (uVar2 <= local_4c) {
            local_4c = uVar2;
          }
          iVar12 = 0;
        }
        goto LAB_081010ab;
      }
      ERR_put_error(0x10,0xbb,0x71,"ec_mult.c",0x180);
LAB_0810158e:
      if (local_54 == (BN_CTX *)0x0) {
        uVar2 = 0;
        local_50 = (void *)0x0;
        goto LAB_08101359;
      }
      local_50 = (void *)0x0;
      points = (EC_POINT **)0x0;
      local_58 = (uint *)0x0;
      local_68 = (void **)0x0;
      local_6c = (void *)0x0;
LAB_081012b8:
      BN_CTX_free(local_54);
LAB_081012c7:
      uVar2 = 0;
      if (local_6c != (void *)0x0) goto LAB_081013e1;
    }
    if (local_58 != (uint *)0x0) {
      CRYPTO_free(local_58);
    }
    if (local_68 != (void **)0x0) {
      pvVar3 = *local_68;
      ppvVar10 = local_68;
      while (pvVar3 != (void *)0x0) {
        ppvVar10 = ppvVar10 + 1;
        CRYPTO_free(pvVar3);
        pvVar3 = *ppvVar10;
      }
      CRYPTO_free(local_68);
    }
    if (points != (EC_POINT **)0x0) {
      pEVar5 = *points;
      ppEVar11 = points;
      while (pEVar5 != (EC_POINT *)0x0) {
        ppEVar11 = ppEVar11 + 1;
        EC_POINT_clear_free(pEVar5);
        pEVar5 = *ppEVar11;
      }
      CRYPTO_free(points);
    }
  }
LAB_08101359:
  if (local_50 != (void *)0x0) {
    CRYPTO_free(local_50);
  }
LAB_08100faf:
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

