
int BN_num_bits(BIGNUM *a)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = a->top;
  if (iVar1 != 0) {
    iVar2 = (iVar1 + -1) * 0x20;
    uVar3 = a->d[iVar1 + -1];
    if (uVar3 >> 0x10 == 0) {
      if ((uVar3 & 0xff00) == 0) {
        uVar3 = (uint)(byte)bits_8706[uVar3];
      }
      else {
        uVar3 = (byte)bits_8706[uVar3 >> 8] + 8;
      }
      iVar1 = uVar3 + iVar2;
    }
    else {
      if ((uVar3 & 0xff000000) == 0) {
        iVar1 = (byte)bits_8706[uVar3 >> 0x10] + 0x10;
      }
      else {
        iVar1 = (byte)bits_8706[uVar3 >> 0x18] + 0x18;
      }
      iVar1 = iVar1 + iVar2;
    }
  }
  return iVar1;
}

