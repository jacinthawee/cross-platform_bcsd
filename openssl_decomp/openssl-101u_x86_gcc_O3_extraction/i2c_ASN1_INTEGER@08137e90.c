
int i2c_ASN1_INTEGER(ASN1_INTEGER *a,uchar **pp)

{
  byte bVar1;
  uchar *__dest;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  size_t sVar5;
  int iVar6;
  uchar uVar7;
  byte *pbVar8;
  uint uVar9;
  size_t sVar10;
  size_t local_20;
  
  if (a == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  sVar10 = a->length;
  if (sVar10 == 0) {
    if (pp == (uchar **)0x0) {
      return 1;
    }
    __dest = *pp;
    sVar10 = 1;
LAB_08137ec5:
    *__dest = '\0';
    goto LAB_08137ec8;
  }
  pbVar8 = a->data;
  uVar2 = (uint)*pbVar8;
  if ((sVar10 == 1) && (uVar9 = 0, uVar2 == 0)) {
LAB_08137ee9:
    if (pp == (uchar **)0x0) {
      return sVar10;
    }
    __dest = *pp;
    local_20 = sVar10;
  }
  else {
    uVar9 = a->type & 0x100;
    if ((uVar9 == 0) && (0x7f < uVar2)) {
      uVar9 = 0;
      uVar7 = '\0';
    }
    else {
      if (uVar9 == 0) goto LAB_08137ee9;
      if (uVar2 == 0x80 || SCARRY4(uVar2,-0x80) != (int)(uVar2 - 0x80) < 0) {
        if ((uVar2 != 0x80) || ((int)sVar10 < 2)) goto LAB_08137ee9;
        if (pbVar8[1] == 0) {
          pbVar3 = pbVar8 + 2;
          do {
            if (pbVar3 == pbVar8 + sVar10) goto LAB_08137ee9;
            bVar1 = *pbVar3;
            pbVar3 = pbVar3 + 1;
          } while (bVar1 == 0);
        }
      }
      uVar7 = 0xff;
    }
    sVar10 = sVar10 + 1;
    if (pp == (uchar **)0x0) {
      return sVar10;
    }
    __dest = *pp + 1;
    **pp = uVar7;
    if (a->length == 0) goto LAB_08137ec5;
    pbVar8 = a->data;
    local_20 = a->length;
  }
  if (uVar9 == 0) {
    memcpy(__dest,pbVar8,local_20);
    goto LAB_08137ec8;
  }
  sVar5 = local_20 - 1;
  pbVar8 = pbVar8 + sVar5;
  pbVar3 = __dest + sVar5;
  bVar1 = *pbVar8;
  if (bVar1 == 0) {
    pbVar4 = pbVar3;
    if (1 < (int)local_20) {
      while( true ) {
        pbVar3 = pbVar4 + -1;
        pbVar8 = pbVar8 + -1;
        *pbVar4 = 0;
        bVar1 = *pbVar8;
        local_20 = sVar5;
        if (bVar1 != 0) break;
        if (sVar5 == 1) {
          *pbVar3 = 0;
          goto LAB_08137ec8;
        }
        sVar5 = sVar5 - 1;
        pbVar4 = pbVar3;
      }
      goto LAB_08137f9b;
    }
  }
  else {
LAB_08137f9b:
    bVar1 = -bVar1;
  }
  *pbVar3 = bVar1;
  if (1 < (int)local_20) {
    iVar6 = 0;
    do {
      pbVar3[iVar6 + -1] = ~pbVar8[iVar6 + -1];
      iVar6 = iVar6 + -1;
    } while (iVar6 != 1 - local_20);
  }
LAB_08137ec8:
  *pp = *pp + sVar10;
  return sVar10;
}

