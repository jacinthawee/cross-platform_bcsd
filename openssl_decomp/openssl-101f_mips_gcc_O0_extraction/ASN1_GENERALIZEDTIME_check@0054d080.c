
int ASN1_GENERALIZEDTIME_check(ASN1_GENERALIZEDTIME *a)

{
  uchar uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uchar *puVar9;
  int iVar10;
  
  if ((a->type != 0x18) || (iVar4 = a->length, iVar4 < 0xd)) {
    return 0;
  }
  puVar9 = a->data;
  puVar8 = max_7035;
  uVar1 = *puVar9;
  puVar7 = min_7034;
  iVar6 = 0;
  puVar5 = puVar9;
  iVar3 = 0;
  while( true ) {
    if (9 < ((int)(char)uVar1 - 0x30U & 0xff)) {
      return 0;
    }
    if (9 < ((int)(char)puVar5[1] - 0x30U & 0xff)) {
      return 0;
    }
    iVar10 = iVar3 + 2;
    iVar2 = ((int)(char)uVar1 - 0x30U) * 10 + (int)(char)puVar5[1] + -0x30;
    if (iVar4 < iVar10) {
      return 0;
    }
    if (iVar2 < *(int *)puVar7) {
      return 0;
    }
    if (*(int *)puVar8 < iVar2) {
      return 0;
    }
    iVar6 = iVar6 + 1;
    if (iVar6 == 7) break;
    if (iVar6 == 6) {
      uVar1 = puVar5[2];
      if (uVar1 == 'Z') {
        iVar3 = iVar3 + 3;
        goto LAB_0054d2dc;
      }
      if ((uVar1 == '+') || (uVar1 == '-')) goto LAB_0054d1c4;
    }
    puVar5 = puVar5 + 2;
    uVar1 = *puVar5;
    puVar8 = (undefined1 *)((int)puVar8 + 4);
    puVar7 = (undefined1 *)((int)puVar7 + 4);
    iVar3 = iVar10;
  }
  iVar6 = (int)(char)puVar9[iVar10];
  iVar2 = iVar3 + 3;
  if (iVar6 != 0x2e) goto LAB_0054d1a0;
  if (iVar4 < iVar2) {
    return 0;
  }
  if (9 < (byte)(puVar9[iVar2] - 0x30)) {
    return 0;
  }
  puVar5 = puVar9 + iVar3;
  iVar10 = iVar2;
  do {
    iVar6 = (int)(char)puVar5[4];
    iVar10 = iVar10 + 1;
    puVar5 = puVar5 + 1;
    if (9 < (iVar6 - 0x30U & 0xff)) break;
  } while (iVar10 <= iVar4);
  if (iVar2 == iVar10) {
    return 0;
  }
LAB_0054d1a0:
  iVar3 = iVar10 + 1;
  if (iVar6 != 0x5a) {
    if ((iVar6 != 0x2b) && (iVar6 != 0x2d)) {
      return 0;
    }
LAB_0054d1c4:
    if (iVar4 <= iVar10 + 4) {
      return 0;
    }
    if ((((int)(char)puVar9[iVar10 + 1] - 0x30U & 0xff) < 10) &&
       (((int)(char)puVar9[iVar10 + 2] - 0x30U & 0xff) < 10)) {
      if (0x3c < (int)(((int)(char)puVar9[iVar10 + 1] - 0x30U) * 10 + (int)(char)puVar9[iVar10 + 2])
         ) {
        return 0;
      }
      if (((((int)(char)puVar9[iVar10 + 3] - 0x30U & 0xff) < 10) &&
          (((int)(char)puVar9[iVar10 + 4] - 0x30U & 0xff) < 10)) &&
         ((int)(((int)(char)puVar9[iVar10 + 3] - 0x30U) * 10 + (int)(char)puVar9[iVar10 + 4]) < 0x6c
         )) {
        return (uint)(iVar4 == iVar10 + 5);
      }
    }
    return 0;
  }
LAB_0054d2dc:
  return (uint)(iVar4 == iVar3);
}

