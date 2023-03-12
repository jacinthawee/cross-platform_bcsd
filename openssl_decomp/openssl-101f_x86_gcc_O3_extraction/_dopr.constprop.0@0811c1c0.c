
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm3
_dopr_constprop_0(int *param_1_00,uint *param_2_00,int *param_3_00,uint *param_1,byte *param_2,
                 double *param_3)

{
  double *pdVar1;
  double dVar2;
  byte bVar3;
  uint *puVar4;
  double dVar5;
  float fVar6;
  ushort **ppuVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  char cVar13;
  char cVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  char *pcVar18;
  undefined4 uVar19;
  uint uVar20;
  int in_GS_OFFSET;
  bool bVar21;
  byte *local_88;
  uint local_84;
  int local_78;
  uint local_74;
  uint local_70;
  double *local_6c;
  uint local_5c;
  undefined4 local_4c;
  char local_48 [19];
  char acStack_35 [21];
  int local_20;
  
  uVar9 = *param_2_00;
  local_4c = 0;
  local_6c = param_3;
  local_70 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar15 = (uint)*param_2;
  local_84 = 0xffffffff;
  local_78 = 0;
  local_74 = 0;
  iVar17 = 0;
  uVar8 = 0;
  local_88 = param_2 + 1;
LAB_0811c238:
  cVar13 = (char)uVar15;
  if ((cVar13 == '\0') || (uVar9 <= uVar8)) goto LAB_0811c240;
  switch(iVar17) {
  case 0:
    if (cVar13 == '%') {
      iVar17 = 1;
      uVar15 = (uint)*local_88;
      local_88 = local_88 + 1;
    }
    else {
      if (*param_1_00 == 0) goto code_r0x0811c36c;
      local_4c = uVar8 + 1;
      *(char *)(*param_1_00 + uVar8) = cVar13;
      uVar9 = *param_2_00;
      uVar15 = (uint)*local_88;
      uVar8 = local_4c;
      local_88 = local_88 + 1;
    }
    goto LAB_0811c238;
  case 1:
    switch(uVar15 - 0x20 & 0xff) {
    case 0:
      local_74 = local_74 | 4;
      uVar15 = (uint)*local_88;
      local_88 = local_88 + 1;
      break;
    default:
      iVar17 = 2;
      break;
    case 3:
      local_74 = local_74 | 8;
      uVar15 = (uint)*local_88;
      local_88 = local_88 + 1;
      break;
    case 0xb:
      local_74 = local_74 | 2;
      uVar15 = (uint)*local_88;
      local_88 = local_88 + 1;
      break;
    case 0xd:
      local_74 = local_74 | 1;
      uVar15 = (uint)*local_88;
      local_88 = local_88 + 1;
      break;
    case 0x10:
      local_74 = local_74 | 0x10;
      uVar15 = (uint)*local_88;
      local_88 = local_88 + 1;
    }
    goto LAB_0811c238;
  case 2:
    ppuVar7 = __ctype_b_loc();
    if ((*(byte *)((int)*ppuVar7 + uVar15 * 2 + 1) & 8) != 0) {
      local_78 = cVar13 + -0x30 + local_78 * 10;
      uVar15 = (uint)*local_88;
      local_88 = local_88 + 1;
      goto LAB_0811c238;
    }
    iVar17 = 3;
    if (cVar13 != '*') goto LAB_0811c238;
    local_78 = *(int *)local_6c;
    break;
  case 3:
    iVar17 = 5;
    if (cVar13 == '.') {
      iVar17 = 4;
      uVar15 = (uint)*local_88;
      local_88 = local_88 + 1;
    }
    goto LAB_0811c238;
  case 4:
    ppuVar7 = __ctype_b_loc();
    if ((*(byte *)((int)*ppuVar7 + uVar15 * 2 + 1) & 8) != 0) {
      uVar15 = 0;
      if (-1 < (int)local_84) {
        uVar15 = local_84;
      }
      local_84 = cVar13 + -0x30 + uVar15 * 10;
      uVar15 = (uint)*local_88;
      local_88 = local_88 + 1;
      goto LAB_0811c238;
    }
    iVar17 = 5;
    if (cVar13 != '*') goto LAB_0811c238;
    local_84 = *(uint *)local_6c;
    break;
  case 5:
    if (cVar13 != 'h') {
      if (cVar13 < 'i') {
        if (cVar13 == 'L') {
          local_70 = 3;
          iVar17 = 6;
          uVar15 = (uint)*local_88;
          local_88 = local_88 + 1;
          goto LAB_0811c238;
        }
      }
      else {
        if (cVar13 == 'l') {
          local_70 = 2;
          bVar3 = *local_88;
          if (bVar3 == 0x6c) {
            bVar3 = local_88[1];
            local_88 = local_88 + 1;
            local_70 = 4;
          }
          uVar15 = (uint)bVar3;
          iVar17 = 6;
          local_88 = local_88 + 1;
          goto LAB_0811c238;
        }
        if (cVar13 == 'q') {
          local_70 = 4;
          iVar17 = 6;
          uVar15 = (uint)*local_88;
          local_88 = local_88 + 1;
          goto LAB_0811c238;
        }
      }
      iVar17 = 6;
      goto LAB_0811c238;
    }
    local_70 = 1;
    iVar17 = 6;
    uVar15 = (uint)*local_88;
    local_88 = local_88 + 1;
    goto LAB_0811c238;
  case 6:
    switch(uVar15 - 0x25 & 0xff) {
    case 0:
      if (*param_1_00 == 0) goto code_r0x0811c36c;
      local_4c = uVar8 + 1;
      *(undefined *)(*param_1_00 + uVar8) = 0x25;
      uVar9 = *param_2_00;
      uVar8 = local_4c;
      break;
    case 0x20:
    case 0x22:
    case 0x40:
    case 0x42:
      local_6c = local_6c + 1;
      break;
    case 0x33:
      local_74 = local_74 | 0x20;
    case 0x4a:
    case 0x50:
    case 0x53:
      local_74 = local_74 | 0x40;
      if (local_70 == 2) {
        uVar8 = *(uint *)local_6c;
        local_6c = (double *)((int)local_6c + 4);
        iVar17 = 0;
      }
      else if (local_70 == 4) {
        iVar17 = *(int *)((int)local_6c + 4);
        uVar8 = *(uint *)local_6c;
        local_6c = local_6c + 1;
      }
      else if (local_70 == 1) {
        uVar8 = (uint)*(ushort *)local_6c;
        local_6c = (double *)((int)local_6c + 4);
        iVar17 = 0;
      }
      else {
        uVar8 = *(uint *)local_6c;
        local_6c = (double *)((int)local_6c + 4);
        iVar17 = 0;
      }
      uVar19 = 8;
      if ((cVar13 != 'o') && (uVar19 = 10, cVar13 != 'u')) {
        uVar19 = 0x10;
      }
LAB_0811c74b:
      fmtint_constprop_3(uVar8,iVar17,uVar19,local_78,local_84,local_74);
      uVar9 = *param_2_00;
      uVar8 = local_4c;
      break;
    case 0x3e:
      if (*param_1_00 == 0) goto code_r0x0811c36c;
      local_4c = uVar8 + 1;
      *(char *)(*param_1_00 + uVar8) = (char)*(undefined4 *)local_6c;
      uVar9 = *param_2_00;
      uVar8 = local_4c;
      local_6c = (double *)((int)local_6c + 4);
      break;
    case 0x3f:
    case 0x44:
      if (local_70 == 2) {
        uVar8 = *(uint *)local_6c;
        local_6c = (double *)((int)local_6c + 4);
        iVar17 = (int)uVar8 >> 0x1f;
      }
      else if (local_70 == 4) {
        iVar17 = *(int *)((int)local_6c + 4);
        uVar8 = *(uint *)local_6c;
        local_6c = local_6c + 1;
      }
      else if (local_70 == 1) {
        uVar8 = (uint)*(short *)local_6c;
        local_6c = (double *)((int)local_6c + 4);
        iVar17 = (int)uVar8 >> 0x1f;
      }
      else {
        uVar8 = *(uint *)local_6c;
        local_6c = (double *)((int)local_6c + 4);
        iVar17 = (int)uVar8 >> 0x1f;
      }
      uVar19 = 10;
      goto LAB_0811c74b;
    case 0x41:
      local_70 = 6;
      dVar2 = *local_6c;
      local_6c = local_6c + 1;
      if ((-1 < (int)local_84) && (local_70 = 9, (int)local_84 < 10)) {
        local_70 = local_84;
      }
      if (dVar2 < 0.0) {
        dVar2 = -dVar2;
        local_5c = 1;
        cVar13 = '-';
      }
      else if (dVar2 < 0.0) {
        local_5c = 1;
        cVar13 = '-';
      }
      else if ((local_74 & 2) == 0) {
        local_5c = local_74 & 4;
        if (local_5c == 0) {
          cVar13 = '\0';
        }
        else {
          local_5c = 1;
          cVar13 = ' ';
        }
      }
      else {
        local_5c = 1;
        cVar13 = '+';
      }
      local_84 = (uint)ROUND(dVar2);
      if (local_70 == 0) {
        iVar17 = 1;
        dVar5 = 1.0;
      }
      else {
        fVar6 = _DAT_08223724;
        if (((((local_70 != 1) && (fVar6 = _DAT_08223728, local_70 != 2)) &&
             (fVar6 = _DAT_081f7088, local_70 != 3)) &&
            ((fVar6 = _DAT_081f7084, local_70 != 4 && (fVar6 = _DAT_0822372c, local_70 != 5)))) &&
           ((fVar6 = _DAT_08223730, local_70 != 6 &&
            ((fVar6 = _DAT_08223734, local_70 != 7 && (fVar6 = _DAT_08223738, local_70 != 8)))))) {
          fVar6 = _DAT_08223720;
        }
        iVar17 = (int)ROUND(fVar6);
        if (local_70 == 1) {
          dVar5 = (double)_DAT_08223724;
        }
        else if (local_70 == 2) {
          dVar5 = (double)_DAT_08223728;
        }
        else if (local_70 == 3) {
          dVar5 = (double)_DAT_081f7088;
        }
        else if (local_70 == 4) {
          dVar5 = (double)_DAT_081f7084;
        }
        else if (local_70 == 5) {
          dVar5 = (double)_DAT_0822372c;
        }
        else if (local_70 == 6) {
          dVar5 = (double)_DAT_08223730;
        }
        else if (local_70 == 7) {
          dVar5 = (double)_DAT_08223734;
        }
        else if (local_70 == 8) {
          dVar5 = (double)_DAT_08223738;
        }
        else {
          dVar5 = (double)_DAT_08223720;
        }
      }
      dVar5 = dVar5 * (dVar2 - (double)local_84);
      iVar11 = (int)ROUND(dVar5);
      if ((double)_DAT_0822373c <= dVar5 - (double)iVar11) {
        iVar11 = iVar11 + 1;
      }
      if (iVar17 <= iVar11) {
        local_84 = local_84 + 1;
        iVar11 = iVar11 - iVar17;
      }
      iVar17 = 0;
      do {
        iVar16 = iVar17;
        iVar17 = iVar16 + 1;
        iVar10 = (int)local_84 / 10;
        local_48[iVar16] = "0123456789abcdef"[(int)local_84 % 10];
        local_84 = iVar10;
      } while (iVar10 != 0 && iVar17 < 0x14);
      if (iVar17 == 0x14) {
        iVar17 = iVar16;
      }
      local_48[iVar17] = '\0';
      iVar10 = 0;
      do {
        iVar16 = iVar10 + 1;
        acStack_35[iVar10 + 1] = "0123456789abcdef"[iVar11 % 10];
        iVar11 = iVar11 / 10;
        iVar10 = iVar16;
      } while (iVar16 < (int)local_70);
      uVar15 = 1;
      if (0 < (int)local_70) {
        uVar15 = local_70;
      }
      acStack_35[uVar15 + 1] = '\0';
      iVar11 = local_70 - uVar15;
      if (iVar11 < 0) {
        iVar11 = 0;
      }
      iVar16 = (((local_78 - iVar17) - local_70) + -1) - local_5c;
      iVar10 = 0;
      if (-1 < iVar16) {
        iVar10 = iVar16;
      }
      if ((local_74 & 1) == 0) {
        if ((local_74 & 0x10) == 0) {
          if (iVar10 < 1) goto LAB_0811ca06;
          do {
            uVar20 = uVar8;
            if (uVar8 < uVar9) {
              if (*param_1_00 == 0) {
                do {
                  invalidInstructionException();
                } while( true );
              }
              uVar20 = uVar8 + 1;
              *(undefined *)(*param_1_00 + uVar8) = 0x20;
              uVar9 = *param_2_00;
              local_4c = uVar20;
            }
            iVar10 = iVar10 + -1;
            uVar8 = uVar20;
          } while (iVar10 != 0);
          if ((cVar13 == '\0') || (uVar9 <= uVar20)) goto joined_r0x0811ca14;
          goto LAB_0811cec8;
        }
        if (iVar10 == 0) goto LAB_0811ca06;
        if (cVar13 != '\0') {
          if (*param_1_00 == 0) goto code_r0x0811c36c;
          local_4c = uVar8 + 1;
          iVar10 = iVar10 + -1;
          *(char *)(*param_1_00 + uVar8) = cVar13;
          if (iVar10 == 0) {
            iVar10 = 0;
            uVar9 = *param_2_00;
            uVar20 = local_4c;
            goto joined_r0x0811ca14;
          }
          uVar9 = *param_2_00;
          uVar8 = local_4c;
        }
        do {
          uVar20 = uVar8;
          if (uVar8 < uVar9) {
            if (*param_1_00 == 0) goto code_r0x0811c36c;
            uVar20 = uVar8 + 1;
            *(undefined *)(*param_1_00 + uVar8) = 0x30;
            uVar9 = *param_2_00;
            local_4c = uVar20;
          }
          iVar10 = iVar10 + -1;
          uVar8 = uVar20;
        } while (iVar10 != 0);
        iVar10 = 0;
      }
      else {
        iVar10 = -iVar10;
LAB_0811ca06:
        uVar20 = uVar8;
        if (cVar13 != '\0') {
LAB_0811cec8:
          if (*param_1_00 == 0) goto code_r0x0811c36c;
          local_4c = uVar20 + 1;
          *(char *)(*param_1_00 + uVar20) = cVar13;
          uVar9 = *param_2_00;
          uVar20 = local_4c;
        }
      }
joined_r0x0811ca14:
      while (iVar16 = iVar17, iVar16 != 0) {
        iVar17 = iVar16 + -1;
        if (uVar20 < uVar9) {
          if (*param_1_00 == 0) {
            do {
              invalidInstructionException();
            } while( true );
          }
          local_4c = uVar20 + 1;
          *(char *)(*param_1_00 + uVar20) = local_48[iVar16 + -1];
          uVar9 = *param_2_00;
          uVar20 = local_4c;
        }
      }
      if ((local_70 != 0) || (uVar8 = uVar20, (local_74 & 8) != 0)) {
        if (uVar20 < uVar9) {
          if (*param_1_00 == 0) goto code_r0x0811c36c;
          local_4c = uVar20 + 1;
          *(undefined *)(*param_1_00 + uVar20) = 0x2e;
          uVar9 = *param_2_00;
          uVar20 = local_4c;
        }
        do {
          uVar12 = uVar15 - 1;
          uVar8 = uVar20;
          if (uVar20 < uVar9) {
            if (*param_1_00 == 0) {
              do {
                invalidInstructionException();
              } while( true );
            }
            uVar8 = uVar20 + 1;
            *(char *)(*param_1_00 + uVar20) = acStack_35[uVar15];
            uVar9 = *param_2_00;
            local_4c = uVar8;
          }
          uVar15 = uVar12;
          uVar20 = uVar8;
        } while (uVar12 != 0);
      }
      for (; iVar11 != 0; iVar11 = iVar11 + -1) {
        uVar15 = uVar8;
        if (uVar8 < uVar9) {
          if (*param_1_00 == 0) {
            do {
              invalidInstructionException();
            } while( true );
          }
          uVar15 = uVar8 + 1;
          *(undefined *)(*param_1_00 + uVar8) = 0x30;
          uVar9 = *param_2_00;
          local_4c = uVar15;
        }
        uVar8 = uVar15;
      }
      for (; iVar10 != 0; iVar10 = iVar10 + 1) {
        uVar15 = uVar8;
        if (uVar8 < uVar9) {
          if (*param_1_00 == 0) {
            do {
              invalidInstructionException();
            } while( true );
          }
          uVar15 = uVar8 + 1;
          *(undefined *)(*param_1_00 + uVar8) = 0x20;
          uVar9 = *param_2_00;
          local_4c = uVar15;
        }
        uVar8 = uVar15;
      }
      break;
    case 0x49:
      puVar4 = *(uint **)local_6c;
      if (local_70 == 1) {
        *(short *)puVar4 = (short)uVar8;
        local_6c = (double *)((int)local_6c + 4);
      }
      else {
        if (local_70 == 2) {
          *puVar4 = uVar8;
        }
        else {
          *puVar4 = uVar8;
          if (local_70 == 4) {
            puVar4[1] = 0;
            local_6c = (double *)((int)local_6c + 4);
            break;
          }
          uVar9 = *param_2_00;
        }
        uVar8 = local_4c;
        local_6c = (double *)((int)local_6c + 4);
      }
      break;
    case 0x4b:
      fmtint_constprop_3(*(int *)local_6c,*(int *)local_6c >> 0x1f,0x10,local_78,local_84,
                         local_74 | 8);
      uVar9 = *param_2_00;
      uVar8 = local_4c;
      local_6c = (double *)((int)local_6c + 4);
      break;
    case 0x4e:
      pdVar1 = (double *)((int)local_6c + 4);
      pcVar18 = *(char **)local_6c;
      if ((int)local_84 < 0) {
        local_84 = uVar9;
      }
      if (pcVar18 == (char *)0x0) {
        pcVar18 = "<NULL>";
      }
      iVar17 = 0;
      cVar14 = *pcVar18;
      cVar13 = cVar14;
      while (cVar13 != '\0') {
        iVar17 = iVar17 + 1;
        cVar13 = pcVar18[iVar17];
      }
      iVar11 = 0;
      local_78 = local_78 - iVar17;
      if (local_78 < 0) {
        local_78 = 0;
      }
      if ((local_74 & 1) == 0) {
        if ((local_78 < 1) || ((int)local_84 < 1)) goto LAB_0811c2ff;
        do {
          uVar15 = uVar8;
          if (uVar8 < uVar9) {
            if (*param_1_00 == 0) {
              do {
                invalidInstructionException();
              } while( true );
            }
            uVar15 = uVar8 + 1;
            *(undefined *)(*param_1_00 + uVar8) = 0x20;
            uVar9 = *param_2_00;
            local_4c = uVar15;
          }
          iVar11 = iVar11 + 1;
          local_78 = local_78 + -1;
          bVar21 = iVar11 < (int)local_84;
        } while ((0 < local_78) && (uVar8 = uVar15, bVar21));
        cVar14 = *pcVar18;
      }
      else {
        local_78 = -local_78;
LAB_0811c2ff:
        bVar21 = 0 < (int)local_84;
        iVar11 = 0;
        uVar15 = uVar8;
      }
      iVar17 = iVar11;
      if ((cVar14 != '\0') && (bVar21)) {
        uVar8 = uVar15;
        do {
          uVar15 = uVar8;
          if (uVar8 < uVar9) {
            if (*param_1_00 == 0) goto code_r0x0811c36c;
            uVar15 = uVar8 + 1;
            *(char *)(*param_1_00 + uVar8) = cVar14;
            uVar9 = *param_2_00;
            local_4c = uVar15;
          }
          iVar17 = iVar17 + 1;
          cVar14 = pcVar18[iVar17 - iVar11];
          bVar21 = iVar17 < (int)local_84;
        } while ((cVar14 != '\0') && (uVar8 = uVar15, bVar21));
      }
      uVar8 = uVar15;
      local_6c = pdVar1;
      if ((local_78 < 0) && (iVar11 = local_78, bVar21)) {
        do {
          uVar8 = uVar15;
          if (uVar15 < uVar9) {
            if (*param_1_00 == 0) {
              do {
                invalidInstructionException();
              } while( true );
            }
            uVar8 = uVar15 + 1;
            *(undefined *)(*param_1_00 + uVar15) = 0x20;
            uVar9 = *param_2_00;
            local_4c = uVar8;
          }
          iVar11 = iVar11 + 1;
        } while ((iVar11 < 0) && (uVar15 = uVar8, (iVar11 - local_78) + iVar17 < (int)local_84));
      }
      break;
    case 0x52:
      local_88 = local_88 + 1;
    }
    uVar15 = (uint)*local_88;
    local_70 = 0;
    local_74 = 0;
    local_84 = 0xffffffff;
    local_78 = 0;
    iVar17 = 0;
    local_88 = local_88 + 1;
    goto LAB_0811c238;
  default:
    goto switchD_0811c381_caseD_7;
  }
  local_6c = (double *)((int)local_6c + 4);
  uVar15 = (uint)*local_88;
  local_88 = local_88 + 1;
  goto LAB_0811c238;
switchD_0811c381_caseD_7:
  if (iVar17 == 7) {
LAB_0811c240:
    bVar21 = uVar9 - 1 < uVar8;
    *param_1 = (uint)bVar21;
    if (bVar21) {
      uVar8 = *param_2_00 - 1;
      local_4c = uVar8;
    }
    uVar9 = uVar8;
    if (uVar8 < *param_2_00) {
      if (*param_1_00 == 0) {
code_r0x0811c36c:
        do {
          invalidInstructionException();
        } while( true );
      }
      uVar9 = uVar8 + 1;
      *(undefined *)(*param_1_00 + uVar8) = 0;
      local_4c = uVar9;
    }
    *param_3_00 = uVar9 - 1;
    if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  goto LAB_0811c238;
}

