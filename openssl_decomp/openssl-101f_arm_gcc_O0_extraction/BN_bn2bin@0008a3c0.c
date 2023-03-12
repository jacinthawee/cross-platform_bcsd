
int BN_bn2bin(BIGNUM *a,uchar *to)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ulong *puVar5;
  
  iVar1 = a->top;
  if (iVar1 != 0) {
    puVar5 = a->d;
    uVar2 = puVar5[iVar1 + -1];
    if (uVar2 >> 0x10 == 0) {
      if ((uVar2 & 0xff00) == 0) {
        uVar2 = (uint)(byte)bits_8706[uVar2];
      }
      else {
        uVar2 = (byte)bits_8706[uVar2 >> 8] + 8;
      }
    }
    else if ((uVar2 & 0xff000000) == 0) {
      uVar2 = (byte)bits_8706[uVar2 >> 0x10] + 0x10;
    }
    else {
      uVar2 = (byte)bits_8706[uVar2 >> 0x18] + 0x18;
    }
    iVar1 = uVar2 + (iVar1 + -1) * 0x20;
    iVar3 = iVar1 + 7;
    iVar1 = iVar1 + 0xe;
    if (-1 < iVar3) {
      iVar1 = iVar3;
    }
    iVar1 = iVar1 >> 3;
    uVar2 = iVar1 - 1;
    if (iVar1 != 0) {
      while( true ) {
        uVar4 = uVar2 + 3 & (int)uVar2 >> 0x20;
        if (uVar2 < 0xfffffffd) {
          uVar4 = uVar2;
        }
        *to = (uchar)(puVar5[(int)uVar4 >> 2] >> (((int)uVar2 % 4) * 8 & 0xffU));
        if (uVar2 - 1 == 0xffffffff) break;
        puVar5 = a->d;
        to = to + 1;
        uVar2 = uVar2 - 1;
      }
    }
  }
  return iVar1;
}

