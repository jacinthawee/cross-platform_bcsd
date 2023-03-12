
int BIO_vprintf(BIO *bio,char *format,va_list args)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  char *pcVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  char *pcVar8;
  BIO *bio_00;
  uint **ppuVar9;
  int *piVar10;
  char *pcVar11;
  char cVar13;
  uint *puVar12;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  code *pcVar17;
  undefined *puVar18;
  char *pcVar19;
  double dVar20;
  int iVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  int aiStack_974 [2];
  int iStack_96c;
  int iStack_968;
  int iStack_964;
  undefined *puStack_960;
  code *pcStack_95c;
  char **appcStack_954 [3];
  uint *puStack_948;
  uint **ppuStack_944;
  undefined *puStack_940;
  uint **ppuStack_938;
  int iStack_934;
  char *pcStack_930;
  int iStack_92c;
  int iStack_928;
  int iStack_924;
  undefined *puStack_920;
  code *pcStack_91c;
  uint *puStack_90c;
  undefined *puStack_908;
  uint *puStack_900;
  int iStack_8fc;
  int iStack_8f8;
  code *pcStack_8f4;
  uint uStack_8e8;
  uint *puStack_8e4;
  int local_8e0;
  uint *local_8dc;
  undefined4 local_8d8;
  uint *local_8d4;
  uint *local_8d0;
  char *local_8cc;
  undefined *local_8c8;
  char *local_8c0;
  uint **local_8bc;
  int local_8b8;
  BIO *local_8b4;
  BIO **local_8b0;
  char *local_8ac;
  char *local_8a8;
  char *local_8a4;
  int local_8a0;
  char *local_89c;
  uint *local_898;
  char *local_894;
  uint local_890;
  uint local_88c;
  char *local_884;
  uint local_880;
  char *local_87c;
  uint local_878;
  char local_874 [40];
  char acStack_84c [2048];
  BIO *local_4c;
  
  puStack_90c = (uint *)(CAST_S_table6 + 0x350);
  local_8b8 = 0x660000;
  local_8ac = acStack_84c;
  local_8b0 = (BIO **)PTR___stack_chk_guard_006aabf0;
  local_8c8 = &_gp;
  pcVar11 = format + 1;
  local_87c = (char *)0x0;
  local_880 = 0x800;
  local_4c = *(BIO **)PTR___stack_chk_guard_006aabf0;
  local_8b4 = bio;
  local_884 = local_8ac;
  (*(code *)PTR_CRYPTO_push_info__006a9a14)("doapr()","b_print.c",0x31a);
  cVar13 = *format;
  local_878 = 0;
  puVar18 = local_8c8;
  if (cVar13 == '\0') {
LAB_005281e8:
    if (local_880 - 1 < local_878) {
      local_878 = local_880 - 1;
    }
    iVar14 = local_8b8 + 0x7f24;
    uStack_8e8 = local_878;
    if (local_880 <= local_878) {
      do {
        uVar16 = local_880 + 0x400;
        if (local_87c == (char *)0x0) {
          if (local_880 == 0) {
            local_880 = 0x400;
          }
          local_87c = (char *)(**(code **)(puVar18 + -0x7dd8))(local_880,iVar14,0x2e5);
          if (local_878 != 0) {
            (**(code **)(local_8c8 + -0x52ec))(local_87c,local_884);
          }
          local_884 = (char *)0x0;
        }
        else {
          puStack_90c = (uint *)0x2ed;
          local_880 = uVar16;
          local_87c = (char *)(**(code **)(puVar18 + -0x729c))(local_87c,uVar16,iVar14);
        }
        uStack_8e8 = local_878;
        puVar18 = local_8c8;
      } while (local_880 <= local_878);
    }
    local_878 = uStack_8e8 + 1;
    if (local_884 == (char *)0x0) {
      local_87c[uStack_8e8] = '\0';
    }
    else {
      local_884[uStack_8e8] = '\0';
    }
    if (local_87c == (char *)0x0) {
      pcStack_930 = local_8ac;
      iStack_8f8 = BIO_write(local_8b4,local_8ac,uStack_8e8);
    }
    else {
      pcStack_930 = local_87c;
      iStack_8f8 = BIO_write(local_8b4,local_87c,uStack_8e8);
      (**(code **)(local_8c8 + -0x7f58))(local_87c);
    }
    (**(code **)(local_8c8 + -0x64c8))();
    if (local_4c == *local_8b0) {
      return iStack_8f8;
    }
    pcStack_8f4 = BIO_printf;
    bio_00 = local_4c;
    (**(code **)(local_8c8 + -0x5328))();
    puStack_920 = PTR___stack_chk_guard_006aabf0;
    puStack_948 = &uStack_8e8;
    puStack_908 = &_gp;
    iStack_8fc = *(int *)PTR___stack_chk_guard_006aabf0;
    puStack_900 = puStack_948;
    puStack_8e4 = puStack_90c;
    iVar14 = BIO_vprintf(bio_00,pcStack_930,puStack_948);
    if (iStack_8fc == *(int *)puStack_920) {
      return iVar14;
    }
    pcStack_91c = BIO_snprintf;
    iStack_934 = iStack_8fc;
    (**(code **)(puStack_908 + -0x5328))();
    puStack_960 = PTR___stack_chk_guard_006aabf0;
    ppuStack_944 = &puStack_90c;
    piVar10 = &iStack_928;
    piVar3 = &iStack_92c;
    appcStack_954[0] = &pcStack_930;
    puStack_940 = &_gp;
    iStack_924 = *(int *)PTR___stack_chk_guard_006aabf0;
    ppuStack_938 = ppuStack_944;
    _dopr_constprop_0(&iStack_934);
    if (iStack_928 == 0) {
      if (iStack_92c < 0) {
        iStack_92c = -1;
      }
    }
    else {
      iStack_92c = -1;
    }
    if (iStack_924 != *(int *)puStack_960) {
      pcStack_95c = BIO_vsnprintf;
      aiStack_974[0] = iStack_924;
      (**(code **)(puStack_940 + -0x5328))();
      puVar18 = PTR___stack_chk_guard_006aabf0;
      iStack_964 = *(int *)PTR___stack_chk_guard_006aabf0;
      _dopr_constprop_0(aiStack_974,appcStack_954,&iStack_96c,&iStack_968,piVar3,piVar10);
      if (iStack_968 == 0) {
        if (iStack_96c < 0) {
          iStack_96c = -1;
        }
      }
      else {
        iStack_96c = -1;
      }
      if (iStack_964 == *(int *)puVar18) {
        return iStack_96c;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x00529660. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar14 = (*(code *)PTR_fwrite_006aab7c)();
      return iVar14;
    }
    return iStack_92c;
  }
  local_8a8 = "7 datafinal";
  local_8a4 = "7 datafinal";
  dVar22 = DAT_006682e8;
  dVar23 = DAT_006682c0;
  dVar24 = DAT_006682b8;
  dVar25 = DAT_0063fac0;
  do {
    iVar14 = local_8b8 + 0x7f24;
    while (cVar13 != '%') {
      while (local_880 <= local_878) {
        while (uVar16 = local_880 + 0x400, local_87c != (char *)0x0) {
          puStack_90c = (uint *)0x2ed;
          local_880 = uVar16;
          local_87c = (char *)(**(code **)(puVar18 + -0x729c))(local_87c,uVar16,iVar14);
          puVar18 = local_8c8;
          if (local_878 < local_880) goto LAB_005283c0;
        }
        if (local_880 == 0) {
          local_880 = 0x400;
        }
        local_87c = (char *)(**(code **)(puVar18 + -0x7dd8))(local_880,iVar14,0x2e5);
        if (local_878 == 0) {
          local_884 = (char *)0x0;
          puVar18 = local_8c8;
        }
        else {
          (**(code **)(local_8c8 + -0x52ec))(local_87c,local_884);
          local_884 = (char *)0x0;
          puVar18 = local_8c8;
        }
      }
LAB_005283c0:
      uVar16 = local_878 + 1;
      if (local_884 == (char *)0x0) {
        local_87c[local_878] = cVar13;
        cVar13 = *pcVar11;
      }
      else {
        local_884[local_878] = cVar13;
        cVar13 = *pcVar11;
      }
      pcVar11 = pcVar11 + 1;
      local_878 = uVar16;
      if (cVar13 == '\0') goto LAB_005281e8;
    }
    uVar16 = (uint)*pcVar11;
    pcVar11 = pcVar11 + 1;
    if (uVar16 == 0) goto LAB_005281e8;
    local_8c0 = (char *)0x0;
    uVar2 = uVar16 - 0x20;
LAB_00528454:
    uVar2 = uVar2 & 0xff;
    pcVar19 = pcVar11;
    if (uVar2 < 0x11) {
      do {
        pcVar11 = pcVar19;
        switch((&switchD_00528470::switchdataD_00668110)[uVar2] & 0xfffffffe) {
        case 0x528478:
          pcVar11 = pcVar19 + 1;
          uVar16 = (uint)*pcVar19;
          local_8c0 = (char *)((uint)local_8c0 | 0x10);
          if (uVar16 == 0) goto LAB_005281e8;
          uVar2 = uVar16 - 0x20 & 0xff;
          pcVar19 = pcVar11;
          if (0x10 < uVar2) goto switchD_00528470_caseD_5284a8;
          break;
        case 0x5284a8:
          goto switchD_00528470_caseD_5284a8;
        case 0x5284fc:
          pcVar11 = pcVar19 + 1;
          uVar16 = (uint)*pcVar19;
          local_8c0 = (char *)((uint)local_8c0 | 1);
          if (uVar16 == 0) goto LAB_005281e8;
          uVar2 = uVar16 - 0x20;
          goto LAB_00528454;
        case 0x52851c:
          pcVar11 = pcVar19 + 1;
          uVar16 = (uint)*pcVar19;
          local_8c0 = (char *)((uint)local_8c0 | 2);
          if (uVar16 == 0) goto LAB_005281e8;
          uVar2 = uVar16 - 0x20;
          goto LAB_00528454;
        case 0x52853c:
          pcVar11 = pcVar19 + 1;
          uVar16 = (uint)*pcVar19;
          local_8c0 = (char *)((uint)local_8c0 | 8);
          if (uVar16 == 0) goto LAB_005281e8;
          uVar2 = uVar16 - 0x20;
          goto LAB_00528454;
        case 0x52855c:
          goto switchD_00528470_caseD_52855c;
        }
      } while( true );
    }
switchD_00528470_caseD_5284a8:
    puVar15 = (uint *)0x0;
    pcVar17 = *(code **)(puVar18 + -0x5498);
    while (piVar3 = (int *)(*pcVar17)(), puVar18 = local_8c8,
          (*(ushort *)(*piVar3 + (uVar16 & 0xff) * 2) & 8) != 0) {
      iVar14 = uVar16 - 0x30;
      uVar16 = (uint)*pcVar11;
      pcVar11 = pcVar11 + 1;
      puVar15 = (uint *)(iVar14 + (int)puVar15 * 10);
      if (uVar16 == 0) goto LAB_005281e8;
      pcVar17 = *(code **)(local_8c8 + -0x5498);
    }
    if (uVar16 == 0x2a) {
      uVar16 = (uint)*pcVar11;
                    /* WARNING: Load size is inaccurate */
      puVar15 = *args;
      pcVar11 = pcVar11 + 1;
      args = (uint **)((int)args + 4);
      if (uVar16 == 0) goto LAB_005281e8;
    }
    puVar12 = (uint *)0xffffffff;
    ppuVar9 = (uint **)args;
    if (uVar16 == 0x2e) {
      uVar16 = (uint)*pcVar11;
      if (uVar16 == 0) goto LAB_005281e8;
      puVar12 = (uint *)0xffffffff;
      pcVar19 = pcVar11;
      while( true ) {
        pcVar11 = pcVar19 + 1;
        piVar3 = (int *)(**(code **)(local_8c8 + -0x5498))();
        puVar18 = local_8c8;
        if ((*(ushort *)(*piVar3 + (uVar16 & 0xff) * 2) & 8) == 0) break;
        if ((int)puVar12 < 0) {
          puVar12 = (uint *)0x0;
        }
        iVar14 = uVar16 - 0x30;
        uVar16 = (uint)*pcVar11;
        puVar12 = (uint *)(iVar14 + (int)puVar12 * 10);
        pcVar19 = pcVar11;
        if (uVar16 == 0) goto LAB_005281e8;
      }
      if (uVar16 == 0x2a) {
        uVar16 = (uint)*pcVar11;
        ppuVar9 = (uint **)((int)args + 4);
                    /* WARNING: Load size is inaccurate */
        puVar12 = *args;
        pcVar11 = pcVar19 + 2;
        if (uVar16 == 0) goto LAB_005281e8;
      }
    }
    puVar18 = local_8c8;
    if (uVar16 == 0x68) {
      uVar16 = (uint)*pcVar11;
      pcVar11 = pcVar11 + 1;
      if (uVar16 == 0) goto LAB_005281e8;
      iVar14 = 1;
    }
    else if ((int)uVar16 < 0x69) {
      iVar14 = 0;
      if (uVar16 == 0x4c) {
        uVar16 = (uint)*pcVar11;
        pcVar11 = pcVar11 + 1;
        if (uVar16 == 0) goto LAB_005281e8;
        iVar14 = 3;
      }
    }
    else if (uVar16 == 0x6c) {
      uVar16 = (uint)*pcVar11;
      iVar14 = 4;
      if (uVar16 == 0x6c) {
        uVar16 = (uint)pcVar11[1];
        pcVar11 = pcVar11 + 1;
      }
      else {
        iVar14 = 2;
      }
      pcVar11 = pcVar11 + 1;
      if (uVar16 == 0) goto LAB_005281e8;
    }
    else {
      iVar14 = 0;
      if (uVar16 == 0x71) {
        uVar16 = (uint)*pcVar11;
        pcVar11 = pcVar11 + 1;
        if (uVar16 == 0) goto LAB_005281e8;
        iVar14 = 4;
      }
    }
    args = ppuVar9;
    switch(uVar16 - 0x25 & 0xff) {
    case 0:
      iVar14 = local_8b8 + 0x7f24;
      while (local_880 <= local_878) {
        while (local_87c != (char *)0x0) {
          local_880 = local_880 + 0x400;
          puStack_90c = (uint *)0x2ed;
          local_87c = (char *)(**(code **)(local_8c8 + -0x729c))(local_87c,local_880,iVar14);
          if (local_878 < local_880) goto LAB_00528dc4;
        }
        if (local_880 == 0) {
          local_880 = 0x400;
        }
        local_87c = (char *)(**(code **)(local_8c8 + -0x7dd8))(local_880,iVar14,0x2e5);
        if (local_878 == 0) {
          local_884 = (char *)0x0;
        }
        else {
          (**(code **)(local_8c8 + -0x52ec))(local_87c,local_884);
          local_884 = (char *)0x0;
        }
      }
LAB_00528dc4:
      puVar18 = local_8c8;
      if (local_884 == (char *)0x0) {
        local_87c[local_878] = '%';
        local_878 = local_878 + 1;
      }
      else {
        local_884[local_878] = '%';
        local_878 = local_878 + 1;
      }
      break;
    case 0x20:
    case 0x22:
    case 0x40:
    case 0x42:
      args = (uint **)(((int)ppuVar9 + 7U & 0xfffffff8) + 8);
      break;
    case 0x33:
      local_8c0 = (char *)((uint)local_8c0 | 0x20);
    case 0x4a:
    case 0x50:
    case 0x53:
      local_8cc = (char *)((uint)local_8c0 | 0x40);
      if (iVar14 == 2) {
LAB_00528714:
        local_8dc = *ppuVar9;
        local_8e0 = 0;
        args = ppuVar9 + 1;
      }
      else if (iVar14 == 4) {
        piVar3 = (int *)((int)ppuVar9 + 7U & 0xfffffff8);
        args = piVar3 + 2;
        local_8e0 = *piVar3;
        local_8dc = (uint *)piVar3[1];
      }
      else {
        local_8e0 = 0;
        if (iVar14 != 1) goto LAB_00528714;
        local_8dc = (uint *)(uint)*(ushort *)((int)ppuVar9 + 2);
        args = ppuVar9 + 1;
      }
      local_8d8 = 0x10;
      if (uVar16 == 0x6f) {
        local_8d8 = 8;
      }
      else if (uVar16 == 0x75) {
        local_8d8 = 10;
      }
      puStack_90c = &local_880;
      local_8d4 = puVar15;
      local_8d0 = puVar12;
      fmtint(&local_884,&local_87c,&local_878);
      puVar18 = local_8c8;
      break;
    case 0x3e:
      puVar15 = *ppuVar9;
      iVar14 = local_8b8 + 0x7f24;
      while (local_880 <= local_878) {
        while (local_87c != (char *)0x0) {
          local_880 = local_880 + 0x400;
          puStack_90c = (uint *)0x2ed;
          local_87c = (char *)(**(code **)(local_8c8 + -0x729c))(local_87c,local_880,iVar14);
          if (local_878 < local_880) goto LAB_00528d48;
        }
        if (local_880 == 0) {
          local_880 = 0x400;
        }
        local_87c = (char *)(**(code **)(local_8c8 + -0x7dd8))(local_880,iVar14,0x2e5);
        if (local_878 == 0) {
          local_884 = (char *)0x0;
        }
        else {
          (**(code **)(local_8c8 + -0x52ec))(local_87c,local_884);
          local_884 = (char *)0x0;
        }
      }
LAB_00528d48:
      args = ppuVar9 + 1;
      puVar18 = local_8c8;
      if (local_884 == (char *)0x0) {
        local_87c[local_878] = (char)puVar15;
        local_878 = local_878 + 1;
      }
      else {
        local_884[local_878] = (char)puVar15;
        local_878 = local_878 + 1;
      }
      break;
    case 0x3f:
    case 0x44:
      if (iVar14 == 2) {
LAB_00528c9c:
        local_8dc = *ppuVar9;
        args = ppuVar9 + 1;
        local_8e0 = (int)local_8dc >> 0x1f;
      }
      else if (iVar14 == 4) {
        piVar3 = (int *)((int)ppuVar9 + 7U & 0xfffffff8);
        args = piVar3 + 2;
        local_8e0 = *piVar3;
        local_8dc = (uint *)piVar3[1];
      }
      else {
        if (iVar14 != 1) goto LAB_00528c9c;
        local_8dc = (uint *)(int)*(short *)((int)ppuVar9 + 2);
        args = ppuVar9 + 1;
        local_8e0 = (int)local_8dc >> 0x1f;
      }
      puStack_90c = &local_880;
      local_8cc = local_8c0;
      local_8d8 = 10;
      local_8d4 = puVar15;
      local_8d0 = puVar12;
      fmtint(&local_884,&local_87c,&local_878);
      puVar18 = local_8c8;
      break;
    case 0x41:
      uVar16 = (int)ppuVar9 + 7;
      if (iVar14 == 3) {
        uVar5 = ((uint *)(uVar16 & 0xfffffff8))[1];
        uVar2 = *(uint *)(uVar16 & 0xfffffff8);
      }
      else {
        uVar5 = ((uint *)(uVar16 & 0xfffffff8))[1];
        uVar2 = *(uint *)(uVar16 & 0xfffffff8);
      }
      args = (va_list)((uVar16 & 0xfffffff8) + 8);
      if ((int)puVar12 < 0) {
        puVar12 = (uint *)&DAT_00000006;
      }
      else if (9 < (int)puVar12) {
        puVar12 = (uint *)&DAT_00000009;
      }
      if (0.0 <= (double)CONCAT44(uVar2,uVar5)) {
        if (0.0 <= (double)CONCAT44(uVar2,uVar5)) {
          uVar16 = (uint)local_8c0 & 4;
          if (((uint)local_8c0 & 2) == 0) {
            if (uVar16 == 0) {
              local_8a0 = 0;
            }
            else {
              uVar16 = 1;
              local_8a0 = 0x20;
            }
          }
          else {
            uVar16 = 1;
            local_8a0 = 0x2b;
          }
        }
        else {
          uVar16 = 1;
          local_8a0 = 0x2d;
        }
      }
      else {
        uVar16 = 1;
        uVar2 = uVar2 ^ 0x80000000;
        local_8a0 = 0x2d;
        local_890 = uVar2;
        local_88c = uVar5;
      }
      iVar14 = (int)(double)CONCAT44(uVar2,uVar5);
      if (puVar12 == (uint *)0x0) {
        iVar7 = 1;
        dVar20 = dVar25;
      }
      else {
        if (puVar12 == (uint *)0x1) {
          dVar20 = *(double *)(local_8a8 + -0x7d48);
        }
        else if (puVar12 == (uint *)&SUB_00000002) {
          dVar20 = *(double *)(local_8a4 + -0x7d40);
        }
        else {
          dVar20 = DAT_0063fad0;
          if (((((puVar12 != (uint *)0x3) &&
                (dVar20 = DAT_0063fac8, puVar12 != (uint *)&SUB_00000004)) &&
               (dVar20 = DAT_006682c8, puVar12 != (uint *)&DAT_00000005)) &&
              ((dVar20 = DAT_006682d0, puVar12 != (uint *)&DAT_00000006 &&
               (dVar20 = DAT_006682d8, puVar12 != (uint *)&DAT_00000007)))) &&
             (dVar20 = DAT_006682e0, puVar12 != (uint *)&DAT_00000008)) {
            dVar20 = DAT_006682b0;
          }
        }
        iVar7 = (int)dVar20;
        dVar20 = dVar24;
        if ((((puVar12 != (uint *)0x1) && (dVar20 = dVar23, puVar12 != (uint *)&SUB_00000002)) &&
            ((dVar20 = DAT_0063fad0, puVar12 != (uint *)0x3 &&
             (((dVar20 = DAT_0063fac8, puVar12 != (uint *)&SUB_00000004 &&
               (dVar20 = DAT_006682c8, puVar12 != (uint *)&DAT_00000005)) &&
              (dVar20 = DAT_006682d0, puVar12 != (uint *)&DAT_00000006)))))) &&
           ((dVar20 = DAT_006682d8, puVar12 != (uint *)&DAT_00000007 &&
            (dVar20 = DAT_006682e0, puVar12 != (uint *)&DAT_00000008)))) {
          dVar20 = DAT_006682b0;
        }
      }
      dVar20 = ((double)CONCAT44(uVar2,uVar5) - (double)iVar14) * dVar20;
      iVar21 = (int)dVar20;
      if (dVar22 <= dVar20 - (double)iVar21) {
        iVar21 = iVar21 + 1;
      }
      local_89c = local_874;
      if (iVar7 <= iVar21) {
        iVar14 = iVar14 + 1;
        iVar21 = iVar21 - iVar7;
      }
      local_8bc = (uint **)0x0;
      pcVar19 = local_89c;
      ppuVar9 = local_8bc;
      do {
        local_8bc = ppuVar9;
        ppuVar9 = (uint **)((int)local_8bc + 1);
        *pcVar19 = "0123456789abcdef"[iVar14 % 10];
        if (iVar14 / 10 == 0) {
          if (ppuVar9 != (uint **)&DAT_00000014) {
            local_8bc = ppuVar9;
          }
          break;
        }
        pcVar19 = pcVar19 + 1;
        iVar14 = iVar14 / 10;
      } while (ppuVar9 != (uint **)&DAT_00000014);
      local_894 = local_874 + 0x14;
      iVar14 = 0;
      local_874[(int)local_8bc] = '\0';
      pcVar19 = local_894;
      do {
        iVar14 = iVar14 + 1;
        *pcVar19 = "0123456789abcdef"[iVar21 % 10];
        iVar21 = iVar21 / 10;
        pcVar19 = pcVar19 + 1;
      } while (iVar14 < (int)puVar12);
      local_898 = (uint *)0x1;
      if (0 < (int)puVar12) {
        local_898 = puVar12;
      }
      pcVar19 = (char *)((int)puVar15 + (((-(int)puVar12 - (int)local_8bc) + -1) - uVar16));
      iVar14 = (int)puVar12 - (int)local_898;
      if ((int)pcVar19 < 0) {
        pcVar19 = (char *)0x0;
      }
      if (iVar14 < 0) {
        iVar14 = 0;
      }
      (local_874 + 0x14)[(int)local_898] = '\0';
      if (((uint)local_8c0 & 1) == 0) {
        if (((uint)local_8c0 & 0x10) == 0) {
          if (0 < (int)pcVar19) {
            do {
              pcVar19 = pcVar19 + -1;
              doapr_outch_constprop_5(&local_884,&local_87c,&local_878,&local_880);
            } while (pcVar19 != (char *)0x0);
          }
          goto LAB_00528a70;
        }
        if (pcVar19 == (char *)0x0) goto LAB_00528a70;
        local_8e0 = local_8a0;
        if (local_8a0 != 0) goto LAB_00529184;
        do {
          local_8e0 = 0x30;
LAB_00529184:
          pcVar19 = pcVar19 + -1;
          puStack_90c = &local_880;
          doapr_outch(&local_884,&local_87c,&local_878);
        } while (pcVar19 != (char *)0x0);
        pcVar19 = (char *)0x0;
      }
      else {
        pcVar19 = (char *)-(int)pcVar19;
LAB_00528a70:
        puStack_90c = &local_880;
        if (local_8a0 != 0) {
          local_8e0 = local_8a0;
          doapr_outch(&local_884,&local_87c,&local_878);
        }
      }
      iVar7 = (int)local_8bc + -1;
      puVar18 = local_8c8;
      if (local_8bc != (uint **)0x0) {
        iVar21 = local_8b8 + 0x7f24;
        pcVar8 = local_89c + iVar7;
        do {
          cVar13 = *pcVar8;
          while (local_880 <= local_878) {
            while (uVar16 = local_880 + 0x400, local_87c != (char *)0x0) {
              puStack_90c = (uint *)0x2ed;
              local_880 = uVar16;
              local_87c = (char *)(**(code **)(puVar18 + -0x729c))(local_87c,uVar16,iVar21);
              puVar18 = local_8c8;
              if (local_878 < local_880) goto LAB_00528b08;
            }
            if (local_880 == 0) {
              local_880 = 0x400;
            }
            local_87c = (char *)(**(code **)(puVar18 + -0x7dd8))(local_880,iVar21,0x2e5);
            if (local_878 == 0) {
              local_884 = (char *)0x0;
              puVar18 = local_8c8;
            }
            else {
              (**(code **)(local_8c8 + -0x52ec))(local_87c,local_884);
              local_884 = (char *)0x0;
              puVar18 = local_8c8;
            }
          }
LAB_00528b08:
          uVar16 = local_878 + 1;
          pcVar4 = local_884;
          if (local_884 == (char *)0x0) {
            pcVar4 = local_87c;
          }
          pcVar8 = pcVar8 + -1;
          pcVar4[local_878] = cVar13;
          local_878 = uVar16;
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
        } while( true );
      }
      if ((puVar12 != (uint *)0x0) || (((uint)local_8c0 & 8) != 0)) {
        local_8e0 = 0x2e;
        doapr_outch(&local_884,&local_87c,&local_878,&local_880);
        local_8c0 = (char *)((int)local_898 + -1);
        pcVar8 = local_894 + (int)local_8c0;
        while( true ) {
          local_8e0 = (int)*pcVar8;
          pcVar8 = pcVar8 + -1;
          puStack_90c = &local_880;
          doapr_outch(&local_884,&local_87c,&local_878);
          puVar18 = local_8c8;
          if (local_8c0 == (char *)0x0) break;
          local_8c0 = local_8c0 + -1;
        }
      }
      if (iVar14 != 0) {
        do {
          iVar14 = iVar14 + -1;
          local_8e0 = 0x30;
          puStack_90c = &local_880;
          doapr_outch(&local_884,&local_87c,&local_878);
          puVar18 = local_8c8;
        } while (iVar14 != 0);
      }
      if (pcVar19 == (char *)0x0) break;
      do {
        pcVar19 = pcVar19 + 1;
        puStack_90c = &local_880;
        doapr_outch_constprop_5(&local_884,&local_87c,&local_878);
      } while (pcVar19 != (char *)0x0);
      cVar13 = *pcVar11;
      puVar18 = local_8c8;
      goto LAB_005286d0;
    case 0x49:
      if (iVar14 == 1) {
        *(short *)*ppuVar9 = (short)local_878;
        args = ppuVar9 + 1;
      }
      else if (iVar14 == 2) {
        **ppuVar9 = local_878;
        args = ppuVar9 + 1;
      }
      else {
        args = ppuVar9 + 1;
        if (iVar14 == 4) {
          puVar15 = *ppuVar9;
          puVar15[1] = local_878;
          *puVar15 = 0;
        }
        else {
          **ppuVar9 = local_878;
        }
      }
      break;
    case 0x4b:
      puStack_90c = &local_880;
      local_8cc = (char *)((uint)local_8c0 | 8);
      local_8d8 = 0x10;
      local_8dc = *ppuVar9;
      local_8e0 = (int)local_8dc >> 0x1f;
      local_8d4 = puVar15;
      local_8d0 = puVar12;
      fmtint(&local_884,&local_87c,&local_878);
      args = ppuVar9 + 1;
      puVar18 = local_8c8;
      break;
    case 0x4e:
      local_8bc = ppuVar9 + 1;
      pcVar19 = (char *)*ppuVar9;
      if ((int)puVar12 < 0) {
        puVar12 = (uint *)0x7fffffff;
      }
      if ((uint *)pcVar19 == (uint *)0x0) {
        pcVar19 = "<NULL>";
      }
      iVar14 = (int)*pcVar19;
      if (iVar14 == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = 0;
        puVar6 = (uint *)pcVar19;
        do {
          puVar6 = (uint *)((int)puVar6 + 1);
          iVar7 = iVar7 + 1;
        } while (*(char *)puVar6 != '\0');
      }
      pcVar8 = (char *)((int)puVar15 - iVar7);
      if ((int)pcVar8 < 0) {
        pcVar8 = (char *)0x0;
      }
      if (((uint)local_8c0 & 1) == 0) {
        puVar15 = (uint *)0x0;
        if (pcVar8 == (char *)0x0) {
LAB_0052942c:
          bVar1 = (int)puVar15 < (int)puVar12;
          args = local_8bc;
          if (iVar14 != 0) goto LAB_005291b8;
        }
        else {
          args = local_8bc;
          if (puVar12 != (uint *)0x0) {
            iVar14 = local_8b8 + 0x7f24;
LAB_00528bf0:
            do {
              if (local_880 <= local_878) {
                do {
                  uVar16 = local_880 + 0x400;
                  if (local_87c == (char *)0x0) {
                    if (local_880 == 0) {
                      local_880 = 0x400;
                    }
                    local_87c = (char *)(**(code **)(puVar18 + -0x7dd8))(local_880,iVar14,0x2e5);
                    if (local_878 == 0) {
                      local_884 = (char *)0x0;
                      puVar18 = local_8c8;
                    }
                    else {
                      (**(code **)(local_8c8 + -0x52ec))(local_87c,local_884);
                      local_884 = (char *)0x0;
                      puVar18 = local_8c8;
                    }
                    goto LAB_00528bf0;
                  }
                  puStack_90c = (uint *)0x2ed;
                  local_880 = uVar16;
                  local_87c = (char *)(**(code **)(puVar18 + -0x729c))(local_87c,uVar16,iVar14);
                  puVar18 = local_8c8;
                } while (local_880 <= local_878);
              }
              uVar16 = local_878 + 1;
              pcVar4 = local_884;
              if (local_884 == (char *)0x0) {
                pcVar4 = local_87c;
              }
              pcVar8 = pcVar8 + -1;
              pcVar4[local_878] = ' ';
              puVar15 = (uint *)((int)puVar15 + 1);
              local_878 = uVar16;
              if (pcVar8 == (char *)0x0) {
                iVar14 = (int)*pcVar19;
                goto LAB_0052942c;
              }
              args = local_8bc;
            } while (puVar12 != puVar15);
          }
        }
      }
      else {
        pcVar8 = (char *)-(int)pcVar8;
        puVar15 = (uint *)0x0;
        if (iVar14 == 0) {
LAB_00529204:
          args = local_8bc;
          puVar18 = local_8c8;
          if (((int)pcVar8 < 0) && ((int)puVar15 < (int)puVar12)) {
            iVar14 = (int)pcVar8 - (int)puVar15;
            do {
              pcVar8 = pcVar8 + 1;
              puStack_90c = &local_880;
              doapr_outch_constprop_5(&local_884,&local_87c,&local_878);
              args = local_8bc;
              puVar18 = local_8c8;
              if (pcVar8 == (char *)0x0) break;
            } while (pcVar8 != (char *)((int)puVar12 + iVar14));
          }
        }
        else {
          bVar1 = 0 < (int)puVar12;
LAB_005291b8:
          args = local_8bc;
          if (bVar1) {
            do {
              pcVar19 = (char *)((int)pcVar19 + 1);
              puStack_90c = &local_880;
              local_8e0 = iVar14;
              doapr_outch(&local_884,&local_87c,&local_878);
              puVar15 = (uint *)((int)puVar15 + 1);
              iVar14 = (int)*pcVar19;
              if (iVar14 == 0) goto LAB_00529204;
              args = local_8bc;
              puVar18 = local_8c8;
            } while (puVar12 != puVar15);
          }
        }
      }
      break;
    case 0x52:
      pcVar11 = pcVar11 + 1;
    }
    cVar13 = *pcVar11;
LAB_005286d0:
    pcVar11 = pcVar11 + 1;
    if (cVar13 == '\0') goto LAB_005281e8;
  } while( true );
switchD_00528470_caseD_52855c:
  pcVar11 = pcVar19 + 1;
  uVar16 = (uint)*pcVar19;
  local_8c0 = (char *)((uint)local_8c0 | 4);
  if (uVar16 == 0) goto LAB_005281e8;
  uVar2 = uVar16 - 0x20;
  goto LAB_00528454;
}

