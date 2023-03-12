
int BN_num_bits(BIGNUM *a)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = a->top;
  if (iVar1 != 0) {
    uVar2 = a->d[iVar1 + -1];
    iVar1 = (iVar1 + -1) * 0x20;
    if ((uVar2 & 0xffff0000) == 0) {
      if ((uVar2 & 0xff00) == 0) {
        return iVar1 + (uint)(byte)bits_6072[uVar2];
      }
      return iVar1 + (byte)bits_6072[uVar2 >> 8] + 8;
    }
    if ((uVar2 & 0xff000000) == 0) {
      return iVar1 + (byte)bits_6072[uVar2 >> 0x10] + 0x10;
    }
    iVar1 = iVar1 + (byte)bits_6072[uVar2 >> 0x18] + 0x18;
  }
  return iVar1;
}

