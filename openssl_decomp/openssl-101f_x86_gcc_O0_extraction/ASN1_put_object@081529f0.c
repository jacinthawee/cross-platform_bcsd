
void ASN1_put_object(uchar **pp,int constructed,int length,int tag,int xclass)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  byte *pbVar6;
  
  pbVar2 = *pp;
  pbVar6 = pbVar2 + 1;
  bVar4 = ~-(constructed == 0) & 0x20U | (byte)xclass & 0xc0;
  if (tag < 0x1f) {
    *pbVar2 = bVar4 | (byte)tag & 0x1f;
  }
  else {
    *pbVar2 = bVar4 | 0x1f;
    iVar3 = tag;
    iVar5 = 0;
    do {
      iVar1 = iVar5;
      iVar3 = iVar3 >> 7;
      iVar5 = iVar1 + 1;
    } while (iVar3 != 0);
    pbVar2[iVar1 + 1] = (byte)tag & 0x7f;
    iVar3 = iVar1;
    while( true ) {
      iVar5 = iVar3 + -1;
      tag = tag >> 7;
      if (iVar5 == -1) break;
      bVar4 = (byte)tag & 0x7f;
      if (iVar1 == iVar5) {
        pbVar2[iVar1 + 1] = bVar4;
        iVar3 = iVar5;
      }
      else {
        pbVar2[iVar3] = bVar4 | 0x80;
        iVar3 = iVar5;
      }
    }
    pbVar6 = pbVar6 + iVar1 + 1;
  }
  if (constructed == 2) {
    *pbVar6 = 0x80;
    *pp = pbVar6 + 1;
    return;
  }
  iVar3 = 0;
  iVar5 = length;
  if (length < 0x80) {
    *pbVar6 = (byte)length;
    *pp = pbVar6 + 1;
    return;
  }
  do {
    iVar1 = iVar3;
    iVar5 = iVar5 >> 8;
    iVar3 = iVar1 + 1;
  } while (iVar5 != 0);
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

