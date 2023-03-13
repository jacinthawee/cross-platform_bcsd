
int ASN1_UTCTIME_cmp_time_t(ASN1_UTCTIME *s,time_t t)

{
  int iVar1;
  uchar *puVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int in_GS_OFFSET;
  undefined local_3c [44];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  iVar4 = 0;
  puVar2 = s->data;
  if (puVar2[0xc] != 'Z') {
    iVar4 = (puVar2[0x10] - 0x30) + ((uint)puVar2[0xf] * 5 + -0xf0) * 2 +
            ((puVar2[0xe] - 0x30) + ((uint)puVar2[0xd] * 5 + -0xf0) * 2) * 0x3c;
    if (puVar2[0xc] == '-') {
      iVar4 = iVar4 * 0x3c;
    }
    else {
      iVar4 = iVar4 * -0x3c;
    }
  }
  t = t + iVar4;
  piVar5 = (int *)OPENSSL_gmtime(&t,local_3c);
  if (piVar5 == (int *)0x0) {
    uVar6 = 0xfffffffe;
    goto LAB_081373b0;
  }
  pbVar3 = s->data;
  iVar1 = (uint)pbVar3[1] + ((uint)*pbVar3 * 5 + -0xf0) * 2;
  iVar4 = iVar1 + -0x30;
  if (iVar4 < 0x32) {
    iVar4 = iVar1 + 0x34;
  }
  if (piVar5[5] <= iVar4) {
    uVar6 = 1;
    if (piVar5[5] < iVar4) goto LAB_081373b0;
    iVar4 = (uint)pbVar3[3] + ((uint)pbVar3[2] * 5 + -0xf0) * 2;
    if (piVar5[4] < iVar4 + -0x30) {
      if (piVar5[4] < iVar4 + -0x31) goto LAB_081373b0;
      iVar4 = (uint)pbVar3[5] + ((uint)pbVar3[4] * 5 + -0xf0) * 2;
      if (piVar5[3] < iVar4 + -0x2f) {
        if (piVar5[3] < iVar4 + -0x30) goto LAB_081373b0;
        iVar4 = (uint)pbVar3[7] + ((uint)pbVar3[6] * 5 + -0xf0) * 2;
        if (piVar5[2] < iVar4 + -0x2f) {
          if (piVar5[2] < iVar4 + -0x30) goto LAB_081373b0;
          iVar4 = (uint)pbVar3[9] + ((uint)pbVar3[8] * 5 + -0xf0) * 2;
          if (piVar5[1] < iVar4 + -0x2f) {
            uVar6 = 1;
            if (piVar5[1] < iVar4 + -0x30) goto LAB_081373b0;
            iVar4 = (uint)pbVar3[0xb] + ((uint)pbVar3[10] * 5 + -0xf0) * 2;
            if (*piVar5 < iVar4 + -0x2f) {
              uVar6 = (uint)(*piVar5 < iVar4 + -0x30);
              goto LAB_081373b0;
            }
          }
        }
      }
    }
  }
  uVar6 = 0xffffffff;
LAB_081373b0:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar6;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

