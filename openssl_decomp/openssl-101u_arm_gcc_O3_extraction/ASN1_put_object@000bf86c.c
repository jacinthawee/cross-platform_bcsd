
void ASN1_put_object(uchar **pp,int constructed,int length,int tag,int xclass)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  if (constructed == 0) {
    bVar5 = 0;
  }
  else {
    bVar5 = 0x20;
  }
  pbVar6 = *pp;
  bVar5 = bVar5 | (byte)xclass & 0xc0;
  if (tag < 0x1f) {
    pbVar7 = pbVar6 + 1;
    *pbVar6 = bVar5 | (byte)tag & 0x1f;
  }
  else {
    *pbVar6 = bVar5 | 0x1f;
    iVar2 = tag;
    iVar3 = 0;
    do {
      iVar1 = iVar3;
      iVar2 = iVar2 >> 7;
      iVar3 = iVar1 + 1;
    } while (iVar2 != 0);
    pbVar6[iVar1 + 1] = (byte)tag & 0x7f;
    iVar2 = iVar1;
    while( true ) {
      iVar3 = iVar2 + -1;
      tag = tag >> 7;
      bVar5 = (byte)tag & 0x7f;
      if (iVar2 < 1) break;
      if (iVar3 == iVar1) {
        pbVar6[iVar2] = bVar5;
        iVar2 = iVar3;
      }
      else {
        pbVar6[iVar2] = bVar5 | 0x80;
        iVar2 = iVar3;
      }
    }
    pbVar7 = pbVar6 + iVar1 + 2;
  }
  if (constructed == 2) {
    *pbVar7 = 0x80;
    *pp = pbVar7 + 1;
    return;
  }
  if (length < 0x80) {
    *pbVar7 = (byte)length;
    pbVar7 = pbVar7 + 1;
  }
  else {
    iVar2 = 0;
    iVar3 = length;
    do {
      iVar1 = iVar2;
      iVar3 = iVar3 >> 8;
      iVar2 = iVar1 + 1;
    } while (iVar3 != 0);
    *pbVar7 = (byte)iVar2 | 0x80;
    pbVar6 = pbVar7 + iVar2;
    do {
      pbVar4 = pbVar6 + -1;
      *pbVar6 = (byte)length;
      length = length >> 8;
      pbVar6 = pbVar4;
    } while (0 < (int)pbVar4 - (int)pbVar7);
    pbVar7 = pbVar7 + iVar1 + 2;
  }
  *pp = pbVar7;
  return;
}

