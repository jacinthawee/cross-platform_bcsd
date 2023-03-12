
ASN1_UTCTIME * ASN1_UTCTIME_set(ASN1_UTCTIME *s,time_t t)

{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  ASN1_UTCTIME *pAVar6;
  int iVar7;
  int iVar8;
  char *in_a2;
  byte *pbVar9;
  char *pcVar10;
  char *in_a3;
  undefined1 *puVar11;
  undefined1 *puVar12;
  char *pcVar13;
  int unaff_s0;
  uchar *unaff_s3;
  uchar *puVar14;
  char *unaff_s4;
  int iVar15;
  undefined auStackY_138 [44];
  int *piStackY_10c;
  int iStackY_104;
  ASN1_UTCTIME *pAStackY_100;
  code *pcStackY_fc;
  char *apcStackY_f4 [3];
  char acStack_c8 [44];
  int iStack_9c;
  int iStack_98;
  ASN1_UTCTIME *pAStack_94;
  undefined *puStack_90;
  uchar *puStack_8c;
  char *pcStack_88;
  code *pcStack_84;
  char *apcStack_7c [3];
  time_t local_4c;
  char acStack_48 [44];
  ASN1_UTCTIME *local_1c;
  
  puStack_90 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(ASN1_UTCTIME **)PTR___stack_chk_guard_006aabf0;
  local_4c = t;
  if ((s == (ASN1_UTCTIME *)0x0) && (s = ASN1_STRING_type_new(0x17), s == (ASN1_STRING *)0x0)) {
    pAVar6 = (ASN1_UTCTIME *)0x0;
  }
  else {
    t = (time_t)acStack_48;
    unaff_s0 = (*(code *)PTR_OPENSSL_gmtime_006a9dc0)(&local_4c);
    if (unaff_s0 == 0) {
LAB_0054cba4:
      pAVar6 = (ASN1_UTCTIME *)0x0;
    }
    else {
      in_a3 = *(char **)(unaff_s0 + 0x14);
      pAVar6 = (ASN1_UTCTIME *)0x0;
      if (in_a3 + -0x32 < &DAT_00000064) {
        unaff_s3 = s->data;
        if ((unaff_s3 == (uchar *)0x0) || ((uint)s->length < 0x14)) {
          unaff_s4 = "r";
          unaff_s3 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"a_utctm.c",0xdd);
          if (unaff_s3 == (uchar *)0x0) {
            in_a3 = "a_utctm.c";
            in_a2 = &DAT_00000041;
            t = 0xda;
            ERR_put_error(0xd,0xda,0x41,"a_utctm.c",0xe0);
            goto LAB_0054cba4;
          }
          if (s->data != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          in_a3 = *(char **)(unaff_s0 + 0x14);
          s->data = unaff_s3;
        }
        unaff_s4 = "r";
        t = (time_t)&DAT_00000014;
        in_a2 = "%02d%02d%02d%02d%02d%02dZ";
        in_a3 = (char *)((int)in_a3 % 100);
        (*(code *)PTR_BIO_snprintf_006a8060)(unaff_s3);
        iVar3 = (*(code *)PTR_strlen_006aab30)(unaff_s3);
        s->length = iVar3;
        s->type = 0x17;
        pAVar6 = s;
      }
    }
  }
  if (local_1c == *(ASN1_UTCTIME **)puStack_90) {
    return pAVar6;
  }
  pcStack_84 = ASN1_UTCTIME_adj;
  pAStackY_100 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iStack_9c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_98 = unaff_s0;
  pAStack_94 = s;
  puStack_8c = unaff_s3;
  pcStack_88 = unaff_s4;
  apcStack_7c[0] = (char *)t;
  if ((pAStackY_100 == (ASN1_UTCTIME *)0x0) &&
     (pAStackY_100 = ASN1_STRING_type_new(0x17), pAStackY_100 == (ASN1_STRING *)0x0)) {
    pAVar6 = (ASN1_UTCTIME *)0x0;
  }
  else {
    t = (time_t)acStack_c8;
    unaff_s0 = (*(code *)PTR_OPENSSL_gmtime_006a9dc0)(apcStack_7c);
    if ((unaff_s0 == 0) ||
       (((in_a2 != (char *)0x0 || (in_a3 != (char *)0x0)) &&
        (iVar3 = (*(code *)PTR_OPENSSL_gmtime_adj_006a9dc4)(unaff_s0,in_a2,in_a3), t = (time_t)in_a2
        , iVar3 == 0)))) {
      pAVar6 = (ASN1_UTCTIME *)0x0;
    }
    else {
      iVar3 = *(int *)(unaff_s0 + 0x14);
      pAVar6 = (ASN1_UTCTIME *)0x0;
      if (iVar3 - 0x32U < 100) {
        puVar14 = pAStackY_100->data;
        if ((puVar14 == (uchar *)0x0) || ((uint)pAStackY_100->length < 0x14)) {
          puVar14 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"a_utctm.c",0xdd);
          if (puVar14 == (uchar *)0x0) {
            t = 0xda;
            ERR_put_error(0xd,0xda,0x41,"a_utctm.c",0xe0);
            pAVar6 = (ASN1_UTCTIME *)0x0;
            goto LAB_0054cd5c;
          }
          if (pAStackY_100->data != (uchar *)0x0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          iVar3 = *(int *)(unaff_s0 + 0x14);
          pAStackY_100->data = puVar14;
        }
        t = (time_t)&DAT_00000014;
        (*(code *)PTR_BIO_snprintf_006a8060)(puVar14,0x14,"%02d%02d%02d%02d%02d%02dZ",iVar3 % 100);
        iVar3 = (*(code *)PTR_strlen_006aab30)(puVar14);
        pAStackY_100->length = iVar3;
        pAStackY_100->type = 0x17;
        pAVar6 = pAStackY_100;
      }
    }
  }
LAB_0054cd5c:
  if (iStack_9c == *(int *)puVar2) {
    return pAVar6;
  }
  pcStackY_fc = ASN1_UTCTIME_cmp_time_t;
  iVar3 = iStack_9c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar8 = *(int *)(iVar3 + 8);
  piStackY_10c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (*(char *)(iVar8 + 0xc) == 'Z') {
    iVar4 = 0;
  }
  else {
    iVar4 = ((*(byte *)(iVar8 + 0xd) - 0x30) * 10 + (uint)*(byte *)(iVar8 + 0xe) + -0x30) * 0x3c +
            (*(byte *)(iVar8 + 0xf) - 0x30) * 10 + (uint)*(byte *)(iVar8 + 0x10) + -0x30;
    if (*(char *)(iVar8 + 0xc) == '-') {
      iVar4 = -iVar4;
    }
    iVar4 = iVar4 * -0x3c;
  }
  apcStackY_f4[0] = (char *)(t + iVar4);
  iStackY_104 = unaff_s0;
  piVar5 = (int *)(*(code *)PTR_OPENSSL_gmtime_006a9dc0)(apcStackY_f4,auStackY_138);
  pbVar9 = *(byte **)(iVar3 + 8);
  iVar8 = (*pbVar9 - 0x30) * 10 + (uint)pbVar9[1];
  iVar3 = iVar8 + -0x30;
  if (iVar3 < 0x32) {
    iVar3 = iVar8 + 0x34;
  }
  if (piVar5[5] <= iVar3) {
    if (piVar5[5] < iVar3) {
LAB_0054d034:
      pAVar6 = (ASN1_UTCTIME *)0x1;
      goto LAB_0054d038;
    }
    iVar3 = (pbVar9[2] - 0x30) * 10 + (uint)pbVar9[3];
    if (piVar5[4] < iVar3 + -0x30) {
      if (piVar5[4] < iVar3 + -0x31) goto LAB_0054d034;
      iVar3 = (pbVar9[4] - 0x30) * 10 + (uint)pbVar9[5];
      if (piVar5[3] < iVar3 + -0x2f) {
        if (piVar5[3] < iVar3 + -0x30) goto LAB_0054d034;
        iVar3 = (pbVar9[6] - 0x30) * 10 + (uint)pbVar9[7];
        if (piVar5[2] < iVar3 + -0x2f) {
          if (piVar5[2] < iVar3 + -0x30) goto LAB_0054d034;
          iVar3 = (pbVar9[8] - 0x30) * 10 + (uint)pbVar9[9];
          if (piVar5[1] < iVar3 + -0x2f) {
            if (piVar5[1] < iVar3 + -0x30) goto LAB_0054d034;
            iVar3 = (pbVar9[10] - 0x30) * 10 + (uint)pbVar9[0xb];
            if (*piVar5 < iVar3 + -0x2f) {
              pAVar6 = (ASN1_UTCTIME *)(uint)(*piVar5 < iVar3 + -0x30);
              goto LAB_0054d038;
            }
          }
        }
      }
    }
  }
  pAVar6 = (ASN1_UTCTIME *)0xffffffff;
LAB_0054d038:
  if (piStackY_10c == *(int **)puVar2) {
    return pAVar6;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if ((piStackY_10c[1] != 0x18) || (iVar3 = *piStackY_10c, iVar3 < 0xd)) {
    return (ASN1_UTCTIME *)0x0;
  }
  pcVar13 = (char *)piStackY_10c[2];
  puVar12 = max_7035;
  cVar1 = *pcVar13;
  puVar11 = min_7034;
  iVar4 = 0;
  pcVar10 = pcVar13;
  iVar8 = 0;
  while( true ) {
    if (9 < ((int)cVar1 - 0x30U & 0xff)) {
      return (ASN1_UTCTIME *)0x0;
    }
    if (9 < ((int)pcVar10[1] - 0x30U & 0xff)) {
      return (ASN1_UTCTIME *)0x0;
    }
    iVar15 = iVar8 + 2;
    iVar7 = ((int)cVar1 - 0x30U) * 10 + (int)pcVar10[1] + -0x30;
    if (iVar3 < iVar15) {
      return (ASN1_UTCTIME *)0x0;
    }
    if (iVar7 < *(int *)puVar11) {
      return (ASN1_UTCTIME *)0x0;
    }
    if (*(int *)puVar12 < iVar7) {
      return (ASN1_UTCTIME *)0x0;
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 7) break;
    if (iVar4 == 6) {
      cVar1 = pcVar10[2];
      if (cVar1 == 'Z') {
        iVar8 = iVar8 + 3;
        goto LAB_0054d2dc;
      }
      if ((cVar1 == '+') || (cVar1 == '-')) goto LAB_0054d1c4;
    }
    pcVar10 = pcVar10 + 2;
    cVar1 = *pcVar10;
    puVar12 = (undefined1 *)((int)puVar12 + 4);
    puVar11 = (undefined1 *)((int)puVar11 + 4);
    iVar8 = iVar15;
  }
  iVar4 = (int)pcVar13[iVar15];
  iVar7 = iVar8 + 3;
  if (iVar4 != 0x2e) goto LAB_0054d1a0;
  if (iVar3 < iVar7) {
    return (ASN1_UTCTIME *)0x0;
  }
  if (9 < (byte)(pcVar13[iVar7] - 0x30U)) {
    return (ASN1_UTCTIME *)0x0;
  }
  pcVar10 = pcVar13 + iVar8;
  iVar15 = iVar7;
  do {
    iVar4 = (int)pcVar10[4];
    iVar15 = iVar15 + 1;
    pcVar10 = pcVar10 + 1;
    if (9 < (iVar4 - 0x30U & 0xff)) break;
  } while (iVar15 <= iVar3);
  if (iVar7 == iVar15) {
    return (ASN1_UTCTIME *)0x0;
  }
LAB_0054d1a0:
  iVar8 = iVar15 + 1;
  if (iVar4 != 0x5a) {
    if ((iVar4 != 0x2b) && (iVar4 != 0x2d)) {
      return (ASN1_UTCTIME *)0x0;
    }
LAB_0054d1c4:
    if (iVar3 <= iVar15 + 4) {
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
      return (ASN1_UTCTIME *)(uint)(iVar3 == iVar15 + 5);
    }
    return (ASN1_UTCTIME *)0x0;
  }
LAB_0054d2dc:
  return (ASN1_UTCTIME *)(uint)(iVar3 == iVar8);
}

