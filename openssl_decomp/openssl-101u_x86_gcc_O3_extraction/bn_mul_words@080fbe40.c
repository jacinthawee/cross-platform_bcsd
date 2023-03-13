
ulong bn_mul_words(ulong *rp,ulong *ap,int num,ulong w)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  ulong uVar4;
  
  if (num < 1) {
    return 0;
  }
  uVar4 = 0;
  if ((num & 0xfffffffcU) != 0) {
    uVar4 = 0;
    do {
      uVar1 = (ulonglong)*ap * (ulonglong)w + (ulonglong)uVar4;
      *rp = (ulong)uVar1;
      uVar1 = (ulonglong)ap[1] * (ulonglong)w + (uVar1 >> 0x20);
      rp[1] = (ulong)uVar1;
      uVar1 = (ulonglong)ap[2] * (ulonglong)w + (uVar1 >> 0x20);
      rp[2] = (ulong)uVar1;
      lVar2 = (ulonglong)ap[3] * (ulonglong)w + (uVar1 >> 0x20);
      uVar4 = (ulong)((ulonglong)lVar2 >> 0x20);
      num = num - 4;
      rp[3] = (ulong)lVar2;
      ap = ap + 4;
      rp = rp + 4;
    } while ((num & 0xfffffffcU) != 0);
    if (num == 0) {
      return uVar4;
    }
  }
  lVar2 = (ulonglong)*ap * (ulonglong)w + (ulonglong)uVar4;
  uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
  *rp = (ulong)lVar2;
  if (num != 1) {
    lVar2 = (ulonglong)ap[1] * (ulonglong)w + (ulonglong)uVar3;
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    rp[1] = (ulong)lVar2;
    if (num != 2) {
      lVar2 = (ulonglong)ap[2] * (ulonglong)w + (ulonglong)uVar3;
      uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
      rp[2] = (ulong)lVar2;
    }
  }
  return uVar3;
}

