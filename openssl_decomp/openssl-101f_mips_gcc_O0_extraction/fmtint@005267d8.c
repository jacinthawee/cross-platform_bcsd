
/* WARNING: Removing unreachable block (ram,0x005280c8) */
/* WARNING: Could not reconcile some variable overlaps */

void fmtint(uint **param_1,uint **param_2,uint **param_3,undefined4 *param_4,int param_5,int param_6
           ,int param_7,int param_8,int param_9,uint param_10)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  int *in_zero;
  int iVar4;
  int iVar5;
  uint *puVar6;
  char *pcVar7;
  int iVar8;
  int extraout_v1;
  uint *puVar9;
  int extraout_v1_00;
  uint uVar10;
  uint **ppuVar11;
  int iVar12;
  uint **ppuVar13;
  uint **ppuVar14;
  uint *puVar15;
  uint *puVar16;
  int iVar17;
  uint uVar18;
  undefined4 uVar19;
  uint uVar20;
  char *pcVar21;
  code *pcVar22;
  undefined *puVar23;
  longlong lVar24;
  undefined4 uStack_e4;
  uint uStack_e0;
  uint auStack_d0 [7];
  int iStack_b4;
  uint **ppuStack_b0;
  undefined4 *puStack_ac;
  uint **ppuStack_a8;
  char *pcStack_a4;
  uint **ppuStack_a0;
  int iStack_9c;
  char *pcStack_98;
  char *pcStack_94;
  int iStack_90;
  code *pcStack_8c;
  int local_78;
  int iStack_74;
  undefined *local_70;
  int iStack_6c;
  int iStack_68;
  uint **local_64;
  char *local_60;
  int local_5c;
  uint local_58;
  int local_54;
  int *local_50;
  char *local_4c;
  char local_48 [28];
  int local_2c;
  
  local_50 = (int *)PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_9 < 0) {
    param_9 = 0;
  }
  local_70 = &_gp;
  if ((param_10 & 0x40) == 0) {
    if (param_5 < 0) {
      param_6 = -param_6;
      local_58 = 1;
      local_5c = 0x2d;
      param_5 = -(uint)(param_6 != 0) - param_5;
    }
    else if ((param_10 & 2) == 0) {
      local_58 = param_10 & 4;
      if (local_58 == 0) goto LAB_00526b40;
      local_58 = 1;
      local_5c = 0x20;
    }
    else {
      local_58 = 1;
      local_5c = 0x2b;
    }
  }
  else {
    local_58 = 0;
LAB_00526b40:
    local_5c = 0;
  }
  if ((param_10 & 8) != 0) {
    if (param_7 == 8) {
      pcStack_98 = "0";
      goto LAB_00526890;
    }
    if (param_7 == 0x10) {
      pcStack_98 = "0x";
      goto LAB_00526890;
    }
  }
  pcStack_98 = "";
LAB_00526890:
  pcVar21 = local_48;
  iStack_90 = 0;
  local_60 = "0123456789abcdef";
  local_54 = param_9;
  local_4c = pcVar21;
  lVar24 = CONCAT44(param_5,param_6);
  if ((param_10 & 0x20) != 0) {
    local_60 = "0123456789ABCDEF";
    lVar24 = CONCAT44(param_5,param_6);
  }
  do {
    iStack_9c = iStack_90;
    uVar19 = (undefined4)((ulonglong)lVar24 >> 0x20);
    local_64 = (uint **)lVar24;
    iStack_90 = iStack_9c + 1;
    (**(code **)(local_70 + -0x6800))(uVar19,local_64,0,param_7);
    ppuVar14 = (uint **)0x0;
    pcVar22 = *(code **)(local_70 + -0x67d4);
    *pcVar21 = local_60[extraout_v1];
    ppuVar13 = local_64;
    lVar24 = (*pcVar22)(uVar19,local_64,0,param_7);
    iVar5 = local_54;
    if (lVar24 == 0) {
      if (iStack_90 != 0x1a) {
        iStack_9c = iStack_90;
      }
      break;
    }
    pcVar21 = pcVar21 + 1;
  } while (iStack_90 != 0x1a);
  pcVar22 = *(code **)(local_70 + -0x53b0);
  local_48[iStack_9c] = '\0';
  pcStack_a4 = (char *)(local_54 - iStack_9c);
  iVar4 = (*pcVar22)(pcStack_98);
  if (iVar5 <= iStack_9c) {
    iVar5 = iStack_9c;
  }
  ppuVar11 = (uint **)(param_10 & 0x10);
  if ((int)pcStack_a4 < 0) {
    pcStack_a4 = (char *)0x0;
  }
  pcStack_94 = (char *)(((param_8 - iVar5) - local_58) - iVar4);
  if ((int)pcStack_94 < 0) {
    pcStack_94 = (char *)0x0;
  }
  if (ppuVar11 == (uint **)0x0) {
    if ((param_10 & 1) == 0) {
      for (; pcStack_94 != (char *)0x0; pcStack_94 = pcStack_94 + -1) {
        ppuVar11 = param_1;
        ppuVar13 = param_2;
        ppuVar14 = param_3;
        doapr_outch_constprop_5();
      }
    }
    else {
      pcStack_94 = (char *)-(int)pcStack_94;
    }
  }
  else {
    if ((int)pcStack_a4 < (int)pcStack_94) {
      pcStack_a4 = pcStack_94;
    }
    pcStack_94 = (char *)0x0;
  }
  iVar5 = local_5c;
  if (local_5c == 0) goto LAB_005269dc;
  do {
    ppuVar11 = param_1;
    ppuVar13 = param_2;
    ppuVar14 = param_3;
    local_78 = iVar5;
    doapr_outch();
LAB_005269dc:
    iVar5 = (int)*pcStack_98;
    pcStack_98 = pcStack_98 + 1;
  } while (iVar5 != 0);
  if (pcStack_a4 != (char *)0x0) {
    pcStack_98 = &DAT_00000030;
    do {
      pcStack_a4 = pcStack_a4 + -1;
      local_78 = 0x30;
      ppuVar11 = param_1;
      ppuVar13 = param_2;
      ppuVar14 = param_3;
      doapr_outch();
    } while (pcStack_a4 != (char *)0x0);
  }
  puVar23 = local_70;
  if (iStack_9c != 0) {
    iStack_9c = iStack_9c + -1;
    ppuVar14 = (uint **)*param_3;
    pcStack_98 = local_4c + iStack_9c;
    pcStack_a4 = "b_print.c";
    iStack_90 = (int)*pcStack_98;
    if (param_2 == (uint **)0x0) goto LAB_00526abc;
LAB_00526a3c:
    ppuVar13 = (uint **)*param_4;
    if (ppuVar13 <= ppuVar14) {
      do {
        ppuVar11 = (uint **)*param_2;
        pcVar22 = *(code **)(puVar23 + -0x729c);
        if (ppuVar11 == (uint **)0x0) {
          if (ppuVar13 == (uint **)0x0) {
            ppuVar13 = (uint **)&DAT_00000400;
            *param_4 = 0x400;
          }
          ppuVar11 = (uint **)(**(code **)(puVar23 + -0x7dd8))(ppuVar13,"b_print.c",0x2e5);
          ppuVar14 = (uint **)*param_3;
          *param_2 = (uint *)ppuVar11;
          if (ppuVar14 == (uint **)0x0) {
            *param_1 = (uint *)0x0;
            ppuVar11 = ppuVar13;
            puVar23 = local_70;
          }
          else {
            (**(code **)(local_70 + -0x52ec))(ppuVar11,*param_1);
            ppuVar14 = (uint **)*param_3;
            *param_1 = (uint *)0x0;
            puVar23 = local_70;
          }
          goto LAB_00526a3c;
        }
        *param_4 = ppuVar13 + 0x100;
        puVar6 = (uint *)(*pcVar22)(ppuVar11,ppuVar13 + 0x100,"b_print.c",0x2ed);
        ppuVar14 = (uint **)*param_3;
        ppuVar13 = (uint **)*param_4;
        *param_2 = puVar6;
        puVar23 = local_70;
      } while (ppuVar13 <= ppuVar14);
    }
    do {
      puVar6 = *param_1;
      if (puVar6 == (uint *)0x0) {
        puVar6 = *param_2;
      }
      puVar9 = (uint *)((int)ppuVar14 + 1);
      ppuVar14 = (uint **)((int)puVar6 + (int)ppuVar14);
      *param_3 = puVar9;
      *(char *)ppuVar14 = (char)iStack_90;
      do {
        pcStack_98 = pcStack_98 + -1;
        if (iStack_9c == 0) goto joined_r0x00526ad4;
        iStack_9c = iStack_9c + -1;
        iStack_90 = (int)*pcStack_98;
        ppuVar14 = (uint **)*param_3;
        if (param_2 != (uint **)0x0) goto LAB_00526a3c;
LAB_00526abc:
      } while ((uint **)*param_4 <= ppuVar14);
    } while( true );
  }
joined_r0x00526ad4:
  for (; pcStack_94 != (char *)0x0; pcStack_94 = pcStack_94 + 1) {
    ppuVar11 = param_1;
    ppuVar13 = param_2;
    ppuVar14 = param_3;
    doapr_outch_constprop_5();
    puVar23 = local_70;
  }
  if (local_2c == *local_50) {
    return;
  }
  pcStack_8c = fmtint_constprop_3;
  (**(code **)(puVar23 + -0x5328))();
  puVar23 = PTR___stack_chk_guard_006aabf0;
  iStack_b4 = *(int *)PTR___stack_chk_guard_006aabf0;
  if (iStack_68 < 0) {
    iStack_68 = 0;
  }
  iVar5 = local_78;
  ppuStack_b0 = param_2;
  puStack_ac = param_4;
  ppuStack_a8 = param_3;
  ppuStack_a0 = param_1;
  if (((uint)local_64 & 0x40) != 0) goto LAB_00526ef4;
  if (-1 < local_78) goto LAB_00527078;
  iStack_74 = -iStack_74;
  uStack_e0 = 1;
  iVar5 = -(uint)(iStack_74 != 0) - local_78;
  uStack_e4 = (uint *)&DAT_0000002d;
  if (((uint)local_64 & 8) != 0) goto LAB_00526f0c;
LAB_00526d2c:
  do {
    pcVar21 = "";
LAB_00526d30:
    puVar6 = auStack_d0;
    iVar4 = 0;
    pcVar7 = "0123456789abcdef";
    lVar24 = CONCAT44(iVar5,iStack_74);
    if (((uint)local_64 & 0x20) != 0) {
      pcVar7 = "0123456789ABCDEF";
      lVar24 = CONCAT44(iVar5,iStack_74);
    }
    do {
      iVar8 = iVar4;
      uVar19 = (undefined4)((ulonglong)lVar24 >> 0x20);
      iVar4 = iVar8 + 1;
      (*(code *)PTR___umoddi3_006a96e0)(uVar19,(int)lVar24,0,local_70);
      puVar3 = local_70;
      *(char *)puVar6 = pcVar7[extraout_v1_00];
      lVar24 = (*(code *)PTR___udivdi3_006a970c)(uVar19,(int)lVar24,0,puVar3);
      iVar5 = (int)((ulonglong)lVar24 >> 0x20);
      if (lVar24 == 0) {
        if (iVar4 != 0x1a) {
          iVar8 = iVar4;
        }
        break;
      }
      puVar6 = (uint *)((int)puVar6 + 1);
    } while (iVar4 != 0x1a);
    *(undefined *)((int)auStack_d0 + iVar8) = 0;
    iVar17 = iStack_68 - iVar8;
    iVar4 = (*(code *)PTR_strlen_006aab30)(pcVar21);
    iVar12 = iStack_68;
    if (iStack_68 <= iVar8) {
      iVar12 = iVar8;
    }
    if (iVar17 < 0) {
      iVar17 = 0;
    }
    puVar6 = (uint *)((uint)local_64 & 0x10);
    iVar4 = ((iStack_6c - iVar12) - uStack_e0) - iVar4;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    iStack_74 = iStack_68;
    if (puVar6 == (uint *)0x0) {
      if (((uint)local_64 & 1) == 0) {
        if (iVar4 != 0) {
LAB_00527050:
          puVar6 = *ppuVar13;
          if (*ppuVar14 <= puVar6) goto LAB_00527044;
          puVar9 = (uint *)((int)puVar6 + 1);
          if (*ppuVar11 != (uint *)0x0) {
            puVar6 = (uint *)((int)*ppuVar11 + (int)puVar6);
            *ppuVar13 = puVar9;
            *(char *)puVar6 = ' ';
            goto LAB_00527044;
          }
          trap(0);
LAB_00527078:
          if (((uint)local_64 & 2) == 0) {
            uStack_e0 = (uint)local_64 & 4;
            if (uStack_e0 != 0) {
              uStack_e0 = 1;
              uStack_e4 = (uint *)&DAT_00000020;
              goto LAB_00526efc;
            }
            goto LAB_00526ef8;
          }
          uStack_e0 = 1;
          uStack_e4 = (uint *)0x2b;
          goto LAB_00526efc;
        }
      }
      else {
        iVar4 = -iVar4;
      }
    }
    else {
      if (iVar17 < iVar4) {
        iVar17 = iVar4;
      }
      iVar4 = 0;
    }
LAB_00526e50:
    if ((uStack_e4 == (uint *)0x0) || (puVar6 = *ppuVar13, *ppuVar14 <= puVar6)) {
LAB_00526e58:
      cVar1 = *pcVar21;
      while (cVar1 != '\0') {
        puVar6 = *ppuVar13;
        if (puVar6 < *ppuVar14) {
          if (*ppuVar11 == (uint *)0x0) goto LAB_00526eec;
          puVar9 = (uint *)((int)puVar6 + 1);
          puVar6 = (uint *)((int)*ppuVar11 + (int)puVar6);
          *ppuVar13 = puVar9;
          *(char *)puVar6 = cVar1;
        }
        pcVar21 = pcVar21 + 1;
        cVar1 = *pcVar21;
      }
      puVar9 = (uint *)&DAT_00000030;
      if (iVar17 != 0) {
        puVar6 = *ppuVar13;
        do {
          if (puVar6 < *ppuVar14) {
            puVar15 = (uint *)((int)puVar6 + 1);
            if (*ppuVar11 == (uint *)0x0) goto LAB_00526eec;
            puVar6 = (uint *)((int)*ppuVar11 + (int)puVar6);
            *ppuVar13 = puVar15;
            *(char *)puVar6 = '0';
          }
          iVar17 = iVar17 + -1;
          if (iVar17 == 0) break;
          puVar6 = *ppuVar13;
        } while( true );
      }
      puVar15 = (uint *)((int)auStack_d0 + iVar8);
      goto joined_r0x00526f34;
    }
    puVar9 = *ppuVar11;
    if (puVar9 != (uint *)0x0) {
      *ppuVar13 = (uint *)((int)puVar6 + 1);
      *(char *)((int)puVar9 + (int)puVar6) = (char)uStack_e4;
      puVar6 = uStack_e4;
      goto LAB_00526e58;
    }
LAB_00526eec:
    trap(0);
LAB_00526ef4:
    uStack_e0 = 0;
LAB_00526ef8:
    uStack_e4 = (uint *)0x0;
LAB_00526efc:
  } while (((uint)local_64 & 8) == 0);
LAB_00526f0c:
  if (local_70 == &DAT_00000008) {
    pcVar21 = "0";
  }
  else {
    if (local_70 != &SUB_00000010) goto LAB_00526d2c;
    pcVar21 = "0x";
  }
  goto LAB_00526d30;
LAB_00527044:
  iVar4 = iVar4 + -1;
  if (iVar4 == 0) goto LAB_00526e50;
  goto LAB_00527050;
joined_r0x00526f34:
  if (iVar8 == 0) goto LAB_00526f88;
  puVar6 = *ppuVar13;
  iVar8 = iVar8 + -1;
  if (puVar6 < *ppuVar14) {
    puVar9 = (uint *)((int)puVar6 + 1);
    if (*ppuVar11 == (uint *)0x0) {
      iVar4 = *in_zero;
      trap(0);
      goto LAB_00526f88;
    }
    cVar1 = *(char *)((int)puVar15 + -1);
    puVar6 = (uint *)((int)*ppuVar11 + (int)puVar6);
    *ppuVar13 = puVar9;
    *(char *)puVar6 = cVar1;
  }
  puVar15 = (uint *)((int)puVar15 + -1);
  goto joined_r0x00526f34;
LAB_00526f88:
  puVar16 = (uint *)&DAT_00000020;
  do {
    if (iVar4 == 0) {
LAB_00526fdc:
      if (iStack_b4 == *(int *)puVar23) {
        return;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      puVar23 = PTR___stack_chk_guard_006aabf0;
      iVar4 = *(int *)PTR___stack_chk_guard_006aabf0;
      uVar18 = 0;
      iVar5 = (int)_gp;
      uVar20 = *puVar15;
      do {
        bVar2 = uVar18 < uVar20;
        if (iVar5 != 0) goto LAB_005272f4;
        while( true ) {
          uVar20 = (uint)(uVar20 - 1 < uVar18);
          *puVar9 = uVar20;
          if (uVar20 != 0) {
            uVar18 = *puVar15 - 1;
          }
          uVar10 = uVar18;
          if (*puVar15 <= uVar18) goto LAB_00527238;
          if (*puVar6 != 0) break;
          trap(0);
LAB_005272f4:
          if (bVar2) {
                    /* WARNING: Could not recover jumptable at 0x00527318. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)switchD_00527318::switchdataD_00667f40)();
            return;
          }
        }
        uVar10 = uVar18 + 1;
        *(undefined *)(*puVar6 + uVar18) = 0;
LAB_00527238:
        uVar18 = uVar10 - 1;
        iVar8 = *(int *)puVar23;
        *puVar16 = uVar18;
        if (iVar4 == iVar8) {
          return;
        }
        (*(code *)PTR___stack_chk_fail_006aabb8)();
      } while( true );
    }
    puVar6 = *ppuVar13;
    if (puVar6 < *ppuVar14) {
      puVar15 = (uint *)((int)puVar6 + 1);
      if (*ppuVar11 == (uint *)0x0) {
        trap(0);
        goto LAB_00526fdc;
      }
      puVar6 = (uint *)((int)*ppuVar11 + (int)puVar6);
      *ppuVar13 = puVar15;
      *(char *)puVar6 = ' ';
    }
    iVar4 = iVar4 + 1;
  } while( true );
}

