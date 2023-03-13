
int ASN1_GENERALIZEDTIME_set_string(ASN1_GENERALIZEDTIME *s,char *str)

{
  int iVar1;
  char cVar2;
  size_t len;
  int iVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  char *pcVar7;
  
  len = strlen(str);
  if ((int)len < 0xd) {
    return 0;
  }
  iVar4 = 0;
  cVar2 = *str;
  pcVar7 = str;
  iVar3 = 0;
  if (9 < (byte)(cVar2 - 0x30U)) {
    return 0;
  }
  while( true ) {
    if (9 < (byte)(pcVar7[1] - 0x30U)) {
      return 0;
    }
    iVar1 = pcVar7[1] + -0x30 + (cVar2 + -0x30) * 10;
    iVar6 = iVar3 + 2;
    if ((int)len < iVar6) {
      return 0;
    }
    if (iVar1 < *(int *)(min_7021 + iVar4 * 4)) {
      return 0;
    }
    if (*(int *)(max_7022 + iVar4 * 4) < iVar1) {
      return 0;
    }
    iVar4 = iVar4 + 1;
    if ((iVar4 == 7) || ((iVar4 == 6 && (((pcVar7[2] - 0x2bU & 0xfd) == 0 || (pcVar7[2] == 'Z'))))))
    break;
    pcVar7 = pcVar7 + 2;
    cVar2 = *pcVar7;
    iVar3 = iVar6;
    if (9 < (byte)(cVar2 - 0x30U)) {
      return 0;
    }
  }
  cVar2 = str[iVar6];
  if (cVar2 == '.') {
    iVar4 = iVar3 + 3;
    if ((int)len < iVar4) {
      return 0;
    }
    iVar6 = iVar4;
    if (9 < (byte)(str[iVar3 + 3] - 0x30U)) {
      return 0;
    }
    do {
      iVar6 = iVar6 + 1;
      cVar2 = str[iVar6];
      if (9 < (byte)(cVar2 - 0x30U)) break;
    } while (iVar6 <= (int)len);
    if (iVar4 == iVar6) {
      return 0;
    }
  }
  if (cVar2 == 'Z') {
    sVar5 = iVar6 + 1;
  }
  else {
    if ((cVar2 - 0x2bU & 0xfd) != 0) {
      return 0;
    }
    if ((int)len <= iVar6 + 4) {
      return 0;
    }
    if (9 < (byte)(str[iVar6 + 1] - 0x30U)) {
      return 0;
    }
    if (9 < (byte)(str[iVar6 + 2] - 0x30U)) {
      return 0;
    }
    if (0x3c < (int)str[iVar6 + 2] + (str[iVar6 + 1] + -0x30) * 10) {
      return 0;
    }
    if (9 < (byte)(str[iVar6 + 3] - 0x30U)) {
      return 0;
    }
    if (9 < (byte)(str[iVar6 + 4] - 0x30U)) {
      return 0;
    }
    if (0x6b < (int)str[iVar6 + 4] + (str[iVar6 + 3] + -0x30) * 10) {
      return 0;
    }
    sVar5 = iVar6 + 5;
  }
  if (len == sVar5) {
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

