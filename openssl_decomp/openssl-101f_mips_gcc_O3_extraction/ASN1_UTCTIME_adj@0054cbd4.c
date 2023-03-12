
ASN1_UTCTIME * ASN1_UTCTIME_adj(ASN1_UTCTIME *s,time_t t,int offset_day,long offset_sec)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  ASN1_UTCTIME *pAVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  char *pcVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  char *pcVar13;
  int unaff_s0;
  uchar *puVar14;
  int iVar15;
  time_t local_res4 [3];
  undefined auStackY_b8 [44];
  int *piStackY_8c;
  int iStackY_84;
  ASN1_UTCTIME *pAStackY_80;
  code *pcStackY_7c;
  undefined *apuStackY_74 [3];
  undefined auStack_48 [44];
  int local_1c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_res4[0] = t;
  if ((s == (ASN1_UTCTIME *)0x0) && (s = ASN1_STRING_type_new(0x17), s == (ASN1_STRING *)0x0)) {
    pAVar5 = (ASN1_UTCTIME *)0x0;
  }
  else {
    t = (time_t)auStack_48;
    unaff_s0 = (*(code *)PTR_OPENSSL_gmtime_006a9dc0)(local_res4);
    if ((unaff_s0 == 0) ||
       (((offset_day != 0 || (offset_sec != 0)) &&
        (iVar10 = (*(code *)PTR_OPENSSL_gmtime_adj_006a9dc4)(unaff_s0,offset_day,offset_sec),
        t = offset_day, iVar10 == 0)))) {
      pAVar5 = (ASN1_UTCTIME *)0x0;
    }
    else {
      iVar10 = *(int *)(unaff_s0 + 0x14);
      pAVar5 = (ASN1_UTCTIME *)0x0;
      if (iVar10 - 0x32U < 100) {
        puVar14 = s->data;
        if ((puVar14 == (uchar *)0x0) || ((uint)s->length < 0x14)) {
          puVar14 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"a_utctm.c",0xdd);
          if (puVar14 == (uchar *)0x0) {
            t = 0xda;
            ERR_put_error(0xd,0xda,0x41,"a_utctm.c",0xe0);
            pAVar5 = (ASN1_UTCTIME *)0x0;
            goto LAB_0054cd5c;
          }
          if (s->data != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          iVar10 = *(int *)(unaff_s0 + 0x14);
          s->data = puVar14;
        }
        t = (time_t)&DAT_00000014;
        (*(code *)PTR_BIO_snprintf_006a8060)(puVar14,0x14,"%02d%02d%02d%02d%02d%02dZ",iVar10 % 100);
        iVar10 = (*(code *)PTR_strlen_006aab30)(puVar14);
        s->length = iVar10;
        s->type = 0x17;
        pAVar5 = s;
      }
    }
  }
LAB_0054cd5c:
  if (local_1c == *(int *)puVar2) {
    return pAVar5;
  }
  pcStackY_7c = ASN1_UTCTIME_cmp_time_t;
  iVar10 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar7 = *(int *)(iVar10 + 8);
  piStackY_8c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (*(char *)(iVar7 + 0xc) == 'Z') {
    iVar3 = 0;
  }
  else {
    iVar3 = ((*(byte *)(iVar7 + 0xd) - 0x30) * 10 + (uint)*(byte *)(iVar7 + 0xe) + -0x30) * 0x3c +
            (*(byte *)(iVar7 + 0xf) - 0x30) * 10 + (uint)*(byte *)(iVar7 + 0x10) + -0x30;
    if (*(char *)(iVar7 + 0xc) == '-') {
      iVar3 = -iVar3;
    }
    iVar3 = iVar3 * -0x3c;
  }
  apuStackY_74[0] = (undefined *)(t + iVar3);
  iStackY_84 = unaff_s0;
  pAStackY_80 = s;
  piVar4 = (int *)(*(code *)PTR_OPENSSL_gmtime_006a9dc0)(apuStackY_74,auStackY_b8);
  pbVar8 = *(byte **)(iVar10 + 8);
  iVar7 = (*pbVar8 - 0x30) * 10 + (uint)pbVar8[1];
  iVar10 = iVar7 + -0x30;
  if (iVar10 < 0x32) {
    iVar10 = iVar7 + 0x34;
  }
  if (piVar4[5] <= iVar10) {
    if (piVar4[5] < iVar10) {
LAB_0054d034:
      pAVar5 = (ASN1_UTCTIME *)0x1;
      goto LAB_0054d038;
    }
    iVar10 = (pbVar8[2] - 0x30) * 10 + (uint)pbVar8[3];
    if (piVar4[4] < iVar10 + -0x30) {
      if (piVar4[4] < iVar10 + -0x31) goto LAB_0054d034;
      iVar10 = (pbVar8[4] - 0x30) * 10 + (uint)pbVar8[5];
      if (piVar4[3] < iVar10 + -0x2f) {
        if (piVar4[3] < iVar10 + -0x30) goto LAB_0054d034;
        iVar10 = (pbVar8[6] - 0x30) * 10 + (uint)pbVar8[7];
        if (piVar4[2] < iVar10 + -0x2f) {
          if (piVar4[2] < iVar10 + -0x30) goto LAB_0054d034;
          iVar10 = (pbVar8[8] - 0x30) * 10 + (uint)pbVar8[9];
          if (piVar4[1] < iVar10 + -0x2f) {
            if (piVar4[1] < iVar10 + -0x30) goto LAB_0054d034;
            iVar10 = (pbVar8[10] - 0x30) * 10 + (uint)pbVar8[0xb];
            if (*piVar4 < iVar10 + -0x2f) {
              pAVar5 = (ASN1_UTCTIME *)(uint)(*piVar4 < iVar10 + -0x30);
              goto LAB_0054d038;
            }
          }
        }
      }
    }
  }
  pAVar5 = (ASN1_UTCTIME *)0xffffffff;
LAB_0054d038:
  if (piStackY_8c == *(int **)puVar2) {
    return pAVar5;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((piStackY_8c[1] != 0x18) || (iVar10 = *piStackY_8c, iVar10 < 0xd)) {
    return (ASN1_UTCTIME *)0x0;
  }
  pcVar13 = (char *)piStackY_8c[2];
  puVar12 = max_7035;
  cVar1 = *pcVar13;
  puVar11 = min_7034;
  iVar3 = 0;
  pcVar9 = pcVar13;
  iVar7 = 0;
  while( true ) {
    if (9 < ((int)cVar1 - 0x30U & 0xff)) {
      return (ASN1_UTCTIME *)0x0;
    }
    if (9 < ((int)pcVar9[1] - 0x30U & 0xff)) {
      return (ASN1_UTCTIME *)0x0;
    }
    iVar15 = iVar7 + 2;
    iVar6 = ((int)cVar1 - 0x30U) * 10 + (int)pcVar9[1] + -0x30;
    if (iVar10 < iVar15) {
      return (ASN1_UTCTIME *)0x0;
    }
    if (iVar6 < *(int *)puVar11) {
      return (ASN1_UTCTIME *)0x0;
    }
    if (*(int *)puVar12 < iVar6) {
      return (ASN1_UTCTIME *)0x0;
    }
    iVar3 = iVar3 + 1;
    if (iVar3 == 7) break;
    if (iVar3 == 6) {
      cVar1 = pcVar9[2];
      if (cVar1 == 'Z') {
        iVar7 = iVar7 + 3;
        goto LAB_0054d2dc;
      }
      if ((cVar1 == '+') || (cVar1 == '-')) goto LAB_0054d1c4;
    }
    pcVar9 = pcVar9 + 2;
    cVar1 = *pcVar9;
    puVar12 = (undefined1 *)((int)puVar12 + 4);
    puVar11 = (undefined1 *)((int)puVar11 + 4);
    iVar7 = iVar15;
  }
  iVar3 = (int)pcVar13[iVar15];
  iVar6 = iVar7 + 3;
  if (iVar3 != 0x2e) goto LAB_0054d1a0;
  if (iVar10 < iVar6) {
    return (ASN1_UTCTIME *)0x0;
  }
  if (9 < (byte)(pcVar13[iVar6] - 0x30U)) {
    return (ASN1_UTCTIME *)0x0;
  }
  pcVar9 = pcVar13 + iVar7;
  iVar15 = iVar6;
  do {
    iVar3 = (int)pcVar9[4];
    iVar15 = iVar15 + 1;
    pcVar9 = pcVar9 + 1;
    if (9 < (iVar3 - 0x30U & 0xff)) break;
  } while (iVar15 <= iVar10);
  if (iVar6 == iVar15) {
    return (ASN1_UTCTIME *)0x0;
  }
LAB_0054d1a0:
  iVar7 = iVar15 + 1;
  if (iVar3 != 0x5a) {
    if ((iVar3 != 0x2b) && (iVar3 != 0x2d)) {
      return (ASN1_UTCTIME *)0x0;
    }
LAB_0054d1c4:
    if (iVar10 <= iVar15 + 4) {
      return (ASN1_UTCTIME *)0x0;
    }
    if (9 < ((int)pcVar13[iVar15 + 1] - 0x30U & 0xff)) {
      return (ASN1_UTCTIME *)0x0;
    }
    if (9 < ((int)pcVar13[iVar15 + 2] - 0x30U & 0xff)) {
      return (ASN1_UTCTIME *)0x0;
    }
    if ((int)(((int)pcVar13[iVar15 + 1] - 0x30U) * 10 + (int)pcVar13[iVar15 + 2]) < 0x3d) {
      if (9 < ((int)pcVar13[iVar15 + 3] - 0x30U & 0xff)) {
        return (ASN1_UTCTIME *)0x0;
      }
      if (9 < ((int)pcVar13[iVar15 + 4] - 0x30U & 0xff)) {
        return (ASN1_UTCTIME *)0x0;
      }
      if (0x6b < (int)(((int)pcVar13[iVar15 + 3] - 0x30U) * 10 + (int)pcVar13[iVar15 + 4])) {
        return (ASN1_UTCTIME *)0x0;
      }
      return (ASN1_UTCTIME *)(uint)(iVar10 == iVar15 + 5);
    }
    return (ASN1_UTCTIME *)0x0;
  }
LAB_0054d2dc:
  return (ASN1_UTCTIME *)(uint)(iVar10 == iVar7);
}

