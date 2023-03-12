
int ASN1_object_size(int constructed,int length,int tag)

{
  int iVar1;
  int iVar2;
  
  iVar1 = length + 1;
  iVar2 = iVar1;
  if (0x1e < tag) {
    do {
      iVar2 = iVar1 + 1;
      if (tag >> 7 == 0) break;
      tag = tag >> 0xe;
      iVar1 = iVar1 + 2;
      iVar2 = iVar1;
    } while (tag != 0);
  }
  if (constructed == 2) {
    return iVar2 + 3;
  }
  iVar2 = iVar2 + 1;
  if (0x7f < length) {
    do {
      length = length >> 8;
      iVar2 = iVar2 + 1;
    } while (length != 0);
  }
  return iVar2;
}

