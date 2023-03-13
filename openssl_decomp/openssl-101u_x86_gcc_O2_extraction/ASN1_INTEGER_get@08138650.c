
long ASN1_INTEGER_get(ASN1_INTEGER *a)

{
  int iVar1;
  byte *pbVar2;
  ushort uVar3;
  uint3 uVar4;
  bool bVar5;
  uint uVar6;
  
  if (a == (ASN1_INTEGER *)0x0) {
    return 0;
  }
  if (a->type == 0x102) {
    bVar5 = true;
  }
  else {
    if (a->type != 2) {
      return -1;
    }
    bVar5 = false;
  }
  iVar1 = a->length;
  if (4 < iVar1) {
    return -1;
  }
  pbVar2 = a->data;
  if (pbVar2 == (byte *)0x0) {
    return 0;
  }
  if (iVar1 < 1) {
    uVar6 = 0;
  }
  else {
    uVar6 = (uint)*pbVar2;
    if (iVar1 != 1) {
      uVar3 = CONCAT11(*pbVar2,pbVar2[1]);
      uVar6 = (uint)uVar3;
      if (iVar1 != 2) {
        uVar4 = CONCAT21(uVar3,pbVar2[2]);
        uVar6 = (uint)uVar4;
        if (iVar1 == 4) {
          uVar6 = CONCAT31(uVar4,pbVar2[3]);
        }
      }
    }
  }
  if (bVar5) {
    return -uVar6;
  }
  return uVar6;
}

