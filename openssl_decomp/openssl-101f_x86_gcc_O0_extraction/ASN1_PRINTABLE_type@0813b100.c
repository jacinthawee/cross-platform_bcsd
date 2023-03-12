
int ASN1_PRINTABLE_type(uchar *s,int max)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  byte *pbVar5;
  
  if (max < 1) {
    max = -1;
  }
  if (s == (uchar *)0x0) {
    return 0x13;
  }
  pbVar5 = s + max;
  bVar2 = false;
  bVar3 = false;
  while ((bVar1 = *s, bVar1 != 0 && (s != pbVar5))) {
    s = s + 1;
    if ((0x19 < (byte)((bVar1 & 0xdf) + 0xbf)) && (bVar1 != 0x20)) {
      if ((byte)(bVar1 - 0x27) < 0x19) {
        if ((0x14ffff7U >> (bVar1 - 0x27 & 0x1f) & 1) == 0) {
          bVar3 = true;
        }
      }
      else {
        bVar3 = true;
      }
    }
    if ((char)bVar1 < '\0') {
      bVar2 = true;
    }
  }
  iVar4 = 0x14;
  if (!bVar2) {
    iVar4 = (-(uint)!bVar3 & 0xfffffffd) + 0x16;
  }
  return iVar4;
}

