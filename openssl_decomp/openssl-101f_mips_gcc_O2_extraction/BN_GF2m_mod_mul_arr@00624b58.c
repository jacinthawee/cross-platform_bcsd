
uint BN_GF2m_mod_mul_arr(uint **param_1,uint **param_2,uint **param_3,uint **param_4,
                        undefined4 param_5)

{
  undefined *puVar1;
  uint **ppuVar2;
  uint uVar3;
  uint **ppuVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  uint **ppuVar13;
  uint **ppuVar14;
  uint *puVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint **ppuVar20;
  int iVar21;
  uint *puVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  int local_74;
  uint *local_70;
  int local_6c;
  uint local_4c [7];
  uint local_30;
  uint **local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(uint ***)PTR___stack_chk_guard_006aabf0;
  ppuVar14 = param_4;
  if (param_2 == param_3) {
    if (local_2c == *(uint ***)PTR___stack_chk_guard_006aabf0) {
      (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
      ppuVar14 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
      if (ppuVar14 == (uint **)0x0) {
        return 0;
      }
      puVar7 = param_2[1];
      if ((int)ppuVar14[2] < (int)puVar7 << 1) {
        iVar21 = (*(code *)PTR_bn_expand2_006a9680)(ppuVar14);
        if (iVar21 != 0) {
          puVar7 = param_2[1];
          goto LAB_00624918;
        }
LAB_00624ac8:
        uVar3 = 0;
      }
      else {
LAB_00624918:
        if (0 < (int)puVar7) {
          puVar15 = *ppuVar14;
          puVar22 = *param_2 + (int)puVar7;
          puVar7 = puVar15 + (int)puVar7 * 2;
          do {
            uVar3 = puVar22[-1];
            puVar11 = puVar7 + -2;
            puVar22 = puVar22 + -1;
            puVar7[-1] = *(int *)(&SQR_tb + (uVar3 >> 0x1c) * 4) << 0x18 |
                         *(uint *)(&SQR_tb + ((uVar3 << 0xc) >> 0x1c) * 4) |
                         *(int *)(&SQR_tb + ((uVar3 << 4) >> 0x1c) * 4) << 0x10 |
                         *(int *)(&SQR_tb + ((uVar3 << 8) >> 0x1c) * 4) << 8;
            uVar3 = *puVar22;
            *puVar11 = *(int *)(&SQR_tb + ((uVar3 << 0x10) >> 0x1c) * 4) << 0x18 |
                       *(int *)(&SQR_tb + ((uVar3 << 0x14) >> 0x1c) * 4) << 0x10 |
                       *(uint *)(&SQR_tb + (uVar3 & 0xf) * 4) |
                       *(int *)(&SQR_tb + ((uVar3 << 0x18) >> 0x1c) * 4) << 8;
            puVar7 = puVar11;
          } while (puVar15 != puVar11);
          puVar7 = param_2[1];
        }
        puVar22 = (uint *)((int)puVar7 << 1);
        ppuVar14[1] = puVar22;
        if (0 < (int)puVar22) {
          puVar7 = *ppuVar14 + (int)puVar7 * 2 + -2;
          do {
            if (puVar7[1] != 0) break;
            puVar22 = (uint *)((int)puVar22 + -1);
            puVar7 = puVar7 + -1;
          } while (puVar22 != (uint *)0x0);
          ppuVar14[1] = puVar22;
        }
        if (*param_4 == (uint *)0x0) {
          uVar3 = 1;
          (*(code *)PTR_BN_set_word_006a8820)(param_1,0);
          goto LAB_00624acc;
        }
        if (ppuVar14 != param_1) {
          if ((int)param_1[2] < (int)puVar22) {
            iVar21 = (*(code *)PTR_bn_expand2_006a9680)(param_1);
            if (iVar21 == 0) goto LAB_00624ac8;
            puVar22 = ppuVar14[1];
          }
          iVar21 = 0;
          if (0 < (int)puVar22) {
            puVar15 = *ppuVar14;
            puVar7 = *param_1;
            do {
              iVar21 = iVar21 + 1;
              *puVar7 = *puVar15;
              puVar22 = ppuVar14[1];
              puVar15 = puVar15 + 1;
              puVar7 = puVar7 + 1;
            } while (iVar21 < (int)puVar22);
          }
          param_1[1] = puVar22;
        }
        iVar21 = BN_GF2m_mod_arr_part_0(param_1,param_4);
        uVar3 = (uint)(iVar21 != 0);
      }
LAB_00624acc:
      (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
      return uVar3;
    }
  }
  else {
    ppuVar4 = param_2;
    ppuVar13 = param_3;
    (*(code *)PTR_BN_CTX_start_006a9644)(param_5);
    ppuVar2 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_5);
    if ((ppuVar2 == (uint **)0x0) ||
       ((ppuVar20 = (uint **)((int)param_2[1] + (int)param_3[1] + 4),
        (int)ppuVar2[2] < (int)ppuVar20 &&
        (ppuVar4 = ppuVar20, iVar21 = (*(code *)PTR_bn_expand2_006a9680)(ppuVar2,ppuVar20),
        iVar21 == 0)))) {
LAB_006255f0:
      uVar3 = 0;
    }
    else {
      ppuVar2[1] = (uint *)ppuVar20;
      if ((int)ppuVar20 < 1) {
        puVar7 = param_3[1];
        if (0 < (int)puVar7) goto LAB_00624c44;
      }
      else {
        ppuVar13 = (uint **)((int)ppuVar20 * 4);
        (*(code *)PTR_memset_006aab00)(*ppuVar2,0,ppuVar13);
        puVar7 = param_3[1];
        if (0 < (int)puVar7) {
LAB_00624c44:
          local_6c = 0;
          local_74 = 0;
          ppuVar14 = (uint **)param_2[1];
          local_70 = *param_3;
          do {
            uVar3 = *local_70;
            if (puVar7 == (uint *)(local_74 + 1)) {
              uVar6 = 0;
            }
            else {
              uVar6 = local_70[1];
            }
            if (0 < (int)ppuVar14) {
              puVar22 = *param_2;
              puVar7 = (uint *)((int)*ppuVar2 + local_6c);
              uVar8 = uVar6 ^ uVar3;
              uVar18 = puVar7[1];
              uVar23 = *puVar7;
              iVar21 = 0;
              do {
                uVar12 = *puVar22;
                if (ppuVar14 == (uint **)(iVar21 + 1)) {
                  uVar19 = 0;
                  uVar24 = 0;
                  local_30 = 0;
                  local_4c[6] = 0;
                  local_4c[5] = 0;
                  local_4c[3] = 0;
                  local_4c[4] = 0;
                  local_4c[2] = 0;
                  local_4c[1] = 0;
                  uVar25 = 0;
                }
                else {
                  uVar25 = puVar22[1];
                  local_4c[1] = uVar25 & 0x3fffffff;
                  local_4c[2] = local_4c[1] << 1;
                  local_4c[4] = uVar25 << 2;
                  local_4c[3] = local_4c[1] ^ local_4c[2];
                  uVar24 = uVar25 >> 0x1e & 1;
                  local_4c[5] = local_4c[1] ^ local_4c[4];
                  local_4c[6] = local_4c[2] ^ local_4c[4];
                  local_30 = local_4c[4] ^ local_4c[3];
                  uVar19 = uVar25 >> 0x1e & 2;
                }
                local_4c[0] = 0;
                uVar9 = local_4c[(uVar6 << 2) >> 0x1d] << 0x1b ^
                        local_4c[uVar6 >> 0x1e] << 0x1e ^ local_4c[uVar6 & 7] ^
                        local_4c[(uVar6 << 0x1a) >> 0x1d] << 3 ^
                        local_4c[(uVar6 << 0x17) >> 0x1d] << 6 ^
                        local_4c[(uVar6 << 0x14) >> 0x1d] << 9 ^
                        local_4c[(uVar6 << 0x11) >> 0x1d] << 0xc ^
                        local_4c[(uVar6 << 0xe) >> 0x1d] << 0xf ^
                        local_4c[(uVar6 << 0xb) >> 0x1d] << 0x12 ^
                        local_4c[(uVar6 << 8) >> 0x1d] << 0x15 ^
                        local_4c[(uVar6 << 5) >> 0x1d] << 0x18;
                ppuVar13 = (uint **)(local_4c[(uVar6 << 2) >> 0x1d] >> 5 ^
                                    local_4c[(uVar6 << 0x17) >> 0x1d] >> 0x1a ^
                                    local_4c[(uVar6 << 0x1a) >> 0x1d] >> 0x1d ^
                                    local_4c[uVar6 >> 0x1e] >> 2 ^
                                    local_4c[(uVar6 << 0x14) >> 0x1d] >> 0x17 ^
                                    local_4c[(uVar6 << 0x11) >> 0x1d] >> 0x14 ^
                                    local_4c[(uVar6 << 0xe) >> 0x1d] >> 0x11 ^
                                    local_4c[(uVar6 << 0xb) >> 0x1d] >> 0xe ^
                                    local_4c[(uVar6 << 8) >> 0x1d] >> 0xb ^
                                    local_4c[(uVar6 << 5) >> 0x1d] >> 8);
                if (uVar24 != 0) {
                  uVar9 = uVar9 ^ uVar6 << 0x1e;
                  ppuVar13 = (uint **)((uint)ppuVar13 ^ uVar6 >> 2);
                }
                if (uVar19 != 0) {
                  uVar9 = uVar9 ^ uVar6 << 0x1f;
                  ppuVar13 = (uint **)((uint)ppuVar13 ^ uVar6 >> 1);
                }
                local_4c[1] = uVar12 & 0x3fffffff;
                local_4c[0] = 0;
                local_4c[4] = uVar12 << 2;
                local_4c[2] = local_4c[1] << 1;
                local_4c[3] = local_4c[1] ^ local_4c[2];
                local_4c[5] = local_4c[1] ^ local_4c[4];
                local_4c[6] = local_4c[2] ^ local_4c[4];
                local_30 = local_4c[4] ^ local_4c[1] ^ local_4c[2];
                uVar24 = local_4c[(uVar3 << 2) >> 0x1d] << 0x1b ^
                         local_4c[uVar3 >> 0x1e] << 0x1e ^ local_4c[uVar3 & 7] ^
                         local_4c[(uVar3 << 0x1a) >> 0x1d] << 3 ^
                         local_4c[(uVar3 << 0x17) >> 0x1d] << 6 ^
                         local_4c[(uVar3 << 0x14) >> 0x1d] << 9 ^
                         local_4c[(uVar3 << 0x11) >> 0x1d] << 0xc ^
                         local_4c[(uVar3 << 0xe) >> 0x1d] << 0xf ^
                         local_4c[(uVar3 << 0xb) >> 0x1d] << 0x12 ^
                         local_4c[(uVar3 << 8) >> 0x1d] << 0x15 ^
                         local_4c[(uVar3 << 5) >> 0x1d] << 0x18;
                uVar19 = local_4c[(uVar3 << 2) >> 0x1d] >> 5 ^
                         local_4c[(uVar3 << 0x17) >> 0x1d] >> 0x1a ^
                         local_4c[(uVar3 << 0x1a) >> 0x1d] >> 0x1d ^ local_4c[uVar3 >> 0x1e] >> 2 ^
                         local_4c[(uVar3 << 0x14) >> 0x1d] >> 0x17 ^
                         local_4c[(uVar3 << 0x11) >> 0x1d] >> 0x14 ^
                         local_4c[(uVar3 << 0xe) >> 0x1d] >> 0x11 ^
                         local_4c[(uVar3 << 0xb) >> 0x1d] >> 0xe ^
                         local_4c[(uVar3 << 8) >> 0x1d] >> 0xb ^ local_4c[(uVar3 << 5) >> 0x1d] >> 8
                ;
                if ((uVar12 >> 0x1e & 1) != 0) {
                  uVar24 = uVar24 ^ uVar3 << 0x1e;
                  uVar19 = uVar19 ^ uVar3 >> 2;
                }
                if ((uVar12 >> 0x1e & 2) != 0) {
                  uVar24 = uVar24 ^ uVar3 << 0x1f;
                  uVar19 = uVar19 ^ uVar3 >> 1;
                }
                uVar25 = uVar25 ^ uVar12;
                local_4c[0] = 0;
                local_4c[1] = uVar25 & 0x3fffffff;
                local_4c[2] = local_4c[1] << 1;
                local_4c[4] = uVar25 << 2;
                local_4c[3] = local_4c[1] ^ local_4c[2];
                local_4c[6] = local_4c[2] ^ local_4c[4];
                local_4c[5] = local_4c[1] ^ local_4c[4];
                local_30 = local_4c[4] ^ local_4c[1] ^ local_4c[2];
                uVar12 = local_4c[uVar8 >> 0x1e] << 0x1e ^ local_4c[uVar8 & 7] ^
                         local_4c[(uVar8 << 0x1a) >> 0x1d] << 3 ^
                         local_4c[(uVar8 << 0x17) >> 0x1d] << 6 ^
                         local_4c[(uVar8 << 0x14) >> 0x1d] << 9 ^
                         local_4c[(uVar8 << 0x11) >> 0x1d] << 0xc ^
                         local_4c[(uVar8 << 0xe) >> 0x1d] << 0xf ^
                         local_4c[(uVar8 << 0xb) >> 0x1d] << 0x12 ^
                         local_4c[(uVar8 << 8) >> 0x1d] << 0x15 ^
                         local_4c[(uVar8 << 5) >> 0x1d] << 0x18 ^
                         local_4c[(uVar8 << 2) >> 0x1d] << 0x1b;
                uVar16 = local_4c[(uVar8 << 0x17) >> 0x1d] >> 0x1a ^
                         local_4c[(uVar8 << 0x1a) >> 0x1d] >> 0x1d ^ local_4c[uVar8 >> 0x1e] >> 2 ^
                         local_4c[(uVar8 << 0x14) >> 0x1d] >> 0x17 ^
                         local_4c[(uVar8 << 0x11) >> 0x1d] >> 0x14 ^
                         local_4c[(uVar8 << 0xe) >> 0x1d] >> 0x11 ^
                         local_4c[(uVar8 << 0xb) >> 0x1d] >> 0xe ^
                         local_4c[(uVar8 << 8) >> 0x1d] >> 0xb ^ local_4c[(uVar8 << 5) >> 0x1d] >> 8
                         ^ local_4c[(uVar8 << 2) >> 0x1d] >> 5;
                if ((uVar25 >> 0x1e & 1) != 0) {
                  uVar12 = uVar12 ^ uVar8 << 0x1e;
                  uVar16 = uVar16 ^ uVar8 >> 2;
                }
                if ((uVar25 >> 0x1e & 2) != 0) {
                  uVar12 = uVar12 ^ uVar8 << 0x1f;
                  uVar16 = uVar16 ^ uVar8 >> 1;
                }
                uVar25 = (uint)ppuVar13 ^ uVar9 ^ uVar19 ^ uVar16;
                uVar19 = uVar24 ^ uVar23;
                puVar7[1] = (uint)ppuVar13 ^ uVar18 ^ uVar24 ^ uVar16 ^ uVar12 ^ uVar25;
                uVar23 = uVar25 ^ puVar7[2];
                *puVar7 = uVar19;
                uVar18 = (uint)ppuVar13 ^ puVar7[3];
                puVar7[2] = uVar23;
                iVar21 = iVar21 + 2;
                puVar7[3] = uVar18;
                puVar22 = puVar22 + 2;
                ppuVar14 = (uint **)param_2[1];
                puVar7 = puVar7 + 2;
              } while (iVar21 < (int)ppuVar14);
              puVar7 = param_3[1];
            }
            local_70 = local_70 + 2;
            local_74 = local_74 + 2;
            local_6c = local_6c + 8;
          } while (local_74 < (int)puVar7);
        }
        ppuVar20 = (uint **)ppuVar2[1];
        if (0 < (int)ppuVar20) {
          puVar7 = *ppuVar2 + (int)ppuVar20 + -1;
          do {
            ppuVar4 = (uint **)((int)ppuVar20 + -1);
            if (*puVar7 != 0) break;
            ppuVar20 = ppuVar4;
            puVar7 = puVar7 + -1;
          } while (ppuVar4 != (uint **)0x0);
          ppuVar2[1] = (uint *)ppuVar20;
        }
      }
      if (*param_4 == (uint *)0x0) {
        ppuVar4 = (uint **)0x0;
        uVar3 = 1;
        (*(code *)PTR_BN_set_word_006a8820)(param_1,0);
      }
      else {
        if (param_1 != ppuVar2) {
          if ((int)param_1[2] < (int)ppuVar20) {
            iVar21 = (*(code *)PTR_bn_expand2_006a9680)(param_1,ppuVar20);
            ppuVar4 = ppuVar20;
            if (iVar21 == 0) goto LAB_006255f0;
            ppuVar20 = (uint **)ppuVar2[1];
          }
          iVar21 = 0;
          if (0 < (int)ppuVar20) {
            puVar22 = *ppuVar2;
            puVar7 = *param_1;
            do {
              iVar21 = iVar21 + 1;
              *puVar7 = *puVar22;
              ppuVar20 = (uint **)ppuVar2[1];
              ppuVar13 = (uint **)(uint)(iVar21 < (int)ppuVar20);
              puVar22 = puVar22 + 1;
              puVar7 = puVar7 + 1;
              ppuVar14 = ppuVar2;
            } while (ppuVar13 != (uint **)0x0);
          }
          param_1[1] = (uint *)ppuVar20;
        }
        iVar21 = BN_GF2m_mod_arr_part_0(param_1,param_4);
        uVar3 = (uint)(iVar21 != 0);
        ppuVar4 = param_4;
      }
    }
    (*(code *)PTR_BN_CTX_end_006a9654)(param_5);
    param_1 = local_2c;
    param_2 = ppuVar4;
    param_4 = ppuVar13;
    if (local_2c == *(uint ***)puVar1) {
      return uVar3;
    }
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar21 = (*(code *)PTR_BN_num_bits_006a82f4)(ppuVar14);
  iVar21 = iVar21 + 1;
  iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar21 * 4,"bn_gf2m.c",0x1bf);
  if (iVar5 == 0) {
    return 0;
  }
  puVar7 = ppuVar14[1];
  if (puVar7 == (uint *)0x0) {
LAB_006257d4:
    uVar3 = 0;
  }
  else {
    if ((int)puVar7 + -1 < 0) {
      uVar3 = 1;
      if (0 < iVar21) {
        iVar17 = 0;
        goto LAB_00625850;
      }
      goto LAB_006257d4;
    }
    puVar22 = *ppuVar14;
    uVar3 = 0;
    puVar15 = puVar22 + (int)puVar7;
    iVar17 = ((int)puVar7 + -1) * 0x20 + -1;
    do {
      uVar6 = puVar15[-1];
      iVar10 = iVar17 + 0x20;
      if (uVar6 != 0) {
        uVar8 = 0x80000000;
        while( true ) {
          if ((uVar8 & uVar6) != 0) {
            if ((int)uVar3 < iVar21) {
              *(int *)(iVar5 + uVar3 * 4) = iVar10;
            }
            uVar3 = uVar3 + 1;
          }
          iVar10 = iVar10 + -1;
          uVar8 = uVar8 >> 1;
          if (iVar10 == iVar17) break;
          uVar6 = puVar15[-1];
        }
      }
      puVar15 = puVar15 + -1;
      iVar17 = iVar17 + -0x20;
    } while (puVar22 != puVar15);
    iVar17 = uVar3 << 2;
    if ((int)uVar3 < iVar21) {
      uVar3 = uVar3 + 1;
LAB_00625850:
      *(undefined4 *)(iVar5 + iVar17) = 0xffffffff;
    }
    else if (uVar3 == 0) goto LAB_006257d4;
    if ((int)uVar3 <= iVar21) {
      uVar3 = BN_GF2m_mod_mul_arr(param_1,param_2,param_4,iVar5,&_gp);
      goto LAB_006257fc;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(3,0x85,0x6a,"bn_gf2m.c",0x1c3);
LAB_006257fc:
  (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
  return uVar3;
}

