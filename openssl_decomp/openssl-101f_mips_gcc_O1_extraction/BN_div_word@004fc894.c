
ulong BN_div_word(BIGNUM *a,ulong w)

{
  ulong uVar1;
  int iVar2;
  ulong uVar3;
  ulong *puVar4;
  ulong *puVar5;
  ulong l;
  ulong d;
  uint n;
  int iVar6;
  
  uVar1 = 0xffffffff;
  if ((w != 0) && (uVar1 = 0, a->top != 0)) {
    iVar2 = BN_num_bits_word(w);
    n = 0x20 - iVar2;
    iVar2 = BN_lshift(a,a,n);
    if (iVar2 == 0) {
      uVar1 = 0xffffffff;
    }
    else {
      iVar2 = a->top;
      iVar6 = iVar2 + -1;
      uVar1 = 0;
      if (iVar6 < 0) {
        uVar1 = 0;
      }
      else {
        puVar4 = a->d;
        d = w << (n & 0x1f);
        iVar2 = iVar6 * 4;
        do {
          iVar6 = iVar6 + -1;
          l = *(ulong *)((int)puVar4 + iVar2);
          uVar3 = bn_div_words(uVar1,l,d);
          puVar4 = a->d;
          uVar1 = l - d * uVar3;
          puVar5 = (ulong *)((int)puVar4 + iVar2);
          iVar2 = iVar2 + -4;
          *puVar5 = uVar3;
        } while (iVar6 != -1);
        iVar2 = a->top;
        uVar1 = uVar1 >> (n & 0x1f);
      }
      if ((0 < iVar2) && (a->d[iVar2 + -1] == 0)) {
        a->top = iVar2 + -1;
      }
    }
    return uVar1;
  }
  return uVar1;
}

