
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int BIO_vprintf(BIO *bio,char *format,va_list args)

{
  double *pdVar1;
  double dVar2;
  char cVar3;
  bool bVar4;
  double dVar5;
  float fVar6;
  undefined *puVar7;
  int iVar8;
  ushort **ppuVar9;
  undefined4 uVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  char cVar14;
  uint uVar15;
  int iVar16;
  int *piVar17;
  byte bVar18;
  byte *pbVar19;
  int iVar20;
  int *piVar21;
  int in_GS_OFFSET;
  int *local_888;
  double *local_884;
  byte *local_880;
  int *local_878;
  uint local_874;
  int *local_870;
  int local_86c;
  undefined *local_858;
  uint local_854;
  undefined *local_850;
  undefined4 local_84c;
  char local_848 [19];
  char acStack_835 [21];
  undefined local_820 [2048];
  int local_20;
  
  local_854 = 0x800;
  local_850 = (undefined *)0x0;
  local_880 = (byte *)(format + 1);
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_858 = local_820;
  CRYPTO_push_info_("doapr()","b_print.c",0x31a);
  bVar18 = *format;
  local_84c = 0;
  local_884 = (double *)args;
joined_r0x0811d0fa:
  if (bVar18 != 0) {
    while (bVar18 != 0x25) {
      while (uVar15 = local_84c, local_854 <= local_84c) {
        while (local_850 != (undefined *)0x0) {
          local_854 = local_854 + 0x400;
          local_850 = (undefined *)CRYPTO_realloc(local_850,local_854,"b_print.c",0x2ed);
          uVar15 = local_84c;
          if (local_84c < local_854) goto LAB_0811d211;
        }
        if (local_854 == 0) {
          local_854 = 0x400;
        }
        local_850 = (undefined *)CRYPTO_malloc(local_854,"b_print.c",0x2e5);
        if (local_84c != 0) {
          memcpy(local_850,local_858,local_84c);
        }
        local_858 = (undefined *)0x0;
      }
LAB_0811d211:
      puVar7 = local_850;
      if (local_858 != (undefined *)0x0) {
        puVar7 = local_858;
      }
      local_84c = uVar15 + 1;
      puVar7[uVar15] = bVar18;
      bVar18 = *local_880;
      local_880 = local_880 + 1;
      if (bVar18 == 0) goto LAB_0811d118;
    }
    bVar18 = *local_880;
    if (bVar18 != 0) {
      local_874 = 0;
      do {
        uVar15 = (uint)bVar18;
        local_880 = local_880 + 1;
        switch(uVar15 - 0x20 & 0xff) {
        case 0:
          bVar18 = *local_880;
          local_874 = local_874 | 4;
          break;
        default:
          goto switchD_0811d320_caseD_1;
        case 3:
          bVar18 = *local_880;
          local_874 = local_874 | 8;
          break;
        case 0xb:
          bVar18 = *local_880;
          local_874 = local_874 | 2;
          break;
        case 0xd:
          bVar18 = *local_880;
          local_874 = local_874 | 1;
          break;
        case 0x10:
          bVar18 = *local_880;
          local_874 = local_874 | 0x10;
        }
        if (bVar18 == 0) break;
      } while( true );
    }
  }
LAB_0811d118:
  if (local_854 - 1 < local_84c) {
    local_84c = local_854 - 1;
  }
  while (uVar15 = local_84c, local_854 <= local_84c) {
    if (local_850 == (undefined *)0x0) {
      if (local_854 == 0) {
        local_854 = 0x400;
      }
      local_850 = (undefined *)CRYPTO_malloc(local_854,"b_print.c",0x2e5);
      if (local_84c != 0) {
        memcpy(local_850,local_858,local_84c);
      }
      local_858 = (undefined *)0x0;
    }
    else {
      local_854 = local_854 + 0x400;
      local_850 = (undefined *)CRYPTO_realloc(local_850,local_854,"b_print.c",0x2ed);
    }
  }
  if (local_858 == (undefined *)0x0) {
    local_850[local_84c] = 0;
  }
  else {
    local_858[local_84c] = 0;
  }
  local_84c = local_84c + 1;
  if (local_850 == (undefined *)0x0) {
    iVar8 = BIO_write(bio,local_820,uVar15);
  }
  else {
    iVar8 = BIO_write(bio,local_850,uVar15);
    CRYPTO_free(local_850);
  }
  CRYPTO_pop_info();
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
switchD_0811d320_caseD_1:
  local_878 = (int *)0x0;
  while( true ) {
    ppuVar9 = __ctype_b_loc();
    if ((*(byte *)((int)*ppuVar9 + uVar15 * 2 + 1) & 8) == 0) break;
    local_878 = (int *)((char)uVar15 + -0x30 + (int)local_878 * 10);
    bVar18 = *local_880;
    uVar15 = (uint)bVar18;
    local_880 = local_880 + 1;
    if (bVar18 == 0) goto LAB_0811d118;
  }
  if ((char)uVar15 == '*') {
    bVar18 = *local_880;
    uVar15 = (uint)bVar18;
    local_880 = local_880 + 1;
    local_878 = *(int **)local_884;
    local_884 = (double *)((int)local_884 + 4);
    if (bVar18 == 0) goto LAB_0811d118;
  }
  local_888 = (int *)0xffffffff;
  if ((char)uVar15 == '.') {
    bVar18 = *local_880;
    if (bVar18 == 0) goto LAB_0811d118;
    local_888 = (int *)0xffffffff;
    pbVar19 = local_880;
    while( true ) {
      local_880 = pbVar19 + 1;
      uVar15 = (uint)bVar18;
      ppuVar9 = __ctype_b_loc();
      if ((*(byte *)((int)*ppuVar9 + uVar15 * 2 + 1) & 8) == 0) break;
      if ((int)local_888 < 0) {
        local_888 = (int *)0x0;
      }
      local_888 = (int *)((char)bVar18 + -0x30 + (int)local_888 * 10);
      bVar18 = *local_880;
      pbVar19 = local_880;
      if (bVar18 == 0) goto LAB_0811d118;
    }
    if (bVar18 == 0x2a) {
      bVar18 = *local_880;
      uVar15 = (uint)bVar18;
      local_880 = pbVar19 + 2;
      local_888 = *(int **)local_884;
      local_884 = (double *)((int)local_884 + 4);
      if (bVar18 == 0) goto LAB_0811d118;
    }
  }
  piVar21 = local_888;
  cVar14 = (char)uVar15;
  if (cVar14 == 'h') {
    bVar18 = *local_880;
    uVar15 = (uint)bVar18;
    local_880 = local_880 + 1;
    if (bVar18 == 0) goto LAB_0811d118;
    iVar8 = 1;
  }
  else if (cVar14 < 'i') {
    if (cVar14 == 'L') {
      bVar18 = *local_880;
      uVar15 = (uint)bVar18;
      local_880 = local_880 + 1;
      if (bVar18 == 0) goto LAB_0811d118;
      iVar8 = 3;
    }
    else {
LAB_0811e1e0:
      iVar8 = 0;
    }
  }
  else if (cVar14 == 'l') {
    bVar18 = *local_880;
    iVar8 = 2;
    if (bVar18 == 0x6c) {
      bVar18 = local_880[1];
      iVar8 = 4;
      local_880 = local_880 + 1;
    }
    uVar15 = (uint)bVar18;
    local_880 = local_880 + 1;
    if (bVar18 == 0) goto LAB_0811d118;
  }
  else {
    if (cVar14 != 'q') goto LAB_0811e1e0;
    bVar18 = *local_880;
    uVar15 = (uint)bVar18;
    local_880 = local_880 + 1;
    if (bVar18 == 0) goto LAB_0811d118;
    iVar8 = 4;
  }
  pdVar1 = local_884;
  switch(uVar15 - 0x25 & 0xff) {
  case 0:
    while (local_854 <= local_84c) {
      while (local_850 != (undefined *)0x0) {
        local_854 = local_854 + 0x400;
        local_850 = (undefined *)CRYPTO_realloc(local_850,local_854,"b_print.c",0x2ed);
        if (local_84c < local_854) goto LAB_0811db6a;
      }
      if (local_854 == 0) {
        local_854 = 0x400;
      }
      local_850 = (undefined *)CRYPTO_malloc(local_854,"b_print.c",0x2e5);
      if (local_84c != 0) {
        memcpy(local_850,local_858,local_84c);
      }
      local_858 = (undefined *)0x0;
    }
LAB_0811db6a:
    if (local_858 == (undefined *)0x0) {
      local_850[local_84c] = 0x25;
      local_84c = local_84c + 1;
    }
    else {
      local_858[local_84c] = 0x25;
      local_84c = local_84c + 1;
    }
    break;
  case 0x20:
  case 0x22:
  case 0x40:
  case 0x42:
    pdVar1 = local_884 + 1;
    break;
  case 0x33:
    local_874 = local_874 | 0x20;
  case 0x4a:
  case 0x50:
  case 0x53:
    local_874 = local_874 | 0x40;
    if (iVar8 == 2) {
      piVar17 = (int *)0x0;
      piVar21 = *(int **)local_884;
      local_884 = (double *)((int)local_884 + 4);
    }
    else if (iVar8 == 4) {
      piVar21 = *(int **)local_884;
      piVar17 = *(int **)((int)local_884 + 4);
      local_884 = local_884 + 1;
    }
    else if (iVar8 == 1) {
      piVar21 = (int *)(uint)*(ushort *)local_884;
      local_884 = (double *)((int)local_884 + 4);
      piVar17 = (int *)0x0;
    }
    else {
      piVar21 = *(int **)local_884;
      local_884 = (double *)((int)local_884 + 4);
      piVar17 = (int *)0x0;
    }
    uVar10 = 8;
    if (((char)uVar15 != 'o') && (uVar10 = 0x10, (char)uVar15 == 'u')) {
      uVar10 = 10;
    }
LAB_0811d564:
    fmtint(&local_854,piVar21,piVar17,uVar10,local_878,local_888,local_874);
    pdVar1 = local_884;
    break;
  case 0x3e:
    piVar21 = *(int **)local_884;
    while (local_854 <= local_84c) {
      while (local_850 != (undefined *)0x0) {
        local_854 = local_854 + 0x400;
        local_850 = (undefined *)CRYPTO_realloc(local_850,local_854,"b_print.c",0x2ed);
        if (local_84c < local_854) goto LAB_0811d967;
      }
      if (local_854 == 0) {
        local_854 = 0x400;
      }
      local_850 = (undefined *)CRYPTO_malloc(local_854,"b_print.c",0x2e5);
      if (local_84c != 0) {
        memcpy(local_850,local_858,local_84c);
      }
      local_858 = (undefined *)0x0;
    }
LAB_0811d967:
    pdVar1 = (double *)((int)local_884 + 4);
    if (local_858 == (undefined *)0x0) {
      local_850[local_84c] = (char)piVar21;
      local_84c = local_84c + 1;
    }
    else {
      local_858[local_84c] = (char)piVar21;
      local_84c = local_84c + 1;
    }
    break;
  case 0x3f:
  case 0x44:
    if (iVar8 == 2) {
      piVar21 = *(int **)local_884;
      local_884 = (double *)((int)local_884 + 4);
      piVar17 = (int *)((int)piVar21 >> 0x1f);
    }
    else if (iVar8 == 4) {
      piVar17 = *(int **)((int)local_884 + 4);
      piVar21 = *(int **)local_884;
      local_884 = local_884 + 1;
    }
    else if (iVar8 == 1) {
      piVar21 = (int *)(int)*(short *)local_884;
      local_884 = (double *)((int)local_884 + 4);
      piVar17 = (int *)((int)piVar21 >> 0x1f);
    }
    else {
      piVar21 = *(int **)local_884;
      local_884 = (double *)((int)local_884 + 4);
      piVar17 = (int *)((int)piVar21 >> 0x1f);
    }
    uVar10 = 10;
    goto LAB_0811d564;
  case 0x41:
    local_870 = (int *)0x6;
    dVar2 = *local_884;
    if ((-1 < (int)local_888) && (local_870 = (int *)0x9, (int)local_888 < 10)) {
      local_870 = local_888;
    }
    if (dVar2 < 0.0) {
      dVar2 = -dVar2;
      local_888 = (int *)0x1;
      local_86c = 0x2d;
    }
    else if (dVar2 < 0.0) {
      local_888 = (int *)0x1;
      local_86c = 0x2d;
    }
    else if ((local_874 & 2) == 0) {
      local_888 = (int *)(local_874 & 4);
      if (local_888 == (int *)0x0) {
        local_86c = 0;
      }
      else {
        local_888 = (int *)0x1;
        local_86c = 0x20;
      }
    }
    else {
      local_888 = (int *)0x1;
      local_86c = 0x2b;
    }
    iVar8 = (int)ROUND(dVar2);
    if (local_870 == (int *)0x0) {
      iVar12 = 1;
      dVar5 = 1.0;
    }
    else {
      fVar6 = _DAT_08223724;
      if (((((local_870 != (int *)0x1) && (fVar6 = _DAT_08223728, local_870 != (int *)0x2)) &&
           (fVar6 = _DAT_081f7088, local_870 != (int *)0x3)) &&
          ((fVar6 = _DAT_081f7084, local_870 != (int *)&DAT_00000004 &&
           (fVar6 = _DAT_0822372c, local_870 != (int *)0x5)))) &&
         ((fVar6 = _DAT_08223730, local_870 != (int *)0x6 &&
          ((fVar6 = _DAT_08223734, local_870 != (int *)0x7 &&
           (fVar6 = _DAT_08223738, local_870 != (int *)&DAT_00000008)))))) {
        fVar6 = _DAT_08223720;
      }
      iVar12 = (int)ROUND(fVar6);
      if (local_870 == (int *)0x1) {
        dVar5 = (double)_DAT_08223724;
      }
      else if (local_870 == (int *)0x2) {
        dVar5 = (double)_DAT_08223728;
      }
      else if (local_870 == (int *)0x3) {
        dVar5 = (double)_DAT_081f7088;
      }
      else if (local_870 == (int *)&DAT_00000004) {
        dVar5 = (double)_DAT_081f7084;
      }
      else if (local_870 == (int *)0x5) {
        dVar5 = (double)_DAT_0822372c;
      }
      else if (local_870 == (int *)0x6) {
        dVar5 = (double)_DAT_08223730;
      }
      else if (local_870 == (int *)0x7) {
        dVar5 = (double)_DAT_08223734;
      }
      else if (local_870 == (int *)&DAT_00000008) {
        dVar5 = (double)_DAT_08223738;
      }
      else {
        dVar5 = (double)_DAT_08223720;
      }
    }
    dVar5 = dVar5 * (dVar2 - (double)iVar8);
    iVar16 = (int)ROUND(dVar5);
    if ((double)_DAT_0822373c <= dVar5 - (double)iVar16) {
      iVar16 = iVar16 + 1;
    }
    if (iVar12 <= iVar16) {
      iVar8 = iVar8 + 1;
      iVar16 = iVar16 - iVar12;
    }
    iVar12 = 0;
    do {
      iVar20 = iVar12;
      iVar12 = iVar20 + 1;
      iVar13 = iVar8 / 10;
      local_848[iVar20] = "0123456789abcdef"[iVar8 % 10];
      iVar8 = iVar13;
    } while (iVar13 != 0 && iVar12 < 0x14);
    if (iVar12 == 0x14) {
      iVar12 = iVar20;
    }
    local_848[iVar12] = '\0';
    iVar8 = 0;
    do {
      iVar13 = iVar8 + 1;
      acStack_835[iVar8 + 1] = "0123456789abcdef"[iVar16 % 10];
      iVar8 = iVar13;
      iVar16 = iVar16 / 10;
    } while (iVar13 < (int)local_870);
    piVar21 = (int *)0x1;
    if (0 < (int)local_870) {
      piVar21 = local_870;
    }
    (acStack_835 + 1)[(int)piVar21] = '\0';
    iVar8 = (int)local_870 - (int)piVar21;
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    iVar16 = (int)local_878 + (((-(int)local_870 - iVar12) + -1) - (int)local_888);
    local_888 = (int *)0;
    if (-1 < iVar16) {
      local_888 = (int *)iVar16;
    }
    if ((local_874 & 1) == 0) {
      if ((local_874 & 0x10) == 0) {
        if (0 < (int)local_888) {
          do {
            doapr_outch_constprop_5(&local_854);
            local_888 = (int *)((int)local_888 + -1);
          } while (local_888 != (int *)0x0);
        }
        goto LAB_0811d7f8;
      }
      if (local_888 == (int *)0x0) goto LAB_0811d7f8;
      if (local_86c != 0) {
        doapr_outch(&local_854,local_86c);
        goto joined_r0x0811e0b2;
      }
      do {
        doapr_outch(&local_854,0x30);
joined_r0x0811e0b2:
        local_888 = (int *)((int)local_888 + -1);
      } while (local_888 != (int *)0x0);
      local_888 = (int *)0x0;
    }
    else {
      local_888 = (int *)-(int)local_888;
LAB_0811d7f8:
      if (local_86c != 0) {
        doapr_outch(&local_854,local_86c);
      }
    }
    while (iVar12 != 0) {
      cVar14 = local_848[iVar12 + -1];
      while (local_854 <= local_84c) {
        while (local_850 != (undefined *)0x0) {
          local_854 = local_854 + 0x400;
          local_850 = (undefined *)CRYPTO_realloc(local_850,local_854,"b_print.c",0x2ed);
          if (local_84c < local_854) goto LAB_0811d875;
        }
        if (local_854 == 0) {
          local_854 = 0x400;
        }
        local_850 = (undefined *)CRYPTO_malloc(local_854,"b_print.c",0x2e5);
        if (local_84c != 0) {
          memcpy(local_850,local_858,local_84c);
        }
        local_858 = (undefined *)0x0;
      }
LAB_0811d875:
      if (local_858 == (undefined *)0x0) {
        local_850[local_84c] = cVar14;
        iVar12 = iVar12 + -1;
        local_84c = local_84c + 1;
      }
      else {
        local_858[local_84c] = cVar14;
        iVar12 = iVar12 + -1;
        local_84c = local_84c + 1;
      }
    }
    if ((local_870 != (int *)0x0) || ((local_874 & 8) != 0)) {
      doapr_outch(&local_854,0x2e);
      do {
        piVar21 = (int *)((int)piVar21 + -1);
        doapr_outch(&local_854,(int)(acStack_835 + 1)[(int)piVar21]);
      } while (piVar21 != (int *)0x0);
    }
    for (; iVar8 != 0; iVar8 = iVar8 + -1) {
      doapr_outch(&local_854,0x30);
    }
    for (; pdVar1 = local_884 + 1, local_888 != (int *)0x0; local_888 = (int *)((int)local_888 + 1))
    {
      doapr_outch_constprop_5(&local_854);
    }
    break;
  case 0x49:
    if (iVar8 == 1) {
      *(short *)*(int **)local_884 = (short)local_84c;
      pdVar1 = (double *)((int)local_884 + 4);
    }
    else {
      if (iVar8 == 2) {
        puVar11 = *(uint **)local_884;
      }
      else {
        puVar11 = *(uint **)local_884;
        if (iVar8 == 4) {
          puVar11[1] = 0;
          *puVar11 = local_84c;
          pdVar1 = (double *)((int)local_884 + 4);
          break;
        }
      }
      *puVar11 = local_84c;
      pdVar1 = (double *)((int)local_884 + 4);
    }
    break;
  case 0x4b:
    fmtint(&local_854,*(int **)local_884,(int)*(int **)local_884 >> 0x1f,0x10,local_878,local_888,
           local_874 | 8);
    pdVar1 = (double *)((int)local_884 + 4);
    break;
  case 0x4e:
    pdVar1 = (double *)((int)local_884 + 4);
    piVar17 = *(int **)local_884;
    if ((int)local_888 < 0) {
      local_888 = (int *)0x7fffffff;
    }
    bVar4 = piVar21 != (int *)0x0;
    if (piVar17 == (int *)0x0) {
      piVar17 = (int *)&UNK_082233cd;
    }
    iVar8 = 0;
    cVar14 = *(char *)piVar17;
    iVar12 = (int)cVar14;
    cVar3 = cVar14;
    while (cVar3 != '\0') {
      iVar8 = iVar8 + 1;
      cVar3 = *(char *)((int)piVar17 + iVar8);
    }
    local_884 = (double *)0;
    if (-1 < (int)local_878 - iVar8) {
      local_884 = (double *)((int)local_878 - iVar8);
    }
    if ((local_874 & 1) == 0) {
      if (((int)local_884 < 1) || (iVar8 = 0, !bVar4)) {
        iVar8 = 0;
      }
      else {
LAB_0811da04:
        do {
          if (local_854 <= local_84c) {
            do {
              if (local_850 == (undefined *)0x0) {
                if (local_854 == 0) {
                  local_854 = 0x400;
                }
                local_850 = (undefined *)CRYPTO_malloc(local_854,"b_print.c",0x2e5);
                if (local_84c != 0) {
                  memcpy(local_850,local_858,local_84c);
                }
                local_858 = (undefined *)0x0;
                goto LAB_0811da04;
              }
              local_854 = local_854 + 0x400;
              local_850 = (undefined *)CRYPTO_realloc(local_850,local_854,"b_print.c",0x2ed);
            } while (local_854 <= local_84c);
          }
          if (local_858 == (undefined *)0x0) {
            local_850[local_84c] = 0x20;
          }
          else {
            local_858[local_84c] = 0x20;
          }
          local_84c = local_84c + 1;
          iVar8 = iVar8 + 1;
          local_884 = (double *)((int)local_884 + -1);
          bVar4 = iVar8 < (int)local_888;
        } while ((0 < (int)local_884) && (bVar4));
        iVar12 = (int)*(char *)piVar17;
      }
      if (((char)iVar12 == '\0') || (!bVar4)) break;
LAB_0811da87:
      iVar16 = iVar8;
      do {
        iVar16 = iVar16 + 1;
        doapr_outch(&local_854,iVar12);
        cVar14 = *(char *)((int)piVar17 + (iVar16 - iVar8));
        iVar12 = (int)cVar14;
        bVar4 = iVar16 < (int)local_888;
        if (cVar14 == '\0') break;
      } while (iVar16 < (int)local_888);
    }
    else {
      local_884 = (double *)-(int)local_884;
      if ((cVar14 != '\0') && (iVar8 = 0, bVar4)) goto LAB_0811da87;
      iVar16 = 0;
    }
    if (((int)local_884 < 0) && (bVar4)) {
      iVar8 = (int)local_884;
      do {
        iVar8 = iVar8 + 1;
        doapr_outch_constprop_5(&local_854);
        if (-1 < iVar8) break;
      } while ((iVar8 - (int)local_884) + iVar16 < (int)local_888);
    }
    break;
  case 0x52:
    local_880 = local_880 + 1;
  }
  local_884 = pdVar1;
  bVar18 = *local_880;
  local_880 = local_880 + 1;
  goto joined_r0x0811d0fa;
}

