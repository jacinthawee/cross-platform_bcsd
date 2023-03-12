
int ASN1_UTCTIME_set_string(ASN1_UTCTIME *s,char *str)

{
  int iVar1;
  char cVar2;
  size_t len;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  size_t sVar6;
  
  len = strlen(str);
  if (10 < (int)len) {
    iVar3 = 0;
    cVar2 = *str;
    pcVar5 = str;
    sVar6 = 0;
    if ((byte)(cVar2 - 0x30U) < 10) {
      while( true ) {
        if (9 < (byte)(pcVar5[1] - 0x30U)) break;
        iVar1 = pcVar5[1] + -0x30 + (cVar2 + -0x30) * 10;
        sVar4 = sVar6 + 2;
        if ((int)len < (int)sVar4) {
          return 0;
        }
        if (iVar1 < *(int *)(min_7014 + iVar3 * 4)) {
          return 0;
        }
        if (*(int *)(max_7015 + iVar3 * 4) < iVar1) {
          return 0;
        }
        iVar3 = iVar3 + 1;
        if ((iVar3 == 6) ||
           ((iVar3 == 5 && (((pcVar5[2] - 0x2bU & 0xfd) == 0 || (pcVar5[2] == 'Z')))))) {
          if (str[sVar4] == 'Z') {
            sVar4 = sVar6 + 3;
          }
          else if ((str[sVar4] - 0x2bU & 0xfd) == 0) {
            if ((int)len <= (int)(sVar6 + 6)) {
              return 0;
            }
            if (9 < (byte)(str[sVar6 + 3] - 0x30U)) {
              return 0;
            }
            if (9 < (byte)(str[sVar6 + 4] - 0x30U)) {
              return 0;
            }
            if (0x3c < (int)str[sVar6 + 4] + (str[sVar6 + 3] + -0x30) * 10) {
              return 0;
            }
            if (9 < (byte)(str[sVar6 + 5] - 0x30U)) {
              return 0;
            }
            if (9 < (byte)(str[sVar6 + 6] - 0x30U)) {
              return 0;
            }
            if (0x6b < (int)str[sVar6 + 6] + (str[sVar6 + 5] + -0x30) * 10) {
              return 0;
            }
            sVar4 = sVar6 + 7;
          }
          if (len != sVar4) {
            return 0;
          }
          if (s != (ASN1_UTCTIME *)0x0) {
            iVar3 = ASN1_STRING_set(s,str,len);
            if (iVar3 == 0) {
              return 0;
            }
            s->type = 0x17;
            return 1;
          }
          return 1;
        }
        pcVar5 = pcVar5 + 2;
        cVar2 = *pcVar5;
        sVar6 = sVar4;
        if (9 < (byte)(cVar2 - 0x30U)) {
          return 0;
        }
      }
    }
  }
  return 0;
}

