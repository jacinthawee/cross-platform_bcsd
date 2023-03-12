
/* WARNING: Type propagation algorithm not settling */

int mime_parse_hdr(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  char **ppcVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  BIO *out;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  uint uVar12;
  char **ppcVar13;
  char **ppcVar14;
  char cVar15;
  code *pcVar16;
  ASN1_VALUE *val;
  BIO *pBVar17;
  BIO *pBVar18;
  char *pcVar19;
  char **unaff_s0;
  char **ppcVar20;
  char **unaff_s4;
  char **unaff_s5;
  char **unaff_s6;
  char **ppcVar21;
  code *pcVar22;
  undefined *puVar23;
  char acStack_8ee [1026];
  BIO *pBStack_4ec;
  int iStack_4e8;
  undefined *puStack_4e4;
  char *pcStack_4e0;
  undefined **ppuStack_4dc;
  char **ppcStack_4d8;
  undefined *puStack_4d4;
  int iStack_4d0;
  char **ppcStack_4cc;
  char **ppcStack_4c8;
  code *pcStack_4c4;
  undefined4 uStack_4b0;
  undefined *puStack_4a8;
  undefined4 uStack_49c;
  char *apcStack_498 [3];
  int iStack_48c;
  char **ppcStack_488;
  undefined4 uStack_484;
  char **ppcStack_480;
  undefined **ppuStack_47c;
  char **ppcStack_478;
  char **ppcStack_474;
  char **ppcStack_470;
  char **ppcStack_46c;
  undefined4 uStack_468;
  code *pcStack_464;
  undefined *local_450;
  undefined4 local_444;
  char **local_440;
  int local_43c;
  char **local_438;
  int *local_434;
  char local_42c;
  undefined local_42b [1023];
  int local_2c;
  
  ppcStack_4cc = (char **)&local_42c;
  local_434 = (int *)PTR___stack_chk_guard_006aabf0;
  ppuStack_4dc = &switchD_0060d944::switchdataD_0067a670;
  pcStack_4e0 = (char *)0x0;
  local_450 = &_gp;
  puStack_4e4 = (undefined *)0x3b;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_444 = param_1;
  local_43c = (*(code *)PTR_sk_new_006a91b4)(mime_hdr_cmp);
  local_440 = (char **)0x0;
  puVar23 = local_450;
LAB_0060d8b4:
  pcVar22 = *(code **)(puVar23 + -0x7910);
  do {
    ppcStack_4c8 = (char **)&DAT_00000400;
    ppcStack_4d8 = ppcStack_4cc;
    iVar2 = (*pcVar22)(local_444);
    puVar23 = local_450;
    if (iVar2 < 1) goto LAB_0060dac8;
    if ((char **)pcStack_4e0 == (char **)0x0) {
      uVar12 = (uint)local_42c;
      uVar9 = uVar12 & 0xff;
LAB_0060ded0:
      ppcStack_4d8 = (char **)0x1;
    }
    else {
      piVar3 = (int *)(**(code **)(local_450 + -0x5498))();
      uVar12 = (uint)local_42c;
      uVar9 = uVar12 & 0xff;
      if ((*(ushort *)(*piVar3 + uVar9 * 2) & 0x20) == 0) goto LAB_0060ded0;
      ppcStack_4d8 = (char **)0x3;
    }
    unaff_s4 = (char **)0x0;
    ppcVar20 = ppcStack_4cc;
    ppcVar21 = ppcStack_4cc;
    puVar23 = local_450;
    if ((uVar9 < 0xe) && ((0x2401U >> (uVar9 & 0x1f) & 1) != 0)) goto LAB_0060dac8;
    do {
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch(ppcStack_4d8) {
      case (char **)0x1:
        ppcStack_4c8 = (char **)&DAT_0000003a;
        while (uVar12 != 0x3a) {
          while( true ) {
            ppcVar21 = (char **)((int)ppcVar21 + 1);
            uVar12 = (uint)*(char *)ppcVar21;
            ppcStack_4d8 = (char **)(uint)((uVar12 & 0xff) < 0xe);
            if (ppcStack_4d8 == (char **)0x0) break;
            if ((0x2401U >> (uVar12 & 0x1f) & 1) != 0) goto LAB_0060dabc;
            if (uVar12 == 0x3a) goto LAB_0060dd88;
          }
        }
LAB_0060dd88:
        *(undefined *)ppcVar21 = 0;
        uVar12 = (uint)*(char *)ppcVar20;
        if (uVar12 == 0) {
LAB_0060e300:
          unaff_s4 = (char **)0x0;
        }
        else {
          if (uVar12 != 0x22) {
            piVar3 = (int *)(**(code **)(puVar23 + -0x5498))();
            ppcStack_4c8 = (char **)0x22;
            unaff_s4 = ppcVar20;
            do {
              ppcVar20 = (char **)((int)unaff_s4 + 1);
              puVar23 = local_450;
              if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) goto LAB_0060ddf0;
              uVar12 = (uint)*(char *)ppcVar20;
              if (uVar12 == 0) goto LAB_0060e300;
              unaff_s4 = ppcVar20;
            } while (uVar12 != 0x22);
          }
          unaff_s4 = (char **)((int)ppcVar20 + 1);
          if ((*(char *)((int)ppcVar20 + 1) == '\0') || (unaff_s4 == (char **)0x0))
          goto LAB_0060e300;
LAB_0060ddf0:
          iVar2 = (**(code **)(puVar23 + -0x53b0))(unaff_s4);
          unaff_s5 = (char **)((int)unaff_s4 + iVar2 + -1);
          puVar23 = local_450;
          if (unaff_s5 < unaff_s4) goto LAB_0060e300;
          uVar12 = (uint)*(char *)unaff_s5;
          if (uVar12 != 0x22) {
            piVar3 = (int *)(**(code **)(local_450 + -0x5498))();
            ppcStack_4c8 = (char **)0x22;
            iVar2 = *piVar3;
            do {
              puVar23 = local_450;
              if ((*(ushort *)(iVar2 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
                cVar15 = *(char *)((int)ppcVar21 + 1);
                goto LAB_0060db1c;
              }
              *(undefined *)unaff_s5 = 0;
              unaff_s5 = (char **)((int)unaff_s5 + -1);
              if (unaff_s5 < unaff_s4) goto LAB_0060e300;
              uVar12 = (uint)*(char *)unaff_s5;
            } while (uVar12 != 0x22);
          }
          puVar23 = local_450;
          if (unaff_s4 == (char **)((int)unaff_s5 + -1)) goto LAB_0060e300;
          *(undefined *)unaff_s5 = 0;
        }
        cVar15 = *(char *)((int)ppcVar21 + 1);
LAB_0060db1c:
        ppcVar21 = (char **)((int)ppcVar21 + 1);
        ppcVar20 = ppcVar21;
        while( true ) {
          uVar12 = (uint)cVar15;
          if (((uVar12 & 0xff) < 0xe) && ((0x2401U >> (uVar12 & 0x1f) & 1) != 0)) goto LAB_0060db68;
LAB_0060db34:
          ppcStack_4c8 = (char **)0x28;
          if (uVar12 == 0x3b) {
            *(undefined *)ppcVar21 = 0;
            uVar12 = (uint)*(char *)ppcVar20;
            if (uVar12 == 0) goto LAB_0060e358;
            if (uVar12 == 0x22) goto LAB_0060e340;
            piVar3 = (int *)(**(code **)(puVar23 + -0x5498))();
            ppcVar13 = ppcVar20;
            goto LAB_0060dfdc;
          }
          if (uVar12 == 0x28) break;
          ppcVar21 = (char **)((int)ppcVar21 + 1);
          cVar15 = *(char *)ppcVar21;
        }
        uVar12 = (uint)*(char *)((int)ppcVar21 + 1);
        ppcStack_4d8 = (char **)(uint)((uVar12 & 0xff) < 0xe);
        ppcVar21 = (char **)((int)ppcVar21 + 1);
        if ((ppcStack_4d8 != (char **)0x0) && ((0x2401U >> (uVar12 & 0x1f) & 1) != 0)) {
          local_440 = (char **)&SUB_00000002;
          unaff_s0 = ppcVar20;
          unaff_s6 = ppcVar21;
          goto joined_r0x0060e460;
        }
        ppcStack_4d8 = (char **)&SUB_00000002;
LAB_0060dcc8:
        if (uVar12 != 0x29) {
          ppcVar21 = (char **)((int)ppcVar21 + 1);
          uVar12 = (uint)*(char *)ppcVar21;
          ppcStack_4c8 = (char **)(uint)((uVar12 & 0xff) < 0xe);
          if ((ppcStack_4c8 != (char **)0x0) &&
             (unaff_s0 = ppcVar20, unaff_s6 = ppcVar21, local_440 = ppcStack_4d8,
             (0x2401U >> (uVar12 & 0x1f) & 1) != 0)) goto joined_r0x0060e460;
          goto LAB_0060dcc8;
        }
        local_440 = ppcStack_4d8;
        break;
      case (char **)0x2:
        goto LAB_0060db34;
      case (char **)0x3:
        unaff_s5 = ppcVar21;
        goto LAB_0060dc80;
      }
      uVar12 = (uint)*(char *)((int)ppcVar21 + 1);
      ppcStack_4c8 = (char **)(uint)((uVar12 & 0xff) < 0xe);
      ppcVar21 = (char **)((int)ppcVar21 + 1);
    } while ((ppcStack_4c8 == (char **)0x0) || ((0x2401U >> (uVar12 & 0x1f) & 1) == 0));
    if (ppcStack_4d8 == (char **)&SUB_00000002) goto LAB_0060db68;
    if (ppcStack_4d8 == (char **)&SUB_00000004) {
LAB_0060d9bc:
      uVar12 = (uint)*(char *)ppcVar20;
      if (uVar12 == 0) {
LAB_0060daa4:
        unaff_s5 = (char **)0x0;
      }
      else {
        if (uVar12 != 0x22) {
          piVar3 = (int *)(**(code **)(puVar23 + -0x5498))();
          unaff_s5 = ppcVar20;
          do {
            ppcVar20 = (char **)((int)unaff_s5 + 1);
            if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
              pcVar22 = *(code **)(local_450 + -0x53b0);
              ppcVar20 = unaff_s5;
              goto LAB_0060da24;
            }
            uVar12 = (uint)*(char *)ppcVar20;
            if (uVar12 == 0) goto LAB_0060daa4;
            unaff_s5 = ppcVar20;
            puVar23 = local_450;
          } while (uVar12 != 0x22);
        }
        unaff_s5 = (char **)((int)ppcVar20 + 1);
        if (*(char *)((int)ppcVar20 + 1) == '\0') goto LAB_0060daa4;
        pcVar22 = *(code **)(puVar23 + -0x53b0);
        if (unaff_s5 != (char **)0x0) {
LAB_0060da24:
          iVar2 = (*pcVar22)(unaff_s5);
          ppcVar13 = (char **)((int)unaff_s5 + iVar2 + -1);
          if (unaff_s5 <= ppcVar13) {
            ppcVar20 = (char **)(int)*(char *)ppcVar13;
            if (ppcVar20 == (char **)0x22) {
              ppcVar4 = (char **)((int)ppcVar13 + -1);
            }
            else {
              local_438 = ppcVar13;
              piVar3 = (int *)(**(code **)(local_450 + -0x5498))();
              iVar2 = *piVar3;
              ppcVar14 = local_438;
              do {
                if ((*(ushort *)(iVar2 + ((uint)ppcVar20 & 0xff) * 2) & 0x20) == 0)
                goto LAB_0060daa8;
                *(undefined *)ppcVar14 = 0;
                ppcVar13 = (char **)((int)ppcVar14 + -1);
                if (ppcVar13 < unaff_s5) goto LAB_0060daa4;
                ppcVar20 = (char **)(int)*(char *)ppcVar13;
                ppcVar4 = (char **)((int)ppcVar14 + -2);
                ppcVar14 = ppcVar13;
              } while (ppcVar20 != (char **)0x22);
            }
            if (unaff_s5 != ppcVar4) {
              *(undefined *)ppcVar13 = 0;
              goto LAB_0060daa8;
            }
          }
          goto LAB_0060daa4;
        }
        unaff_s5 = (char **)0x0;
      }
LAB_0060daa8:
      ppcStack_4d8 = unaff_s4;
      ppcStack_4c8 = unaff_s5;
      mime_hdr_addparam_isra_1((char **)((int)pcStack_4e0 + 8));
      puVar23 = local_450;
LAB_0060dabc:
      pcVar22 = *(code **)(puVar23 + -0x7910);
      unaff_s0 = ppcVar20;
      unaff_s6 = ppcVar21;
    }
    else {
      pcVar22 = *(code **)(puVar23 + -0x7910);
      unaff_s0 = ppcVar20;
      unaff_s6 = ppcVar21;
    }
joined_r0x0060dd40:
    if (unaff_s6 == ppcStack_4cc) goto LAB_0060dac8;
  } while( true );
  while( true ) {
    uVar12 = (uint)*(char *)ppcVar20;
    ppcVar13 = (char **)0x0;
    if (uVar12 == 0) goto LAB_0060e078;
    ppcVar13 = ppcVar20;
    puVar23 = local_450;
    if (uVar12 == 0x22) break;
LAB_0060dfdc:
    ppcVar20 = (char **)((int)ppcVar13 + 1);
    if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
      pcVar22 = *(code **)(local_450 + -0x53b0);
      goto LAB_0060e000;
    }
  }
LAB_0060e340:
  ppcVar13 = (char **)0x0;
  if (*(char *)((int)ppcVar20 + 1) != '\0') {
    ppcVar13 = (char **)((int)ppcVar20 + 1);
    pcVar22 = *(code **)(puVar23 + -0x53b0);
    if (ppcVar13 != (char **)0x0) {
LAB_0060e000:
      iVar2 = (*pcVar22)(ppcVar13);
      ppcVar20 = (char **)((int)ppcVar13 + iVar2 + -1);
      if (ppcVar13 <= ppcVar20) {
        uVar12 = (uint)*(char *)ppcVar20;
        if (uVar12 != 0x22) {
          piVar3 = (int *)(**(code **)(local_450 + -0x5498))();
          iVar2 = *piVar3;
          do {
            if ((*(ushort *)(iVar2 + (uVar12 & 0xff) * 2) & 0x20) == 0) goto LAB_0060e078;
            *(undefined *)ppcVar20 = 0;
            ppcVar20 = (char **)((int)ppcVar20 + -1);
            if (ppcVar20 < ppcVar13) goto LAB_0060e358;
            uVar12 = (uint)*(char *)ppcVar20;
          } while (uVar12 != 0x22);
        }
        if (ppcVar13 != (char **)((int)ppcVar20 + -1)) {
          *(undefined *)ppcVar20 = 0;
          goto LAB_0060e078;
        }
      }
    }
LAB_0060e358:
    ppcVar13 = (char **)0x0;
  }
LAB_0060e078:
  pcStack_4e0 = (char *)mime_hdr_new(unaff_s4,ppcVar13);
  unaff_s5 = (char **)((int)ppcVar21 + 1);
  ppcStack_4d8 = (char **)pcStack_4e0;
  (**(code **)(local_450 + -0x7e38))(local_43c);
LAB_0060e0a4:
  do {
    cVar15 = *(char *)((int)ppcVar21 + 1);
    unaff_s0 = ppcVar20;
    ppcVar20 = unaff_s5;
    puVar23 = local_450;
    while( true ) {
      uVar12 = (uint)cVar15;
      if (((uVar12 & 0xff) < 0xe) && ((0x2401U >> (uVar12 & 0x1f) & 1) != 0)) {
        pcVar22 = *(code **)((int)puVar23 + -0x7910);
        unaff_s6 = unaff_s5;
        goto joined_r0x0060dd40;
      }
LAB_0060dc80:
      ppcStack_4d8 = (char **)&DAT_0000003d;
      if (uVar12 == 0x3d) break;
      unaff_s5 = (char **)((int)unaff_s5 + 1);
      cVar15 = *(char *)unaff_s5;
      unaff_s0 = ppcVar20;
    }
    *(undefined *)unaff_s5 = 0;
    uVar12 = (uint)*(char *)ppcVar20;
    if (uVar12 == 0) {
LAB_0060e2f8:
      unaff_s4 = (char **)0x0;
    }
    else {
      if (uVar12 != 0x22) {
        piVar3 = (int *)(**(code **)(puVar23 + -0x5498))();
        unaff_s4 = ppcVar20;
        do {
          ppcVar20 = (char **)((int)unaff_s4 + 1);
          puVar23 = local_450;
          if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) goto LAB_0060e254;
          uVar12 = (uint)*(char *)ppcVar20;
          if (uVar12 == 0) goto LAB_0060e2f8;
          unaff_s4 = ppcVar20;
        } while (uVar12 != 0x22);
      }
      unaff_s4 = (char **)((int)ppcVar20 + 1);
      if ((*(char *)((int)ppcVar20 + 1) == '\0') || (unaff_s4 == (char **)0x0)) goto LAB_0060e2f8;
LAB_0060e254:
      iVar2 = (**(code **)(puVar23 + -0x53b0))(unaff_s4);
      ppcVar21 = (char **)((int)unaff_s4 + iVar2 + -1);
      puVar23 = local_450;
      if (ppcVar21 < unaff_s4) goto LAB_0060e2f8;
      uVar12 = (uint)*(char *)ppcVar21;
      if (uVar12 != 0x22) {
        piVar3 = (int *)(**(code **)(local_450 + -0x5498))();
        iVar2 = *piVar3;
        do {
          puVar23 = local_450;
          if ((*(ushort *)(iVar2 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
            cVar15 = *(char *)((int)unaff_s5 + 1);
            goto LAB_0060d960;
          }
          *(undefined *)ppcVar21 = 0;
          ppcVar21 = (char **)((int)ppcVar21 + -1);
          if (ppcVar21 < unaff_s4) goto LAB_0060e2f8;
          uVar12 = (uint)*(char *)ppcVar21;
        } while (uVar12 != 0x22);
      }
      puVar23 = local_450;
      if (unaff_s4 == (char **)((int)ppcVar21 + -1)) goto LAB_0060e2f8;
      *(undefined *)ppcVar21 = 0;
    }
    cVar15 = *(char *)((int)unaff_s5 + 1);
LAB_0060d960:
    ppcVar20 = (char **)((int)unaff_s5 + 1);
    ppcVar21 = ppcVar20;
    while( true ) {
      uVar5 = SEXT14(cVar15);
      if (((uVar5 & 0xff) < 0xe) && ((0x2401U >> (uVar5 & 0x1f) & 1) != 0)) goto LAB_0060d9bc;
      ppcStack_4c8 = (char **)0x28;
      if (uVar5 == 0x3b) break;
      unaff_s0 = ppcVar20;
      if (uVar5 == 0x22) {
        cVar15 = *(char *)((int)ppcVar21 + 1);
        unaff_s6 = (char **)((int)ppcVar21 + 1);
        while( true ) {
          uVar5 = SEXT14(cVar15);
          ppcStack_4d8 = (char **)(uint)((uVar5 & 0xff) < 0xe);
          if ((ppcStack_4d8 != (char **)0x0) && ((0x2401U >> (uVar5 & 0x1f) & 1) != 0)) {
            pcVar22 = *(code **)(puVar23 + -0x7910);
            goto joined_r0x0060dd40;
          }
          ppcStack_4c8 = (char **)0x22;
          if (uVar5 == 0x22) break;
          unaff_s6 = (char **)((int)unaff_s6 + 1);
          cVar15 = *(char *)unaff_s6;
        }
        cVar15 = *(char *)((int)unaff_s6 + 1);
        ppcVar21 = (char **)((int)unaff_s6 + 1);
      }
      else {
        if (uVar5 == 0x28) {
          uVar12 = (uint)*(char *)((int)ppcVar21 + 1);
          ppcStack_4d8 = (char **)(uint)((uVar12 & 0xff) < 0xe);
          ppcVar21 = (char **)((int)ppcVar21 + 1);
          if ((ppcStack_4d8 == (char **)0x0) || ((0x2401U >> (uVar12 & 0x1f) & 1) == 0)) {
            ppcStack_4d8 = (char **)&SUB_00000004;
            goto LAB_0060dcc8;
          }
          local_440 = (char **)&SUB_00000004;
          unaff_s6 = ppcVar21;
          goto joined_r0x0060e460;
        }
        cVar15 = *(char *)(char **)((int)ppcVar21 + 1);
        ppcVar21 = (char **)((int)ppcVar21 + 1);
      }
    }
    *(undefined *)ppcVar21 = 0;
    uVar12 = (uint)*(char *)ppcVar20;
    ppcStack_4d8 = unaff_s4;
    if (uVar12 == 0) goto LAB_0060e324;
    if (uVar12 != 0x22) {
      piVar3 = (int *)(**(code **)(puVar23 + -0x5498))();
      do {
        ppcVar13 = (char **)((int)ppcVar20 + 1);
        if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
          pcVar22 = *(code **)(local_450 + -0x53b0);
          ppcStack_4c8 = ppcVar20;
          goto LAB_0060e13c;
        }
        uVar12 = (uint)*(char *)ppcVar13;
        ppcVar20 = ppcVar13;
        if (uVar12 == 0) goto LAB_0060e324;
        puVar23 = local_450;
      } while (uVar12 != 0x22);
    }
    if (*(char *)((int)ppcVar20 + 1) == '\0') goto LAB_0060e324;
    ppcStack_4c8 = (char **)((int)ppcVar20 + 1);
    pcVar22 = *(code **)(puVar23 + -0x53b0);
    if (ppcStack_4c8 == (char **)0x0) goto LAB_0060e324;
LAB_0060e13c:
    iVar2 = (*pcVar22)(ppcStack_4c8);
    ppcVar13 = (char **)((int)ppcStack_4c8 + iVar2 + -1);
    if (ppcVar13 < ppcStack_4c8) goto LAB_0060e324;
    ppcVar20 = (char **)(int)*(char *)ppcVar13;
    if (ppcVar20 == (char **)0x22) {
      ppcVar4 = (char **)((int)ppcVar13 + -1);
    }
    else {
      local_438 = ppcVar13;
      piVar3 = (int *)(**(code **)(local_450 + -0x5498))();
      iVar2 = *piVar3;
      ppcVar14 = local_438;
      do {
        if ((*(ushort *)(iVar2 + ((uint)ppcVar20 & 0xff) * 2) & 0x20) == 0) {
          mime_hdr_addparam_isra_1((char **)((int)pcStack_4e0 + 8));
          unaff_s5 = (char **)((int)ppcVar21 + 1);
          goto LAB_0060e0a4;
        }
        *(undefined *)ppcVar14 = 0;
        ppcVar13 = (char **)((int)ppcVar14 + -1);
        if (ppcVar13 < ppcStack_4c8) goto LAB_0060e324;
        ppcVar20 = (char **)(int)*(char *)ppcVar13;
        ppcVar4 = (char **)((int)ppcVar14 + -2);
        ppcVar14 = ppcVar13;
      } while (ppcVar20 != (char **)0x22);
    }
    if (ppcStack_4c8 == ppcVar4) {
LAB_0060e324:
      ppcStack_4c8 = (char **)0x0;
      mime_hdr_addparam_isra_1((char **)((int)pcStack_4e0 + 8));
      unaff_s5 = (char **)((int)ppcVar21 + 1);
    }
    else {
      *(undefined *)ppcVar13 = 0;
      mime_hdr_addparam_isra_1((char **)((int)pcStack_4e0 + 8));
      unaff_s5 = (char **)((int)ppcVar21 + 1);
    }
  } while( true );
LAB_0060db68:
  uVar12 = (uint)*(char *)ppcVar20;
  if (uVar12 != 0) {
    if (uVar12 != 0x22) {
      piVar3 = (int *)(**(code **)(puVar23 + -0x5498))();
      unaff_s5 = ppcVar20;
      do {
        ppcVar20 = (char **)((int)unaff_s5 + 1);
        if ((*(ushort *)(*piVar3 + (uVar12 & 0xff) * 2) & 0x20) == 0) {
          pcVar22 = *(code **)(local_450 + -0x53b0);
          goto LAB_0060dbcc;
        }
        uVar12 = (uint)*(char *)ppcVar20;
        unaff_s5 = (char **)0x0;
        if (uVar12 == 0) goto LAB_0060dc44;
        unaff_s5 = ppcVar20;
        puVar23 = local_450;
      } while (uVar12 != 0x22);
    }
    if (*(char *)((int)ppcVar20 + 1) != '\0') {
      unaff_s5 = (char **)((int)ppcVar20 + 1);
      pcVar22 = *(code **)(puVar23 + -0x53b0);
      if (unaff_s5 == (char **)0x0) {
        unaff_s5 = (char **)0x0;
        goto LAB_0060dc44;
      }
LAB_0060dbcc:
      iVar2 = (*pcVar22)(unaff_s5);
      ppcVar20 = (char **)((int)unaff_s5 + iVar2 + -1);
      if (unaff_s5 <= ppcVar20) {
        uVar12 = (uint)*(char *)ppcVar20;
        if (uVar12 != 0x22) {
          piVar3 = (int *)(**(code **)(local_450 + -0x5498))();
          ppcStack_4c8 = (char **)0x22;
          iVar2 = *piVar3;
          do {
            if ((*(ushort *)(iVar2 + (uVar12 & 0xff) * 2) & 0x20) == 0) goto LAB_0060dc44;
            *(undefined *)ppcVar20 = 0;
            ppcVar20 = (char **)((int)ppcVar20 + -1);
            if (ppcVar20 < unaff_s5) goto LAB_0060e36c;
            uVar12 = (uint)*(char *)ppcVar20;
          } while (uVar12 != 0x22);
        }
        if (unaff_s5 != (char **)((int)ppcVar20 + -1)) {
          *(undefined *)ppcVar20 = 0;
          goto LAB_0060dc44;
        }
      }
    }
  }
LAB_0060e36c:
  unaff_s5 = (char **)0x0;
LAB_0060dc44:
  pcStack_4e0 = (char *)mime_hdr_new(unaff_s4,unaff_s5);
  ppcStack_4d8 = (char **)pcStack_4e0;
  (**(code **)(local_450 + -0x7e38))(local_43c);
  unaff_s0 = ppcVar20;
  unaff_s6 = ppcVar21;
  puVar23 = local_450;
joined_r0x0060e460:
  if (unaff_s6 == ppcStack_4cc) goto LAB_0060dac8;
  goto LAB_0060d8b4;
LAB_0060dac8:
  if (local_2c == *local_434) {
    return local_43c;
  }
  pcStack_464 = SMIME_read_ASN1;
  iStack_4d0 = local_2c;
  (**(code **)(puVar23 + -0x5328))();
  puStack_4d4 = PTR___stack_chk_guard_006aabf0;
  uStack_468 = 0x2401;
  ppuStack_47c = &switchD_0060d944::switchdataD_0067a670;
  uStack_484 = 0x3b;
  puStack_4a8 = &_gp;
  uStack_49c = 0;
  iStack_48c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (ppcStack_4d8 != (char **)0x0) {
    *ppcStack_4d8 = (char *)0x0;
  }
  ppcStack_488 = unaff_s0;
  ppcStack_480 = (char **)pcStack_4e0;
  ppcStack_478 = unaff_s4;
  ppcStack_474 = unaff_s5;
  ppcStack_470 = unaff_s6;
  ppcStack_46c = ppcStack_4cc;
  iStack_4e8 = mime_parse_hdr(iStack_4d0);
  if (iStack_4e8 == 0) {
    pcVar22 = *(code **)(puStack_4a8 + -0x6eb0);
    pBVar17 = (BIO *)0xcf;
    uStack_4b0 = 0x1bd;
    goto LAB_0060ea0c;
  }
  ppcStack_4cc = apcStack_498;
  pcStack_4e0 = "content-type";
  apcStack_498[0] = "content-type";
  iVar2 = (**(code **)(puStack_4a8 + -0x6e74))(iStack_4e8,ppcStack_4cc);
  if ((iVar2 < 0) ||
     (ppuStack_4dc = (undefined **)(**(code **)(puStack_4a8 + -0x7fbc))(iStack_4e8,iVar2),
     ppuStack_4dc == (undefined **)0x0)) {
LAB_0060e9e0:
    (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
    pBVar17 = (BIO *)0xd1;
    uStack_4b0 = 0x1c3;
    pcVar22 = *(code **)(puStack_4a8 + -0x6eb0);
  }
  else {
    puStack_4e4 = ppuStack_4dc[1];
    if (puStack_4e4 == (undefined *)0x0) goto LAB_0060e9e0;
    iVar2 = (**(code **)(puStack_4a8 + -0x52c0))(puStack_4e4,"multipart/signed");
    if (iVar2 != 0) {
      iVar2 = (**(code **)(puStack_4a8 + -0x52c0))(puStack_4e4,"application/x-pkcs7-mime");
      if ((iVar2 == 0) ||
         (iVar2 = (**(code **)(puStack_4a8 + -0x52c0))(puStack_4e4,"application/pkcs7-mime"),
         iVar2 == 0)) {
        (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
        uVar5 = (**(code **)(puStack_4a8 + -0x7928))();
        puStack_4e4 = (undefined *)(**(code **)(puStack_4a8 + -0x7f3c))(uVar5);
        if (puStack_4e4 == (undefined *)0x0) {
          uStack_4b0 = 0xbb;
          (**(code **)(puStack_4a8 + -0x6eb0))(0xd,0xd1,0x41,"asn_mime.c");
        }
        else {
          pcStack_4e0 = (char *)(**(code **)(puStack_4a8 + -0x7920))(puStack_4e4,iStack_4d0);
          iVar2 = (**(code **)(puStack_4a8 + -0x727c))(ppcStack_4c8,pcStack_4e0,0);
          if (iVar2 != 0) {
            pcVar19 = (char *)0x0;
            pBVar17 = (BIO *)0x0;
            pcVar16 = (code *)&DAT_0000000b;
            (**(code **)(puStack_4a8 + -0x7fc8))(pcStack_4e0);
            (**(code **)(puStack_4a8 + -0x742c))(pcStack_4e0);
            (**(code **)(puStack_4a8 + -0x7f70))(puStack_4e4);
            iStack_4e8 = iVar2;
            goto LAB_0060e648;
          }
          uStack_4b0 = 0xc1;
          (**(code **)(puStack_4a8 + -0x6eb0))(0xd,0xd1,0x6e,"asn_mime.c");
          (**(code **)(puStack_4a8 + -0x7fc8))(pcStack_4e0,0xb,0,0);
          (**(code **)(puStack_4a8 + -0x742c))(pcStack_4e0);
          (**(code **)(puStack_4a8 + -0x7f70))(puStack_4e4);
        }
        pcVar19 = "asn_mime.c";
        pBVar17 = (BIO *)0xcb;
        pcVar16 = (code *)&DAT_000000d4;
        uStack_4b0 = 0x210;
        (**(code **)(puStack_4a8 + -0x6eb0))(0xd);
        iVar2 = 0;
        iStack_4e8 = 0x680000;
      }
      else {
        pcVar19 = "asn_mime.c";
        uStack_4b0 = 0x207;
        (**(code **)(puStack_4a8 + -0x6eb0))(0xd,0xd4,0xcd);
        pBVar17 = (BIO *)ppuStack_4dc[1];
        (**(code **)(puStack_4a8 + -0x6c7c))(2,"type: ");
        pcVar16 = mime_hdr_free;
        (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8);
        iVar2 = 0;
      }
      goto LAB_0060e648;
    }
    apcStack_498[0] = "boundary";
    iVar2 = (**(code **)(puStack_4a8 + -0x6e74))(ppuStack_4dc[2],ppcStack_4cc);
    if (((-1 < iVar2) &&
        (iVar2 = (**(code **)(puStack_4a8 + -0x7fbc))(ppuStack_4dc[2],iVar2), iVar2 != 0)) &&
       (*(int *)(iVar2 + 4) != 0)) {
      ppuStack_4dc = (undefined **)multi_split(iStack_4d0,*(int *)(iVar2 + 4),&uStack_49c);
      puStack_4e4 = (undefined *)0x610000;
      (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
      if ((ppuStack_4dc == (undefined **)0x0) ||
         (iVar2 = (**(code **)(puStack_4a8 + -0x7fb4))(uStack_49c), iVar2 != 2)) {
        pcVar22 = *(code **)(puStack_4a8 + -0x6eb0);
        pBVar17 = (BIO *)0xd2;
        uStack_4b0 = 0x1d4;
LAB_0060e8c4:
        pcVar19 = "asn_mime.c";
        (*pcVar22)(0xd,0xd4);
      }
      else {
        ppuStack_4dc = (undefined **)(**(code **)(puStack_4a8 + -0x7fbc))(uStack_49c,1);
        iStack_4e8 = mime_parse_hdr(ppuStack_4dc);
        if (iStack_4e8 == 0) {
          pcVar22 = *(code **)(puStack_4a8 + -0x6eb0);
          pBVar17 = (BIO *)&DAT_000000d0;
          uStack_4b0 = 0x1dd;
          goto LAB_0060e8c4;
        }
        apcStack_498[0] = "content-type";
        iVar2 = (**(code **)(puStack_4a8 + -0x6e74))(iStack_4e8,ppcStack_4cc);
        if (((iVar2 < 0) ||
            (iStack_4d0 = (**(code **)(puStack_4a8 + -0x7fbc))(iStack_4e8,iVar2), iStack_4d0 == 0))
           || (pcStack_4e0 = *(char **)(iStack_4d0 + 4), (char **)pcStack_4e0 == (char **)0x0)) {
          (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
          pBVar17 = (BIO *)&DAT_000000d4;
          uStack_4b0 = 0x1e7;
          pcVar22 = *(code **)(puStack_4a8 + -0x6eb0);
          goto LAB_0060ea0c;
        }
        iVar2 = (**(code **)(puStack_4a8 + -0x52c0))(pcStack_4e0,"application/x-pkcs7-signature");
        if ((iVar2 == 0) ||
           (iVar2 = (**(code **)(puStack_4a8 + -0x52c0))(pcStack_4e0,"application/pkcs7-signature"),
           iVar2 == 0)) {
          (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
          uVar5 = (**(code **)(puStack_4a8 + -0x7928))();
          pcStack_4e0 = (char *)(**(code **)(puStack_4a8 + -0x7f3c))(uVar5);
          if ((char **)pcStack_4e0 == (char **)0x0) {
            uStack_4b0 = 0xbb;
            (**(code **)(puStack_4a8 + -0x6eb0))(0xd,0xd1,0x41,"asn_mime.c");
          }
          else {
            puStack_4e4 = (undefined *)
                          (**(code **)(puStack_4a8 + -0x7920))(pcStack_4e0,ppuStack_4dc);
            iVar2 = (**(code **)(puStack_4a8 + -0x727c))(ppcStack_4c8,puStack_4e4,0);
            if (iVar2 != 0) {
              pcVar19 = (char *)0x0;
              pBVar17 = (BIO *)0x0;
              (**(code **)(puStack_4a8 + -0x7fc8))(puStack_4e4,0xb);
              (**(code **)(puStack_4a8 + -0x742c))(puStack_4e4);
              (**(code **)(puStack_4a8 + -0x7f70))(pcStack_4e0);
              iStack_4e8 = iVar2;
              if (ppcStack_4d8 == (char **)0x0) {
                pcVar16 = *(code **)(puStack_4a8 + -0x55dc);
                (**(code **)(puStack_4a8 + -0x7d88))(uStack_49c);
              }
              else {
                pcVar16 = (code *)0x0;
                pcVar10 = (char *)(**(code **)(puStack_4a8 + -0x7fbc))(uStack_49c);
                pcVar22 = *(code **)(puStack_4a8 + -0x7f70);
                *ppcStack_4d8 = pcVar10;
                (*pcVar22)(ppuStack_4dc);
                (**(code **)(puStack_4a8 + -0x7f60))(uStack_49c);
              }
              goto LAB_0060e648;
            }
            uStack_4b0 = 0xc1;
            (**(code **)(puStack_4a8 + -0x6eb0))(0xd,0xd1,0x6e,"asn_mime.c");
            (**(code **)(puStack_4a8 + -0x7fc8))(puStack_4e4,0xb,0,0);
            (**(code **)(puStack_4a8 + -0x742c))(puStack_4e4);
            (**(code **)(puStack_4a8 + -0x7f70))(pcStack_4e0);
          }
          iStack_4e8 = 0x680000;
          pcVar22 = *(code **)(puStack_4a8 + -0x6eb0);
          pBVar17 = (BIO *)&DAT_000000cc;
          uStack_4b0 = 0x1f6;
          goto LAB_0060e8c4;
        }
        pcVar19 = "asn_mime.c";
        uStack_4b0 = 0x1ed;
        (**(code **)(puStack_4a8 + -0x6eb0))(0xd,0xd4,0xd5);
        pBVar17 = *(BIO **)(iStack_4d0 + 4);
        (**(code **)(puStack_4a8 + -0x6c7c))(2,"type: ");
        (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
      }
      pcVar16 = *(code **)(puStack_4a8 + -0x55dc);
      (**(code **)(puStack_4a8 + -0x7d88))(uStack_49c);
      iVar2 = 0;
      goto LAB_0060e648;
    }
    (**(code **)(puStack_4a8 + -0x7d88))(iStack_4e8,mime_hdr_free);
    pBVar17 = (BIO *)0xd3;
    uStack_4b0 = 0x1ce;
    pcVar22 = *(code **)(puStack_4a8 + -0x6eb0);
  }
LAB_0060ea0c:
  pcVar19 = "asn_mime.c";
  pcVar16 = (code *)&DAT_000000d4;
  (*pcVar22)(0xd);
  iVar2 = 0;
LAB_0060e648:
  if (iStack_48c == *(int *)puStack_4d4) {
    return iVar2;
  }
  pcStack_4c4 = SMIME_crlf_copy;
  iVar2 = iStack_48c;
  (**(code **)(puStack_4a8 + -0x5328))();
  puVar23 = PTR___stack_chk_guard_006aabf0;
  pBStack_4ec = *(BIO **)PTR___stack_chk_guard_006aabf0;
  val = (ASN1_VALUE *)pcVar16;
  pBVar18 = pBVar17;
  uVar5 = (*(code *)PTR_BIO_f_buffer_006a8940)();
  iVar6 = (*(code *)PTR_BIO_new_006a7fa4)(uVar5);
  if (iVar6 == 0) {
    iVar2 = 0;
  }
  else {
    uVar5 = (*(code *)PTR_BIO_push_006a85c0)(iVar6,pcVar16);
    if (((uint)pBVar17 & 0x80) == 0) {
      if (((uint)pBVar17 & 1) != 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(uVar5,"Content-Type: text/plain\r\n\r\n");
      }
      pcVar19 = acStack_8ee + 2;
LAB_0060ecd4:
      iVar7 = (*(code *)PTR_BIO_gets_006a85d0)(iVar2,pcVar19,0x400);
      if (0 < iVar7) {
        do {
          iVar8 = iVar7 + -1;
          pcVar10 = pcVar19 + iVar7 + -2;
          bVar1 = false;
          cVar15 = acStack_8ee[iVar7 + 1];
          if (cVar15 == '\n') goto LAB_0060ed28;
          while (cVar15 == '\r') {
            iVar7 = iVar8;
            pcVar11 = pcVar10;
            if (iVar8 == 0) goto LAB_0060ed4c;
            while( true ) {
              pcVar10 = pcVar11 + -1;
              iVar8 = iVar7 + -1;
              cVar15 = *pcVar11;
              if (cVar15 != '\n') break;
LAB_0060ed28:
              bVar1 = true;
              iVar7 = iVar8;
              pcVar11 = pcVar10;
              if (iVar8 == 0) goto LAB_0060ed54;
            }
          }
          (*(code *)PTR_BIO_write_006a7f14)(uVar5,pcVar19,iVar7);
LAB_0060ed4c:
          if (!bVar1) goto LAB_0060ecd4;
LAB_0060ed54:
          (*(code *)PTR_BIO_write_006a7f14)(uVar5,"\r\n",2);
          iVar7 = (*(code *)PTR_BIO_gets_006a85d0)(iVar2,pcVar19,0x400);
          if (iVar7 < 1) break;
        } while( true );
      }
    }
    else {
      while (iVar7 = (*(code *)PTR_BIO_read_006a85bc)(iVar2,acStack_8ee + 2,0x400), 0 < iVar7) {
        (*(code *)PTR_BIO_write_006a7f14)(uVar5,acStack_8ee + 2,iVar7);
      }
    }
    pcVar19 = (char *)0x0;
    pBVar18 = (BIO *)0x0;
    val = (ASN1_VALUE *)&DAT_0000000b;
    (*(code *)PTR_BIO_ctrl_006a7f18)(uVar5);
    (*(code *)PTR_BIO_pop_006a8ab4)(uVar5);
    (*(code *)PTR_BIO_free_006a7f70)(iVar6);
    iVar2 = 1;
  }
  if (pBStack_4ec == *(BIO **)puVar23) {
    return iVar2;
  }
  pBVar17 = pBStack_4ec;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (((uint)pcVar19 & 0x1000) == 0) {
    (*(code *)PTR_ASN1_item_i2d_bio_006a8810)(&_gp,pBVar17,val);
    iVar2 = 1;
  }
  else {
    out = BIO_new_NDEF(pBVar17,val,(ASN1_ITEM *)&_gp);
    if (out != (BIO *)0x0) {
      SMIME_crlf_copy(pBVar18,out,(int)pcVar19);
      (*(code *)PTR_BIO_ctrl_006a7f18)(out,0xb,0,0);
      do {
        pBVar18 = (BIO *)(*(code *)PTR_BIO_pop_006a8ab4)(out);
        (*(code *)PTR_BIO_free_006a7f70)(out);
        out = pBVar18;
      } while (pBVar17 != pBVar18);
      return 1;
    }
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xd3,0x41,"asn_mime.c",0x7d);
    iVar2 = 0;
  }
  return iVar2;
}

