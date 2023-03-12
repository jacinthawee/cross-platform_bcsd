
char str2fmt(byte *param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  if (param_1 == (byte *)0x0) {
    return '\0';
  }
  bVar1 = *param_1;
  bVar4 = bVar1 & 0xdf;
  if (bVar4 == 0x44) {
    return '\x01';
  }
  if (bVar4 == 0x54) {
    return '\x02';
  }
  if (bVar4 == 0x4e) {
    return '\x04';
  }
  if (bVar4 == 0x53) {
    return '\x06';
  }
  if (bVar4 == 0x4d) {
    return '\v';
  }
  bVar7 = bVar1 < 0x31;
  bVar8 = bVar1 == 0x31;
  if (bVar8) {
    return '\x05';
  }
  iVar3 = 7;
  pbVar5 = param_1;
  pbVar6 = (byte *)"PKCS12";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pbVar5 < *pbVar6;
    bVar8 = *pbVar5 == *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar8);
  bVar7 = (!bVar7 && !bVar8) == bVar7;
  if (bVar7) {
    return '\x05';
  }
  iVar3 = 7;
  pbVar5 = param_1;
  pbVar6 = (byte *)"pkcs12";
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pbVar5 == *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar7);
  if (bVar7) {
    return '\x05';
  }
  if (bVar1 == 0x50) {
    if (param_1[1] != 0x31) goto LAB_08079c90;
    bVar1 = param_1[2];
  }
  else {
    if ((bVar1 != 0x70) || (param_1[1] != 0x31)) goto LAB_08079c90;
    bVar1 = param_1[2];
  }
  if ((bVar1 == 0x32) && (param_1[3] == 0)) {
    return '\x05';
  }
LAB_08079c90:
  cVar2 = '\a';
  if ((bVar4 != 0x45) && (cVar2 = '\0', bVar4 == 0x50)) {
    cVar2 = ((param_1[1] & 0xdf) == 0x56) * '\t' + '\x03';
  }
  return cVar2;
}

