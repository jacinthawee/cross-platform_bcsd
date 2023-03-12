
/* WARNING: Removing unreachable block (ram,0x005280c8) */
/* WARNING: Could not reconcile some variable overlaps */

void fmtint_constprop_3(int *param_1,uint **param_2,uint **param_3,undefined4 param_4,int param_5,
                       int param_6,int param_7,int param_8,int param_9,uint param_10)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  int *in_zero;
  char *pcVar4;
  int iVar5;
  int extraout_v1;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  int iVar16;
  char *pcVar17;
  longlong lVar18;
  undefined4 local_5c;
  uint local_58;
  uint local_48 [7];
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_9 < 0) {
    param_9 = 0;
  }
  if ((param_10 & 0x40) != 0) goto LAB_00526ef4;
  if (-1 < param_5) goto LAB_00527078;
  param_6 = -param_6;
  local_58 = 1;
  param_5 = -(uint)(param_6 != 0) - param_5;
  local_5c = (uint *)&DAT_0000002d;
  if ((param_10 & 8) != 0) goto LAB_00526f0c;
LAB_00526d2c:
  do {
    pcVar17 = "";
LAB_00526d30:
    puVar7 = local_48;
    iVar16 = 0;
    pcVar4 = "0123456789abcdef";
    lVar18 = CONCAT44(param_5,param_6);
    if ((param_10 & 0x20) != 0) {
      pcVar4 = "0123456789ABCDEF";
      lVar18 = CONCAT44(param_5,param_6);
    }
    do {
      iVar11 = iVar16;
      uVar14 = (undefined4)((ulonglong)lVar18 >> 0x20);
      iVar16 = iVar11 + 1;
      (*(code *)PTR___umoddi3_006a96e0)(uVar14,(int)lVar18,0,param_7);
      *(char *)puVar7 = pcVar4[extraout_v1];
      lVar18 = (*(code *)PTR___udivdi3_006a970c)(uVar14,(int)lVar18,0,param_7);
      param_5 = (int)((ulonglong)lVar18 >> 0x20);
      if (lVar18 == 0) {
        if (iVar16 != 0x1a) {
          iVar11 = iVar16;
        }
        break;
      }
      puVar7 = (uint *)((int)puVar7 + 1);
    } while (iVar16 != 0x1a);
    *(undefined *)((int)local_48 + iVar11) = 0;
    iVar12 = param_9 - iVar11;
    iVar16 = (*(code *)PTR_strlen_006aab30)(pcVar17);
    iVar5 = param_9;
    if (param_9 <= iVar11) {
      iVar5 = iVar11;
    }
    if (iVar12 < 0) {
      iVar12 = 0;
    }
    puVar7 = (uint *)(param_10 & 0x10);
    iVar16 = ((param_8 - iVar5) - local_58) - iVar16;
    if (iVar16 < 0) {
      iVar16 = 0;
    }
    param_6 = param_9;
    if (puVar7 == (uint *)0x0) {
      if ((param_10 & 1) == 0) {
        if (iVar16 != 0) {
LAB_00527050:
          puVar7 = *param_2;
          if (*param_3 <= puVar7) goto LAB_00527044;
          puVar10 = (uint *)((int)puVar7 + 1);
          if (*param_1 != 0) {
            puVar7 = (uint *)(*param_1 + (int)puVar7);
            *param_2 = puVar10;
            *(char *)puVar7 = ' ';
            goto LAB_00527044;
          }
          trap(0);
LAB_00527078:
          if ((param_10 & 2) == 0) {
            local_58 = param_10 & 4;
            if (local_58 != 0) {
              local_58 = 1;
              local_5c = (uint *)&DAT_00000020;
              goto LAB_00526efc;
            }
            goto LAB_00526ef8;
          }
          local_58 = 1;
          local_5c = (uint *)0x2b;
          goto LAB_00526efc;
        }
      }
      else {
        iVar16 = -iVar16;
      }
    }
    else {
      if (iVar12 < iVar16) {
        iVar12 = iVar16;
      }
      iVar16 = 0;
    }
LAB_00526e50:
    if ((local_5c == (uint *)0x0) || (puVar7 = *param_2, *param_3 <= puVar7)) {
LAB_00526e58:
      cVar1 = *pcVar17;
      while (cVar1 != '\0') {
        puVar7 = *param_2;
        if (puVar7 < *param_3) {
          if (*param_1 == 0) goto LAB_00526eec;
          puVar10 = (uint *)((int)puVar7 + 1);
          puVar7 = (uint *)(*param_1 + (int)puVar7);
          *param_2 = puVar10;
          *(char *)puVar7 = cVar1;
        }
        pcVar17 = pcVar17 + 1;
        cVar1 = *pcVar17;
      }
      puVar10 = (uint *)&DAT_00000030;
      if (iVar12 != 0) {
        puVar7 = *param_2;
        do {
          if (puVar7 < *param_3) {
            puVar8 = (uint *)((int)puVar7 + 1);
            if (*param_1 == 0) goto LAB_00526eec;
            puVar7 = (uint *)(*param_1 + (int)puVar7);
            *param_2 = puVar8;
            *(char *)puVar7 = '0';
          }
          iVar12 = iVar12 + -1;
          if (iVar12 == 0) break;
          puVar7 = *param_2;
        } while( true );
      }
      puVar8 = (uint *)((int)local_48 + iVar11);
      goto joined_r0x00526f34;
    }
    iVar5 = *param_1;
    if (iVar5 != 0) {
      *param_2 = (uint *)((int)puVar7 + 1);
      *(char *)(iVar5 + (int)puVar7) = (char)local_5c;
      puVar7 = local_5c;
      goto LAB_00526e58;
    }
LAB_00526eec:
    trap(0);
LAB_00526ef4:
    local_58 = 0;
LAB_00526ef8:
    local_5c = (uint *)0x0;
LAB_00526efc:
  } while ((param_10 & 8) == 0);
LAB_00526f0c:
  if (param_7 == 8) {
    pcVar17 = "0";
  }
  else {
    if (param_7 != 0x10) goto LAB_00526d2c;
    pcVar17 = "0x";
  }
  goto LAB_00526d30;
LAB_00527044:
  iVar16 = iVar16 + -1;
  if (iVar16 == 0) goto LAB_00526e50;
  goto LAB_00527050;
joined_r0x00526f34:
  if (iVar11 == 0) goto LAB_00526f88;
  puVar7 = *param_2;
  iVar11 = iVar11 + -1;
  if (puVar7 < *param_3) {
    puVar10 = (uint *)((int)puVar7 + 1);
    if (*param_1 == 0) {
      iVar16 = *in_zero;
      trap(0);
      goto LAB_00526f88;
    }
    cVar1 = *(char *)((int)puVar8 + -1);
    puVar7 = (uint *)(*param_1 + (int)puVar7);
    *param_2 = puVar10;
    *(char *)puVar7 = cVar1;
  }
  puVar8 = (uint *)((int)puVar8 + -1);
  goto joined_r0x00526f34;
LAB_00526f88:
  puVar9 = (uint *)&DAT_00000020;
  do {
    if (iVar16 == 0) {
LAB_00526fdc:
      if (local_2c == *(int *)puVar3) {
        return;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      puVar3 = PTR___stack_chk_guard_006aabf0;
      iVar11 = *(int *)PTR___stack_chk_guard_006aabf0;
      uVar13 = 0;
      iVar16 = (int)_gp;
      uVar15 = *puVar8;
      do {
        bVar2 = uVar13 < uVar15;
        if (iVar16 != 0) goto LAB_005272f4;
        while( true ) {
          uVar15 = (uint)(uVar15 - 1 < uVar13);
          *puVar10 = uVar15;
          if (uVar15 != 0) {
            uVar13 = *puVar8 - 1;
          }
          uVar6 = uVar13;
          if (*puVar8 <= uVar13) goto LAB_00527238;
          if (*puVar7 != 0) break;
          trap(0);
LAB_005272f4:
          if (bVar2) {
                    /* WARNING: Could not recover jumptable at 0x00527318. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)switchD_00527318::switchdataD_00667f40)();
            return;
          }
        }
        uVar6 = uVar13 + 1;
        *(undefined *)(*puVar7 + uVar13) = 0;
LAB_00527238:
        uVar13 = uVar6 - 1;
        iVar5 = *(int *)puVar3;
        *puVar9 = uVar13;
        if (iVar11 == iVar5) {
          return;
        }
        (*(code *)PTR___stack_chk_fail_006aabb8)();
      } while( true );
    }
    puVar7 = *param_2;
    if (puVar7 < *param_3) {
      puVar8 = (uint *)((int)puVar7 + 1);
      if (*param_1 == 0) {
        trap(0);
        goto LAB_00526fdc;
      }
      puVar7 = (uint *)(*param_1 + (int)puVar7);
      *param_2 = puVar8;
      *(char *)puVar7 = ' ';
    }
    iVar16 = iVar16 + 1;
  } while( true );
}

