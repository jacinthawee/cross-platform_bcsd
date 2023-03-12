
int ASN1_UTCTIME_set_string(ASN1_UTCTIME *s,char *str)

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
  
  iVar3 = (*(code *)PTR_strlen_006a9a24)(str);
  if (iVar3 < 0xb) {
    return 0;
  }
  cVar1 = *str;
  puVar8 = max_7042;
  puVar7 = min_7041;
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
    if (iVar6 == 6) break;
    if (iVar6 == 5) {
      cVar1 = pcVar5[2];
      if (cVar1 == 'Z') goto LAB_0054961c;
      if ((cVar1 == '+') || (cVar1 == '-')) goto LAB_00549560;
    }
    pcVar5 = pcVar5 + 2;
    cVar1 = *pcVar5;
    puVar8 = (undefined1 *)((int)puVar8 + 4);
    puVar7 = (undefined1 *)((int)puVar7 + 4);
    iVar2 = iVar9;
  }
  cVar1 = str[iVar9];
  if (cVar1 != 'Z') {
    if ((cVar1 != '+') && (cVar1 != '-')) goto LAB_005494f8;
LAB_00549560:
    if (iVar3 <= iVar2 + 6) {
      return 0;
    }
    if (9 < ((int)str[iVar2 + 3] - 0x30U & 0xff)) {
      return 0;
    }
    if (9 < ((int)str[iVar2 + 4] - 0x30U & 0xff)) {
      return 0;
    }
    if (0x3c < (int)(((int)str[iVar2 + 3] - 0x30U) * 10 + (int)str[iVar2 + 4])) {
      return 0;
    }
    if (9 < ((int)str[iVar2 + 5] - 0x30U & 0xff)) {
      return 0;
    }
    if (9 < ((int)str[iVar2 + 6] - 0x30U & 0xff)) {
      return 0;
    }
    if (0x6b < (int)(((int)str[iVar2 + 5] - 0x30U) * 10 + (int)str[iVar2 + 6])) {
      return 0;
    }
    iVar9 = iVar2 + 7;
    goto LAB_005494f8;
  }
LAB_0054961c:
  iVar9 = iVar2 + 3;
LAB_005494f8:
  if (iVar3 == iVar9) {
    if (s == (ASN1_UTCTIME *)0x0) {
      return 1;
    }
    iVar3 = ASN1_STRING_set(s,str,iVar3);
    if (iVar3 != 0) {
      s->type = 0x17;
      return 1;
    }
  }
  return 0;
}

