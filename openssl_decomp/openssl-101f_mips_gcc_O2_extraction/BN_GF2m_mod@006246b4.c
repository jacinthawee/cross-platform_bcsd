
uint BN_GF2m_mod(int *param_1,int *param_2,int **param_3,char *param_4)

{
  undefined *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint **ppuVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint **ppuVar8;
  int iVar9;
  char **ppcVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  int **ppiVar14;
  uint *puVar15;
  char *local_2c [6];
  uint **local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  piVar2 = param_3[1];
  local_14 = *(uint ***)PTR___stack_chk_guard_006aabf0;
  if (piVar2 == (int *)0x0) {
LAB_00624804:
    param_3 = (int **)&DAT_0000006a;
    param_4 = "bn_gf2m.c";
    ppcVar10 = (char **)0x83;
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x83,0x6a,"bn_gf2m.c",0x176);
    uVar6 = 0;
  }
  else {
    if ((int)piVar2 + -1 < 0) {
      ppcVar10 = local_2c;
LAB_00624778:
      *ppcVar10 = (char *)0xffffffff;
    }
    else {
      ppiVar14 = (int **)*param_3;
      iVar9 = 0;
      param_3 = ppiVar14 + (int)piVar2;
      param_4 = (char *)(((int)piVar2 + -1) * 0x20 + -1);
      do {
        piVar2 = param_3[-1];
        pcVar5 = param_4 + 0x20;
        if (piVar2 != (int *)0x0) {
          uVar6 = 0x80000000;
          while( true ) {
            if ((uVar6 & (uint)piVar2) != 0) {
              if (iVar9 < 6) {
                local_2c[iVar9] = pcVar5;
              }
              iVar9 = iVar9 + 1;
            }
            pcVar5 = pcVar5 + -1;
            uVar6 = uVar6 >> 1;
            if (param_4 == pcVar5) break;
            piVar2 = param_3[-1];
          }
        }
        param_3 = param_3 + -1;
        param_4 = param_4 + -0x20;
      } while (ppiVar14 != param_3);
      if (iVar9 < 6) {
        ppcVar10 = local_2c + iVar9;
        goto LAB_00624778;
      }
      if (6 < iVar9) goto LAB_00624804;
    }
    if (local_2c[0] == (char *)0x0) {
      ppcVar10 = (char **)0x0;
      (*(code *)PTR_BN_set_word_006a8820)(param_1);
      uVar6 = 1;
    }
    else {
      if (param_1 != param_2) {
        ppcVar10 = (char **)param_2[1];
        if (param_1[2] < (int)ppcVar10) {
          iVar9 = (*(code *)PTR_bn_expand2_006a9680)(param_1);
          uVar6 = 0;
          if (iVar9 == 0) goto LAB_00624830;
          ppcVar10 = (char **)param_2[1];
        }
        if (0 < (int)ppcVar10) {
          puVar7 = (undefined4 *)*param_2;
          iVar9 = 0;
          puVar3 = (undefined4 *)*param_1;
          do {
            iVar9 = iVar9 + 1;
            *puVar3 = *puVar7;
            ppcVar10 = (char **)param_2[1];
            param_3 = (int **)(uint)(iVar9 < (int)ppcVar10);
            puVar7 = puVar7 + 1;
            puVar3 = puVar3 + 1;
          } while (param_3 != (int **)0x0);
        }
        param_1[1] = (int)ppcVar10;
      }
      ppcVar10 = local_2c;
      uVar6 = BN_GF2m_mod_arr_part_0(param_1);
    }
  }
LAB_00624830:
  if (local_14 == *(uint ***)puVar1) {
    return uVar6;
  }
  ppuVar8 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  (*(code *)PTR_BN_CTX_start_006a9644)(param_4);
  ppuVar4 = (uint **)(*(code *)PTR_BN_CTX_get_006a9648)(param_4);
  if (ppuVar4 == (uint **)0x0) {
    return 0;
  }
  pcVar5 = ppcVar10[1];
  if ((int)ppuVar4[2] < (int)pcVar5 << 1) {
    iVar9 = (*(code *)PTR_bn_expand2_006a9680)(ppuVar4);
    if (iVar9 != 0) {
      pcVar5 = ppcVar10[1];
      goto LAB_00624918;
    }
LAB_00624ac8:
    uVar6 = 0;
  }
  else {
LAB_00624918:
    if (0 < (int)pcVar5) {
      puVar15 = *ppuVar4;
      puVar13 = (uint *)(*ppcVar10 + (int)pcVar5 * 4);
      puVar12 = puVar15 + (int)pcVar5 * 2;
      do {
        uVar6 = puVar13[-1];
        puVar11 = puVar12 + -2;
        puVar13 = puVar13 + -1;
        puVar12[-1] = *(int *)(&SQR_tb + (uVar6 >> 0x1c) * 4) << 0x18 |
                      *(uint *)(&SQR_tb + ((uVar6 << 0xc) >> 0x1c) * 4) |
                      *(int *)(&SQR_tb + ((uVar6 << 4) >> 0x1c) * 4) << 0x10 |
                      *(int *)(&SQR_tb + ((uVar6 << 8) >> 0x1c) * 4) << 8;
        uVar6 = *puVar13;
        *puVar11 = *(int *)(&SQR_tb + ((uVar6 << 0x10) >> 0x1c) * 4) << 0x18 |
                   *(int *)(&SQR_tb + ((uVar6 << 0x14) >> 0x1c) * 4) << 0x10 |
                   *(uint *)(&SQR_tb + (uVar6 & 0xf) * 4) |
                   *(int *)(&SQR_tb + ((uVar6 << 0x18) >> 0x1c) * 4) << 8;
        puVar12 = puVar11;
      } while (puVar15 != puVar11);
      pcVar5 = ppcVar10[1];
    }
    puVar12 = (uint *)((int)pcVar5 << 1);
    ppuVar4[1] = puVar12;
    if (0 < (int)puVar12) {
      puVar13 = *ppuVar4 + (int)pcVar5 * 2 + -2;
      do {
        if (puVar13[1] != 0) break;
        puVar12 = (uint *)((int)puVar12 + -1);
        puVar13 = puVar13 + -1;
      } while (puVar12 != (uint *)0x0);
      ppuVar4[1] = puVar12;
    }
    if (*param_3 == (int *)0x0) {
      uVar6 = 1;
      (*(code *)PTR_BN_set_word_006a8820)(ppuVar8,0);
      goto LAB_00624acc;
    }
    if (ppuVar4 != ppuVar8) {
      if ((int)ppuVar8[2] < (int)puVar12) {
        iVar9 = (*(code *)PTR_bn_expand2_006a9680)(ppuVar8);
        if (iVar9 == 0) goto LAB_00624ac8;
        puVar12 = ppuVar4[1];
      }
      iVar9 = 0;
      if (0 < (int)puVar12) {
        puVar15 = *ppuVar4;
        puVar13 = *ppuVar8;
        do {
          iVar9 = iVar9 + 1;
          *puVar13 = *puVar15;
          puVar12 = ppuVar4[1];
          puVar15 = puVar15 + 1;
          puVar13 = puVar13 + 1;
        } while (iVar9 < (int)puVar12);
      }
      ppuVar8[1] = puVar12;
    }
    iVar9 = BN_GF2m_mod_arr_part_0(ppuVar8,param_3);
    uVar6 = (uint)(iVar9 != 0);
  }
LAB_00624acc:
  (*(code *)PTR_BN_CTX_end_006a9654)(param_4);
  return uVar6;
}
