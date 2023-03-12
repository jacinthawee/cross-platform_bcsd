
long ASN1_INTEGER_get(ASN1_INTEGER *a)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  
  if (a != (ASN1_INTEGER *)0x0) {
    if (a->type == 0x102) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
      if (a->type != 2) {
        return -1;
      }
    }
    iVar5 = a->length;
    if (4 < iVar5) {
      return -1;
    }
    pbVar6 = a->data;
    if (pbVar6 != (byte *)0x0) {
      if (iVar5 < 1) {
        uVar4 = 0;
      }
      else {
        uVar4 = (uint)*pbVar6;
        if (iVar5 != 1) {
          uVar1 = CONCAT11(*pbVar6,pbVar6[1]);
          uVar4 = (uint)uVar1;
          if (iVar5 != 2) {
            uVar2 = CONCAT21(uVar1,pbVar6[2]);
            uVar4 = (uint)uVar2;
            if (iVar5 == 4) {
              uVar4 = CONCAT31(uVar2,pbVar6[3]);
            }
          }
        }
      }
      if (!bVar3) {
        return uVar4;
      }
      return -uVar4;
    }
  }
  return 0;
}

