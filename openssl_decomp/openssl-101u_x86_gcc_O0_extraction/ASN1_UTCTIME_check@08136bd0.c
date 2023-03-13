
int ASN1_UTCTIME_check(ASN1_UTCTIME *a)

{
  int iVar1;
  uchar uVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((a->type == 0x17) && (iVar3 = a->length, 10 < iVar3)) {
    puVar4 = a->data;
    iVar7 = 0;
    uVar2 = *puVar4;
    iVar6 = 0;
    if ((byte)(uVar2 - 0x30) < 10) {
      while( true ) {
        if (9 < (byte)(puVar4[iVar6 + 1] - 0x30)) break;
        iVar1 = (char)puVar4[iVar6 + 1] + -0x30 + ((char)uVar2 + -0x30) * 10;
        iVar5 = iVar6 + 2;
        if (iVar3 < iVar5) {
          return 0;
        }
        if (iVar1 < *(int *)(min_7021 + iVar7 * 4)) {
          return 0;
        }
        if (*(int *)(max_7022 + iVar7 * 4) < iVar1) {
          return 0;
        }
        iVar7 = iVar7 + 1;
        if ((iVar7 == 6) ||
           ((iVar7 == 5 && (((puVar4[iVar5] - 0x2b & 0xfd) == 0 || (puVar4[iVar5] == 'Z')))))) {
          if (puVar4[iVar5] == 'Z') {
            iVar5 = iVar6 + 3;
          }
          else if ((puVar4[iVar5] - 0x2b & 0xfd) == 0) {
            if (iVar3 <= iVar6 + 6) {
              return 0;
            }
            if (9 < (byte)(puVar4[iVar6 + 3] - 0x30)) {
              return 0;
            }
            if (9 < (byte)(puVar4[iVar6 + 4] - 0x30)) {
              return 0;
            }
            if (0x3c < (int)(char)puVar4[iVar6 + 4] + ((char)puVar4[iVar6 + 3] + -0x30) * 10) {
              return 0;
            }
            if (9 < (byte)(puVar4[iVar6 + 5] - 0x30)) {
              return 0;
            }
            if (9 < (byte)(puVar4[iVar6 + 6] - 0x30)) {
              return 0;
            }
            if (0x6b < (int)(char)puVar4[iVar6 + 6] + ((char)puVar4[iVar6 + 5] + -0x30) * 10) {
              return 0;
            }
            iVar5 = iVar6 + 7;
          }
          return (uint)(iVar3 == iVar5);
        }
        uVar2 = puVar4[iVar5];
        iVar6 = iVar5;
        if (9 < (byte)(uVar2 - 0x30)) {
          return 0;
        }
      }
    }
  }
  return 0;
}

