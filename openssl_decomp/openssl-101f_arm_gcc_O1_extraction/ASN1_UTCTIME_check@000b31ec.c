
int ASN1_UTCTIME_check(ASN1_UTCTIME *a)

{
  uchar uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uchar *puVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  
  if (a->type != 0x17) {
    return 0;
  }
  iVar10 = a->length;
  puVar7 = a->data;
  if (10 < iVar10) {
    iVar4 = 0;
    piVar9 = DAT_000b32e0 + 8;
    iVar2 = 0;
    piVar8 = DAT_000b32e0;
    do {
      do {
        iVar5 = iVar2;
        if (9 < (puVar7[iVar5] - 0x30 & 0xff)) {
          return 0;
        }
        if (9 < puVar7[iVar5 + 1] - 0x30) {
          return 0;
        }
        iVar2 = iVar5 + 2;
        iVar6 = (uint)puVar7[iVar5 + 1] + (puVar7[iVar5] - 0x30) * 10 + -0x30;
        if (iVar10 < iVar2) {
          return 0;
        }
        piVar9 = piVar9 + 1;
        if (iVar6 < *piVar9) {
          return 0;
        }
        piVar8 = piVar8 + 1;
        if (*piVar8 < iVar6) {
          return 0;
        }
        iVar4 = iVar4 + 1;
        if (iVar4 == 6) {
LAB_000b325c:
          uVar1 = puVar7[iVar2];
          if (uVar1 == 'Z') {
            iVar2 = iVar5 + 3;
            goto LAB_000b32be;
          }
          if (uVar1 != '+' && uVar1 != '-') goto LAB_000b32be;
          goto LAB_000b326a;
        }
      } while (iVar4 != 5);
      uVar1 = puVar7[iVar2];
      if ((uVar1 == '+') || (uVar1 == 'Z')) goto LAB_000b325c;
    } while (uVar1 != '-');
LAB_000b326a:
    if (((((iVar5 + 6 < iVar10) && ((puVar7[iVar5 + 3] - 0x30 & 0xff) < 10)) &&
         (puVar7[iVar5 + 4] - 0x30 < 10)) &&
        (((int)((uint)puVar7[iVar5 + 4] + (puVar7[iVar5 + 3] - 0x30) * 10) < 0x3d &&
         ((puVar7[iVar5 + 5] - 0x30 & 0xff) < 10)))) &&
       ((puVar7[iVar5 + 6] - 0x30 < 10 &&
        ((iVar2 = (uint)puVar7[iVar5 + 6] + (puVar7[iVar5 + 5] - 0x30) * 10 + -0x30, -1 < iVar2 &&
         (iVar2 < 0x3c)))))) {
      iVar2 = iVar5 + 7;
LAB_000b32be:
      uVar3 = count_leading_zeroes(iVar2 - iVar10);
      return uVar3 >> 5;
    }
  }
  return 0;
}

