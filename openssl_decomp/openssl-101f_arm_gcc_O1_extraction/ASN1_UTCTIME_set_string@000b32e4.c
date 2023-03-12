
int ASN1_UTCTIME_set_string(ASN1_UTCTIME *s,char *str)

{
  char cVar1;
  size_t len;
  int *piVar2;
  int iVar3;
  size_t sVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  size_t sVar8;
  
  len = strlen(str);
  if (10 < (int)len) {
    iVar3 = 0;
    piVar2 = DAT_000b33f8 + 8;
    sVar4 = 0;
    piVar5 = DAT_000b33f8;
    pcVar7 = str;
    while( true ) {
      if (9 < ((byte)str[sVar4] - 0x30 & 0xff)) {
        return 0;
      }
      if (9 < (byte)pcVar7[1] - 0x30) {
        return 0;
      }
      sVar8 = sVar4 + 2;
      iVar6 = (uint)(byte)pcVar7[1] + ((byte)str[sVar4] - 0x30) * 10 + -0x30;
      if ((int)len < (int)sVar8) {
        return 0;
      }
      piVar2 = piVar2 + 1;
      if (iVar6 < *piVar2) {
        return 0;
      }
      piVar5 = piVar5 + 1;
      if (*piVar5 < iVar6) {
        return 0;
      }
      iVar3 = iVar3 + 1;
      if (iVar3 == 6) break;
      if (iVar3 == 5) {
        cVar1 = pcVar7[2];
        if ((cVar1 == '+') || (cVar1 == 'Z')) break;
        if (cVar1 != '-') goto LAB_000b334a;
LAB_000b3368:
        if ((int)len <= (int)(sVar4 + 6)) {
          return 0;
        }
        if (9 < ((byte)str[sVar4 + 3] - 0x30 & 0xff)) {
          return 0;
        }
        if (9 < (byte)str[sVar4 + 4] - 0x30) {
          return 0;
        }
        if (0x3c < (int)((uint)(byte)str[sVar4 + 4] + ((byte)str[sVar4 + 3] - 0x30) * 10)) {
          return 0;
        }
        if (9 < ((byte)str[sVar4 + 5] - 0x30 & 0xff)) {
          return 0;
        }
        if (9 < (byte)str[sVar4 + 6] - 0x30) {
          return 0;
        }
        iVar3 = (uint)(byte)str[sVar4 + 6] + ((byte)str[sVar4 + 5] - 0x30) * 10 + -0x30;
        if (iVar3 < 0) {
          return 0;
        }
        if (0x3b < iVar3) {
          return 0;
        }
        sVar8 = sVar4 + 7;
        goto LAB_000b33b8;
      }
LAB_000b334a:
      pcVar7 = pcVar7 + 2;
      sVar4 = sVar8;
    }
    cVar1 = str[sVar8];
    if (cVar1 == 'Z') {
      sVar8 = sVar4 + 3;
    }
    else if (cVar1 == '+' || cVar1 == '-') goto LAB_000b3368;
LAB_000b33b8:
    if (len == sVar8) {
      if (s == (ASN1_UTCTIME *)0x0) {
        return 1;
      }
      iVar3 = ASN1_STRING_set(s,str,len);
      if (iVar3 != 0) {
        s->type = 0x17;
        return 1;
      }
    }
  }
  return 0;
}

