
/* WARNING: Removing unreachable block (ram,0x081032ec) */
/* WARNING: Removing unreachable block (ram,0x081032fb) */
/* WARNING: Removing unreachable block (ram,0x081034f5) */
/* WARNING: Removing unreachable block (ram,0x08103317) */
/* WARNING: Removing unreachable block (ram,0x0810332c) */
/* WARNING: Removing unreachable block (ram,0x0810340a) */
/* WARNING: Removing unreachable block (ram,0x0810336e) */
/* WARNING: Removing unreachable block (ram,0x08103507) */
/* WARNING: Removing unreachable block (ram,0x08103380) */
/* WARNING: Removing unreachable block (ram,0x08103414) */
/* WARNING: Removing unreachable block (ram,0x0810338a) */
/* WARNING: Removing unreachable block (ram,0x081034c1) */
/* WARNING: Removing unreachable block (ram,0x081033b5) */
/* WARNING: Removing unreachable block (ram,0x081033cf) */
/* WARNING: Removing unreachable block (ram,0x081033d2) */
/* WARNING: Removing unreachable block (ram,0x08103492) */
/* WARNING: Removing unreachable block (ram,0x081034a1) */
/* WARNING: Removing unreachable block (ram,0x081033e0) */
/* WARNING: Removing unreachable block (ram,0x08103473) */
/* WARNING: Removing unreachable block (ram,0x0810347e) */

uint ec_wNAF_mul(int *param_1,int *param_2,BIGNUM *param_3,uint param_4,int **param_5,int param_6,
                BN_CTX *param_7)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  void *pvVar4;
  uint uVar5;
  EC_POINT *pEVar6;
  int iVar7;
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
    iVar12 = 0x176;
LAB_08102ab7:
    ERR_put_error(0x10,0xbb,0x65,"ec_mult.c",iVar12);
    uVar3 = 0;
    goto LAB_08102acf;
  }
  if ((param_3 == (BIGNUM *)0x0) && (param_4 == 0)) {
    uVar3 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
    goto LAB_08102acf;
  }
  if (param_4 != 0) {
    if (**param_5 == *param_1) {
      uVar3 = 0;
      do {
        uVar3 = uVar3 + 1;
        if (param_4 == uVar3) goto LAB_08102b2a;
      } while (**param_5 == *param_5[uVar3]);
    }
    iVar12 = 0x183;
    goto LAB_08102ab7;
  }
LAB_08102b2a:
  local_54 = (BN_CTX *)0x0;
  if ((param_7 == (BN_CTX *)0x0) &&
     (local_74 = BN_CTX_new(), local_54 = local_74, local_74 == (BN_CTX *)0x0)) {
    local_50 = (void *)0x0;
    uVar3 = 0;
  }
  else {
    if (param_3 == (BIGNUM *)0x0) {
      local_4c = 0;
      iVar12 = 0;
      bVar2 = false;
      local_48 = 0;
      local_40 = (int *)0x0;
LAB_08102bcb:
      local_3c = local_4c + param_4;
      iVar7 = local_3c * 4;
      local_6c = CRYPTO_malloc(iVar7,"ec_mult.c",0x1bc);
      local_58 = (uint *)CRYPTO_malloc(iVar7,"ec_mult.c",0x1bd);
      local_68 = (void **)CRYPTO_malloc(iVar7 + 4,"ec_mult.c",0x1be);
      local_50 = CRYPTO_malloc(iVar7,"ec_mult.c",0x1bf);
      if ((((local_6c == (void *)0x0) || (local_58 == (uint *)0x0)) || (local_68 == (void **)0x0))
         || (local_50 == (void *)0x0)) {
        points = (EC_POINT **)0x0;
        ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x1c3);
        if (local_54 != (BN_CTX *)0x0) goto LAB_08102de8;
        goto LAB_08102df7;
      }
      uVar3 = iVar12 + param_4;
      *local_68 = (void *)0x0;
      if (uVar3 == 0) {
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
            uVar5 = BN_num_bits(*(BIGNUM **)(param_6 + uVar9 * 4));
            if (uVar5 < 2000) goto LAB_08102cc5;
            local_64 = local_64 + 0x20;
            *(undefined4 *)((int)local_6c + uVar9 * 4) = 6;
            local_68[uVar9 + 1] = (void *)0x0;
          }
          else {
            uVar5 = BN_num_bits(param_3);
            if (uVar5 < 2000) {
LAB_08102cc5:
              if (uVar5 < 800) {
                if (uVar5 < 300) {
                  if (uVar5 < 0x46) {
                    iVar12 = 2 - (uint)(uVar5 < 0x14);
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
          pvVar4 = (void *)compute_wNAF();
          local_68[uVar9] = pvVar4;
          if (pvVar4 == (void *)0x0) goto LAB_08102fb0;
          if (local_78 < *puVar8) {
            local_78 = *puVar8;
          }
          uVar9 = uVar9 + 1;
          puVar8 = puVar8 + 1;
        } while (uVar9 != uVar3);
      }
      if (local_4c == 0) {
LAB_0810319f:
        points = (EC_POINT **)CRYPTO_malloc(local_64 * 4 + 4,"ec_mult.c",0x250);
        if (points == (EC_POINT **)0x0) {
          ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x253);
          goto LAB_08102fb2;
        }
        points[local_64] = (EC_POINT *)0x0;
        ppEVar11 = points;
        if (uVar3 != 0) {
          uVar9 = 0;
          do {
            *(EC_POINT ***)((int)local_50 + uVar9 * 4) = ppEVar11;
            if (1 << ((char)*(undefined4 *)((int)local_6c + uVar9 * 4) - 1U & 0x1f) != 0) {
              uVar5 = 0;
              do {
                pEVar6 = EC_POINT_new((EC_GROUP *)param_1);
                *ppEVar11 = pEVar6;
                if (pEVar6 == (EC_POINT *)0x0) goto LAB_08102fb2;
                uVar5 = uVar5 + 1;
                ppEVar11 = ppEVar11 + 1;
              } while (uVar5 < (uint)(1 << ((char)*(undefined4 *)((int)local_6c + uVar9 * 4) - 1U &
                                           0x1f)));
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 != uVar3);
        }
        if (points + local_64 != ppEVar11) {
          ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x266);
          goto LAB_08102fb2;
        }
        pEVar6 = EC_POINT_new((EC_GROUP *)param_1);
        if (pEVar6 == (EC_POINT *)0x0) goto LAB_08102fb2;
        for (uVar9 = 0; uVar9 != uVar3; uVar9 = uVar9 + 1) {
          src = local_40;
          if (uVar9 < param_4) {
            src = param_5[uVar9];
          }
          iVar12 = EC_POINT_copy(**(EC_POINT ***)((int)local_50 + uVar9 * 4),(EC_POINT *)src);
          if (iVar12 == 0) goto LAB_08102eea;
          if (1 < *(uint *)((int)local_6c + uVar9 * 4)) {
            iVar12 = EC_POINT_dbl((EC_GROUP *)param_1,pEVar6,
                                  **(EC_POINT ***)((int)local_50 + uVar9 * 4),local_74);
            if (iVar12 == 0) goto LAB_08102eea;
            if (1 < (uint)(1 << ((char)*(undefined4 *)((int)local_6c + uVar9 * 4) - 1U & 0x1f))) {
              uVar5 = 1;
              do {
                iVar12 = *(int *)((int)local_50 + uVar9 * 4);
                iVar12 = EC_POINT_add((EC_GROUP *)param_1,
                                      *(EC_POINT **)(iVar12 + 4 + (uVar5 + 0x3fffffff) * 4),
                                      *(EC_POINT **)(iVar12 + (uVar5 + 0x3fffffff) * 4),pEVar6,
                                      local_74);
                if (iVar12 == 0) goto LAB_08102eea;
                uVar5 = uVar5 + 1;
              } while (uVar5 < (uint)(1 << ((char)*(undefined4 *)((int)local_6c + uVar9 * 4) - 1U &
                                           0x1f)));
            }
          }
        }
        iVar12 = EC_POINTs_make_affine((EC_GROUP *)param_1,local_64,points,local_74);
        if (iVar12 == 0) {
LAB_08102eea:
          uVar3 = 0;
        }
        else {
          bVar2 = true;
          local_60 = 0;
          while (local_64 = local_78 - 1, -1 < (int)local_64) {
            if ((!bVar2) &&
               (iVar12 = EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_2,
                                      local_74), iVar12 == 0)) goto LAB_08102eea;
            iVar12 = 0;
            local_78 = local_64;
            if (local_3c != 0) {
              do {
                if ((local_64 < local_58[iVar12]) &&
                   (uVar3 = (uint)*(char *)((int)local_68[iVar12] + local_64), uVar3 != 0)) {
                  uVar9 = (int)uVar3 >> 0x1f;
                  if (-uVar9 != local_60) {
                    if ((!bVar2) &&
                       (iVar7 = EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,local_74),
                       iVar7 == 0)) goto LAB_08102eea;
                    local_60 = local_60 ^ 1;
                  }
                  iVar7 = (int)((uVar9 ^ uVar3) - uVar9) >> 1;
                  if (bVar2) {
                    iVar7 = EC_POINT_copy((EC_POINT *)param_2,
                                          *(EC_POINT **)
                                           (*(int *)((int)local_50 + iVar12 * 4) + iVar7 * 4));
                    if (iVar7 == 0) goto LAB_08102eea;
                    bVar2 = false;
                  }
                  else {
                    iVar7 = EC_POINT_add((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_2
                                         ,*(EC_POINT **)
                                           (*(int *)((int)local_50 + iVar12 * 4) + iVar7 * 4),
                                         local_74);
                    if (iVar7 == 0) goto LAB_08102eea;
                  }
                }
                iVar12 = iVar12 + 1;
              } while (local_3c != iVar12);
            }
          }
          if (bVar2) {
            iVar12 = EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
            uVar3 = (uint)(iVar12 != 0);
          }
          else {
            uVar3 = 1;
            if (local_60 != 0) {
              iVar12 = EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,local_74);
              uVar3 = (uint)(iVar12 != 0);
            }
          }
        }
        if (local_54 != (BN_CTX *)0x0) {
          BN_CTX_free(local_54);
        }
        EC_POINT_free(pEVar6);
      }
      else {
        if (local_48 == 0) {
          if (bVar2) goto LAB_0810319f;
          points = (EC_POINT **)0x0;
          ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x1e3);
        }
        else {
          if (bVar2) {
            ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x1ef);
          }
          else {
            *(undefined4 *)((int)local_6c + param_4 * 4) = *(undefined4 *)(local_48 + 0xc);
            pvVar4 = (void *)compute_wNAF();
            if (pvVar4 != (void *)0x0) {
              local_3c = param_4 + 1;
              local_68[param_4] = pvVar4;
              local_68[param_4 + 1] = (void *)0x0;
              local_58[param_4] = 0;
              *(undefined4 *)((int)local_50 + param_4 * 4) = *(undefined4 *)(local_48 + 0x10);
              goto LAB_0810319f;
            }
          }
LAB_08102fb0:
          points = (EC_POINT **)0x0;
        }
LAB_08102fb2:
        if (local_54 != (BN_CTX *)0x0) goto LAB_08102de8;
        uVar3 = 0;
      }
LAB_08102f11:
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
          bVar2 = true;
        }
        else if ((*(int *)(local_48 + 8) == 0) ||
                (iVar12 = EC_POINT_cmp((EC_GROUP *)param_1,(EC_POINT *)local_40,
                                       **(EC_POINT ***)(local_48 + 0x10),local_74), iVar12 != 0)) {
          local_4c = 1;
          iVar12 = 1;
          bVar2 = true;
          local_48 = 0;
        }
        else {
          uVar3 = *(uint *)(local_48 + 4);
          uVar9 = BN_num_bits(param_3);
          local_4c = *(uint *)(local_48 + 8);
          if (*(int *)(local_48 + 0x14) !=
              (1 << ((char)*(undefined4 *)(local_48 + 0xc) - 1U & 0x1f)) * local_4c) {
            ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x1ad);
            goto LAB_081030be;
          }
          bVar2 = false;
          uVar3 = uVar9 / uVar3 + 1;
          if (uVar3 <= local_4c) {
            local_4c = uVar3;
          }
          iVar12 = 0;
        }
        goto LAB_08102bcb;
      }
      ERR_put_error(0x10,0xbb,0x71,"ec_mult.c",0x194);
LAB_081030be:
      if (local_54 == (BN_CTX *)0x0) {
        uVar3 = 0;
        local_50 = (void *)0x0;
        goto LAB_08102e89;
      }
      local_50 = (void *)0x0;
      points = (EC_POINT **)0x0;
      local_58 = (uint *)0x0;
      local_68 = (void **)0x0;
      local_6c = (void *)0x0;
LAB_08102de8:
      BN_CTX_free(local_54);
LAB_08102df7:
      uVar3 = 0;
      if (local_6c != (void *)0x0) goto LAB_08102f11;
    }
    if (local_58 != (uint *)0x0) {
      CRYPTO_free(local_58);
    }
    if (local_68 != (void **)0x0) {
      pvVar4 = *local_68;
      ppvVar10 = local_68;
      while (pvVar4 != (void *)0x0) {
        ppvVar10 = ppvVar10 + 1;
        CRYPTO_free(pvVar4);
        pvVar4 = *ppvVar10;
      }
      CRYPTO_free(local_68);
    }
    if (points != (EC_POINT **)0x0) {
      pEVar6 = *points;
      ppEVar11 = points;
      while (pEVar6 != (EC_POINT *)0x0) {
        ppEVar11 = ppEVar11 + 1;
        EC_POINT_clear_free(pEVar6);
        pEVar6 = *ppEVar11;
      }
      CRYPTO_free(points);
    }
  }
LAB_08102e89:
  if (local_50 != (void *)0x0) {
    CRYPTO_free(local_50);
  }
LAB_08102acf:
  if (iVar1 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

