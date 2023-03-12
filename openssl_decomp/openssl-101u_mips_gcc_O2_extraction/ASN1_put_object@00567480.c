
void ASN1_put_object(uchar **pp,int constructed,int length,int tag,int xclass)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  byte *pbVar6;
  
  bVar5 = 0x20;
  pbVar6 = *pp;
  if (constructed == 0) {
    bVar5 = 0;
  }
  bVar5 = (byte)xclass & 0xc0 | bVar5;
  if (tag < 0x1f) {
    *pbVar6 = (byte)tag & 0x1f | bVar5;
    pbVar6 = pbVar6 + 1;
  }
  else {
    *pbVar6 = bVar5 | 0x1f;
    iVar3 = tag;
    iVar4 = 0;
    do {
      iVar1 = iVar4;
      iVar3 = iVar3 >> 7;
      iVar4 = iVar1 + 1;
    } while (iVar3 != 0);
    pbVar6[iVar1 + 1] = (byte)tag & 0x7f;
    pbVar2 = pbVar6 + iVar1;
    iVar4 = tag >> 7;
    iVar3 = iVar1;
    while (iVar3 = iVar3 + -1, iVar3 != -1) {
      bVar5 = (byte)iVar4 & 0x7f;
      if (iVar1 != iVar3) {
        bVar5 = bVar5 | 0x80;
      }
      *pbVar2 = bVar5;
      iVar4 = iVar4 >> 7;
      pbVar2 = pbVar2 + -1;
    }
    pbVar6 = pbVar6 + iVar1 + 2;
  }
  if (constructed == 2) {
    *pbVar6 = 0x80;
    *pp = pbVar6 + 1;
    return;
  }
  if (0x7f < length) {
    iVar3 = 0;
    iVar4 = length;
    do {
      iVar1 = iVar3;
      iVar4 = iVar4 >> 8;
      iVar3 = iVar1 + 1;
    } while (iVar4 != 0);
    pbVar2 = pbVar6 + iVar1;
    *pbVar6 = (byte)(iVar1 + 1) | 0x80;
    do {
      pbVar2[1] = (byte)length;
      pbVar2 = pbVar2 + -1;
      length = length >> 8;
    } while (pbVar2 != pbVar6 + -1);
    *pp = pbVar6 + iVar1 + 2;
    return;
  }
  *pbVar6 = (byte)length;
  *pp = pbVar6 + 1;
  return;
}

