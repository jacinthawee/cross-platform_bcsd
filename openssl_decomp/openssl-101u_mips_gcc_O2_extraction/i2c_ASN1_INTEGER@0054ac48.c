
int i2c_ASN1_INTEGER(ASN1_INTEGER *a,uchar **pp)

{
  bool bVar1;
  uchar *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  byte bVar9;
  int iVar10;
  
  if (a == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  iVar6 = a->length;
  if (iVar6 == 0) {
    if (pp == (uchar **)0x0) {
      return 1;
    }
    puVar2 = *pp;
    iVar10 = 1;
LAB_0054ad60:
    *puVar2 = '\0';
  }
  else {
    pbVar5 = a->data;
    bVar9 = *pbVar5;
    if (((iVar6 == 1) && (bVar9 == 0)) || ((a->type & 0x100U) == 0)) {
      iVar10 = (bVar9 < 0x80 ^ 1) + iVar6;
      if (pp == (uchar **)0x0) {
        return iVar10;
      }
      puVar2 = *pp;
      if (bVar9 < 0x80 == 0) {
        *puVar2 = '\0';
        iVar6 = a->length;
        puVar2 = puVar2 + 1;
        if (iVar6 == 0) goto LAB_0054ad60;
        pbVar5 = a->data;
      }
      (*(code *)PTR_memcpy_006a9aec)(puVar2,pbVar5,iVar6,a,&_gp);
      goto LAB_0054ad64;
    }
    if (bVar9 < 0x81) {
      if ((bVar9 == 0x80) && (1 < iVar6)) {
        if (pbVar5[1] == 0) {
          pbVar3 = pbVar5 + 2;
          do {
            if (pbVar3 == pbVar5 + iVar6) goto LAB_0054add8;
            bVar9 = *pbVar3;
            pbVar3 = pbVar3 + 1;
          } while (bVar9 == 0);
        }
        goto LAB_0054aca4;
      }
LAB_0054add8:
      if (pp == (uchar **)0x0) {
        return iVar6;
      }
      puVar2 = *pp;
      iVar10 = iVar6;
    }
    else {
LAB_0054aca4:
      iVar10 = iVar6 + 1;
      if (pp == (uchar **)0x0) {
        return iVar10;
      }
      puVar2 = *pp;
      *puVar2 = 0xff;
      iVar6 = a->length;
      puVar2 = puVar2 + 1;
      if (iVar6 == 0) goto LAB_0054ad60;
      pbVar5 = a->data;
    }
    iVar7 = iVar6 + -1;
    pbVar5 = pbVar5 + iVar7;
    bVar9 = *pbVar5;
    pbVar3 = puVar2 + iVar7;
    if (bVar9 == 0) {
      bVar1 = iVar6 < 2;
      pbVar4 = pbVar3;
      if (!bVar1) {
        do {
          iVar6 = iVar7;
          pbVar3 = pbVar4 + -1;
          *pbVar4 = 0;
          pbVar5 = pbVar5 + -1;
          bVar9 = *pbVar5;
          if (bVar9 != 0) goto LAB_0054ad10;
          pbVar4 = pbVar3;
          iVar7 = iVar6 + -1;
        } while (iVar6 != 1);
        *pbVar3 = 0;
        goto LAB_0054ad64;
      }
    }
    else {
LAB_0054ad10:
      bVar9 = -bVar9;
      bVar1 = iVar6 < 2;
    }
    *pbVar3 = bVar9;
    pbVar4 = pbVar3 + -1;
    if (!bVar1) {
      do {
        pbVar5 = pbVar5 + -1;
        pbVar8 = pbVar4 + -1;
        *pbVar4 = ~*pbVar5;
        pbVar4 = pbVar8;
      } while (pbVar8 != pbVar3 + -iVar6);
    }
  }
LAB_0054ad64:
  *pp = *pp + iVar10;
  return iVar10;
}

