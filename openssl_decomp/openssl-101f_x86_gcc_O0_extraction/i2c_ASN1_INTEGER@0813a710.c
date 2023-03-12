
int i2c_ASN1_INTEGER(ASN1_INTEGER *a,uchar **pp)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  uchar *puVar6;
  uchar *puVar7;
  uint uVar8;
  byte *pbVar9;
  uchar local_1d;
  
  if (a == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  pbVar9 = (byte *)a->length;
  if (pbVar9 == (byte *)0x0) {
    if (pp == (uchar **)0x0) {
      return 1;
    }
    puVar6 = *pp;
    pbVar9 = (byte *)0x1;
LAB_0813a7f4:
    *puVar6 = '\0';
  }
  else {
    pbVar4 = a->data;
    uVar2 = a->type & 0x100;
    uVar8 = (uint)*pbVar4;
    if ((uVar2 == 0) && (local_1d = '\0', 0x7f < uVar8)) {
LAB_0813a753:
      pbVar9 = pbVar9 + 1;
      if (pp == (uchar **)0x0) {
        return (int)pbVar9;
      }
      puVar6 = *pp + 1;
      **pp = local_1d;
      pbVar3 = (byte *)a->length;
      if (pbVar3 == (byte *)0x0) goto LAB_0813a7f4;
      pbVar4 = a->data;
    }
    else {
      if (uVar2 != 0) {
        if (uVar8 == 0x80 || SCARRY4(uVar8,-0x80) != (int)(uVar8 - 0x80) < 0) {
          if ((uVar8 != 0x80) || ((int)pbVar9 < 2)) goto LAB_0813a813;
          bVar1 = pbVar4[1];
          pbVar3 = pbVar4 + 2;
          while (bVar1 == 0) {
            if (pbVar3 == pbVar4 + (int)pbVar9) goto LAB_0813a813;
            bVar1 = *pbVar3;
            pbVar3 = pbVar3 + 1;
          }
        }
        local_1d = 0xff;
        goto LAB_0813a753;
      }
LAB_0813a813:
      if (pp == (uchar **)0x0) {
        return (int)pbVar9;
      }
      puVar6 = *pp;
      pbVar3 = pbVar9;
    }
    if (uVar2 == 0) {
      memcpy(puVar6,pbVar4,(size_t)pbVar3);
    }
    else {
      pbVar4 = pbVar4 + (int)(pbVar3 + -1);
      puVar6 = puVar6 + (int)(pbVar3 + -1);
      bVar1 = *pbVar4;
      if (bVar1 == 0) {
        iVar5 = (int)pbVar3 - (int)pbVar4;
        puVar7 = puVar6;
        do {
          pbVar4 = pbVar4 + -1;
          puVar6 = puVar7 + -1;
          *puVar7 = '\0';
          bVar1 = *pbVar4;
          pbVar3 = pbVar4 + iVar5;
          puVar7 = puVar6;
        } while (bVar1 == 0);
      }
      *puVar6 = -bVar1;
      iVar5 = 0;
      if (1 < (int)pbVar3) {
        do {
          puVar6[iVar5 + -1] = ~pbVar4[iVar5 + -1];
          iVar5 = iVar5 + -1;
        } while (iVar5 != 1 - (int)pbVar3);
      }
    }
  }
  *pp = *pp + (int)pbVar9;
  return (int)pbVar9;
}

