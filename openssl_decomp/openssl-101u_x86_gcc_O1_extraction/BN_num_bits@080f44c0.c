
int BN_num_bits(BIGNUM *a)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = a->top;
  if (iVar2 != 0) {
    iVar3 = (iVar2 + -1) * 0x20;
    uVar1 = a->d[iVar2 + -1];
    if ((uVar1 & 0xffff0000) == 0) {
      if ((char)(uVar1 >> 8) == '\0') {
        iVar2 = (uint)(byte)bits_6057[uVar1] + iVar3;
      }
      else {
        iVar2 = (byte)bits_6057[uVar1 >> 8] + 8 + iVar3;
      }
    }
    else if ((uVar1 & 0xff000000) == 0) {
      iVar2 = (byte)bits_6057[uVar1 >> 0x10] + 0x10 + iVar3;
    }
    else {
      iVar2 = (byte)bits_6057[uVar1 >> 0x18] + 0x18 + iVar3;
    }
  }
  return iVar2;
}

