
int ASN1_GENERALIZEDTIME_set_string(ASN1_GENERALIZEDTIME *s,char *str)

{
  char cVar1;
  size_t len;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  size_t sVar7;
  int *piVar8;
  char *pcVar9;
  int *piVar10;
  
  len = strlen(str);
  if ((int)len < 0xd) {
    return 0;
  }
  iVar4 = 0;
  piVar10 = DAT_000b3954 + 9;
  iVar3 = 0;
  piVar8 = DAT_000b3954;
  pcVar9 = str;
  while( true ) {
    if (9 < ((byte)str[iVar3] - 0x30 & 0xff)) {
      return 0;
    }
    if (9 < (byte)pcVar9[1] - 0x30) {
      return 0;
    }
    iVar6 = iVar3 + 2;
    iVar2 = (uint)(byte)pcVar9[1] + ((byte)str[iVar3] - 0x30) * 10 + -0x30;
    if ((int)len < iVar6) {
      return 0;
    }
    piVar10 = piVar10 + 1;
    if (iVar2 < *piVar10) {
      return 0;
    }
    piVar8 = piVar8 + 1;
    if (*piVar8 < iVar2) {
      return 0;
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 7) break;
    if (iVar4 == 6) {
      cVar1 = pcVar9[2];
      if ((cVar1 == '+') || (cVar1 == 'Z')) break;
      if (cVar1 == '-') goto LAB_000b38b6;
    }
    pcVar9 = pcVar9 + 2;
    iVar3 = iVar6;
  }
  uVar5 = (uint)(byte)str[iVar6];
  if (uVar5 == 0x2e) {
    iVar3 = iVar3 + 3;
    if ((int)len < iVar3) {
      return 0;
    }
    iVar6 = iVar3;
    if (9 < (byte)str[iVar3] - 0x30) {
      return 0;
    }
    do {
      iVar6 = iVar6 + 1;
      uVar5 = (uint)(byte)str[iVar6];
      if (9 < uVar5 - 0x30) break;
    } while (iVar6 <= (int)len);
    if (iVar3 == iVar6) {
      return 0;
    }
  }
  if (uVar5 == 0x5a) {
    sVar7 = iVar6 + 1;
  }
  else {
    if (uVar5 != 0x2b && uVar5 != 0x2d) {
      return 0;
    }
LAB_000b38b6:
    if ((int)len <= iVar6 + 4) {
      return 0;
    }
    if (9 < ((byte)str[iVar6 + 1] - 0x30 & 0xff)) {
      return 0;
    }
    if (9 < (byte)str[iVar6 + 2] - 0x30) {
      return 0;
    }
    if (0x3c < (int)((uint)(byte)str[iVar6 + 2] + ((byte)str[iVar6 + 1] - 0x30) * 10)) {
      return 0;
    }
    if (9 < ((byte)str[iVar6 + 3] - 0x30 & 0xff)) {
      return 0;
    }
    if (9 < (byte)str[iVar6 + 4] - 0x30) {
      return 0;
    }
    iVar3 = (uint)(byte)str[iVar6 + 4] + ((byte)str[iVar6 + 3] - 0x30) * 10 + -0x30;
    if (iVar3 < 0) {
      return 0;
    }
    if (0x3b < iVar3) {
      return 0;
    }
    sVar7 = iVar6 + 5;
  }
  if (len == sVar7) {
    if (s == (ASN1_GENERALIZEDTIME *)0x0) {
      return 1;
    }
    iVar3 = ASN1_STRING_set(s,str,len);
    if (iVar3 != 0) {
      s->type = 0x18;
      return 1;
    }
  }
  return 0;
}

