
void bn_sqr_words(ulong *rp,ulong *ap,int num)

{
  longlong lVar1;
  ulong *puVar2;
  ulong *puVar3;
  
  if (0 < num) {
    puVar2 = rp;
    puVar3 = ap;
    if ((num & 0xfffffffcU) != 0) {
      do {
        puVar2 = rp + 8;
        puVar3 = ap + 4;
        num = num - 4;
        lVar1 = (ulonglong)*ap * (ulonglong)*ap;
        *rp = (ulong)lVar1;
        rp[1] = (ulong)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)ap[1] * (ulonglong)ap[1];
        rp[2] = (ulong)lVar1;
        rp[3] = (ulong)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)ap[2] * (ulonglong)ap[2];
        rp[4] = (ulong)lVar1;
        rp[5] = (ulong)((ulonglong)lVar1 >> 0x20);
        lVar1 = (ulonglong)ap[3] * (ulonglong)ap[3];
        rp[6] = (ulong)lVar1;
        rp[7] = (ulong)((ulonglong)lVar1 >> 0x20);
        rp = puVar2;
        ap = puVar3;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return;
      }
    }
    lVar1 = (ulonglong)*puVar3 * (ulonglong)*puVar3;
    *puVar2 = (ulong)lVar1;
    puVar2[1] = (ulong)((ulonglong)lVar1 >> 0x20);
    if (num != 1) {
      lVar1 = (ulonglong)puVar3[1] * (ulonglong)puVar3[1];
      puVar2[2] = (ulong)lVar1;
      puVar2[3] = (ulong)((ulonglong)lVar1 >> 0x20);
      if (num != 2) {
        lVar1 = (ulonglong)puVar3[2] * (ulonglong)puVar3[2];
        puVar2[4] = (ulong)lVar1;
        puVar2[5] = (ulong)((ulonglong)lVar1 >> 0x20);
      }
    }
  }
  return;
}

