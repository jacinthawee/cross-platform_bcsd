
int __regparm2 ASN1_UNIVERSALSTRING_to_string(ASN1_UNIVERSALSTRING *s)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  uint *in_stack_00000004;
  char *pcVar4;
  
  iVar2 = 0;
  if ((in_stack_00000004[1] != 0x1c) || (uVar7 = *in_stack_00000004, (uVar7 & 3) != 0)) {
    return iVar2;
  }
  pcVar5 = (char *)in_stack_00000004[2];
  if (0 < (int)uVar7) {
    if (*pcVar5 != '\0') {
      return iVar2;
    }
    if (pcVar5[1] != '\0') {
      return iVar2;
    }
    if (pcVar5[2] != '\0') {
      return iVar2;
    }
    pcVar4 = pcVar5;
    while (pcVar3 = pcVar4 + 4, pcVar5 + (uVar7 - 1 & 0xfffffffc) + 4 != pcVar3) {
      if (((*pcVar3 != '\0') || (pcVar4[5] != '\0')) ||
         (pcVar1 = pcVar4 + 6, pcVar4 = pcVar3, *pcVar1 != '\0')) {
        return 0;
      }
    }
    if (3 < (int)uVar7) {
      uVar7 = 3;
      pcVar3 = pcVar5;
      pcVar4 = pcVar5;
      while( true ) {
        pcVar4 = pcVar4 + uVar7;
        pcVar5 = pcVar3 + 1;
        uVar7 = uVar7 + 4;
        *pcVar3 = *pcVar4;
        if (*in_stack_00000004 == uVar7 || (int)*in_stack_00000004 < (int)uVar7) break;
        pcVar4 = (char *)in_stack_00000004[2];
        pcVar3 = pcVar5;
      }
    }
  }
  *pcVar5 = '\0';
  uVar7 = *in_stack_00000004;
  uVar6 = uVar7 + 3;
  if (-1 < (int)uVar7) {
    uVar6 = uVar7;
  }
  *in_stack_00000004 = (int)uVar6 >> 2;
  uVar7 = ASN1_PRINTABLE_type((uchar *)in_stack_00000004[2],(int)uVar6 >> 2);
  in_stack_00000004[1] = uVar7;
  return 1;
}

