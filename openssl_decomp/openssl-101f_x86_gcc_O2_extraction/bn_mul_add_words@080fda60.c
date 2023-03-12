
ulong bn_mul_add_words(ulong *rp,ulong *ap,int num,ulong w)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  ulong uVar4;
  
  if (num < 1) {
    return 0;
  }
  uVar3 = 0;
  if ((num & 0xfffffffcU) != 0) {
    uVar3 = 0;
    do {
      uVar1 = (ulonglong)*ap * (ulonglong)w + (ulonglong)CONCAT14(CARRY4(uVar3,*rp),uVar3 + *rp);
      *rp = (uint)uVar1;
      uVar1 = (ulonglong)ap[1] * (ulonglong)w + (ulonglong)rp[1] + (uVar1 >> 0x20);
      rp[1] = (uint)uVar1;
      uVar1 = (ulonglong)ap[2] * (ulonglong)w + (ulonglong)rp[2] + (uVar1 >> 0x20);
      rp[2] = (uint)uVar1;
      lVar2 = (ulonglong)ap[3] * (ulonglong)w + (ulonglong)rp[3] + (uVar1 >> 0x20);
      uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
      num = num - 4;
      rp[3] = (uint)lVar2;
      ap = ap + 4;
      rp = rp + 4;
    } while ((num & 0xfffffffcU) != 0);
    if (num == 0) {
      return uVar3;
    }
  }
  lVar2 = (ulonglong)*ap * (ulonglong)w + (ulonglong)CONCAT14(CARRY4(*rp,uVar3),*rp + uVar3);
  uVar4 = (ulong)((ulonglong)lVar2 >> 0x20);
  *rp = (uint)lVar2;
  if (num != 1) {
    lVar2 = (ulonglong)ap[1] * (ulonglong)w + (ulonglong)CONCAT14(CARRY4(uVar4,rp[1]),uVar4 + rp[1])
    ;
    uVar4 = (ulong)((ulonglong)lVar2 >> 0x20);
    rp[1] = (uint)lVar2;
    if (num != 2) {
      lVar2 = (ulonglong)ap[2] * (ulonglong)w +
              (ulonglong)CONCAT14(CARRY4(rp[2],uVar4),rp[2] + uVar4);
      uVar4 = (ulong)((ulonglong)lVar2 >> 0x20);
      rp[2] = (uint)lVar2;
    }
  }
  return uVar4;
}

