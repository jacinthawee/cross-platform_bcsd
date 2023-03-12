
int i2c_ASN1_INTEGER(ASN1_INTEGER *a,uchar **pp)

{
  int iVar1;
  uchar *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte bVar9;
  byte *pbVar6;
  uchar *puVar8;
  byte *pbVar10;
  byte *pbVar7;
  
  if (a == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  pbVar5 = (byte *)a->length;
  if (pbVar5 == (byte *)0x0) {
    if (pp == (uchar **)0x0) {
      return 1;
    }
    puVar2 = *pp;
    pbVar10 = (byte *)0x1;
LAB_0054df9c:
    *puVar2 = '\0';
  }
  else {
    pbVar4 = a->data;
    bVar9 = *pbVar4;
    if ((a->type & 0x100U) == 0) {
      pbVar10 = pbVar5 + (bVar9 < 0x80 ^ 1);
      if (pp == (uchar **)0x0) {
        return (int)pbVar10;
      }
      puVar8 = *pp;
      puVar2 = puVar8;
      if (bVar9 < 0x80 == 0) {
        *puVar8 = '\0';
        pbVar5 = (byte *)a->length;
        puVar2 = puVar8 + 1;
        if (pbVar5 == (byte *)0x0) goto LAB_0054df9c;
        pbVar4 = a->data;
      }
      (*(code *)PTR_memcpy_006aabf4)(puVar2,pbVar4,pbVar5,puVar8,&_gp);
      goto LAB_0054dfa0;
    }
    if (bVar9 < 0x81) {
      if ((bVar9 == 0x80) && (1 < (int)pbVar5)) {
        if (pbVar4[1] == 0) {
          pbVar10 = pbVar4 + 2;
          do {
            if (pbVar10 == pbVar4 + (int)pbVar5) goto LAB_0054e0bc;
            bVar9 = *pbVar10;
            pbVar10 = pbVar10 + 1;
          } while (bVar9 == 0);
        }
        goto LAB_0054dfe4;
      }
LAB_0054e0bc:
      if (pp == (uchar **)0x0) {
        return (int)pbVar5;
      }
      puVar2 = *pp;
      pbVar10 = pbVar5;
    }
    else {
LAB_0054dfe4:
      pbVar10 = pbVar5 + 1;
      if (pp == (uchar **)0x0) {
        return (int)pbVar10;
      }
      puVar2 = *pp;
      *puVar2 = 0xff;
      pbVar5 = (byte *)a->length;
      puVar2 = puVar2 + 1;
      if (pbVar5 == (byte *)0x0) goto LAB_0054df9c;
      pbVar4 = a->data;
    }
    pbVar4 = pbVar4 + (int)(pbVar5 + -1);
    bVar9 = *pbVar4;
    pbVar3 = puVar2 + (int)(pbVar5 + -1);
    if (bVar9 == 0) {
      iVar1 = (int)pbVar5 - (int)pbVar4;
      do {
        pbVar4 = pbVar4 + -1;
        *pbVar3 = 0;
        pbVar3 = pbVar3 + -1;
        bVar9 = *pbVar4;
        pbVar5 = pbVar4 + iVar1;
      } while (bVar9 == 0);
    }
    *pbVar3 = -bVar9;
    pbVar7 = pbVar4 + -1;
    if (1 < (int)pbVar5) {
      do {
        pbVar3 = pbVar3 + -1;
        pbVar6 = pbVar7 + -1;
        *pbVar3 = ~*pbVar7;
        pbVar7 = pbVar6;
      } while (pbVar6 != pbVar4 + -(int)pbVar5);
    }
  }
LAB_0054dfa0:
  *pp = *pp + (int)pbVar10;
  return (int)pbVar10;
}

