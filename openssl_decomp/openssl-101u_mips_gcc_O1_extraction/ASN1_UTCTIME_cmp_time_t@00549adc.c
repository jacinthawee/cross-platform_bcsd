
int ASN1_UTCTIME_cmp_time_t(ASN1_UTCTIME *s,time_t t)

{
  char cVar1;
  undefined *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uchar *puVar7;
  int iVar8;
  byte *pbVar9;
  char *pcVar10;
  int iVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  char *pcVar14;
  int iVar15;
  int local_res4 [3];
  undefined auStack_40 [44];
  int *local_14;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  puVar7 = s->data;
  local_14 = *(int **)PTR___stack_chk_guard_006a9ae8;
  if (puVar7[0xc] == 'Z') {
    local_res4[0] = 0;
  }
  else {
    local_res4[0] =
         ((puVar7[0xd] - 0x30) * 10 + (uint)puVar7[0xe] + -0x30) * 0x3c +
         (puVar7[0xf] - 0x30) * 10 + (uint)puVar7[0x10] + -0x30;
    if (puVar7[0xc] == '-') {
      local_res4[0] = -local_res4[0];
    }
    local_res4[0] = local_res4[0] * -0x3c;
  }
  local_res4[0] = t + local_res4[0];
  piVar3 = (int *)(*(code *)PTR_OPENSSL_gmtime_006a8ca0)(local_res4,auStack_40);
  if (piVar3 == (int *)0x0) {
    uVar4 = 0xfffffffe;
    goto LAB_00549d1c;
  }
  pbVar9 = s->data;
  iVar6 = (*pbVar9 - 0x30) * 10 + (uint)pbVar9[1];
  iVar8 = iVar6 + -0x30;
  if (iVar8 < 0x32) {
    iVar8 = iVar6 + 0x34;
  }
  if (piVar3[5] <= iVar8) {
    if (piVar3[5] < iVar8) {
LAB_00549d18:
      uVar4 = 1;
      goto LAB_00549d1c;
    }
    iVar8 = (pbVar9[2] - 0x30) * 10 + (uint)pbVar9[3];
    if (piVar3[4] < iVar8 + -0x30) {
      if (piVar3[4] < iVar8 + -0x31) goto LAB_00549d18;
      iVar8 = (pbVar9[4] - 0x30) * 10 + (uint)pbVar9[5];
      if (piVar3[3] < iVar8 + -0x2f) {
        if (piVar3[3] < iVar8 + -0x30) goto LAB_00549d18;
        iVar8 = (pbVar9[6] - 0x30) * 10 + (uint)pbVar9[7];
        if (piVar3[2] < iVar8 + -0x2f) {
          if (piVar3[2] < iVar8 + -0x30) goto LAB_00549d18;
          iVar8 = (pbVar9[8] - 0x30) * 10 + (uint)pbVar9[9];
          if (piVar3[1] < iVar8 + -0x2f) {
            if (piVar3[1] < iVar8 + -0x30) goto LAB_00549d18;
            iVar8 = (pbVar9[10] - 0x30) * 10 + (uint)pbVar9[0xb];
            if (*piVar3 < iVar8 + -0x2f) {
              uVar4 = (uint)(*piVar3 < iVar8 + -0x30);
              goto LAB_00549d1c;
            }
          }
        }
      }
    }
  }
  uVar4 = 0xffffffff;
LAB_00549d1c:
  if (local_14 == *(int **)puVar2) {
    return uVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((local_14[1] != 0x18) || (iVar8 = *local_14, iVar8 < 0xd)) {
    return 0;
  }
  pcVar14 = (char *)local_14[2];
  puVar13 = max_7042;
  cVar1 = *pcVar14;
  puVar12 = min_7041;
  iVar11 = 0;
  pcVar10 = pcVar14;
  iVar6 = 0;
  while( true ) {
    if (9 < ((int)cVar1 - 0x30U & 0xff)) {
      return 0;
    }
    if (9 < ((int)pcVar10[1] - 0x30U & 0xff)) {
      return 0;
    }
    iVar15 = iVar6 + 2;
    iVar5 = ((int)cVar1 - 0x30U) * 10 + (int)pcVar10[1] + -0x30;
    if (iVar8 < iVar15) {
      return 0;
    }
    if (iVar5 < *(int *)puVar12) {
      return 0;
    }
    if (*(int *)puVar13 < iVar5) {
      return 0;
    }
    iVar11 = iVar11 + 1;
    if (iVar11 == 7) break;
    if (iVar11 == 6) {
      cVar1 = pcVar10[2];
      if (cVar1 == 'Z') {
        iVar6 = iVar6 + 3;
        goto LAB_00549fcc;
      }
      if ((cVar1 == '+') || (cVar1 == '-')) goto LAB_00549eb4;
    }
    pcVar10 = pcVar10 + 2;
    cVar1 = *pcVar10;
    puVar13 = (undefined1 *)((int)puVar13 + 4);
    puVar12 = (undefined1 *)((int)puVar12 + 4);
    iVar6 = iVar15;
  }
  iVar11 = (int)pcVar14[iVar15];
  iVar5 = iVar6 + 3;
  if (iVar11 != 0x2e) goto LAB_00549e90;
  if (iVar8 < iVar5) {
    return 0;
  }
  if (9 < (byte)(pcVar14[iVar5] - 0x30U)) {
    return 0;
  }
  pcVar10 = pcVar14 + iVar6;
  iVar15 = iVar5;
  do {
    iVar11 = (int)pcVar10[4];
    iVar15 = iVar15 + 1;
    pcVar10 = pcVar10 + 1;
    if (9 < (iVar11 - 0x30U & 0xff)) break;
  } while (iVar15 <= iVar8);
  if (iVar5 == iVar15) {
    return 0;
  }
LAB_00549e90:
  iVar6 = iVar15 + 1;
  if (iVar11 != 0x5a) {
    if ((iVar11 != 0x2b) && (iVar11 != 0x2d)) {
      return 0;
    }
LAB_00549eb4:
    if (iVar8 <= iVar15 + 4) {
      return 0;
    }
    if (9 < ((int)pcVar14[iVar15 + 1] - 0x30U & 0xff)) {
      return 0;
    }
    if (9 < ((int)pcVar14[iVar15 + 2] - 0x30U & 0xff)) {
      return 0;
    }
    if ((int)(((int)pcVar14[iVar15 + 1] - 0x30U) * 10 + (int)pcVar14[iVar15 + 2]) < 0x3d) {
      if (9 < ((int)pcVar14[iVar15 + 3] - 0x30U & 0xff)) {
        return 0;
      }
      if (9 < ((int)pcVar14[iVar15 + 4] - 0x30U & 0xff)) {
        return 0;
      }
      if (0x6b < (int)(((int)pcVar14[iVar15 + 3] - 0x30U) * 10 + (int)pcVar14[iVar15 + 4])) {
        return 0;
      }
      return (uint)(iVar8 == iVar15 + 5);
    }
    return 0;
  }
LAB_00549fcc:
  return (uint)(iVar8 == iVar6);
}

