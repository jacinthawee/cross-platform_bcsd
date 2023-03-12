
int ASN1_GENERALIZEDTIME_set_string(ASN1_GENERALIZEDTIME *s,char *str)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  int iVar9;
  
  iVar3 = (*(code *)PTR_strlen_006aab30)(str);
  if (iVar3 < 0xd) {
    return 0;
  }
  cVar1 = *str;
  puVar8 = max_7035;
  puVar7 = min_7034;
  iVar6 = 0;
  iVar2 = 0;
  pcVar5 = str;
  while( true ) {
    if (9 < ((int)cVar1 - 0x30U & 0xff)) {
      return 0;
    }
    if (9 < ((int)pcVar5[1] - 0x30U & 0xff)) {
      return 0;
    }
    iVar9 = iVar2 + 2;
    iVar4 = ((int)cVar1 - 0x30U) * 10 + (int)pcVar5[1] + -0x30;
    if (iVar3 < iVar9) {
      return 0;
    }
    if (iVar4 < *(int *)puVar7) {
      return 0;
    }
    if (*(int *)puVar8 < iVar4) {
      return 0;
    }
    iVar6 = iVar6 + 1;
    if (iVar6 == 7) break;
    if (iVar6 == 6) {
      cVar1 = pcVar5[2];
      if (cVar1 == 'Z') goto LAB_0054d5c8;
      if ((cVar1 == '+') || (cVar1 == '-')) goto LAB_0054d464;
    }
    pcVar5 = pcVar5 + 2;
    cVar1 = *pcVar5;
    puVar8 = (undefined1 *)((int)puVar8 + 4);
    puVar7 = (undefined1 *)((int)puVar7 + 4);
    iVar2 = iVar9;
  }
  iVar6 = (int)str[iVar9];
  iVar4 = iVar2 + 3;
  if (iVar6 == 0x2e) {
    if (iVar3 < iVar4) {
      return 0;
    }
    if (9 < (byte)(str[iVar4] - 0x30U)) {
      return 0;
    }
    pcVar5 = str + iVar2;
    iVar9 = iVar4;
    do {
      iVar6 = (int)pcVar5[4];
      iVar9 = iVar9 + 1;
      pcVar5 = pcVar5 + 1;
      if (9 < (iVar6 - 0x30U & 0xff)) break;
    } while (iVar9 <= iVar3);
    if (iVar4 == iVar9) {
      return 0;
    }
  }
  if (iVar6 == 0x5a) {
LAB_0054d5c8:
    iVar9 = iVar9 + 1;
  }
  else {
    if ((iVar6 != 0x2b) && (iVar6 != 0x2d)) {
      return 0;
    }
LAB_0054d464:
    if (iVar3 <= iVar9 + 4) {
      return 0;
    }
    if (9 < ((int)str[iVar9 + 1] - 0x30U & 0xff)) {
      return 0;
    }
    if (9 < ((int)str[iVar9 + 2] - 0x30U & 0xff)) {
      return 0;
    }
    if (0x3c < (int)(((int)str[iVar9 + 1] - 0x30U) * 10 + (int)str[iVar9 + 2])) {
      return 0;
    }
    if (9 < ((int)str[iVar9 + 3] - 0x30U & 0xff)) {
      return 0;
    }
    if (9 < ((int)str[iVar9 + 4] - 0x30U & 0xff)) {
      return 0;
    }
    if (0x6b < (int)(((int)str[iVar9 + 3] - 0x30U) * 10 + (int)str[iVar9 + 4])) {
      return 0;
    }
    iVar9 = iVar9 + 5;
  }
  if (iVar3 == iVar9) {
    if (s == (ASN1_GENERALIZEDTIME *)0x0) {
      return 1;
    }
    iVar3 = ASN1_STRING_set(s,str,iVar3);
    if (iVar3 != 0) {
      s->type = 0x18;
      return 1;
    }
  }
  return 0;
}

