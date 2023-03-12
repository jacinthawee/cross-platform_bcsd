
int ASN1_GENERALIZEDTIME_check(ASN1_GENERALIZEDTIME *a)

{
  uchar uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uchar *puVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  
  if (a->type != 0x18) {
    return 0;
  }
  iVar10 = a->length;
  puVar7 = a->data;
  if (iVar10 < 0xd) {
    return 0;
  }
  iVar8 = 0;
  piVar2 = DAT_000b381c + 9;
  iVar6 = 0;
  piVar9 = DAT_000b381c;
  do {
    do {
      iVar5 = iVar6;
      if (9 < (puVar7[iVar5] - 0x30 & 0xff)) {
        return 0;
      }
      if (9 < puVar7[iVar5 + 1] - 0x30) {
        return 0;
      }
      iVar6 = iVar5 + 2;
      iVar4 = (uint)puVar7[iVar5 + 1] + (puVar7[iVar5] - 0x30) * 10 + -0x30;
      if (iVar10 < iVar6) {
        return 0;
      }
      piVar2 = piVar2 + 1;
      if (iVar4 < *piVar2) {
        return 0;
      }
      piVar9 = piVar9 + 1;
      if (*piVar9 < iVar4) {
        return 0;
      }
      iVar8 = iVar8 + 1;
      if (iVar6 == 0xe) {
LAB_000b3796:
        uVar3 = (uint)puVar7[iVar6];
        if (uVar3 != 0x2e) goto LAB_000b379c;
        iVar5 = iVar5 + 3;
        if (iVar10 < iVar5) {
          return 0;
        }
        iVar6 = iVar5;
        if (9 < puVar7[iVar5] - 0x30) {
          return 0;
        }
        goto LAB_000b3782;
      }
    } while (iVar8 != 6);
    uVar1 = puVar7[iVar6];
    if ((uVar1 == '+') || (uVar1 == 'Z')) goto LAB_000b3796;
  } while (uVar1 != '-');
  goto LAB_000b37b2;
  while (iVar6 <= iVar10) {
LAB_000b3782:
    iVar6 = iVar6 + 1;
    uVar3 = (uint)puVar7[iVar6];
    if (9 < uVar3 - 0x30) break;
  }
  if (iVar5 == iVar6) {
    return 0;
  }
LAB_000b379c:
  if (uVar3 == 0x5a) {
    iVar6 = iVar6 + 1;
    goto LAB_000b3800;
  }
  if (uVar3 != 0x2b && uVar3 != 0x2d) {
    return (uint)(uVar3 == 0x2b || uVar3 == 0x2d);
  }
LAB_000b37b2:
  if (((((iVar10 <= iVar6 + 4) || (9 < (puVar7[iVar6 + 1] - 0x30 & 0xff))) ||
       (9 < puVar7[iVar6 + 2] - 0x30)) ||
      ((0x3c < (int)((uint)puVar7[iVar6 + 2] + (puVar7[iVar6 + 1] - 0x30) * 10) ||
       (9 < (puVar7[iVar6 + 3] - 0x30 & 0xff))))) ||
     ((9 < puVar7[iVar6 + 4] - 0x30 ||
      ((iVar8 = (uint)puVar7[iVar6 + 4] + (puVar7[iVar6 + 3] - 0x30) * 10 + -0x30, iVar8 < 0 ||
       (0x3b < iVar8)))))) {
    return 0;
  }
  iVar6 = iVar6 + 5;
LAB_000b3800:
  uVar3 = count_leading_zeroes(iVar6 - iVar10);
  return uVar3 >> 5;
}

