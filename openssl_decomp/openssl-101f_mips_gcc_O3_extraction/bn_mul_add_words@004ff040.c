
ulong bn_mul_add_words(ulong *rp,ulong *ap,int num,ulong w)

{
  ulonglong uVar1;
  longlong lVar2;
  ulong uVar3;
  ulong *puVar4;
  ulong *puVar5;
  uint uVar6;
  
  uVar3 = 0;
  if (0 < num) {
    puVar4 = rp;
    puVar5 = ap;
    if ((num & 0xfffffffcU) != 0) {
      do {
        ap = puVar5 + 4;
        uVar6 = *puVar4 + uVar3;
        rp = puVar4 + 4;
        num = num - 4;
        uVar1 = (ulonglong)CONCAT14(uVar6 < *puVar4,uVar6) + (ulonglong)*puVar5 * (ulonglong)w;
        *puVar4 = (uint)uVar1;
        uVar1 = (ulonglong)puVar4[1] + (ulonglong)puVar5[1] * (ulonglong)w + (uVar1 >> 0x20);
        puVar4[1] = (uint)uVar1;
        uVar1 = (ulonglong)puVar4[2] + (ulonglong)puVar5[2] * (ulonglong)w + (uVar1 >> 0x20);
        puVar4[2] = (uint)uVar1;
        lVar2 = (ulonglong)puVar4[3] + (ulonglong)puVar5[3] * (ulonglong)w + (uVar1 >> 0x20);
        puVar4[3] = (uint)lVar2;
        uVar3 = (ulong)((ulonglong)lVar2 >> 0x20);
        puVar4 = rp;
        puVar5 = ap;
      } while ((num & 0xfffffffcU) != 0);
      if (num == 0) {
        return uVar3;
      }
    }
    uVar6 = *rp + uVar3;
    lVar2 = (ulonglong)*ap * (ulonglong)w + (ulonglong)CONCAT14(uVar6 < *rp,uVar6);
    *rp = (uint)lVar2;
    uVar3 = (ulong)((ulonglong)lVar2 >> 0x20);
    if (num != 1) {
      uVar6 = rp[1] + uVar3;
      lVar2 = (ulonglong)ap[1] * (ulonglong)w + (ulonglong)CONCAT14(uVar6 < rp[1],uVar6);
      rp[1] = (uint)lVar2;
      uVar3 = (ulong)((ulonglong)lVar2 >> 0x20);
      if (num != 2) {
        uVar6 = rp[2] + uVar3;
        lVar2 = (ulonglong)ap[2] * (ulonglong)w + (ulonglong)CONCAT14(uVar6 < rp[2],uVar6);
        uVar3 = (ulong)((ulonglong)lVar2 >> 0x20);
        rp[2] = (uint)lVar2;
      }
    }
  }
  return uVar3;
}

