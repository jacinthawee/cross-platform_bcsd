
int i2c_ASN1_INTEGER(ASN1_INTEGER *a,uchar **pp)

{
  byte bVar1;
  uchar uVar2;
  uchar *__dest;
  byte *pbVar3;
  uchar *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  
  if (a == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  pbVar5 = (byte *)a->length;
  pbVar3 = (byte *)(a->type & 0x100);
  if (pbVar5 == (byte *)0x0) {
    pbVar8 = (byte *)0x1;
    pbVar6 = pbVar5;
    pbVar7 = pbVar5;
    goto LAB_000b3d3a;
  }
  pbVar8 = a->data;
  bVar1 = *pbVar8;
  pbVar9 = (byte *)(uint)(0x7f < bVar1);
  if (pbVar3 != (byte *)0x0) {
    pbVar9 = (byte *)0x0;
  }
  if (pbVar9 == (byte *)0x0) {
    pbVar6 = pbVar3;
    pbVar7 = pbVar3;
    if (pbVar3 != (byte *)0x0) {
      if (bVar1 < 0x81) {
        pbVar6 = pbVar9;
        pbVar7 = pbVar9;
        if ((bVar1 != 0x80) || ((int)pbVar5 < 2)) goto LAB_000b3db2;
        if (pbVar8[1] == 0) {
          pbVar6 = pbVar8 + 2;
          do {
            if (pbVar6 == pbVar8 + (int)pbVar5) {
              pbVar6 = (byte *)0x0;
              pbVar7 = (byte *)0x0;
              goto LAB_000b3db2;
            }
            bVar1 = *pbVar6;
            pbVar6 = pbVar6 + 1;
          } while (bVar1 == 0);
        }
      }
      pbVar6 = (byte *)0x1;
      pbVar7 = (byte *)0xff;
    }
  }
  else {
    pbVar6 = (byte *)0x1;
    pbVar7 = (byte *)0x0;
  }
LAB_000b3db2:
  pbVar8 = pbVar6 + (int)pbVar5;
LAB_000b3d3a:
  if (pp == (uchar **)0x0) {
    return (int)pbVar8;
  }
  __dest = *pp;
  if (pbVar6 != (byte *)0x0) {
    *__dest = (uchar)pbVar7;
    __dest = __dest + 1;
    pbVar5 = (byte *)a->length;
  }
  if (pbVar5 == (byte *)0x0) {
    *__dest = '\0';
  }
  else {
    if (pbVar3 == (byte *)0x0) {
      memcpy(__dest,a->data,(size_t)pbVar5);
      *pp = *pp + (int)pbVar8;
      return (int)pbVar8;
    }
    pbVar7 = pbVar5 + -1;
    puVar4 = a->data + (int)pbVar7;
    uVar2 = a->data[(int)pbVar7];
    pbVar3 = __dest + (int)pbVar7;
    pbVar6 = pbVar5;
    while (uVar2 == '\0') {
      puVar4 = puVar4 + -1;
      *pbVar3 = 0;
      pbVar6 = pbVar3 + -1 + ((int)pbVar5 - (int)(__dest + (int)pbVar7));
      pbVar3 = pbVar3 + -1;
      uVar2 = *puVar4;
    }
    *pbVar3 = -uVar2;
    if (1 < (int)pbVar6) {
      pbVar5 = puVar4 + -1;
      do {
        pbVar7 = pbVar5 + -1;
        pbVar3 = pbVar3 + -1;
        *pbVar3 = ~*pbVar5;
        pbVar5 = pbVar7;
      } while (pbVar7 != puVar4 + -(int)pbVar6);
      *pp = *pp + (int)pbVar8;
      return (int)pbVar8;
    }
  }
  *pp = *pp + (int)pbVar8;
  return (int)pbVar8;
}

