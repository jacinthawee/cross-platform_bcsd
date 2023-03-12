
void bn_sqr_words(ulong *rp,ulong *ap,int num)

{
  longlong *plVar1;
  ulong *puVar2;
  
  if (0 < num) {
    plVar1 = (longlong *)rp;
    puVar2 = ap;
    if ((num & 0xfffffffcU) != 0) {
      do {
        num = num - 4;
        puVar2 = ap + 4;
        plVar1 = (longlong *)((int)rp + 0x20);
        *(ulonglong *)rp = (ulonglong)*ap * (ulonglong)*ap;
        *(ulonglong *)((int)rp + 8) = (ulonglong)ap[1] * (ulonglong)ap[1];
        *(ulonglong *)((int)rp + 0x10) = (ulonglong)ap[2] * (ulonglong)ap[2];
        *(ulonglong *)((int)rp + 0x18) = (ulonglong)ap[3] * (ulonglong)ap[3];
        rp = (ulong *)plVar1;
        ap = puVar2;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return;
      }
    }
    *plVar1 = (ulonglong)*puVar2 * (ulonglong)*puVar2;
    if ((num != 1) && (plVar1[1] = (ulonglong)puVar2[1] * (ulonglong)puVar2[1], num != 2)) {
      plVar1[2] = (ulonglong)puVar2[2] * (ulonglong)puVar2[2];
    }
  }
  return;
}

