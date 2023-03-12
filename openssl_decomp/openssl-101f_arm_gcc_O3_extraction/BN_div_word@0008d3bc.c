
ulong BN_div_word(BIGNUM *a,ulong w)

{
  ulong uVar1;
  int iVar2;
  ulong *puVar3;
  ulong l;
  int iVar4;
  uint n;
  ulong d;
  
  if (w == 0) {
    return 0xffffffff;
  }
  uVar1 = a->top;
  if (uVar1 != 0) {
    iVar2 = BN_num_bits_word(w);
    n = 0x20 - iVar2;
    iVar2 = BN_lshift(a,a,n);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = a->top;
    iVar4 = iVar2 + -1;
    if (iVar4 < 0) {
      uVar1 = 0;
    }
    else {
      puVar3 = a->d;
      d = w << (n & 0xff);
      iVar2 = iVar4 * 4;
      uVar1 = 0;
      do {
        l = *(ulong *)((int)puVar3 + iVar2);
        iVar4 = iVar4 + -1;
        uVar1 = bn_div_words(uVar1,l,d);
        puVar3 = a->d;
        *(ulong *)((int)puVar3 + iVar2) = uVar1;
        uVar1 = l - d * uVar1;
        iVar2 = iVar2 + -4;
      } while (iVar4 != -1);
      iVar2 = a->top;
      uVar1 = uVar1 >> (n & 0xff);
    }
    if ((0 < iVar2) && (a->d[iVar2 + 0x3fffffff] == 0)) {
      a->top = iVar2 + -1;
    }
  }
  return uVar1;
}

