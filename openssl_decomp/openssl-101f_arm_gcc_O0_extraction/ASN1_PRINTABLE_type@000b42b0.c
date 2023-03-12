
int ASN1_PRINTABLE_type(uchar *s,int max)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  byte *pbVar4;
  byte bVar5;
  bool bVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  
  if (max < 1) {
    max = -1;
  }
  if (s == (uchar *)0x0) {
    return 0x13;
  }
  pbVar8 = s + 1;
  bVar2 = false;
  pbVar9 = pbVar8 + max;
  bVar6 = false;
LAB_000b42c6:
  bVar1 = pbVar8[-1];
  pbVar4 = pbVar8;
joined_r0x000b42d0:
  uVar3 = (uint)bVar1;
  if (uVar3 == 0) {
LAB_000b4312:
    if (bVar2) {
      return 0x14;
    }
    if (bVar6) {
      iVar7 = 0x16;
    }
    else {
      iVar7 = 0x13;
    }
    return iVar7;
  }
  pbVar8 = pbVar4 + 1;
  if (pbVar4 == pbVar9) goto LAB_000b4312;
  if (0x19 < (uVar3 & 0xffffffdf) - 0x41) {
    if (uVar3 == 0x20) goto LAB_000b42c6;
    if (((2 < uVar3 - 0x27) && (0xf < uVar3 - 0x2b)) && ((uVar3 & 0xfd) != 0x3d)) {
      bVar6 = true;
    }
  }
  bVar5 = bVar1 & 0x80;
  bVar1 = *pbVar4;
  pbVar4 = pbVar8;
  if (bVar5 != 0) {
    bVar2 = true;
  }
  goto joined_r0x000b42d0;
}

