
int ASN1_PRINTABLE_type(uchar *s,int max)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  
  if (max < 1) {
    max = -1;
  }
  if (s == (uchar *)0x0) {
    return 0x13;
  }
  pbVar6 = s + max;
  bVar2 = false;
  bVar3 = false;
  bVar1 = *s;
  while (uVar4 = (uint)bVar1, uVar4 != 0) {
    if (s == pbVar6) break;
    s = s + 1;
    if ((uVar4 & 0xffffffdf) - 0x41 < 0x1a) {
LAB_0054ec18:
      if ((bVar1 & 0x80) != 0) {
        bVar2 = true;
      }
    }
    else {
      if (0x1f < (uVar4 - 0x20 & 0xff)) {
        bVar3 = true;
        goto LAB_0054ec18;
      }
      if ((0xa7fffb81U >> (uVar4 - 0x20 & 0x1f) & 1) == 0) {
        bVar3 = true;
      }
      if ((bVar1 & 0x80) != 0) {
        bVar2 = true;
      }
    }
    bVar1 = *s;
  }
  if (!bVar2) {
    iVar5 = 0x16;
    if (!bVar3) {
      iVar5 = 0x13;
    }
    return iVar5;
  }
  return 0x14;
}

