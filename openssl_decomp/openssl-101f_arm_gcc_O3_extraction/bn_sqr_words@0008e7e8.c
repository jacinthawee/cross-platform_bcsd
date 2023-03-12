
void bn_sqr_words(ulong *rp,ulong *ap,int num)

{
  longlong *plVar1;
  ulong *puVar2;
  uint *puVar3;
  
  if (0 < num) {
    plVar1 = (longlong *)rp;
    puVar2 = ap;
    if ((num & 0xfffffffcU) != 0) {
      do {
        num = num - 4;
        ap = puVar2 + 4;
        *plVar1 = (ulonglong)*puVar2 * (ulonglong)*puVar2;
        rp = (ulong *)(plVar1 + 4);
        plVar1[1] = (ulonglong)puVar2[1] * (ulonglong)puVar2[1];
        plVar1[2] = (ulonglong)puVar2[2] * (ulonglong)puVar2[2];
        plVar1[3] = (ulonglong)puVar2[3] * (ulonglong)puVar2[3];
        plVar1 = (longlong *)rp;
        puVar2 = ap;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return;
      }
    }
    puVar3 = ap + -1;
    do {
      puVar3 = puVar3 + 1;
      num = num - 1;
      *(ulonglong *)rp = (ulonglong)*puVar3 * (ulonglong)*puVar3;
      rp = (ulong *)((int)rp + 8);
    } while (num != 0);
  }
  return;
}

