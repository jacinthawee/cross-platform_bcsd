
int ASN1_UNIVERSALSTRING_to_string(ASN1_UNIVERSALSTRING *s)

{
  uchar *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if ((s->type != 0x1c) || (uVar6 = s->length, (uVar6 & 3) != 0)) {
    return 0;
  }
  puVar1 = s->data;
  if (0 < (int)uVar6) {
    if (*puVar1 != '\0') {
      return 0;
    }
    if (puVar1[1] != '\0') {
      return 0;
    }
    uVar4 = (uint)puVar1[2];
    puVar3 = puVar1;
    if (uVar4 != 0) {
      return 0;
    }
    while( true ) {
      uVar4 = uVar4 + 4;
      if ((int)uVar6 <= (int)uVar4) break;
      if (puVar1[uVar4] != '\0') {
        return 0;
      }
      if (puVar3[5] != '\0') {
        return 0;
      }
      puVar2 = puVar3 + 6;
      puVar3 = puVar3 + 4;
      if (*puVar2 != '\0') {
        return 0;
      }
    }
    if (3 < (int)uVar6) {
      iVar5 = 3;
      puVar2 = puVar1;
      puVar3 = puVar1;
      while( true ) {
        puVar3 = puVar3 + iVar5;
        iVar5 = iVar5 + 4;
        puVar1 = puVar2 + 1;
        *puVar2 = *puVar3;
        if (s->length <= iVar5) break;
        puVar3 = s->data;
        puVar2 = puVar1;
      }
    }
  }
  *puVar1 = '\0';
  uVar4 = s->length;
  uVar6 = uVar4 & ~((int)uVar4 >> 0x20);
  if ((int)uVar4 < 0) {
    uVar6 = uVar4 + 3;
  }
  s->length = (int)uVar6 >> 2;
  iVar5 = ASN1_PRINTABLE_type(s->data,(int)uVar6 >> 2);
  s->type = iVar5;
  return 1;
}

