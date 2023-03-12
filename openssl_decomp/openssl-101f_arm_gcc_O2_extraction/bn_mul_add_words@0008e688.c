
ulong bn_mul_add_words(ulong *rp,ulong *ap,int num,ulong w)

{
  ulonglong uVar1;
  longlong lVar2;
  ulong *puVar3;
  ulong *puVar4;
  ulong *puVar5;
  ulong uVar6;
  ulong *puVar7;
  
  if (num < 1) {
    uVar6 = 0;
  }
  else {
    uVar6 = num & 0xfffffffc;
    if (uVar6 != 0) {
      uVar6 = 0;
      puVar4 = rp;
      puVar5 = ap;
      puVar3 = rp + 4;
      puVar7 = rp + 4;
      do {
        rp = puVar3;
        num = num - 4;
        ap = puVar5 + 4;
        uVar1 = (ulonglong)w * (ulonglong)*puVar5 + (ulonglong)puVar7[-4] + (ulonglong)uVar6;
        puVar7[-4] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar5[1] + (ulonglong)puVar4[1] + (uVar1 >> 0x20);
        puVar4[1] = (ulong)uVar1;
        uVar1 = (ulonglong)w * (ulonglong)puVar5[2] + (ulonglong)puVar4[2] + (uVar1 >> 0x20);
        puVar4[2] = (ulong)uVar1;
        lVar2 = (ulonglong)w * (ulonglong)puVar5[3] + (ulonglong)puVar4[3] + (uVar1 >> 0x20);
        puVar4[3] = (ulong)lVar2;
        uVar6 = (ulong)((ulonglong)lVar2 >> 0x20);
        puVar4 = rp;
        puVar5 = ap;
        puVar3 = rp + 4;
        puVar7 = puVar7 + 4;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return uVar6;
      }
    }
    puVar4 = ap + -1;
    do {
      puVar4 = puVar4 + 1;
      lVar2 = (ulonglong)*puVar4 * (ulonglong)w + (ulonglong)uVar6 + (ulonglong)*rp;
      *rp = (ulong)lVar2;
      uVar6 = (ulong)((ulonglong)lVar2 >> 0x20);
      num = num - 1;
      rp = rp + 1;
    } while (num != 0);
  }
  return uVar6;
}

