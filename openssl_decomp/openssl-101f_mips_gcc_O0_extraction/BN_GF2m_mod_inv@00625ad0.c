
uint BN_GF2m_mod_inv(undefined4 param_1,uint **param_2,uint **param_3,uint *param_4)

{
  uint uVar1;
  undefined *puVar2;
  uint **ppuVar3;
  uint **ppuVar4;
  uint **ppuVar5;
  uint **ppuVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  uint *puVar17;
  uint **ppuVar18;
  uint **ppuVar19;
  char *pcVar20;
  uint *puVar21;
  uint **ppuVar22;
  uint **ppuVar23;
  uint **ppuVar24;
  uint **ppuVar25;
  uint uVar26;
  uint *local_44 [6];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppuVar22 = param_2;
  ppuVar18 = param_3;
  pcVar20 = (char *)param_4;
  (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
  ppuVar3 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_4);
  if ((((ppuVar3 != (uint **)0x0) &&
       (ppuVar4 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_4), ppuVar4 != (uint **)0x0)) &&
      (ppuVar5 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_4), ppuVar5 != (uint **)0x0)) &&
     (ppuVar6 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_4), ppuVar6 != (uint **)0x0)) {
    puVar7 = param_3[1];
    if (puVar7 == (uint *)0x0) {
LAB_00625c2c:
      ppuVar18 = (uint **)&DAT_0000006a;
      pcVar20 = "bn_gf2m.c";
      ppuVar22 = (uint **)0x83;
      (*(code *)PTR_ERR_put_error_006a9030)(3,0x83,0x6a,"bn_gf2m.c",0x176);
    }
    else {
      if ((int)puVar7 + -1 < 0) {
        ppuVar22 = local_44;
LAB_00625cb0:
        *ppuVar22 = (uint *)0xffffffff;
      }
      else {
        ppuVar22 = (uint **)*param_3;
        iVar16 = 0;
        ppuVar18 = ppuVar22 + (int)puVar7;
        pcVar20 = (char *)(((int)puVar7 + -1) * 0x20 + -1);
        do {
          puVar7 = ppuVar18[-1];
          puVar11 = (uint *)((int)pcVar20 + 0x20);
          if (puVar7 != (uint *)0x0) {
            uVar13 = 0x80000000;
            while( true ) {
              if ((uVar13 & (uint)puVar7) != 0) {
                if (iVar16 < 6) {
                  local_44[iVar16] = puVar11;
                }
                iVar16 = iVar16 + 1;
              }
              puVar11 = (uint *)((int)puVar11 + -1);
              uVar13 = uVar13 >> 1;
              if (puVar11 == (uint *)pcVar20) break;
              puVar7 = ppuVar18[-1];
            }
          }
          ppuVar18 = ppuVar18 + -1;
          pcVar20 = (char *)((int)pcVar20 + -0x20);
        } while (ppuVar22 != ppuVar18);
        if (iVar16 < 6) {
          ppuVar22 = local_44 + iVar16;
          goto LAB_00625cb0;
        }
        if (6 < iVar16) goto LAB_00625c2c;
      }
      if (local_44[0] == (uint *)0x0) {
        ppuVar22 = (uint **)0x0;
        (*(code *)PTR_BN_set_word_006a8820)(ppuVar5,0);
      }
      else {
        if (ppuVar5 != param_2) {
          ppuVar22 = (uint **)param_2[1];
          if ((int)ppuVar5[2] < (int)ppuVar22) {
            iVar16 = (*(code *)PTR_bn_expand2_006a9680)(ppuVar5);
            if (iVar16 == 0) goto LAB_00625c54;
            ppuVar22 = (uint **)param_2[1];
          }
          iVar16 = 0;
          if (0 < (int)ppuVar22) {
            puVar11 = *param_2;
            puVar7 = *ppuVar5;
            do {
              iVar16 = iVar16 + 1;
              *puVar7 = *puVar11;
              ppuVar22 = (uint **)param_2[1];
              ppuVar18 = (uint **)(uint)(iVar16 < (int)ppuVar22);
              puVar11 = puVar11 + 1;
              puVar7 = puVar7 + 1;
            } while (ppuVar18 != (uint **)0x0);
          }
          ppuVar5[1] = (uint *)ppuVar22;
        }
        ppuVar22 = local_44;
        iVar16 = BN_GF2m_mod_arr_part_0(ppuVar5,ppuVar22);
        if (iVar16 == 0) goto LAB_00625c54;
      }
      if ((ppuVar5[1] != (uint *)0x0) &&
         (ppuVar22 = param_3, iVar16 = (*(code *)PTR_BN_copy_006a9570)(ppuVar6,param_3), iVar16 != 0
         )) {
        iVar16 = (*(code *)PTR_BN_num_bits_006a82f4)(ppuVar5);
        iVar9 = (*(code *)PTR_BN_num_bits_006a82f4)(ppuVar6);
        puVar7 = param_3[1];
        if ((int)ppuVar5[2] < (int)puVar7) {
          (*(code *)PTR_bn_expand2_006a9680)(ppuVar5,puVar7);
        }
        puVar8 = ppuVar5[1];
        puVar11 = *ppuVar5;
        if ((int)puVar8 < (int)puVar7) {
          ppuVar18 = (uint **)(((int)puVar7 - (int)puVar8) * 4);
          (*(code *)PTR_memset_006aab00)(puVar11 + (int)puVar8,0);
        }
        puVar8 = ppuVar3[2];
        ppuVar5[1] = puVar7;
        if ((int)puVar8 < (int)puVar7) {
          (*(code *)PTR_bn_expand2_006a9680)(ppuVar3,puVar7);
        }
        ppuVar23 = (uint **)*ppuVar3;
        *ppuVar23 = (uint *)0x1;
        if (1 < (int)puVar7) {
          ppuVar18 = (uint **)((int)puVar7 * 4 + -4);
          (*(code *)PTR_memset_006aab00)(ppuVar23 + 1,0);
        }
        puVar8 = ppuVar4[2];
        ppuVar3[1] = puVar7;
        if ((int)puVar8 < (int)puVar7) {
          (*(code *)PTR_bn_expand2_006a9680)(ppuVar4,puVar7);
        }
        ppuVar24 = (uint **)*ppuVar4;
        if (0 < (int)puVar7) {
          ppuVar18 = (uint **)((int)puVar7 << 2);
          (*(code *)PTR_memset_006aab00)(ppuVar24,0);
        }
        puVar8 = *ppuVar6;
        ppuVar4[1] = puVar7;
LAB_00625ea0:
        iVar10 = iVar9;
        uVar13 = *puVar11;
        ppuVar22 = ppuVar3;
        if (iVar16 != 0) goto LAB_00625fe8;
LAB_00625eac:
        ppuVar19 = ppuVar24;
        ppuVar25 = ppuVar6;
        puVar14 = puVar8;
        iVar9 = iVar10;
        if (uVar13 != 1) {
LAB_00625eb4:
          ppuVar24 = ppuVar19;
          ppuVar6 = ppuVar25;
          puVar8 = puVar14;
          ppuVar3 = ppuVar22;
          iVar10 = iVar16;
          if (iVar16 < iVar9) {
            ppuVar24 = (uint **)*ppuVar22;
            puVar8 = *ppuVar5;
            ppuVar23 = ppuVar19;
            ppuVar6 = ppuVar5;
            ppuVar3 = ppuVar4;
            ppuVar4 = ppuVar22;
            ppuVar5 = ppuVar25;
            iVar10 = iVar9;
            puVar11 = puVar14;
            iVar9 = iVar16;
          }
          if (0 < (int)puVar7) {
            puVar14 = puVar11;
            ppuVar22 = ppuVar23;
            ppuVar19 = ppuVar24;
            pcVar20 = (char *)puVar8;
            do {
              uVar13 = *(uint *)pcVar20;
              ppuVar18 = ppuVar19 + 1;
              puVar21 = puVar14 + 1;
              pcVar20 = (char *)((int)pcVar20 + 4);
              *puVar14 = *puVar14 ^ uVar13;
              *ppuVar22 = (uint *)((uint)*ppuVar22 ^ (uint)*ppuVar19);
              puVar14 = puVar21;
              ppuVar22 = ppuVar22 + 1;
              ppuVar19 = ppuVar18;
            } while (puVar21 != puVar11 + (int)puVar7);
          }
          iVar16 = iVar10;
          if (iVar10 != iVar9) goto LAB_00625ea0;
          iVar9 = iVar10 + -1;
          if (iVar10 + -1 < 0) {
            iVar9 = iVar10 + 0x1e;
          }
          iVar9 = iVar9 >> 5;
          puVar14 = puVar11 + iVar9;
          if (*puVar14 == 0) {
            while (iVar9 != 0) {
              iVar9 = iVar9 + -1;
              if (puVar14[-1] != 0) goto LAB_00625f90;
              puVar14 = puVar14 + -1;
            }
            iVar9 = 0;
          }
          else {
LAB_00625f90:
            iVar9 = iVar9 << 5;
          }
          iVar16 = (*(code *)PTR_BN_num_bits_word_006a96c0)();
          iVar16 = iVar16 + iVar9;
          uVar13 = *puVar11;
          ppuVar22 = ppuVar3;
          if (iVar16 == 0) goto LAB_00625eac;
LAB_00625fe8:
          iVar9 = iVar10;
          if ((uVar13 & 1) != 0) {
            ppuVar19 = ppuVar24;
            ppuVar25 = ppuVar6;
            puVar14 = puVar8;
            ppuVar22 = ppuVar3;
            if (iVar16 < 0x21) goto LAB_00625eac;
            goto LAB_00625eb4;
          }
          pcVar20 = (char *)*param_3;
          uVar1 = -((uint)*ppuVar23 & 1);
          uVar26 = uVar1 & *(uint *)pcVar20 ^ (uint)*ppuVar23;
          uVar15 = uVar13 & 1;
          if (0 < (int)puVar7 + -1) {
            uVar12 = uVar13;
            puVar14 = puVar11 + 1;
            ppuVar22 = ppuVar23 + 1;
            puVar21 = (uint *)((int)pcVar20 + 4);
            do {
              uVar13 = *puVar14;
              puVar17 = puVar14 + 1;
              pcVar20 = (char *)(puVar21 + 1);
              ppuVar18 = ppuVar22 + 1;
              uVar15 = uVar26 >> 1;
              puVar14[-1] = uVar12 >> 1 | uVar13 << 0x1f;
              uVar26 = uVar1 & *puVar21 ^ (uint)*ppuVar22;
              ppuVar22[-1] = (uint *)(uVar15 | uVar26 << 0x1f);
              uVar12 = uVar13;
              uVar15 = ((int)puVar7 + -1) * 4;
              puVar14 = puVar17;
              ppuVar22 = ppuVar18;
              puVar21 = (uint *)pcVar20;
            } while (puVar11 + (int)puVar7 != puVar17);
          }
          *(uint *)((int)puVar11 + uVar15) = uVar13 >> 1;
          iVar16 = iVar16 + -1;
          *(uint *)((int)ppuVar23 + uVar15) = uVar26 >> 1;
          goto LAB_00625ea0;
        }
        puVar7 = ppuVar22[1];
        if (0 < (int)puVar7) {
          puVar11 = *ppuVar22 + (int)puVar7 + -1;
          do {
            puVar8 = (uint *)((int)puVar7 + -1);
            if (*puVar11 != 0) break;
            puVar11 = puVar11 + -1;
            puVar7 = puVar8;
          } while (puVar8 != (uint *)0x0);
          ppuVar22[1] = puVar7;
        }
        iVar16 = (*(code *)PTR_BN_copy_006a9570)(param_1,ppuVar22);
        uVar13 = (uint)(iVar16 != 0);
        goto LAB_00625c58;
      }
    }
  }
LAB_00625c54:
  uVar13 = 0;
LAB_00625c58:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
  if (local_2c == *(int *)puVar2) {
    return uVar13;
  }
  iVar16 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  (*(code *)PTR_BN_CTX_start_006a9644)(pcVar20);
  iVar9 = (*(code *)PTR_BN_CTX_get_006a9648)(pcVar20);
  if (iVar9 == 0) {
LAB_00626298:
    uVar13 = 0;
  }
  else {
    (*(code *)PTR_BN_set_word_006a8820)(iVar9,0);
    puVar7 = *ppuVar18;
    while (puVar7 != (uint *)0xffffffff) {
      ppuVar18 = ppuVar18 + 1;
      iVar10 = (*(code *)PTR_BN_set_bit_006a9710)(iVar9);
      if (iVar10 == 0) goto LAB_00626298;
      puVar7 = *ppuVar18;
    }
    uVar13 = BN_GF2m_mod_inv(iVar16,ppuVar22,iVar9,pcVar20);
  }
  (*(code *)PTR_BN_CTX_end_006a9654)(pcVar20);
  return uVar13;
}

