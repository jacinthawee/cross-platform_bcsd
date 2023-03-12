
ulong bn_mul_words(ulong *rp,ulong *ap,int num,ulong w)

{
  ulonglong uVar1;
  longlong lVar2;
  uint uVar3;
  ulong *puVar4;
  ulong *puVar5;
  
  uVar3 = 0;
  if (0 < num) {
    puVar4 = rp;
    puVar5 = ap;
    if ((num & 0xfffffffcU) != 0) {
      do {
        rp = puVar4 + 4;
        ap = puVar5 + 4;
        num = num - 4;
        uVar1 = (ulonglong)uVar3 + (ulonglong)*puVar5 * (ulonglong)w;
        *puVar4 = (ulong)uVar1;
        uVar1 = (uVar1 >> 0x20) + (ulonglong)puVar5[1] * (ulonglong)w;
        puVar4[1] = (ulong)uVar1;
        uVar1 = (uVar1 >> 0x20) + (ulonglong)puVar5[2] * (ulonglong)w;
        puVar4[2] = (ulong)uVar1;
        lVar2 = (uVar1 >> 0x20) + (ulonglong)puVar5[3] * (ulonglong)w;
        uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
        puVar4[3] = (ulong)lVar2;
        puVar4 = rp;
        puVar5 = ap;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return uVar3;
      }
    }
    lVar2 = (ulonglong)*ap * (ulonglong)w + (ulonglong)uVar3;
    *rp = (ulong)lVar2;
    uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
    if (num != 1) {
      lVar2 = (ulonglong)ap[1] * (ulonglong)w + (ulonglong)uVar3;
      rp[1] = (ulong)lVar2;
      uVar3 = (uint)((ulonglong)lVar2 >> 0x20);
      if (num != 2) {
        lVar2 = (ulonglong)ap[2] * (ulonglong)w + (ulonglong)uVar3;
        rp[2] = (ulong)lVar2;
        return (ulong)((ulonglong)lVar2 >> 0x20);
      }
    }
  }
  return uVar3;
}

