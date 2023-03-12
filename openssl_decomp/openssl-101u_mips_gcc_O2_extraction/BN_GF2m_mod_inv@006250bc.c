
uint BN_GF2m_mod_inv(undefined4 param_1,uint **param_2,uint **param_3,uint **param_4)

{
  undefined *puVar1;
  uint **ppuVar2;
  uint **ppuVar3;
  uint **ppuVar4;
  uint **ppuVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  uint **ppuVar10;
  uint **ppuVar11;
  uint uVar12;
  uint *puVar13;
  uint **ppuVar14;
  uint uVar15;
  int iVar16;
  uint **ppuVar17;
  uint **ppuVar18;
  char *pcVar19;
  uint **ppuVar20;
  uint **ppuVar21;
  uint **ppuVar22;
  uint **ppuVar23;
  uint uVar24;
  uint **ppuVar25;
  int iVar26;
  uint **ppuVar27;
  uint *local_44 [6];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuVar20 = param_2;
  ppuVar17 = param_3;
  pcVar19 = (char *)param_4;
  (*(code *)PTR_BN_CTX_start_006a8528)(param_4);
  ppuVar2 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(param_4);
  if ((((ppuVar2 != (uint **)0x0) &&
       (ppuVar3 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(param_4), ppuVar3 != (uint **)0x0)) &&
      (ppuVar4 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(param_4), ppuVar4 != (uint **)0x0)) &&
     (ppuVar5 = (uint **)(*(code *)PTR_BN_CTX_get_006a852c)(param_4), ppuVar5 != (uint **)0x0)) {
    puVar6 = param_3[1];
    if (puVar6 == (uint *)0x0) {
LAB_00625218:
      ppuVar17 = (uint **)&DAT_0000006a;
      pcVar19 = "bn_gf2m.c";
      ppuVar20 = (uint **)0x83;
      (*(code *)PTR_ERR_put_error_006a7f34)(3,0x83,0x6a,"bn_gf2m.c",0x1de);
    }
    else {
      if ((int)puVar6 + -1 < 0) {
        ppuVar20 = local_44;
LAB_0062529c:
        *ppuVar20 = (uint *)0xffffffff;
      }
      else {
        ppuVar20 = (uint **)*param_3;
        iVar16 = 0;
        ppuVar17 = ppuVar20 + (int)puVar6;
        pcVar19 = (char *)(((int)puVar6 + -1) * 0x20 + -1);
        do {
          puVar6 = ppuVar17[-1];
          ppuVar10 = (uint **)((int)pcVar19 + 0x20);
          if (puVar6 != (uint *)0x0) {
            uVar12 = 0x80000000;
            while( true ) {
              if ((uVar12 & (uint)puVar6) != 0) {
                if (iVar16 < 6) {
                  local_44[iVar16] = (uint *)ppuVar10;
                }
                iVar16 = iVar16 + 1;
              }
              ppuVar10 = (uint **)((int)ppuVar10 + -1);
              uVar12 = uVar12 >> 1;
              if (ppuVar10 == (uint **)pcVar19) break;
              puVar6 = ppuVar17[-1];
            }
          }
          ppuVar17 = ppuVar17 + -1;
          pcVar19 = (char *)((int)pcVar19 + -0x20);
        } while (ppuVar20 != ppuVar17);
        if (iVar16 < 6) {
          ppuVar20 = local_44 + iVar16;
          goto LAB_0062529c;
        }
        if (6 < iVar16) goto LAB_00625218;
      }
      if (local_44[0] == (uint *)0x0) {
        ppuVar20 = (uint **)0x0;
        (*(code *)PTR_BN_set_word_006a7730)(ppuVar4,0);
      }
      else {
        if (ppuVar4 != param_2) {
          ppuVar20 = (uint **)param_2[1];
          if ((int)ppuVar4[2] < (int)ppuVar20) {
            iVar16 = (*(code *)PTR_bn_expand2_006a8524)(ppuVar4);
            if (iVar16 == 0) goto LAB_00625240;
            ppuVar20 = (uint **)param_2[1];
          }
          iVar16 = 0;
          if (0 < (int)ppuVar20) {
            puVar13 = *param_2;
            puVar6 = *ppuVar4;
            do {
              iVar16 = iVar16 + 1;
              *puVar6 = *puVar13;
              ppuVar20 = (uint **)param_2[1];
              ppuVar17 = (uint **)(uint)(iVar16 < (int)ppuVar20);
              puVar13 = puVar13 + 1;
              puVar6 = puVar6 + 1;
            } while (ppuVar17 != (uint **)0x0);
          }
          ppuVar4[1] = (uint *)ppuVar20;
        }
        ppuVar20 = local_44;
        iVar16 = BN_GF2m_mod_arr_part_0(ppuVar4,ppuVar20);
        if (iVar16 == 0) goto LAB_00625240;
      }
      if ((ppuVar4[1] != (uint *)0x0) &&
         (ppuVar20 = param_3, iVar16 = (*(code *)PTR_BN_copy_006a8450)(ppuVar5,param_3), iVar16 != 0
         )) {
        iVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(ppuVar4);
        iVar16 = (*(code *)PTR_BN_num_bits_006a71f4)(ppuVar5);
        ppuVar10 = (uint **)param_3[1];
        if ((int)ppuVar4[2] < (int)ppuVar10) {
          ppuVar20 = ppuVar10;
          iVar9 = (*(code *)PTR_bn_expand2_006a8524)(ppuVar4,ppuVar10);
          if (iVar9 == 0) goto LAB_00625240;
          puVar6 = ppuVar4[1];
        }
        else {
          puVar6 = ppuVar4[1];
        }
        ppuVar27 = (uint **)*ppuVar4;
        if ((int)puVar6 < (int)ppuVar10) {
          ppuVar17 = (uint **)(((int)ppuVar10 - (int)puVar6) * 4);
          ppuVar20 = (uint **)0x0;
          (*(code *)PTR_memset_006a99f4)(ppuVar27 + (int)puVar6,0);
        }
        puVar6 = ppuVar2[2];
        ppuVar4[1] = (uint *)ppuVar10;
        if ((int)puVar6 < (int)ppuVar10) {
          ppuVar20 = ppuVar10;
          iVar9 = (*(code *)PTR_bn_expand2_006a8524)(ppuVar2,ppuVar10);
          if (iVar9 == 0) goto LAB_00625240;
          ppuVar21 = (uint **)*ppuVar2;
        }
        else {
          ppuVar21 = (uint **)*ppuVar2;
        }
        *ppuVar21 = (uint *)0x1;
        if (1 < (int)ppuVar10) {
          ppuVar20 = (uint **)0x0;
          ppuVar17 = (uint **)((int)ppuVar10 * 4 + -4);
          (*(code *)PTR_memset_006a99f4)(ppuVar21 + 1,0);
        }
        puVar6 = ppuVar3[2];
        ppuVar2[1] = (uint *)ppuVar10;
        if ((int)puVar6 < (int)ppuVar10) {
          ppuVar20 = ppuVar10;
          iVar9 = (*(code *)PTR_bn_expand2_006a8524)(ppuVar3,ppuVar10);
          if (iVar9 == 0) goto LAB_00625240;
          ppuVar22 = (uint **)*ppuVar3;
        }
        else {
          ppuVar22 = (uint **)*ppuVar3;
        }
        if (0 < (int)ppuVar10) {
          ppuVar17 = (uint **)((int)ppuVar10 << 2);
          ppuVar20 = (uint **)0x0;
          (*(code *)PTR_memset_006a99f4)(ppuVar22,0);
        }
        ppuVar23 = (uint **)*ppuVar5;
        ppuVar3[1] = (uint *)ppuVar10;
LAB_0062547c:
        for (; puVar6 = *ppuVar27, iVar8 != 0; iVar8 = iVar8 + -1) {
          if (((uint)puVar6 & 1) != 0) {
            if (iVar8 < 0x21) goto LAB_0062548c;
            goto LAB_00625494;
          }
          puVar13 = *param_3;
          uVar12 = -((uint)*ppuVar21 & 1);
          uVar24 = uVar12 & *puVar13 ^ (uint)*ppuVar21;
          uVar15 = (uint)puVar6 & 1;
          if (0 < (int)ppuVar10 + -1) {
            puVar7 = puVar6;
            ppuVar11 = ppuVar27 + 1;
            ppuVar18 = ppuVar21 + 1;
            do {
              puVar13 = puVar13 + 1;
              puVar6 = *ppuVar11;
              ppuVar20 = ppuVar11 + 1;
              ppuVar17 = ppuVar18 + 1;
              uVar15 = uVar24 >> 1;
              ppuVar11[-1] = (uint *)((uint)puVar7 >> 1 | (int)puVar6 << 0x1f);
              uVar24 = uVar12 & *puVar13 ^ (uint)*ppuVar18;
              ppuVar18[-1] = (uint *)(uVar15 | uVar24 << 0x1f);
              puVar7 = puVar6;
              uVar15 = ((int)ppuVar10 + -1) * 4;
              ppuVar11 = ppuVar20;
              ppuVar18 = ppuVar17;
            } while (ppuVar20 != ppuVar27 + (int)ppuVar10);
          }
          pcVar19 = (char *)((uint)puVar6 >> 1);
          *(char **)((int)ppuVar27 + uVar15) = pcVar19;
          *(uint *)((int)ppuVar21 + uVar15) = uVar24 >> 1;
        }
        if (puVar6 == (uint *)0x0) goto LAB_00625240;
LAB_0062548c:
        if (puVar6 != (uint *)0x1) {
LAB_00625494:
          iVar9 = iVar16;
          ppuVar11 = ppuVar23;
          ppuVar18 = ppuVar2;
          ppuVar25 = ppuVar5;
          iVar26 = iVar8;
          if (iVar8 < iVar16) {
            iVar9 = iVar8;
            ppuVar21 = ppuVar22;
            ppuVar22 = (uint **)*ppuVar2;
            ppuVar11 = (uint **)*ppuVar4;
            ppuVar18 = ppuVar3;
            ppuVar3 = ppuVar2;
            ppuVar25 = ppuVar4;
            ppuVar4 = ppuVar5;
            iVar26 = iVar16;
            ppuVar27 = ppuVar23;
          }
          ppuVar23 = ppuVar11;
          if (0 < (int)ppuVar10) {
            ppuVar2 = ppuVar27;
            ppuVar5 = ppuVar21;
            ppuVar11 = ppuVar22;
            pcVar19 = (char *)ppuVar23;
            do {
              puVar6 = *(uint **)pcVar19;
              ppuVar20 = ppuVar5 + 1;
              ppuVar17 = ppuVar11 + 1;
              ppuVar14 = ppuVar2 + 1;
              pcVar19 = (char *)((int)pcVar19 + 4);
              *ppuVar2 = (uint *)((uint)*ppuVar2 ^ (uint)puVar6);
              *ppuVar5 = (uint *)((uint)*ppuVar5 ^ (uint)*ppuVar11);
              ppuVar2 = ppuVar14;
              ppuVar5 = ppuVar20;
              ppuVar11 = ppuVar17;
            } while (ppuVar14 != ppuVar27 + (int)ppuVar10);
          }
          iVar16 = iVar9;
          ppuVar2 = ppuVar18;
          ppuVar5 = ppuVar25;
          iVar8 = iVar26;
          if (iVar26 == iVar9) {
            iVar16 = iVar26 + -1;
            if (iVar26 + -1 < 0) {
              iVar16 = iVar26 + 0x1e;
            }
            iVar16 = iVar16 >> 5;
            ppuVar11 = ppuVar27 + iVar16;
            if (*ppuVar11 == (uint *)0x0) {
              while (iVar16 != 0) {
                iVar16 = iVar16 + -1;
                if (ppuVar11[-1] != (uint *)0x0) goto LAB_00625580;
                ppuVar11 = ppuVar11 + -1;
              }
              iVar16 = 0;
            }
            else {
LAB_00625580:
              iVar16 = iVar16 << 5;
            }
            iVar8 = (*(code *)PTR_BN_num_bits_word_006a859c)();
            iVar8 = iVar8 + iVar16;
            iVar16 = iVar26;
          }
          goto LAB_0062547c;
        }
        puVar6 = ppuVar2[1];
        if (0 < (int)puVar6) {
          puVar13 = *ppuVar2 + (int)puVar6 + -1;
          do {
            puVar7 = (uint *)((int)puVar6 + -1);
            if (*puVar13 != 0) break;
            puVar6 = puVar7;
            puVar13 = puVar13 + -1;
          } while (puVar7 != (uint *)0x0);
          ppuVar2[1] = puVar6;
        }
        iVar16 = (*(code *)PTR_BN_copy_006a8450)(param_1,ppuVar2);
        uVar12 = (uint)(iVar16 != 0);
        goto LAB_00625244;
      }
    }
  }
LAB_00625240:
  ppuVar2 = ppuVar20;
  uVar12 = 0;
LAB_00625244:
  (*(code *)PTR_BN_CTX_end_006a8530)(param_4);
  if (local_2c == *(int *)puVar1) {
    return uVar12;
  }
  iVar16 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  (*(code *)PTR_BN_CTX_start_006a8528)(pcVar19);
  iVar8 = (*(code *)PTR_BN_CTX_get_006a852c)(pcVar19);
  if (iVar8 == 0) {
LAB_0062586c:
    uVar12 = 0;
  }
  else {
    (*(code *)PTR_BN_set_word_006a7730)(iVar8,0);
    puVar6 = *ppuVar17;
    while (puVar6 != (uint *)0xffffffff) {
      ppuVar17 = ppuVar17 + 1;
      iVar9 = (*(code *)PTR_BN_set_bit_006a85ec)(iVar8);
      if (iVar9 == 0) goto LAB_0062586c;
      puVar6 = *ppuVar17;
    }
    uVar12 = BN_GF2m_mod_inv(iVar16,ppuVar2,iVar8,pcVar19);
  }
  (*(code *)PTR_BN_CTX_end_006a8530)(pcVar19);
  return uVar12;
}

