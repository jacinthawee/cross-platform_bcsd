
int ASN1_GENERALIZEDTIME_check(ASN1_GENERALIZEDTIME *a)

{
  int iVar1;
  uchar uVar2;
  int iVar3;
  uchar *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (a->type != 0x18) {
    return 0;
  }
  iVar3 = a->length;
  if (iVar3 < 0xd) {
    return 0;
  }
  puVar4 = a->data;
  iVar7 = 0;
  uVar2 = *puVar4;
  iVar6 = 0;
  if ((byte)(uVar2 - 0x30) < 10) {
    while( true ) {
      if (9 < (byte)(puVar4[iVar6 + 1] - 0x30)) break;
      iVar1 = (char)puVar4[iVar6 + 1] + -0x30 + ((char)uVar2 + -0x30) * 10;
      iVar8 = iVar6 + 2;
      if (iVar3 < iVar8) {
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
         ((iVar7 == 6 && (((puVar4[iVar8] - 0x2b & 0xfd) == 0 || (puVar4[iVar8] == 'Z')))))) {
        uVar2 = puVar4[iVar8];
        if (uVar2 != '.') goto LAB_08139d3f;
        iVar7 = iVar6 + 3;
        if (iVar3 < iVar7) {
          return 0;
        }
        iVar8 = iVar7;
        if (9 < (byte)(puVar4[iVar6 + 3] - 0x30)) {
          return 0;
        }
        goto LAB_08139e14;
      }
      uVar2 = puVar4[iVar8];
      iVar6 = iVar8;
      if (9 < (byte)(uVar2 - 0x30)) {
        return 0;
      }
    }
  }
  return 0;
  while (iVar8 <= iVar3) {
LAB_08139e14:
    iVar8 = iVar8 + 1;
    uVar2 = puVar4[iVar8];
    if (9 < (byte)(uVar2 - 0x30)) break;
  }
  if (iVar7 == iVar8) {
    uVar5 = 0;
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
      if (iVar3 <= iVar8 + 4) {
        return 0;
      }
      if (9 < (byte)(puVar4[iVar8 + 1] - 0x30)) {
        return 0;
      }
      if (9 < (byte)(puVar4[iVar8 + 2] - 0x30)) {
        return 0;
      }
      if (0x3c < (int)(char)puVar4[iVar8 + 2] + ((char)puVar4[iVar8 + 1] + -0x30) * 10) {
        return 0;
      }
      if (9 < (byte)(puVar4[iVar8 + 3] - 0x30)) {
        return 0;
      }
      if (9 < (byte)(puVar4[iVar8 + 4] - 0x30)) {
        return 0;
      }
      if (0x6b < (int)(char)puVar4[iVar8 + 4] + ((char)puVar4[iVar8 + 3] + -0x30) * 10) {
        return 0;
      }
      iVar8 = iVar8 + 5;
    }
    uVar5 = (uint)(iVar3 == iVar8);
  }
  return uVar5;
}

