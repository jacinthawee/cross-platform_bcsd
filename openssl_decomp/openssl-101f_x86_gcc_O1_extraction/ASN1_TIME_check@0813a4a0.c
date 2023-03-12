
int ASN1_TIME_check(ASN1_TIME *t)

{
  int iVar1;
  uchar uVar2;
  uchar *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (t->type != 0x18) {
    if (t->type == 0x17) {
      iVar5 = ASN1_UTCTIME_check(t);
      return iVar5;
    }
    return 0;
  }
  if (t->type != 0x18) {
    return 0;
  }
  iVar5 = t->length;
  if (iVar5 < 0xd) {
    return 0;
  }
  puVar3 = t->data;
  iVar7 = 0;
  uVar2 = *puVar3;
  iVar6 = 0;
  if ((byte)(uVar2 - 0x30) < 10) {
    while( true ) {
      if (9 < (byte)(puVar3[iVar6 + 1] - 0x30)) break;
      iVar1 = (char)puVar3[iVar6 + 1] + -0x30 + ((char)uVar2 + -0x30) * 10;
      iVar8 = iVar6 + 2;
      if (iVar5 < iVar8) {
        return 0;
      }
      if (iVar1 < *(int *)(min_7014 + iVar7 * 4)) {
        return 0;
      }
      if (*(int *)(max_7015 + iVar7 * 4) < iVar1) {
        return 0;
      }
      iVar7 = iVar7 + 1;
      if ((iVar8 == 0xe) ||
         ((iVar7 == 6 && (((puVar3[iVar8] - 0x2b & 0xfd) == 0 || (puVar3[iVar8] == 'Z')))))) {
        uVar2 = puVar3[iVar8];
        if (uVar2 != '.') goto LAB_08139d3f;
        iVar7 = iVar6 + 3;
        if (iVar5 < iVar7) {
          return 0;
        }
        iVar8 = iVar7;
        if (9 < (byte)(puVar3[iVar6 + 3] - 0x30)) {
          return 0;
        }
        goto LAB_08139e14;
      }
      uVar2 = puVar3[iVar8];
      iVar6 = iVar8;
      if (9 < (byte)(uVar2 - 0x30)) {
        return 0;
      }
    }
  }
  return 0;
  while (iVar8 <= iVar5) {
LAB_08139e14:
    iVar8 = iVar8 + 1;
    uVar2 = puVar3[iVar8];
    if (9 < (byte)(uVar2 - 0x30)) break;
  }
  if (iVar7 == iVar8) {
    uVar4 = 0;
  }
  else {
LAB_08139d3f:
    if (uVar2 == 'Z') {
      iVar8 = iVar8 + 1;
    }
    else {
      if ((uVar2 - 0x2b & 0xfd) != 0) {
        return 0;
      }
      if (iVar5 <= iVar8 + 4) {
        return 0;
      }
      if (9 < (byte)(puVar3[iVar8 + 1] - 0x30)) {
        return 0;
      }
      if (9 < (byte)(puVar3[iVar8 + 2] - 0x30)) {
        return 0;
      }
      if (0x3c < (int)(char)puVar3[iVar8 + 2] + ((char)puVar3[iVar8 + 1] + -0x30) * 10) {
        return 0;
      }
      if (9 < (byte)(puVar3[iVar8 + 3] - 0x30)) {
        return 0;
      }
      if (9 < (byte)(puVar3[iVar8 + 4] - 0x30)) {
        return 0;
      }
      if (0x6b < (int)(char)puVar3[iVar8 + 4] + ((char)puVar3[iVar8 + 3] + -0x30) * 10) {
        return 0;
      }
      iVar8 = iVar8 + 5;
    }
    uVar4 = (uint)(iVar5 == iVar8);
  }
  return uVar4;
}

