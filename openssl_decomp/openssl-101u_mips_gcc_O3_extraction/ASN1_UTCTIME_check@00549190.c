
int ASN1_UTCTIME_check(ASN1_UTCTIME *a)

{
  uchar uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uchar *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  uchar *puVar10;
  int iVar11;
  
  if ((a->type != 0x17) || (iVar2 = a->length, iVar2 < 0xb)) {
    return 0;
  }
  puVar10 = a->data;
  puVar7 = max_7042;
  puVar6 = min_7041;
  iVar8 = 0;
  uVar4 = (int)(char)*puVar10 - 0x30;
  puVar5 = puVar10;
  iVar9 = 0;
  if ((uVar4 & 0xff) < 10) {
    while (((int)(char)puVar5[1] - 0x30U & 0xff) < 10) {
      iVar11 = iVar9 + 2;
      iVar3 = uVar4 * 10 + (int)(char)puVar5[1] + -0x30;
      if (iVar2 < iVar11) {
        return 0;
      }
      if (iVar3 < *(int *)puVar6) {
        return 0;
      }
      if (*(int *)puVar7 < iVar3) {
        return 0;
      }
      iVar8 = iVar8 + 1;
      if (iVar11 == 0xc) {
        uVar1 = puVar10[0xc];
        if (uVar1 != 'Z') {
          if ((uVar1 != '+') && (uVar1 != '-')) goto LAB_005492c8;
LAB_005492f4:
          if (iVar2 <= iVar9 + 6) {
            return 0;
          }
          if (9 < ((int)(char)puVar10[iVar9 + 3] - 0x30U & 0xff)) {
            return 0;
          }
          if (9 < ((int)(char)puVar10[iVar9 + 4] - 0x30U & 0xff)) {
            return 0;
          }
          if (0x3c < (int)(((int)(char)puVar10[iVar9 + 3] - 0x30U) * 10 +
                          (int)(char)puVar10[iVar9 + 4])) {
            return 0;
          }
          if (9 < ((int)(char)puVar10[iVar9 + 5] - 0x30U & 0xff)) {
            return 0;
          }
          if (9 < ((int)(char)puVar10[iVar9 + 6] - 0x30U & 0xff)) {
            return 0;
          }
          if (0x6b < (int)(((int)(char)puVar10[iVar9 + 5] - 0x30U) * 10 +
                          (int)(char)puVar10[iVar9 + 6])) {
            return 0;
          }
          iVar11 = iVar9 + 7;
          goto LAB_005492c8;
        }
LAB_005493a4:
        iVar11 = iVar9 + 3;
LAB_005492c8:
        return (uint)(iVar2 == iVar11);
      }
      if (iVar8 == 5) {
        uVar1 = puVar5[2];
        if (uVar1 == 'Z') goto LAB_005493a4;
        if ((uVar1 == '+') || (uVar1 == '-')) goto LAB_005492f4;
      }
      puVar5 = puVar5 + 2;
      puVar7 = (undefined1 *)((int)puVar7 + 4);
      puVar6 = (undefined1 *)((int)puVar6 + 4);
      uVar4 = (int)(char)*puVar5 - 0x30;
      iVar9 = iVar11;
      if (9 < (uVar4 & 0xff)) {
        return 0;
      }
    }
  }
  return 0;
}

