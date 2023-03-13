
ASN1_TIME * ASN1_TIME_adj(ASN1_TIME *s,time_t t,int offset_day,long offset_sec)

{
  uchar uVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ASN1_TIME *pAVar6;
  ASN1_UTCTIME *a;
  uchar *puVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  uchar *puVar11;
  int iVar12;
  code *pcVar13;
  time_t local_res4 [3];
  undefined auStack_48 [44];
  ASN1_UTCTIME *local_1c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(ASN1_UTCTIME **)PTR___stack_chk_guard_006a9ae8;
  local_res4[0] = t;
  iVar5 = (*(code *)PTR_OPENSSL_gmtime_006a8ca0)(local_res4,auStack_48);
  if (iVar5 == 0) {
    ERR_put_error(0xd,0xd9,0xad,"a_time.c",0x72);
    pAVar6 = (ASN1_TIME *)0x0;
  }
  else if (((offset_day == 0) && (offset_sec == 0)) ||
          (iVar4 = (*(code *)PTR_OPENSSL_gmtime_adj_006a8ca4)(iVar5,offset_day,offset_sec),
          iVar4 != 0)) {
    pcVar13 = (code *)PTR_ASN1_UTCTIME_adj_006a8ca8;
    if (99 < *(int *)(iVar5 + 0x14) - 0x32U) {
      pcVar13 = (code *)PTR_ASN1_GENERALIZEDTIME_adj_006a8cac;
    }
    pAVar6 = (ASN1_TIME *)(*pcVar13)(s,local_res4[0],offset_day,offset_sec);
  }
  else {
    pAVar6 = (ASN1_TIME *)0x0;
  }
  if (local_1c == *(ASN1_UTCTIME **)puVar2) {
    return pAVar6;
  }
  a = local_1c;
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
  puVar11 = a->data;
  puVar10 = max_7042;
  uVar1 = *puVar11;
  puVar9 = min_7041;
  iVar8 = 0;
  puVar7 = puVar11;
  iVar4 = 0;
  while( true ) {
    if (9 < ((int)(char)uVar1 - 0x30U & 0xff)) {
      return (ASN1_TIME *)0x0;
    }
    if (9 < ((int)(char)puVar7[1] - 0x30U & 0xff)) {
      return (ASN1_TIME *)0x0;
    }
    iVar12 = iVar4 + 2;
    iVar3 = ((int)(char)uVar1 - 0x30U) * 10 + (int)(char)puVar7[1] + -0x30;
    if (iVar5 < iVar12) {
      return (ASN1_TIME *)0x0;
    }
    if (iVar3 < *(int *)puVar9) {
      return (ASN1_TIME *)0x0;
    }
    if (*(int *)puVar10 < iVar3) {
      return (ASN1_TIME *)0x0;
    }
    iVar8 = iVar8 + 1;
    if (iVar8 == 7) break;
    if (iVar8 == 6) {
      uVar1 = puVar7[2];
      if (uVar1 == 'Z') {
        iVar4 = iVar4 + 3;
        goto LAB_00549fcc;
      }
      if ((uVar1 == '+') || (uVar1 == '-')) goto LAB_00549eb4;
    }
    puVar7 = puVar7 + 2;
    uVar1 = *puVar7;
    puVar10 = (undefined1 *)((int)puVar10 + 4);
    puVar9 = (undefined1 *)((int)puVar9 + 4);
    iVar4 = iVar12;
  }
  iVar8 = (int)(char)puVar11[iVar12];
  iVar3 = iVar4 + 3;
  if (iVar8 != 0x2e) goto LAB_00549e90;
  if (iVar5 < iVar3) {
    return (ASN1_TIME *)0x0;
  }
  if (9 < (byte)(puVar11[iVar3] - 0x30)) {
    return (ASN1_TIME *)0x0;
  }
  puVar7 = puVar11 + iVar4;
  iVar12 = iVar3;
  do {
    iVar8 = (int)(char)puVar7[4];
    iVar12 = iVar12 + 1;
    puVar7 = puVar7 + 1;
    if (9 < (iVar8 - 0x30U & 0xff)) break;
  } while (iVar12 <= iVar5);
  if (iVar3 == iVar12) {
    return (ASN1_TIME *)0x0;
  }
LAB_00549e90:
  iVar4 = iVar12 + 1;
  if (iVar8 != 0x5a) {
    if ((iVar8 != 0x2b) && (iVar8 != 0x2d)) {
      return (ASN1_TIME *)0x0;
    }
LAB_00549eb4:
    if (iVar5 <= iVar12 + 4) {
      return (ASN1_TIME *)0x0;
    }
    if ((((int)(char)puVar11[iVar12 + 1] - 0x30U & 0xff) < 10) &&
       (((int)(char)puVar11[iVar12 + 2] - 0x30U & 0xff) < 10)) {
      if (0x3c < (int)(((int)(char)puVar11[iVar12 + 1] - 0x30U) * 10 +
                      (int)(char)puVar11[iVar12 + 2])) {
        return (ASN1_TIME *)0x0;
      }
      if (((((int)(char)puVar11[iVar12 + 3] - 0x30U & 0xff) < 10) &&
          (((int)(char)puVar11[iVar12 + 4] - 0x30U & 0xff) < 10)) &&
         ((int)(((int)(char)puVar11[iVar12 + 3] - 0x30U) * 10 + (int)(char)puVar11[iVar12 + 4]) <
          0x6c)) {
        return (ASN1_TIME *)(uint)(iVar5 == iVar12 + 5);
      }
    }
    return (ASN1_TIME *)0x0;
  }
LAB_00549fcc:
  return (ASN1_TIME *)(uint)(iVar5 == iVar4);
}

