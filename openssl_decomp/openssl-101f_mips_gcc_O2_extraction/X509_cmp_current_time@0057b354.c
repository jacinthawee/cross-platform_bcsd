
/* WARNING: Could not reconcile some variable overlaps */

int X509_cmp_current_time(ASN1_TIME *s)

{
  uchar uVar1;
  char cVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  uchar *puVar9;
  int *piVar10;
  char *pcVar11;
  undefined4 *puVar12;
  int unaff_s2;
  code *pcVar13;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  int iStack_d8;
  undefined4 *puStack_d4;
  uint uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  char acStack_c0 [12];
  char cStack_b4;
  char cStack_b3;
  int iStack_9c;
  ASN1_TIME *pAStack_94;
  undefined *puStack_90;
  int iStack_8c;
  undefined4 *puStack_88;
  code *pcStack_84;
  undefined *local_70;
  undefined4 *local_68;
  undefined4 local_64;
  undefined4 *local_60;
  undefined4 *local_5c;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uchar local_48 [12];
  char local_3c;
  char local_3b;
  int *local_24;
  
  puStack_90 = PTR___stack_chk_guard_006aabf0;
  puVar12 = (undefined4 *)s->type;
  puVar4 = (undefined4 *)s->data;
  local_24 = *(int **)PTR___stack_chk_guard_006aabf0;
  local_70 = &_gp;
  if (puVar12 == (undefined4 *)&DAT_00000017) {
    if (s->length - 0xbU < 7) {
      local_54 = *puVar4;
      local_50 = puVar4[1];
      puVar6 = (undefined4 *)((int)puVar4 + 10);
      puVar9 = (uchar *)((int)&local_4c + 2);
      local_4c = CONCAT13(*(uchar *)(puVar4 + 2),
                          CONCAT12(*(uchar *)((int)puVar4 + 9),(short)local_4c));
      goto LAB_0057b414;
    }
  }
  else if (0xc < s->length) {
    local_54 = *puVar4;
    local_50 = puVar4[1];
    puVar6 = puVar4 + 3;
    local_4c = puVar4[2];
    puVar9 = local_48;
LAB_0057b414:
    uVar1 = *(uchar *)puVar6;
    if (((uVar1 == 'Z') || (uVar1 == '-')) || (uVar1 == '+')) {
      *puVar9 = '0';
      puVar9[1] = '0';
      puVar4 = puVar6;
    }
    else {
      *puVar9 = uVar1;
      puVar9[1] = *(uchar *)((int)puVar6 + 1);
      if (*(uchar *)((int)puVar6 + 2) == '.') {
        puVar4 = (undefined4 *)((int)puVar6 + 3);
        if ((byte)(*(uchar *)((int)puVar6 + 3) - 0x30) < 10) {
          puVar6 = puVar6 + 1;
          do {
            uVar1 = *(uchar *)puVar6;
            puVar4 = puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
          } while ((byte)(uVar1 - 0x30) < 10);
        }
      }
      else {
        puVar4 = (undefined4 *)((int)puVar6 + 2);
      }
    }
    puVar9[3] = '\0';
    puVar9[2] = 'Z';
    uVar1 = *(uchar *)puVar4;
    if (uVar1 == 'Z') {
      unaff_s2 = 0;
    }
    else {
      if ((uVar1 != '+') && (uVar1 != '-')) goto LAB_0057b3b4;
      iVar5 = ((char)*(uchar *)((int)puVar4 + 3) + -0x30) * 10 +
              (char)*(uchar *)(puVar4 + 1) + -0x30 +
              (((char)*(uchar *)((int)puVar4 + 1) + -0x30) * 10 +
              (char)*(uchar *)((int)puVar4 + 2) + -0x30) * 0x3c;
      if (uVar1 == '-') {
        iVar5 = -iVar5;
      }
      unaff_s2 = iVar5 * 0x3c;
    }
    puVar4 = (undefined4 *)&local_3c;
    local_58 = 0;
    local_64 = 0x18;
    local_60 = puVar12;
    local_5c = puVar4;
    (*(code *)PTR_time_006aabe4)(&local_68);
    if (((local_58 & 0x40) != 0) ||
       ((pcVar13 = *(code **)(local_70 + -0x6118), local_60 != (undefined4 *)&DAT_00000017 &&
        (pcVar13 = *(code **)(local_70 + -0x6114), local_60 != (undefined4 *)&DAT_00000018)))) {
      pcVar13 = *(code **)(local_70 + -0x5ed4);
    }
    iVar5 = (*pcVar13)(&local_64,local_68,0,unaff_s2);
    puVar12 = local_68;
    if (iVar5 != 0) {
      if (s->type == 0x17) {
        iVar5 = (local_54._0_1_ + -0x30) * 10 + local_54._1_1_ + -0x30;
        iVar8 = (local_3c + -0x30) * 10 + local_3b + -0x30;
        puVar12 = (undefined4 *)(uint)(iVar8 < 0x32);
        if (iVar5 < 0x32) {
          iVar5 = iVar5 + 100;
        }
        if (puVar12 != (undefined4 *)0x0) {
          iVar8 = iVar8 + 100;
        }
        if (iVar5 < iVar8) {
          iVar5 = -1;
          puVar4 = puVar12;
          goto LAB_0057b3b8;
        }
        pcVar13 = *(code **)(local_70 + -0x52c0);
        if (iVar8 < iVar5) {
          iVar5 = 1;
          puVar4 = puVar12;
          goto LAB_0057b3b8;
        }
      }
      else {
        pcVar13 = *(code **)(local_70 + -0x52c0);
      }
      iVar5 = (*pcVar13)(&local_54);
      if (iVar5 == 0) {
        iVar5 = -1;
      }
      goto LAB_0057b3b8;
    }
  }
LAB_0057b3b4:
  iVar5 = 0;
  puVar4 = puVar12;
LAB_0057b3b8:
  puVar12 = &local_54;
  if (local_24 == *(int **)puStack_90) {
    return iVar5;
  }
  pcStack_84 = X509_cmp_time;
  piVar10 = local_24;
  (**(code **)(local_70 + -0x5328))();
  puVar3 = PTR___stack_chk_guard_006aabf0;
  iVar5 = piVar10[1];
  puVar6 = (undefined4 *)piVar10[2];
  iStack_9c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAStack_94 = s;
  iStack_8c = unaff_s2;
  puStack_88 = puVar12;
  if (iVar5 == 0x17) {
    if (6 < *piVar10 - 0xbU) goto LAB_0057b70c;
    uStack_cc = *puVar6;
    uStack_c8 = puVar6[1];
    puVar7 = (undefined4 *)((int)puVar6 + 10);
    pcVar11 = (char *)((int)&uStack_c4 + 2);
    uStack_c4 = CONCAT13(*(undefined *)(puVar6 + 2),
                         CONCAT12(*(undefined *)((int)puVar6 + 9),(short)uStack_c4));
  }
  else {
    if (*piVar10 < 0xd) goto LAB_0057b70c;
    uStack_cc = *puVar6;
    uStack_c8 = puVar6[1];
    puVar7 = puVar6 + 3;
    uStack_c4 = puVar6[2];
    pcVar11 = acStack_c0;
  }
  cVar2 = *(char *)puVar7;
  if (((cVar2 == 'Z') || (cVar2 == '-')) || (cVar2 == '+')) {
    *pcVar11 = '0';
    pcVar11[1] = '0';
    puVar6 = puVar7;
  }
  else {
    *pcVar11 = cVar2;
    pcVar11[1] = *(char *)((int)puVar7 + 1);
    if (*(char *)((int)puVar7 + 2) == '.') {
      puVar6 = (undefined4 *)((int)puVar7 + 3);
      if ((byte)(*(char *)((int)puVar7 + 3) - 0x30U) < 10) {
        puVar7 = puVar7 + 1;
        do {
          puVar6 = puVar7;
          puVar7 = (undefined4 *)((int)puVar6 + 1);
        } while ((byte)(*(char *)puVar6 - 0x30U) < 10);
      }
    }
    else {
      puVar6 = (undefined4 *)((int)puVar7 + 2);
    }
  }
  pcVar11[3] = '\0';
  pcVar11[2] = 'Z';
  cVar2 = *(char *)puVar6;
  if (((cVar2 != 'Z') && (cVar2 != '+')) && (cVar2 != '-')) goto LAB_0057b70c;
  puVar12 = (undefined4 *)&cStack_b4;
  uStack_d0 = 0;
  uStack_dc = 0x18;
  iStack_d8 = iVar5;
  puStack_d4 = puVar12;
  if (puVar4 != (undefined4 *)0x0) {
    uStack_e0 = *puVar4;
    goto LAB_0057b870;
  }
  (*(code *)PTR_time_006aabe4)(&uStack_e0);
  if ((uStack_d0 & 0x40) == 0) goto LAB_0057b870;
LAB_0057b888:
  iVar5 = (*(code *)PTR_ASN1_TIME_adj_006aa00c)(&uStack_dc,uStack_e0,0);
LAB_0057b89c:
  do {
    if (iVar5 == 0) {
LAB_0057b70c:
      iVar5 = 0;
    }
    else if (piVar10[1] == 0x17) {
      iVar5 = (uStack_cc._0_1_ + -0x30) * 10 + uStack_cc._1_1_ + -0x30;
      iVar8 = (cStack_b4 + -0x30) * 10 + cStack_b3 + -0x30;
      if (iVar5 < 0x32) {
        iVar5 = iVar5 + 100;
      }
      if (iVar8 < 0x32) {
        iVar8 = iVar8 + 100;
      }
      if (iVar5 < iVar8) {
        iVar5 = -1;
      }
      else {
        if (iVar5 <= iVar8) goto LAB_0057b8b4;
        iVar5 = 1;
      }
    }
    else {
LAB_0057b8b4:
      iVar5 = (*(code *)PTR_strcmp_006aac20)(&uStack_cc,puVar12);
      if (iVar5 == 0) {
        iVar5 = -1;
      }
    }
    if (iStack_9c == *(int *)puVar3) {
      return iVar5;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0057b870:
    if (iStack_d8 == 0x17) {
      iVar5 = (*(code *)PTR_ASN1_UTCTIME_adj_006a9dc8)(&uStack_dc,uStack_e0,0);
      goto LAB_0057b89c;
    }
    if (iStack_d8 != 0x18) goto LAB_0057b888;
    iVar5 = (*(code *)PTR_ASN1_GENERALIZEDTIME_adj_006a9dcc)(&uStack_dc,uStack_e0,0);
  } while( true );
}

