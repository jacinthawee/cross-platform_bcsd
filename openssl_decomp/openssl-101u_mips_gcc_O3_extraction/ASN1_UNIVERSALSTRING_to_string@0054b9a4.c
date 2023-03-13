
int ASN1_UNIVERSALSTRING_to_string(ASN1_UNIVERSALSTRING *s)

{
  uchar uVar1;
  uchar *puVar2;
  uchar *puVar3;
  int iVar4;
  uchar *puVar5;
  uint uVar6;
  
  if ((s->type == 0x1c) && (uVar6 = s->length, (uVar6 & 3) == 0)) {
    puVar5 = s->data;
    if ((int)uVar6 < 1) {
LAB_0054ba84:
      *puVar5 = '\0';
      iVar4 = s->length;
      if (iVar4 < 0) {
        iVar4 = iVar4 + 3;
      }
      s->length = iVar4 >> 2;
      iVar4 = ASN1_PRINTABLE_type(s->data,iVar4 >> 2);
      s->type = iVar4;
      return 1;
    }
    if ((*puVar5 == '\0') && (puVar5[1] == '\0')) {
      uVar1 = puVar5[2];
      puVar3 = puVar5;
      while (uVar1 == '\0') {
        puVar2 = puVar3 + 4;
        if ((int)uVar6 <= (int)puVar2 - (int)puVar5) {
          if (3 < (int)uVar6) {
            iVar4 = 3;
            puVar3 = puVar5;
            puVar2 = puVar5;
            while( true ) {
              puVar2 = puVar2 + iVar4;
              puVar5 = puVar3 + 1;
              iVar4 = iVar4 + 4;
              *puVar3 = *puVar2;
              if (s->length <= iVar4) break;
              puVar2 = s->data;
              puVar3 = puVar5;
            }
          }
          goto LAB_0054ba84;
        }
        if (*puVar2 != '\0') {
          return 0;
        }
        if (puVar3[5] != '\0') {
          return 0;
        }
        uVar1 = puVar3[6];
        puVar3 = puVar2;
      }
    }
  }
  return 0;
}

