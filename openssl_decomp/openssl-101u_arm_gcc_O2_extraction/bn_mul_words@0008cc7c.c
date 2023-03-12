
ulong bn_mul_words(ulong *rp,ulong *ap,int num,ulong w)

{
  ulonglong uVar1;
  longlong lVar2;
  ulong *puVar3;
  uint *puVar4;
  uint uVar5;
  ulong *puVar6;
  
  if (num < 1) {
    uVar5 = 0;
  }
  else {
    uVar5 = num & 0xfffffffc;
    if (uVar5 != 0) {
      uVar5 = 0;
      puVar3 = ap;
      puVar6 = rp;
      do {
        num = num - 4;
        ap = puVar3 + 4;
        uVar1 = (ulonglong)w * (ulonglong)*puVar3 + (ulonglong)uVar5;
        rp = puVar6 + 4;
        *puVar6 = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar3[1] + (uVar1 >> 0x20);
        puVar6[1] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar3[2] + (uVar1 >> 0x20);
        puVar6[2] = (ulong)uVar1;
        lVar2 = (ulonglong)w * (ulonglong)puVar3[3] + (uVar1 >> 0x20);
        uVar5 = (uint)((ulonglong)lVar2 >> 0x20);
        puVar6[3] = (ulong)lVar2;
        puVar3 = ap;
        puVar6 = rp;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return uVar5;
      }
    }
    puVar4 = ap + -1;
    do {
      puVar4 = puVar4 + 1;
      num = num - 1;
      lVar2 = (ulonglong)*puVar4 * (ulonglong)w + (ulonglong)uVar5;
      uVar5 = (uint)((ulonglong)lVar2 >> 0x20);
      *rp = (ulong)lVar2;
      rp = rp + 1;
    } while (num != 0);
  }
  return uVar5;
}

