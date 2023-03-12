
undefined4 str2fmt(byte *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  bVar1 = *param_1;
  bVar4 = bVar1 & 0xdf;
  if (bVar4 == 0x44) {
    return 1;
  }
  if (bVar4 == 0x54) {
    return 2;
  }
  if (bVar4 == 0x4e) {
    return 4;
  }
  if (bVar4 == 0x53) {
    return 6;
  }
  if (bVar4 == 0x4d) {
    return 0xb;
  }
  if ((((bVar1 == 0x31) || (iVar2 = strcmp((char *)param_1,"PKCS12"), iVar2 == 0)) ||
      (iVar2 = strcmp((char *)param_1,"pkcs12"), iVar2 == 0)) ||
     (((bVar1 == 0x50 || (bVar1 == 0x70)) &&
      ((param_1[1] == 0x31 && ((param_1[2] == 0x32 && (param_1[3] == 0)))))))) {
    return 5;
  }
  if (bVar4 == 0x45) {
    return 7;
  }
  if (bVar4 == 0x50) {
    if ((param_1[1] & 0xdf) == 0x56) {
      uVar3 = 0xc;
    }
    else {
      uVar3 = 3;
    }
    return uVar3;
  }
  return 0;
}

