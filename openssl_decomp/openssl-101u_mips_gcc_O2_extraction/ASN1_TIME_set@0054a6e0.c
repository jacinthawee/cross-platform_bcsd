
ASN1_TIME * ASN1_TIME_set(ASN1_TIME *s,time_t t)

{
  uchar uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ASN1_TIME *pAVar6;
  int iVar7;
  ASN1_UTCTIME *a;
  uchar *puVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  uchar *puVar12;
  int iVar13;
  code *pcVar14;
  undefined auStack_b0 [44];
  ASN1_UTCTIME *pAStack_84;
  undefined *puStack_80;
  ASN1_TIME *pAStack_7c;
  time_t atStack_64 [3];
  time_t local_44;
  undefined auStack_40 [44];
  int local_14;
  
  puStack_80 = PTR___stack_chk_guard_006a9ae8;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_44 = t;
  iVar5 = (*(code *)PTR_OPENSSL_gmtime_006a8ca0)(&local_44,auStack_40);
  if (iVar5 == 0) {
    iVar5 = 0xad;
    pcVar9 = "a_time.c";
    atStack_64[0] = 0xd9;
    ERR_put_error(0xd,0xd9,0xad,"a_time.c",0x72);
    pAVar6 = (ASN1_TIME *)0x0;
  }
  else {
    pcVar14 = (code *)PTR_ASN1_UTCTIME_adj_006a8ca8;
    if (99 < *(int *)(iVar5 + 0x14) - 0x32U) {
      pcVar14 = (code *)PTR_ASN1_GENERALIZEDTIME_adj_006a8cac;
    }
    pcVar9 = (char *)0x0;
    iVar5 = 0;
    atStack_64[0] = local_44;
    pAVar6 = (ASN1_TIME *)(*pcVar14)(s);
  }
  if (local_14 == *(int *)puStack_80) {
    return pAVar6;
  }
  iVar4 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pAStack_84 = *(ASN1_UTCTIME **)PTR___stack_chk_guard_006a9ae8;
  pAStack_7c = s;
  iVar7 = (*(code *)PTR_OPENSSL_gmtime_006a8ca0)(atStack_64,auStack_b0);
  if (iVar7 == 0) {
    ERR_put_error(0xd,0xd9,0xad,"a_time.c",0x72);
    pAVar6 = (ASN1_TIME *)0x0;
  }
  else if (((iVar5 == 0) && (pcVar9 == (char *)0x0)) ||
          (iVar13 = (*(code *)PTR_OPENSSL_gmtime_adj_006a8ca4)(iVar7,iVar5,pcVar9), iVar13 != 0)) {
    pcVar14 = (code *)PTR_ASN1_UTCTIME_adj_006a8ca8;
    if (99 < *(int *)(iVar7 + 0x14) - 0x32U) {
      pcVar14 = (code *)PTR_ASN1_GENERALIZEDTIME_adj_006a8cac;
    }
    pAVar6 = (ASN1_TIME *)(*pcVar14)(iVar4,atStack_64[0],iVar5,pcVar9);
  }
  else {
    pAVar6 = (ASN1_TIME *)0x0;
  }
  if (pAStack_84 == *(ASN1_UTCTIME **)puVar2) {
    return pAVar6;
  }
  a = pAStack_84;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (a->type != 0x18) {
    if (a->type != 0x17) {
      return (ASN1_TIME *)0x0;
    }
    pAVar6 = (ASN1_TIME *)ASN1_UTCTIME_check(a);
    return pAVar6;
  }
  if ((a->type != 0x18) || (iVar5 = a->length, iVar5 < 0xd)) {
    return (ASN1_TIME *)0x0;
  }
  puVar12 = a->data;
  puVar11 = max_7042;
  uVar1 = *puVar12;
  puVar10 = min_7041;
  iVar7 = 0;
  puVar8 = puVar12;
  iVar4 = 0;
  while( true ) {
    if (9 < ((int)(char)uVar1 - 0x30U & 0xff)) {
      return (ASN1_TIME *)0x0;
    }
    if (9 < ((int)(char)puVar8[1] - 0x30U & 0xff)) {
      return (ASN1_TIME *)0x0;
    }
    iVar13 = iVar4 + 2;
    iVar3 = ((int)(char)uVar1 - 0x30U) * 10 + (int)(char)puVar8[1] + -0x30;
    if (iVar5 < iVar13) {
      return (ASN1_TIME *)0x0;
    }
    if (iVar3 < *(int *)puVar10) {
      return (ASN1_TIME *)0x0;
    }
    if (*(int *)puVar11 < iVar3) {
      return (ASN1_TIME *)0x0;
    }
    iVar7 = iVar7 + 1;
    if (iVar7 == 7) break;
    if (iVar7 == 6) {
      uVar1 = puVar8[2];
      if (uVar1 == 'Z') {
        iVar4 = iVar4 + 3;
        goto LAB_00549fcc;
      }
      if ((uVar1 == '+') || (uVar1 == '-')) goto LAB_00549eb4;
    }
    puVar8 = puVar8 + 2;
    uVar1 = *puVar8;
    puVar11 = (undefined1 *)((int)puVar11 + 4);
    puVar10 = (undefined1 *)((int)puVar10 + 4);
    iVar4 = iVar13;
  }
  iVar7 = (int)(char)puVar12[iVar13];
  iVar3 = iVar4 + 3;
  if (iVar7 != 0x2e) goto LAB_00549e90;
  if (iVar5 < iVar3) {
    return (ASN1_TIME *)0x0;
  }
  if (9 < (byte)(puVar12[iVar3] - 0x30)) {
    return (ASN1_TIME *)0x0;
  }
  puVar8 = puVar12 + iVar4;
  iVar13 = iVar3;
  do {
    iVar7 = (int)(char)puVar8[4];
    iVar13 = iVar13 + 1;
    puVar8 = puVar8 + 1;
    if (9 < (iVar7 - 0x30U & 0xff)) break;
  } while (iVar13 <= iVar5);
  if (iVar3 == iVar13) {
    return (ASN1_TIME *)0x0;
  }
LAB_00549e90:
  iVar4 = iVar13 + 1;
  if (iVar7 != 0x5a) {
    if ((iVar7 != 0x2b) && (iVar7 != 0x2d)) {
      return (ASN1_TIME *)0x0;
    }
LAB_00549eb4:
    if (iVar5 <= iVar13 + 4) {
      return (ASN1_TIME *)0x0;
    }
    if ((((int)(char)puVar12[iVar13 + 1] - 0x30U & 0xff) < 10) &&
       (((int)(char)puVar12[iVar13 + 2] - 0x30U & 0xff) < 10)) {
      if (0x3c < (int)(((int)(char)puVar12[iVar13 + 1] - 0x30U) * 10 +
                      (int)(char)puVar12[iVar13 + 2])) {
        return (ASN1_TIME *)0x0;
      }
      if (((((int)(char)puVar12[iVar13 + 3] - 0x30U & 0xff) < 10) &&
          (((int)(char)puVar12[iVar13 + 4] - 0x30U & 0xff) < 10)) &&
         ((int)(((int)(char)puVar12[iVar13 + 3] - 0x30U) * 10 + (int)(char)puVar12[iVar13 + 4]) <
          0x6c)) {
        return (ASN1_TIME *)(uint)(iVar5 == iVar13 + 5);
      }
    }
    return (ASN1_TIME *)0x0;
  }
LAB_00549fcc:
  return (ASN1_TIME *)(uint)(iVar5 == iVar4);
}

