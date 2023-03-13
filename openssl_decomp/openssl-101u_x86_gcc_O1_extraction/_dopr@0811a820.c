
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __regparm3
_dopr(undefined4 param_1_00,int param_2_00,uint *param_3_00,int *param_1,uint *param_2,char *param_3
     ,double *param_4)

{
  double *pdVar1;
  double dVar2;
  uint *puVar3;
  double dVar4;
  float fVar5;
  int iVar6;
  undefined4 uVar7;
  ushort **ppuVar8;
  size_t sVar9;
  int iVar10;
  int iVar11;
  char cVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  char *pcVar16;
  uint uVar17;
  uint uVar18;
  int in_GS_OFFSET;
  bool bVar19;
  uint local_80;
  int local_74;
  uint local_70;
  char *local_6c;
  double *local_68;
  int local_5c;
  undefined4 local_4c;
  undefined local_48 [19];
  char acStack_35 [21];
  int local_20;
  
  local_4c = 0;
  local_6c = (char *)0x0;
  local_68 = param_4;
  local_70 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_80 = 0xffffffff;
  local_74 = 0;
  uVar13 = (uint)*param_3;
  uVar17 = 0;
  pcVar16 = param_3 + 1;
LAB_0811a8a0:
  cVar12 = (char)uVar13;
joined_r0x0811a8a2:
  if (cVar12 == '\0') {
LAB_0811a900:
    uVar18 = *param_3_00;
LAB_0811a908:
    bVar19 = uVar18 - 1 < local_4c;
    *param_2 = (uint)bVar19;
    if (bVar19) {
      local_4c = *param_3_00 - 1;
    }
    iVar6 = doapr_outch(param_3_00,0);
    if (iVar6 == 0) goto LAB_0811aba0;
    *param_1 = local_4c - 1;
    uVar7 = 1;
    goto LAB_0811a952;
  }
  if ((param_2_00 == 0) && (uVar18 = *param_3_00, uVar18 <= local_4c)) goto LAB_0811a908;
  if (6 < uVar17) {
    if (uVar17 == 7) goto LAB_0811a900;
    goto LAB_0811a8a0;
  }
  cVar12 = (char)uVar13;
  switch(uVar17) {
  case 0:
    if (cVar12 == '%') {
      uVar17 = 1;
    }
    else {
      iVar6 = doapr_outch(param_3_00,uVar13);
      if (iVar6 == 0) goto LAB_0811aba0;
    }
    break;
  case 1:
    switch(uVar13 - 0x20 & 0xff) {
    case 0:
      uVar13 = (uint)*pcVar16;
      local_70 = local_70 | 4;
      pcVar16 = pcVar16 + 1;
      goto LAB_0811a8a0;
    default:
      uVar17 = 2;
      goto LAB_0811a8a0;
    case 3:
      uVar13 = (uint)*pcVar16;
      local_70 = local_70 | 8;
      pcVar16 = pcVar16 + 1;
      goto LAB_0811a8a0;
    case 0xb:
      uVar13 = (uint)*pcVar16;
      local_70 = local_70 | 2;
      pcVar16 = pcVar16 + 1;
      goto LAB_0811a8a0;
    case 0xd:
      local_70 = local_70 | 1;
      break;
    case 0x10:
      uVar13 = (uint)*pcVar16;
      local_70 = local_70 | 0x10;
      pcVar16 = pcVar16 + 1;
      goto LAB_0811a8a0;
    }
    break;
  case 2:
    ppuVar8 = __ctype_b_loc();
    if ((*(byte *)((int)*ppuVar8 + (uVar13 & 0xff) * 2 + 1) & 8) == 0) {
      uVar17 = 3;
      if (cVar12 == '*') {
        uVar13 = (uint)*pcVar16;
        pcVar16 = pcVar16 + 1;
        local_74 = *(int *)local_68;
        local_68 = (double *)((int)local_68 + 4);
      }
    }
    else {
      local_74 = (uVar13 - 0x30) + local_74 * 10;
      uVar13 = (uint)*pcVar16;
      pcVar16 = pcVar16 + 1;
    }
    goto LAB_0811a8a0;
  case 3:
    uVar17 = 5;
    if (cVar12 == '.') {
      uVar13 = (uint)*pcVar16;
      uVar17 = 4;
      pcVar16 = pcVar16 + 1;
    }
    goto LAB_0811a8a0;
  case 4:
    ppuVar8 = __ctype_b_loc();
    if ((*(byte *)((int)*ppuVar8 + (uVar13 & 0xff) * 2 + 1) & 8) == 0) {
      uVar17 = 5;
      if (cVar12 == '*') {
        uVar13 = (uint)*pcVar16;
        local_80 = *(uint *)local_68;
        local_68 = (double *)((int)local_68 + 4);
        pcVar16 = pcVar16 + 1;
      }
    }
    else {
      uVar18 = 0;
      if (-1 < (int)local_80) {
        uVar18 = local_80;
      }
      local_80 = (uVar13 - 0x30) + uVar18 * 10;
      uVar13 = (uint)*pcVar16;
      pcVar16 = pcVar16 + 1;
    }
    goto LAB_0811a8a0;
  case 5:
    if (cVar12 == 'h') {
      uVar13 = (uint)*pcVar16;
      local_6c = (char *)0x1;
      uVar17 = 6;
      pcVar16 = pcVar16 + 1;
      goto LAB_0811a8a0;
    }
    if (cVar12 < 'i') {
      if (cVar12 == 'L') {
        uVar13 = (uint)*pcVar16;
        local_6c = (char *)0x3;
        uVar17 = 6;
        pcVar16 = pcVar16 + 1;
        goto LAB_0811a8a0;
      }
    }
    else {
      if (cVar12 == 'l') {
        cVar12 = *pcVar16;
        local_6c = (char *)0x2;
        if (cVar12 == 'l') {
          cVar12 = pcVar16[1];
          local_6c = (char *)0x4;
          pcVar16 = pcVar16 + 1;
        }
        uVar13 = (uint)cVar12;
        uVar17 = 6;
        pcVar16 = pcVar16 + 1;
        goto LAB_0811a8a0;
      }
      if (cVar12 == 'q') goto code_r0x0811a8e1;
    }
    uVar17 = 6;
    goto LAB_0811a8a0;
  case 6:
    switch(uVar13 - 0x25 & 0xff) {
    case 0:
      iVar6 = doapr_outch(param_3_00,0x25);
      if (iVar6 != 0) goto switchD_0811aa4a_caseD_1;
      uVar7 = 0;
      goto LAB_0811a952;
    default:
      goto switchD_0811aa4a_caseD_1;
    case 0x20:
    case 0x22:
    case 0x40:
    case 0x42:
      local_68 = local_68 + 1;
      goto switchD_0811aa4a_caseD_1;
    case 0x33:
      local_70 = local_70 | 0x20;
    case 0x4a:
    case 0x50:
    case 0x53:
      local_70 = local_70 | 0x40;
      if (local_6c == (char *)0x2) {
        uVar13 = *(uint *)local_68;
        local_68 = (double *)((int)local_68 + 4);
        iVar6 = 0;
      }
      else if (local_6c == (char *)0x4) {
        iVar6 = *(int *)((int)local_68 + 4);
        uVar13 = *(uint *)local_68;
        local_68 = local_68 + 1;
      }
      else if (local_6c == (char *)0x1) {
        uVar13 = (uint)*(ushort *)local_68;
        local_68 = (double *)((int)local_68 + 4);
        iVar6 = 0;
      }
      else {
        uVar13 = *(uint *)local_68;
        local_68 = (double *)((int)local_68 + 4);
        iVar6 = 0;
      }
      uVar7 = 8;
      if ((cVar12 != 'o') && (uVar7 = 10, cVar12 != 'u')) {
        uVar7 = 0x10;
      }
LAB_0811ab81:
      iVar6 = fmtint(param_3_00,uVar13,iVar6,uVar7,local_74,local_80,local_70);
      if (iVar6 != 0) goto switchD_0811aa4a_caseD_1;
      goto LAB_0811aba0;
    case 0x3e:
      iVar6 = doapr_outch(param_3_00,*(undefined4 *)local_68);
      if (iVar6 != 0) goto LAB_0811affe;
      uVar7 = 0;
      goto LAB_0811a952;
    case 0x3f:
    case 0x44:
      if (local_6c == (char *)0x2) {
        uVar13 = *(uint *)local_68;
        local_68 = (double *)((int)local_68 + 4);
        iVar6 = (int)uVar13 >> 0x1f;
      }
      else if (local_6c == (char *)0x4) {
        iVar6 = *(int *)((int)local_68 + 4);
        uVar13 = *(uint *)local_68;
        local_68 = local_68 + 1;
      }
      else if (local_6c == (char *)0x1) {
        uVar13 = (uint)*(short *)local_68;
        local_68 = (double *)((int)local_68 + 4);
        iVar6 = (int)uVar13 >> 0x1f;
      }
      else {
        uVar13 = *(uint *)local_68;
        local_68 = (double *)((int)local_68 + 4);
        iVar6 = (int)uVar13 >> 0x1f;
      }
      uVar7 = 10;
      goto LAB_0811ab81;
    case 0x41:
      local_6c = (char *)0x6;
      pdVar1 = local_68 + 1;
      dVar2 = *local_68;
      if ((-1 < (int)local_80) && (local_6c = (char *)0x9, (int)local_80 < 10)) {
        local_6c = (char *)local_80;
      }
      if (dVar2 < 0.0) {
        dVar2 = -dVar2;
        local_80 = 1;
        local_5c = 0x2d;
      }
      else if (dVar2 < 0.0) {
        local_80 = 1;
        local_5c = 0x2d;
      }
      else if ((local_70 & 2) == 0) {
        local_80 = local_70 & 4;
        if (local_80 == 0) {
          local_5c = 0;
        }
        else {
          local_80 = 1;
          local_5c = 0x20;
        }
      }
      else {
        local_80 = 1;
        local_5c = 0x2b;
      }
      iVar6 = (int)ROUND(dVar2);
      if (local_6c == (char *)0x0) {
        iVar15 = 1;
        dVar4 = 1.0;
      }
      else {
        fVar5 = _DAT_0822397c;
        if (((((local_6c != (char *)0x1) && (fVar5 = _DAT_08223980, local_6c != (char *)0x2)) &&
             (fVar5 = _DAT_081f772c, local_6c != (char *)0x3)) &&
            ((fVar5 = _DAT_081f7728, local_6c != (char *)0x4 &&
             (fVar5 = _DAT_08223984, local_6c != (char *)0x5)))) &&
           ((fVar5 = _DAT_08223988, local_6c != (char *)0x6 &&
            ((fVar5 = _DAT_0822398c, local_6c != (char *)0x7 &&
             (fVar5 = _DAT_08223990, local_6c != (char *)0x8)))))) {
          fVar5 = _DAT_08223978;
        }
        iVar15 = (int)ROUND(fVar5);
        if (local_6c == (char *)0x1) {
          dVar4 = (double)_DAT_0822397c;
        }
        else if (local_6c == (char *)0x2) {
          dVar4 = (double)_DAT_08223980;
        }
        else if (local_6c == (char *)0x3) {
          dVar4 = (double)_DAT_081f772c;
        }
        else if (local_6c == (char *)0x4) {
          dVar4 = (double)_DAT_081f7728;
        }
        else if (local_6c == (char *)0x5) {
          dVar4 = (double)_DAT_08223984;
        }
        else if (local_6c == (char *)0x6) {
          dVar4 = (double)_DAT_08223988;
        }
        else if (local_6c == (char *)0x7) {
          dVar4 = (double)_DAT_0822398c;
        }
        else if (local_6c == (char *)0x8) {
          dVar4 = (double)_DAT_08223990;
        }
        else {
          dVar4 = (double)_DAT_08223978;
        }
      }
      dVar4 = dVar4 * (dVar2 - (double)iVar6);
      iVar10 = (int)ROUND(dVar4);
      if ((double)_DAT_08223994 <= dVar4 - (double)iVar10) {
        iVar10 = iVar10 + 1;
      }
      if (iVar15 <= iVar10) {
        iVar6 = iVar6 + 1;
        iVar10 = iVar10 - iVar15;
      }
      iVar15 = 0;
      do {
        iVar14 = iVar15;
        iVar15 = iVar14 + 1;
        iVar11 = iVar6 / 10;
        local_48[iVar14] = (&DAT_082237b4)[iVar6 % 10];
        iVar6 = iVar11;
      } while (iVar11 != 0 && iVar15 < 0x14);
      if (iVar15 == 0x14) {
        iVar15 = iVar14;
      }
      local_48[iVar15] = 0;
      iVar6 = 0;
      do {
        iVar11 = iVar6 + 1;
        acStack_35[iVar6 + 1] = (&DAT_082237b4)[iVar10 % 10];
        iVar6 = iVar11;
        iVar10 = iVar10 / 10;
      } while (iVar11 < (int)local_6c);
      uVar13 = 1;
      if (0 < (int)local_6c) {
        uVar13 = (uint)local_6c;
      }
      acStack_35[uVar13 + 1] = '\0';
      iVar6 = (((local_74 - iVar15) - (int)local_6c) + -1) - local_80;
      if (iVar6 < 0) {
        iVar6 = 0;
      }
      if ((local_70 & 1) != 0) {
        iVar6 = -iVar6;
LAB_0811af43:
        if ((local_5c != 0) && (iVar10 = doapr_outch(param_3_00,local_5c), iVar10 == 0))
        goto LAB_0811aba0;
joined_r0x0811af6e:
        do {
          if (iVar15 == 0) {
            if ((local_6c != (char *)0x0) || ((local_70 & 8) != 0)) {
              iVar15 = doapr_outch(param_3_00,0x2e);
              uVar17 = uVar13;
              if (iVar15 == 0) goto LAB_0811aba0;
              do {
                uVar18 = uVar17 - 1;
                iVar15 = doapr_outch(param_3_00,(int)acStack_35[uVar17]);
                if (iVar15 == 0) {
                  uVar7 = 0;
                  goto LAB_0811a952;
                }
                uVar17 = uVar18;
              } while (uVar18 != 0);
            }
            iVar15 = (int)local_6c - uVar13;
            if (iVar15 < 0) {
              iVar15 = 0;
            }
            for (; iVar15 != 0; iVar15 = iVar15 + -1) {
              iVar10 = doapr_outch(param_3_00,0x30);
              if (iVar10 == 0) {
                uVar7 = 0;
                goto LAB_0811a952;
              }
            }
            for (; local_68 = pdVar1, iVar6 != 0; iVar6 = iVar6 + 1) {
              iVar15 = doapr_outch_constprop_0(param_3_00);
              if (iVar15 == 0) {
                uVar7 = 0;
                goto LAB_0811a952;
              }
            }
            goto switchD_0811aa4a_caseD_1;
          }
          iVar10 = doapr_outch(param_3_00,(int)(char)local_48[iVar15 + -1]);
          iVar15 = iVar15 + -1;
          if (iVar10 == 0) {
            uVar7 = 0;
            goto LAB_0811a952;
          }
        } while( true );
      }
      if ((local_70 & 0x10) == 0) {
        if (0 < iVar6) {
          do {
            iVar10 = doapr_outch_constprop_0(param_3_00);
            if (iVar10 == 0) {
              uVar7 = 0;
              goto LAB_0811a952;
            }
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
        goto LAB_0811af43;
      }
      if (iVar6 == 0) goto LAB_0811af43;
      if (local_5c == 0) {
LAB_0811b311:
        do {
          iVar10 = doapr_outch(param_3_00,0x30);
          if (iVar10 == 0) {
            uVar7 = 0;
            goto LAB_0811a952;
          }
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        iVar6 = 0;
        goto joined_r0x0811af6e;
      }
      iVar10 = doapr_outch(param_3_00,local_5c);
      if (iVar10 != 0) {
        iVar6 = iVar6 + -1;
        if (iVar6 != 0) goto LAB_0811b311;
        iVar6 = 0;
        goto joined_r0x0811af6e;
      }
LAB_0811aba0:
      uVar7 = 0;
      goto LAB_0811a952;
    case 0x49:
      puVar3 = *(uint **)local_68;
      if (local_6c == (char *)0x1) {
        *(short *)puVar3 = (short)local_4c;
        local_68 = (double *)((int)local_68 + 4);
      }
      else if ((local_6c == (char *)0x2) || (local_6c != (char *)0x4)) {
        *puVar3 = local_4c;
        local_68 = (double *)((int)local_68 + 4);
      }
      else {
        puVar3[1] = 0;
        *puVar3 = local_4c;
        local_68 = (double *)((int)local_68 + 4);
      }
      goto switchD_0811aa4a_caseD_1;
    case 0x4b:
      iVar6 = fmtint(param_3_00,*(int *)local_68,*(int *)local_68 >> 0x1f,0x10,local_74,local_80,
                     local_70 | 8);
      if (iVar6 == 0) goto LAB_0811aba0;
LAB_0811affe:
      local_68 = (double *)((int)local_68 + 4);
      goto switchD_0811aa4a_caseD_1;
    case 0x4e:
      goto switchD_0811aa4a_caseD_4e;
    case 0x52:
      pcVar16 = pcVar16 + 1;
      goto switchD_0811aa4a_caseD_1;
    }
  }
  uVar13 = (uint)*pcVar16;
  pcVar16 = pcVar16 + 1;
  goto LAB_0811a8a0;
switchD_0811aa4a_caseD_4e:
  pdVar1 = (double *)((int)local_68 + 4);
  local_6c = *(char **)local_68;
  if (((int)local_80 < 0) && (local_80 = 0x7fffffff, param_2_00 == 0)) {
    local_80 = *param_3_00;
  }
  if (local_6c == (char *)0x0) {
    sVar9 = 6;
    local_6c = "<NULL>";
  }
  else {
    sVar9 = strlen(local_6c);
    if ((int)sVar9 < 0) {
      sVar9 = 0x7fffffff;
    }
  }
  iVar6 = local_74 - sVar9;
  if ((local_74 < 0) || (iVar6 < 0)) {
    iVar6 = 0;
    iVar15 = 0;
    goto LAB_0811b1d0;
  }
  if ((local_70 & 1) != 0) {
    iVar6 = -iVar6;
    iVar15 = 0;
    goto LAB_0811b1d0;
  }
  iVar15 = 0;
  if (((int)local_80 < 1) || (iVar6 < 1)) goto LAB_0811b1d0;
  goto LAB_0811b128;
  while( true ) {
    iVar6 = iVar6 + -1;
    iVar15 = iVar15 + 1;
    if ((iVar6 < 1) || ((int)local_80 <= iVar15)) break;
LAB_0811b128:
    iVar10 = doapr_outch_constprop_0(param_3_00);
    if (iVar10 == 0) {
      uVar7 = 0;
      goto LAB_0811a952;
    }
  }
LAB_0811b1d0:
  cVar12 = *local_6c;
  bVar19 = iVar15 < (int)local_80;
  iVar10 = iVar15;
  if ((cVar12 != '\0') && (bVar19)) {
    do {
      iVar11 = doapr_outch(param_3_00,(int)cVar12);
      if (iVar11 == 0) {
        uVar7 = 0;
        goto LAB_0811a952;
      }
      iVar10 = iVar10 + 1;
      cVar12 = local_6c[iVar10 - iVar15];
      bVar19 = iVar10 < (int)local_80;
    } while ((cVar12 != '\0') && (bVar19));
  }
  local_68 = pdVar1;
  if ((iVar6 < 0) && (iVar15 = iVar6, bVar19)) {
    do {
      iVar11 = doapr_outch_constprop_0(param_3_00);
      if (iVar11 == 0) {
        uVar7 = 0;
LAB_0811a952:
        if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return uVar7;
      }
      iVar15 = iVar15 + 1;
    } while ((iVar15 < 0) && ((iVar15 - iVar6) + iVar10 < (int)local_80));
  }
switchD_0811aa4a_caseD_1:
  uVar13 = (uint)*pcVar16;
  local_6c = (char *)0x0;
  local_70 = 0;
  uVar17 = 0;
  local_80 = 0xffffffff;
  local_74 = 0;
  pcVar16 = pcVar16 + 1;
  goto LAB_0811a8a0;
code_r0x0811a8e1:
  cVar12 = *pcVar16;
  uVar13 = (uint)cVar12;
  pcVar16 = pcVar16 + 1;
  local_6c = (char *)0x4;
  uVar17 = 6;
  goto joined_r0x0811a8a2;
}

