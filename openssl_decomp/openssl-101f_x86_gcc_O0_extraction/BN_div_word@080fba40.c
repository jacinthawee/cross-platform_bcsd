
ulong BN_div_word(BIGNUM *a,ulong w)

{
  ulong l;
  int iVar1;
  int iVar2;
  ulong uVar3;
  ulong *puVar4;
  ulong h;
  ulong d;
  int iVar5;
  uint uVar6;
  byte local_20;
  
  if (w != 0) {
    uVar6 = 0;
    if (a->top == 0) {
      return 0;
    }
    iVar1 = BN_num_bits_word(w);
    iVar2 = BN_lshift(a,a,0x20 - iVar1);
    if (iVar2 != 0) {
      iVar2 = a->top;
      iVar5 = iVar2 + -1;
      if (-1 < iVar5) {
        local_20 = (byte)(0x20 - iVar1);
        iVar1 = iVar5 * 4;
        h = 0;
        d = w << (local_20 & 0x1f);
        puVar4 = a->d;
        do {
          l = *(ulong *)((int)puVar4 + iVar1);
          iVar5 = iVar5 + -1;
          uVar3 = bn_div_words(h,l,d);
          puVar4 = a->d;
          h = l - d * uVar3;
          *(ulong *)((int)puVar4 + iVar1) = uVar3;
          iVar1 = iVar1 + -4;
        } while (iVar5 != -1);
        iVar2 = a->top;
        uVar6 = h >> (local_20 & 0x1f);
      }
      if (iVar2 < 1) {
        return uVar6;
      }
      if (a->d[iVar2 + -1] != 0) {
        return uVar6;
      }
      a->top = iVar2 + -1;
      return uVar6;
    }
  }
  return 0xffffffff;
}

