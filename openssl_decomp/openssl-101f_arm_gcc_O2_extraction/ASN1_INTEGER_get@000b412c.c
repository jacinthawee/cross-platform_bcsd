
long ASN1_INTEGER_get(ASN1_INTEGER *a)

{
  ushort uVar1;
  uint3 uVar2;
  bool bVar3;
  byte *pbVar4;
  int iVar5;
  
  if (a != (ASN1_INTEGER *)0x0) {
    if (a->type == 0x102) {
      bVar3 = true;
    }
    else {
      if (a->type != 2) {
        return -1;
      }
      bVar3 = false;
    }
    iVar5 = a->length;
    if (4 < iVar5) {
      return -1;
    }
    pbVar4 = a->data;
    if (pbVar4 == (byte *)0x0) {
      return 0;
    }
    if (iVar5 < 1) {
      a = (ASN1_INTEGER *)0x0;
    }
    else {
      a = (ASN1_INTEGER *)(uint)*pbVar4;
      if (1 < iVar5) {
        uVar1 = CONCAT11(*pbVar4,pbVar4[1]);
        a = (ASN1_INTEGER *)(uint)uVar1;
        if (2 < iVar5) {
          uVar2 = CONCAT21(uVar1,pbVar4[2]);
          a = (ASN1_INTEGER *)(uint)uVar2;
          if (3 < iVar5) {
            a = (ASN1_INTEGER *)CONCAT31(uVar2,pbVar4[3]);
          }
        }
      }
    }
    if (bVar3) {
      a = (ASN1_INTEGER *)-(int)a;
    }
  }
  return (long)a;
}

